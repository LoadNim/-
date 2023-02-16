#include <stdio.h>
#include "binary_tree.h"

void traversal(binary_tree* bt){
    if(bt == NULL) return;
    traversal(bt->left);
    printf("%d\n", get_data(bt));
    traversal(bt->right);
}

int main(){
    binary_tree* bin[5];
    for(int i = 0; i < 5; ++i) bin[i] = make_node();
    for(int i = 0; i < 5; ++i) set_data(bin[i], i);
    link_left(bin[0], bin[1]);
    link_right(bin[0], bin[2]);
    link_left(bin[1], bin[3]);
    link_left(bin[2], bin[4]);
    traversal(bin[0]);
}