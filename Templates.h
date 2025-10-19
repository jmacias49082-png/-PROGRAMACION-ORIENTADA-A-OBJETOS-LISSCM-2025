#pragma once
#include <iostream> 

template <typename T>
void PrintArray(T* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
