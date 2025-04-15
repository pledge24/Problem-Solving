#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;

    priority_queue<long long> positive_pq;
    priority_queue<long long, vector<long long>, greater<long long>> negative_pq;
    bool haveZero = false;
    for(int i = 0; i < N; i++){
        long long num; cin >> num;

        if(num == 0){
            haveZero = true;
            continue;
        }

        if(num > 0)
            positive_pq.push(num);
        else
            negative_pq.push(num);
    }

    long long ans = 0;
    while(positive_pq.size() > 1){
        long long A = positive_pq.top(); positive_pq.pop();
        long long B = positive_pq.top(); positive_pq.pop();

        ans += max(A*B, A+B);
    }
    if(!positive_pq.empty())
        ans += positive_pq.top(); positive_pq.pop();
    
    while(negative_pq.size() > 1){
        long long A = negative_pq.top(); negative_pq.pop();
        long long B = negative_pq.top(); negative_pq.pop();

        ans += A*B;
    }
    if(!negative_pq.empty()){
        ans += negative_pq.top()*(!haveZero); negative_pq.pop();
    }
        
    cout << ans << '\n';

    return 0;
}