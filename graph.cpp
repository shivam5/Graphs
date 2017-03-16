#include "graph.h"

graph :: graph (){

}

graph :: ~graph (){

}

// Insert function 
void graph :: insert (string country,string neighbourcountry,float border){
	int coun, neigh;

	// First search country, 
    // If present store its index, 
    // Otherwise insert and store index
	coun = addvertice(country);
	
	// search neighbouring country, 
    // if present store index, 
    // otherwise insert and store index	
	neigh = addvertice(neighbourcountry);

	// Now, add the neighbouring country index to the neighbours vector;
	if (neigh != -1){
		V[coun]->addneighbour(neigh);

		// Search for the edge (border distance), if found check the verticeone and verticetwo, 
    	// if ok then done
   		// otherwise, add edge	
		if(searchedge(border, coun, neigh) == -1){
			// Adding edge
			edge *x = new edge();
			x->setborder(border);
			x->setverticeone(coun);
			x->setverticetwo(neigh);
			E.push_back(x);
		}	
	}

}

// First search country, 
// If present store its index, 
// Otherwise insert and store index
int graph :: addvertice (string c){
	if (c=="\0")
		return -1;

	// Searching country, if present return the index (Country id)
	for (int i=0; i<V.size(); i++){
		if (c==V[i]->getname())
			return i;
	}

	// If conuntry not present, adding it to the list and returninf the last index (country is stored in last index)
	vertice *x = new vertice();
	x->setname (c);
	V.push_back(x);
	return V.size()-1;
}

// Searching for vertex in the vertice vector, if found then returning the index (country id),
// otherwise return -1, for not found
int graph :: searchvertice (string c){
	for (int i=0; i<V.size(); i++){
		if (c==V[i]->getname())
			return i;
	}
	return -1;	
}

// Searching for edge in the vertice vector, if found then returning the index of the edge,
// otherwise return -1, for not found
int graph :: searchedge (float b, int coun, int neigh){
	for (int i=0; i<E.size(); i++){
		// Check whether the two country id given are same, if same then match is found
		if ( (E[i]->getverticeone() == coun && E[i]->getverticetwo() == neigh ) || (E[i]->getverticeone() == neigh && E[i]->getverticetwo() == coun ) )
			return i;
	}
	return -1;
}

/*
// Searching for edge in the vertice vector, if found then returning the index of the edge,
// otherwise return -1, for not found
int graph :: searchedge (float b, int coun, int neigh){
	for (int i=0; i<E.size(); i++){
		// If the border distance is equal
		if (b==E[i]->getborder()){
			// Check whether the two country id given are same, if same then match is found
			if ( (E[i]->getverticeone() == coun && E[i]->getverticetwo() == neigh ) || (E[i]->getverticeone() == neigh && E[i]->getverticetwo() == coun ) )
				return i;
		}
	}
	return -1;
}
*/

// Finding shortest path between two countries
int graph :: findshortestpath (string a, string b){
		cout << "\n*****************************************************\n";
	cout<<"Shortest path between "<<a<<" and "<<b<<endl;
	cout << "*****************************************************\n";

	int one,two,l,x,i;
	vector <int> n;

	// Searching the first country and storing its index
	one = searchvertice(a);
	// Searching the second country and storing its index
	two = searchvertice(b);

	// If any of the country is not found, break
	if (one == -1 || two == -1){
		cout<<"Either one of two country is not in the graph\n";
		return -1;
	}

	// Create an array called level, which basically donates the distance of any country id from country id one
	int level[V.size()] ;

	// Initialize level by -1, -1 means no country is visited
	for (i=0; i<V.size(); i++)
		level[i] = -1;

	// Create a queue
	queue <int> Q;
	// Push the country id one into queue
	Q.push(one);
	// The level of one would be 0
	level[one]=0;

	// Traverse till the queue is not empty
	while (!Q.empty()){
		// If level[two] is not equal to -1, which means coutry two is visited and its shortest path is stored, then return it
		if (level[two]!=-1){
			cout<<"The shortest path is : "<<level[two]<<endl;
			return level[two];
		}

		// Extract the country id in front of the queue
		x=Q.front();
		// Extract its level
		l=level[x];
		// Get the neighbour list of country id x
		n = V[x]->getneighbours();

		// Iterate through the neighbour list
		for (i=0; i<n.size(); i++){
			// If any of the neighbour is not visited as of now (level=-1), push into queue, and make the level = l+1
			if (level[n[i]]==-1){
				Q.push(n[i]);
				level[n[i]]=l+1;
			}
		}

		// Remove the front element, remove country x
		Q.pop();

	}

	// If level of country two is -1, it is not visited even after bfs, hence there is no path
	if (level[two]== -1){
		cout<<"No path found between the two\n";
		return -1;
	}

	// Return the shortest path in case not returned above
	else{
		cout<<"The shortest path is : "<<level[two]<<endl;
		return level[two];
	}

}

// Display countries and their bordering countries
// Each country is visited the vertice list, and corresponding neighbours are printed
void graph :: discountries (){
	cout << "*****************************************************\n";
	cout<<"\tCountries and their bordering Countries\n";
	cout << "*****************************************************\n\n";

	for (int i=0; i<V.size(); i++){
		cout<<"==============================================================\n";
		cout<<"Country : ";
		cout <<V[i]->getname()<<", ID - "<<i<<endl;
		vector <int> neighbours=V[i]->getneighbours();
		cout<<"Bodering countries : "<<endl;
		for (int i=0; i<neighbours.size(); i++)
			cout<<V[neighbours[i]]->getname()<<", ID - "<<neighbours[i]<<"\n";
		cout<<endl<<endl;
	}	

}

// Display countries with neighbours greater than x
// The size of the neighbour list is compared, and the country is returned if comparison above is true
void graph :: discountriesXneighbours (int x){
	cout << "*****************************************************\n";
	cout<<"\tCountries with "<<x<<" neighbours\n";
	cout << "*****************************************************\n\n";

	int j=0;
	for (int i=0; i<V.size(); i++){
		vector <int> neighbours=V[i]->getneighbours();
		if (neighbours.size()==x){
			cout<<++j<<". Country : ";
			cout <<V[i]->getname()<<", ID - "<<i<<endl;	
		}
	}	

}

// Display countries with border greater than x km,
void graph :: discountriesXkmborder (float x){
	cout << "*****************************************************\n";
	cout<<"\tCountries with borders larger than X km\n";
	cout << "*****************************************************\n\n";

	int i=0, j=0, sum=0, k=0;
	vector <int> neighbours;

	for (i=0; i< V.size(); i++){
		sum=0;
		for (j=0; j<E.size(); j++){
			if (E[j]->getverticeone() == i || E[j]->getverticetwo() == i)
				sum += E[j]->getborder();
		}

		if (sum>x){
			cout<<++k<<". Country : ";
			cout <<V[i]->getname()<<", ID - "<<i<<endl;	
		}
	}

}
