#include <stdio.h>

/* In bieu do ngang ve tan suat cac ky tu */
int main() {
    int c, i, j;
    int char_freq[128]; // Mang luu tan suat cho 128 ky tu ASCII

    // Khoi tao mang bang 0
    for (i = 0; i < 128; ++i) char_freq[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c < 128) {
            ++char_freq[c];
        }
    }

    printf("\nBieu do tan suat:\n");
    for (i = 32; i < 127; ++i) { // Chi in cac ky tu doc duoc
        if (char_freq[i] > 0) {
            printf("'%c': ", i);
            for (j = 0; j < char_freq[i]; ++j) {
                putchar('*'); // Ve hinh sao dai dien cho tan suat
            }
            putchar('\n');
        }
    }
    return 0;
}