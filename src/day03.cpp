#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdint.h>
#include <vector>

#define UPPERCASE_ASCII_OFFSET 64

#define LOWERCASE_ASCII_OFFSET 96

#define UPERCASE_VALUE 26

char findMatchingChar(std::string currLine)
{
    char matchingChar = 0;
    int halfPoint = currLine.length() / 2;
    std::string firstHalf = currLine.substr(0, halfPoint);
    std::string secondHalf = currLine.substr(halfPoint, halfPoint);

    std::cout << firstHalf << "   " << secondHalf;

    for (char &currChar : firstHalf)
    {

        for (char &compareChar : secondHalf)
        {
            if (compareChar == currChar)
            {
                matchingChar = compareChar;
                std::cout << "                 matching char is: " << matchingChar << "\n";
                break;
            }
        }
        if (matchingChar != 0)
        {
            //Check to see if we found it yet, If so break.
            break;
        }
    }

    if (matchingChar == 0)
    {
        std::cout << "error";
    }
    return matchingChar;
}

int getNumericalValue(char charToCheck)
{
    int valToReturn = 0;
    if ((charToCheck >= 'a') && (charToCheck <= 'z'))
    {
        valToReturn = (charToCheck - LOWERCASE_ASCII_OFFSET);
        std::cout << "value returning for " << charToCheck << " is: " << valToReturn << "\n";
        return valToReturn;
    }
    else if ((charToCheck >= 'A') && (charToCheck <= 'Z'))
    {
        valToReturn = (charToCheck - UPPERCASE_ASCII_OFFSET + UPERCASE_VALUE);
        std::cout << "value returning for " << charToCheck << " is: " << valToReturn << "\n";
        return valToReturn;
    }
    else

        std::cout << "error parsing char \n" << charToCheck << "\n";
    return 0;
}

void day03Part1()
{
    std::ifstream is("../input/day3Input.txt");
    std::string currLine;
    int pointSum = 0;
    char matchingChar = 0;
    while (std::getline(is, currLine))
    {
        matchingChar = findMatchingChar(currLine);
        pointSum += getNumericalValue(matchingChar);
    }
    std::cout << "final val: " << pointSum << "\n";
}

char findMatchingCharPt2(std::string Line1, std::string Line2, std::string Line3)
{
    char matchingChar = 0;

    for (char &firstChar : Line1)
    {
        for (char &secondChar : Line2)
        {
            if (firstChar == secondChar)
            {
                for (char &thirdChar : Line3)
                {
                    if (firstChar == thirdChar)
                    {
                        std::cout << "                 matching char is: " << matchingChar << "\n";
                        return firstChar;
                    }
                }
            }
        }
    }

    if (matchingChar == 0)
    {
        std::cout << "error";
    }
    return matchingChar;
}

void day03Part2()
{
    std::ifstream is("../input/day3Input.txt");
    std::string lineOne;
    std::string lineTwo;
    std::string lineThree;

    int pointSum = 0;

    while (std::getline(is, lineOne))
    {
        std::getline(is, lineTwo);
        std::getline(is, lineThree);
        char matchingChar = findMatchingCharPt2(lineOne, lineTwo, lineThree);
        pointSum += getNumericalValue(matchingChar);
    }
    std::cout << "done with value: " << pointSum;
}

void day03()
{
    std::cout << "three\n\n\n\n";
    // day03Part1();
    day03Part2();
}