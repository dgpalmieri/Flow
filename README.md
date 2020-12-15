# Flow
Implementation of the Ford-Fulkerson Algorithm

CS411 Analysis of Algorithms, Homework 8

For further reading + an explaination of the first example, see
[this article](https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/),
which is also linked in the flow_main.cpp file.

## Using the module

To use this module, include flow.hpp in your source file.

Graphs are specified as a vector of a vector of pairs, where:
    * the index of the outermost vector is the node number
    * the inner vector is a list of edges, where
        * the first number is the node that the index-node connects to
        * the second number is the weight of the edge

So, we can specify a new Flow object with a graph like this:
```
Flow gfg_test( {
             { { 1, 16 }, { 2, 13 } }, // We have an edge 0->1 with weight 16, etc.
             { { 2, 10 }, { 3, 12 } },
             { { 1,  4 }, { 4, 14 } },
             { { 2,  9 }, { 5, 20 } },
             { { 3,  7 }, { 5,  4 } },
             { }
             } );
```

## Utility functions

There are a couple functions that can be used to take a closer look at the
step-by-step functionality of this module that I've left in the Flow source
file. Feel free to dig around!
