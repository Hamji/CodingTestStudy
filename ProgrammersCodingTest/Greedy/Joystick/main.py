def solution(name):
    answer = 0
    name_gap = [min(ord(i) - ord("A"), ord("Z") - ord(i)+1) for i in name]
    i = 0
    
    a = [1,2,3]
    print(a[3] == 0)

    while True:
        answer += name_gap[i]
        name_gap[i] = 0
        if sum(name_gap) == 0:
            break
        left = 1
        right = 1
        while name_gap[i - left] == 0:
            left += 1
        while name_gap[(i + right)] == 0:
            right += 1
        if left < right :
            answer += left
            i -= left
        else :
            answer += right
            i += right
    
    return answer
