// flow.cpp
// Dylan Palmieri
// 2020-12-12
// Implementation of the Ford-Fulkerson algorithm


#include"flow.hpp"

#include<iostream>
using std::cout;
using std::endl;

#include<utility>
using std::pair;

#include<string>
using std::string;

void Flow::hello() const {
    std::cout << "Hello, World!" << std::endl;
}

void Flow::printGraph() const {
    for ( size_t i = 0; i < this->_graph.size(); ++i ){
            cout << "vertex " << i << ": ";
        for ( auto x : this->_graph[i] ){
            cout << x.first << "(" << x.second << ") ";
        }
        cout << endl;
    }
}

int Flow::getMaxFlow() { return this->_maxFlow; }

bool bfs( string & path, int & weight );

void Flow::calculate() {
    this->_maxFlow = 0;
}
