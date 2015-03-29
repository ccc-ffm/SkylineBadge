CC = gcc
CFLAGS = -Wall -Wextra -std=gnu99
LDFLAGS = -lcunit

OBJ=shift.o shift_test.c
SRC=shift.c shift_test.c
TARGET = shift_test

rebuild: clean all

test: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

all: test

.PHONY:
	clean

clean:
	rm -f *.o $(TARGET) *.xml
	
