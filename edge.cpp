// Class for storing edges information (borders)
// This class stores the border as an integers
// It also stores the end point countries, it stores their country id as integers in verticeone and vertice two

#include "edge.h"

// Constructor
edge :: edge (){
	border =0;
	verticeone = -1;
	verticetwo = -1;
}

//Destructor
edge :: ~edge (){

}

// Sets border
void edge ::  setborder(int x){
	border=x;
}

// Return border
int edge :: getborder(){
	return border;
}

// Sets vertice one
void edge ::  setverticeone(int x){
	verticeone=x;
}

// Get vertice one
int edge :: getverticeone(){
	return verticeone;
}

// Sets vertice two
void edge ::  setverticetwo(int x){
	verticetwo=x;
}

// Sets vertice two
int edge :: getverticetwo(){
	return verticetwo;
}

