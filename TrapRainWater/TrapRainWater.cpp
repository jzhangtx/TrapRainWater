// TrapRainWater.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

size_t FindNextTrapper(const std::vector<int>& heights, size_t begin)
{
    int height = heights[begin++];
    for (; begin < heights.size(); ++begin)
    {
        if (heights[begin] >= height)
            return begin;
    }

    return heights.size();
}

int VolumeOfTrappedRainWater(const std::vector<int>& heights)
{
    int volume = 0;
    for (size_t i = 0; i < heights.size(); )
    {
        int startHeight = heights[i];
        auto stop = FindNextTrapper(heights, i);
        if (stop == heights.size())
        {
            ++i;
            continue;
        }

        for (size_t j = i + 1; j != stop; ++j)
        {
            volume += (startHeight - heights[j]);
        }
        i = stop;
    }

    return volume;
}

int main()
{
    std::vector<int> vec{ 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    std::cout << "The trapped rain volume is: " << VolumeOfTrappedRainWater(vec);
}
