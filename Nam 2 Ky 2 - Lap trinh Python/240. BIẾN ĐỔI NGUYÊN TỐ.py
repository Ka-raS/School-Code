from typing import List
import bisect

def find_primes(limit: int) -> List[int]:
    primes: List[int] = []
    is_primes = [True] * limit
    is_primes[0] = is_primes[1] = False
    end = int(limit ** 0.5) + 1
    
    for prime in range(2, end):
        if is_primes[prime]:
            primes.append(prime)

            for multiplier in range(prime ** 2, limit, prime):
                is_primes[multiplier] = False
    
    primes.extend(
        prime
        for prime in range(end, limit)
            if is_primes[prime]
    )

    return primes

def prime_distance(numbers: List[int]) -> int:
    PRIMES = find_primes(10_000)
    max_distance = 0

    for number in numbers:
        pos = bisect.bisect_left(PRIMES, number)
        distance = min(PRIMES[pos] - number, number - PRIMES[pos - 1])
        max_distance = max(max_distance, distance)

    return max_distance

def main() -> None:
    length = int(input())
    numbers = list(map(int, input().split()))
    print(prime_distance(numbers))

if __name__ == '__main__':
    main()