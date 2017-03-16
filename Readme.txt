*********************************************************************************************************************************

PROJECT DETAILS
This project's aim is to use undirected graphs data structures and applying graph algorithms.

The data file (countries.dat) is in the following format:
Country Name >> Neighbor Country Name#1[: XX km]; Neighbor Country Name#2[: XX
km];
Here [:] means it is optional. In most cases, the country has a border, but there are a
few cases that do not. Note that every line ends with a semicolon.

In this project, we write a menu-driven console interface that allows the user to
list the countries and check if paths between two countries exist (and if so, what is the
shortest path in terms of # of countries visited [note that border length does not matter
in the shortest path computation]). Additional functionalities must also be provided; see
details in the following for additional functionalities.

Example of menu:
1. List all countries and bordering countries
2. Find shortest path
3. List all countries with X neighbors
4. Find countries with borders larger than X km
5. Exit

********************************************************************************************************************************

AUTHOR
Shivam Mittal
2nd year B.Tech Computer Science Engineering, IIT Ropar
Email - 2015csb1032@iitrpr.ac.in
GIthub profile - github.com/shivam5


*********************************************************************************************************************************

IMPLEMENTATION
ALl the questions are implemented in C++ language.
The graph data structure used is - Edge list + Adjacency list 

*********************************************************************************************************************************

COMPILING AND RUNNING PROGRAM
1. Extract the contents of this archive in a folder.
2. Navigate to the folder which contains all these files using cd commands.
3. Type make and press enter. This will automatically compile the necessary file  and links them and create a file 'run' which is necessary executable file.
Note : Your input should be in "countries.dat" file.
4. Type ./run on linux (run on windows) and press enter. 
5. The program would run, just follow the instructions from there.


*********************************************************************************************************************************

FILE INFORMATION

Header Files -  edge.h -> Class for storing edges information (borders), this class stores the border as an integers
                          it also stores the end point countries, it stores their country id as integers in verticeone and vertice two

		graph.h -> Class for storing the graph, has a vertice list (vector) that stores all the countries and has a edge list (vector) that stores all the edges

		vertice.h -> Class for storing vertice information (countries), this class stores the country name as string (name), it also stores the nieghbouring countries (Stores their country id) as a vector (vector <int> neighbours)

CPP Files -     main.cpp -> Contains the main program
		edge.cpp -> Defines functions for the edge class 
		vertice.cpp -> Defines functions for the vertice class
		graph.cpp -> Defines functions for the graph class

Input Files -	countries.dat ->Used to provide the input

Makefile - File used to compile and link all the various cpp files in one go - Easy compilation.



THANK YOU

***********************************************************************************************************************************