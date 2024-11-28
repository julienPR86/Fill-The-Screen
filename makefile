CC = gcc
CFLAGS = -lmingw32 -lSDL2main -lSDL2
SRC = main_menu.c
OBJ = main_menu.o
EXEC = game.exe

all : $(EXEC) clean

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS)

$(OBJ): $(SRC)
	$(CC) -c $(SRC)

clean:
	rm "$(OBJ)"	