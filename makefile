# change application name here (executable output name)
TARGET=main

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall
# multithreading
PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe 

GTKLIB=`pkg-config --cflags --libs gtk+-3.0 gthread-2.0` -lm -w

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB)  -export-dynamic

OBJS=    main.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
    
main.o: src/main.c
	$(CC) -c $(CCFLAGS) src/main.c $(GTKLIB) -o main.o -lm
    
clean:
	rm -f *.o $(TARGET)

