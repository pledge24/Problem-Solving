#include <bits/stdc++.h>

using namespace std;

const int MAX_TIME = 100'000'000;

int BinarySearch(int n, vector<int>& cores)
{
    int low = 0;            // low Time(마지막 작업이 시작되지 않은 영역)
    int high = MAX_TIME;    // high Time(마지막 작업이 시작된 영역)
    
    while(low <= high)
    {
        int mid = (low + high) / 2; // mid Time(걸린 시간 후보자)
        int processN = cores.size();
        for(int& processTime : cores)
        {
            processN += ((mid - 1) / processTime);
        }
        
        if(processN < n)    // 처리한 양이 부족(오른쪽 이동)
        {
            low = mid+1;
            
            // 마지막 작업을 수행하는 지 체크
            for(int coreIdx = 0; coreIdx < cores.size(); coreIdx++)
            {
                int processTime = cores[coreIdx];
                if(mid % processTime == 0)
                    processN++;

                if(processN == n)
                {
                    cout << "mid: " << mid << '\n';
                    return coreIdx+1;
                }
            }
        }
        else                // 처리한 양이 충분(왼쪽 이동)
        {
            high = mid;
        }
        
        
        
    }
    
    return -1;
}

int solution(int n, vector<int> cores) {
    int answer = 0;
    
    answer = BinarySearch(n, cores);
    
    return answer;
}