#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXGAP 2'000'000'001

using namespace std;

vector<long long> v1;

// 항상 음수만 본다고 가정
int findMinGapIdx(int idx){
    int low = idx+1;
    int high = v1.size()-1;
    int mid = (low+high)/2;

    if(abs(v1[idx]) > v1[high]){
        return high;
    }

    if(abs(v1[idx]) < v1[low]){
        return low;
    }

    while(low < high){

        if(abs(v1[idx]) > v1[mid]){
            low = mid+1;
        }
        else{
            high = mid;
        }

        mid = (low+high)/2;
    }

    int min_idx = abs(v1[mid] + v1[idx]) < abs(v1[mid-1] + v1[idx]) ? mid : mid-1;
    return min_idx;
}

int main() {
	fastio;
    int N; cin >> N;
    
    v1.resize(N);

    bool findFirstPositive = false;
    int firstPositiveIdx = -1;

    // input data
    for(int i = 0; i < N; i++){
        cin >> v1[i];
        if(!findFirstPositive && v1[i] > 0){
            findFirstPositive = true;
            firstPositiveIdx = i;
        }
    }
    
    // 양수로 시작하면, 0번째와 1번째의 합이 가장 0에 가깝다.
    if(v1[0] > 0){
        cout << v1[0] << " " << v1[1] << '\n';
        return 0;
    }

    // 양수가 없다면, 가장 끝에 있는 두 값의 합이 가장 0에 가깝다.
    if(!findFirstPositive){
        cout << v1[v1.size()-2] << " " << v1[v1.size()-1] << '\n';
        return 0;
    }

    long long ans1, ans2;
    long long minGap = MAXGAP;
    for(int i = 0; i < N-1; i++){
        int idx = findMinGapIdx(i);

        if(abs(v1[i] + v1[idx]) <= minGap){
            minGap = abs(v1[i] + v1[idx]);
            ans1 = v1[i];
            ans2 = v1[idx];
        }
    }
    
    cout << ans1 << " " << ans2 << '\n';
}