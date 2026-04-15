/*
 * TONG QUAN FILE HEADER:
 * Khai bao cau truc du lieu Node va cac ham giao tiep cua thu vien Bang Bam.
 * Giup cac chuong trinh khac co the su dung lai ma nguon ma khong can biet chi tiet cai dat.
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 10 // Kich thuoc mang buckets [cite: 8]

// Cau truc Node cho danh sach lien ket [cite: 10, 39]
typedef struct Node {
    char name[50];
    char phone[20];
    struct Node* next;
} Node;

// Cac nguyen mau ham giao tiep [cite: 33, 36, 38]
void initTable();                      // Khoi tao bang bam [cite: 37]
unsigned int hash(char *str);          // Ham bam chuoi ky tu [cite: 12]
void insert(char *name, char *phone);  // Them lien he [cite: 16]
char* search(char *name);              // Tim kiem theo ten [cite: 17]
void deleteNode(char *name);           // Xoa lien he [cite: 18]
void freeTable();                      // Giai phong bo nho [cite: 38]
void display();                        // In toan bo danh ba [cite: 26]

#endif