# mazegenerator
A forked and slightly refactored maze generator from ![@razimantv](https://github.com/razimantv/mazegenerator) with aim to draw mazes immediately using SFML graphics library.

The main idea is to simplify the library to easily look inside and learn the algorithms of maze generation. Here is what changed/added:
1. It is simplified to support only rectangular mazes (thought, it is not a problem at all to support all others by copy-pasting several CPP files from the original repository and by implementing simple Draw function).
2. It is very easy to run inside Visual Studio 2017 by simply pressing F5. No need to deal with console.
3. I removed all the input parameters, since the idea is to SEE the resulting maze that is saved in the SVG file.
4. I added visualization with SFML graphics library by adding and implementing a very simple Draw function.
