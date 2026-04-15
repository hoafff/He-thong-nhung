#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Xac dinh gioi han cua cac kieu du lieu bang header va tinh toan */
int main() {
    // Dung thu vien limits.h
    printf("Dung thu vien limits.h:\n");
    printf("Signed char: %d den %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char: 0 den %u\n", UCHAR_MAX);
    printf("Signed int: %d den %d\n", INT_MIN, INT_MAX);
    printf("Signed long: %ld den %ld\n\n", LONG_MIN, LONG_MAX);

    // Dung tinh toan (vi du cho unsigned char)
    // (unsigned char)~0 se cho tat ca bit la 1
    printf("Tinh toan truc tiep:\n");
    printf("Max Unsigned Char: %u\n", (unsigned char)~0);
    printf("Max Unsigned Int: %u\n", (unsigned int)~0);

    return 0;
}