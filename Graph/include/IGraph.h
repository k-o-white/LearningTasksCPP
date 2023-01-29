//
// Created by teena on 25.01.2023.
//

#pragma once
#include <vector>

class IGraph
{
public:
    virtual ~IGraph() {};
    IGraph() {};
    IGraph(IGraph &oth) {};

    virtual void AddEdge(int from, int to) = 0;

    virtual std::vector<int> Vertices() = 0;

    virtual int VerticesCount() const = 0;

    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0;

    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0;

    virtual void printGraph() const = 0;
};
