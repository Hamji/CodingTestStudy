def solution(brown, yellow):
    answer = []
    total = brown + yellow
    for i in range(total, 2, -1):
        if total % i == 0:
            temp = total // i
            if yellow == (i - 2)* (temp - 2):
                return [i, temp]
    return answer
