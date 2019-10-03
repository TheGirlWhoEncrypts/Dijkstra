#include "greedyAlgo.h"

using namespace std;

/* --------------------------------------- Global Variables ---------------------------------------*/
const vector<string> locations =
    {"Sembawang", "Punggol", "Changi", "Woodlands", "Mandai",
     "Nee Soon", "Ang Mo Kio", "Serangoon", "Tampines", "Bedok",
     "Bukit Panjang", "Upper Thomson", "Choa Chu Kang", "Bukit Batok", "Bukit Timah",
     "Toa Payoh", "Marina Bay", "Tuas", "Jurong", "Clementi",
     "Queenstown", "Outram", "Pasir Panjang", "Sentosa"};

const vector<string> question = {"Starting point", "Destination"};

/* --------------------------------------- Main  ---------------------------------------*/
int main(int argc, char **argv)
{
    const int MAX = 999;
    vector<vector<int>> matrix;

    string fileName = argv[1];
    ReadFile::processFile(fileName, matrix, MAX);

    const int sourceVertex = getVertexIndex(question.at(0)), destinationVertex = getVertexIndex(question.at(1));

    Dijkstra::getShortestPath(matrix, sourceVertex, destinationVertex, locations, MAX);
}

/* --------------------------------------- Function Implementation ---------------------------------------*/
void print2DVector(const vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.at(i).size(); j++)
        {
            cout << left << setw(5) << matrix.at(i).at(j);
        }
        cout << endl;
    }
}

int getVertexIndex(const string &question)
{
    string userInput;
    int validLocationIndex = -1;
    bool isValidLocationInput = false;
    do
    {
        cout << "Enter " << question << " : ";
        getline(cin, userInput);
        isValidLocationInput = locationValidation(userInput, validLocationIndex);

        if (!isValidLocationInput)
        {
            printErrorMessage();
        }
    } while (!isValidLocationInput);
    return validLocationIndex;
}

bool locationValidation(string &userInput, int &validLocationIndex)
{
    bool isValidLocation = false;
    vector<string> locations_copy = locations;

    toUpperCase(userInput, locations_copy);

    vector<string>::iterator itr = find(locations_copy.begin(), locations_copy.end(), userInput);
    // If found
    if (itr != locations_copy.end())
    {
        isValidLocation = true;
        // assign found location index to validLocationIndex
        validLocationIndex = distance(locations_copy.begin(), itr);
    }

    return isValidLocation;
}

void toUpperCase(string &userInput, vector<string> &locations_copy)
{
    // Transfrom user's input to uppercase
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

    // Make a copy and transfrom all valid location to uppercase
    for (int i = 0; i < locations_copy.size(); i++)
    {
        transform(locations_copy.at(i).begin(), locations_copy.at(i).end(), locations_copy.at(i).begin(), ::toupper);
    }
}

void printErrorMessage()
{
    cerr << "ERROR : Invalid Input\n"
         << endl;
}