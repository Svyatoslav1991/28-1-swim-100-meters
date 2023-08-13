#pragma once
#include <string>
#include <vector>

class Swimmer
{
public:
	Swimmer(std::string name, float speed);

	void swim(std::vector<Swimmer>& vResults);
	std::string getName() const;
	int64_t getTime() const;

private:
	std::string m_name;
	float m_speed;
	int64_t m_time;
};

