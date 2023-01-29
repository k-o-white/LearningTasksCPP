//
// Created by teena on 25.01.2023.
//

#pragma once
#include "IGraph.h"

class MatrixGraph : public IGraph
{
private:
    int size = 0;
    std::vector<std::vector<int>> matrixG;
    std::vector<int> verticesG;
public:
    MatrixGraph();

    explicit MatrixGraph(IGraph &oth);

    MatrixGraph& operator=(IGraph &oth);

    ~MatrixGraph() override;

    void AddEdge(int from, int to) override;

    std::vector<int> Vertices() override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

    void printGraph() const override;

    void clear();

    void AddVertices(const int &v1, const int &v2);
};
