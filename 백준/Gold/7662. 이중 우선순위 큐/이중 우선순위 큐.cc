#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void startTestcase(){

    int k; cin >> k;

    map<int, int> m;
    for(int i = 0; i < k; i++){
        char op; int num;
        cin >> op >> num;

        if(op == 'I'){
            m[num]++;
        }
        else if(op == 'D'){
            // 비어있을때 삭제 연산은 무시.
            if(m.empty()) 
                continue;
                
            int key = num == 1 ? prev(m.end())->first : m.begin()->first;
            m[key]--;

            // cout << "key: " << key << " m[key] " << m[key] << '\n';

            if(m[key] == 0)
                m.erase(key);
        }

        // for(auto it : m){
        //     cout << it.first << ' ';
        // }
        // cout << '\n';

    }

    // 결과 출력
    if(m.empty())
        cout << "EMPTY" << '\n';
    else
        cout << prev(m.end())->first << " " << m.begin()->first << '\n';
}

int main(void){
    fastio;
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTestcase();
    }

    return 0;
}