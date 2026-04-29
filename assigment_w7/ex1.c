/*
 * TONG QUAN CHUONG TRINH:
 * Chuong trinh quan ly danh ba dien thoai su dung Bang Bam (Hash Table).
 * Co che xu ly xung dot: Chaining (Su dung danh sach lien ket don).
 * Cac chuc nang chinh: Them, Tim kiem, Xoa lien he.
 * Do phuc tap thoi gian trung binh: O(1) cho cac thao tac.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10 // Kich thuoc bang bam

// Dinh nghia cau truc mot nut trong danh sach lien ket
typedef struct Node {
    char name[50];
    char phone[20];
    struct Node* next;
} Node;

// Mang cac con tro buckets
Node* buckets[TABLE_SIZE];

// Ham bam: Su dung cong thuc da thuc voi so 31
unsigned int hash(char *str) {
    unsigned int hash_val = 0;
    while (*str) {
        hash_val = hash_val * 31 + *str++;
    }
    return hash_val % TABLE_SIZE; // Anh xa vao kich thuoc bang
}

// Ham tao mot nut moi
Node* createNode(char *name, char *phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = NULL;
    return newNode;
}

// Chuc nang 1: Them lien he moi (insert)
void insert(char *name, char *phone) {
    unsigned int index = hash(name);
    Node* newNode = createNode(name, phone);
    
    // Them vao dau danh sach lien ket tai bucket tuong ung
    newNode->next = buckets[index];
    buckets[index] = newNode;
    printf("Da them: %s - %s (Bucket %d)\n", name, phone, index);
}

// Chuc nang 2: Tim kiem theo ten (search)
char* search(char *name) {
    unsigned int index = hash(name);
    Node* temp = buckets[index];
    
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp->phone; // Tim thay
        }
        temp = temp->next;
    }
    return NULL; // Khong tim thay
}

// Chuc nang 3: Xoa mot lien he (delete)
void deleteNode(char *name) {
    unsigned int index = hash(name);
    Node *temp = buckets[index], *prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Khong tim thay lien he '%s' de xoa.\n", name);
        return;
    }

    if (prev == NULL) {
        buckets[index] = temp->next; // Xoa nut dau
    } else {
        prev->next = temp->next; // Ngat ket noi nut can xoa
    }
    
    free(temp);
    printf("Da xoa lien he: %s\n", name);
}

// Ham in toan bo bang bam de kiem tra
void display() {
    printf("\n--- TRANG THAI BANG BAM ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* temp = buckets[i];
        while (temp) {
            printf("[%s: %s] -> ", temp->name, temp->phone);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    printf("---------------------------\n");
}

int main() {
    // Khoi tao bang bam rong
    for (int i = 0; i < TABLE_SIZE; i++) buckets[i] = NULL;

    // 1. Nhap thu 8 lien he
    printf("--- BAT DAU THEM LIEN HE ---\n");
    insert("An", "0912345678");
    insert("Binh", "0988888888");
    insert("Chinh", "0977777777");
    insert("Dung", "0966666666");
    insert("Giang", "0944444444");
    insert("Huong", "0933333333");
    insert("Khoa", "0922222222");
    insert("Lan", "0911111111");

    display();

    // 2. Thuc hien tim kiem 3 ten
    printf("\n--- KIEM TRA TIM KIEM ---\n");
    char* namesToSearch[3] = {"An", "Khoa", "NguoiLa"};
    for(int i=0; i<3; i++) {
        char* result = search(namesToSearch[i]);
        if (result) 
            printf("Tim thay %s: %s\n", namesToSearch[i], result);
        else 
            printf("Khong tim thay: %s\n", namesToSearch[i]);
    }

    // 3. Thuc hien xoa 2 lien he
    printf("\n--- KIEM TRA XOA ---\n");
    deleteNode("An");
    deleteNode("Chinh");

    // In lai bang sau khi xoa
    display();

    return 0;
}

/*
int main() {
    int choice;
    char name[50];
    char phone[20];

    // Khoi tao bang bam rong
    for (int i = 0; i < TABLE_SIZE; i++) {
        buckets[i] = NULL;
    }

    do {
        printf("\n===== MENU QUAN LY DANH BA =====\n");
        printf("1. Them lien he\n");
        printf("2. Tim kiem lien he\n");
        printf("3. Xoa lien he\n");
        printf("4. Hien thi danh ba\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar(); // xoa ky tu '\n' con lai trong bo dem

        switch (choice) {
            case 1:
                printf("Nhap ten: ");
                fgets(name, sizeof(name), stdin);
                removeNewline(name);

                printf("Nhap so dien thoai: ");
                fgets(phone, sizeof(phone), stdin);
                removeNewline(phone);

                insert(name, phone);
                break;

            case 2:
                printf("Nhap ten can tim: ");
                fgets(name, sizeof(name), stdin);
                removeNewline(name);

                char* result = search(name);
                if (result != NULL) {
                    printf("Tim thay %s: %s\n", name, result);
                } else {
                    printf("Khong tim thay lien he '%s'\n", name);
                }
                break;

            case 3:
                printf("Nhap ten can xoa: ");
                fgets(name, sizeof(name), stdin);
                removeNewline(name);

                deleteNode(name);
                break;

            case 4:
                display();
                break;

            case 0:
                printf("Dang thoat chuong trinh...\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long nhap lai!\n");
        }

    } while (choice != 0);

    freeTable();
    return 0;
}*/