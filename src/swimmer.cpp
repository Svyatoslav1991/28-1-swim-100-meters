#include "..\include\swimmer.h"
#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
#include "functions.h"


std::mutex mtx;
std::mutex res_mtx;
static std::vector<Swimmer> vResult;


Swimmer::Swimmer(std::string name, float speed) : m_name(name), m_speed(speed), m_time(0)
{
}

/////////////////////////////////////////////////////////////////////////////////

void Swimmer::swim()
{
	float distance = 0.f;

	while (distance < 100.0f)
	{
		distance += m_speed;
		if (distance > 100.0f)
		{
			distance = 100.0f;
		}
		m_time += 1;

		std::this_thread::sleep_for(Sec(1));

		std::unique_lock<std::mutex> ul(mtx);
		std::cout << m_name << " : " << distance << " m\n";
	}

	std::unique_lock<std::mutex> ul2(res_mtx);
	vResult.push_back(std::move(*this));

	if (vResult.size() == N)
	{
		std::cout << "\n\tRESULTS:\n";

		int64_t place = 1;
		std::unique_lock<std::mutex> lock(res_mtx);
		for (const auto& swimmer : vResult)
		{
			std::cout << place++ << ": " << swimmer.getName() << "\t" << swimmer.getTime() << "\n";
		}

	}
}

/////////////////////////////////////////////////////////////////////////////////

std::string Swimmer::getName() const
{
	return m_name;
}

/////////////////////////////////////////////////////////////////////////////////

int64_t Swimmer::getTime() const
{
	return m_time;
}
