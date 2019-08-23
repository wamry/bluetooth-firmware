
# OPTIMIZATION LEVELS
# asm 		Select optimizations of assembly code derived from C source (default)
# asmfile 	Select optimizations of assembly source files
# debug 	Favor accurate debugging over optimization
# local 	Limit OCG optimizations to within the source file group
# speed 	Favor optimizations that result in faster code
# space 	Favor optimizations that result in smaller code (default)
# all 		Enable all compiler optimizations
# none 		Do not use any compiler optimizations

OPT=debug
CC=xc8
SRC_PATH=src
SRC=main
SRC_USRT=usart
OBJECTS=$(SRC).o
CHIP=18f2550
DISTDIR=dist
OPTIONS=--chip=$(CHIP) -P --mode=DEBUG --MSGDISABLE=359 --OPT=$(OPT) --OUTDIR=$(DISTDIR) --WARNFORMAT="warn: [%a] [%n] [%l] [%f] %s"  
#--MSGDISABLE=1257,195:off,194:off  // this option will disable warning 1257, and errors 195 and 194.

MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 


all: build
build:
	@${MKDIR} $(DISTDIR)
	$(CC) $(OPTIONS) $(SRC_PATH)/$(SRC).c $(SRC_PATH)/$(SRC_USRT).c
flash: build
	pk2cmd -M -PPIC$(CHIP)  -Y  -F$(DISTDIR)/$(SRC).hex
clean:
	rm -rf dist
.PHONY: all clean