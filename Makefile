TARGET  := blink
BUILD   := build

CXX     := arm-none-eabi-g++
OBJCOPY := arm-none-eabi-objcopy
SIZE    := arm-none-eabi-size

CPU     := -mcpu=cortex-m4 -mthumb -mfloat-abi=soft

CXXFLAGS := $(CPU) -std=c++14 -Og -g -Wall -Wextra \
            -ffreestanding -fno-exceptions -fno-rtti \
            -ffunction-sections -fdata-sections

LDFLAGS  := $(CPU) -nostartfiles -nostdlib -T linker.ld \
            -Wl,--gc-sections -Wl,-Map=$(BUILD)/$(TARGET).map

SRCS := main.cpp startup.cpp
OBJS := $(SRCS:%.cpp=$(BUILD)/%.o)

all: $(BUILD)/$(TARGET).elf $(BUILD)/$(TARGET).bin
	$(SIZE) $(BUILD)/$(TARGET).elf

$(BUILD)/%.o: %.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD)/$(TARGET).elf: $(OBJS) linker.ld
	$(CXX) $(OBJS) $(LDFLAGS) -lgcc -o $@

$(BUILD)/$(TARGET).bin: $(BUILD)/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@

$(BUILD):
	mkdir -p $(BUILD)

# Flash with OpenOCD over the Nucleo's built-in ST-LINK
flash: $(BUILD)/$(TARGET).elf
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg \
	        -c "program $< verify reset exit"

clean:
	rm -rf $(BUILD)

.PHONY: all flash clean
