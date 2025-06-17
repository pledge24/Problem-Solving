#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    string str; cin >> str;
    int strLen = str.length();


    int totalA = count(str.begin(), str.end(), 'a');
    
    int curA, maxA;
    maxA = curA = count(str.begin(), str.begin() + totalA, 'a');
    int e = totalA-1;
    for(int s = 0; s < strLen; s++){
        maxA = max(maxA, curA);

        // next set
        e = (e+1) % strLen;
        curA -= str[s] == 'a';
        curA += str[e] == 'a';
    }

    cout << totalA - maxA << '\n';

    return 0;
}