# Conway's Game of Life

## Description:

The Conway's game of life is a simple set of rules which behave like a celular automata, maybe It's the simplest celular automata known. The game is based on a bidimensional matrix which contais 0s or 1s, indicating wether the cell is alive (1 or true) or death (0 or false). With that and the following set of rules, the game is created:

* A death cell borns if is surrounded by exactly 3 alive cells
* An alive cell remains alive if is surrounded either by 2 or 3 alive cells, otherwise it deads.

It has been demostrated that this game is a complete turing machine, that means that any logic computation can be made with the game an it set of rules.

More information can be used [here](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

## How to use:

Once downloaded the sources, you can do the following:
* Installing:

    ~~~bash
    make
    ~~~

* Executing:   

    ~~~bash
    #This is the built-in way to execute the program
    make exe

    #This also can be done, as usual
    ./main
    ~~~

* Cleaning the objet's programs

    ~~~bash
    make clean  #If you want only to remove .o files
    make cleanAll   #If you want to also remove the executable file
    ~~~

## Version log:

* v1.0 22th Jaunay 2018: first fully functionaly version

## Author:

* **Sergio Quijano Rey**
* [Email](sergiquijano@gmail.com)
