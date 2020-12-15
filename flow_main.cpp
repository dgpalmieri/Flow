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

    { // test case
      // example from https://www.geeksforgeeks.org/max-flow-problem-introduction/

        Flow basic_backwards_test( {
                { { 1, 3 }, { 2, 2 } },
                { { 2, 5 }, { 3, 2 } },
                { { 3, 3 } },
                { }
                } );

        basic_backwards_test.calculate();
        int tFlow = basic_backwards_test.getMaxFlow();
        cout << "Test Case: graph from Geeks For Geeks small example" << endl;
        basic_backwards_test.printGraph();
        if ( tFlow != 5 ){
            cout << "   TEST FAILED" << endl;
            cout << "   Max Flow value calculated: " << tFlow << endl;
            cout << "   Expected value: 6" << endl;

        }
        else
            cout << "   Test Passed!" << endl;

    } // end test case

    { // test case
      // From the course textbook, Introduction to the Design and Analysis of
      // Algorithms, Levitin
      // Figure 10.7, page 368
      // NOTE: all node values are decreased by one, because in the book, the
      // source is labeled as one, and here it is zero
    
        Flow textbook_test( {
                { { 1, 2 }, { 3, 3 } },
                { { 4, 3 }, { 2, 5 } },
                { { 5, 2 } },
                { { 2, 1 } },
                { { 5, 4 } },
                { }
                } );

        textbook_test.calculate();
        int tFlow = textbook_test.getMaxFlow();
        cout << "Test Case: graph from textbook example" << endl;
        textbook_test.printGraph();
        if ( tFlow != 3 ){
            cout << "   TEST FAILED" << endl;
            cout << "   Max Flow value calculated: " << tFlow << endl;
            cout << "   Expected value: 6" << endl;

        }
        else
            cout << "   Test Passed!" << endl;
    }

    return 0;
}
