# Purpose
Generate a random user profile avatar (a GitHub like avatar) based on a config file saved inside the './data' folder.
The random avatar is made up of squares called 'cells', it has as many 'cells' in it's height as in it's width.
The number of 'cells' on the width/height is given as the first number inside the 'config' file.
The pixel size of one such square, of one such 'cell' is given as the next number after that, the number of colors that could be randomnly
 chosen for a 'cell' is given as the next number, and the next lines have the hex codes of said colors.
The random generation goes as such: random values are assigned first to the left side of a matrix, then to it's middle and after that the right
 side is copied after the left one. In order to have a middle, the size of the matrix should be an odd number, that is not verified for, it's
 just assured by setting the config properly.
The random values are from 0 up to the number of colors exclusively. 
With the matrix properly generated, each pixel of the image gets the color indicated by the element of the matrix to which it corresponds.
