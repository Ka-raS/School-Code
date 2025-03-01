import sys
import typing

def find_primes() -> typing.List[bool]:
    is_prime = [True] * 500
    is_prime[0] = is_prime[1] = False
    for i in range(2, 23):
        if is_prime[i]:
            for j in range(i ** 2, 500, i):
                is_prime[j] = False
    return is_prime

def is_prime_dominant(sequence: str, is_prime: typing.List[bool]) -> bool:
    length = len(sequence)
    prime_digit_count = sum(is_prime[ord(digit) - 48] for digit in sequence)
    return is_prime[length] and prime_digit_count * 2 > length

def run_test(inputs: str, is_prime: typing.List[bool]) -> None:
    if is_prime_dominant(inputs[:-1], is_prime):
        print('YES')
    else:
        print('NO')

def main() -> None:
    is_prime = find_primes()
    sys.stdin.readline()
    for inputs in sys.stdin:
        run_test(inputs, is_prime)

if __name__ == '__main__':
    main()