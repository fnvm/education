#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Stack {
    int elem[100];
    int count;
};

void initStack(struct Stack *stack) {
    stack->count = 0;
}

void sort(struct Stack *stack) {
    int n = stack->count;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (stack->elem[j] > stack->elem[j + 1]) {
                int tmp = stack->elem[j];
                stack->elem[j] = stack->elem[j + 1];
                stack->elem[j + 1] = tmp;
            }
        }
    }
}

int isEmpty(struct Stack *stack) {
    return stack->count == 0;
}

void add(struct Stack *stack, int value) {
    if (stack->count < 100) {
        stack->elem[stack->count++] = value;
    }
}

int pop(struct Stack *stack) {
    if (stack->count > 0) {
        return stack->elem[--stack->count];
    } else {
        printf("Стек пуст!\n");
        return 0;
    }
}

int getTopElement(struct Stack *stack) {
    if (stack->count > 0) {
        return stack->elem[stack->count - 1];
    } else {
        printf("Стек пуст!\n");
        return 0;
    }
}

void printStack(struct Stack *stack) {
    for (int i = 0; i < stack->count; i++) {
        printf("%d ", stack->elem[i]);
    }
    printf("\n");
}

void fillStackRandom(struct Stack *stack, int count) {
    srand(time(NULL));
    for (int i = 0; i < count / 2; i++) {
        add(stack, rand() % 50 + 1);
        add(stack, -(rand() % 50 + 1));
    }
}

int main() {
    struct Stack s1, s2, temp;
    initStack(&s1);
    initStack(&s2);
    initStack(&temp);

    fillStackRandom(&s1, 100);
    sort(&s1);

    printf("Исходный стек:\n");
    printStack(&s1);

     while (!isEmpty(&s1)) {
        int val = pop(&s1);
        if (val < 0 && val % 3 == 0) {
            add(&s2, val);
        }
        add(&temp, val); // сохраняем, чтобы потом вернуть
    }

    // Восстанавливаем исходный стек
    while (!isEmpty(&temp)) {
        add(&s1, pop(&temp));
    }

    printf("Новый стек (отрицательные, кратные 3):\n");
    printStack(&s2);

    return 0;
}
