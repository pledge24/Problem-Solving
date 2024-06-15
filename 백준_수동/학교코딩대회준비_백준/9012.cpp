//문제 9012.괄호 (자료구조)
//
// -설명
// 
// 괄호로만 구성되어 있는 문자열을 PS(Parenthesis String)라 부르며, 
// 모든 괄호가 짝을 이루는 문자열을 VPS(Valid PS)라고 부른다.
// 입력으로 주어진 PS가 VPS인지 판단하여 YES 또는 NO를 출력해야한다.
//
// Tip) 왼쪽부터 순차적으로 문자를 탐색할 때, VPS는 항상 왼쪽 괄호 개수가 많거나 같다.

#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// 문자열이 VPS인지 판단한다.
/// </summary>
/// <param name="str"> 판단할 문자열 </param>
/// <returns> VPS 판단 결과</returns>
bool isVPS(string str) {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') cnt++;
		else cnt--;

		if (cnt < 0) return false;
	}

	return (cnt == 0);
}

int main() {

	int T;			// Test 개수
	string str, ans;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> str;
		ans = isVPS(str) ? "YES" : "NO";
		cout << ans << endl;
	}
	return 0;
}