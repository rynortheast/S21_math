#include "s21_math.h"

long double s21_sin(double num) {
    int status = 1, sign = 1;
    long double sum = (long double) num;
    if (s21_isNAN(num) || s21_isINF(num)) {
        status = 0;
    } else {

        num = fmod(num, s21_PI * 2);

        if (num > (s21_PI / 2.0) && num <= s21_PI) {
            num = s21_PI - num;
        } else if (num > s21_PI && num <= ((s21_PI * 3.0) / 2.0)) {
            num -= s21_PI;
            sign *= (-1);
        } else if (num > ((s21_PI * 3.0) / 2.0) && num <= (s21_PI * 2.0)) {
            num = (2 * s21_PI) - num;
            sign *= (-1);
        }

        sum = (long double) num;
        long double tailor = (long double) num;
        for (int p = 1; fabsl(tailor / num) > 1e-100; p += 1) {
            tailor = (-tailor * num * num) / ((2.0 * p + 1) * (2.0 * p));
            sum += tailor;
        }

    }
    return status ? (sum * sign) : s21_NAN;
}
