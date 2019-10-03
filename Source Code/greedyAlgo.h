// g++ -std=c++11 greedyAlgo.cpp readFile.cpp dijkstra.cpp Information.cpp -o greedyAlgo.exe
#ifndef GREEDY_ALGO_H
#define GREEDY_ALGO_H

#include "readFile.h"
#include "dijkstra.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>

void print2DVector(const std::vector<std::vector<int>> &matrix);

int getVertexIndex(const std::string &question);
bool locationValidation(std::string &userInput, int &validLocationIndex);
void toUpperCase(std::string &userInput, std::vector<std::string> &locations_copy);
void printErrorMessage();
#endif