CC = gcc
CFLAGS = -lmingw32 -lSDL2main -lSDL2
EXEC = main

all : $(EXEC)

$(EXEC) : main.o button.o game.o init.o map.o pause_menu.o player.o
	$(CC) -o $(EXEC) main.o button.o game.o init.o map.o pause_menu.o player.o $(CFLAGS)

%.o : scripts/%.c
	$(CC) -c $<

clean:
	rm -f *.o