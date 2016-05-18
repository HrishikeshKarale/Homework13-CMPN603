

Program 1(Clock):

The objective of this program is to fix a broken clock. We are given a broken clock that shows the wrong time.
In order to show thw correct time the hour hand of the clock must be moved in the clock wise or anti-clockwise direction
to display the correct time. 

Algorithm:

Create an initially empty queue of configurations.(config)
    Insert the initial configuration into the queue.
    While
      the queue is not empty and
      the first configuration in the queue does not meet the goal,
    loop:
        Remove the first configuration from the queue and call it C.
        For each move applicable to C, loop:
          Make the move and enqueue the resulting
          configuration if it has not already been seen.(visited())
        end-loop.
    end-loop.
    The acceptable configuration is now at the head of the queue;(goal_check())
    but if the queue is empty, there is no solution to the problem.

The sloution to the program is implemented using a solver that generates all possible configurationsand pushes it into a queue "config". 
A seperate vector "visited state" is used to store the number of states that have already been visited. The function goal_check() 
checks whether the current state matches the goal state and returns a boolean depending on the condition. The function visited() 
checks is the states generated state matches the an already existing state and removes returns a boolean accordingly. The final 
function configsolver() generates new states by taking into consideration all posibilities. The program is completed when the current 
state generated matches the goal state and outputs the correct set of sequential steps to reach the goal state.

Example:

Three inputs must be given viz. number of hours on the dial, current time and true time.

Number of hours on dial - 12
Current time - 5
True time - 7

How to run: g++ clock.cpp -o clock
			./clock 12 5 7

configsolver - 5(current time) -> (5+1, 5-1) -> (4+1, 4-1, 6+1, 6-1)....Goal state is reached.

Program 2(Water Jug):

The objective of this program is to solve the infamous water jug problem. Here the goal state is a jug which must hold the desired litres of
water. However the only way to add water to the goal jug is by using a series of jugs with a fixed size. Water can be poured from one jug to another
into the goal jug until the goal jug is finally full.

Algorithm:

Create an initially empty queue of configurations.
    Insert the initial configuration into the queue.
    While
      the queue is not empty and
      the first configuration in the queue does not meet the goal,
    loop:
        Remove the first configuration from the queue and call it C.
        For each move applicable to C, loop:
          Make the move and enqueue the resulting
          configuration if it has not already been seen.
        end-loop.
    end-loop.
    The acceptable configuration is now at the head of the queue;
    but if the queue is empty, there is no solution to the problem.

The sloution to the program is implemented using a solver that generates all possible configurationsand pushes it into a queue "config". 
A seperate vector "visited state" is used to store the number of states that have already been visited. The function goal_check() 
checks whether the current state matches the goal state and returns a boolean depending on the condition. The function visited() 
checks is the states generated state matches the an already existing state and removes returns a boolean accordingly. The final 
function configsolver() generates new states by taking into consideration all posibilities. Here the container can be filled, emptied
or even transferred from one jug to another. The program is completed when the current state generated matches the goal state and 
outputs the correct set of sequential steps to reach the goal state.

Example:

There can be n number of inputs. The first input is always the capacity of the goal jug. The other inputs are the capacities of the 
other jugs that we wish to use to eventually reach the capacity of the goal jug.

Example:

Goal capacity - 4 litres
Capacity of jug 1 - 3 litres
Capacity of jug 2 - 5 litres

How to run: g++ water.cpp -o
			./water 4 3 5

configsolver - 1) Fill 5 gallon jug upto brim.
			   2) Empty 3 gallons from 5 gallon jug to 3 gallon jug.
			   3) Empty the three gallon jug. 2 gallons remain in 5 gallon jug.
			   4) Empty two gallons from 5 gallon jug to 3 gallon jug.
			   5) Fill 5 gallon jug upto brim.
			   6) Empty a litre from 5 gallon jug to 3 gallon jug thus leaving 4 gallons in 5 gallon jug...Goal state reached.

Program 3(Sam Lloyd's puzzle):

The objective of this program is to solve an nxn puzzle. The idea being each nxn consists of blocks where atleast one block is 
left empty in order to facilitate the movement of the pieces along the board. We are given an initial state and usinf a sequential
set of moves using the black block we must achieve the goal state.

Algorithm:

Create an initially empty queue of configurations.
    Insert the initial configuration into the queue.
    While
      the queue is not empty and
      the first configuration in the queue does not meet the goal,
    loop:
        Remove the first configuration from the queue and call it C.
        For each move applicable to C, loop:
          Make the move and enqueue the resulting
          configuration if it has not already been seen.
        end-loop.
    end-loop.
    The acceptable configuration is now at the head of the queue;
    but if the queue is empty, there is no solution to the problem.

The sloution to the program is implemented using a solver that generates all possible configurationsand pushes it into a queue "config". 
A seperate vector "visited state" is used to store the number of states that have already been visited. The function goal_check() 
checks whether the current state matches the goal state and returns a boolean depending on the condition. The function visited() 
checks is the states generated state matches the an already existing state and removes returns a boolean accordingly. The final 
function configsolver() generates new states by taking into consideration all posibilities. Here the solver facilitates the next move 
by taking into consideration, all the possible moves when the blank space is reached i.e. the pieces can be moved up, down, left or right in
a particular configuration. The program is completed when the current state generated matches the goal state and outputs the correct set of 
sequential steps to reach the goal state.

Example:

Here we inputs are the input file and the output file. If either of the files are inputted as a '-' then we have to manually enter the config.

Let us consider an input file as:

4 1
..xy

xy..

Where 4 is the number of columns, 1 the number of rows, ..xy the initial state and xy.. the goal state.

How to run: g++ Lloyd.cpp
			./Lloyd "example.txt" "output.txt" 
			./Lloyd "-" "output.txt"
			./Lloyd "example.txt" "-"
			./Lloyd "-" "-"

configsolver - 1) ..xy
			   2) .x.y
			   3) .xy.
			   4) x.y.
			   5) xy..



