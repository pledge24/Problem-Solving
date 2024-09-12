#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

map<int, int> m1;
vector<bool> visited;
vector<int> v1;
string numbers_global;

int numbers_len;

bool isPrime(int num){
    
    if(num < 2) return false;
    
    for(int i = 2; i <= (int)sqrt(num); i++){
        if(num % i == 0) return false;
    }    
    return true;
}

int getAns(){
    int ans = 0;
       
    for(auto it : m1){
        
        if(isPrime(it.first)){
            //cout << it.first << '\n';
            ans++;
        }
    }
    
    return ans++;
}

void dfs(int k, int size){
    
    if(k == size){
        string s = "";
        for(int elem : v1){
            s += numbers_global[elem];
        }
        
        //cout << s << '\n';
        
        m1[stoi(s)]++;
        
        return;
    }
    
    for(int i = 0; i < numbers_len; i++){
        if(!visited[i]){
            v1.push_back(i);
            visited[i] = true;
            
            dfs(k, size+1);
            
            v1.pop_back();
            visited[i] = false;
        }
    }
    
    return;
}

int solution(string numbers) {
    int answer;
    
    numbers_len = numbers.length();
    visited.resize(numbers_len);
    numbers_global = numbers;
    
    for(int i = 1; i<=numbers_len; i++){
        dfs(i, 0);
    }
      
    answer = getAns();
    return answer;
}