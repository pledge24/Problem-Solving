#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using BinaryTree = vector<pair<int, int>>;

int N; 

void InOrder(BinaryTree& tree, int cur, int& moveCnt, bool onlyRight){
    
    if(tree[cur].first != -1){ // left Node
        // cout << "Move " << cur << " To " << tree[cur].first << '\n';
        moveCnt++;
        InOrder(tree, tree[cur].first, moveCnt, onlyRight && false); 
    }

    if(tree[cur].second != -1){ // right Node
        // cout << "Move " << cur << " To " << tree[cur].second << '\n';
        moveCnt++;
        InOrder(tree, tree[cur].second, moveCnt, onlyRight && true); 
    }

    // cout << "Move " << cur << " To " << "Back" << '\n';
    if(!onlyRight)
        moveCnt++;

    return;
}

int main(void){
    fastio;
    cin >> N;
    BinaryTree tree(N+1);
    for(int i = 0; i < N; i++){
        int vtx, left, right;
        cin >> vtx >> left >> right;
        tree[vtx] = make_pair(left, right);
    }

    int cnt = 0;
    InOrder(tree, 1/*startNode*/, cnt, true);

    int ans = cnt;
    cout << ans << '\n';

    return 0;
}