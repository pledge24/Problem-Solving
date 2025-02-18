#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// target이상인 부분 합의 최소 길이 반환
int twoPointer(vector<int>& v1, int target){
    int len = v1.size();
    int end = 0, sum = v1[0]; // start와 end는 겹쳐있다는 설정.
    int minLen = INT32_MAX;

    // start포인터 이동: 반복당 한 번 이동
    for(int start = 0; start < len; start++){
        // end포인터 이동: sum이 target이상이 될 때까지 이동
        while(end < len && sum < target){
            end++;
            if(end != len) sum += v1[end];  // 예외처리
        }

        // 더 이상 S 이상인 구간이 없음
        if(end == len) break;

        // 현재 start의 최소 길이와 비교 및 갱신
        minLen = min(minLen, end-start+1);
        sum -= v1[start];
    }

    return minLen;
}

// 두 용액의 합이 0과 가장 가까운 값 반환(ver1)
pair<int, int> twoPointer2(vector<int>& v1){
    int len = v1.size();
    int end = len-1;
    pair<int, int> p = {v1[0], v1[end]};
    int minSum = abs(v1[0] + v1[end]);

    // start포인터 이동: 반복당 한 번 이동
    for(int start = 0; start < end; start++){
        pair<int, int> tempP = {v1[start], v1[end]};
        int tempSum = abs(v1[start] + v1[end]);

        // end포인터 이동: start에 가장 어울리는 end를 찾을 때까지 이동
        while(start < end && abs(v1[start] + v1[end-1]) < tempSum){
            end--;
            if(start != end){   // 예외처리
                tempP = {v1[start], v1[end]};
                tempSum = abs(v1[start] + v1[end]);
            } 
        }

        // 현재 start의 최소값과 비교 및 갱신
        if(tempSum < minSum){
            p = tempP;
            minSum = tempSum;    
        }
       
    }

    return p;
}

// 두 용액의 합이 0과 가장 가까운 값 반환(ver2)
pair<int, int> twoPointer2(vector<int>& v1){
    int len = v1.size();
    int start = 0, end = len-1;
    pair<int, int> p = {v1[0], v1[end]};
    int minSum = abs(v1[0] + v1[end]);

    while(start < end){
        // start, end포인터 이동: 두 용액의 합이 양수면 end, 아니면 start 이동
        if(v1[start] + v1[end] > 0) end--; 
        else start++;

        // 더 이상 구간이 없음
        if(start == end) break;

        // 현재 최소값과 비교 및 갱신
        if(abs(v1[start] + v1[end]) < minSum){
            p = {v1[start], v1[end]};
            minSum = abs(v1[start] + v1[end]);    
        }
    }
    
    return p;
}

int main() {
	fastio;
    int N; cin >> N;

    vector<int> v1; v1.resize(N);

    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    sort(v1.begin(), v1.end());

    pair<int, int> ans = twoPointer2(v1);

    cout << ans.first << " " << ans.second << '\n';
    
}