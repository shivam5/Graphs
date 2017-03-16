#ifndef VERTICE_H
#define VERTICE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Class for storing vertice information (countries)
// This class stores the country name as string (name)
// It also stores the nieghbouring countries (Stores their country id) as a vector (vector <int> neighbours)
class vertice
{
 public:
  vertice();
  ~vertice();

  // Sets country name
  void setname(string x);
  // Gets country name
  string getname();
  // Add neighbour in the vector
  void addneighbour(int x);
  // return the neighbour vector
  vector <int> getneighbours();
  vector <int> neighbours;

 protected:
 private:
  string name;
};

#endif // VERTICE_H
