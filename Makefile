TrapRainWater: TrapRainWater.o
	g++ -g -o TrapRainWater.exe TrapRainWater.o -pthread    

TrapRainWater.o: TrapRainWater/TrapRainWater.cpp
	g++ -g  -c -pthread TrapRainWater/TrapRainWater.cpp
