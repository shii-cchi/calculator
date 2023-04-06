#ifndef SRC_CALC_H_
#define SRC_CALC_H_

#include "pars.h"

double calculate_reverse_polish(lexeme *reverse_polish);
double calc_func(double number, char function);
double calc_unary_op(double number, char operator);
double calc_op(double number_1, double number_2, char operator);

#endif  // SRC_CALC_H_