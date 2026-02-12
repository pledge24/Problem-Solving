#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 타겟과 동일한 값이 여러 개면 가장 낮은 위치 반환.
int lowerBound(vector<int>& v, int target){
    int start = 0, end = v.size();

    while(start < end){
        int mid = (start + end) / 2;

        if(v[mid] < target){   // 오른쪽 범위로 이동
            start = mid + 1;
        }
        else{                  // 왼쪽 범위로 이동
            end = mid;
        }
    }

    return start; 
}

// 타겟과 동일한 값이 여러 개면 가장 높은 위치 반환.
int upperBound(vector<int>& v, int target){
    int start = 0, end = v.size();

    while(start < end){
        int mid = (start + end) / 2;

        if(v[mid] <= target){   // 오른쪽 범위로 이동
            start = mid + 1;
        }
        else{                   // 왼쪽 범위로 이동
            end = mid;
        }
    }

    return start; 
}

// 타겍을 찾으면 위치 상관없이 즉시 반환
int binarySearch(vector<int> &v, int target)
{
    int start = 0, end = v.size();

    while (start < end) // 탐색 범위(len)의 길이가 1이상인 경우
    {
        int mid = (start + end) / 2;

        if (v[mid] == target)
            return mid;
        else if (v[mid] < target)   // 오른쪽 범위로 이동
            start = mid + 1;
        else                        // 왼쪽 범위로 이동
            end = mid;
    }

    return -1;
}

int main()
{
    vector<int> v1 = {10, 11, 11, 11, 12, 13};
    int target = 11;

    auto lb = lower_bound(v1.begin(), v1.end(), target);
    auto ub = upper_bound(v1.begin(), v1.end(), target);

    if (lb != v1.end())
    {
        cout << "Lower bound idx is " << lb - v1.begin() << '\n';
        cout << "Upper bound idx is " << ub - v1.begin() << '\n';
    }
    else
    {
        cout << "not found" << '\n';
    }

    return 0;
}
