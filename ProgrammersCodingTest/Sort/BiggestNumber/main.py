def solution(numbers):
    answer = ''
    # numbers = list(map(str, numbers))
    # numbers.sort(key=lambda x: x*3, reverse=True)
    # return ''.join(numbers)
# 뭔차일까 야발
    string_ints = [str(int) for int in numbers]
    string_ints.sort(key= lambda x : x*3, reverse=True)
    answer = str(int(''.join(string_ints)))
    return answer
