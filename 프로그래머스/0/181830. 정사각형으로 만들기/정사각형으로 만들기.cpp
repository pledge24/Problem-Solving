#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    
    int r = arr.size();
    int c = arr[0].size();
    
    if(r < c)
        for(int i = 0; i < c-r; i++)
            arr.push_back(vector<int>(c));
    else if(r > c)
        for(int i = 0; i < r; i++)
            arr[i].resize(r);
    
    answer = arr;
    
    return answer;
}