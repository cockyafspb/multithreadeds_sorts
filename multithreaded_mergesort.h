#ifndef MULTITHREADED_MERGESORT_H
#define MULTITHREADED_MERGESORT_H

#include <thread>

template<class T>
static inline void fillTheRest(T *dst, int dstIndex, T *src, int srcIndex, int size)
{
    while (srcIndex < size) {
        dst[dstIndex] = src[srcIndex];
        dstIndex++;
        srcIndex++;
    }
}

template<class T>
void static merge(T a[], int sizeA, T b[], int sizeB, T c[])
{
    int ia = 0, ib = 0, ic = 0;
    while (ia < sizeA && ib < sizeB) {
        if (a[ia] <= b[ib]) {
            c[ic] = a[ia];
            ia++;
        }
        else {
            c[ic] = b[ib];
            ib++;
        }
        ic++;
    }
    fillTheRest(c, ic, a, ia, sizeA);
    fillTheRest(c, ic, b, ib, sizeB);
}

template<class T>
void mergeSort(T *arr, T *temp, int size, int cur_depth, int max_depth)
{
    if (size < 2) {
        return;
    }
    int left = size / 2;
    if (cur_depth <= max_depth) {
        std::thread t(mergeSort<T>, arr, temp, left, cur_depth + 1, max_depth);
        std::thread t1(mergeSort<T>, (arr + left), temp + left, (size - left), cur_depth + 1, max_depth);
        //wait for threads to finish
        t.join();
        t1.join();
    }
    else {
        mergeSort(arr, temp, left, cur_depth + 1, max_depth);
        mergeSort(arr + left, temp + left, (size - left), cur_depth + 1, max_depth);
    }
    merge(arr, left, arr + left, size - left, temp);
    memcpy(arr, temp, size * sizeof(T));
}

template<class T>
void mt_mergesort(T *arr, int size, int max_depth)
{
    T *temp = new T[size];
    //in case of allocation error will throw bad_alloc
    mergeSort(arr, temp, size, 1, max_depth);
    delete[] temp;
}

#endif //MULTITHREADED_MERGESORT_H
