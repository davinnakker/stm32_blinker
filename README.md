# Overview

This is an embedded systems microcontroller project. Throughout my CS journey have become 
continually more interested in learning the deeper CS fundamentals such as computer architecture,
OS, low-level programming, memory and networking. Embedded Sytems is a field that forces you to learn
a lot of these fundamentals. Embedded work is mostly dont in C, C++ and Assembly. I used C++ for this project and learned how to directly use software to manipulate and configure hardware. 

This piece of software does a very simple task but by doing it at the lowest level possible in order for me to learn how things work under the hood. It blinks and embedded LED light on the STM32 Nucleo 64 board. I directly configures the registers neccesary to configure GPIO pins, enable the correct clocks for each hardware peripheral and use a hardware timer.

The purpose of building this software was to get comfortable with how software interacts with hardware in a bare-metal application. It was also useful for me to get familiar with the STM32 F4 Microcontroller and how its GPIO ports, timers, and clock system work.

{Provide a link to your YouTube demonstration. It should be a 4-5 minute demo of the software running and a walkthrough of the code. Focus should be on sharing what you learned about the language syntax.}

[Software Demo Video](https://youtu.be/b8OoWLcqpos)

# Development Environment

- GCC Cross Compiler for the ARM Cortex M4
- C++ 14

# Useful Websites

- [STM32 F446RE Datasheet](https://www.st.com/en/microcontrollers-microprocessors/)
- [STM32 F446RE Reference Manual](https://www.st.com/en/microcontrollers-microprocessors/)

# Future Work

- fix small bug in the Timer (after 72.1 minutes of blinking it will not wait in between)
- reduce hardcoded values and magic numbers