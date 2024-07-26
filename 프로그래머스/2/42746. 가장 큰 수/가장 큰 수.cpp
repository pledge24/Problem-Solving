#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp (int a, int b){

    int temp_a = a;
    int temp_b = b;
    
    while(temp_a >= 10.0) temp_a/=10;
    while(temp_b >= 10.0) temp_b/=10;
    
    if(temp_a == temp_b){
        string str_a = to_string(a);
        string str_b = to_string(b);
        
        return str_a + str_b > str_b + str_a;
    }
    return temp_a > temp_b;
}
string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    for(int elem : numbers){
        answer += to_string(elem);
    }
    
    if(answer.length() > 0 && answer[0] == '0') return "0";
    return answer;
}