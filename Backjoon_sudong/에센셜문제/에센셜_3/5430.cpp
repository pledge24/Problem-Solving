#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void startTest(){
    string p; cin >> p;
    int n; cin >> n;
    string vectorList; cin >> vectorList;

    // store list
    vector<int> v1;
    string num = "";
    for(char c : vectorList){
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

    // size = 0
    if(v1.size() == 0){
        if(p.find('D') == string::npos){
            cout << "[]" << '\n';
        }
        else{
            cout << "error" << '\n';
        }
        return;
    }

    // size > 0
    int start = 0;
    int end = v1.size();
    bool isReversed = false;
    for(char c : p){
        if(c == 'R'){
            isReversed = !isReversed;
        }
        else if(c == 'D'){
            if(isReversed) end--;
            else start++;
        }

        if(start > end){
            cout << "error" << '\n';
            return;
        }
            
    }

    // print
    if(isReversed){
        cout << '[';
        for(int i = end-1; start <= i; i--){
            cout << v1[i];
            if(i != start){
                cout << ',';
            }
        }
        cout << ']' << '\n';
    }
    else{
        cout << '[';
        for(int i = start; i <= end-1; i++){
            cout << v1[i];
            if(i != end-1){
                cout << ',';
            }
        }
        cout << ']' << '\n';
    }
    
    return;
}

int main(void){
    fastio;

    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTest();
    }

    return 0;
}