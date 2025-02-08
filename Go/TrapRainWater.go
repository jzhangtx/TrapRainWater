package main

import "fmt"

func FindNextHighest(heights []int, index int) int {
	for index = index + 1; index < len(heights); index++ {
		if heights[index] < heights[index-1] {
			return index - 1
		}
	}

	return -1
}

func NoHigherLeft(heights []int, index int) bool {
	for i := index + 1; i < len(heights); i++ {
		if heights[i] > heights[index] {
			return false
		}
	}

	return true
}

func GetTrap(heights []int, index int) int {
	lowest := heights[index]
	highest := heights[index]

	for index = index + 1; index < len(heights); index++ {
		if heights[index] >= highest {
			return index
		}
		if heights[index] > heights[index-1] {
			if NoHigherLeft(heights, index) {
				return index
			}
		}

		if heights[index] < lowest {
			lowest = heights[index]
		}
	}

	return -1
}

func FindNextTrap(heights []int, start int) (int, int) {
	start = FindNextHighest(heights, start)
	if start == len(heights)-1 {
		return start, -1
	}
	highest := GetTrap(heights, start)

	return start, highest
}

func VolumeOfTrappedRainWater(heights []int) int {
	start := 0
	volume := 0
	end := 0
	for start < len(heights) {
		if end == len(heights)-1 {
			break
		}

		start, end = FindNextTrap(heights, end)
		if end == -1 {
			end = start + 1
			continue
		}

		trappingHeight := min(heights[start], heights[end])
		for start++; start < end; start++ {
			if heights[start] <= trappingHeight {
				volume += (trappingHeight - heights[start])
			}
		}
	}

	return volume
}

func main() {
	for {
		fmt.Print("Number of heights: ")
		count := 0
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		fmt.Print("Please enter the heights: ")
		heights := make([]int, count)
		for i := 0; i < count; i++ {
			fmt.Scan(&heights[i])
		}

		fmt.Print("The volume of trapped water is ")
		fmt.Println(VolumeOfTrappedRainWater(heights))
	}
}
