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