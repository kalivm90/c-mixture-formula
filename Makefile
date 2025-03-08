CC = clang 
CFLAGS = -g -Wall -Iinclude

SRC = src/main.c src/lib.c
OBJ = $(SRC:.c=.o)
OUT = main
BIN = bin/$(OUT)

all: $(BIN)

$(BIN) : $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

%.o: $.c
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f src/*.o $(BIN)

# main: $(TARGET)
# 	$(CC) $(CFLAGS) $(TARGET) -o $(OUT)

# clean: 
# 	rm -f $(TARGET)
 
