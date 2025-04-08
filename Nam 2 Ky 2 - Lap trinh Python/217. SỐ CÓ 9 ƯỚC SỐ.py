from typing import List

def find_min_prime_divisors(limit: int) -> List[int]:
    min_primes = list(range(limit))

    for i in range(2, int(limit ** 0.5) + 1):
        if min_primes[i] == i:

            for j in range(i ** 2, limit, i):
                if min_primes[j] == j:
                    min_primes[j] = i
    
    return min_primes

def count_9_divisors(upperbound: int) -> int:
    count = 0
    square = int(upperbound ** 0.5) + 1 
    eighth = int(upperbound ** (1 / 8)) + 1
    min_prime_divisors = find_min_prime_divisors(square)

    for value in range(2, square):
        prime = min_prime_divisors[value]
        other_prime = min_prime_divisors[value // prime]

        is_prime_factor = (
            prime != other_prime and 
            other_prime != 1 and 
            prime * other_prime == value
        )
        is_prime = (
            value == prime and 
            value < eighth
        )
        if is_prime_factor or is_prime:
            count += 1

    return count

def main() -> None:
    upperbound = int(input())
    print(count_9_divisors(upperbound))

if __name__ == '__main__':
    main()