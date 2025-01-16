#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N, K; cin >> N >> K;

    vector<bool> visited(N);
    int pos = 0;
    cout << '<';
    for(int i = 0; i < N; i++){
        int cnt = 0;
        do{
            if(!visited[pos]){
                cnt++;
                if(cnt == K){
                    visited[pos] = true;

                    cout << pos + 1;
                }
            }
            pos = (pos + 1) % N;

        }while(cnt < K);
        
        if(i+1 < N){
            cout << ", ";
        }
    }
    cout << '>';

    return 0;
} 