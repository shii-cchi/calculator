#include "calc.h"

// int main() {
//     char str[LEN] = "1 + 2 +";
//     double result = 0;
//     int status = calculate(str, &result);
//     printf("%f\n%d\n", result, status);
//     return 0;
// }

int calculate(char *str_input, double *result) {
    int status = 0;
    lexeme reverse_polish[LEN];
    for (int i = 0; i < LEN; i++) {
        clear_lexeme(&reverse_polish[i]);
    }
    if (check_str_valid(str_input)) {
        if (str_to_reverse_polish(str_input, reverse_polish)) {
            if (check_valid(reverse_polish)) {
                output_arr(reverse_polish);
                *result = calculate_reverse_polish(reverse_polish);
                status = 1;
            }
        }
    }
    return status;
}

int check_str_valid(char *str_input) {
    int status = 1;
    if (!check_dot_x(str_input)) {
        status = 0;
    }
    if (!check_numbers(str_input)) {
        status = 0;
    }
    return status;
}

int check_dot_x(char *str_input) {
    int status = 1;
    int count_dot = 0, count_x = 0;
    for (int i = 0; i < (int)strlen(str_input); i++) {
        if (str_input[i] == '.') {
            count_dot++;
            if (i == (int)strlen(str_input) - 1) {
                if (!isdigit(str_input[i - 1])) {
                    status = 0;
                }
            } else {
                if (!isdigit(str_input[i - 1]) && !isdigit(str_input[i + 1])) {
                    status = 0;
                }
            }
        }
        if (str_input[i] == 'x') {
            count_x++;
        }
        if (str_input[i] == ' ') {
            count_dot = 0;
            count_x = 0;
        }
        if (count_dot > 1 || count_x > 1) {
            status = 0;
            break;
        }
    }
    return status;
}

int check_numbers(char *str_input) {
    int status = 1;
    int digit = 0;
    for (int i = 0; i < (int)strlen(str_input); i++) {
        if (isdigit(str_input[i]) || str_input[i] == 'x') {
            digit++;
        }
    }
    if (digit == 0) {
        status = 0;
    }
    return status;
}

int check_valid(lexeme *reverse_polish) {
    int status = 1;
    int index = 0, unary = 0, operators = 0, functions = 0, numbers = 0;
    while (reverse_polish[index].type != UNDEFINED) {
        if (reverse_polish[index].type == NUMBER) {
            numbers++;
        }
        if (reverse_polish[index].type == OPERATOR) {
            if (reverse_polish[index].unary == 1) {
                unary++;
            } else {
                operators++;
            }
        }
        index++;
    }
    if (numbers < operators + 1 || unary > numbers) {
        status = 0;
    }
    printf("%d\n%d\n%d\n", numbers, operators, unary);
    return status;
}

double calculate_reverse_polish(lexeme *reverse_polish) {
    double result = 0;
    int index_rev_pol = 0, index_num = 0;
    double numbers[LEN] = {0};
    while (reverse_polish[index_rev_pol].type != UNDEFINED) {
        if (reverse_polish[index_rev_pol].type == NUMBER) {
            numbers[index_num] = reverse_polish[index_rev_pol].number;
            index_num++;
        }
        if (reverse_polish[index_rev_pol].type == FUNCTION) {
            numbers[index_num - 1] = calc_func(numbers[index_num - 1], reverse_polish[index_rev_pol].lexeme_kind);
        }
        if (reverse_polish[index_rev_pol].type == OPERATOR) {
            if (reverse_polish[index_rev_pol].unary == 1) {
                numbers[index_num - 1] = calc_unary_op(numbers[index_num - 1], reverse_polish[index_rev_pol].lexeme_kind);
            } else {
                numbers[index_num - 2] = calc_op(numbers[index_num - 2], numbers[index_num - 1], reverse_polish[index_rev_pol].lexeme_kind);
                numbers[index_num - 1] = 0;
                index_num--;
            }
        }
        index_rev_pol++;
    }
    result = numbers[index_num - 1];
    return result;
}

double calc_func(double number, char function) {
    double result = 0;
    switch (function) {
        case 's':
            result = sin(number);
            break;
        case 'c':
            result = cos(number);
            break;
        case 't':
            result = tan(number);
            break;
        case 'l':
            result = log10(number);
            break;
        case 'S':
            result = asin(number);
            break;
        case 'C':
            result = acos(number);
            break;
        case 'T':
            result = atan(number);
            break;
        case 'Q':
            result = sqrt(number);
            break;
        case 'L':
            result = log(number);
            break;  
        default:
            break;
        }
    return result;
}

double calc_unary_op(double number, char op) {
    switch (op) {
        case '-':
            number = -number;
            break;
        case '+':
        default:
            break;
        }
    return number;
}

double calc_op(double number_1, double number_2, char op) {
    double result = 0;
    switch (op) {
        case '+':
            result = number_1 + number_2;
            break;
        case '-':
            result = number_1 - number_2;
            break;
        case '*':
            result = number_1 * number_2;
            break;
        case '/':
            result = number_1 / number_2;
            break;
        case '^':
            result = pow(number_1, number_2);
            break;
        case 'm':
            result = fmod(number_1, number_2);
            break;
        default:
            break;
        }
    return result;
}
