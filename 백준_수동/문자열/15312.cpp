#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    vector<int> lines = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

    string myName, herName;
    cin >> myName >> herName;

    int len = myName.length();
    vector<int> v1;
    v1.resize(len*2);
    for(int i = 0; i < len; i++){
        v1[i*2] = lines[myName[i] - 'A'];
        v1[i*2 + 1] = lines[herName[i] - 'A'];
    }

    int size = v1.size();
    while(size > 2){
        for(int i = 0; i < size-1; i++){
            v1[i] = (v1[i] + v1[i+1]) % 10;
        }

        size--;
    }

    string ans = to_string(v1[0]) + to_string(v1[1]);

    cout << ans << '\n';
}