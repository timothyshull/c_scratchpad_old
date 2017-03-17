CC=gcc
ROOT=./apue.3e
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)
INC1=$(ROOT)/include
INCDIRS=-I$(INC1)
LDFLAGS=$(ROOT)/lib/libapue.a
CFLAGS=$(INCDIRS)


a.out:
	$(CC) $(CFLAGS) -o a.out main.c $(LDFLAGS)

clean:
	rm ./a.out