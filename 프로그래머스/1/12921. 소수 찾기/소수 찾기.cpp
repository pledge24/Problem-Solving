#include <bits/stdc++.h>

#define OUT

using namespace std;

void Eratos(int n, int& answer){
    vector<bool> primeList(n+1);
    vector<bool> visited(n+1);
    for(int i = 2; i <= n; i++){
        if(visited[i] == true){
            continue;
        }
        
        primeList[i] = true;
        
        int multiplyN = 2;
        while(i*multiplyN <= n){
            visited[i*multiplyN] = true;
            multiplyN++;
        }
    }
    
    answer = count(primeList.begin(), primeList.end(), true);
}

int solution(int n) {
    int answer = 0;
    
    Eratos(n, OUT answer);
    
    return answer;
}