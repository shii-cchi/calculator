#ifndef SRC_PARS_H_
#define SRC_PARS_H_

#include "stack.h"

int str_to_reverse_polish(char *str_input, lexeme *reverse_polish);
int define_lex(char *str_input, lexeme *lex, int index_input, int *status);
char is_num(char *str_input, int *index_input, double *number, int *sign);
char is_operator(char *str_input, int *index_input);
char is_func(char *str_input, int *index_input);
char is_bracket(char *str_input, int *index_input);
char *copy_str(const char *str_input, char *new_str, int index_input);
int get_prior(lexeme lex);

#endif  // SRC_PARS_H_