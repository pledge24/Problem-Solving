#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            answer[i][j] = i == j;
        }
    }
    
    return answer;
}