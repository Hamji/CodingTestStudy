from queue import PriorityQueue
import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    while(True):
        first = heapq.heappop(scoville)
        # 첫빠따 검사
        if first >= K:
            return answer
        # 사이즈 검사
        if len(scoville) == 0:
            break;
        # 섞기 
        second = heapq.heappop(scoville)
        heapq.heappush(scoville, first + second * 2)
        answer += 1
    
    return -1
