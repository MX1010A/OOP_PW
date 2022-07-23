#include <array>
#include <iostream>
#include <exception>
#include "FillArray.h"
#include <iomanip>

void fillArray(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns) {
    if (rows == 0 || rows > maxRows || columns == 0 || columns > maxColumns)
        throw std::invalid_argument("Invalid array size.");

    int value = 1;

    for (size_t row = 0; row < rows; ++row)
        for (size_t column = 0; column < columns; ++column)
            array[row][column] = value++;
}

void fillArray1(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns) {
    if (rows == 0 || rows > maxRows || columns == 0 || columns > maxColumns)
        throw std::invalid_argument("Invalid array size.");

    int index, value = 1;
    for (int i = columns - 1; i >= 0; i--) {
        index = 0;
        while (index < rows && i + index < columns)
        {
            array[index][i + index] = value++;
            index++;
        }
    }
    for (int i = 1; i < rows; i++) {
        index = 0;
        while (i + index < rows && index < columns)
        {
            array[i + index][index] = value++;
            index++;
        }
    }
}

void fillArray2(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns) {
    if (rows == 0 || rows > maxRows || columns == 0 || columns > maxColumns)
        throw std::invalid_argument("Invalid array size.");

    int index, value = 1;
    for (int i = 0; i < columns; i++) {
        index = 0;
        while (int(rows) - 1 - index >= 0 && i - index >= 0) {
            array[rows - 1 - index][i - index] = value++;
            index++;
        }
    }
    for (int i = rows - 2; i >= 0; i--) {
        index = 0;
        while (int(columns) - 1 - index >= 0 && i - index >= 0) {
            array[i - index][columns - 1 - index] = value++;
            index++;
        }
    }
}

void fillArray3(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns) {
    if (rows == 0 || rows > maxRows || columns == 0 || columns > maxColumns)
        throw std::invalid_argument("Invalid array size.");

    int value = 1, index = 0;
    for (int i = rows - 1; i >= 0; i--) {
        if (index % 2 == 0)
            for (int j = 0; j < columns; j++)
                array[i][j] = value++;
        else
            for (int j = columns - 1; j >= 0; j--)
                array[i][j] = value++;
        index++;
    }
}

void fillArray4(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns) {
    if (rows == 0 || rows > maxRows || columns == 0 || columns > maxColumns)
        throw std::invalid_argument("Invalid array size.");

    int value = 1;
    for (int j = 0; j < columns; j++) {
        if (j % 2 == 0)
            for (int i = 0; i < rows; i++)
                array[i][j] = value++;
        else
            for (int i = rows - 1; i >= 0; i--)
                array[i][j] = value++;
    }
}

void displayArray(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            std::cout << std::setw(4) << array[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}