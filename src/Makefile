DESTDIR=/usr/local

CFLAGS += -O2 -Wall -Werror -pedantic -std=gnu99

dsp_test: spi.c

install:
	install -d $(DESTDIR)/bin
	install dsp_test $(DESTDIR)/bin

clean:
	rm -rf dsp_test *.o
