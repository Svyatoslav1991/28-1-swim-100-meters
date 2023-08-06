#pragma once
#include <chrono>
#include <thread>


using Sec = std::chrono::seconds;

constexpr int64_t N = 6;

float generateSpeed() noexcept;
