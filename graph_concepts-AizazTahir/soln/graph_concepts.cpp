// Name: Mian Aizaz Tahir
// SID: 1662795
// CCID: matahir
// CMPUT 275, Winter 2022
#include <iostream>
#include <string>
#include <stack>
#include "digraph.h"
using namespace std;


// Description : The function returns the first word in a sentace and then deletes that word from the sentance
// Arguments : 
// str : The string that we are going to extract its word from 
// Returns:
// A string containing the first word in the sentace
string getWord(string & str) {
    int pos = str.find (",");
    string word = str.substr(0, pos); // store the substring   
    str.erase(0, pos + 1);   
    return word;
}
// Description : The function reads a map from the std input and creates an instance digraph that represtnts the map as an undirected graph
// Returns:
// An instance of digraph representing the map
Digraph read_city_graph_undirected() {
    Digraph EdmontonNetwork;    // Instantiates an instance of the Digraph class for the edmontotn road netword
    string input = "Nothing";
    while (input != "") {   
        getline(cin, input);  // Obtains input from the stdin
        string flag = getWord(input);
        if (flag == "V") {
            string strVertexID = getWord(input);
            int VertexID = stoi(strVertexID);    // Converts vertex from string to integer
            EdmontonNetwork.addVertex(VertexID);  // Adds the vertex to the graph
        }
        if (flag == "E") {
            string strStartVertex = getWord(input);  // Deterimnes the start vertex of the edge
            string strEndVertex = getWord(input);  // Determines the end vertex of the edge
            int startVertex = stoi(strStartVertex);
            int endVertex = stoi(strEndVertex);
            // Adds the edgo in an undirected mannor by adding both directions
            EdmontonNetwork.addEdge(startVertex, endVertex); 
            EdmontonNetwork.addEdge(endVertex, startVertex);
        }
}
    return EdmontonNetwork;
}
// Description : This funciton impliments the DFS algoritm recursively
// Arguments : 
// graph: An instance of the digraph class that represents a map
// u: The vertex that you want to start your search at
// prev: The parent of u
void recursive_dfs(const Digraph& graph, const int u, const int prev, unordered_map<int, int> & reached) {
	if (reached.find(u) != reached.end())
		return; // it was visited before

	reached[u] = prev;

	// Iterate over all neighbours of u
	for (auto itr = graph.neighbours(u); itr != graph.endIterator(u); ++itr) {
		recursive_dfs(graph, *itr, u, reached);
	}
}

// Description : This function counts the number of connected components in the graph given to it
// Arguments : 
// graph: An instance of the digraph class that you want to operate the funciton upon
// Returns:
// an integer represting the number of connected componenets in the graph
unsigned int count_components(const Digraph& graph) {
    vector<int> vertices = graph.vertices();  // Obtains the vertices of the graph
    unordered_map<int, int> reached = {};
    int branches = 0;
    for (int vertex : vertices) {
        if (reached.find(vertex) == reached.end()) {  // Tests if the vertex is not already part of a conntected components
            recursive_dfs(graph, vertex, vertex, reached); 
            branches++; // Adds one to the variable represeting the number of connected componnets in the graph
        }
        else {
            continue;
        }
    }
    return branches;
}


int main() {
    Digraph Edmonton_map;
    Edmonton_map = read_city_graph_undirected();  // Creates an undirected representation of edmontons road networks
    cout << count_components(Edmonton_map) << endl; // Outputs the numeber of connected components in the graph 
    return 0;
}