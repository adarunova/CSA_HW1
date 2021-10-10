
// rectangle.cpp - содержит процедуру ввода параметров для уже созданного прямоугольника.

#include <stdio.h>
#include "../Headers/rectangle.h"

// Ввод параметров прямоугольника из файла.
void In(rectangle &r, FILE *fileIn) {
    fscanf_s(fileIn, "%d %d %d %d", &r.x1, &r.y1, &r.x2, &r.y2);
    if ((r.x2 - r.x1) * (r.y1 - r.y2) == 0) {
        printf("Incorrect RECTANGLE. All coordinates are on one line. The RECTANGLE will be randomly generated.\n");
        InRandom(r);
    } else if ((r.x2 <= r.x1) || (r.y1 <= r.y2)) {
        printf("Incorrect RECTANGLE. Wrong corner coordinates! The RECTANGLE will be randomly generated.\n");
        InRandom(r);
    }
}

// Случайный ввод параметров прямоугольника.
void InRandom(rectangle &r) {
    r.x1 = Random(-100, 100);
    r.y1 = Random(-100, 100);
    r.x2 = Random(r.x1, 100 + r.x1);
    r.y2 = Random(r.y1, 100 + r.y1);
}

// Вывод параметров прямоугольника в файл.
void Out(rectangle &r, FILE *fileOut) {
    fprintf(fileOut,
            "It is RECTANGLE. Coordinates of angles: (%d, %d), (%d, %d). Perimeter = %f;",
            r.x1, r.y1, r.x2, r.y2, Perimeter(r));
}

// Вычисление периметра прямоугольника.
double Perimeter(rectangle &r) {
    return 2.0 * (abs(r.x1 - r.x2) + abs(r.y1 - r.y2));
}

