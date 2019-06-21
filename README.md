# FdF

Wireframe representation of a (X, Y, Z) map.

## Install

Only works at **42-Paris** for now because of the library used (*Minilibx*).

Type this command :
```
$> make
```

## Usage
###How to run the FdF

Once the program is compiled, you can show the usage with the command :
```
$> ./fdf
```
You can run the program with this command :
```
$> ./fdf 'map'
```

### The map

To run the program, you will need a map.
A map is designed like this :
```
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9
```
#### How it works
 * The position of the number tell is coordinates in *X* and *Y*
 * His value tell is *Z* coordinate
 * You can use any number
 * The map must be rectangular

### Controls

Keyboard :
* **Arrows** Translate the map in the direction you want
* **+ / -** Zoom in / Zoom out
* **Pge Up / Pge Down** Increase / Decrease all the Z values
* **2 / 8** Rotations on X axis
* **4 / 6** Rotations on Y axis
* **3 / 7** Rotations on Z axis
* **I / P** Change between Isometric / Parallel oint of view
* **Echap** Quit the program

Mouse:
* You can use the mouse to do the rotations easier

## Screenshots
![screen1](/screens/screen1.png)
![screen2](/screens/screen2.png)
![screen3](/screens/screen3.png)

## Credits
This project was made in collaboration with [@reda-con](https://github.com/RemiDC)