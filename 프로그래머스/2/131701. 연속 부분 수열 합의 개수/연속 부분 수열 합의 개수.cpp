#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    map<int, int> m;
    
    int sum;
    int elements_size = elements.size();
    for(int i = 0; i < elements_size; i++){
        sum = 0;
        for(int n = 0; n < elements_size -1; n++){
            sum += elements[(i + n) % elements_size];
            m[sum]++;
        }
    }
    
    sum = 0;
    for(int elem : elements){
        sum += elem;
    }
    m[sum]++;
    
    answer = m.size();
    
    return answer;
}