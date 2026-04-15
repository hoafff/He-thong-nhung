#include <stdio.h>

/* Thay the nhieu khoang trang lien tiep bang 1 khoang trang duy nhat */
int main() {
    int c, last_c;

    last_c = EOF; // Bien luu ky tu truoc do

    while ((c = getchar()) != EOF) {
        // Neu ky tu hien tai khong phai khoang trang 
        // HOAC ky tu truoc do khong phai khoang trang thi moi in
        if (c != ' ' || last_c != ' ') {
            putchar(c);
        }
        last_c = c;
    }
    return 0;
}