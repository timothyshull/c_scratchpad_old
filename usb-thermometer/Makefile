all:	pcsensor

INCLUDES        = -I /usr/local/Cellar/lisub/include/libusb-1.0 -I /usr/local/include
LIBS            = -L /usr/local/Cellar/libusb/1.0.19/lib
CFLAGS = -O2 -Wall ${INCLUDES}

pcsensor:	pcsensor.c
	${CC} -DUNIT_TEST -o $@ $^ -lusb

clean:
	rm -f pcsensor *.o

rules-install:			# must be superuser to do this
	cp 99-tempsensor.rules /etc/udev/rules.d
