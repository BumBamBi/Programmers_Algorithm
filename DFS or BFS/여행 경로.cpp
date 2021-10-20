#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 총 이동 경로 카운트를 하는 변수
int max_cnt = 0;

void DFS(string start, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& answer, vector<string>& temp, int cnt) {
    // 
    temp.push_back(start);
    
    // 
    if (max_cnt < cnt) {
        max_cnt = cnt;
        answer = temp;
    }
    
    for (int i = 0; i < tickets.size(); i++) {
        if (start == tickets[i][0] && !visit[i]) {
            visit[i] = true;
            DFS(tickets[i][1], tickets, visit, answer, temp, cnt + 1);
            visit[i] = false;
        }
    }
    temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {

    int cnt = 0;
    
    vector<string> answer, temp;
    vector<bool> visit(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    
    // ICN에서 시작하는 DFS실행
    DFS("ICN", tickets, visit, answer, temp, cnt);
    return answer;
}