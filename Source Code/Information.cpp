#include "Information.h"

using namespace std;

Information::Information()
{
    startingPoint = destination = path = "";
    distance = 0;
}

Information::Information(string startingPoint, string destination, string path, int distance)
{
    setStartingPoint(startingPoint);
    setDestination(destination);
    setPath(path);
    setDistance(distance);
}

void Information::setStartingPoint(string startingPoint) { this->startingPoint = startingPoint; }
void Information::setDestination(string destination) { this->destination = destination; }
void Information::setPath(string path) { this->path = path; }
void Information::setDistance(int distance) { this->distance = distance; }

void Information::displayInformation()
{
    cout << endl;
    format("Start from", startingPoint);
    format("To", destination);
    format("Path", path);
    format("Total Distance", to_string(distance) += " KM");
}

void Information::format(const string &title, const string &data)
{
    cout << left << setw(16) << title << " : " << data << endl;
}