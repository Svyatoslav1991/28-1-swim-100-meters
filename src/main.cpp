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

	std::sort(vSwimmers.begin(), vSwimmers.end(), [](const auto& s1, const auto& s2)
		{
			return s1.getTime() < s2.getTime();
		});

	std::cout << "\n\tRESULTS:\n";
	int64_t place = 1;
	for (const auto& swimmer : vSwimmers)
	{
		std::cout << place++ << ": " << swimmer.getName() << "\t" << swimmer.getTime() << "\n";
	}



	return 0;
}