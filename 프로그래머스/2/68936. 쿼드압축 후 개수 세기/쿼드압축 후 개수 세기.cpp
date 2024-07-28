#include <string>
#include <vector>
#include <iostream>
#include <utility>

#define AREA 4

using namespace std;
vector<vector<int>> arr_global;

pair<int, int> dnc(int min_x, int min_y, int arr_size){
    
    pair<int, int> p;
    pair<int, int> ans_p = make_pair(0, 0);
    
    if(arr_size == 1){
        ans_p = arr_global[min_x][min_y] ? make_pair(0, 1) : make_pair(1, 0);
        return ans_p;
    }
    
    int area_x[AREA] = {0, 0, arr_size/2, arr_size/2};
    int area_y[AREA] = {0, arr_size/2, 0, arr_size/2};
    
    vector<int> v_zero, v_one;
    for(int i = 0; i < AREA; i++){
        int min_nx = min_x + area_x[i];
        int min_ny = min_y + area_y[i];
        p = dnc(min_nx, min_ny, arr_size/2);
        
        v_zero.push_back(p.first);
        v_one.push_back(p.second);
    }
    
    bool ismerged_zero = true;
    for(int elem : v_zero){
        if(elem != 1){
            ismerged_zero = false;
        }
        ans_p.first += elem;
    }
   
    bool ismerged_one = true;
    for(int elem : v_one){
        if(elem != 1){
            ismerged_one = false;
        }
        ans_p.second += elem;
    }
    if(ismerged_zero && ans_p.second == 0) ans_p.first = 1;
    if(ismerged_one && ans_p.first == 0) ans_p.second = 1;
 
    return ans_p;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int arr_size = arr.size();
    arr_global.resize(arr_size, vector<int>(arr_size));
    swap(arr_global, arr);
    
    // for(int i = 0; i < arr_size; i++){
    //     for(int j = 0; j < arr_size; j++){
    //         cout << arr_global[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int min_x = 0, min_y = 0;    
    pair<int, int> ans = dnc(min_x, min_y, arr_size);
    
    answer = {ans.first, ans.second};
    

    
    
    return answer;
}