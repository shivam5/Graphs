#ifndef EDGE_H
#define EDGE_H

// Class for storing edges information (borders)
// This class stores the border as an integers
// It also stores the end point countries, it stores their country id as integers in verticeone and vertice two
class edge
{
 public:
  edge();
  ~edge();
  // Sets border
  void setborder(int x);
  // Get border
  int getborder();
  // Sets vertice one
  void setverticeone(int x);
  // Get vertice one
  int getverticeone();
  // Sets vertice two
  void setverticetwo(int x);
  // Get vertice two
  int getverticetwo();

 protected:
 private:
  int border;
  int verticeone;
  int verticetwo;
};

#endif // EDGE_H
