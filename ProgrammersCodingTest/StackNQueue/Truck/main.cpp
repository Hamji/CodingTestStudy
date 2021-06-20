#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

// 입력 들어옴
// 지금 브릿지에 넣을 수 있나?
// 못넣으면 0 넣기
// 넣을 수 있으면 숫자 넣고 인덱스 이동
// 한칸씩 밀기 값 넣고 마지막놈 pop

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int limit = weight;
    int out = 0;
    deque<int> deq(bridge_length);
    deque<int> truck;
    for (int i = 0; i < truck_weights.size(); i++)
        truck.push_back(truck_weights[i]);
    
    while(1){
        // 차를 먼저 뺀다.
        limit += deq.back();
        deq.pop_back();
        // 차를 넣는다. 
        if (truck.size() != 0 && truck.front() <= limit)
        {
            deq.push_front(truck.front());
            limit -= truck.front();
            truck.pop_front();
        }else{
            // 만약 버티는 무게가 적다면 0을 집어넣자
            deq.push_front(0);
        }
        if (truck.size() == 0 && limit == weight)
            break;
        answer++;
    }
    return answer + 1;
}
