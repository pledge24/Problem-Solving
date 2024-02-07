#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct hop
{
    int size = 0;
    int next = -1;
};

//map<int, hop> m;
vector<hop> m(1000001);

void dp(int N){

    if(m[N].size || N == 1){return;}

    vector<int> v;
    if(N%3 == 0){dp(N/3); v.push_back(N/3);}
    if(N%2 == 0){dp(N/2); v.push_back(N/2);}
    dp(N-1); v.push_back(N-1);

    int next_num = v[0];
    for(int elem: v){
        if(m[elem].size < m[next_num].size){
            next_num = elem;
        }
    }
    //printf("N: %d, next_num: %d\n", N, next_num);

    
    m[N].size = m[next_num].size + 1;
    m[N].next = next_num;

    // printf("N: %d, size: %d\n", N, m[N].size());
    // stack<int> stk_copy(m[N]);
    // while(!stk_copy.empty()) {
    //     cout << stk_copy.top() << endl;
    //     stk_copy.pop();
    // }
    
    return;
}

int main() {
	fastio;
    int N; cin >> N;

    m[1].size = 0; m[1].next = -1;
    m[2].size = 1; m[2].next = 1;
    m[3].size = 1; m[3].next = 1;

    dp(N);

    cout << m[N].size << '\n';

    while (N != -1)
    {
        cout << N << ' ';
        N = m[N].next;
    }
    cout << '\n';
}