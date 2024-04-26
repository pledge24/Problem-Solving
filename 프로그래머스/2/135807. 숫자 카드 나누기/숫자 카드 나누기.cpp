#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int gcd_n(vector<int>& arr) {
    int result = arr[0];
    for(int i = 1; i < arr.size(); i++){
        result = gcd(result, arr[i]);
    }
    return result;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int gcdA = gcd_n(arrayA);       // arrayA의 최대 공약수
    int gcdB = gcd_n(arrayB);       // arrayB의 최대 공약수
    
    if(gcdA != 1){
        bool find = true;
        for(int elem : arrayB){
            if(elem % gcdA == 0){
                find = false;
                break;
            } 
        }
        
        if(find) answer = gcdA;
    }
    
    if(gcdB != 1){
        bool find = true;
        for(int elem : arrayA){
            if(elem % gcdB == 0){
                find = false;
                break;
            } 
        }
        
        if(find) answer = max(answer, gcdB);
    }
    
    // cout << gcdA << '\n';
    // cout << gcdB << '\n';
    return answer;
}