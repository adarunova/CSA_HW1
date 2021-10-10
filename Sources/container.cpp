
// container.cpp - содержит функции обработки контейнера.

#include "../Headers/container.h"

// Инициализация контейнера.
void Init(container &c) {
    c.length = 0;
}

// Очистка контейнера от элементов (освобождение памяти).
void Clear(container &c) {
    for (int i = 0; i < c.length; i++) {
        delete c.cont[i];
    }
    c.length = 0;
}

// Ввод содержимого контейнера из указанного файла.
void In(container &c, FILE *fileIn) {
    int key = 0;
    while (fscanf_s(fileIn, "%d", &key) != EOF) {
        if (c.length >= c.max_length) {
            In(fileIn, key);
            c.length++;
        } else if ((c.cont[c.length] = In(fileIn, key)) != nullptr) {
            c.length++;
        }
    }
}

// Случайный ввод содержимого контейнера.
void InRandom(container &c, int size) {
    while (c.length < size) {
        if ((c.cont[c.length] = InRandom()) != nullptr) {
            ++c.length;
        }
    }
}

// Вывод содержимого контейнера в указанный файл.
void Out(container &c, FILE *fileOut) {
    fprintf(fileOut, "Container contains %d elements.\n", c.length);
    for (int i = 0; i < c.length; i++) {
        fprintf(fileOut, "%d: ", i);
        Out(*(c.cont[i]), fileOut);
    }
}

// Отчистка контейнера от фигур с периметром, меньшим среднего значаения.
void DeleteElements(container &c) {
    container newContainer;
    double perimeters[c.max_length];
    double averagePerimeter = 0.0;
    // Считаем сумму периметров всех фигур.
    for (int i = 0; i < c.length; ++i) {
        perimeters[i] = Perimeter(*c.cont[i]);
        averagePerimeter += perimeters[i];
    }
    // Находим среднее значение периметров.
    averagePerimeter /= c.length;
    int index = 0;
    // Кладём в массив только те фигуры, у которых периметр больше среднего.
    for (int i = 0; i < c.length; i++) {
        if (perimeters[i] >= averagePerimeter) {
            newContainer.cont[index] = c.cont[i];
            ++index;
        }
    }
    c = newContainer;
    c.length = index;
    Clear(newContainer);
}
