// Copyright (c) 2022 Marshall Demars All rights reserved

// Created by: Marshall Demars
// Created on: Nov 2022
// This program generates a 2d array

#include <iostream>
#include <random>

template <int rows, int cols>
int averageOfNumbers(int (&passedIn2DList)[rows][cols],
                     int rowElement, int columnElement) {
    // this function gets the average

    int total = 0;

    for (size_t rowElement = 0; rowElement < rows; ++rowElement) {
        for (size_t columnElement = 0; columnElement < cols; ++columnElement)
            total += passedIn2DList[rowElement][columnElement];
    }
    total = total / (rowElement * columnElement);

    return total;
}

int main() {
    // this function generates the random numbers

    int aSingleRandomNumber = 0;
    int average = 0;
    const int rows = 2;
    const int columns = 7;
    int a2DArray[rows][columns];

    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(1, 50);

    std::cout << "Rows:" << rows << std::endl;
    std::cout << "Columns:"
              << columns << std::endl;

    for (int rowElement = 0; rowElement < rows; rowElement++) {
        for (int columnElement = 0; columnElement < columns; columnElement++) {
            aSingleRandomNumber = idist(rgen);
            a2DArray[rowElement][columnElement] = aSingleRandomNumber;
            std::cout << aSingleRandomNumber << " ";
        }
        std::cout << std::endl;
    }

    // calls function
    average = averageOfNumbers(a2DArray, rows, columns);
    std::cout << "\nThe average of all the numbers is: " << average
              << std::endl;

    std::cout << "\nDone." << std::endl;
}
