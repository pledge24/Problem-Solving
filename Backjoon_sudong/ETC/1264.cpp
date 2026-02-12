#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<char> mo = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

int main(void){
    fastio;

    string str; getline(cin, str);
    while(str[0] != '#'){
        int cnt = 0;
        for(char c : str){
            if(bool in = any_of(mo.begin(), mo.end(), [=](char elem){return c == elem;})){
                cnt++;
            }
        }
        cout << cnt << '\n';

        getline(cin, str);
    }


    return 0;
}