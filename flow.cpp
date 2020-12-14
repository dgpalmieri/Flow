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
using std::make_pair;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include<queue>
using std::queue;

#include<unordered_set>
using std::unordered_set;

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

void Flow::setGraph( Graph & graph ) { this->_graph = graph; }

// bool bfs
// Pre: all parameters are initialized
// Post:
//      path contains a list of edges of a path from source to sink
//      weight contains the maximum possible flow flow through the path
bool bfs( vector< pair< int, int > > & path, int & weight, const Graph & g){
    int currentVertex = 0;
    queue< int > nextVerticies;
    unordered_set< int > discovered{ 0 };

    while ( g[ currentVertex ].size() > 0 ) {

        for ( auto p : g[currentVertex] )
            if ( p.second > 0 &&
                 discovered.find( p.first ) == discovered.end() ) {
                nextVerticies.push( p.first );
                discovered.insert( p.first );
                weight += p.second;
            }

        int nextVertex = nextVerticies.front();
        nextVerticies.pop();

        path.push_back( { currentVertex, nextVertex } );

        currentVertex = nextVertex;
    }

    auto end = path.size() - 1;
    auto prev = end - 1;
    while ( true ) {
        if ( prev < 0 ) { break; }

        if ( path[ prev ].second != path[ end ].first ) {
            for ( auto p : g[ path[ prev ].first ] ) {
                if ( p.first == path[ prev ].second ) {
                    weight -= p.second;
                    break;
                }
            }
            path.erase( path.begin() + prev );
        }

        --end;
        --prev;
    }

    return true;
}

void Flow::calculate() {
    vector< pair< int, int > > path = { };
    int weight = 0;

    while( bfs( path, weight, this->_graph) ){

    }

    this->_maxFlow = 0;
}
