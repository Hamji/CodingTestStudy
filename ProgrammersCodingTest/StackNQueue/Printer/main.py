from collections import deque

def solution(priorities, location):
    answer = 0
    con = True
    check = True
    arr1 = []
    for i, j in zip(priorities, range(0, len(priorities))):
        arr1.append((i, j))
    
    while(con):
        con = False
        check = True
        hand = arr1.pop(0)
        for i in range(0, len(arr1)):
            if hand[0] < arr1[i][0]:
                con = True
                arr1.append(hand)
                check = False
                break;
        if check == True:
            answer += 1
          
        if con == False and location == hand[1]:
            return answer
        elif con == False and location != hand[1]:
            con = True
        
    return answer
