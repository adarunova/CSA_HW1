#ifndef HW1_RECTANGLE_H
#define HW1_RECTANGLE_H

// rectangle.h - содержит описание прямоугольника.

#include "random.h"

// Прямоугольник.
struct rectangle {
    // Координаты левой верхней вершины.
    int x1, y1;
    // Координаты правой нижней вершины.
    int x2, y2;
};

// Ввод параметров прямоугольника из файла.
void In(rectangle &r, FILE *fileIn);

// Случайный ввод параметров прямоугольника.
void InRandom(rectangle &r);

// Вывод параметров прямоугольника в файл.
void Out(rectangle &r, FILE *fileOut);

// Вычисление периметра прямоугольника.
double Perimeter(rectangle &r);

#endif //HW1_RECTANGLE_H
