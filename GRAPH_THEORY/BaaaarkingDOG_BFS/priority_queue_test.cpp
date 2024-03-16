#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct test
{
    int x;
    int y;
    char* s;
};

struct cmp
{
    bool operator()(test a, test b) {
        return a.y > b.y;
    }
};

int main() {
	fastio;

    priority_queue<test, vector<test>, cmp> p1;

    p1.push({1, 3, "test1"});
    p1.push({10, 5, "test2"});
    p1.push({7, 1, "test3"});
    p1.push({2, 8, "test4"});

    while (!p1.empty()) {
        test ts = p1.top(); p1.pop();
        printf("x: %d, y: %d, s: %s\n", ts.x, ts.y, ts.s);
    }

}