CC = gcc
SRCS = main2.c
INCLUDES = -Iincludes
LIBS = -lm -lgmp
TARGET = fib
CFLAGS = -O3 -fopenmp
 
$(TARGET): $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) $(INCLUDES) $(LIBS) -o $(TARGET)
 
clean:
	rm -f $(TARGET)
 
.PHONY: clean
