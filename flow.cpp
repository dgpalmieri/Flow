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
using std::size_t;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include<queue>
using std::queue;

#include<unordered_set>
using std::unordered_set;

#include<algorithm>
using std::find;

// GLOBAL FUNCTIONS

void printGraph( const Graph & g ) {
    for ( size_t i = 0; i < g.size(); ++i ){
            cout << "vertex " << i << ": ";
        for ( auto x : g[i] ){
            cout << x.first << "(" << x.second << ") ";
        }
        cout << endl;
    }
}

void printPath( const vector< pair< size_t, size_t > > & path , const Graph & g ) {
    cout << "New Path: " << endl;
    for ( const auto & p : path ) {
        cout << p.first << " to " << p.second << ", weight: ";
        for ( const auto & q : g[ p.first ] ) {
            if ( q.first == p.second )
                cout << q.second << endl;
        }
    }
    cout << endl;
}

void addReverseEdges( const Graph & gPrime, Graph & g ) {
    for ( size_t i = 1; i < gPrime.size() - 1; ++i ){
        for ( auto & path : gPrime[ i ] ) {
                g[ path.first ].push_back( { i, 0 } );
        }
    }
}

// bool bfs
// Pre: all parameters are initialized
// Post:
//      path contains a list of edges of a path from source to sink
//      weight contains the maximum possible flow flow through the path
bool bfs( vector< pair< size_t, size_t > > & path, size_t & weight, const Graph & g) {
    queue< int > verticies;
    verticies.push( 0 );
    unordered_set< int > discovered{ 0 };

    while ( g[ verticies.front() ].size() > 0 ) {
        int curr = verticies.front();
        verticies.pop();

        for ( const auto & p : g[ curr ] ) {
            if ( p.second > 0 &&
                 discovered.find( p.first ) == discovered.end() ) {
                verticies.push( p.first );
                discovered.insert( p.first );
                path.push_back( { curr, p.first } );
            }
        }
    }

    if ( path.empty() )
        return false;

    auto end = path.size() - 1;
    auto prev = end - 1;
    while ( true ) {
        if ( prev < 0 || end == 0 || path.empty() ) { break; }

        if ( path[ prev ].second != path[ end ].first ) {
            path.erase( path.begin() + prev );
        }

        --end;
        --prev;
    }

    if ( path[0].first != 0 || path[ path.size() - 1 ].second != g.size() - 1 )
        return false;

    for ( const auto & p : path ){
        for ( const auto & q : g[ p.first ] ){
            if ( q.first == p.second && weight > q.second )
                weight = q.second;
        }
    }

    auto lastNode = ( path.end() - 1 )->second;
    return lastNode == g.size() - 1;
}

// FLOW MEMBER FUNCTIONS

void Flow::hello() const { std::cout << "Hello, World!" << std::endl; }

int Flow::getMaxFlow() const { return this->_maxFlow; }

void Flow::setGraph( Graph & graph ) { this->_graph = graph; }

void Flow::calculate() {
    vector< pair< size_t, size_t > > path = { };
    size_t weight = -1;

    auto gcopy( this->_graph );

    addReverseEdges( this->_graph, gcopy );
    gcopy[ gcopy.size() - 1 ].clear();

    while ( bfs( path, weight, gcopy ) ){

        if ( weight == 0 )
            break;

        for ( const auto & edge : path ){
            for ( auto & p : gcopy[ edge.first ] ) {
                if ( p.first == edge.second )
                    p.second -= weight;
            }
            for ( auto & p : gcopy[ edge.second ] ) {
                if ( p.first == edge.first )
                    p.second += weight;
            }
        }


        path.clear();

        this->_maxFlow += weight;
        weight = -1;
    }
}

