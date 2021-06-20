#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> hash;
    unordered_map<string, int>::iterator i;
    
    for(int i =0; i < clothes.size(); i++)
        hash[clothes[i][1]]++;
    
    for(i = hash.begin(); i != hash.end(); i++)
        answer *= (i->second) + 1;
    answer--;
    //cout << answer << endl;
    return answer;
}
