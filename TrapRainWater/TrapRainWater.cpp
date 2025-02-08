// TrapRainWater.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

size_t GetNextHighest(const std::vector<int>& heights, size_t begin)
{
    int height = heights[begin++];
    while (begin != heights.size())
    {
        if (heights[begin] < heights[begin - 1])
            return begin - 1;
    }

    return begin - 1;
}

bool NoHigherLeft(const std::vector<int>& heights, size_t begin)
{
    for (auto i = begin + 1; i < heights.size(); ++i)
        if (heights[i] > heights[begin])
            return false;
    return true;
}

size_t GetNextTrap(const std::vector<int>& heights, size_t begin)
{
    int highest = heights[begin];
    int lowest = heights[begin];

    while (++begin != heights.size())
    {
        if (heights[begin] >= highest)
            return begin;

        if (heights[begin] > heights[begin - 1])
        {
            if (NoHigherLeft(heights, begin))
                return begin;
        }

        if (heights[begin] < lowest)
            lowest = heights[begin];
    }

    return -1;
}

int VolumeOfTrappedRainWater(const std::vector<int>& heights)
{
    size_t endHeight = 0;
    size_t startHeight = 0;
    int volume = 0;

    while (startHeight < heights.size())
    {
        startHeight = GetNextHighest(heights, endHeight);
        if (startHeight == heights.size()-1)
            break;

        endHeight = GetNextTrap(heights, startHeight);
        if (endHeight == -1)
        {
            endHeight = startHeight + 1;
            continue;
        }

        int trappingHeight = std::min(heights[startHeight], heights[endHeight]);
        for (++startHeight; startHeight < endHeight; ++startHeight)
        {
            if (heights[startHeight] < trappingHeight)
                volume += trappingHeight - heights[startHeight];
        }
    }

    return volume;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of elements in the array: ";
        std::cin >> count;
        if (count == 0)
            break;

        std::vector<int> vec(count);
        std::cout << "The numbers of the sorted array: ";
        for (int i = 0; i < count; ++i)
            std::cin >> vec[i];

        std::cout << "The trapped rain volume is: " << VolumeOfTrappedRainWater(vec) << std::endl << std::endl;
    }
}
