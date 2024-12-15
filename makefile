CC = gcc
CFLAGS = -lmingw32 -lSDL2main -lSDL2
EXEC = main
OBJ = main.o button.o game.o init.o map.o pause_menu.o player.o game_mode.o

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS)

%.o : scripts/%.c
	$(CC) -c $<

clean:
	rm -f *.o