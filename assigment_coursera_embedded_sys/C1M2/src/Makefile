#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile that can compile multiple source files and support two platform targets.
# Build system using the GNU tools, GCC and GNU Make that supports two platforms; 
# the host environment and the target embedded system MSP432.
#
#  @author Renato Soriano
#  @date March 19, 2022
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.i    : Generates <FILE>.i intermediate preprocessed output from 
#					 the corresponding C file.
#      <FILE>.asm  : Generates <FILE>.asm assembly output of c-program implementation 
#					 files and the final output executable.
#      <FILE>.o    : Generates <FILE>.o the object file for all c-source files 
#					 (but do not link) by specifying the object file to compile.
#      compile-all : Compile all object files, but don't link.
#      build 	   : Compile all object files and link into a final executable.
#      clean       : Remove all compiled objects, preprocessed outputs,
#                    assembly outputs, executable files and build output files.
#
# Platform Overrides:
#      CPU - ARM Cortex Architecture (cortex-m4, x86_64)
#      ARCH - ARM Architecture (arm, thumb)
#      SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST
TARGET = c1m2
GCFLAGS = -Wall -Werror -g -O0 -std=c99 

# Architectures Specific Flags
ifeq ($(PLATFORM),MSP432)
	LINKER_FILE = ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	ARCH_CAT = armv7e-m
	FPU = fpv4-sp-d16
	FLOAT_ABI = hard 
	SPECS = nosys.specs
else
	CPU = $(shell cpu)
	ARCH = $(shell arch)
endif

# Compiler Flags and Defines
ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE) 
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=$(ARCH_CAT) -mfloat-abi=$(FLOAT_ABI)\
	 		 -mfpu=$(FPU) --specs=$(SPECS) $(GCFLAGS)
	CPPFLAGS = -DMSP432
	OBJDUMP = arm-none-eabi-objdump 
	SIZE = arm-none-eabi-size
	PLATFORM = MSP432
else
	CC = gcc
	LD = ld
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = $(GCFLAGS)
	CPPFLAGS = -DHOST
	OBJDUMP = objdump 
	SIZE = size
	PLATFORM = HOST
endif

# Variable Definitions
PREPS = $(SOURCES:.c=.i)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
OBJS = $(SOURCES:.c=.o)

#------------------------------------------------------------------------------
# Target: <file>.i
# Prerequisites: <file>.c 
# Output: <file>.i
#------------------------------------------------------------------------------
%.i: %.c
	$(CC) -E $(CPPFLAGS) $(INCLUDES) $< -o $@ 
# -E: Stop after the preprocessing stage; do not run the compiler proper. 
#	  The output is in the form of preprocessed source code, which is sent 
#	  to the standard output. 

#------------------------------------------------------------------------------
# Target: <file>.d
# Prerequisites: <file>.c 
# Output: <file>.d
#------------------------------------------------------------------------------
%.d: %.c
	$(CC) -E -M $(CPPFLAGS) $(INCLUDES) $< -o $@ 

#------------------------------------------------------------------------------
# Target: <file>.asm
# Prerequisites: <file>.c, <file>.out
# Output: <file>.asm
#------------------------------------------------------------------------------
%.asm : %.c
	$(CC) -S $(CFLAGS) $(CPPFLAGS) $< -o $@ 
# -S: Stop after the stage of compilation proper; do not assemble. The output is 
#	  in the form of an assembler code file for each non-assembler input file specified. 
%.asm : %.out
	$(OBJDUMP) -D $< > $@

#------------------------------------------------------------------------------
# Target: <file>.o
# Prerequisites: <file>.c 
# Output: <file>.o
#------------------------------------------------------------------------------
%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $^ -o $@

#------------------------------------------------------------------------------
# Target: compile-all
# Prerequisites: All source files.
# Output: All object files are compiled and the corresponding <files>.o are generated.
#------------------------------------------------------------------------------
.PHONY: compile-all
compile-all: $(OBJS)

#------------------------------------------------------------------------------
# Target: build
# Prerequisites: The source files.
# Output: All files are compiled and generated the final executable <file>.out, 
#		  as well as a brief report regarding the application size.
#------------------------------------------------------------------------------
.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out
$(TARGET).out: $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) -o $@ 
	$(SIZE) $@
	$(OBJDUMP) -D $(TARGET).out > $(TARGET).asm

#------------------------------------------------------------------------------
# Target: clean
# Prerequisites: None.
# Output: Remove all compiled objects, preprocessed outputs, assembly outputs,
#		  executable files and build output files
#------------------------------------------------------------------------------
.PHONY: clean
clean:
	rm -f *.i *.d *.asm *.o *.map *.out

