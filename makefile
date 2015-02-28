IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR)
CPFLAGS=-c -Wall

ODIR=./obj
LDIR=./lib
SRCDIR=./src

MODELSRC=$(SRC)/models
CTRLSRC=$(SRC)/controllers
VIEWSRC=$(SRC)/views

LIBS=-lm

all: gofish

gofish: $(ODIR)/gofish.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/gofish.o: $(SRCDIR)/gofish.c  $(wildcard $(MODELSRC)/*.c) $(wildcard $(CTRLSRC)/*.c) $(widlcard $(VIEWSRC)/*.c)
	$(CC) $(CPFLAGS) -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~

cleanall: clean
	rm -f gofish