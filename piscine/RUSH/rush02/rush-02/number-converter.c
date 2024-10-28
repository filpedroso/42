#include "rush-02.h"

int convert_and_print(t_dict *dict, const char *number_str) {
    unsigned long long num = strtoull(number_str, NULL, 10);
    return print_number(dict, num);
}

int print_number(t_dict *dict, unsigned long long num) {
    if (num == 0) {
        return print_word(dict, 0);
    }

    int first = 1;
    unsigned long long scale = 1000000000000000000ULL;  // 10^18

    while (scale > 0) {
        unsigned long long quotient = num / scale;
        if (quotient > 0) {
            if (!first) {
                write(1, " ", 1);
            }
            if (!print_triple(dict, quotient)) {
                return 0;
            }
            if (scale > 1 && !print_word(dict, scale)) {
                return 0;
            }
            first = 0;
        }
        num %= scale;
        scale /= 1000;
    }

    write(1, "\n", 1);
    return 1;
}

int print_triple(t_dict *dict, unsigned long long num) {
    unsigned long long hundreds = num / 100;
    unsigned long long tens = num % 100;

    if (hundreds > 0) {
        if (!print_word(dict, hundreds) || !print_word(dict, 100)) {
            return 0;
        }
        if (tens > 0) {
            write(1, " ", 1);
        }
    }

    if (tens > 0) {
        if (tens < 20) {
            return print_word(dict, tens);
        } else {
            unsigned long long ones = tens % 10;
            if (!print_word(dict, tens - ones)) {
                return 0;
            }
            if (ones > 0) {
                write(1, "-", 1);
                return print_word(dict, ones);
            }
        }
    }

    return 1;
}

int print_word(t_dict *dict, unsigned long long num) {
    while (dict) {
        if (dict->key == num) {
            write(1, dict->value, strlen(dict->value));
            return 1;
        }
        dict = dict->next;
    }
    return 0;
}