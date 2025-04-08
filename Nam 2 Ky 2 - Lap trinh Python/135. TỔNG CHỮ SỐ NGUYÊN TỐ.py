import sys
import typing

def find_primes() -> typing.List[bool]:
    is_prime = [True] * 4501
    is_prime[0] = is_prime[1] = False
    for i in range(2, 68):
        if is_prime[i]:
            for j in range(i ** 2, 4501, i):
                is_prime[j] = False
    return is_prime

def is_prime_sum_digit(sequence: str, is_prime: typing.List[bool]) -> bool:
    sum_digit = sum(int(digit) for digit in sequence)
    return is_prime[sum_digit]

def run_test(inputs: str, is_prime: typing.List[bool]) -> None:
    if is_prime_sum_digit(inputs.strip(), is_prime):
        print('YES')
    else:
        print('NO')

def main() -> None:
    is_prime = find_primes()
    sys.stdin.readline()
    for line in sys.stdin:
        run_test(line, is_prime)

if __name__ == '__main__':
    main()