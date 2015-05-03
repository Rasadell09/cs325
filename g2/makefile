CC = gcc
DEBUG = -g
CFLAGS = -std=c99
SOURCES = dp.c
OBJECTS = $(SOURCES:.c=.o)
PROGS = dp

all: $(PROGS)

$(PROGS): $(OBJECTS)
	$(CC) $(DEBUG) $(CFLAGS) -o $(PROGS) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(DEBUG) $(CFLAGS) -c $(SOURCES)

clean:
	rm -rf $(PROGS) *.c~ *.o makefile~
