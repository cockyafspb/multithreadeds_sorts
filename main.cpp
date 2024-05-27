#include <iostream>
#include <algorithm>
#include <random>
#include <functional>
#include "multithreaded_quicksort.h"
#include "multithreaded_mergesort.h"

void print_sorted(int *arr, int sz) {
    if (std::is_sorted(arr, arr + sz)) {
        std::cout << "Sorted";
    }
    else {
        std::cout << "Not sorted";
    }
    std::cout << std::endl;
}

void test_one_thread_mergesort(const int *arr, int size) {
    std::cout << "One thread test:" << std::endl;
    int *copy = new int[size];
    for (int i = 0; i < size; i++) {
        copy[i] = arr[i];
    }
    auto start = std::chrono::steady_clock::now();
    mt_mergesort(copy, size, 0);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = end - start;
    std::cout <<"mt_mergesort: " <<std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << '\n';
    delete[]copy;
}

void test_one_thread_quicksort(const int *arr, int size) {
    std::cout << "One thread test:" << std::endl;
    int *copy = new int[size];
    for (int i = 0; i < size; i++) {
        copy[i] = arr[i];
    }
    auto start = std::chrono::steady_clock::now();
    mt_quicksort(copy, size, 0);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = end - start;
    std::cout <<"mt_quicksort: " <<std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << '\n';
    delete[]copy;
}

void test_two_thread_mergesort(const int *arr, int size) {
    std::cout << "Two thread test:" << std::endl;
    int *copy = new int[size];
    for (int i = 0; i < size; i++) {
        copy[i] = arr[i];
    }
    auto start = std::chrono::steady_clock::now();
    mt_mergesort(copy, size, 1);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = end - start;
    std::cout <<"mt_mergesort: " <<std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << '\n';
    delete[]copy;
}

void test_two_thread_quicksort(const int *arr, int size) {
    std::cout << "Two thread test:" << std::endl;
    int *copy = new int[size];
    for (int i = 0; i < size; i++) {
        copy[i] = arr[i];
    }
    auto start = std::chrono::steady_clock::now();
    mt_quicksort(copy, size, 1);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = end - start;
    std::cout <<"mt_quicksort: " <<std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << '\n';
    delete[]copy;
}

void test_four_thread_quicksort(const int *arr, int size) {
    std::cout << "Four thread test:" << std::endl;
    int *copy = new int[size];
    for (int i = 0; i < size; i++) {
        copy[i] = arr[i];
    }
    auto start = std::chrono::steady_clock::now();
    mt_quicksort(copy, size, 2);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = end - start;
    std::cout <<"mt_quicksort: " <<std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << '\n';
    delete[]copy;
}

void test_four_thread_mergesort(const int *arr, int size) {
    std::cout << "Four thread test:" << std::endl;
    int *copy = new int[size];
    for (int i = 0; i < size; i++) {
        copy[i] = arr[i];
    }
    auto start = std::chrono::steady_clock::now();
    mt_mergesort(copy, size, 2);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = end - start;
    std::cout <<"mt_mergesort: " <<std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << '\n';
    delete[]copy;
}

int main()
{
    // генерируем массив чисел в обратном убыванию порядке
    int *arr = new int[1000 * 1000];
    for (int i = 0; i < 1000000; i++) {
        arr[i] = 1000000 - i;
    }
    std::cout << "Tests for array with numbers in descending order" << std::endl;

    test_one_thread_quicksort(arr, 1000 * 1000);
    test_one_thread_mergesort(arr, 1000 * 1000);
    test_two_thread_quicksort(arr, 1000 * 1000);
    test_two_thread_mergesort(arr, 1000 * 1000);
    test_four_thread_quicksort(arr, 1000 * 1000);
    test_four_thread_mergesort(arr, 1000 * 1000);

    auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    for (int i = 0; i < 1000 * 1000; i++) {
        if (gen()) {
            arr[i] = i + (gen() ? 1000 : 200);
        }
        else {
            arr[i] = i - (gen() ? 44 : 22);
        }
    }
    std::cout << std::endl;
    std::cout << "Tests for array with numbers in random order" << std::endl;

    test_one_thread_quicksort(arr, 1000 * 1000);
    test_one_thread_mergesort(arr, 1000 * 1000);
    test_two_thread_quicksort(arr, 1000 * 1000);
    test_two_thread_mergesort(arr, 1000 * 1000);
    test_four_thread_quicksort(arr, 1000 * 1000);
    test_four_thread_mergesort(arr, 1000 * 1000);
    std::cout << std::endl;
    for (int i = 0; i < 1000000; i++) {
        arr[i] = i;
    }
    std::cout << "Already sorted array" << std::endl;
    test_one_thread_quicksort(arr, 1000 * 1000);
    test_one_thread_mergesort(arr, 1000 * 1000);
    test_two_thread_quicksort(arr, 1000 * 1000);
    test_two_thread_mergesort(arr, 1000 * 1000);
    test_four_thread_quicksort(arr, 1000 * 1000);
    test_four_thread_mergesort(arr, 1000 * 1000);


    delete[]arr;
    return 0;
}
