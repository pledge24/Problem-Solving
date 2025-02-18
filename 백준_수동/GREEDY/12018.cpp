#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct s_data{
    // 신청자 수 / 정원
    int maxN;
    vector<int> b;
};

bool cmp(const int a, const int b){
    return a > b;   // 내림차
}

int main(void){
    fastio;

    int n, m; cin >> n >> m;

    vector<s_data> v1(n);
    vector<int> minMile(n);
    for(int i = 0; i < n; i++){
        int pi, li; cin >> pi >> li;
        s_data s;
        
        s.maxN = li;
        s.b.resize(pi);
        for(int j = 0; j < pi; j++){
            cin >> s.b[j];
        }
        sort(s.b.begin(), s.b.end(), cmp);

        // 정원 미달인 경우
        if(pi < li){
            minMile[i] = 1;
        }
        // 정원 초과인 경우 li번째로 많이 낸 사람이 되면 됨.
        else{
            minMile[i] = s.b[li-1];
        }
    }

    sort(minMile.begin(), minMile.end());

    int cnt = 0;
    for(int elem : minMile){
        if(m - elem < 0)
            break;
        
        m -= elem;
        cnt++;
    }

    int ans  = cnt;
    cout << ans << '\n';
 
    return 0;
}