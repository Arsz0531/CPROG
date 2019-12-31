# CPROG
######## DISCLAIMER ##########################################################

This repository contains code from an assignemnt from the CPROG course
at DSV in Stockholm. The task was to create a mini "game engine". Due to poor
time management the code is riddled with bugs and is not the prettiest
but it got the job done. 

##############################################################################

Below is the requirements that this code fulfills, this is for the grade D. Sadly
due to bad time management this is the highest grade I had time to develop for.

1. It is coded in C++ with the help of SDL2
2. The code should be divided in classes and use oo-techniques like heritage, polymorfism etc.
3. The coder who makes the game should be protected from hard detected errors
4. There should be a base class for all figures. This class should be prepared to be a root class.
5. Variables should be private, and should only be public for specific reasons.
6. No memory leakage
7. The game engine should be able to handle input and the keybinds should not be hardcoded.
8. Simple collision detection
9. It should be able to run on Linux, MS windows

(For grade D)
1. There should be a maximum framerate
2. There should be different types of sprites in a class hierarchy, movable/unmovable sprites.
   Object from the class hierarchy should only be created dynamically. 


###############################################################################

The game is a simple game where the goal is to 
survive the falling planets by moving out of thier way.

The player is a spaceship and can only be control with the 
arrow keys. There are aliens trying to escape the planets aswell
but they are not a threath for the spaceship.

the image files for the game can be found in a map called assets
an example of a search path; "assets/alien.png"

NotMovableSprites have a default tick and a default movement function 
that can be overriden if desired.

MovableSprite have functions for mouseUp,mouseDown, keyDown, keyUp
which in return make use of
HandleEventKeyDown,HandleEventKeyUp HandleEventMouseDown HandleEventmouseUp
functions that are supposed to be overriden in the game implementation.
The tick function in MovableSprite can also be overriden if desired.

The Width of the game window is 800.
The Height of the game window is 600.
