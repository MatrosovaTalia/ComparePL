# Gradient demo

This folder contains program, producing gradient picture of size (`H` * `W`) pixels, where gradient starts
from gray color `A` to gray color `B`.

Algorithm is intentionally made dumb and non-optimized.

All numbers `H`, `W`, `A` and `B` are of type `uint8`.

Routine generates image of [Plain PGM](http://netpbm.sourceforge.net/doc/pgm.html#plainpgm) format. Ubuntu can show such format out of the box.

ASCII content of the image is printed to `STDOUT`.

JavaScript variant of routine pending.