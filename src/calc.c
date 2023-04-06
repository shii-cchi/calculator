#include "calc.h"

int main() {
    char str_input[LEN] = "sin(5.5) * tan(3) + (42 - (4 * 2))";
    lexeme reverse_polish[LEN];
    for (int i = 0; i < LEN; i++) {
        clear_lexeme(&reverse_polish[i]);
    }
    str_to_reverse_polish(str_input, reverse_polish);
    output_arr(reverse_polish);
    double result = calculate_reverse_polish(reverse_polish);
    printf("%lf\n", result);
    return 0;
}

double calculate_reverse_polish(lexeme *reverse_polish) {
    double result = 0, num_1 = 0, num_2 = 0;
    int index_rev_pol = 0, index_num = 0;
    double numbers[LEN] = {0};
    while (reverse_polish[index_rev_pol].type != UNDEFINED) {
        if (reverse_polish[index_rev_pol].type == NUMBER) {
            numbers[index_num] = reverse_polish[index_rev_pol].number;
            index_num++;
            // for (int i = 0; i < 5; i++) {
            //     printf("1^ %lf\n", numbers[i]);
            // }
        }
        if (reverse_polish[index_rev_pol].type == FUNCTION) {
            numbers[index_num - 1] = calc_func(numbers[index_num - 1], reverse_polish[index_rev_pol].lexeme_kind);
            // for (int i = 0; i < 5; i++) {
            //     printf("2^ %lf\n", numbers[i]);
            // }
        }
        if (reverse_polish[index_rev_pol].type == OPERATOR) {
            if (reverse_polish[index_rev_pol].unary == 1) {
                numbers[index_num - 1] = calc_unary_op(numbers[index_num - 1], reverse_polish[index_rev_pol].lexeme_kind);
            } else {
                numbers[index_num - 2] = calc_op(numbers[index_num - 2], numbers[index_num - 1], reverse_polish[index_rev_pol].lexeme_kind);
                numbers[index_num - 1] = 0;
                index_num--;
            }
            // for (int i = 0; i < 5; i++) {
            //     printf("3^ %lf\n", numbers[i]);
            // }
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

double calc_unary_op(double number, char operator) {
    double result = 0;
    switch (operator) {
        case '-':
            result = -result;
            break;
        case '+':
        default:
            break;
        }
    return result;
}

double calc_op(double number_1, double number_2, char operator) {
    double result = 0;
    switch (operator) {
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