#include <stdio.h>

/* Viet lai vong lap K&R ma khong dung && hoac || */
int main() {
    int i = 0, lim = 100;
    char c, s[100];

    // Vong lap goc: for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    
    while (i < lim - 1) {
        c = getchar();
        if (c == '\n') {
            break; // Thoat neu gap dong moi
        }
        if (c == EOF) {
            break; // Thoat neu het file
        }
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return 0;
}