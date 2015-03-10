IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR)
CPFLAGS=-c -Wall -g -O0
EXE=gofish

ODIR=./obj
LDIR=./lib
SRCDIR=./src

MODELSRC=$(SRCDIR)/models
CTRLSRC=$(SRCDIR)/controllers
VIEWSRC=$(SRCDIR)/views

LIBS=-lm

all: gofish

$(EXE): $(ODIR)/$(EXE).o $(ODIR)/test.o $(ODIR)/cardset.o $(ODIR)/stack.o $(ODIR)/carddeck.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/$(EXE).o: $(SRCDIR)/gofish.c  $(wildcard $(MODELSRC)/*.c) $(wildcard $(CTRLSRC)/*.c) $(widlcard $(VIEWSRC)/*.c)
	$(CC) $(CPFLAGS) -o $@ $< $(CFLAGS)

$(ODIR)/cardset.o: $(MODELSRC)/cardset.c
	$(CC) $(CPFLAGS) -o $@ $< $(CFLAGS)

$(ODIR)/stack.o: $(MODELSRC)/stack.c
	$(CC) $(CPFLAGS) -o $@ $< $(CFLAGS)

$(ODIR)/carddeck.o: $(MODELSRC)/carddeck.c
	$(CC) $(CPFLAGS) -o $@ $< $(CFLAGS)

$(ODIR)/test.o: $(SRCDIR)/test.c
	$(CC) $(CPFLAGS) -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~

cleanall: clean
	rm -f $(EXE)
	rm -fR $(EXE).dSYM/


run:
	./$(EXE)

val:
	valgrind --leak-check=full --show-leak-kinds=all --dsymutil=yes ./$(EXE)
