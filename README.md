README for "so_long" Project
Program Name
"so_long"

Description
"so_long" is a 2D game in which a character collects every collectible present on the map, then escapes by choosing the shortest possible route. The game has a top-down or profile view and the player can move in four directions (up, down, left, right) using the W, A, S, and D keys. The game must comply with the following rules:

The MiniLibX library must be used, either the version available on the school machines or by installing it using its sources.
A Makefile must be provided which will compile the source files without relinking.
The program must take as parameter a map description file ending with the .ber extension.
The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
The map must be rectangular and closed/surrounded by walls. If it's not, the program must return an error.
If the map contains duplicate characters (exit/start), an error message should be displayed.
The program must be able to parse any kind of map as long as it respects the above rules.
Files
Makefile: used to compile the source files.
*.h, *.c: source files for the "so_long" game.
maps: folder containing valid and invalid maps.
textures: folder containing images used in the game.
Makefile
The Makefile contains the following rules:

NAME: set the name of the executable file.
all: compile the source files and create the executable file.
clean: delete all object files.
fclean: delete all object files and the executable file.
re: delete all object files and the executable file, then recompile.
External functions
The following external functions are authorized to be used:

open, close, read, write, malloc, free, perror, strerror, exit.
All functions of the math library (-lm compiler option, man man 3 math).
All functions of the MiniLibX library.
ft_printf and any equivalent YOU coded.
Graphic management
The program displays the image in a window. The management of the window must remain smooth (changing to another window, minimizing, etc.). Pressing ESC must close the window and quit the program in a clean way. Clicking on the cross on the window's frame must close the window and quit the program in a clean way. The use of the images of the MiniLibX library is mandatory.

Map
The map is constructed with 3 components: walls, collectibles, and free space. The map can be composed of only these 5 characters:

0 for an empty space.
1 for a wall.
C for a collectible.
E for a map exit.
P for the player's starting position.
Here is a simple valid map:
