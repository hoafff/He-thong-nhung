/******************************************************************************
 * File: ex1.c
 * Mo ta: Chuong trinh cai dat danh sach lien ket don voi cac thao tac
 * them vao cuoi danh sach, tim kiem, xoa node va giai phong bo nho.
 *
 * Ngay: 15/03/2026
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 * Function: display
 * Description:
 * Ham hien thi toan bo cac phan tu trong danh sach lien ket.
 *
 * Parameters:
 * struct node *head[]: Con tro tro den node dau tien cua danh sach.
 *
 * Return:
 * void.
 ******************************************************************************/
struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    struct node *current = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

/******************************************************************************
 * Function: addback
 * Description:
 * Ham them mot node moi co gia tri data vao cuoi danh sach lien ket.
 *
 * Parameters:
 * struct node *head[]: Con tro tro den node dau tien cua danh sach.
 * int data: Gia tri can them vao danh sach.
 *
 * Return:
 * struct node *: Con tro head cua danh sach sau khi them.
 ******************************************************************************/
struct node *addback(struct node *head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        return new_node;
    }

    struct node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;

    return head;
}

/******************************************************************************
 * Function: find
 * Description:
 * Ham tim node co gia tri data trong danh sach lien ket.
 *
 * Parameters:
 * struct node *head[]: Con tro tro den node dau tien cua danh sach.
 * int data: Gia tri can tim.
 *
 * Return:
 * struct node *: Con tro den node tim thay, neu khong co thi tra ve NULL.
 ******************************************************************************/
struct node *find(struct node *head, int data)
{
    struct node *current = head;

    while (current != NULL)
    {
        if (current->data == data)
        {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

/******************************************************************************
 * Function: delnode
 * Description:
 * Ham xoa mot node khoi danh sach lien ket.
 *
 * Parameters:
 * struct node *head[]: Con tro tro den node dau tien cua danh sach.
 * struct node *pelement[]: Con tro den node can xoa.
 *
 * Return:
 * struct node *: Con tro head moi cua danh sach sau khi xoa.
 ******************************************************************************/
struct node *delnode(struct node *head, struct node *pelement)
{
    if (head == NULL || pelement == NULL)
    {
        return head;
    }

    if (head == pelement)
    {
        struct node *new_head = head->next;
        free(head);
        return new_head;
    }

    struct node *current = head;
    while (current->next != NULL && current->next != pelement)
    {
        current = current->next;
    }

    if (current->next == pelement)
    {
        current->next = pelement->next;
        free(pelement);
    }

    return head;
}

/******************************************************************************
 * Function: freelist
 * Description:
 * Ham giai phong toan bo bo nho da cap phat cho danh sach lien ket.
 *
 * Parameters:
 * struct node *head[]: Con tro tro den node dau tien cua danh sach.
 *
 * Return:
 * void.
 ******************************************************************************/
void freelist(struct node *head)
{
    struct node *current = head;
    while (current != NULL)
    {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }
}

/******************************************************************************
 * Function: main
 * Description:
 * Ham chinh de kiem tra cac thao tac tren danh sach lien ket don:
 * them, tim, xoa va giai phong danh sach.
 *
 * Parameters:
 * void.
 *
 * Return:
 * 0: Neu chuong trinh chay thanh cong.
 ******************************************************************************/
int main(void)
{
    struct node *head = NULL;
    struct node *p = NULL;

    printf("=== EXERCISE 1: LINKED LIST ===\n");

    printf("\n1. Add elements 10, 20, 30, 40 to list:\n");
    head = addback(head, 10);
    head = addback(head, 20);
    head = addback(head, 30);
    head = addback(head, 40);
    display(head);

    printf("\n2. Find element 30:\n");
    p = find(head, 30);
    if (p != NULL)
    {
        printf("Found node with data = %d\n", p->data);
    }
    else
    {
        printf("Node not found.\n");
    }

    printf("\n3. Find element 99:\n");
    p = find(head, 99);
    if (p != NULL)
    {
        printf("Found node with data = %d\n", p->data);
    }
    else
    {
        printf("Node not found.\n");
    }

    printf("\n4. Delete node containing 30:\n");
    p = find(head, 30);
    head = delnode(head, p);
    display(head);

    printf("\n5. Delete head node:\n");
    head = delnode(head, head);
    display(head);

    printf("\n6. Free entire list:\n");
    freelist(head);
    head = NULL;
    display(head);

    return 0;
}