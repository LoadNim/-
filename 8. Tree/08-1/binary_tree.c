#include "binary_tree.h"
#include <stdlib.h>

binary_tree* make_node(){
    binary_tree* node = (binary_tree*)malloc(sizeof(binary_tree));
    node->data = 0;
    node->right = NULL;
    node->left = NULL;
    return node;
}

void link_left(binary_tree* bt1, binary_tree* bt2){
    if(bt1->left != NULL) free(bt1->left);
    bt1->left = bt2;
}

void link_right(binary_tree* bt1, binary_tree* bt2){
    if(bt1->right != NULL) free(bt1->right);
    bt1->right = bt2;
}

int get_data(binary_tree* bt){return bt->data;}
void set_data(binary_tree* bt, int data){bt->data = data;}
binary_tree* get_left(binary_tree* bt){return bt->left;}
binary_tree* get_right(binary_tree* bt){return bt->right;}