#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include "vertice.h"
#include <iostream>
#include <queue>

using namespace std;

// Class for storing the graph
// Has a vertice list (vector) that stores all the countries
// Has a edge list (vector) that stores all the edges
class graph
{
 public:
  graph();
  ~graph();

  // Insert function 
  void insert (string country,string neighbourcountry,float border);

  // Add vertice function
  // First search country, 
  // If present store its index, 
  // Otherwise insert and store index
  int addvertice (string c);
  
  // Searching for vertex in the vertice vector, if found then returning the index (country id),
  // otherwise return -1, for not found
  int searchvertice (string c);
  
  // Searching for edge in the vertice vector, if found then returning the index of the edge,
  // otherwise return -1, for not found
  int searchedge (float b, int coun, int neigh);
  
  // Display countries and their bordering countries
  void discountries ();
  
  // Display countries with neighbours greater than x
  void discountriesXneighbours (int x);
  
  // Display countries with border greater than x km
  void discountriesXkmborder (float x);
  
  // Finding shortest path between two countries
  int findshortestpath (string a, string b);

 protected:
 private:
  vector <vertice*> V;
  vector <edge*> E;

};

#endif // GRAPH_H
