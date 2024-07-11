#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    answer.resize(arr1.size(), vector<int>(arr2[0].size()));
    
    for(int arr1_r = 0; arr1_r < arr1.size(); arr1_r++){
        for(int arr2_c = 0; arr2_c < arr2[0].size(); arr2_c++){
            for(int arr1_c = 0; arr1_c < arr1[0].size(); arr1_c++){
                answer[arr1_r][arr2_c] += arr1[arr1_r][arr1_c] * arr2[arr1_c][arr2_c];
            }
        }
              
    }
    
    return answer;
}