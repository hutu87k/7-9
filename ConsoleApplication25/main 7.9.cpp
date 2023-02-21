#include "intarrray.h"
#include <cstdlib>
#include <iostream>

void printArray(const IntegerArray& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr.get(i) << ' ';
    }
    std::cout << std::endl;
}

int main() //int argc, char** argv
{
    IntegerArray arr(10, 1);

    printArray(arr);
    try {
        arr.get(11) = 10;
    }
    catch (IntegerArray::BadIndex& e) {
        std::cout << "bad situation" << std::endl;
        arr.push_back(10);
    }
    printArray(arr);

}
