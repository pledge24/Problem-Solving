#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(vector<int>& q : queries)
    {
        int s = q[0];
        int e = q[1];
        for(int i = s; i <= e; i++)
        {
            arr[i]++;
        }
    }
    
    answer = arr;
    
    return answer;
}