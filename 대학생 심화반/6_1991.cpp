#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct node{
    char left;
    char right;
};

map<char, node> tree;

// 전위 순회: (루트) (왼쪽 자식) (오른쪽 자식)
void print_preorder(char root){
    if(root == '.'){
        return;
    }

    cout << root;
    print_preorder(tree[root].left);
    print_preorder(tree[root].right);
}

// 중위 순회: (왼쪽 자식) (루트) (오른쪽 자식)
void print_inorder(char root){

    if(root == '.'){
        return;
    }
 
    print_inorder(tree[root].left);
    cout << root;
    print_inorder(tree[root].right);
}

// 후위 순회: (왼쪽 자식) (오른쪽 자식) (루트)
void print_postorder(char root){

    if(root == '.'){
        return;
    }
 
    print_postorder(tree[root].left);
    print_postorder(tree[root].right);
    cout << root;
}

int main() {
	fastio;
    int N; cin >> N;
    
    char root, left, right;
    char start_node;
    for(int i = 0; i < N; i++){
        cin >> root >> left >> right;
        tree[root] = {left, right};

        if(i == 0) start_node = root;
    }

    print_preorder(start_node);
    cout << '\n';

    print_inorder(start_node);
    cout << '\n';

    print_postorder(start_node);
    cout << '\n';
}