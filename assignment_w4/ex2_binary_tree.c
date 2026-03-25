/******************************************************************************
 * File: ex2.c
 * Mo ta: Chuong trinh cai dat cay nhi phan tim kiem (Binary Search Tree)
 * voi cac thao tac tao node, chen node, duyet tien tu, duyet trung tu
 * va xoa toan bo cay.
 *
 * Ngay: 15/03/2026
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 * Cau truc: tnode
 * Mo ta:
 * Moi node trong cay gom:
 * - data: gia tri cua node
 * - left: con tro tro den cay con ben trai
 * - right: con tro tro den cay con ben phai
 ******************************************************************************/
struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
};

/******************************************************************************
 * Function: talloc
 * Description:
 * Ham cap phat bo nho cho mot node moi trong cay nhi phan va gan gia tri
 * data cho node do.
 *
 * Parameters:
 * int data: Gia tri can luu trong node moi.
 *
 * Return:
 * struct tnode *: Con tro den node moi duoc tao.
 * Neu cap phat bo nho that bai thi tra ve NULL.
 ******************************************************************************/
struct tnode *talloc(int data)
{
    struct tnode *new_node = (struct tnode *)malloc(sizeof(struct tnode));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

/******************************************************************************
 * Function: addnode
 * Description:
 * Ham chen mot gia tri moi vao cay nhi phan tim kiem.
 * Neu data nho hon gia tri cua node goc thi chen vao cay con trai,
 * nguoc lai chen vao cay con phai.
 *
 * Parameters:
 * struct tnode *root: Con tro tro den node goc cua cay.
 * int data: Gia tri can chen vao cay.
 *
 * Return:
 * struct tnode *: Con tro den goc cua cay sau khi chen.
 ******************************************************************************/
struct tnode *addnode(struct tnode *root, int data)
{
    if (root == NULL)
    {
        return talloc(data);
    }

    if (data < root->data)
    {
        root->left = addnode(root->left, data);
    }
    else
    {
        root->right = addnode(root->right, data);
    }

    return root;
}

/******************************************************************************
 * Function: preorder
 * Description:
 * Ham duyet cay theo thu tu tien tu:
 * root -> left -> right
 *
 * Parameters:
 * struct tnode *root: Con tro tro den node goc cua cay.
 *
 * Return:
 * void.
 ******************************************************************************/
void preorder(struct tnode *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

/******************************************************************************
 * Function: inorder
 * Description:
 * Ham duyet cay theo thu tu trung tu:
 * left -> root -> right
 * Doi voi cay nhi phan tim kiem, ket qua in ra se theo thu tu tang dan.
 *
 * Parameters:
 * struct tnode *root: Con tro tro den node goc cua cay.
 *
 * Return:
 * void.
 ******************************************************************************/
void inorder(struct tnode *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/******************************************************************************
 * Function: deltree
 * Description:
 * Ham xoa toan bo cac node trong cay theo kieu hau tu,
 * dong thoi dem so luong node da duoc giai phong.
 *
 * Parameters:
 * struct tnode *root: Con tro tro den node goc cua cay.
 *
 * Return:
 * int: So luong node da xoa.
 ******************************************************************************/
int deltree(struct tnode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left_count = deltree(root->left);
    int right_count = deltree(root->right);

    free(root);

    return left_count + right_count + 1;
}

/******************************************************************************
 * Function: main
 * Description:
 * Ham chinh dung de kiem tra cac thao tac tren cay nhi phan tim kiem:
 * - chen cac phan tu vao cay
 * - duyet tien tu
 * - duyet trung tu
 * - xoa toan bo cay
 *
 * Parameters:
 * void.
 *
 * Return:
 * 0: Neu chuong trinh chay thanh cong.
 ******************************************************************************/
int main(void)
{
    struct tnode *root = NULL;
    int values[] = {3, 1, 0, 2, 8, 6, 5, 9};
    int n = sizeof(values) / sizeof(values[0]);
    int i;
    int deleted_nodes;

    printf("=== EXERCISE 2: BINARY TREE ===\n");

    printf("\n1. Insert elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", values[i]);
        root = addnode(root, values[i]);
    }
    printf("\n");

    printf("\n2. Preorder traversal:\n");
    preorder(root);
    printf("\n");

    printf("\n3. Inorder traversal (sorted):\n");
    inorder(root);
    printf("\n");

    printf("\n4. Delete all nodes in tree:\n");
    deleted_nodes = deltree(root);
    root = NULL;
    printf("Deleted %d nodes.\n", deleted_nodes);

    return 0;
}