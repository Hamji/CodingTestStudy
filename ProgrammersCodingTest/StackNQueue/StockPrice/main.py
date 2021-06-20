def solution(prices):
    answer = []
    maintain = True
    
    for i in range(0, len(prices)):
        maintain = True;
        for j in range(i + 1, len(prices) - 1):
            if prices[i] > prices[j]:
                answer.append(j - i);
                maintain = False;
                break;
        if maintain == True:
            answer.append(len(prices) - 1 - i)

    return answer
