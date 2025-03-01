import math

def is_prime(number: int) -> bool:
    if number <= 1: 
        return False
    if number == 2 or number == 3:
        return True
    if number % 2 == 0 or number % 3 == 0:
        return False
    
    for dividend in range(5, int(math.sqrt(number)), 6):
        if number % dividend == 0 or number % (dividend + 2) == 0:
            return False
    return True

def is_perfect_prime(number: int) -> bool:
    if not is_prime(number):
        return False
    
    digit_sum: int = 0
    reverse: str = ''
    
    while number > 0:
        digit: int = number % 10
        if not is_prime(digit):
            return False
        
        number //= 10
        digit_sum += digit
        reverse += str(digit)
    
    return is_prime(digit_sum) and is_prime(int(reverse))

def run_tests() -> None:
    number: int = int(input())
    
    if is_perfect_prime(number):
        print('Yes')
    else:
        print('No')

def main() -> None:
    tests: int = int(input())
    for test in range(tests):
        run_tests()

if __name__ == '__main__':
    main()