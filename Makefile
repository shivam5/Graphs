run: main.o graph.o vertice.o edge.o
	g++ main.o graph.o vertice.o edge.o -o run

main.o: main.cpp
	g++ -c main.cpp

graph.o: graph.cpp graph.h
	g++ -c graph.cpp

vertice.o: vertice.cpp vertice.h
	g++ -c vertice.cpp

edge.o: edge.cpp edge.h
	g++ -c edge.cpp
	
clean:
	rm *.o run
