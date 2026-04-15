/*
 * TONG QUAN CHUONG TRINH:
 * Mo phong hang doi kham benh bang Max-Heap (Hang doi uu tien).
 * Moi benh nhan co ten va muc do uu tien (priority). 
 * Priority cang lon, benh nhan cang duoc uu tien kham truoc.
 * * DO PHUC TAP THOI GIAN:
 * - Push (Them benh nhan): O(log n) do thao tac heapify-up.
 * - Pop (Lay benh nhan): O(log n) do thao tac heapify-down.
 * - Peek (Xem benh nhan dau): O(1).
 */

#include <stdio.h>
#include <string.h>

#define MAX 100 // Kich thuoc toi da cua hang doi

// Cau truc du lieu benh nhan
typedef struct {
    char name[50];
    int priority;
} Patient;

// Mang bieu dien Max-Heap
Patient heap[MAX];
int size = 0;

// Ham hoan doi hai benh nhan
void swap(Patient *a, Patient *b) {
    Patient temp = *a;
    *a = *b;
    *b = temp;
}

// Ham dua phan tu len dung vi tri (Heapify-up)
void heapifyUp(int index) {
    // So sanh voi nut cha, neu lon hon thi doi cho
    while (index > 0 && heap[(index - 1) / 2].priority < heap[index].priority) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

// Ham dua phan tu xuong dung vi tri (Heapify-down)
void heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Tim nut lon nhat giua cha va hai con
    if (left < size && heap[left].priority > heap[largest].priority)
        largest = left;
    if (right < size && heap[right].priority > heap[largest].priority)
        largest = right;

    // Neu nut cha khong phai lon nhat, doi cho va tiep tuc de quy
    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

// Chuc nang 1: Them benh nhan vao hang doi (push)
void push(char *name, int priority) {
    if (size >= MAX) return;
    
    strcpy(heap[size].name, name);
    heap[size].priority = priority;
    heapifyUp(size); // Duy tri dac tinh Max-Heap
    size++;
}

// Chuc nang 2: Lay benh nhan uu tien nhat ra (pop)
Patient pop() {
    Patient top = heap[0];
    heap[0] = heap[size - 1]; // Dua phan tu cuoi len goc
    size--;
    heapifyDown(0); // Sap xep lai heap
    return top;
}

// Chuc nang 3: Xem benh nhan uu tien nhat (peek)
Patient peek() {
    return heap[0];
}

int main() {
    printf("--- HE THONG QUAN LY HANG DOI BENH VIEN ---\n\n");

    // 1. Nhap vao 5 benh nhan voi priority khac nhau
    struct { char n[50]; int p; } input[] = {
        {"Nguyen Van A", 3},
        {"Tran Thi B", 5},
        {"Le Van C", 1},
        {"Pham Van D", 4},
        {"Hoang Thi E", 2}
    };

    for (int i = 0; i < 5; i++) {
        push(input[i].n, input[i].p);
        // 2. In ra benh nhan dung dau sau moi lan them
        Patient top = peek();
        printf("Da them: %s (Priority: %d) -> Uu tien nhat hien tai: %s\n", 
               input[i].n, input[i].p, top.name);
    }

    // 3. Lay lan luot tung nguoi ra kham
    printf("\n--- THU TU GOI KHAM ---\n");
    int count = 1;
    while (size > 0) {
        Patient p = pop();
        printf("Luot %d: Moi benh nhan %s (Muc uu tien: %d) vao phong kham.\n", 
               count++, p.name, p.priority);
    }

    return 0;
}