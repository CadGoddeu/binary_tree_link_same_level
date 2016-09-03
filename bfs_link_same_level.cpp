//developex test bfs for binary tree
//Link nodes at same level in a binary tree
//Time complexity: O(n) - BFS for binary tree.
//Space complexity: O(n) - worst case for holding n vertices in the queue

#include <iostream>
#include <queue>

struct node
{
    int n; // value of node
    struct node *left; // left subtree
    struct node *right; // right subtree
    struct node *level; // level pointer (node “to the right”)
};

void linkSameLevel(struct node *t){
    //bfs queue
    std::queue<node *> q;

    if (!t)
        return;

    node *prev_node = NULL;

    int count_level_nodes = 1;
    int count_next_level_nodes = 0;

    for (q.push(t); !q.empty(); q.pop())  {
        node * temp_node = q.front();
        //push left branch
        if (temp_node->left) {
            q.push(temp_node->left);
            count_next_level_nodes++;
        }
        //push right branch
        if (temp_node->right) {
            q.push(temp_node->right);
            count_next_level_nodes++;
        }
        //link same level nodes
        if (prev_node)
            prev_node->level = temp_node;

        prev_node = temp_node;
        count_level_nodes--;

        //end of the level
        if (!count_level_nodes) {
            count_level_nodes = count_next_level_nodes;
            count_next_level_nodes = 0;
            prev_node = NULL;
        }
    }
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

