TARGET = main.c
OUT = out
CC = gcc 
CFLAGS = -g -Wall


main: $(TARGET)
	$(CC) $(CFLAGS) $(TARGET) -o $(OUT)

clean: 
	rm -f $(TARGET)
 
