// flow_main.cpp
// Dylan Palmieri
// 2020-12-12
// Test Suite for flow module

#include"flow.hpp"

#include<iostream>
using std::cout;
using std::endl;

int main() {

    Flow test;
    test.hello();

    { // test case with example from
      // https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
      // ( Also from the class final lol )

    // The format for the graph input is:
    // index = node number
    // pair.first = node the edge connectes to
    // pair.second = edge weight
    Flow gfg_test( {
                 { { 1, 16 }, { 2, 13 } }, // We have an edge 0->1 with weight 16, etc.
                 { { 2, 10 }, { 3, 12 } },
                 { { 1,  4 }, { 4, 14 } },
                 { { 2,  9 }, { 5, 20 } },
                 { { 3,  7 }, { 5,  4 } },
                 { }
                 } );

    gfg_test.calculate();
    int tFlow = gfg_test.getMaxFlow();

    cout << "Test Case: graph from GeeksForGeeks example" << endl;
    gfg_test.printGraph();
    if ( tFlow != 23 ){
        cout << "   TEST FAILED" << endl;
        cout << "   Max Flow value calculated: " << tFlow << endl;
        cout << "   Expected value: 23" << endl;

    }
    else
        cout << "   Test Passed!" << endl;

    } // end test case

    { // second test case
      // example from https://www.programiz.com/dsa/ford-fulkerson-algorithm

    Flow p_test( {
            { { 1, 8 }, { 3, 3 } },
            { { 2, 9 } },
            { { 5, 2 } },
            { { 5, 5 } },
            { { 2, 7 }, { 3, 4 } },
            { }
            } );


    p_test.calculate();
    int tFlow = p_test.getMaxFlow();

    cout << "Test Case: graph from Programiz example" << endl;
    p_test.printGraph();
    if ( tFlow != 6 ){
        cout << "   TEST FAILED" << endl;
        cout << "   Max Flow value calculated: " << tFlow << endl;
        cout << "   Expected value: 6" << endl;

    }
    else
        cout << "   Test Passed!" << endl;

    }

    return 0;
}
