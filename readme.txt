Tiny 2048 for Arduboy

## Description
tiny 2048 is 2048 clone.


## Installation
Request : Arduino IDE 1.6.x

1. download from github
2. pls edit test.bat(windows) or test.sh(osx) for your computer(must change COM port number)
3. execute test.bat
4. play it


## Rule
synthetic process. bit different.
2 + 2 -> 3.
3 + 3 -> 4.
4 + 4 -> 5.
goal is 10.


## Controls
direction : move
A+B       : reset


## Development
compiler        : windows Arduino IDE 1.6.8(avr-gcc) + 1.0.6(make.exe)
image converter : python 2.6 + PIL
etc             : Visual Studio 2015 C#


## History
v1.02 2016/05/11    support arduboy 1.0. thank you cactus!
v1.01 2016/02/23    fix. reset bug of 64 bit computer.
v1.00 2016/02/20    first version


Arduboy 1.0 infomation.

AVR Memory Usage
----------------
Device: atmega32u4

Program:   15872 bytes (48.4% Full)
(.text + .data + .bootloader)

Data:       2121 bytes (82.9% Full)
(.data + .bss + .noinit)
