
run: we6_solution edmonton-roads-2.0.1.txt
	./we6_solution < edmonton-roads-2.0.1.txt

we6_solution: graph_concepts.o digraph.o
	g++ -o we6_solution graph_concepts.o digraph.o

digraph.o: digraph.cpp
	g++ -c -Wall -std=c++11 digraph.cpp

graph_concepts.o: graph_concepts.cpp
	g++ -c -Wall -std=c++11 graph_concepts.cpp

clean: 
	rm -f digraph.o graph_concepts.o we6_solution	 