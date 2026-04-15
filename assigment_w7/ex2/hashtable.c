/*
 * TONG QUAN FILE CAI DAT:
 * Chua logic chi tiet cua ham bam va cac thao tac tren Bang Bam (Chaining).
 * Quan ly bo nho dong cho cac Node va xu ly xung dot bang danh sach lien ket.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

// Mang cac con tro buckets duoc khai bao static de khu tru pham vi
static Node* buckets[TABLE_SIZE];

// Ham khoi tao: Dat tat ca buckets ve NULL [cite: 37]
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        buckets[i] = NULL;
    }
}

// Ham bam: Cong thuc da thuc nhan voi 31 [cite: 13, 14]
unsigned int hash(char *str) {
    unsigned int hash_val = 0;
    while (*str) {
        hash_val = hash_val * 31 + *str++;
    }
    return hash_val % TABLE_SIZE;
}

// Ham insert: Them vao dau danh sach tai bucket [cite: 9, 16]
void insert(char *name, char *phone) {
    unsigned int index = hash(name);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return; // Kiem tra cap phat
    
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = buckets[index];
    buckets[index] = newNode;
}

// Ham search: Duyet danh sach lien ket de tim ten [cite: 17]
char* search(char *name) {
    unsigned int index = hash(name);
    Node* temp = buckets[index];
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) return temp->phone;
        temp = temp->next;
    }
    return NULL;
}

// Ham delete: Tim va ngat ket noi Node can xoa [cite: 18]
void deleteNode(char *name) {
    unsigned int index = hash(name);
    Node *temp = buckets[index], *prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL) buckets[index] = temp->next;
        else prev->next = temp->next;
        free(temp); // Giai phong vung nho
    }
}

// Ham freeTable: Xoa toan bo cac Node de tranh ro ri bo nho [cite: 38]
void freeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = buckets[i];
        while (temp != NULL) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        buckets[i] = NULL;
    }
}

// Ham display: In cau truc hien tai cua bang bam [cite: 26]
void display() {
    printf("\n--- DANH BA DIEN THOAI ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* temp = buckets[i];
        while (temp) {
            printf("[%s: %s] -> ", temp->name, temp->phone);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}