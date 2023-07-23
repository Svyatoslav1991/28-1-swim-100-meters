#include "..\include\functions.h"
#include <random>
#include <cmath>

float generateSpeed() noexcept
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(1.0f, 5.0f);

	float speed = dis(gen);

	speed = std::round(speed * 10.0f) / 10.0f;
	
	return speed;
}