#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

bool isPrime(long long num){
    if(num < 2) return false;
    
    for(int i = 2; i <= (int)sqrt(num); i++){
        if(num % i == 0){
            return false;
        } 
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    vector<int> v1;
    while(n > 0){
        v1.push_back(n % k);
        n /= k;
    }
    
    reverse(v1.begin(), v1.end());
    v1.push_back(0);
    
    string num = "";
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << ' ';
        if(v1[i] != 0){
            num += to_string(v1[i]);
        }
        else{
            if(num.length() > 0){               
                answer += isPrime(stoll(num)) ? 1 : 0;
                //cout << num << " " << answer << '\n';
                num = "";
            }
            
        }
    }
           
    return answer;
}