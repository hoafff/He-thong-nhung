/* * CHU THICH TONG THE:
 * Chuong trinh nay thuc hien so sanh hai chuoi dua tren mot "truong" (field) cu the.
 * Moi truong duoc phan cach boi khoang trang.
 * Ham get_field: Tim vi tri bat dau cua truong thu n trong chuoi.
 * Ham field_cmp: Lay noi dung tu truong thu n tro di cua hai chuoi de so sanh voi nhau.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Ham bo qua n-1 truong de tim den vi tri bat dau cua truong thu n
char *get_field(char *s, int field) {
    while (field > 1 && *s) {         // Lap den khi toi truong can tim hoac het chuoi
        while (*s && !isspace(*s)) s++; // Nhay qua cac ky tu khong phai khoang trang
        while (*s && isspace(*s)) s++;  // Nhay qua cac ky tu khoang trang de den truong ke tiep
        field--;                        // Giam so luong truong can nhay qua
    }
    return s; // Tra ve con tro tai vi tri bat dau truong thu n
}

// Ham so sanh hai chuoi tai mot truong cu the
int field_cmp(char *s1, char *s2, int field) {
    // Lay vi tri truong thu n cua ca hai chuoi roi dung strcmp de so sanh
    return strcmp(get_field(s1, field), get_field(s2, field));
}

int main() {
    char row1[] = "101 Apple 0.5";  // Khai bao chuoi du lieu thu nhat
    char row2[] = "102 Banana 0.2"; // Khai bao chuoi du lieu thu hai

    // So sanh tu truong thu 2 (tuc la so sanh "Apple 0.5" voi "Banana 0.2")
    // Ket qua tra ve gia tri am vi 'A' dung truoc 'B' trong bang ma ASCII
    printf("Result: %d\n", field_cmp(row1, row2, 2)); 

    return 0; // Ket thuc chuong trinh
}