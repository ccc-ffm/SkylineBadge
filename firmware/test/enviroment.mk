#Toolchain Path
#Set TOOL_PATH
TOOL_PATH ?=../../toolchain/binary/avr8-gnu-toolchain-linux_x86_64/bin/
SHELL = sh
CC = $(TOOL_PATH)avr-gcc
OBJCOPY = $(TOOL_PATH)avr-objcopy
OBJDUMP = $(TOOL_PATH)avr-objdump
SIZE = $(TOOL_PATH)avr-size
NM = $(TOOL_PATH)avr-nm
REMOVE = rm -f
COPY = cp
SUDO = sudo
