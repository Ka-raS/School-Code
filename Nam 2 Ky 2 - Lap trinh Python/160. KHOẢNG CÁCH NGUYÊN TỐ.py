from typing import List

def find_primes() -> List[int]:
    is_prime = [True] * 7920
    is_prime[0] = is_prime[1] = False
    for i in range(2, 84):
        if is_prime[i]:
            for j in range(i ** 2, 7919, i):
                is_prime[j] = False
    return [prime for prime in range(7920) if is_prime[prime]]

def main() -> None:
    length, begin = map(int, input().split())
    print(begin, end=' ')
    for prime in find_primes()[:length]:
        begin += prime
        print(begin, end=' ')

if __name__ == '__main__':
    main()