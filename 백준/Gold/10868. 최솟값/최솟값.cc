#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using int64 = long long;

const int64 INF = numeric_limits<int64>::max();

class SegmentTree
{
public:
    SegmentTree(int N) : N(N)
    {
        tree.assign(4*N, INF);
    }

    void Update(int node, int start, int end, int idx, int64 val)
    {
        // 범위를 벗어나는 구간인 경우
        if(idx < start || end < idx)
            return;

        if(start == end)
        {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;
        Update(node*2, start, mid, idx, val);
        Update(node*2+1, mid+1, end, idx, val);

        tree[node] = min(tree[node*2], tree[node*2+1]);
    }

    int64 Query(int node, int start, int end, int left, int right)
    {
        // 범위를 완전히 벗어나는 경우
        if(start > right || end < left)
        {
            return INF;
        }

        // 범위 안으로 완전히 들어오는 경우
        if(left <= start && end <= right)
        {
            return tree[node];
        }

        int mid = (start + end) / 2;
        int64 leftMin = Query(node*2, start, mid, left, right);
        int64 rightMin = Query(node*2 + 1, mid+1, end, left, right);

        return min(leftMin, rightMin);
    }

    void Print()
    {
        for(int i = 0; i < tree.size(); i++)
        {
            printf("idx: %lld, elem: %lld \n", i, tree[i]);
        }
    }

private:
    vector<int64> tree;
    int N;
};

int main(void)
{
    fastio;

    int N, M; cin >> N >> M;
    SegmentTree ST(N);

    for(int i = 1; i <= N; i++)
    {
        int64 num; cin >> num;
        ST.Update(1, 1, N, i, num);    
    }

    for(int i = 0; i < M; i++)
    {
        int left, right; cin >> left >> right;
        cout << ST.Query(1, 1, N, left, right) << '\n';
    }

    return 0;
}