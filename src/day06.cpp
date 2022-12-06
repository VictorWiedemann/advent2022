#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <stdint.h>
#include <string>
#include <vector>

#define FIRST_CHAR   'a'
#define NUM_OF_CHARS 26

bool uniqueCharacters(std::string str)
{
 
    // If at any time we encounter 2
    // same characters, return false
    for (int i = 0; i < str.length() - 1; i++) {
        for (int j = i + 1; j < str.length(); j++) {
            if (str[i] == str[j]) {
                return false;
            }
        }
    }
 
    // If no duplicate characters encountered,
    // return true
    return true;
}

void day06()
{
    int charLocation[NUM_OF_CHARS] = {0};

    std::ifstream inputFile("../input/day6Input.txt");
    std::string rawInput((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    int charCount = 0;
    while (true)
    {
        if (charCount + 14 > rawInput.length())
        {
            break;
        }
        std::string substr = rawInput.substr(charCount, 14);
        if (uniqueCharacters(substr))
        {
            break;
        }
        charCount++;
    }
    std::cout << (charCount + 14);
}