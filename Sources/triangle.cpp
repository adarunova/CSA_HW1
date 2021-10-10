
// triangle.cpp - содержит функции обработки треугольника.

#include <stdio.h>
#include <math.h>
#include "../Headers/triangle.h"

// Ввод параметров треугольника из файла.
void In(triangle &t, FILE *fileIn) {
    fscanf(fileIn, "%d %d %d %d %d %d", &t.x1, &t.y1, &t.x2, &t.y2, &t.x3, &t.y3);
    // Проверка на то, что координаты находятся на одной линии.
    if ((t.x3 - t.x2) * (t.y2 - t.y1) == (t.y3 - t.y2) * (t.x2 - t.x1)) {
        printf("Incorrect TRIANGLE. All coordinates are on one line. The TRIANGLE will be randomly generated.\n");
        InRandom(t);
    }
}

// Случайный ввод параметров треугольника.
void InRandom(triangle &t) {
    t.x1 = Random(-100, 100);
    t.y1 = Random(-100, 100);
    t.x2 = Random(-100, 100);
    t.x3 = Random(-100, 100);
    // Генерируем y2 так, чтобы точки (x1, y1) и (x2, y2) не совпадали.
    do {
        t.y2 = Random(-100, 100);
    } while (t.x1 == t.x2 && t.y1 == t.y2);
    // Генерируем y3 так, чтобы точки (x1, y1), (x2, y2) и (x3, y3) не лежали на одной прямой.
    do {
        t.y3 = Random(-100, 100);
    } while ((t.x3 - t.x2) * (t.y2 - t.y1) == (t.y3 - t.y2) * (t.x2 - t.x1));
}

// Вывод параметров треугольника в файл.
void Out(triangle &t, FILE *fileOut) {
    fprintf(fileOut,
            "It is TRIANGLE. Coordinates of vertices: (%d, %d), (%d, %d), (%d, %d). Perimeter =  %f;",
            t.x1, t.y1, t.x2, t.y2, t.x3, t.y3, Perimeter(t));
}

// Вычисление периметра треугольника.
double Perimeter(triangle &t) {
    return sqrt(pow(t.x1 - t.x2, 2) + pow(t.y1 - t.y2, 2)) +
           sqrt(pow(t.x2 - t.x3, 2) + pow(t.y2 - t.y3, 2)) +
           sqrt(pow(t.x1 - t.x3, 2) + pow(t.y1 - t.y3, 2));
}
