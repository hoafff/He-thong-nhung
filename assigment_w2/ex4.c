/******************************************************************************
 * File: itob.c
 * * Mo ta: Chuong trinh chuyen doi so nguyen sang chuoi ky tu
 * dua tren co so (base) bat ky.
 * 
 * Ngay: 10/03/2026
 *****************************************************************************/

#include <stdio.h>
#include <string.h>

/******************************************************************************
 * Function: itob
 * Description:
 * Chuyen doi so nguyen n thanh bieu dien co so b (2, 8, 10, 16...).
 * Parameters:
 * int n: So nguyen can chuyen doi.
 * char s[]: Chuoi luu ket qua sau khi chuyen.
 * int b: Co so can chuyen sang (vi du: 16 cho Hex).
 * Return:
 * None
 *****************************************************************************/
void itob(int n, char s[], int b) {
    int i, sign;
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if ((sign = n) < 0) n = -n;

    i = 0;
    do {
        s[i++] = digits[n % b];
    } while ((n /= b) > 0);

    if (sign < 0) s[i++] = '-';
    s[i] = '\0';

    // Dao nguoc chuoi
    int left, right;
    char temp;
    for (left = 0, right = i - 1; left < right; left++, right--) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
    }
}

int main() {
    char s[64];
    itob(255, s, 16);
    printf("So 255 co so 16 la: %s\n", s);
    return 0;
}

// dấu trừ ở tầm 45 nên nhỏ hơn các số ở khoảng 48 đến 57 (0-9) và 65 đến 90 (A-Z) trong bảng mã ASCII, nên nó sẽ được đặt ở vị trí đầu tiên của chuỗi kết quả nếu số nguyên ban đầu là âm.