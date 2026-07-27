#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    auto get_slope = [](vector<int>& p1, vector<int>& p2) {
        return (double)(p2[1] - p1[1]) / (p2[0] - p1[0]);
    };
    
    if (get_slope(dots[0], dots[1]) == get_slope(dots[2], dots[3])) return 1;
    if (get_slope(dots[0], dots[2]) == get_slope(dots[1], dots[3])) return 1;
    if (get_slope(dots[0], dots[3]) == get_slope(dots[1], dots[2])) return 1;
    
    return 0; // 평행한 경우가 없으면 0 반환
}