#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;


int main(void){
    fastio;

    int N, K; cin >> N >> K;

    vector<int> v1(N);
    for(int i = 0; i < N; i++){
        char c;
        cin >> c;
        v1[i] = c - '0';
    }

    int curK = 0; // 현재 지운 개수
    vector<bool> banList(N);
    stack<pair<int, int>> s;

    for(int idx = 0; (idx < N && curK < K); idx++){
        int num = v1[idx];

        // 시작 시.
        if(idx == 0){
            s.push({idx, num});
            continue;
        }

        // 오름차순 발견
        if(s.top().second < num){
            // 현재 숫자가 스택에서 가장 작은 수가 될 때까지 반복
            while(!s.empty() && s.top().second < num){
                int curIdx = s.top().first; s.pop();

                banList[curIdx] = true;
                curK++;

                if(curK == K){
                    break;
                }
            }
        }

        s.push({idx, num});
        
    }
    
    string ans = "";
    for(int i = 0; i < N; i++){
        if(banList[i] == false){
            ans += (v1[i] + '0');
        }   
            
    }

    cout << ans.substr(0, N-K) << '\n';

    return 0;
}