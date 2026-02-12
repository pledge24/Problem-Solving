#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using int64 = long long;

vector<int64> v1;
vector<int64> tree;

void Build(int64 node, int64 start, int64 end)
{
    if(start == end)
    {
        tree[node] = v1[start];
        return;
    }

    int64 mid = (start + end) / 2;

    // 왼쪽 자식 노드로 이동
    Build(node*2, start, mid);        
    // 오른쪽 자식 노드로 이동
    Build(node*2 + 1, mid + 1, end);

    tree[node] = tree[node*2] + tree[node*2 + 1];
}

int64 Query(int64 node, int64 start, int64 end, int64 left, int64 right) 
{
    // 범위를 완전히 벗어난 경우
    if (left > end || right < start) 
        return 0; 

    // 범위에 완전히 포함된 경우
    if (start <= left && right <= end) 
        return tree[node]; 

    // 일부 범위만 포함된 경우
    int64 mid = (start + end) / 2;
    int64 leftSum = Query(node*2, start, mid, left, right);
    int64 rightSum = Query(node*2 + 1, mid + 1, end, left, right);

    return leftSum + rightSum;
}

void Update(int64 node, int64 start, int64 end, int64 index, int64 val) 
{
    // 범위를 벗어난 경우
    if (index < start || index > end) 
        return; 

    if (start == end) {
        tree[node] = val; // 리프 노드를 찾아 값 갱신
        v1[index] = val;

        return;
    }

    int64 mid = (start + end) / 2;
    Update(node*2, start, mid, index, val);
    Update(node*2 + 1, mid + 1, end, index, val);
    
    // 자식이 바뀌었으므로 부모 값도 갱신
    tree[node] = tree[node*2] + tree[node*2 + 1];
}

int main(void)
{
    fastio;

    int64 N, M, K; cin >> N >> M >> K;
    v1.resize(N+1, 0);
    for(int64 i = 1; i <= N; i++)
    {
        cin >> v1[i];
    }

    tree.resize(4*N);
    Build(1, 1, N);

    for(int64 i = 0; i < M + K; i++)
    {
        int64 a, b, c; cin >> a >> b >> c;

        if(a == 1)
            Update(1, 1, N, b, c);
        else if(a == 2)
            cout << Query(1, 1, N, b, c) << '\n';
    }

    return 0;
}