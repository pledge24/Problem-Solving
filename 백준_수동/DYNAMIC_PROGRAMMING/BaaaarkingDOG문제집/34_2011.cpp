#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ALPHA 27
#define DIV 1000000

using namespace std;

bool inRange(int num){
    //cout << "ss: " << num << '\n'; 
    return 0 < num && num <= ALPHA;
}

int main() {
	fastio;
    string s; cin >> s;

    s.insert(0, " ");

    vector<int>v1(s.length());

    v1[0] = 1, v1[1] = 1;
    int prev, curr, next;
    bool isImposiible = false;
    if(s[1] != '0'){
        for(int i = 2; i < s.length(); i++){
            prev = s[i-1] - '0';
            curr = s[i] - '0';
            
            int alpha_num = prev*10 + curr;

            // 1. 현재 또는 바로 다음 수가 0일 경우, i-1번째 경우의 수를 그대로 가져온다.
            // 2. 이전 값이 0이 아니고, 범위 안의 값일 때 전전값을 추가하여 저장한다.
            // 3. 범위 밖의 값일 때, 이전 값을 그대로 가져온다.
            if( (i+1 < s.length() && s[i+1] == '0') || s[i] == '0'){
                v1[i] = v1[i-1] % DIV;
            }
            else if(s[i-1] != '0' && inRange(alpha_num)){
                v1[i] = (v1[i-1] + v1[i-2]) % DIV;
            }
            else{
                v1[i] = v1[i-1] % DIV;
            }

            // 이전 또는 현재 값이 0이고, 범위 밖의 값일 경우, 불가능처리 후 루프를 탈출한다.
            if((prev == 0 || curr == 0) && !inRange(alpha_num)){
                isImposiible = true;
                break;
            }
        }
    }
    else{
        isImposiible = true;
    }
    
    // for(int i = 1; i < s.length(); i++){
    //     cout << v1[i] << ' ';
    // }
    // cout << '\n';

    int ans = isImposiible ? 0 : v1[s.length()-1];

    cout << ans << '\n';

}