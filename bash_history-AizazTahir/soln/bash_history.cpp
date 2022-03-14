// Name: Mian Aizaz Tahir
// SID: 1662795
// CCID: matahir
// CMPUT 275, Winter 2022

// Weekly exersise #6: Bash history

#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

// Description: Returns the current pathname of the directory.
// Arguments :
// str_array: array of strings containing the directoryis in the bash
// pathLength: The length of the path to the directory
// // Returns:
// pathname : A string containing the full pathname to the given directory
string getPath(string * str_array, int pathLength) {
    // initialize empty pathname
    string pathname = "";
    if (pathLength == 1) {
        pathname += (str_array[0]);
    }
    else {
        for (int i = 1; i < pathLength; ++i) {
            pathname += ("/" + str_array[i]);
        }
    }
    return pathname;
}

// Description: Prints our the content of the bash history
// Arguments :
// bashContents : A map conttaing all of the contents of the bash essentially the hisory of all the directries that have been visiten and in what order
void printBashHistory(map<string, set<string>> const &bashContents) { 
    // my_map is an iterator to traverse through key—value pairs of 
    // map_history 
    for (auto& my_map : bashContents) { 
        // to store all the names of the files as one string, 
        // space—separated, for a unique directory 
        string filenames = ""; 
        // "it" is an iterator to traverse the elements of the string set 
        // containing the names of the files for a unique directory 
        for(auto it = my_map.second.begin(); it != my_map.second.end(); ++it) { 
            // names of the files are appened in lexicographic order 
            filenames += (*it + " ");
        } 
        // remove trailing whitespace 
        int fileNameLength = filenames.length() - 1;
        filenames = filenames.substr(0, fileNameLength); 
        cout << my_map.first << filenames << endl;
    }
} 

int main() { 
    int queue_num; 
    cin >> queue_num; 
    // String variables to store the values of the command (ls or cd) and the name of the directory 
    string cmd, strName; 
    // A string array that will hold all of the directories in the bash 
    string * path = new string[25]; 
    
    int pathIndex = 0; 
    // Here we have to add the "/" becasue this represents the root directory which is explicity assumed and not given with a command
    path[pathIndex] = "/"; 
    pathIndex++; 
    // We use a map data structure to store the files within each directory 
    // The key will be the directory path as a string and the key will be a set
    // of all of the files within that directory.
    map<string, set<string>> bashContents; 
    // A string that holds the current path of the directory
    string currentPath = getPath(path, pathIndex); 
    // We need to insert the root directory 
    bashContents[currentPath].insert("");
   
    for (int i = 0; i < queue_num; ++i) {
        cin >> cmd >> strName;
        if (cmd == "ls") { 
            // We must obtain the path of the directory 
            currentPath = getPath(path, pathIndex); 
            // Now we insert the fileName into the bashContents to keep track of what files are in each directory
            bashContents[currentPath].insert(strName); 
            } 
        else if (strName == "..") {
            // If .. is given we have to go the past dirctory. 
            // We have to go to the last directoy and erase it to do this
            pathIndex--; 
            path[pathIndex] = ""; 
        }
        else { 
            // This assumes that cd was the given command so we just add directory to the path 
            path[pathIndex] = strName; 
            pathIndex++; 

            currentPath = getPath(path, pathIndex); 
            // if the bashContents does not have this path already then we have to add it  
            if (bashContents.find(currentPath) == bashContents.end()) {
                bashContents[currentPath].insert("");
            } 
        } 
    }
    printBashHistory(bashContents);
    // Free the allocated memory from the heap
    delete[] path;
    return 0;
}

