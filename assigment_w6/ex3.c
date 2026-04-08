/* * CHU THICH TONG THE:
 * Chuong trinh nay la mot may tinh bo tui don gian su dung ky phap Ba Lan nguoc (RPN).
 * Du lieu dau vao duoc lay tu tham so dong lenh (command line arguments).
 * Chuong trinh su dung mot cau truc ngan xep (stack) de luu tru cac con so.
 * Khi gap con so, no se dua vao stack. Khi gap toan tu (+, -, *, /), no se lay cac 
 * con so ra de tinh toan va luu ket qua tro lai stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    double stack[100];      // Mang dong vai tro ngan xep de luu tru cac so thuc
    int sp = 0;             // Bien tro chi so (stack pointer) vao vi tri tiep theo trong stack

    while (--argc > 0) {    // Duyet qua tat ca cac tham so truyen vao tu dong lenh
        char *s = *++argv;  // Lay tham so tiep theo trong danh sach tham so

        // Kiem tra neu tham so la mot con so (duong hoac am)
        if (isdigit(s[0]) || (s[0] == '-' && isdigit(s[1]))) {
            stack[sp++] = atof(s); // Chuyen chuoi thanh so thuc va dua vao stack
        } else {
            // Neu la toan tu, lay gia tri cuoi cung ra de thuc hien phep tinh
            double op2 = stack[--sp]; 

            switch (s[0]) {
                case '+': 
                    stack[sp-1] += op2; // Cong don vao phan tu phia truoc trong stack
                    break;
                case '-': 
                    stack[sp-1] -= op2; // Tru phan tu phia truoc cho op2
                    break;
                case '*': 
                    stack[sp-1] *= op2; // Nhan phan tu phia truoc voi op2
                    break;
                case '/': 
                    stack[sp-1] /= op2; // Chia phan tu phia truoc cho op2
                    break;
                default: 
                    // Thong bao loi neu gap ky tu khong phai toan tu hop le
                    printf("Error: unknown operator %s\n", s); 
                    return 1;
            }
        }
    }
    
    // In ket qua cuoi cung (nam tai vi tri dau tien cua stack) voi 2 chu so thap phan
    printf("%.2f\n", stack[0]); 
    
    return 0; // Ket thuc chuong trinh thanh cong
}