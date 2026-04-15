#include <stdio.h>
#include <ctype.h>

/* Ham htoi: chuyen chuoi hex thanh so nguyen */
long htoi(char s[]) {
    long result = 0;
    int i = 0;

    // Bo qua 0x hoac 0X neu co
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
    }

    for (; s[i] != '\0'; ++i) {
        int val;
        if (isdigit(s[i])) {
            val = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            val = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            val = s[i] - 'A' + 10;
        } else {
            break; // Ky tu khong hop le thi dung
        }
        result = result * 16 + val;
    }
    return result;
}

int main() {
    char hex[] = "0x1A3F";
    printf("Gia tri cua %s la: %ld\n", hex, htoi(hex));
    return 0;
}