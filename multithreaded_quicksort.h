#ifndef MULTITHREADED_QUICKSORT_H
#define MULTITHREADED_QUICKSORT_H

#include <thread>

template<class T>
void mt_partition(T *arr, int size, int maxDepth, int curDepth)
{
    if (size < 2) {
        return;
    }
    int pivot, left = 1, right = size - 1;
    std::swap(arr[0], arr[size / 2]);
    pivot = arr[0];
    while (left <= right) {
        while (right >= left && arr[right] >= pivot) {
            right--;
        }
        while (left <= right && arr[left] < pivot) {
            left++;
        }
        if (left < right) {
            std::swap(arr[left++], arr[right--]);
        }
    }
    std::swap(arr[0], arr[right]);

    if (curDepth <= maxDepth) {
        std::thread t(mt_partition<T>, arr, right, maxDepth, curDepth + 1);
        std::thread t2(mt_partition<T>, arr + right + 1, size - right - 1, maxDepth, curDepth + 1);
        t.join();
        t2.join();
    }
    else {
        mt_partition(arr, right, maxDepth, curDepth + 1);
        mt_partition(arr + right + 1, size - right - 1, maxDepth, curDepth + 1);
    }
}

// mt_quicksort sorts an array of T using the quicksort algorithm
// using a number of threads equal to 2^maxDepth.
template<class T>
void mt_quicksort(T *arr, int size, int maxDepth)
{
    mt_partition(arr, size, maxDepth, 1);
}

#endif //MULTITHREADED_QUICKSORT_H
