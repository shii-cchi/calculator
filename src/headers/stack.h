#ifndef SRC_HEADERS_STACK_H_
#define SRC_HEADERS_STACK_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 255

enum lexeme_type { NUMBER, OPERATOR, FUNCTION, BRACKET, UNDEFINED };

typedef struct lexemes {
  enum lexeme_type type;
  char lexeme_kind;  // mod - m, cos - c, sin - s, tan - t, acos - C, asin - S,
                     // atan - T, sqrt - Q, log - l, ln - L
  double number;
  int unary;
} lexeme;

typedef struct stack_operators {
  lexeme items[LEN];
  int top;
} stack;

void stack_init(stack *operators);
int is_empty_stack(stack *operators);
int is_full_stack(stack *operators);
void push(stack *operators, lexeme *new_item);
void pop(stack *operators);
lexeme peek(stack *operators);
// void output_stack(stack *operators);
// void output_arr(lexeme *arr);
void clear_lexeme(lexeme *lex);

#endif  // SRC_HEADERS_STACK_H_
