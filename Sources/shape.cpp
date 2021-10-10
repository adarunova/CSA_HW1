
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры и создания произвольной фигуры.

#include <stdio.h>
#include <time.h>
#include "../Headers/shape.h"

// Ввод параметров обобщенной фигуры из файла.
shape *In(FILE *fileIn, int key) {
    shape *s;
    int color;
    fscanf_s(fileIn, "%d", &color);

    if (color > 6 || color < 0) {
        printf("Incorrect color! The COLOR will be randomly generated.\n");
        color = rand() % 7;
    }
    switch (key) {
        case 1:
            s = new shape;
            s->k = shape::CIRCLE;
            s->col = static_cast<shape::color>(color);
            In(s->c, fileIn);
            return s;
        case 2:
            s = new shape;
            s->k = shape::RECTANGLE;
            s->col = static_cast<shape::color>(color);
            In(s->r, fileIn);
            return s;
        case 3:
            s = new shape;
            s->k = shape::TRIANGLE;
            s->col = static_cast<shape::color>(color);
            In(s->t, fileIn);
            return s;
        default:
            printf("Incorrect shape!\n");
            return nullptr;
    }
}

// Случайный ввод обобщенной фигуры.
shape *InRandom() {
    shape *s;
    // Генерируем число, которыму соответствует одна из фигур.
    auto key = rand() % 3 + 1;
    // Генерируем число, которыму соответствует один из цветов.
    auto color = rand() % 7;
    switch (key) {
        case 1:
            s = new shape;
            s->k = shape::CIRCLE;
            s->col = static_cast<shape::color>(color);
            InRandom(s->c);
            return s;
        case 2:
            s = new shape;
            s->k = shape::RECTANGLE;
            s->col = static_cast<shape::color>(color);
            InRandom(s->r);
            return s;
        case 3:
            s = new shape;
            s->k = shape::TRIANGLE;
            s->col = static_cast<shape::color>(color);
            InRandom(s->t);
            return s;
        default:
            return nullptr;
    }
}

// Вывод параметров текущей фигуры в файл.
void Out(shape &s, FILE *fileOut) {
    switch (s.k) {
        case shape::CIRCLE:
            Out(s.c, fileOut);
            break;
        case shape::RECTANGLE:
            Out(s.r, fileOut);
            break;
        case shape::TRIANGLE:
            Out(s.t, fileOut);
            break;
        default:
            fprintf(fileOut, "Incorrect figure!\n");
            return;
    }
    Color(s, fileOut);
}

// Вычисление периметра фигуры.
double Perimeter(shape &s) {
    switch (s.k) {
        case shape::CIRCLE:
            return Perimeter(s.c);
        case shape::RECTANGLE:
            return Perimeter(s.r);
        case shape::TRIANGLE:
            return Perimeter(s.t);
        default:
            return 0.0;
    }
}

// Выводит цвет фигуры.
void Color(shape &s, FILE *fOut) {
    switch (s.col) {
        case shape::color::RED:
            fprintf(fOut, " Color: RED\n");
            break;
        case shape::color::ORANGE:
            fprintf(fOut, " Color: ORANGE\n");
            break;
        case shape::color::YELLOW:
            fprintf(fOut, " Color: YELLOW\n");
            break;
        case shape::color::GREEN:
            fprintf(fOut, " Color: GREEN\n");
            break;
        case shape::color::CYAN:
            fprintf(fOut, " Color: CYAN\n");
            break;
        case shape::color::BLUE:
            fprintf(fOut, " Color: BLUE\n");
            break;
        case shape::color::PURPLE:
            fprintf(fOut, " Color: PURPLE\n");
            break;
    }
}
