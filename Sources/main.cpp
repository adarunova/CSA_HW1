
// main.cpp - содержит главную функцию, обеспечивающую простое тестирование.

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "../Headers/container.h"

void errMessage1() {
    printf("Incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile1 outfile2\n"
           "  Or:\n"
           "     command -n number outfile1 outfile2\n");
}

void errMessage2() {
    printf("Incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile1 outfile2\n"
           "  Or:\n"
           "     command -n number outfile1 outfile2\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    container c;
    Init(c);

    srand(static_cast<unsigned int>(time(nullptr)));

    if (!strcmp(argv[1], "-f")) {
        FILE *fileIn = fopen(argv[2], "r");
        if (fileIn == nullptr) {
            printf("Cannot find file with name %s\n", argv[2]);
            return 3;
        }
        In(c, fileIn);
        fclose(fileIn);
        if (c.length < 1 || c.length >= container::max_length) {
            printf("Incorrect number of figures = %d. Set 0 < number <= %d\n", c.length, container::max_length);
            return 3;
        }
    } else if (!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if ((size < 1) || (size > container::max_length)) {
            printf("Incorrect number of figures > %d. Set 0 < number <= %d\n", size, container::max_length);
            return 3;
        }
        InRandom(c, size);
    } else {
        errMessage2();
        return 2;
    }

    // Поток вывода контейнера.
    FILE *fileOut1 = fopen(argv[3], "w");
    fprintf(fileOut1, "Filled container:\n");
    Out(c, fileOut1);
    fclose(fileOut1);

    // Поток вывода контейнера с удалёнными фигурами.
    FILE *fileOut2 = fopen(argv[4], "w");
    DeleteElements(c);
    fprintf(fileOut2, "Container with deleted elements:\n");
    Out(c, fileOut2);
    fclose(fileOut2);

    Clear(c);

    printf("Stop\n");
    return 0;
}
