// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    if (num == 1) return 1;
    uint64_t next = (num % 2 == 0) ? num / 2 : 3 * num + 1;
    uint64_t max_in_tail = collatzMaxValue(next);
    return (num > max_in_tail) ? num : max_in_tail;
}

unsigned int collatzLen(uint64_t num) {
    if (num == 1) return 1;
    uint64_t next = (num % 2 == 0) ? num / 2 : 3 * num + 1;
    return 1 + collatzLen(next);
}

unsigned int seqCollatz(unsigned int* maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int best_len = 0;
    uint64_t best_num = lbound;
    for (uint64_t n = lbound; n <= rbound; ++n) {
        unsigned int len = collatzLen(n);
        if (len > best_len) {
            best_len = len;
            best_num = n;
        }
    }
    if (maxlen) *maxlen = best_len;
    return static_cast<unsigned int>(best_num);
}
