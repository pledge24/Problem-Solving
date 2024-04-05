// 2023-10-17

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main2816() {
	fastio;
	int N;
	cin >> N;
	vector<string> ch(N);

	// input
	for (int i = 0; i < N; i++) {
		cin >> ch[i];
	}
	
	string ans;

	int pos1 = 0;
	while (ch[pos1] != "KBS1")
	{
		// 내리는 작동.
		ans.append("1");
		pos1++;
	}

	string temp;
	while (pos1 != 0)
	{
		// 올리면서 스왑하는 작동.
		ans.append("4");
		temp = ch[pos1];
		ch[pos1] = ch[pos1 - 1];
		ch[pos1 - 1] = temp;
		pos1--;
	}

	int pos2 = 0;
	while (ch[pos2] != "KBS2")
	{
		// 내리는 작동.
		ans.append("1");
		pos2++;
	}

	while (pos2 != 1)
	{
		// 올리면서 스왑하는 작동.
		ans.append("4");
		temp = ch[pos2];
		ch[pos2] = ch[pos2 - 1];
		ch[pos2 - 1] = temp;
		pos2--;
	}

	//for (int i = 0; i < N; i++) {
	//	cout << ch[i] << ' ';
	//}
	//cout << '\n';

	cout << ans << '\n';

	return 0;
}