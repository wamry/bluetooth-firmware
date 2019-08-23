CC=xc8
SRC=main.c
OBJECTS=$(SRC:.cpp=.o)
CHIP=18f2550
OPTIONS=--chip=$(CHIP) --MSGDISABLE=359 --OPT=all  --WARNFORMAT="warn: [%a] [%n] [%l] [%f] %s"  
#--MSGDISABLE=1257,195:off,194:off  // this option will disable warning 1257, and errors 195 and 194.


all: build clean
build: $(SRC:.c=.hex)
	$(CC) $(OPTIONS) $(SRC)
flash: build
	pk2cmd -M -PPIC$(CHIP)  -Y  -F$(SRC:.c=.hex)
clean: 
	rm -f $(SRC:.c=.asm) $(SRC:.c=.cod) $(SRC:.c=.lst) $(SRC:.c=.d) $(SRC:.c=.cmf) $(SRC:.c=.p1) $(SRC:.c=.hxl) $(SRC:.c=.o) \
	$(SRC:.c=.map) $(SRC:.c=.pre) $(SRC:.c=.lst)  $(SRC:.c=.as) $(SRC:.c=.cof) $(SRC:.c=.sdb) $(SRC:.c=.sym) $(SRC:.c=.obj) $(SRC:.c=.elf) startup*
cleanx: clean 
	rm -f $(SRC:.c=.hex)

.PHONY: all clean