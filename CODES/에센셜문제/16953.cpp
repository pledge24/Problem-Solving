#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXN 1000000000

using namespace std;

long long A, B;
queue<long long> q;

int bfs(){
    int cnt = 1;
    long long cur_num, next_num;

    if(A == B) return cnt;

    q.push(A);
    while(!q.empty()){
        
        cnt++;

        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            cur_num = q.front(); q.pop();

            next_num = cur_num * 10 + 1;
            if(next_num <= B){
                if(next_num == B){
                    return cnt;
                }
                q.push(next_num);
            }

            next_num = cur_num * 2;
            if(next_num <= B){
                if(next_num == B){
                    return cnt;
                }
                q.push(next_num);
            }
        }
        
    }

    return -1;
}
int main() {
	fastio;
    cin >> A >> B;

    int ans = bfs();
    
    cout << ans << '\n';
}