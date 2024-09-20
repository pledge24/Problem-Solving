#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct mixData{
    int idx0;
    int idx1;
    int idx2;
    int res;
};

mixData calcMinMix(vector<int>& v1, int idx){

    int e = v1.size()-1;
    cout << "===test===\n";
    cout << "test " << idx << " " << idx+1 << " " << e << "\n";
    mixData minMix = {-1, -1, -1, INT32_MAX};
    for(int s = idx+1; s < e; s++){
        mixData candMixData = {idx, s, e, abs(v1[s] + v1[e] + v1[idx])};
        while(s < e){                   
            candMixData = {idx, s, e, abs(v1[s] + v1[e] + v1[idx])};

            if(v1[e] < 0){
                s = e - 1;
                candMixData = {idx, s, e, abs(v1[s] + v1[e] + v1[idx])};
                return candMixData;
            }

            if(v1[idx] + v1[s] > 0){
                e = s + 1;
                candMixData = {idx, s, e, abs(v1[s] + v1[e] + v1[idx])};
                return candMixData;
            }
            
            if(abs(v1[idx] + v1[s]) < abs(v1[e])){
                break;
            }
  
            e--;

        }
        if(candMixData.res < minMix.res) 
            minMix = candMixData;

    }

    cout << minMix.idx0 << " " << minMix.idx1 << " " << minMix.idx2 << " " << minMix.res << '\n';
    return minMix;
}

int main() {
	fastio;
    int N; cin >> N;

    vector<int> v1(N);
    for(int i = 0; i < N; i++) cin >> v1[i];

    sort(v1.begin(), v1.end());

    mixData ans = {0, 0, 0, INT32_MAX};

    for(int i = 0; i < N; i++){
        mixData md = calcMinMix(v1, i);
        if(md.res < ans.res) ans = md;
    }

    cout << v1[ans.idx0] << " " << v1[ans.idx1] << " " << v1[ans.idx2] << '\n';
    
}