#ifndef HW1_TRIANGLE_H
#define HW1_TRIANGLE_H

// triangle.h - содержит описание треугольника.

# include "random.h"

// Треугольник.
struct triangle {
    // Координаты вершин.
    int x1, y1;
    int x2, y2;
    int x3, y3;
};

// Ввод параметров треугольника из файла.
void In(triangle &t, FILE *fileIn);

// Случайный ввод параметров треугольника.
void InRandom(triangle &t);

// Вывод параметров треугольника в файл.
void Out(triangle &t, FILE *fileOut);

// Вычисление периметра треугольника.
double Perimeter(triangle &t);

#endif //HW1_TRIANGLE_H
