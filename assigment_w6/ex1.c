/* * CHU THICH TONG THE:
 * Chuong trinh nay kiem tra xem mot chuoi (t) co nam o cuoi cua mot chuoi khac (s) hay khong.
 * Ham strend se tra ve 1 neu chuoi t la phan ket thuc cua chuoi s, nguoc lai tra ve 0.
 * Thuat toan su dung tinh toan do dai chuoi va so sanh vung nho cuoi cung cua s voi t.
 */

#include <stdio.h>
#include <string.h>

// Ham kiem tra chuoi t co nam o cuoi chuoi s khong
int strend(char *s, char *t) {
    int ls = strlen(s); // Lay do dai cua chuoi nguon s
    int lt = strlen(t); // Lay do dai cua chuoi can kiem tra t

    // Neu chuoi t dai hon chuoi s thi chac chan t khong the o cuoi s
    if (lt > ls) return 0; 

    /* * s + ls - lt: Di chuyen con tro den vi tri bat dau cua phan duoi trong chuoi s
     * strcmp: So sanh phan duoi do voi chuoi t
     * Neu bang nhau (strcmp tra ve 0) thi ham strend tra ve 1 (true)
     */
    return strcmp(s + ls - lt, t) == 0;
}

int main() {
    // In ra 1 vi "world" nam o cuoi chuoi "hello world"
    printf("%d\n", strend("hello world", "world")); 

    // In ra 0 vi "hell" khong nam o cuoi chuoi "hello world"
    printf("%d\n", strend("hello world", "hell"));  

    return 0; // Ket thuc chuong trinh
}