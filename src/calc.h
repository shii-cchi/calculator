#ifndef SRC_CALC_H_
#define SRC_CALC_H_

#include "pars.h"

int calculate(char *str_input, double *result);
int check_str_valid(char *str_input);
int check_dot_x(char *str_input);
int check_numbers(char *str_input);
int check_brackets(char *str_input);
int check_valid(lexeme *reverse_polish);
double calculate_reverse_polish(lexeme *reverse_polish);
double calc_func(double number, char function);
double calc_unary_op(double number, char op);
double calc_op(double number_1, double number_2, char op);

#endif  // SRC_CALC_H_
