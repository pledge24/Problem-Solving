#include <bits/stdc++.h>

using namespace std;

// 주어진 시간동안 초침이 시침/분침과 겹친 횟수는?
// 단, 둘 다 겹쳤을경우 한 번으로 친다.

int hhUnit = 1;
int mmUnit = 12;
int ssUnit = 720;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = -1;
    int totalSecond = 24*60*60;
    int cycle = 12*60*60;
    
    int startTime = h1*60*60 + m1*60 + s1;
    int leftTime = (h2 - h1)*60*60 + (m2 - m1)*60 + (s2 - s1);
    
    int hhAngle = startTime % cycle;
    int mmAngle = (startTime * mmUnit) % cycle;
    int ssAngle = (startTime * ssUnit) % cycle;
    
    int cnt = (ssAngle == hhAngle || ssAngle == mmAngle);
    int dHH = hhAngle > ssAngle ? hhAngle - ssAngle : hhAngle + cycle - ssAngle;
    int dMM = mmAngle > ssAngle ? mmAngle - ssAngle : mmAngle + cycle - ssAngle;
    
    // cout << hhAngle << " " << mmAngle << " " << ssAngle << '\n';

    for(int i = 0; i < leftTime; i++)
    {
        hhAngle = (hhAngle + hhUnit) % cycle;
        mmAngle = (mmAngle + mmUnit) % cycle;
        ssAngle = (ssAngle + ssUnit) % cycle;
        
        int nextdHH = hhAngle > ssAngle ? hhAngle - ssAngle : hhAngle + cycle - ssAngle;
        int nextdMM = mmAngle > ssAngle ? mmAngle - ssAngle : mmAngle + cycle - ssAngle;
        
        cnt += (dHH < nextdHH) + (dMM < nextdMM);
        if(ssAngle == hhAngle && mmAngle == hhAngle)
        {
            cnt--;
        }
        
        dHH = nextdHH;
        dMM = nextdMM;
    }
    
    answer = cnt;
    
    return answer;
}