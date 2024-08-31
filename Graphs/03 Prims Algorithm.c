#include<stdio.h>

/*
Greedy approach to find minimum spanning tree
we start with any node and start creating a MST
*/

// Graph representation using adjacency matrix
int a[7][7] = {
    {0, 0, 8, 0, 13, 17, 0},
    {0, 0, 20, 0, 0, 0, 6},
    {8, 20, 0, 11, 0, 0, 0},
    {0, 0, 11, 0, 12, 0, 0},
    {13, 0, 0, 12, 0, 15, 0},
    {17, 0, 0, 0, 15, 0, 18},
    {0, 6, 0, 0, 0, 18, 0}
};