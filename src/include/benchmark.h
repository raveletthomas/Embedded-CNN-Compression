#pragma once

/* Including standard libraries */
#include <string>
#include <chrono>

/* Including project files */
#include "comp_algo.h"

/* Aliasing name of chrono library features */
typedef std::chrono::milliseconds mSEC;
typedef std::chrono::microseconds uSEC;
typedef std::chrono::nanoseconds nSEC;
typedef std::chrono::high_resolution_clock HRC;

/* Enum of all the algorithms that are implemented */
enum EncodingAlorithm {
    RLE_ENCODING,
};

/* Prototype of the benchmark function */
void benchmark(enum EncodingAlorithm E, Layer& L);