#include "pars.h"

int str_to_reverse_polish(char *str_input, lexeme *reverse_polish) {
    stack queue;
    stack_init(&queue);
    lexeme lex;
    int length_input = (int)strlen(str_input);
    int index_input = 0, index_output = 0, status = 1;
    while (index_input < length_input) {
        index_input = define_lex(str_input, &lex, index_input, &status);
        if (lex.type == NUMBER) {
            reverse_polish[index_output] = lex;
            index_output++;
        }
        if (lex.type == FUNCTION || lex.lexeme_kind == '(') {
            push(&queue, &lex);         
        }
        if (lex.lexeme_kind == ')') {
            while(peek(&queue).lexeme_kind != '(') {
                reverse_polish[index_output] = peek(&queue);
                index_output++;
                pop(&queue);
                if (is_empty_stack(&queue)) {
                    fprintf(stderr, "Error\n");
                    break;
                }
            }
            pop(&queue);
        }
        if (lex.type == OPERATOR) {
            while (peek(&queue).type == FUNCTION ||
            (peek(&queue).type == OPERATOR && get_prior(peek(&queue)) <= get_prior(lex))) {
                reverse_polish[index_output] = peek(&queue);
                index_output++;
                pop(&queue);
            }
            push(&queue, &lex);
        }
        if (str_input[index_input] == ' ') {
            index_input++;
        }
    }
    while (is_empty_stack(&queue) != 1) {
        reverse_polish[index_output] = peek(&queue);
        index_output++;
        pop(&queue);
    }
    return status;
}

int define_lex(char *str_input, lexeme *lex, int index_input, int *status) {
    clear_lexeme(lex);
    char lex_kind = 0;
    double number = 0;
    int sign = 1;
    if (lex_kind = is_operator(str_input, &index_input)) {
        lex->type = OPERATOR;
        lex->lexeme_kind = lex_kind;
        if (strchr("+-", lex_kind) && (str_input[index_input] == 'x' || isdigit(str_input[index_input]))) {
            lex->unary = 1;
        }
    } else if (lex_kind = is_func(str_input, &index_input)) {
        lex->type = FUNCTION;
        lex->lexeme_kind = lex_kind;
    } else if (lex_kind = is_bracket(str_input, &index_input)) {
        lex->type = BRACKET;
        lex->lexeme_kind = lex_kind;
    } else if (lex_kind = is_num(str_input, &index_input, &number, &sign)) {
        lex->type = NUMBER;
        lex->lexeme_kind = lex_kind;
        lex->number = number;
        lex->sign = sign;
    } else {
        *status = 0;
    }
    return index_input;
}

char is_num(char *str_input, int *index_input, double *number, int *sign) {
    char status = 0;
    int count_symbol = 0;
    char new_str[LEN] = {0};
    copy_str(str_input, new_str, *index_input);
    if (sscanf(new_str, "%lf%n", number, &count_symbol) > 0) {
        *index_input += count_symbol;
        status = 1;
    } else {
        if (str_input[*index_input] == 'x') {
            status = 'x';
            *index_input += 1;
        } else if ((str_input[*index_input] == '-' || str_input[*index_input] == '+') && str_input[*index_input + 1] == 'x') {
            if (str_input[*index_input] == '-') {
                *sign = -1;
            }
            status = 'x';
            *index_input += 2;
        }
    }
    return status;
}

char is_operator(char *str_input, int *index_input) {
    char status = 0;
    if (strchr("+-*/^", str_input[*index_input])) {
        status = str_input[*index_input];
        *index_input += 1; 
    } else if (strstr(str_input, "mod") - str_input == *index_input) {
        status = 'm';
        *index_input += 3;
    }
    return status;
}

char is_func(char *str_input, int *index_input) {
    char status = 0;
    if (strstr(str_input, "sin") - str_input == *index_input || 
    strstr(str_input, "cos") - str_input == *index_input || 
    strstr(str_input, "tan") - str_input == *index_input || 
    strstr(str_input, "log") - str_input == *index_input) {
        status = str_input[*index_input];
        *index_input += 3;   
    } else if (strstr(str_input, "asin") - str_input == *index_input || 
    strstr(str_input, "acos") - str_input == *index_input || 
    strstr(str_input, "atan") - str_input == *index_input || 
    strstr(str_input, "sqrt") - str_input == *index_input) {
        status = str_input[*index_input + 1] - 32;
        *index_input += 4;  
    } else if (strstr(str_input, "ln") - str_input == *index_input) {
        status = str_input[*index_input] - 32;
        *index_input += 2;          
    }
    return status;
}

char is_bracket(char *str_input, int *index_input) {
    char status = 0;
    if (str_input[*index_input] == '(' || str_input[*index_input] == ')') {
        status = str_input[*index_input];
        *index_input += 1;
    }
    return status;
}

char *copy_str(const char *str_input, char *new_str, int index_input) {
    for (int i = 0; i < (int)strlen(str_input) - index_input; i++) {
        new_str[i] = str_input[index_input + i];
    }
    return new_str;
}

int get_prior(lexeme lex) {
    int prior = 0;
    if (lex.lexeme_kind == '^') {
        prior = 2;
    } else if (strchr("*/msctlSCTQL", lex.lexeme_kind)) {
        prior = 3;
    } else if (lex.lexeme_kind == '+' || lex.lexeme_kind == '-') {
        if (lex.unary == 0) {
            prior = 4;
        } else {
            prior = 1;
        }
    }
    return prior;
}
