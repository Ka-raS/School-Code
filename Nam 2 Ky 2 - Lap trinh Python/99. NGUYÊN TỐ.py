import math

def is_prime(number: int) -> bool:
    if number <= 1: return False
    if number == 2 or number == 3: return True
    if number % 2 == 0 or number % 3 == 0: return False

    for dividend in range(5, int(math.sqrt(number)) + 1, 6):
        if number % dividend == 0 or number % (dividend + 2) == 0:
            return False
    return True

def count_coprimes(number: int) -> int:
    count = 0
    for value in range(1, number):
        if math.gcd(value, number) == 1:
            count += 1
    return count

def run_test() -> None:
    number = int(input())
    if is_prime(count_coprimes(number)):
        print('YES')
    else:
        print('NO')

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()