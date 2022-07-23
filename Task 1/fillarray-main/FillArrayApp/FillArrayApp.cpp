#include <iostream>
#include <array>
#include <exception>
#include <iomanip>
#include "..\FillArrayLib\FillArray.h"

int main()
{
    size_t rows, cols;
    do
    {
        std::cout << "\nEnter the number of rows: ";
        std::cin >> rows;
        std::cout << "Enter the number of columns: ";
        std::cin >> cols;
        std::cout << std::endl;

        std::array<std::array<int, maxRows>, maxColumns> mat;
        try
        {
            fillArray(mat, rows, cols);
            displayArray(mat, rows, cols);

            std::cout << "NE DIAG DOWN" << std::endl;
            fillArray1(mat, rows, cols);
            displayArray(mat, rows, cols);

            std::cout << "SW DIAG UP" << std::endl;
            fillArray2(mat, rows, cols);
            displayArray(mat, rows, cols);

            std::cout << "NW HOR" << std::endl;
            fillArray3(mat, rows, cols);
            displayArray(mat, rows, cols);

            std::cout << "NW VER" << std::endl;
            fillArray4(mat, rows, cols);
            displayArray(mat, rows, cols);
        }
        catch (std::invalid_argument e)
        {
            std::cout << e.what() << std::endl;
        }
    } while (rows != 0 || cols != 0);
}
