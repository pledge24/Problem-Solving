#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    string str; getline(cin, str);
    int idx = 0;
    int len = str.length();

    while(idx < len){
        // 1) 태그는 무시한다.
        if(str[idx] == '<'){
            while(str[idx] != '>') idx++;
        }
        // 단어는 공백으로 분리되어 있다.
        else if(str[idx] != ' '){
            int prevIdx = idx;
            while(idx < len && str[idx] != ' ' && str[idx] != '<') idx++;

            int wordLen = idx - prevIdx;
            if(wordLen > 0){
                ::reverse(str.begin()+prevIdx, str.begin()+idx);
            }

            continue;
        }

        idx++;
    }

    cout << str << '\n';
    
}