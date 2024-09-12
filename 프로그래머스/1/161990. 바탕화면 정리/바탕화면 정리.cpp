#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    vector<int> pos_x_list;
    vector<int> pos_y_list;
    
    for(int i = 0; i < wallpaper.size(); i++){
        for(int j = 0; j < wallpaper[0].size(); j++){
            if(wallpaper[i][j] == '#'){
                pos_x_list.push_back(i);
                pos_x_list.push_back(i+1);
                pos_y_list.push_back(j);
                pos_y_list.push_back(j+1);
            }
        }
    }
    int min_x = *min_element(pos_x_list.begin(), pos_x_list.end());
    int max_x = *max_element(pos_x_list.begin(), pos_x_list.end());
    int min_y = *min_element(pos_y_list.begin(), pos_y_list.end());
    int max_y = *max_element(pos_y_list.begin(), pos_y_list.end());
    
    answer = {min_x, min_y, max_x, max_y};
    return answer;
}