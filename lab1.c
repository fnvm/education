#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int waitUser() {
    while (1) {
        printf("\n[1 - выйти в меню] [0 - выйти из программы]\n");
        int ch;
        scanf("%d", &ch);

        switch (ch) {
            case 1:
            	printf("\n");
                return 1; // возврат по стеку
            case 0:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Некорректный ввод.\n");
        }
    }
}

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void printNums() {
    printf("\nПолучить таблицу квадратов пяти положительных нечётных чисел, идущих после введённого числа.\nВведите число: ");
    int ch;
    scanf("%d", &ch);

    if (ch < 0) ch = 0;

    int numbers[5];
    int squares[5];
    int count = 0;
    int check = ch;

    while (count < 5) {
        check++;
        if (check % 2 != 0) {
            numbers[count] = check;
            squares[count] = check * check;
            count++;
        }
    }

    printf("\n%-15s %s\n", "Число", "Квадрат");
    for (int i = 0; i < 5; i++) {
        printf("%-10d %d\n", numbers[i], squares[i]);
    }

    waitUser();
}

void checkPrimeNumber() {
    printf("Введите число: ");
    int num;
    scanf("%d", &num);

    if (num <= 0) {
        printf("Не натуральное число.\n");
    } else if (isPrime(num)) {
        printf("%d — простое число!\n", num);
    } else {
        printf("%d — составное число.\n", num);
    }

    waitUser();
}

void printMainMenu() {
    while (1) {
        printf("1 - вывести квадраты первых пяти нечетных чисел после n-числа.\n");
        printf("2 - проверка на простое число.\n");
        printf("0 - выйти.\n");
        printf("========================================\n");
        printf("Выберите опцию: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printNums();
                break;
            case 2:
                checkPrimeNumber();
                break;
            case 0:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Некорректный ввод.\n\n");
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    printf("Добро пожаловать!\n");
    printMainMenu();
    return 0;
}
