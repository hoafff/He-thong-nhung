/*
 * TONG QUAN FILE CHINH:
 * Su dung cac ham tu thu vien hashtable de thuc hien cac yeu cau kiem thu.
 * Bao gom: Them 8 lien he, tim kiem 3 ten va xoa 2 lien he[cite: 20, 22, 23].
 */

#include <stdio.h>
#include "hashtable.h"

int main() {
    // 1. Khoi tao bang [cite: 37]
    initTable();

    // 2. Them 8 lien he [cite: 20]
    insert("An", "0123"); insert("Binh", "0456");
    insert("Chinh", "0789"); insert("Dung", "0111");
    insert("Giang", "0222"); insert("Huong", "0333");
    insert("Khoa", "0444"); insert("Lan", "0555");
    
    display();

    // 3. Tim kiem 3 ten (co 1 ten khong ton tai) [cite: 22]
    char* testSearch[] = {"An", "Khoa", "NguoiLa"};
    printf("\n--- KET QUA TIM KIEM ---\n");
    for(int i=0; i<3; i++) {
        char* p = search(testSearch[i]);
        if(p) printf("Tim thay %s: %s\n", testSearch[i], p);
        else printf("Khong tim thay: %s\n", testSearch[i]);
    }

    // 4. Xoa 2 lien he va in lai [cite: 23]
    printf("\n--- TIEN HANH XOA 'An' VA 'Chinh' ---\n");
    deleteNode("An");
    deleteNode("Chinh");
    display();

    // 5. Don dep bo nho [cite: 38]
    freeTable();
    return 0;
}