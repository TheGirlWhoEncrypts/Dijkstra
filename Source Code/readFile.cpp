#include "readFile.h"

using namespace std;

void ReadFile::processFile(const string &fileName, vector<vector<int>> &matrix, const int &MAX)
{
    fstream inputFile(fileName.c_str(), fstream::in);
    if (!inputFile)
    {
        cerr << "Error opening : " << fileName << "\n"
             << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else
    {
        string readFileLine;

        while (getline(inputFile, readFileLine))
        {
            vector<string> weights = tokenizeString(readFileLine, " ");
            vector<int> records;
            for (int i = 0; i < weights.size(); i++)
            {
                records.push_back(((stoi(weights.at(i)) == MAX) ? MAX : stoi(weights.at(i))));
            }
            matrix.push_back(records);
            records.clear();
        }
    }
    inputFile.close();
}

vector<string> ReadFile::tokenizeString(string str, string delimiter)
{
    size_t pos = 0;
    string token;
    vector<string> result;

    while ((pos = str.find(delimiter)) != string::npos)
    {
        token = str.substr(0, pos);
        result.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    result.push_back(str);
    return result;
}