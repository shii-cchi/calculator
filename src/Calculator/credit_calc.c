#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#define LEN 255

typedef struct credit_data {
    double sum;
    double percent;
    int term;
    char type;
    double max_payment;
    double min_payment;
    double overpayment;
    double total_sum;
} credit_t;

void credit_calculate(const char *credit_data, char *result);
credit_t clear(credit_t *credit);
void calc(credit_t *credit);

int main() {
    char credit_data[LEN] = "5000000 120 6 a";
    char result[LEN] = {0};
    credit_calculate(credit_data, result);
    printf("%s\n", result);
    return 0;
}

void credit_calculate(const char *credit_data, char *result) {
    credit_t credit;
    clear(&credit);
    int count_assign = sscanf(credit_data, "%lf%d%lf %c", &credit.sum, &credit.term, &credit.percent, &credit.type);
    if (count_assign > 0) {
        calc(&credit);
        if (credit.type == 'a') {
            sprintf(result, "Ежемесячный платеж: %.2lf\n Переплата по кредиту: %.2lf\n Общая выплата: %.2lf", credit.max_payment, credit.overpayment, credit.total_sum);
        } else if (credit.type == 'd') {
            sprintf(result, "Ежемесячный платеж: %.2lf-%.2lf\n Переплата по кредиту: %.2lf\n Общая выплата: %.2lf", credit.max_payment, credit.min_payment, credit.overpayment, credit.total_sum);
        }
    } else {
        fprintf(stderr, "Error data\n");
    }
}

credit_t clear(credit_t *credit) {
    credit->sum = 0;
    credit->percent = 0;
    credit->term = 0;
    credit->type = 0;
    credit->max_payment = 0;
    credit->min_payment = 0;
    credit->overpayment = 0;
    credit->total_sum = 0;
}

void calc(credit_t *credit) {
    credit->percent = credit->percent / (12.0 * 100);
    if (credit->type == 'a') {
        credit->max_payment = credit->sum * (credit->percent + credit->percent / (pow(1 + credit->percent, credit->term) - 1));
        credit->total_sum = credit->max_payment * credit->term;
        credit->overpayment = credit->total_sum - credit->sum;
    } else if (credit->type == 'd') {
        double sum = credit->sum;
        double pay_without_percent = credit->sum / 120;
        credit->max_payment = credit->sum * credit->percent + pay_without_percent;
        while (sum > 0.1) {
            credit->total_sum += pay_without_percent + sum * credit->percent;
            credit->min_payment = pay_without_percent + sum * credit->percent;
            sum -= pay_without_percent;
        }
        credit->overpayment = credit->total_sum - credit->sum;
    }
}