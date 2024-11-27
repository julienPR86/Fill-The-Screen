# PassManager
Here is my first game. I already made it in python with Tkinter, you can obtain it on Itch.io... and I decided to make it in C. I currently use SDL2 for the graphics.

## Requirements
You'll need the SDL library, you can download it on github. After that, you need to put the .ddl file in the bin repo of your C compiler, and also the SDL2 folder in the include repo.

After that, to compile the main_menu.c file, you need to run the following command if you're using Mingw :
```bash
gcc main_menu.c -lmingw32 -lSDL2main -lSDL2
```
And you'll get an executable !

## Contributing
This is a personal game, but if you have ideas about the gameplay, tell me !

## License
[MIT](https://choosealicense.com/licenses/mit/)
