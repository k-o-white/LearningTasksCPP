//
// Created by teena on 25.01.2023.
//

#pragma once
#include <map>
#include "IGraph.h"

class ListGraph : public IGraph
{
private:
    std::map<int, std::vector<int>> listG;
public:
    ListGraph();

    explicit ListGraph(IGraph &oth);

    ListGraph& operator=(IGraph &oth);

    ~ListGraph() override;

    void AddEdge(int from, int to) override;

    std::vector<int> Vertices() override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

    void printGraph() const override;

    void clear();
};