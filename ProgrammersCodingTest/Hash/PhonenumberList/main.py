def solution(phone_book):
    phone_book.sort()
    for num1, num2 in zip(phone_book, phone_book[1:]):
        if num2.startswith(num1):
            return False
    
    return True
