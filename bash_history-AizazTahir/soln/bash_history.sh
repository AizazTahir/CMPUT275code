#!/bin/bash
g++ bash_history.cpp -o bash_history -Wall -std=c++11 -g && ./bash_history
rm -f ./bash_history
