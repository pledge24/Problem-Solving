#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct cmp{
    bool operator()(const int& a, const int& b){
        if(abs(a) == abs(b))
            return a > b;
            
        return abs(a) > abs(b);
    }
};

int main(void){
    fastio;
    int N; cin >> N;
    priority_queue<int, vector<int>, cmp> pq;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        if(x == 0){
            int num;
            if(pq.empty()){
                num = 0;
            }
            else{
                num = pq.top(); pq.pop();
            }
            cout << num << '\n'; 

            continue;
        }

        pq.push(x);

    }

    return 0;
}