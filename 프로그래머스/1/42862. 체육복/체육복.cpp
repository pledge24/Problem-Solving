#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v1(n+1, 1);
      
    // 여분을 가진 학생은 1 증가.
    for(int student : reserve){
        v1[student]++;
    }
    
    // 잃어버린 학생은 1 감소
    for(int student : lost){
        v1[student]--;
    }
    
    sort(lost.begin(), lost.end());
    
    int left_lost = lost.size();
    for(int student : lost){
        if(v1[student] > 0){
            left_lost--;
            continue;
        } 
        
        if(student-1 >= 1 && v1[student-1] == 2){
            v1[student-1] = 1;
            v1[student] = 1;   
            left_lost--;
            continue;
        }
        
        if(student+1 <= n && v1[student+1] == 2){
            v1[student+1] = 1;
            v1[student] = 1;     
            left_lost--;
            continue;
        }
    }
    
    answer = n - left_lost;
    
    return answer;
}