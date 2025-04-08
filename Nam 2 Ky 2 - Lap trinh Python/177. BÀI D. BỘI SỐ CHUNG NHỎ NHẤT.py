from typing import List

BOUND = 1_000_000
MODULO = 1_000_000_007

def sieve_of_eratosthenes() -> List[bool]:
    is_prime = [True] * (BOUND + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(BOUND ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i ** 2, BOUND + 1, i):
                is_prime[j] = False
    return is_prime

def power(base: int, exponent: int) -> int:
    result = 1
    while exponent > 0:
        if exponent % 2 != 0:
            result = result * base % MODULO
        base = base ** 2 % MODULO
        exponent //= 2
    return result

# count prime appearances in number! prime factorization 
def prime_factorization(number: int, prime: int) -> int:
    result = 0
    while number >= prime:
        number //= prime
        result += number
    return result 

def lcd_pairs(down: int, up: int, is_prime: List[bool]) -> int:
    result = 1
    middle = up // 2 + 1
    for prime in range(2, middle):
        if is_prime[prime]:
            temp = prime_factorization(up, prime) - prime_factorization(down - 1, prime)
            result = result * (2 * temp + 1) % MODULO

    prime_count = 0
    for prime in range(middle, up + 1):
        if is_prime[prime]:
            prime_count += 1
    
    result = result * power(3, prime_count) % MODULO
    return result

def run_test(is_prime: List[bool]) -> None:
    down, up = map(int, input().split())
    print(lcd_pairs(down, up, is_prime))

def main() -> None:
    is_prime = sieve_of_eratosthenes()
    tests = int(input())
    for test in range(tests):
        run_test(is_prime)

if __name__ == '__main__':
    main()