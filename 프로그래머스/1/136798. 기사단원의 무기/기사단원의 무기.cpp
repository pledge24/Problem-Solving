#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int getMeasureN(int num){
    int cnt = 0;
    for(int i = 1; i <= (int)sqrt(num); i++){
        if(num % i == 0){
            cnt+=2;
        }
    }
    
    if((int)sqrt(num) * (int)sqrt(num) == num) cnt--;
    
    return cnt;
}
int solution(int number, int limit, int power) {
    int answer = 0;
    
    
    int measures; 
    for(int i = 1; i <= number; i++){
        measures = getMeasureN(i);
        cout << measures << ' ';
        answer += measures > limit ? power : measures;      
    }
    
    return answer;
}