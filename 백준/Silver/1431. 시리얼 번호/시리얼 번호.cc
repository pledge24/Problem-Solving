#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Data = pair<string, int>;

struct cmp{
    bool operator()(const Data& d1, const Data& d2){
        // 길이가 짧은게 앞으로,
        if(d1.first.length() != d2.first.length())
            return d1.first.length() < d2.first.length();

        // 자리수 합이 작은게 앞으로,
        if(d1.second != d2.second)
            return d1.second < d2.second;

        // 사전순 비교.
        return d1.first < d2.first;
    }
};

int main(void){
    fastio;
    int N; cin >> N;
    vector<Data> v1(N);
    for(int i = 0; i < N; i++){
        string str; cin >> str;
        int digitsN = 0;
        for(char c : str){
            if(isdigit(c))
                digitsN += (c-'0');
        }

        v1[i] = make_pair(str, digitsN);
    }


    sort(v1.begin(), v1.end(), cmp());

    for(const Data& data : v1){
        cout << data.first << '\n';
    }

    return 0;
}