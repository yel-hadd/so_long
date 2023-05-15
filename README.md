# so_long
so_long is a 2D game where the player controls a character who must collect all of the collectables and reach the exit. The game is played on a grid of tiles, and the player can move around the grid by pressing the WASD keys. The player can also interact with objects on the grid by pressing the E key.

The game is over if the player Collects all of the collectables and reaches the exit.
The game can be played on any map that is in the .ber format. The .ber format is a simple text format that defines the layout of the map. The map must contain a starting position for the player, a goal position, and a number of collectables.
## Preview


https://github.com/yel-hadd/so_long/assets/82560247/1919189f-fded-46f4-bd1b-74e3e0788a0c


To play the game, clone the repository and run the following command:
```bash
make
```
This will compile the game and create an executable file called so_long. To run the game, type the following command:
```bash
./so_long <map_file>
```
Where <map_file> is the path to the .ber file that contains the map. a map is already including with the project (`m.ber`).
## Controls
* WASD
* ARROW KEYS





