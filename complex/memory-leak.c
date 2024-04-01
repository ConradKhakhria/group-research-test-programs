#include <stdio.h>
#include <stdlib.h>


struct BTree {
    int val;
    int node;
    struct BTree* left;
    struct BTree* right;
};


struct BTree* init_btree_node(int v, struct BTree* l, struct BTree* r) {
    struct BTree* t = malloc(sizeof(struct BTree));

    if (t) {
        t->left = l;
        t->right = r;
        t->node = 1;
        t->val = v;
    }

    return t;
}


struct BTree* init_btree_leaf(int v) {
    struct BTree* t = malloc(sizeof(struct BTree));

    if (t) {
        t->left = NULL;
        t->right = NULL;
        t->node = 0;
        t->val = v;
    }

    return t;
}


void tree_insert(struct BTree* t, int v) {
    if (!t)
        exit(EXIT_FAILURE);

    if (t->val < v) {
        if (t->left) {
            tree_insert(t->left, v);
        } else {
            t->left = init_btree_leaf(v);
        }
    } else if (t->val > v) {
        if (t->right) {
            tree_insert(t->right, v);
        } else {
            t->right = init_btree_leaf(v);
        }
    }
}


int tree_min(struct BTree* t) {
    if (!t->node || t->left== NULL)
        return t->val;

    return tree_min(t->left);
}


int main() {
    struct BTree* t = init_btree_leaf(5);
    int xs[10] = {5, 3, 6, 4, 7, 8, 2, 10, 1};

    if (!t)
        exit(EXIT_FAILURE);

    for (int i = 1; i < 10; i++)
        tree_insert(t, xs[i]);

    printf("%d\n", tree_min(t));
}
