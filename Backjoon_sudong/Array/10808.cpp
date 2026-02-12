#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    vector<int> v1(30);

    string str; cin >> str;
    for(char c : str){
        v1[c-'a']++;
    }

    for(int i = 0; i <= 'z' - 'a'; i++)
        cout << v1[i] << ' ';

    return 0;
}