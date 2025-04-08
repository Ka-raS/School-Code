from typing import List

def find_primes(limit: int) -> List[int]:
    is_prime = [True] * limit
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(limit ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i ** 2, limit, i):
                is_prime[j] = False
    return [number for number in range(limit) if is_prime[number]]

PRIMES = find_primes(50)

def is_valid(num: int, limit: int) -> bool:
    for prime in PRIMES:
        if prime > limit:
            break
        if num % prime == 0:
            return False
    return True

def run_test(begin: int, end: int, limit: int) -> None:
    count = 0
    for i in range(begin, end + 1):
        count += is_valid(i, limit)
    print(count)

def main() -> None:
    primes = find_primes(50)
    while True:
        inputs = input()
        if inputs == '-1':
            break

        begin, end = map(int, inputs.split())
        limit = int(input())
        run_test(begin, end, limit)

if __name__ == '__main__':
    main()