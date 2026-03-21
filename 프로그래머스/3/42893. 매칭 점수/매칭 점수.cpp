#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>

using namespace std;

struct PageData {
    int idx;
    double baseScore;
    double linkScore;
    vector<string> externalLinks;
};

// 모든 문자를 소문자로 변환하는 헬퍼 함수
string toLower(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

int solution(string word, vector<string> pages) {
    word = toLower(word);
    int n = pages.size();
    map<string, int> urlToIndex; // URL을 통해 인덱스를 바로 찾기 위함
    vector<PageData> pds(n);

    for (int i = 0; i < n; i++) {
        string page = pages[i];
        pds[i].idx = i;
        pds[i].linkScore = 0;

        // 1. 본인 URL 추출 (meta 태그 property="og:url" 찾기)
        // <meta property="og:url" content="https://careers.kakao.com/index"/>
        string url = "";
        size_t pos = page.find("<meta property=\"og:url\"");
        if (pos != string::npos) {
            size_t contentPos = page.find("content=\"", pos);
            if (contentPos != string::npos) {
                contentPos += 9; // "content=\"" 길이
                size_t endPos = page.find("\"", contentPos);
                url = page.substr(contentPos, endPos - contentPos);
            }
        }
        urlToIndex[url] = i;

        // 2. 기본 점수 계산 (단어 단위 매칭)
        double score = 0;
        string temp = "";
        for (char c : page) {
            if (isalpha(c)) {
                temp += tolower(c);
            } else {
                if (temp == word) score++;
                temp = "";
            }
        }
        if (temp == word) score++; // 마지막 단어 체크
        pds[i].baseScore = score;

        // 3. 외부 링크 추출
        size_t lPos = page.find("<a href=\"");
        while (lPos != string::npos) {
            lPos += 9; // "<a href=\"" 길이
            size_t rPos = page.find("\"", lPos);
            if (rPos != string::npos) {
                pds[i].externalLinks.push_back(page.substr(lPos, rPos - lPos));
                lPos = page.find("<a href=\"", rPos);
            } else break;
        }
    }

    // 4. 링크 점수 계산
    for (int i = 0; i < n; i++) {
        int outCount = pds[i].externalLinks.size();
        if (outCount == 0) continue;

        double giveScore = pds[i].baseScore / (double)outCount;
        for (const string& link : pds[i].externalLinks) {
            if (urlToIndex.count(link)) {
                int targetIdx = urlToIndex[link];
                pds[targetIdx].linkScore += giveScore;
            }
        }
    }

    // 5. 최적의 페이지 찾기
    double maxTotalScore = -1.0;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        double total = pds[i].baseScore + pds[i].linkScore;
        // 실수 비교 시 오차를 고려할 수도 있지만, 이 문제에서는 단순히 > 비교로 충분합니다.
        // 같은 점수일 때 작은 인덱스를 유지하기 위해 > 만 사용합니다.
        if (total > maxTotalScore + 1e-9) { 
            maxTotalScore = total;
            answer = i;
        }
    }

    return answer;
}