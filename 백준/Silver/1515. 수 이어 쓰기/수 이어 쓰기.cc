#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    string str; cin >> str;

    int pointer = 0;
    int num = 1;
    
    while (pointer < str.length()) {
        string num_str = to_string(num);
        
        for (char digit : num_str) {
            if (pointer < str.length() && digit == str[pointer]) {
                pointer++;
            }
        }
        
        num++;
    }
    
    cout << num - 1 << endl;

    return 0;
}