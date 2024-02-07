#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int T, W;

vector<int> first_tree;
vector<int> second_tree;

void no_move_collect(int pos){
    if(pos == 1){
        for(int i = 0; i<W; i++){
            if(first_tree[i] != 0) first_tree[i]++;      
        }
        first_tree[W]++;     // 처음 위치가 첫번째 나무이므로, 이동 횟수가 없어도 무조건 카운트를 올린다.
    }
    else{
        for(int i = 0; i<=W; i++){
            if(second_tree[i] != 0) second_tree[i]++;     
        }
    }
}

void move_collect(int pos){
    if(pos == 1){
        for(int i = 0; i<W; i++){
            if(second_tree[i+1] != 0) {
                first_tree[i] = max(second_tree[i+1] + 1, first_tree[i]);
            }  
        }
    }
    else{
        for(int i = 0; i<W; i++){
            if(first_tree[i+1] != 0) {
                second_tree[i] = max(first_tree[i+1] + 1, second_tree[i]);
            }   
        }
    }
}

void print_cur_tree(){
    for(int elem : first_tree){
        cout << elem << ' ';
    }
    cout << '\n';

    for(int elem : second_tree){
        cout << elem << ' ';
    }
    cout << '\n';
    cout << '\n';
}

int main() {
	fastio;
    cin >> T >> W;

    vector<int> item_pos(T+1);
    first_tree.resize(W+1);
    second_tree.resize(W+1);

    for(int i=1; i<=T; i++){
        cin >> item_pos[i];
    }
    
    if(item_pos[1] == 1) {first_tree[W] = 1;}
    else {second_tree[W-1] = 1;};

    //print_cur_tree();

    for(int i=2; i<=T; i++){
        
        no_move_collect(item_pos[i]);               
        move_collect(item_pos[i]);
        
        //print_cur_tree();
    }

    cout << max(*max_element(first_tree.begin(), first_tree.end()), *max_element(second_tree.begin(), second_tree.end())) << '\n';
}