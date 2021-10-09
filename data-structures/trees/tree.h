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
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

binaryTree *create_bin_tree(int root_value){
    binaryTree *temp = (binaryTree*)malloc(sizeof(binaryTree));
    temp->root = create_node(root_value);
    return temp;
}

int count(node *root){
    if (root){
        return 1 + count(root->left) + count(root->right);
    }
    return 0;
}

int height(node *actual){
    if (actual){
        int left = 1 + height(actual->left);
        int right = 1 + height(actual->right);

        return left > right ? left : right;
    }
    return 0;
}

int depth(node *root, node *actual){
    if (root){
        if (root == actual){
            return 1; // it found *-*
        }
        int left_find = depth(root->left, actual);
        if (left_find){
            return left_find + 1;
        }
        int right_find = depth(root->right, actual);
        if (right_find){
            return right_find + 1;
        }
        return 0;
    }
}

void insert(node *root, int data){
    node *temp = create_node(data);

    if (!root->left){
        root->left = temp;
    }
    else if (!root->right){
        root->right = temp;
    }
    else{
        int left_height = height(root->left);
        int right_height = height(root->right);

        if (left_height > right_height){
            insert(root->right, data);
        }
        else{
            // main insert at left side
            insert(root->left, data);
        }
    }
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

node *search(node *root, int data){
    if (root == NULL){
        return NULL;
    }
    if (root->data == data){
        return root;
    }
    node *find = search(root->left, data);
    if (!find){
        find = search(root->right, data);
    }
    return find;
}
