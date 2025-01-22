#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

bool isNumber(string& s){
    for(char c : s){
        if(!isdigit(c))
            return false;
    }

    return true;
}

int main(void){
    fastio;

    const int N = 3;
    vector<string> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    int ans = 0;
    bool flag = false;
    for(int i = 0; i < N; i++){
        string s = v1[i];
        if(isNumber(s)){
            ans = stoi(s) + (N - i);
            flag = true;
            break;
        }
    }

    if(!flag){
        if(v1.front() == "Fizz") ans = 3 + 3;
        else if(v1.front() == "Buzz") ans = 5 + 3;
        else ans = 15 + 3;
    }

    bool Fizz = !(ans % 3);
    bool Buzz = !(ans % 5);

    string str_ans;
    if(Fizz) str_ans.append("Fizz");
    if(Buzz) str_ans.append("Buzz");

    if(str_ans.length() > 0 )
        cout << str_ans << '\n';
    else
        cout << ans << '\n';
    

    return 0;
}