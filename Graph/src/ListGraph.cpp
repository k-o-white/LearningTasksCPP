//
// Created by teena on 25.01.2023.
//

#include <iostream>
#include "ListGraph.h"

ListGraph::ListGraph() = default;

ListGraph::~ListGraph() = default;

ListGraph::ListGraph(IGraph &oth)
{
    this->clear();
    for (int i = 0; i < oth.Vertices().size(); ++i)
    {
        std::vector<int> nextVertices;
        oth.GetNextVertices(oth.Vertices()[i], nextVertices);
        listG.insert(std::pair<int, std::vector<int>>(oth.Vertices()[i], nextVertices));
    }
}

ListGraph &ListGraph::operator=(IGraph &oth)
{
    this->clear();
    for (int i = 0; i < oth.Vertices().size(); ++i)
    {
        std::vector<int> nextVertices;
        oth.GetNextVertices(oth.Vertices()[i], nextVertices);
        this->listG.insert(std::pair<int, std::vector<int>>(oth.Vertices()[i], nextVertices));
    }
    return *this;
}


void ListGraph::AddEdge(int from, int to)
{
    bool found = false;
    for (auto it = listG.begin(); it != listG.end() && !found; ++it)
    {
        if (it->first == from)
        {
            for (int i = 0; i < it->second.size() && !found; ++i)
            {
                if (it->second[i] == to)
                    found = true;
            }
            if (!found)
            {
                it->second.push_back(to);
                found = true;
            }
        }
    }
    if (!found)
        listG.insert(std::pair<int, std::vector<int>>(from, {to}));

    found = false;
    for (auto it = listG.begin(); it != listG.end() && !found; ++it)
    {
        if (it->first == to)
            found = true;
    }
    if (!found)
        listG.insert(std::pair<int, std::vector<int>>(to, {}));
}

std::vector<int> ListGraph::Vertices()
{
    std::vector<int> vertices;
    for (auto &it : listG)
        vertices.push_back(it.first);
    return vertices;
}

int ListGraph::VerticesCount() const
{
    return (int)listG.size();
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{
    vertices.clear();
    for (const auto &it : listG)
    {
        if (it.first == vertex)
        {
            for (int i : it.second)
                vertices.push_back(i);
            break;
        }
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
{
    vertices.clear();
    for (const auto &it : listG)
    {
        for (int i : it.second)
        {
            if (i == vertex)
                vertices.push_back(it.first);
        }
    }
}

void ListGraph::printGraph() const
{
    for (const auto &it : listG)
    {
        std::cout << it.first << ":";
        if (!it.second.empty())
        {
            for (int i : it.second)
                std::cout << " " << i;
            std::cout << ";" << std::endl;
        }
        else
        {
            std::cout << " no next vertices;" << std::endl;
        }
    }
    std::cout << std::endl;
}

void ListGraph::clear()
{
    listG.clear();
}








