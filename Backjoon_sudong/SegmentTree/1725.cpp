#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> h;
vector<int> tree;

// 세그먼트 트리 초기화: 특정 구간에서 가장 낮은 막대의 '인덱스'를 저장
void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);

    // 더 낮은 높이를 가진 인덱스를 부모 노드에 저장
    if (h[tree[node * 2]] <= h[tree[node * 2 + 1]])
        tree[node] = tree[node * 2];
    else
        tree[node] = tree[node * 2 + 1];
}

// 구간 [left, right] 내에서 최소 높이의 인덱스를 쿼리
int query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return -1;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    int m1 = query(node * 2, start, mid, left, right);
    int m2 = query(node * 2 + 1, mid + 1, end, left, right);

    if (m1 == -1) return m2;
    if (m2 == -1) return m1;
    return (h[m1] <= h[m2]) ? m1 : m2;
}

// 분할 정복 함수
ll solve(int left, int right, int n) {
    // 1. 최소 높이 인덱스 찾기
    int min_idx = query(1, 0, n - 1, left, right);

    // 2. 현재 구간에서의 최대 넓이 계산
    ll area = (ll)(right - left + 1) * h[min_idx];

    // 3. 최소 막대 기준 왼쪽 구간 탐색
    if (left < min_idx) {
        area = max(area, solve(left, min_idx - 1, n));
    }
    // 4. 최소 막대 기준 오른쪽 구간 탐색
    if (right > min_idx) {
        area = max(area, solve(min_idx + 1, right, n));
    }

    return area;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    if (!(cin >> n)) return 0;
    h.resize(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    // 트리 크기는 4*N이면 충분합니다.
    tree.resize(4 * n);
    init(1, 0, n - 1);

    cout << solve(0, n - 1, n) << '\n';

    return 0;
}