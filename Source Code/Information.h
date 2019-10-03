#ifndef INFORMATION_H
#define INFORMATION_H

#include <string>
#include <iomanip>
#include <iostream>

class Information
{
  private:
    std::string startingPoint, destination, path;
    int distance;

  public:
    Information();
    Information(std::string startingPoint, std::string destination, std::string path, int distance);

    void setStartingPoint(std::string startingPoint);
    void setDestination(std::string destination);
    void setPath(std::string path);
    void setDistance(int distance);

    void displayInformation();
    void format(const std::string &title, const std::string &data);
};

#endif