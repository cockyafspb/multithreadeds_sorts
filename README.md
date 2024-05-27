# Многопоточный сортировки: слиянием и быстрая
### INFO: Приложение разработано под С++11
### О подходе: был использован параметр maxDepth, число потоков по нему будет равно 2^maxDepth.
### Результат: быстрая сортировка показала преимущество на любом количестве потоков на размере массива 1 миллион.
### Предположение: быстрая сортировка начнет проигрывать при размерах массива от 10 млн и выше, т.к. по асимптотике на некоторых тесткейсах будет проигрывать, а доп аллокация памяти у сортировки слиянием будет работать быстрее.
### Пример работы программы (резульат в миллисекундаx):
```
Tests for array with numbers in descending order
One thread test:
mt_quicksort: 32
One thread test:
mt_mergesort: 85
Two thread test:
mt_quicksort: 18
Two thread test:
mt_mergesort: 51
Four thread test:
mt_quicksort: 14
Four thread test:
mt_mergesort: 36

Tests for array with numbers in random order
One thread test:
mt_quicksort: 76
One thread test:
mt_mergesort: 105
Two thread test:
mt_quicksort: 46
Two thread test:
mt_mergesort: 57
Four thread test:
mt_quicksort: 27
Four thread test:
mt_mergesort: 40

Already sorted array
One thread test:
mt_quicksort: 29
One thread test:
mt_mergesort: 100
Two thread test:
mt_quicksort: 14
Two thread test:
mt_mergesort: 39
Four thread test:
mt_quicksort: 10
Four thread test:
mt_mergesort: 37
```
