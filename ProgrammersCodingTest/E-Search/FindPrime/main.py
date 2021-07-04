import math
import itertools
def prime(n):
    k = math.sqrt(n)
    if n <= 1:
        return False
    
    for i in range(2, int(k) + 1):
        if n % i == 0:
            return False
        
    return True

def solution(numbers):
    list_ans = []
    list_num = list(numbers)
    for k in range(1, len(numbers) + 1):
        permu = list(map(''.join, itertools.permutations(list_num, k)))
        for i in list(set(permu)):
            if prime(int(i)):
                list_ans.append(int(i))
                
    list_ans = list(set(list_ans))
    return len(list_ans)
