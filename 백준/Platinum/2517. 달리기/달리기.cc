#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

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
    fastio;
    int N; cin >> N;
    vector<int> orgins;
    for(int i = 0; i < N; i++)
    {
        int num; cin >> num;
        orgins.push_back(num);
    }

    // Sort(No Use Unique-Erase Pattern)
    vector<int> coords = orgins;
    std::sort(coords.begin(), coords.end());

    FenwickTree ft(N);
    for(int i = 0; i < N; i++)
    {
        int num = orgins[i];
        int idx = lower_bound(coords.begin(), coords.end(), num) - coords.begin();
        
        cout << i + 1 - ft.Query(idx) << '\n';

        ft.Update(idx, 1);
    }
    
    return 0;
}