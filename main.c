// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;



struct Node* createNode(int data){
    struct Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
}


void insertNode(struct Node** tree, int data){
    if (*tree == NULL){
        struct Node* new_node = createNode(data);
        *tree = new_node;
    }
    else{
        int root_value = (*tree)->data;
        if (data < root_value){
            insertNode(&(*tree)->left, data);
        }
        else{
            insertNode(&(*tree)->right, data);
        }
    }
}


void printTree(struct Node* tree, int counter){
    if (tree == NULL){
        return;
    }
    else{
        printTree(tree->right, counter+=1);
        for (int i = 0; i < counter; ++i){
            printf("\t");
        }
        printf("(%d)\n", tree->data);
        
        printTree(tree->left, counter+=1);
        
    }
}


bool search(struct Node* tree, int data){
    if (tree == NULL){
        return false;
    }
    else if (tree->data == data){
        return true;
    }
    else if (data < tree->data){
        search(tree->left, data);
    }
    else{
        search(tree->right, data);
    }
}


int main() {
    struct Node* root = NULL;
    int counter = 0;
    insertNode(&root, 8);
    insertNode(&root, 3);
    insertNode(&root, 1);
    insertNode(&root, 6);
    insertNode(&root, 5);
    insertNode(&root, 7);
    
    int value = 20;
    printTree(root, counter);
    
    if (search(root, value)){
        printf("value [%d] has been found!", value);
    }
    else{
        printf("value [%d] has not been found!", value);

    }

    return 0;
}
