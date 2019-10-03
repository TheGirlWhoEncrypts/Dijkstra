#include "dijkstra.h"

using namespace std;

void Dijkstra::getShortestPath(const vector<vector<int>> &matrix, const int &sourceVertex, const int &destinationVertex, const vector<string> &location, const int &MAX)
{
    if (sourceVertex == destinationVertex)
    {
        string path = location.at(sourceVertex) + " --> " + location.at(destinationVertex);
        Information information(location.at(sourceVertex), location.at(destinationVertex), path, 0);
        information.displayInformation();
    }
    else
    {
        dijkstra(matrix, location, sourceVertex, destinationVertex, MAX);
    }
}

void Dijkstra::dijkstra(const vector<vector<int>> &matrix, const vector<string> &location, const int &sourceVertex, const int &destinationVertex, const int &MAX)
{
    vector<int> shortestDistanceFromSourceVertex;
    vector<int> previousVertex;
    vector<bool> vistedVertex;

    initialiseAllVerticesShortestDistance(matrix, shortestDistanceFromSourceVertex, MAX);
    initialisePreviousVertex(matrix, previousVertex);
    initialiseVistedVertex(matrix, vistedVertex);

    setSourceVertexDistance(matrix, sourceVertex, shortestDistanceFromSourceVertex);

    getShortestDistanceForAllVertices(matrix, shortestDistanceFromSourceVertex, previousVertex, vistedVertex, MAX);

    updateInformation(location, previousVertex, shortestDistanceFromSourceVertex, sourceVertex, destinationVertex);
}

void Dijkstra::initialiseAllVerticesShortestDistance(const vector<vector<int>> &matrix, vector<int> &shortestDistanceFromSourceVertex, const int &MAX)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        shortestDistanceFromSourceVertex.push_back(MAX);
    }
}

void Dijkstra::initialisePreviousVertex(const vector<vector<int>> &matrix, vector<int> &previousVertex)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        previousVertex.push_back(-1);
    }
}

void Dijkstra::initialiseVistedVertex(const vector<vector<int>> &matrix, vector<bool> &vistedVertex)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        vistedVertex.push_back(false);
    }
}

void Dijkstra::setSourceVertexDistance(const vector<vector<int>> &matrix, const int &sourceVertex, vector<int> &shortestDistanceFromSourceVertex)
{
    // Check if sourceVertex is within matrix.size();
    if (sourceVertex >= 0 && sourceVertex < matrix.size())
    {
        shortestDistanceFromSourceVertex.at(sourceVertex) = 0;
    }
}

void Dijkstra::getShortestDistanceForAllVertices(const vector<vector<int>> &matrix, vector<int> &shortestDistanceFromSourceVertex, vector<int> &previousVertex, vector<bool> &vistedVertex, const int &MAX)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        int minVertexIndex = getMinDistanceVertexIndexNotYetVisted(matrix, shortestDistanceFromSourceVertex, vistedVertex, MAX);
        vistedVertex.at(minVertexIndex) = true;
        updateNeighboringVertices(matrix, shortestDistanceFromSourceVertex, previousVertex, vistedVertex, minVertexIndex, MAX);
    }
}

int Dijkstra::getMinDistanceVertexIndexNotYetVisted(const vector<vector<int>> &matrix, const vector<int> &shortestDistanceFromSourceVertex, const vector<bool> &vistedVertex, const int &MAX)
{
    int currentMinDistance = MAX, minVertexIndex;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (vistedVertex.at(i) == false && shortestDistanceFromSourceVertex.at(i) < currentMinDistance)
        {
            currentMinDistance = shortestDistanceFromSourceVertex.at(i);
            minVertexIndex = i;
        }
    }
    return minVertexIndex;
}

void Dijkstra::updateNeighboringVertices(const vector<vector<int>> &matrix, vector<int> &shortestDistanceFromSourceVertex, vector<int> &previousVertex, const vector<bool> &vistedVertex, const int &minVertexIndex, const int &MAX)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (!vistedVertex.at(i) && matrix.at(minVertexIndex).at(i) != MAX && (shortestDistanceFromSourceVertex.at(minVertexIndex) + matrix.at(minVertexIndex).at(i) < shortestDistanceFromSourceVertex.at(i)))
        {
            previousVertex.at(i) = minVertexIndex;

            shortestDistanceFromSourceVertex.at(i) = shortestDistanceFromSourceVertex.at(minVertexIndex) + matrix.at(minVertexIndex).at(i);
        }
    }
}

void Dijkstra::updateInformation(const vector<string> &location, const vector<int> &previousVertex, const vector<int> &shortestDistanceFromSourceVertex, const int &sourceVertex, const int &destinationVertex)
{
    const int index = destinationVertex;
    string path;
    getPath(location, previousVertex, destinationVertex, index, path);
    Information information(location.at(sourceVertex), location.at(destinationVertex), path, shortestDistanceFromSourceVertex.at(destinationVertex));
    information.displayInformation();
}

void Dijkstra::getPath(const vector<string> &location, const vector<int> &previousVertex, const int &destinationVertex, const int &index, string &path)
{
    const string arrows = " --> ";
    if (previousVertex.at(index) == -1)
    {
        path += (location.at(index) + arrows);
        return;
    }
    getPath(location, previousVertex, destinationVertex, previousVertex.at(index), path);
    path += location.at(index);
    path += ((destinationVertex == index) ? "" : arrows);
}
