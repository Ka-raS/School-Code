from typing import List

def find_primes(limit: int) -> List[bool]:
    is_primes = [True] * limit
    is_primes[0] = is_primes[1] = False

    for i in range(2, int(limit ** 0.5) + 1):
        if is_primes[i]:
            for j in range(i ** 2, limit, i):
                is_primes[j] = False
    
    return is_primes

def sorted_prime(numbers: List[int]) -> None:
    primes: List[int] = []
    prime_pos: List[int] = []
    IS_PRIMES = find_primes(1001)

    for pos, number in enumerate(numbers):
        if IS_PRIMES[number]:
            primes.append(number)
            prime_pos.append(pos)

    primes.sort()
    for pos, prime in zip(prime_pos, primes):
        numbers[pos] = prime

def main() -> None:
    length = int(input())
    numbers = list(map(int, input().split()))
    sorted_prime(numbers)
    print(*numbers)

if __name__ == '__main__':
    main()