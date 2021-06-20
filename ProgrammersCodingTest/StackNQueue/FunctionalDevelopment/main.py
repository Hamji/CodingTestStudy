def solution(progresses, speeds):
    answer = []
    left_day = []
    temp = 0;
    for i, j in zip(range(0, len(progresses)), speeds):
        progresses[i] = 100 - progresses[i];
        left_day.append(progresses[i] // j)        
        if (progresses[i] % j) != 0:
            left_day[i] += 1    
    
    for i in range(0, len(left_day)):
        if(left_day[i] > left_day[temp]):
            answer.append(i - temp)
            temp = i
        if(i == len(left_day) - 1):
            answer.append(i - temp + 1)
    
    print(answer)
    return answer
