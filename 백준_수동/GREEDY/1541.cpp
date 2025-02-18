#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    string str; cin >> str;

    // split하는 방법에 대한 고찰... 
    // 음... 참조를 넘겨줄까?

    string str_num = "";
    int ans = 0;
    int minusOffset = 1; 
    for(char c : str){
        if(isdigit(c)){
            // 앞에 0붙는거 방지
            if(str_num.length() == 0 && c == '0'){}
            else str_num += c;     
            continue;
        }

        // +나 -인경우 진입
        if(str_num.length() > 0){   // 값이 존재할때만 더한다.
            ans += stoi(str_num) * minusOffset;
            str_num = "";
        }

        if(c == '-'){
            minusOffset = -1;
        }

    }

    if(str_num.length() > 0){
        ans += stoi(str_num) * minusOffset;
        str_num = "";
    }

    cout << ans << '\n';
}