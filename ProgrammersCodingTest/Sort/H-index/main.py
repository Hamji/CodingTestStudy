def solution(citations):
    answer = 0
    citations.sort()
    length = len(citations)
    #print(citations)
    for i in range(length):
        if citations[i] >= length - i:
            answer = length - i
            return answer
    return answer
