#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdint.h>
#include <vector>

bool isInsideOther(int startFirst, int endFirst, int startSecond, int endSecond)
{
    if ((startFirst <= startSecond) && (endFirst >= endSecond))
    {
        return true;
    }
    else if ((startSecond <= startFirst) && (endSecond >= endFirst))
    {
        return true;
    }

    return false;
}

bool isPartialOther(int startFirst, int endFirst, int startSecond, int endSecond)
{
    // if the start of second is between the ranges of the first
    if ((startFirst <= startSecond) && (endFirst >= startSecond))
    {
        return true;
    }
    // if the end of second is between the ranges of first
    else if ((startFirst <= endSecond) && (endFirst >= endSecond))
    {
        return true;
    }
    //Also check the part one case:
    return isInsideOther(startFirst, endFirst, startSecond, endSecond);
}

void day04()
{
    std::ifstream is;
    std::string currLine;
    is.open("../input/day4Input.txt");

    int startFirst, startSecond, endFirst, endSecond;
    char skip;

    int countFull = 0;
    int countPartial = 0;
    // clang-format off
    while (is >> startFirst && 
            is >> skip && 
            is >> endFirst &&
            is >> skip && 
            is >> startSecond &&
            is >> skip &&
            is >> endSecond)
    // clang-format on
    {
        std::cout << "line is: " << startFirst << " " << endFirst << " " << startSecond << " " << endSecond;
                  
        if (isInsideOther(startFirst, endFirst, startSecond, endSecond))
        {
            countFull++;
        }
        if (isPartialOther(startFirst, endFirst, startSecond, endSecond))
        {
            countPartial++;
            std::cout << "is partial";
        }
        std::cout << std::endl;
    }

    std::cout << countFull << "\n";
    std::cout << countPartial << "\n";
}
