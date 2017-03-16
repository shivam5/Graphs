// Class for storing vertice information (countries)
// This class stores the country name as string
// It also stores the nieghbouring countries (Stores their country id) as a vector

#include "vertice.h"

vertice :: vertice (){
	name = "\0";
}

vertice :: ~vertice (){

}

// Sets country name
void vertice ::  setname(string x){
	name=x;
}

// Gets country name
string vertice :: getname(){
	return name;
}

// Add neighbour in the vector
void vertice ::  addneighbour(int x){
	neighbours.push_back(x);
}

// Return the neighbour vector
vector <int> vertice :: getneighbours(){
	return neighbours;
}
