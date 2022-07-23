#pragma once
#include <array>

const size_t maxRows = 20;
const size_t maxColumns = 20;

void fillArray(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns);
void fillArray1(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns);
void fillArray2(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns);
void fillArray3(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns);
void fillArray4(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns);

void displayArray(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns);