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

int Flow::getMaxFlow() const { return this->_maxFlow; }

void Flow::setGraph( Graph & graph ) { this->_graph = graph; }

void printPath( const vector< pair< int, int > > & path , const Graph & g ) {
    cout << "Path: ";
    for ( const auto & p : path ) {
        cout << p.first << " to " << p.second << ", weight: ";
        for ( const auto & q : g[ p.first ] ) {
            if ( q.first == p.second )
                cout << q.second << endl;
        }
    }
}

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

        for ( const auto & p : g[currentVertex] )
            if ( p.second > 0 &&
                 discovered.find( p.first ) == discovered.end() ) {
                nextVerticies.push( p.first );
                discovered.insert( p.first );
                weight += p.second;
            }

        int nextVertex = nextVerticies.front();
        nextVerticies.pop();

        path.push_back( { currentVertex, nextVertex } );

        cout << "Path pushed: " << currentVertex << ", " << nextVertex << endl;

        currentVertex = nextVertex;
    }

    printPath( path, g );
    cout << endl;

    auto end = path.size() - 1;
    auto prev = end - 1;
    while ( true ) {
        if ( prev < 0 || end == 0) { break; }

        if ( path[ prev ].second != path[ end ].first ) {
            for ( const auto & p : g[ path[ prev ].first ] ) {
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
        printPath( path, this->_graph );
        cout << "weight pushed: " << weight << endl;
        cout << endl;

        break;

    }

    this->_maxFlow = 0;
}
