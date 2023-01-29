//
// Created by teena on 25.01.2023.
//

#include <iostream>
#include <iomanip>
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph() = default;

MatrixGraph::~MatrixGraph() = default;

MatrixGraph::MatrixGraph(IGraph &oth)
{
    this->clear();

    for (const auto& vertex : oth.Vertices())
    {
        std::vector<int> nextVertices;
        oth.GetNextVertices(vertex, nextVertices);
        for (const auto& next : nextVertices)
            this->AddEdge(vertex, next);
    }
}

MatrixGraph& MatrixGraph::operator=(IGraph &oth)
{
    this->clear();
    this->verticesG = oth.Vertices();

    for (const auto& vertex : verticesG)
    {
        std::vector<int> nextVertices;
        oth.GetNextVertices(vertex, nextVertices);
        for (const auto& next : nextVertices)
            this->AddEdge(vertex, next);
    }
    return *this;
}

void MatrixGraph::AddEdge(int from, int to)
{
    this->AddVertices(from, to);
    if (matrixG.empty() || from > size || to > size)
    {
        size = (from > to) ? from : to;
        matrixG.resize(size);
        for (int i = 0; i < size; ++i)
            matrixG[i].resize(size);
    }
    matrixG[to - 1][from - 1] = 1;
}

std::vector<int> MatrixGraph::Vertices()
{
    return this->verticesG;
}


int MatrixGraph::VerticesCount() const
{
    return (int)verticesG.size();
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{
    vertices.clear();
    for (int i = 0; i < size; ++i)
    {
        if (matrixG[i][vertex - 1] != 0)
            vertices.push_back(i + 1);
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
{
    vertices.clear();
    for (int i = 0; i < size; ++i)
    {
        if (matrixG[vertex - 1][i] != 0)
            vertices.push_back(i + 1);
    }
}

void MatrixGraph::printGraph() const
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
            std::cout << std::setw(2) << matrixG[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void MatrixGraph::AddVertices(const int &v1, const int &v2)
{
    bool found = false;
    for (int i = 0; i < verticesG.size(); ++i)
    {
        if (verticesG[i] == v1)
            found = true;
    }
    if (!found)
        verticesG.push_back(v1);
    found = false;
    for (int i = 0; i < verticesG.size(); ++i)
    {
        if (verticesG[i] == v2)
            found = true;
    }
    if (!found)
        verticesG.push_back(v2);
    std::sort(verticesG.begin(), verticesG.end());
}

void MatrixGraph::clear()
{
    size = 0;
    matrixG.clear();
    verticesG.clear();
}











