mport heapq
def solution(operations):
    answer = [0, 0]
    reverse_sign = lambda x: x * -1
    li = []

    for i in operations:
        order = i.split() 
        if i[0] == 'I':
            li.append(int(order[1]))
        elif i[0] == 'D':
            if len(li) == 0:
                continue
            if order[1] == '1':
                li.remove(max(li))
            elif order[1] == '-1':
                li.remove(min(li))
                
    if li:
        answer = []
        answer.append(max(li))
        answer.append(min(li))
    
    print(answer)
    return answer
