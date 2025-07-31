#include <bits/stdc++.h>

#define PWD_SIZE 5

using namespace std;

// 1~n 까지의 서로 다른 정수 5개가 "오름차순"으로 주어짐
// 5개의 정수를 입력하면 포함된 정수의 개수를 알려줌. -> "5번" 시도한 결과가 주어짐
// -> 가능한 정수 조합의 개수는?
// "단, 비밀 코드가 존재하지 않는 경우는 주어지지 않는다."

bool isMatch(vector<vector<int>>& q, vector<int>& ans, vector<int>& sequence){
    vector<int> res(PWD_SIZE);
    set<int> s1;
    
    // sequence에 있는 원소를 집합에 넣는다.
    for(int elem : sequence)
        s1.insert(elem);
    
    for(int i = 0; i < q.size(); i++){
        int cnt = 0;
        vector<int>& tryList = q[i];
        
        for(auto elem : tryList){
            cnt += s1.find(elem) != s1.end();
        }
        
        if(ans[i] != cnt)
            return false;
    }
    
    return true;
}

// 30C5 -> 30*29*28*27*26 / 5! '==. 30^4 '==. 약 100만번
void DfsUtil(int& n, vector<vector<int>>& q, vector<int>& ans, int& answer, vector<int>& sequence){
    // 종료 조건
    if(sequence.size() == PWD_SIZE){
        // for(int elem : sequence)
        //     cout << elem << ' ';
        // cout << '\n';
        
        answer += isMatch(q, ans, sequence);
        return;
    }
    
    int maxNum = sequence.empty() == false ? sequence.back() : 0;
    for(int i = maxNum + 1; i <= n; i++){
        sequence.push_back(i);
        DfsUtil(n, q, ans, answer, sequence);
        sequence.pop_back();
    }
}

void Dfs(int& n, vector<vector<int>>& q, vector<int>& ans, int& answer){
    vector<int> sequence;
    
    DfsUtil(n, q, ans, answer, sequence);
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    Dfs(n, q, ans, answer);
    
    return answer;
}