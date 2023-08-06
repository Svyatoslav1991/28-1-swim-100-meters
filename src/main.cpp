#include <iostream>
#include <vector>
#include <future>
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
	
	std::vector<std::future<void>> vFutures;

	for (auto& swimmer : vSwimmers)
	{
		vFutures.push_back(std::async(&Swimmer::swim, &swimmer));
	}
	
	
	for (auto& future : vFutures)
	{
		future.wait();
	}


	return 0;
}