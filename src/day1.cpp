#include "../inc/day1.h"

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm> 
#include <stdint.h>

std::vector<uint64_t> totalCalories;

void ReadInNumbers()
{
    std::ifstream is("../input/day1Input.txt");
    std::istream_iterator<uint64_t> start(is), end;
    std::vector<uint64_t> calorieCounts(start, end);
    std::cout << "Read " << calorieCounts.size() << " numbers" << std::endl;
}

std::ifstream is("numbers.txt");
































void dayOne()
{
    std::cout << "hello one";
}

