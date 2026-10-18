#include <stdint.h>

// Symbols provided by linker.ld
extern uint32_t _estack;
extern uint32_t _sidata;   // start of .data initial values (in flash)
extern uint32_t _sdata;    // start of .data (in RAM)
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern void (*__init_array_start[])(void);
extern void (*__init_array_end[])(void);

extern int main(void);

extern "C" {

void Reset_Handler(void);
void Default_Handler(void) { while (1) {} }

// Every handler defaults to an infinite loop unless you define your own.
void NMI_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)      __attribute__((weak, alias("Default_Handler")));

}

typedef void (*handler_t)(void);

// Cortex-M core vector table. The first word is the initial stack pointer,
// the second is where the CPU jumps after reset. Peripheral interrupt vectors
// would continue after SysTick; add them when you start using interrupts.
__attribute__((section(".isr_vector"), used))
const handler_t vector_table[] = {
    (handler_t)&_estack,     //  0: initial stack pointer
    Reset_Handler,           //  1: reset
    NMI_Handler,             //  2
    HardFault_Handler,       //  3
    MemManage_Handler,       //  4
    BusFault_Handler,        //  5
    UsageFault_Handler,      //  6
    0, 0, 0, 0,              //  7-10: reserved
    SVC_Handler,             // 11
    DebugMon_Handler,        // 12
    0,                       // 13: reserved
    PendSV_Handler,          // 14
    SysTick_Handler,         // 15
};

extern "C" void Reset_Handler(void)
{
    // Copy initialized globals from flash to RAM
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;
    while (dst < &_edata) {
        *dst++ = *src++;
    }

    // Zero uninitialized globals
    for (dst = &_sbss; dst < &_ebss; ++dst) {
        *dst = 0;
    }

    // Run C++ static constructors (if the compiler generated any)
    for (void (**fn)(void) = __init_array_start; fn < __init_array_end; ++fn) {
        (*fn)();
    }

    main();

    while (1) {}
}
