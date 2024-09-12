#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> m;
    
    for(int elem : tangerine){
        m[elem]++;
    }
    
    vector<int> v1;
    for(auto it : m){
        v1.push_back(it.second);
    }
    
    sort(v1.begin(), v1.end(), greater<>());
    
    int cnt = 0;
    for(int elem : v1){
        answer++;
        cnt += elem;
        if(cnt >= k){
            break;
        }
    }
    
    
    
    return answer;
}