#include <bits/stdc++.h>

using namespace std;

// 암호 해독해야함.
// n*n 지도 두 개 있음
// 둘 중에 하나라도 벽이면 벽
// 둘 다 공백이면 공백
// 1이 벽, 0이 공백
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<int> combinedArr(n);
    for(int i = 0; i < n; i++){
        combinedArr[i] = arr1[i] | arr2[i];
    }
    
    // for(int elem : combinedArr){
    //     cout << elem << ' ';
    // }
    // cout << '\n';
    
    for(int i = 0; i < n; i++){
        string str = "";
        for(int j = n-1; j >= 0; j--){
            int num = 1 << j;
            str += (combinedArr[i] & num) > 0 ? '#' : ' ';
        }
        answer.push_back(str);
    }
    return answer;
}