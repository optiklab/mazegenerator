# mazegenerator
A forked and slightly refactored maze generator from ![@razimantv](https://github.com/razimantv/mazegenerator) with aim to **draw mazes immediately on the screen using SFML graphics library**.

The main idea is to simplify the library to easily look inside and learn the algorithms of maze generation. Here is what changed/added:
1. It is simplified to support only rectangular mazes (thought, it is not a problem at all to support all others by copy-pasting several CPP files from the original repository and by implementing simple Draw function).
2. It is very easy to run inside Visual Studio 2017 by simply pressing F5. No need to deal with console.
3. I added visualization with SFML graphics library by adding and implementing a very simple Draw function.
4. I removed all the input parameters, since the idea is to SEE the resulting maze that is saved in the SVG file.

As a result, the program will:
a. Immediately show generated maze 

![1](https://github.com/optiklab/mazegenerator/blob/main/results/screenshot.jpg)

b. Will push the generated SVG file into your filesystem.

![2](https://github.com/optiklab/mazegenerator/blob/main/results/maze.svg)

# How to run

The project is written in C++ with use of STL, SFML for graphics.
Project file is built using Visual Studio 2022 and Microsoft Windows.
So, you basically need to open the project using VS and press F5.

I didn't check the project on any other platforms except Windows (sorry).

# Author

Copyright (C) 2022 Anton "optiklab" Yarkov

https://github.com/optiklab/mazegenerator

See LICENSE file in the repo.