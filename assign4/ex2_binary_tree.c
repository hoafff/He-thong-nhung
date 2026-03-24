#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
};

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