#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

typedef struct binary_tree{
    int data;
    struct binary_tree* right;
    struct binary_tree* left;
}binary_tree;

binary_tree* make_node();
void link_left(binary_tree* bt1, binary_tree* bt2);
void link_right(binary_tree* bt1, binary_tree* bt2);
int get_data(binary_tree* bt);
void set_data(binary_tree* bt, int data);
binary_tree* get_left(binary_tree* bt);
binary_tree* get_right(binary_tree* bt);
#endif