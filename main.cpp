#include <iostream>
#include "edge.h"
#include "vertice.h"
#include "graph.h"
#include <vector>
#include <fstream>
#include <string>


using namespace std;

int main(){

	// Create an object of class graph
	graph G;

	// Character array to get input from file
	char cline[1000];

	// Strings to store line read from input file, conutry name, neighbour country, t is intermediate string
	string line, country, neighbourcountry, t="\0";

	// Integers for iterating through the string, countrylen gives the length of the country to extract from string
	int pos=0, countrylen=0, d;

	// The border between two countries is by default 0
	float border = 0;

	// To handle if there is a decimal value or not
	bool decimal = false;
	
	// Create ifstream object for reading file
	ifstream fin;

	// Opening countries.dat file in read mode
	fin.open("countries.dat");

	while (fin.getline(cline, 1000)){
		// Now the read character array cline is stored to line to be used further
		line = cline;
		// Find the length of country, (till >>)
		countrylen = line.find(">>")-1;
		// Extract country from line
		country = line.substr(0,countrylen);
		// Increment pos by 4, (to ignore " >> ") to iterate over the string
		pos = countrylen+4;

		// Iterate till you reach the end
		while(pos < line.length() - 1){
			// Set neighbour country initally to empty string
			neighbourcountry = "\0";
			// Set by default border between two countries as 0
			border=0;
			// By default, the border is not a decimal value
			decimal = false;
			// Numbers after decimal place is 0
			d = 0;

			// Reading the neighbouring country name, (Reading till ':' or ';' is encountered)
			while(line[pos] != ':' && line[pos] != ';'){
				t += line[pos];
				pos++;
			}

			// Neighbouring country is stored in t that was extracted in t
			neighbourcountry = t;

			// t is again initialised to NULL
			t="\0";

			// If the current position is ":", it means, a border exists, extracting the border value
			if(line[pos] == ':'){

				// Ignore ": "	
				pos+=2;
				// Border Extraction, while the space after number is not encountered
				while(line[pos] != ' '){
					// Ignore commas between number
					if(line[pos] == ',')
						pos++;
					// Taking care of decimal, make decimal found = true and ignore that character
					if (line[pos] == '.'){
						decimal = true;
						pos++;
					}
					// Calculating border
					else{
						border = (border * 10) + (line[pos] - '0');
						// If it is a decimal number, then increment d (Numbers after decimal place)
						if (decimal)
							d++;
						// Increment pos
						pos++;
					}
				}// Border extracted

				// After one neighbouring country is found, ignore "km;"
				pos+=3;
			}

			// Ignore " " and go to the next character
			pos+=2;
			// If there was a decimal in the border, divide the number by 10 as many decimal places are there
			for (int i = 0; i < d ; i++)
				border /= 10;

			// Insert the (country, neighbourcountry, border) into the graph
			G.insert (country, neighbourcountry, border);
		}
	}

	// User Interface
	int ans=0, x;
	string one, two;

	while (ans!=5){
		cout<<"\n=============================================================\n";
		cout<<"1. List all countries and bordering countries\n";
		cout<<"2. Find shortest path\n";
		cout<<"3. List all countries with X neighbors\n";
		cout<<"4. Find countries with borders larger than X km\n";
		cout<<"5. Exit\n";
		cout<<"Enter your option \n";
		cin>>ans;

		switch(ans){
			case 1:
				G.discountries();
				break;

			case 2:
				getline(cin,one);
				cout<<"Enter country 1\n";
				getline(cin, one);
				cout<<"Enter country 2\n";				
				getline(cin, two);
				G.findshortestpath(one, two);
				break;

			case 3:
				cout<<"Enter X\n";
				cin>>x;
				G.discountriesXneighbours(x);
				break;

			case 4:
				cout<<"Enter X\n";
				cin>>x;
				G.discountriesXkmborder(x);
				break;
				
			case 5:
				return 0;

			default:
				cout<<"Wrong option entered, try again\n";
				break;
		}
	}

	return 0;
}