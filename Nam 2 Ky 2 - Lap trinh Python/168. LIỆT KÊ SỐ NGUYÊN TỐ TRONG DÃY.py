import math
import collections
from typing import (
    Iterable,
    List,
    OrderedDict
)

def find_primes(bound: int) -> List[bool]:
    is_prime = [True] * bound
    is_prime[0] = is_prime[1] = False
    for i in range(2, math.isqrt(bound)):
        if is_prime[i]:
            for j in range(i ** 2, bound, i):
                is_prime[j] = False
    return is_prime

def find_prime_counts(array: Iterable[int]) -> OrderedDict[int, int]:
    is_prime = find_primes(1_000_000)
    prime_count: OrderedDict[int, int] = collections.OrderedDict()

    for number in array:
        if is_prime[number]:
            prime_count[number] = prime_count.get(number, 0) + 1

    return prime_count

def main() -> None:
    length = int(input())
    array = list(map(int, input().split()))
    
    prime_counts = find_prime_counts(array)
    for prime, count in prime_counts.items():
        print(prime, count)

if __name__ == '__main__':
    main()