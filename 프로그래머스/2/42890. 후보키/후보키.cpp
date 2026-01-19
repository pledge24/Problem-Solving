#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 최소성을 만족하는지 확인하는 함수
bool is_minimal(int subset, const vector<int>& candidate_keys) {
    for (int key : candidate_keys) {
        // 이미 저장된 후보키(key)가 현재 subset에 포함되어 있다면 최소성 위배
        if ((key & subset) == key) return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int row_size = relation.size();
    int col_size = relation[0].size();
    vector<int> candidate_keys;

    // 1. 모든 컬럼 조합을 비트마스크로 탐색 (1부터 2^col_size - 1까지)
    for (int i = 1; i < (1 << col_size); ++i) {
        
        // 2. 최소성 검사
        if (!is_minimal(i, candidate_keys)) continue;

        // 3. 유일성 검사
        set<string> s;
        for (int r = 0; r < row_size; ++r) {
            string row_str = "";
            for (int c = 0; c < col_size; ++c) {
                // i번째 비트마스크에 c번째 컬럼이 포함되어 있는지 확인
                if (i & (1 << c)) {
                    row_str += relation[r][c] + "/"; // 구분자 추가로 값 섞임 방지
                }
            }
            s.insert(row_str);
        }

        // 중복 없이 모든 튜플이 식별되면 유일성 만족
        if (s.size() == row_size) {
            candidate_keys.push_back(i);
        }
    }

    return candidate_keys.size();
}