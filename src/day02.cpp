#include "day02.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdint.h>
#include <vector>

#define ENEMY_ROCK     'A'
#define ENEMY_PAPER    'B'
#define ENEMY_SCISSORS 'C'

#define ME_ROCK     'X'
#define ME_PAPER    'Y'
#define ME_SCISSORS 'Z'

enum
{
    ROCK = 1,
    PAPER = 2,
    SCISSORS = 3,
};

int getPointsForPlayerOutcome(int playerHand, int opposeHand)
{
    if (playerHand == opposeHand)
    {
        return 3;
    }
    //roll the enemies scissors to 0 and see if we are greater than it.
    else if (playerHand > (opposeHand % 3))
    {
        return 6;
    }

    return 0;
}

// convert the coded value to the actual value.
int getHandType(int handType)
{
    switch (handType)
    {
        case ME_ROCK:
        case ENEMY_ROCK:
            return ROCK;
        case ME_PAPER:
        case ENEMY_PAPER:
            return PAPER;
        case ME_SCISSORS:
        case ENEMY_SCISSORS:
            return SCISSORS;
    }
    return 9999999;
}

void day02()
{
    std::cout << "two\n";

    std::ifstream is("../input/day2Input.txt");
    std::string currLine;
    int pointSum = 0;
    while (std::getline(is, currLine))
    {
        if(currLine.empty())
        {
            break;
        }
        uint playerHand = getHandType(currLine[0]);
        uint opposeHand = getHandType(currLine[2]);
        pointSum += opposeHand + getPointsForPlayerOutcome(opposeHand, playerHand);
    }
    std::cout << pointSum;
}
// #define ENEMY_ROCK     'A'
// #define ENEMY_PAPER    'B'
// #define ENEMY_SCISSORS 'C'

// #define ME_ROCK     'X'
// #define ME_PAPER    'Y'
// #define ME_SCISSORS 'Z'

// enum
// {
//     ROCK = 1,
//     PAPER = 2,
//     SCISSORS = 3,
// };