#include "credit_calc.h"

void credit_calculate(const char *credit_data, char *result) {
    credit_t credit;
    clear(&credit);
    int count_assign = sscanf(credit_data, "%lf%d%lf %c", &credit.sum, &credit.term, &credit.percent, &credit.type);
    if (count_assign > 0) {
        calc(&credit);
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
