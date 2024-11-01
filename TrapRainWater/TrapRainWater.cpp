// TrapRainWater.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

size_t GetNextHighest(const std::vector<int>& heights, size_t begin)
{
    int height = heights[begin++];
    bool hasOne = false;
    while (begin != heights.size() && height < heights[begin])
    {
        hasOne = true;
        height = heights[begin++];
    }

    if (!hasOne && begin == heights.size())
        return begin;

    return begin - 1;
}

size_t GetNextLowest(const std::vector<int>& heights, size_t begin)
{
    int height = heights[begin++];
    bool hasOne = false;
    while (begin != heights.size() && height >= heights[begin])
    {
        hasOne = true;
        height = heights[begin++];
    }

    if (!hasOne && begin == heights.size())
        return begin;

    return begin - 1;
}

int VolumeOfTrappedRainWater(const std::vector<int>& heights)
{
    size_t endHeight = 0;
    size_t startHeight = 0;
    int volume = 0;

    while (startHeight < heights.size())
    {
        startHeight = GetNextHighest(heights, endHeight);
        if (startHeight == heights.size())
            break;

        size_t lowestHeight = GetNextLowest(heights, startHeight);
        if (lowestHeight == heights.size())
            break;

        endHeight = GetNextHighest(heights, lowestHeight);
        if (endHeight == heights.size())
            break;

        int trappingHeight = std::min(heights[startHeight], heights[endHeight]);
        for (++startHeight; startHeight < endHeight; ++ startHeight)
        {
            if (trappingHeight > heights[startHeight])
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
