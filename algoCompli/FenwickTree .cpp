#include <iostream>
#include <vector>

using namespace std;

class FenwickTree
{
public:
    FenwickTree(int n) : n(n)
    {
        // assign은 resize와 다르게 메모리를 전부 밀고 크기 조정
        // resize는 기존 원소는 유지.
        tree.assign(n+1, 0);
    }

    FenwickTree(const vector<int>& arr) : n(arr.size()) {
        tree.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            Update(i, arr[i]);
        }
    }

    void Update(int idx, int delta)
    {
        idx++;  // 0-indexed -> 1-indexed로 변환
        while(idx <= n)
        {
            tree[idx] += delta;
            idx += idx & (-idx);    // 최하위 1을 더하면서 이동.
        }
    }

    // [0, idx]의 누적합을 반환
    int Query(int idx)
    {
        idx++;  // 0-indexed -> 1-indexed로 변환
        int sum = 0;
        while(idx > 0)
        {
            sum += tree[idx];
            idx -= idx & (-idx);    // 최하위 1을 제거하며 이동.
        }

        return sum;
    }

    // [left, right] 구간합 반환(0-indexed)
    int RangeQuery(int left, int right)
    {
        // left가 0이 아닌 경우, [0, right] - [0, left - 1]
        if(left > 0)
            return Query(right) - Query(left - 1);

        return Query(right);
    }

private:
    vector<int> tree; // 1-indexed
    int n;
};

int main(void)
{
vector<int> arr = {1, 3, 5, 7, 9, 11};
    FenwickTree ft(arr);
    
    // 구간 합 쿼리
    cout << "Sum [0, 3]: " << ft.RangeQuery(0, 3) << endl; // 1+3+5+7 = 16
    cout << "Sum [2, 5]: " << ft.RangeQuery(2, 5) << endl; // 5+7+9+11 = 32
    
    // 값 업데이트 (인덱스 2에 10 더하기)
    ft.Update(2, 10);
    cout << "After update(2, 10):" << endl;
    cout << "Sum [0, 3]: " << ft.RangeQuery(0, 3) << endl; // 1+3+15+7 = 26
    cout << "Sum [2, 5]: " << ft.RangeQuery(2, 5) << endl; // 15+7+9+11 = 42
    
    return 0;
}