#include "..\include\functions.h"
#include <random>
#include <cmath>
#include <iostream>

float generateSpeed() noexcept
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(3.0f, 5.0f);

	float speed = dis(gen);

	speed = std::round(speed * 10.0f) / 10.0f;
	
	return speed;
}

//---------------------------------------------------------------

void printResults(const std::vector<Swimmer>& vResults) noexcept
{
	std::cout << "\n\tRESULTS:\n";

	int64_t place = 1;
	for (const auto& swimmer : vResults)
	{
		std::cout << place++ << ": " << swimmer.getName() << "\t" << swimmer.getTime() << "\n";
	}
}