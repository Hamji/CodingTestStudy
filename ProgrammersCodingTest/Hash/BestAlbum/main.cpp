#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<string,int>& a, const pair<string,int>& b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> total;
    unordered_map<string, int> most;
    unordered_map<string, int> second;
    map<string, int>::iterator i;

    for(int i = 0; i < genres.size(); i++){
        string word = genres[i];
        total[word] += plays[i];
        if(most.find(word) == most.end())
            most[word] = i;
        else if(plays[most[word]] < plays[i]) {
            second[word] = most[word];
            most[word] = i;
        }else if(second.find(word) == second.end())
            second[word] = i;
        else if(plays[second[word]] < plays[i]) {
            second[word] = i;
        }
    }
 
    vector<pair<string,int>> vec( total.begin(), total.end() );
    sort(vec.begin(), vec.end(), cmp);
    
    for (auto num : vec)
    {
        string name = num.first;
        if(most.find(name) != most.end())
            answer.push_back(most[name]);
        if(second.find(name) != second.end())
            answer.push_back(second[name]);
    }
    
    return answer;
}
