#include <bits/stdc++.h>

using namespace std;

int ParametricSearch(vector<int>& rocks, int n, int total_distance)
{
    int res = 0;
    int start = 1;
    int end = total_distance;
    
    // 바위 위치 정렬은 함수 호출 전이나 내부에서 반드시 수행되어야 합니다.
    // sort(rocks.begin(), rocks.end());

    while(start <= end)
    {
        int mid = (start + end) / 2;
        int removeN = 0;
        int lastRockPos = 0;

        for (int i = 0; i < rocks.size(); i++) {
            if (rocks[i] - lastRockPos < mid) {
                // 거리가 mid보다 작으면 바위 제거
                removeN++;
            } 
            else {
                // 거리가 mid 이상이면 바위 유지, 기준점 업데이트
                lastRockPos = rocks[i];
            }
        }

        // 마지막 바위와 도착지 사이의 거리 체크
        if (total_distance - lastRockPos < mid) {
            removeN++;
        }
        
        if(removeN <= n) // n개 이하로 지워서 mid 간격을 유지할 수 있다면
        {
            res = mid;      // 현재 mid는 가능한 답이므로 저장
            start = mid + 1; // 더 큰 최솟값이 있는지 확인하기 위해 오른쪽 탐색
        }
        else // n개보다 많이 지워야만 mid 간격이 나온다면 (mid가 너무 크다면)
        {
            end = mid - 1;  // 간격을 줄이기 위해 왼쪽 탐색
        }
    }
    
    return res;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    // Sort
    std::sort(rocks.begin(), rocks.end());
    
    // Process
    answer = ParametricSearch(rocks, n, distance);
    
    return answer;
}