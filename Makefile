CC = gcc
SRCS = main.c
TARGET = fib
CFLAGS = -O3

$(TARGET): $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) $(INCLUDES) $(LIBS) -o $(TARGET)
 
clean:
	rm -f $(TARGET)
 
.PHONY: clean
