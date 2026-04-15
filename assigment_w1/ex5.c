#include <stdio.h>

/* Lam cho cac ky tu dac biet tro nen hien thi ro rang */
int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t"); // Thay tab bang \t
        } else if (c == '\b') {
            printf("\\b"); // Thay backspace bang \b
        } else if (c == '\\') {
            printf("\\\\"); // Thay dau gach cheo nguoc bang \\
        } else {
            putchar(c);
        }
    }
    return 0;
}