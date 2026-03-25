#include <stdio.h>
#include <stdlib.h>

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