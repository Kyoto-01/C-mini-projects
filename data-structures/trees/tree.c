#include <stdio.h>

#include "tree.h"


int main() {

   /*
              8
            /   \
           1     2
          / \   / \
         3   5 4   7
        /
       6
   */

    binaryTree *nums = create_bin_tree(8);
    insert(nums->root, 1);
    insert(nums->root, 2);
    insert(nums->root, 3);
    insert(nums->root, 4);
    insert(nums->root, 5);
    insert(nums->root, 6);
    insert(nums->root, 7);

    // tests below

    // representation
    printf("\n------------------------------------------\n");
    printf("\tREPRESENTATION OF MY TREE\n");
    printf("------------------------------------------\n\n");

    printf("Pre-order --> ");
    pre_order(nums->root);
    printf("\n");

    printf("In-order --> ");
    in_order(nums->root);
    printf("\n");

    printf("Post-order --> ");
    post_order(nums->root);
    printf("\n\n");

    printf("Representation of my tree:\n");
    formated_print(nums->root, 0);

    // properties
    printf("\n--------------------------------------\n");
    printf("\tPROPERTIES OF MY TREE\n");
    printf("--------------------------------------\n\n");

    printf("Count: %d\n\n", count(nums->root));

    printf("Height 1: %d\n", height(search(nums->root, 1)));
    printf("Height 2: %d\n", height(search(nums->root, 2)));
    printf("Height 3: %d\n", height(search(nums->root, 3)));
    printf("Height 4: %d\n", height(search(nums->root, 4)));
    printf("Height 5: %d\n", height(search(nums->root, 5)));
    printf("Height 6: %d\n", height(search(nums->root, 6)));
    printf("Height 7: %d\n", height(search(nums->root, 7)));
    printf("Height 8: %d\n", height(search(nums->root, 8)));
    printf("\n\n");

    printf("Depth 1: %d\n", depth(nums->root, search(nums->root, 1)));
    printf("Depth 2: %d\n", depth(nums->root, search(nums->root, 2)));
    printf("Depth 3: %d\n", depth(nums->root, search(nums->root, 3)));
    printf("Depth 4: %d\n", depth(nums->root, search(nums->root, 4)));
    printf("Depth 5: %d\n", depth(nums->root, search(nums->root, 5)));
    printf("Depth 6: %d\n", depth(nums->root, search(nums->root, 6)));
    printf("Depth 7: %d\n", depth(nums->root, search(nums->root, 7)));
    printf("Depth 8: %d\n", depth(nums->root, search(nums->root, 8)));

    return 0;
}
