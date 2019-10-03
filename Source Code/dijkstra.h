#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Information.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

namespace Dijkstra
{
void getShortestPath(const std::vector<std::vector<int>> &matrix, const int &sourceVertex, const int &destinationVertex, const std::vector<std::string> &location, const int &MAX);

void dijkstra(const std::vector<std::vector<int>> &matrix, const std::vector<std::string> &location, const int &sourceVertex, const int &destinationVertex, const int &MAX);

void initialiseAllVerticesShortestDistance(const std::vector<std::vector<int>> &matrix, std::vector<int> &shortestDistanceFromSourceVertex, const int &MAX);
void initialisePreviousVertex(const std::vector<std::vector<int>> &matrix, std::vector<int> &previousVertex);
void initialiseVistedVertex(const std::vector<std::vector<int>> &matrix, std::vector<bool> &vistedVertex);

void setSourceVertexDistance(const std::vector<std::vector<int>> &matrix, const int &sourceVertex, std::vector<int> &shortestDistanceFromSourceVertex);

void getShortestDistanceForAllVertices(const std::vector<std::vector<int>> &matrix, std::vector<int> &shortestDistanceFromSourceVertex, std::vector<int> &previousVertex, std::vector<bool> &vistedVertex, const int &MAX);
int getMinDistanceVertexIndexNotYetVisted(const std::vector<std::vector<int>> &matrix, const std::vector<int> &shortestDistanceFromSourceVertex, const std::vector<bool> &vistedVertex, const int &MAX);
void updateNeighboringVertices(const std::vector<std::vector<int>> &matrix, std::vector<int> &shortestDistanceFromSourceVertex, std::vector<int> &previousVertex, const std::vector<bool> &vistedVertex, const int &minVertexIndex, const int &MAX);

void updateInformation(const std::vector<std::string> &location, const std::vector<int> &previousVertex, const std::vector<int> &shortestDistanceFromSourceVertex, const int &sourceVertex, const int &destinationVertex);
void getPath(const std::vector<std::string> &location, const std::vector<int> &previousVertex, const int &destinationVertex, const int &index, std::string &path);
}
#endif