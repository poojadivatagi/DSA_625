#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *left, *right;
};

typedef struct node* NODE;

// Create node
NODE createNode(int data) {
    NODE newnode = (NODE)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Insert (Simple BST)
NODE insert(NODE root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Inorder traversal
void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Search node
void search(NODE root, int key) {
    if (root == NULL) {
        printf("Not Found\n");
        return;
    }

    if (root->data == key) {
        printf("Found\n");
        return;
    }

    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

// Main menu
int main() {
    NODE root = NULL;
    int choice, data;

    while (1) {
        printf("\n1.Insert\n2.Display(Inorder)\n3.Search\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &data);
                search(root, data);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
