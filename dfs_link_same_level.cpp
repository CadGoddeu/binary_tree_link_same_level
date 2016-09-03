//developex test dfs (recursive) for binary tree
//Link nodes at same level in a binary tree
//Time complexity: O(n) - BFS for binary tree.
//Space complexity: O(d) - where d is depth.

#include <iostream>
#include <queue>

struct node
{
    int n; // value of node
    struct node *left; // left subtree
    struct node *right; // right subtree
    struct node *level; // level pointer (node “to the right”)
};

struct node *getLevel(struct node *t)
{
    struct node *temp = t->level;

    while(temp){
        if(temp->left)
            return temp->left;
        if(temp->right)
            return temp->right;
        temp = temp->level;
    }

    return NULL;
}

void linkSameLevel(struct node *t){

    if(!t)
        return;

    if (t->level)
        linkSameLevel(t->level);

    if (t->left){
        if (t->right){
            t->left->level = t->right;
            t->right->level = getLevel(t);
        }
        else
            t->left->level = getLevel(t);

        linkSameLevel(t->left);
    }
    else if (t->right){
        t->right->level = getLevel(t);
        linkSameLevel(t->right);
    }
    else
        linkSameLevel(getLevel(t));
}

int main()
{
    node* a = new node[9];
    a[0].n = 1;
    a[1].n = 2;
    a[2].n = 3;
    a[3].n = 4;
    a[4].n = 5;
    a[5].n = 6;
    a[6].n = 7;
    a[7].n = 8;
    a[8].n = 9;
    for(int i=0;i<9;i++){
        a[i].left = a[i].right = a[i].level = NULL;
    }

    a[0].left = &a[1];
    a[0].right = &a[2];
    a[1].left = &a[3];
    a[2].left = &a[4];
    a[2].right = &a[5];
    a[3].left = &a[6];
    a[5].left = &a[7];
    a[5].right = &a[8];
    linkSameLevel(&a[0]);
    for(int i=0;i<9;i++){
        std::cout << a[i].n << " " << &a[i].n << " --------------- " << &a[i].left << " " << &a[i].right << " " << a[i].level << std::endl;
    }
}