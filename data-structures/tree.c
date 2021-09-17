#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}node;

typedef struct BinaryTree{
  node *root;  
}binaryTree;

node *create_node(int data){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    return temp;
}

binaryTree *create_bin_tree(node *root){
    binaryTree *temp = (binaryTree*)malloc(sizeof(binaryTree));
    temp->root = root;
    return temp;
}

void pre_order(node *root){
    if (root){
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(node *root){
    if (root){
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}

void post_order(node *root){
    if (root){
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->data);
    }
}

void formated_print(node *root, int indent){
    if (root){
        for(int i = 0; i < indent; i++){
            printf(" ");
        }
        printf("%d\n", root->data);
        formated_print(root->left, indent + 1);
        formated_print(root->right, indent + 1);
    }
}

int main() {
   
   /*
          5
         / \
        3  6
       / \
      2  4
   */
   
    node *num2 = create_node(2);
    node *num3 = create_node(3);
    node *num4 = create_node(4);
    node *num5 = create_node(5);
    node *num6 = create_node(6);
    
    num5->left = num3;
    num5->right = num6;
    num3->left = num2;
    num3->right = num4;
    
    binaryTree *nums = create_bin_tree(num5);
    
    // tests below
    
    pre_order(nums->root);
    printf("\n");
    in_order(nums->root);
    printf("\n");
    post_order(nums->root);
    printf("\n");
    
    formated_print(nums->root, 0);
    
