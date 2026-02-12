#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;

vector<int64> arr;
vector<int64> tree;

void Build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    // 왼쪽 자식 노드로 이동
    Build(node*2, start, mid);        
    // 오른쪽 자식 노드로 이동
    Build(node*2 + 1, mid + 1, end);

    tree[node] = tree[node*2] + tree[node*2 + 1];
}

int64 Query(int node, int start, int end, int left, int right) 
{
    // 범위를 완전히 벗어난 구간인 경우
    if (left > end || right < start) 
        return 0; 

    // 범위에 완전히 포함된 구간인 경우
    if (left <= start && end <= right) 
        return tree[node]; 

    // 일부 범위만 포함된 구간인 경우
    int mid = (start + end) / 2;
    int64 leftSum = Query(node*2, start, mid, left, right);
    int64 rightSum = Query(node*2 + 1, mid + 1, end, left, right);

    return leftSum + rightSum;
}

void Update(int node, int start, int end, int index, int64 val) 
{
    // 구간을 벗어난 index인 경우
    if (index < start || end < index) 
        return; 

    if (start == end) {
        tree[node] = val; // 리프 노드를 찾아 값 갱신
        arr[index] = val;

        return;
    }

    int mid = (start + end) / 2;
    Update(node*2, start, mid, index, val);
    Update(node*2 + 1, mid + 1, end, index, val);
    
    // 자식이 바뀌었으므로 부모 값도 갱신
    tree[node] = tree[node*2] + tree[node*2 + 1];
}

int main() {
    int n = 6;
    arr = {0, 1, 2, 3, 4, 5, 6}; // 인덱스 편의를 위해 0번은 비움
    tree.resize(4*n); // 안전하게 4N 크기 할당

    Build(1, 1, n);

    cout << "1~6 구간 합: " << Query(1, 1, n, 1, 6) << endl; // 21
    cout << "2~4 구간 합: " << Query(1, 1, n, 2, 4) << endl; // 9

    Update(1, 1, n, 3, 10); // 3번 인덱스를 10으로 변경
    cout << "값 변경 후 2~4 구간 합: " << Query(1, 1, n, 2, 4) << endl; // 2+10+4 = 16

    return 0;
}