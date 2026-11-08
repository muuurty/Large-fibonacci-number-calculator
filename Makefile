CC = gcc
SRCS = main.c
LIBS = -lgmp
TARGET = fib
CFLAGS = -O3

$(TARGET): $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) $(LIBS) -o $(TARGET)
 
clean:
	rm -f $(TARGET)
 
.PHONY: clean