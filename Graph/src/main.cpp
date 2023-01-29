#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"

int main()
{
    ListGraph l;
    l.AddEdge(2, 3);
    l.AddEdge(2, 1);
    l.AddEdge(6, 1);
    l.AddEdge(2, 7);
    l.printGraph();

    MatrixGraph m(l);
    m.printGraph();

    m.AddEdge(4, 5);
    m.AddEdge(4, 1);
    m.AddEdge(5, 6);
    m.AddEdge(7, 6);
    m.AddEdge(3, 7);

    l = m;
    l.printGraph();
    
    m.printGraph();
    return 0;
}
