// flow.hpp
// Dylan Palmieri
// 2020-12-12
// Implementation of the Ford-Fulkerson algorithm

#ifndef FLOW_HPP
#define FLOW_HPP

#include<vector>
#include<utility>

using Graph = std::vector < std::vector< std::pair< int, int > > >;

class Flow {

    public:

        Flow() {};

        Flow( Graph graph ) : _graph(graph) { };

        void hello() const;

        void printGraph() const;

        void calculate();

        int getMaxFlow();

    private:

        Graph _graph;

        int _maxFlow;

}; // End class Flow

#endif /* FLOW_HPP */
