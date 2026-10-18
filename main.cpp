#include <stdint.h>
#include <cstddef>   // offsetof

#define CHECK_OFFSET(type, member, off) \
    static_assert(offsetof(type, member) == (off), #type "::" #member " is at the wrong offset")

#define FLASH_ACR_BASE 0x0
#define RCC_BASE    0x40023800UL
#define PORTA_BASE  0x40020000UL
#define TIMER2_BASE 0x40000000UL

#define INPUT_MODE 0U
#define OUTPUT_MODE 1U
#define ALT_MODE 2U
#define ANALOG_MODE 3U

typedef struct {
    volatile uint32_t MODER;      // parities 00 input (reset), 01 output, 10 alternate mode, 11 analog mode
    volatile uint32_t OTYPER;     // output type only bits 15:0 - 0 push-pull (reset), 1 open-drain
    volatile uint32_t OSPEEDR;    // output speed parities - 00 lowspeed, 01 medium, 10 fast, 11 high speed
    volatile uint32_t PUPDR;      // pull up pull down parities - 00 no pupd, 01 pu, 10 pd, 11 reserved
    const volatile uint32_t IDR;  // input data (read only) - 15:0 
    volatile uint32_t ODR;        // output data 15:0 - 1 high 0 low
    volatile uint32_t BSRR;       // bit set / reset - 31:16 reset bits, 15:0 set bits
    volatile uint32_t LCKR;       // configuration lock - bit 16 is lock, 15:0 config
    volatile uint32_t AFRL;       // alternate function low - 4 bit zones, each corresponds so AFx of 15
    volatile uint32_t AFRH;       // alternate function low - 4 bit zones, each corresponds so AFx of 15
} GPIO_TYPEDEF;

typedef struct {
    volatile uint32_t CR;           // turns on clock componenets and signals when they stabalize
    volatile uint32_t PLLCFGR;      // allows setting M, N, P, Q, R and selecting clock source
    volatile uint32_t CFGR;         // select system clock, bus prescalers, rtc prescalers, MCO pins
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    volatile uint32_t RESERVED1[1];
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t RESERVED2[2];
    volatile uint32_t AHB1ENR;       // enable High Performance Bus 1 (GPIO Ports)
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    volatile uint32_t RESERVED3[1];
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t RESERVED4[2];
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    volatile uint32_t AHB3LPENR;
    volatile uint32_t RESERVED5[1];
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    volatile uint32_t RESERVED6[2];
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t RESERVED7[2];
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    volatile uint32_t PLLSAICFGR;
    volatile uint32_t DCKCFGR;
    volatile uint32_t CKGATENR;
    volatile uint32_t DCKCFGR2;
} RCC_TYPEDEF;

typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMCR;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t CCMR1;
    volatile uint32_t CCMR2;
    volatile uint32_t CCER;
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
    volatile uint32_t RESERVED;
    volatile uint32_t CCR1;
    volatile uint32_t CCR2;
    volatile uint32_t CCR3;
    volatile uint32_t CCR4;
    volatile uint32_t RESERVED2;
    volatile uint32_t DCR;
    volatile uint32_t DMAR;
    volatile uint32_t OR;
} TIM_TYPEDEF;


// ---------------- GPIO ----------------
CHECK_OFFSET(GPIO_TYPEDEF, MODER,   0x00);
CHECK_OFFSET(GPIO_TYPEDEF, OTYPER,  0x04);
CHECK_OFFSET(GPIO_TYPEDEF, OSPEEDR, 0x08);
CHECK_OFFSET(GPIO_TYPEDEF, PUPDR,   0x0C);
CHECK_OFFSET(GPIO_TYPEDEF, IDR,     0x10);
CHECK_OFFSET(GPIO_TYPEDEF, ODR,     0x14);
CHECK_OFFSET(GPIO_TYPEDEF, BSRR,    0x18);
CHECK_OFFSET(GPIO_TYPEDEF, LCKR,    0x1C);
CHECK_OFFSET(GPIO_TYPEDEF, AFRL,    0x20);
CHECK_OFFSET(GPIO_TYPEDEF, AFRH,    0x24);
static_assert(sizeof(GPIO_TYPEDEF) == 0x28, "GPIO_TYPEDEF size");

