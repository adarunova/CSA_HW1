#ifndef HW1_SHAPE_H
#define HW1_SHAPE_H

// shape.h - содержит описание обобщающей геометрической фигуры.

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

// Структура, обобщающая все имеющиеся фигуры.
struct shape {
    // Значения ключей для каждой из фигур.
    enum key {
        CIRCLE, RECTANGLE, TRIANGLE
    };
    // Ключ.
    key k;

    // Значения цветов для фигур.
    enum color {
        RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PURPLE
    };
    // Цвет.
    color col;

    union {
        circle c;
        rectangle r;
        triangle t;
    };
};

// Ввод обобщенной фигуры.
shape *In(FILE *fileIn, int key);

// Случайный ввод обобщенной фигуры.
shape *InRandom();

// Вывод обобщенной фигуры.
void Out(shape &s, FILE *fileOut);

// Вычисление периметра обобщенной фигуры.
double Perimeter(shape &s);

// Выводит цвет фигуры.
void Color(shape &s, FILE *fOut);

#endif //HW1_SHAPE_H
