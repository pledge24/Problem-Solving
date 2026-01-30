#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using int64 = long long;

const pair<int64, int64> emptyPair = make_pair(numeric_limits<int64>::max(), 0);

class SegmentTree
{
public:
    SegmentTree(int N) : N(N) 
    {
        tree.assign(N, emptyPair);
    };

    void Update(int node, int start, int end, int idx, int val)
    {
        // 범위를 완전히 벗어나는 경우
        if(idx < start || end < idx)
            return;

        if(start == end)
        {
            tree[node] = make_pair(val, val);
            return;
        }

        int mid = (start + end) / 2;
        Update(node*2, start, mid, idx, val);
        Update(node*2+1, mid+1, end, idx, val);

        int64 minNum = min(tree[node*2].first, tree[node*2+1].first);
        int64 maxNum = max(tree[node*2].second, tree[node*2+1].second);
        tree[node] = make_pair(minNum, maxNum);
    }

    pair<int64, int64> Query(int node, int start, int end, int left, int right)
    {
        // 범위를 완전히 벗어나는 경우
        if(right < start || end < left)
            return emptyPair;

        // 범위안에 다들어가는 경우
        if(left <= start && end <= right)
            return tree[node];

        int mid = (start + end) / 2;
        pair<int64, int64> leftMinMax = Query(node*2, start, mid, left, right);
        pair<int64, int64> rightMinMax = Query(node*2+1, mid+1, end, left, right);

        int64 minNum = min(leftMinMax.first, rightMinMax.first);
        int64 maxNum = max(leftMinMax.second, rightMinMax.second);

        // printf("%d ~ %d (%d, %d)\n", start, end, minNum, maxNum);

        return make_pair(minNum, maxNum);
    }

    // void Print()
    // {
    //     int i = 0;
    //     for(pair<int64, int64> p : tree)
    //     {
    //         cout << i << " "<< p.first << " " << p.second << '\n';
    //         i++;
    //     }
    // }

private:
    vector<pair<int64, int64>> tree;
    int N;
};

int main(void)
{
    fastio;

    int N, M; cin >> N >> M;
    int treeSize = N*4;
    SegmentTree st(treeSize);

    for(int i = 1; i <= N; i++)
    {
        int num; cin >> num;
        st.Update(1, 1, N, i, num);
    }

    // st.Print();

    for(int i = 0; i < M; i++)
    {
        int left, right; cin >> left >> right;
        pair<int64, int64> p = st.Query(1, 1, N, left, right);
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}