#include <iostream>
#include <algorithm>
#include "multithreaded_quicksort.h"
#include "multithreaded_mergesort.h"
int main()
{
    int *arr = new int[1000 * 1000];
    for (int i = 0; i < 1000000; i++) {
        arr[i] = 1000000 - i;
    }
    auto start = std::chrono::steady_clock::now();

    mt_mergesort(arr, 1000 * 1000, 0);

    auto end = std::chrono::steady_clock::now();
    auto elapsed = end - start;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << '\n';

    if (std::is_sorted(arr, arr + 1000000)) {
        std::cout << "Sorted";
    }
    else {
        std::cout << "Not sorted";
    }

    delete[]arr;
    return 0;
}
