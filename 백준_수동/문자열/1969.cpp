#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M; 

int main() {
	fastio;
    cin >> N >> M;

    string str;
    vector<map<char, int>> v1(M);
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int pos = 0; pos < M; pos++){
            v1[pos][str[pos]]++;
        }
    }

    vector<char> v2 = {'A', 'C', 'G', 'T'};
    string ans = ""; int totalHD = 0;
    for(int pos = 0; pos < M; pos++){
        int MaxOverlap = 0;
        char tempC;
        for(char c : v2){
            int overlap = v1[pos][c];
            if(MaxOverlap < overlap){
                MaxOverlap = overlap;
                tempC = c;
            }
        }
        ans += tempC;
        totalHD += N - MaxOverlap;
    }

    cout << ans << '\n';
    cout << totalHD << '\n';
}