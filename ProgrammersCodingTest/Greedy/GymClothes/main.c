#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int total[32];
    fill_n(total, n+1, 0);
    
    for (int i = 0; i < reserve.size(); i++)
        total[reserve[i]] = 1;
    for (int i = 0; i < lost.size(); i++)
        total[lost[i]]--;
    
    for (int i = 1; i <= n; i++){
        if (total[i] == -1){
            if (total[i-1] == 1){
                total[i-1] = 0;
                total[i] = 0;
            }else if (total[i+1] == 1){
                total[i+1] = 0;
                total[i] = 0;
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
        if (total[i] != -1)
            answer++;
    
    return answer;
}
