
// circle.cpp - содержит функции обработки круга.

#include <stdio.h>
#include <time.h>
#include "../Headers/circle.h"

// Число пи.
const double pi = 3.141592653;

// Ввод параметров круга из файла.
void In(circle &c, FILE *fileIn) {
    fscanf_s(fileIn, "%d %d %d", &c.x, &c.y, &c.radius);
    // Проверка на то, что радиус меньше нуля.
    if (c.radius <= 0) {
        printf("Incorrect CIRCLE. Radius cannot be zero or less. The CIRCLE will be randomly generated.\n");
        InRandom(c);
    }
}

// Случайный ввод параметров круга.
void InRandom(circle &c) {
    c.x = Random(-100, 100);
    c.y = Random(-100, 100);
    // Генерируем положительное число - радиус круга.
    do {
        c.radius = Random(0, 100);
    } while (c.radius <= 0);
}

// Вывод параметров круга в файл.
void Out(circle &c, FILE *fOut) {
    fprintf(fOut,
            "It is CIRCLE. Center coordinates: (%d, %d), radius: %d. Perimeter = %f;",
            c.x, c.y, c.radius, Perimeter(c));
}

// Вычисление периметра круга.
double Perimeter(circle &c) {
    return 2 * pi * c.radius;
}
