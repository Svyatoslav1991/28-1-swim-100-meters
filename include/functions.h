#pragma once
#include <chrono>
#include <thread>
#include "swimmer.h"


using Sec = std::chrono::seconds;

constexpr int64_t N = 6;

float generateSpeed() noexcept;

void printResults(const std::vector<Swimmer>& vResults) noexcept;