// ---------------- RCC ----------------
CHECK_OFFSET(RCC_TYPEDEF, CR,         0x00);
CHECK_OFFSET(RCC_TYPEDEF, PLLCFGR,    0x04);
CHECK_OFFSET(RCC_TYPEDEF, CFGR,       0x08);
CHECK_OFFSET(RCC_TYPEDEF, CIR,        0x0C);
CHECK_OFFSET(RCC_TYPEDEF, AHB1RSTR,   0x10);
CHECK_OFFSET(RCC_TYPEDEF, AHB2RSTR,   0x14);
CHECK_OFFSET(RCC_TYPEDEF, AHB3RSTR,   0x18);
CHECK_OFFSET(RCC_TYPEDEF, RESERVED1,  0x1C);
CHECK_OFFSET(RCC_TYPEDEF, APB1RSTR,   0x20);
CHECK_OFFSET(RCC_TYPEDEF, APB2RSTR,   0x24);
CHECK_OFFSET(RCC_TYPEDEF, RESERVED2,  0x28);
CHECK_OFFSET(RCC_TYPEDEF, AHB1ENR,    0x30);
CHECK_OFFSET(RCC_TYPEDEF, AHB2ENR,    0x34);
CHECK_OFFSET(RCC_TYPEDEF, AHB3ENR,    0x38);
CHECK_OFFSET(RCC_TYPEDEF, RESERVED3,  0x3C);
CHECK_OFFSET(RCC_TYPEDEF, APB1ENR,    0x40);
CHECK_OFFSET(RCC_TYPEDEF, APB2ENR,    0x44);
CHECK_OFFSET(RCC_TYPEDEF, RESERVED4,  0x48);
CHECK_OFFSET(RCC_TYPEDEF, AHB1LPENR,  0x50);
CHECK_OFFSET(RCC_TYPEDEF, AHB2LPENR,  0x54);
CHECK_OFFSET(RCC_TYPEDEF, AHB3LPENR,  0x58);
CHECK_OFFSET(RCC_TYPEDEF, RESERVED5,  0x5C);
CHECK_OFFSET(RCC_TYPEDEF, APB1LPENR,  0x60);
CHECK_OFFSET(RCC_TYPEDEF, APB2LPENR,  0x64);
CHECK_OFFSET(RCC_TYPEDEF, RESERVED6,  0x68);
CHECK_OFFSET(RCC_TYPEDEF, BDCR,       0x70);
CHECK_OFFSET(RCC_TYPEDEF, CSR,        0x74);
CHECK_OFFSET(RCC_TYPEDEF, RESERVED7,  0x78);
CHECK_OFFSET(RCC_TYPEDEF, SSCGR,      0x80);
CHECK_OFFSET(RCC_TYPEDEF, PLLI2SCFGR, 0x84);
CHECK_OFFSET(RCC_TYPEDEF, PLLSAICFGR, 0x88);
CHECK_OFFSET(RCC_TYPEDEF, DCKCFGR,    0x8C);
CHECK_OFFSET(RCC_TYPEDEF, CKGATENR,   0x90);
CHECK_OFFSET(RCC_TYPEDEF, DCKCFGR2,   0x94);
static_assert(sizeof(RCC_TYPEDEF) == 0x98, "RCC_TYPEDEF size");

// ---------------- TIM2 / TIM5 ----------------
CHECK_OFFSET(TIM_TYPEDEF, CR1,        0x00);
CHECK_OFFSET(TIM_TYPEDEF, CR2,        0x04);
CHECK_OFFSET(TIM_TYPEDEF, SMCR,       0x08);
CHECK_OFFSET(TIM_TYPEDEF, DIER,       0x0C);
CHECK_OFFSET(TIM_TYPEDEF, SR,         0x10);
CHECK_OFFSET(TIM_TYPEDEF, EGR,        0x14);
CHECK_OFFSET(TIM_TYPEDEF, CCMR1,      0x18);
CHECK_OFFSET(TIM_TYPEDEF, CCMR2,      0x1C);
CHECK_OFFSET(TIM_TYPEDEF, CCER,       0x20);
CHECK_OFFSET(TIM_TYPEDEF, CNT,        0x24);
CHECK_OFFSET(TIM_TYPEDEF, PSC,        0x28);
CHECK_OFFSET(TIM_TYPEDEF, ARR,        0x2C);
CHECK_OFFSET(TIM_TYPEDEF, RESERVED,   0x30);
CHECK_OFFSET(TIM_TYPEDEF, CCR1,       0x34);
CHECK_OFFSET(TIM_TYPEDEF, CCR2,       0x38);
CHECK_OFFSET(TIM_TYPEDEF, CCR3,       0x3C);
CHECK_OFFSET(TIM_TYPEDEF, CCR4,       0x40);
CHECK_OFFSET(TIM_TYPEDEF, RESERVED2,  0x44);
CHECK_OFFSET(TIM_TYPEDEF, DCR,        0x48);
CHECK_OFFSET(TIM_TYPEDEF, DMAR,       0x4C);
CHECK_OFFSET(TIM_TYPEDEF, OR,         0x50);
static_assert(sizeof(TIM_TYPEDEF) == 0x54, "TIM_TYPEDEF size");

volatile RCC_TYPEDEF *rcc = (RCC_TYPEDEF *)RCC_BASE;
volatile uint32_t *flash_acr = (uint32_t *)FLASH_ACR_BASE;
volatile GPIO_TYPEDEF *porta = (GPIO_TYPEDEF *)PORTA_BASE;
volatile TIM_TYPEDEF *timer2 = (TIM_TYPEDEF *)TIMER2_BASE;

void enable_port_a(void) {
    rcc->AHB1ENR |= 1U;
    (void)rcc->AHB1ENR;
}

void enable_timer_2(void) {
    rcc->APB1ENR |= 1U;
    (void)rcc->APB1ENR;
}

void configure_timer_2(void) {
    timer2->PSC = (16U - 1);    // set prescaler for timer
    timer2->ARR = 0xFFFFFFFFUL; // set max wrap around
    timer2->EGR = 1U;           // loads registers
    timer2->CR1 |= (1U << 0);   // enable/start counter
}

void wait_ms(unsigned int ms) {
    uint32_t start = timer2->CNT;
    while (1) {
        if (timer2->CNT > ms * 1000 + start) break;
    }
}

void set_pin_mode(int pin_number, uint32_t mode) {
    int starting_bit = pin_number * 2;
    uint32_t pin_mask = ~(3U << starting_bit);
    porta->MODER &= pin_mask;
    porta->MODER |= (mode << starting_bit);
}

void drive_pin_high(int pin_number) {
    porta->BSRR = (1U << pin_number);
}

void drive_pin_low(int pin_number) {
    porta->BSRR = (1U << (pin_number + 16));
}

int main(void) {
    enable_port_a();
    set_pin_mode(5, OUTPUT_MODE);
    enable_timer_2();
    configure_timer_2();

    while (1) {
        drive_pin_high(5);
        wait_ms(1000);
        drive_pin_low(5);
        wait_ms(1000);
    }
    return 0;
}