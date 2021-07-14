def solution(people, limit):
    answer = 0
    people.sort()
    
    front, rear = 0, len(people) - 1
    while front <= rear:
        answer += 1
        if people[front] + people[rear] <= limit :
            front += 1
        rear -= 1
    
    # 처음엔 그냥 작은거부터 싩으면 되지 않을까 싶었는데
    # 생각해보니 20 30 50 50 50 / 80 이면 작은 순서대로 담아버리면 
    # 4개가 나오는데 제일 작은거 하나 큰거 하나씩 담으면 
    # 3개나온다
    # while len(people) != 0:
    #     cur_tube = limit
    #     while len(people) != 0 and people[0] <= cur_tube:
    #         cur_tube -= people.pop(0)
    #     answer += 1
    
    return answer
