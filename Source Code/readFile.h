#ifndef READ_FILE_H
#define READ_FILE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>

namespace ReadFile
{
void processFile(const std::string &fileName, std::vector<std::vector<int>> &matrix, const int &MAX);
std::vector<std::string> tokenizeString(std::string str, std::string delimiter);
}
#endif