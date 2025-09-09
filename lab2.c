#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Point;

int dist(Point a, Point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy; // без извлечения корня
}

// Пузырьковая сортировка
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int isSquare(Point dots[]) {
    int dists[6];
    int idx = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            dists[idx++] = dist(dots[i], dots[j]);
        }
    }

    bubbleSort(dists, 6);

    // Если точки совпадают, то после сортировки в начале массива будет 0
    if (dists[0] == 0) return 0;

    int sidesEqual = (dists[0] == dists[1]) && (dists[1] == dists[2]) && (dists[2] == dists[3]);
    int diagonalsEqual = (dists[4] == dists[5]);

    return sidesEqual && diagonalsEqual;
}

int main() {
    FILE *fin = fopen("dots.txt", "r");
    if (!fin) {
        printf("Файл dots.txt создан. Внесите в него координаты четырёх точек\n");
        FILE *fout = fopen("dots.txt", "w");
        for (int i = 0; i < 4; i++) {
            fprintf(fout, "%-5d		%d\n", 0, 0);
        }
        return 1;
    }

    Point dots[4];
    int count = 0;

    while (count < 4 && fscanf(fin, "%d %d", &dots[count].x, &dots[count].y) == 2) {
        count++;
    }
    fclose(fin);

    if (count != 4) {
        printf("Не найдено 4 точки.\n");
        return 1;
    }

    FILE *fout = fopen("out.txt", "w");

    fprintf(fout, "Точки, указанные при вводе\n");
    for (int i = 0; i < 4; i++) {
        fprintf(fout, "x: %d, y: %d\n", dots[i].x, dots[i].y);
    }

    if (isSquare(dots)) {
        fprintf(fout, "Образуют квадрат\n");
    } else {
        fprintf(fout, "Не образуют квадрат\n");
    }

    fclose(fout);
    return 0;
}
