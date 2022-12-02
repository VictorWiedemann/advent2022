#include "../inc/day01.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdint.h>
#include <vector>
#include <algorithm>

std::vector<uint64_t> totalCalories;

void ReadInNumbers()
{
    std::ifstream is("../input/day1Input.txt");
    std::string currLine;
    int localSum = 0;
    while (std::getline(is, currLine))
    {
        // Line contains string of length > 0 then save it in vector
        if(currLine.size() > 0)
        {
            localSum += stoi(currLine);
        }
        else
        {
            totalCalories.push_back(localSum);
            localSum = 0;
        }
    }

    std::sort(totalCalories.begin(), totalCalories.end());
    std::cout << "wait";

}

std::ifstream is("numbers.txt");

void dayOne()
{
    std::cout << "hello one";
    ReadInNumbers();
}
