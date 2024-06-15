#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<int> multiTap;

int N, K;

bool isFull(int num){
    return num == N;
}

bool isHit(int num){
    return num < N;
}

int main() {
	fastio;
    cin >> N >> K;

    multiTap.resize(N, -1);

    vector<queue<int>> usage_order(K+1);
    vector<int> order(K+1);
    int num;
    for(int i = 1; i <= K; i++){
        cin >> num;
        order[i] = num;
        usage_order[num].push(i);
    }
    
    
    int cnt = 0;
    for(int i = 1; i <= K; i++){
        
        int cur_num = order[i];
        usage_order[cur_num].pop();
        
        int Hit_code = find(multiTap.begin(), multiTap.end(), cur_num) - multiTap.begin();    // 값이 N이면 없음, N 이하면 존재함.

        
        if(!isHit(Hit_code)){

            int empty_code = find(multiTap.begin(), multiTap.end(), -1) - multiTap.begin();    // 값이 N이면 없음, N 이하면 존재함.
            if(isHit(empty_code)){
                multiTap[empty_code] = cur_num;
                //cout << "check" << '\n';
            }
            else{
                int change_idx = 0;
                for(int m_idx = 0; m_idx < N; m_idx++){
                    int product_id = multiTap[m_idx];
                    //printf("current multi_num = %d\n", multi_num);
                    if(usage_order[product_id].empty()){
                        //cout << "check" << '\n';
                        change_idx = m_idx;
                        break;
                    }
                    
                    change_idx = usage_order[product_id].front() > usage_order[multiTap[change_idx]].front() ? m_idx : change_idx;
                }

                //printf("change idx: %d, %d -> %d\n", change_idx, multiTap[change_idx], cur_num);
                multiTap[change_idx] = cur_num;
                
                cnt++;
            }
            
        }
        
 
        // for(int j = 0; j < N; j++){
        //     cout << multiTap[j] << ' ';
        // }
        // cout << '\n';
    }

    int ans = cnt;
    cout << ans << '\n';
}