#ifndef HW1_CONTAINER_H
#define HW1_CONTAINER_H

// container.h - содержит тип данных, представляющий простейший контейнер.

#include <stdio.h>
#include "shape.h"

// Простейший контейнер на основе одномерного массива
struct container {
    enum {
        // Максимальная длина.
        max_length = 10000
    };
    // Текущая длина.
    int length;
    shape *cont[max_length];
};

// Инициализация контейнера.
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти).
void Clear(container &c);

// Ввод содержимого контейнера из указанного файла.
void In(container &c, FILE *fileIn);

// Случайный ввод содержимого контейнера.
void InRandom(container &c, int size);

// Вывод содержимого контейнера в указанный файл.
void Out(container &c, FILE *fileOut);

// Отчистка контейнера от фигур с периметром, меньшим среднего значаения.
void DeleteElements(container &c);

#endif //HW1_CONTAINER_H
