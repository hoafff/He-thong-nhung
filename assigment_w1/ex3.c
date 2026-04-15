#include <stdio.h>

/* Chuong trinh dem khoang trang, tab va dong moi */
int main() {
    int c, nl, nt, ns;

    nl = 0; // Bien dem dong moi
    nt = 0; // Bien dem tab
    ns = 0; // Bien dem khoang trang (blank)

    printf("Nhap van ban (Bam Ctrl+D de ket thuc):\n");
    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        else if (c == '\t')
            ++nt;
        else if (c == ' ')
            ++ns;
    }

    // In ket qua
    printf("Khoang trang: %d\nTab: %d\nDong moi: %d\n", ns, nt, nl);
    return 0;
}