import math

def is_prime(number: int) -> bool:
    if number <= 1: return False
    if number == 2 or number == 3: return True
    if number % 2 == 0 or number % 3 == 0: return False

    for dividend in range(5, int(math.sqrt(number)) + 1, 6):
        if number % dividend == 0 or number % (dividend + 2) == 0:
            return False
    return True

def is_valid(a: int, b: int) -> bool:
    divisor = math.gcd(a, b)
    sum_digit = sum(int(digit) for digit in str(divisor))
    return is_prime(sum_digit)

def run_test() -> None:
    a, b = map(int, input().split())
    if is_valid(a, b):
        print('YES')
    else:
        print('NO')

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()