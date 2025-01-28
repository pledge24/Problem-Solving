#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void startTest(){
    string cmd; cin >> cmd;

    int N; cin >> N;
    string str; cin >> str;
    vector<int> v1;

    string num = "";
    for(char c : str){
        if(isdigit(c)){
            num += c;
        }
        else{
            if(num.length() > 0){
                v1.push_back(stoi(num));
                num = "";
            }
        }
    }

    if(v1.size() == 0){
        if(cmd.find('D') == string::npos){
            cout << "[]" << '\n';
        }
        else{
            cout << "error" << '\n';
        }
        return;
    }

    int start = 0;
    int end = v1.size()-1;
    bool isReversed = false;
    for(char c : cmd){
        if(c == 'R'){
            isReversed = !isReversed;
        }
        else if(c == 'D'){
            if(isReversed) end--;
            else start++;
        }

        if(start > end || /*overRange*/(start >= v1.size() || end < 0)){
            cout << "error" << '\n';
            return;
        }
            
    }
    
    if(isReversed){
        cout << '[';
        for(; end > start; end--){
            cout << v1[end] << ",";
        }
        
        cout << v1[start] << "]\n";
    }
    else{
        cout << '[';
        for(; start < end; start++){
            cout << v1[start] << ",";
        }
        
        cout << v1[end] << "]\n";
    }
    
}

int main(void){
    fastio;

    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTest();
    }

    return 0;
}