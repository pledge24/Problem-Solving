#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {   
    int completeRows = n / w;
    int leftBoxes = n % w;
    
    int r = (num - 1) / w;
    int c = (r % 2) == 0 ? (num - 1) % w : (w - 1) - ((num - 1) % w);
    
    // cout << "(r, c) " << r << " " << c << '\n';
    
    // 완성된 행만 봤을때
    int answer = completeRows - (r/*현재 박스 아래에 깔려있는 박스 개수*/);
    
    // cout << "answer: " << answer << '\n';
    
    // 완성되지 않은 행 처리
    if(leftBoxes > 0){
        // 지정한 박스의 열 위에 남은 박스가 있는지 확인
        answer += (completeRows % 2) == 0 ? /*홀수*/(c+1) <= leftBoxes : /*짝수*/((w-1) - c+1) <= leftBoxes;
    }
    
    // cout << "answer: " << answer << '\n';
    // cout << "leftBoxes: " << leftBoxes << '\n';
    // cout << "completeRows: " << completeRows << '\n';
    
    return answer;
}