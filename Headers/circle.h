#ifndef HW1_CIRCLE_H
#define HW1_CIRCLE_H

// triangle.h - содержит описание круга.

#include "random.h"

// Круг.
struct circle {
    // Координаты центра.
    int x, y;
    // Радиус.
    int radius;
};

// Ввод параметров круга из файла.
void In(circle &c, FILE *fileIn);

// Случайный ввод параметров круга.
void InRandom(circle &c);

// Вывод параметров круга в файл.
void Out(circle &c, FILE *fileOut);

// Вычисление периметра круга.
double Perimeter(circle &c);

#endif //HW1_CIRCLE_H
