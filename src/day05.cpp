#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <stdint.h>
#include <string>
#include <vector>
#include <sstream>

#define FIRST_CHAR       1
#define NEXT_CHAR_OFFSET 4
#define NUM_OF_STACKS    9

std::vector<std::string> splitString(const std::string &str)
{
    std::vector<std::string> tokens;

    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, '\n'))
    {
        tokens.push_back(token);
    }

    return tokens;
}

void getNextNum(std::string stringToParse, int *moveCount, int *from, int *to)
{

    std::stringstream ss;

    /* Storing the whole string into string stream */
    ss << stringToParse;

    /* Running loop till the end of the stream */
    std::string temp;
    int found;
    int nums[3];
    int count = 0;
    while (!ss.eof())
    {

        /* extracting word by word from stream */
        ss >> temp;

        /* Checking the given word is integer or not */
        if (std::stringstream(temp) >> found){
            nums[count] = found;
            count++;
            if(count >= 3)
            {
                *moveCount = nums[0];
                *from = nums[1];
                *to = nums[2];
                return;
            }
        }
        /* To save from space at the end of string */
    }
    return;
}

void part1()
{
    bool abort = false;
    int currRow = 0;

    std::vector<char> stacks[9];

    std::ifstream inputFile("../input/day5Input.txt");
    std::string rawInput((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    std::vector<std::string> rawRows = splitString(rawInput);
    // for (auto const &rawRow : rawRows)
    // {
    //     std::cout << rawRow << std::endl;
    // }
    currRow = 7;
    while (!abort)
    {

        std::string thisRow = rawRows.at(currRow);
        int currOffset = 0;
        for (int i = 0; i < NUM_OF_STACKS; i++)
        {
            int currCharOffset = FIRST_CHAR + (currOffset * NEXT_CHAR_OFFSET);
            if (currCharOffset >= thisRow.length())
            {
                break;
            }
            char currChar = thisRow.at(currCharOffset);
            if ((currChar >= 'A') && (currChar <= 'Z'))
            {
                stacks[currOffset].push_back(currChar);
            }
            if ((currChar >= '1') && (currChar <= '9'))
            {
                break;
            }

            currOffset++;
        }
        currRow--;
        if (currRow < 0)
        {
            break;
        }
    }

    for (currRow = 10; currRow < rawRows.size(); currRow++)
    {
        int moveCount, from, to;
        getNextNum(rawRows.at(currRow), &moveCount, &from, &to);
        if (!moveCount || !from || !to)
        {
            break;
        }

        //part 1 move
        // for(int i = 0; i < moveCount; i++)
        // {
        //     int boxVal = stacks[(from-1)].back();
        //     stacks[(from-1)].pop_back();
        //     stacks[(to-1)].push_back(boxVal);
        // }

        std::vector<char> tempStack;
        for(int i = 0; i < moveCount; i++)
        {
            if(stacks[(from-1)].size() == 0)
            {
                std::cout << "size zero";
            }
            char boxVal = stacks[(from-1)].back();
            stacks[(from-1)].pop_back();
            tempStack.push_back(boxVal);
        }

        for(int i = 1; i <= moveCount; i++)
        {
            stacks[(to-1)].push_back(tempStack.at(moveCount - i));
        }
    }

    for (auto const &stack : stacks)
    {
        for (auto const &ch : stack)
        {
            std::cout << ch << "-";
        }
        std::cout << std::endl;
    }

    std::cout << "\n\n\n\n\nAnswer is:";

    for (auto const &stack : stacks)
    {
        std::cout << stack.back() << "-";
    }
}

void day05()
{
    part1();
}