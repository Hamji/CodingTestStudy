def solution(number, k):
    answer = ''
    #질문하기 보니까 stack을 이용하더라
    stack = []
    
    #순차로 순회하면서 하나씩 넣어준다.
    for i in number:
        while len(stack) > 0 and stack[-1] < i and k > 0:
            k -= 1
            stack.pop()
        stack.append(i)
    
    #만약 충분히 제거 못했으면 걍 뒤엣놈 잘라버린다.
    if k != 0:
        stack = stack[0:-k]
    return ''.join(stack)

    # 망한코드 답도 아니고 속도도 느리다..
    # 최대값은 찾지만 너무 느리고 GREEDY에 맞지 않음
    # length = len(number)
    # number = list(number);
    # permu = list(map(''.join, itertools.permutations(number, length - k)))
    # permu = list(map(int, permu))
