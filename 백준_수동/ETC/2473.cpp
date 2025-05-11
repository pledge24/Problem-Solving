#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

pair<long long, long long> calcMinGap(vector<long long>& liquids, long long idx){
    pair<long long, long long> minCombi = make_pair(-1, -1);
    long long offset = liquids[idx];
    long long minGap = INT64_MAX;

    // start ----> 
    long long start = 0;
    long long end = liquids.size() - 1;

    start += (start == idx);
    end -= (end == idx);

    while(start < end){
        // 갱신 조건.
        long long gap = liquids[start] + liquids[end] + liquids[idx];
        if(abs(gap) < minGap){
            minGap = abs(gap);
            minCombi = make_pair(start, end);
        }

        // 시작을 옮기면 값은 커진다.
        // 끝을 옮기면 값은 작아진다.
        // => 값이 컸다면 끝을 옮기고, 작았다면 시작을 옮긴다.
        if(gap > 0)
            end -= 1 + (end-1 == idx);
        else if(gap < 0)
            start += 1 + (start+1 == idx);
        else
            break;

    }

    // prlong longf("idx: (%d %d %d) => (%d %d %d) = %d\n", 
    //     idx, minCombi.first, minCombi.second, 
    //     liquids[idx], liquids[minCombi.first], liquids[minCombi.second], 
    //     minGap
    // );

    return minCombi;
}

int main(void){
    fastio;
    long long N; cin >> N;
    vector<long long> liquids(N);
    for(long long i = 0; i < N; i++){
        cin >> liquids[i];
    }

    sort(liquids.begin(), liquids.end());

    long long minGap = INT64_MAX;
    vector<long long> ans;
    for(long long i = 0; i < N; i++){
        pair<long long, long long> p1 = calcMinGap(liquids, i);
        
        long long gap = abs(liquids[i] + liquids[p1.first] + liquids[p1.second]);
        if(gap < minGap){
            minGap = gap;
            ans = {liquids[i], liquids[p1.first], liquids[p1.second]};
        }
    }

    sort(ans.begin(), ans.end());
    for(long long elem : ans)
        cout << elem << ' ';
    cout << '\n';

    return 0;
}