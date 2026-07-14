#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = std::count_if(array.begin(), array.end(), [height](int elem){
        return elem > height;
    });
    
    return answer;
}