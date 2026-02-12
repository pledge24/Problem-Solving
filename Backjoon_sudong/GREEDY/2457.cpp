#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define BEGIN_DATE 301
#define END_DATE 1201
#define MAX_DATE 1231


using namespace std;

struct flowerDate
{
    int openDate;
    int closeDate;
};

bool inRange(int beginDate, int endDate){
    return beginDate >= BEGIN_DATE || endDate <= END_DATE;
}

bool cmp(const flowerDate& p1, const flowerDate& p2){
    return p1.openDate < p2.openDate;
}

int main() {
	fastio;
    int N; cin >> N;
    vector<flowerDate> v1;

    // 3.1 ~ 11.30 피어 있어야 함(즉, 12.1에 져야함)
    int a1, a2, b1, b2;
    for(int i = 0; i < N; i++){
        cin >> a1 >> a2 >> b1 >> b2;

        if(!inRange(a1*100+a2, b1*100+b2)) continue;

        int openDate = max(a1*100+a2, BEGIN_DATE);
        int closeDate = min(b1*100+b2, END_DATE);

        v1.push_back({openDate, closeDate});
    }

    sort(v1.begin(), v1.end(), cmp);

    // for(flowerDate fd : v1){
    //     cout << "flowerData: " << fd.openDate << " ~ "<< fd.closeDate << '\n';
    // }
    
    int ans = 0;
    int curOpenDate = 301, curCloseDate = 301;
    for(flowerDate fd : v1){
        // 빈 공간이 생길 경우
        if(curOpenDate < fd.openDate){
            if(curCloseDate < fd.openDate){
                cout << 0 << '\n';
                return 0;
            }
            curOpenDate = curCloseDate;
            ans++;
        }     
        curCloseDate = max(curCloseDate, fd.closeDate);
        
       //cout << "iter: " << curOpenDate << " ~ "<< curCloseDate << '\n';
    }

    if(curOpenDate != curCloseDate) ans++;

    // 모든 꽃을 넣었지만 종료일까지 피울 수 있는 꽃이 없었던 경우
    if(curCloseDate != END_DATE) ans = 0;

    cout << ans << '\n';
}