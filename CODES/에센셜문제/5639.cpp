#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct node_5639
{
    int num = -1;
    node_5639 *left = NULL;
    node_5639 *right = NULL;
};


node_5639 BinaryTree;

void addNode(int num){

    if(BinaryTree.num == -1){
        BinaryTree.num = num;
        return;
    }

    node_5639 *cur_node = &BinaryTree;
    while(1){

        if(cur_node->num < num){
            if(cur_node->right == NULL){
                cur_node->right = new node_5639({num});
                return;
            }
            else{
                cur_node = cur_node->right;
            }
            
        }
        else{
            if(cur_node->left == NULL){
                cur_node->left = new node_5639({num});
                return;
            }
            else{
                cur_node = cur_node->left;
            }
        }
    }

    return;
}

void print_preorder(node_5639 *cur_node){
    if(cur_node->num == -1) return;

    cout << cur_node->num << '\n';

    if(cur_node->left != NULL){
        print_preorder(cur_node->left);
    }

    if(cur_node->right != NULL){
        print_preorder(cur_node->right);
    }
}

void print_postorder(node_5639 *cur_node){
    if(cur_node->num == -1) return;

    if(cur_node->left != NULL){
        print_postorder(cur_node->left);
    }

    if(cur_node->right != NULL){
        print_postorder(cur_node->right);
    }

    cout << cur_node->num << '\n';
}

int main() {
	fastio;

    int num; cin >> num;
    while(!cin.eof()){
        addNode(num);
        cin >> num;
    }

    //print_preorder(&BinaryTree);
    print_postorder(&BinaryTree);
    //cout << "check\n";
}