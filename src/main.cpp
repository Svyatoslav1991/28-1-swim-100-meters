#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

#include "functions.h"
#include "swimmer.h"


int main() {
	std::cout << "\tTask 28.1 SWIM 100 METERS\n\n";

	std::vector<Swimmer> vSwimmers;

	for (int64_t i = 0; i < N; ++i)
	{
		vSwimmers.push_back(Swimmer("swimmer_" + std::to_string(i + 1), generateSpeed()));
	}
	
	std::vector<std::thread> vThreads;

	std::vector<Swimmer> vResult;

	for (auto& swimmer : vSwimmers)
	{
		vThreads.push_back(std::thread(&Swimmer::swim, &swimmer, std::ref(vResult)));
	}
	
	for (auto& thread : vThreads)
	{
		thread.join();
	}

	printResults(vResult);


	return 0;
}