#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    // 2. col 기준으로 오름차순 정렬, 동일하면 첫 번째 기준으로 내림차순 정렬   
    sort(data.begin(), data.end(), [col](const auto& a, const auto& b){
        if(a[col-1] == b[col-1]) return a[0] > b[0];
        return a[col-1] < b[col-1];
    });
    
    // for(vector<int> elem_list : data){
    //     for(int elem : elem_list){
    //         cout << elem << ' ';
    //     }
    //     cout << '\n';        
    // }
    
    // 3. S_i 구하기
    vector<int> S_i;
    for(int i = 0; i < data.size(); i++){
        int sum = 0;
        for(int elem : data[i]){
            sum += elem % (i+1);
        }
        //cout << "sum : " << sum << '\n';
        S_i.push_back(sum);
    }
    
    int ans = S_i[row_begin-1];
    for(int idx = row_begin; idx <= row_end - 1; idx++){
        ans ^= S_i[idx];
    }
    
    //cout << ans << '\n';
    
    answer = ans;
    
    return answer;
}