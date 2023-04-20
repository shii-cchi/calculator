#include "stack.h"

void stack_init(stack *operators) {  // инициализация пустого стека
    operators->top = -1;
}

int is_empty_stack(stack *operators) {  // проверка стека на пустоту, 1 - стек пустой, 0 - непустой
    int status = 0;
    if (operators->top == -1) {
        status = 1;
    }
    return status;
}

int is_full_stack(stack *operators) {  // проверка стека на заполненность, 1 - стек полон, 0 - не полон
    int status = 0;
    if (operators->top == LEN - 1) {
        status = 1;
    }
    return status;
}

void push(stack *operators, lexeme *new_item) {  // добавление элемента в стек
    if (is_full_stack(operators)) {
        fprintf(stderr, "stack overflow\n");
    } else {
        operators->top++;
        operators->items[operators->top] = *new_item;
    }
}

void pop(stack *operators) {  // удаление верхнего элемента из стека
    if (is_empty_stack(operators)) {
        fprintf(stderr, "stack is empty\n");
    } else {
        clear_lexeme(&(operators->items[operators->top]));
        operators->top--;
    }
}

lexeme peek(stack *operators) {  // возвращение верхнего элемента стека
    lexeme elem;
    clear_lexeme(&elem);
    if (!is_empty_stack(operators)) {
        elem = operators->items[operators->top];
    }
    return elem;
}

void output_stack(stack *operators) {  // вывод стека
    for (int i = 0; i <= operators->top; i++) {
        printf("элемент %d", i);
        printf(": type = %d kind = %d number = %lf sign = %d unary = %d\n", operators->items[i].type, operators->items[i].lexeme_kind, operators->items[i].number, operators->items[i].sign, operators->items[i].unary);
    }
}

void output_arr(lexeme *arr) {  // вывод выходной строки
    for (int i = 0; i < 13; i++) {
        printf("элемент %d", i);
        printf(": type = %d kind = %d number = %lf sign = %d unary = %d\n", arr[i].type, arr[i].lexeme_kind, arr[i].number, arr[i].sign, arr[i].unary);
    }
}

void clear_lexeme(lexeme *lex) {
    if (lex != NULL) {
        lex->type = UNDEFINED;
        lex->lexeme_kind = 0;
        lex->number = 0;
        lex->sign = 0;
        lex->unary = 0;
    }
}