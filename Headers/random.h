#ifndef HW1_RANDOM_H
#define HW1_RANDOM_H

// random.h - содержит генератор случайных чисел в диапазоне от min до max.

#include <stdlib.h>

// Генерирует числа в диапазоне от min до max.
inline auto Random(int min, int max) {
    return rand() % (max - min) + min;
}

#endif //HW1_RANDOM_H
