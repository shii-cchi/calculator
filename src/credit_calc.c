#include "credit_calc.h"

int credit_calculate(char *credit_data, double *max_payment, double *min_payment, double *overpayment, double *total_sum) {
    int status = 1, count_symb = 0;
    credit_t credit;
    clear(&credit);
    int count_assign = sscanf(credit_data, "%lf%d%lf %c%n", &credit.sum, &credit.term, &credit.percent, &credit.type, &count_symb);
    if (count_assign == 4 && count_symb == (int)strlen(credit_data)) {
        calc(&credit);
        *max_payment = credit.max_payment;
        *min_payment = credit.min_payment;
        *overpayment = credit.overpayment;
        *total_sum = credit.total_sum;
    } else {
        status = 0;
    }
    return status;
}

void clear(credit_t *credit) {
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
    credit->term = credit->term * 12;
    credit->percent = credit->percent / (12.0 * 100);
    if (credit->type == 'a') {
        credit->max_payment = credit->sum * (credit->percent + credit->percent / (pow(1 + credit->percent, credit->term) - 1));
        credit->total_sum = credit->max_payment * credit->term;
        credit->overpayment = credit->total_sum - credit->sum;
    } else if (credit->type == 'd') {
        double sum = credit->sum;
        double pay_without_percent = credit->sum / credit->term;
        credit->max_payment = credit->sum * credit->percent + pay_without_percent;
        while (sum > 0.1) {
            credit->total_sum += pay_without_percent + sum * credit->percent;
            credit->min_payment = pay_without_percent + sum * credit->percent;
            sum -= pay_without_percent;
        }
        credit->overpayment = credit->total_sum - credit->sum;
    }
}
