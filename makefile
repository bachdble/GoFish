IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR)
CPFLAGS=-c -Wall

ODIR=./obj
LDIR=./lib
SRCDIR=./src

MODELSRC=$(SRCDIR)/models
CTRLSRC=$(SRCDIR)/controllers
VIEWSRC=$(SRCDIR)/views

LIBS=-lm

all: gofish

gofish: $(ODIR)/gofish.o $(ODIR)/test.o $(ODIR)/cardset.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/gofish.o: $(SRCDIR)/gofish.c  $(wildcard $(MODELSRC)/*.c) $(wildcard $(CTRLSRC)/*.c) $(widlcard $(VIEWSRC)/*.c)
	$(CC) $(CPFLAGS) -o $@ $< $(CFLAGS)

$(ODIR)/cardset.o: $(MODELSRC)/cardset.c
	$(CC) $(CPFLAGS) -o $@ $< $(CFLAGS)

$(ODIR)/test.o: $(SRCDIR)/test.c
	$(CC) $(CPFLAGS) -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~

cleanall: clean
	rm -f gofish