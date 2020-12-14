// flow.hpp
// Dylan Palmieri
// 2020-12-12
// Implementation of the Ford-Fulkerson algorithm

#ifndef FLOW_HPP
#define FLOW_HPP

#include<vector>
#include<utility>

using Graph = std::vector < std::vector< std::pair< std::size_t, std::size_t > > >;

void printGraph(const Graph &);

class Flow {

    public:

        Flow( Graph graph = { } ) : _graph(graph), _maxFlow(0) { };

        void hello() const;

        int getMaxFlow() const;

        void printGraph() const { ::printGraph( this->_graph ); };

        void calculate();

        void setGraph( Graph & graph );

    private:

        Graph _graph;

        int _maxFlow;

}; // End class Flow

#endif /* FLOW_HPP */
