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

def is_valid_or_whatever_idk(sequence: str, is_prime: typing.List[bool]) -> bool:
    sum_digit = 0
    for i, digit in enumerate(sequence):
        value = ord(digit) - 48
        if i & 1 != value & 1:
            return False
        sum_digit += value
    return is_prime[sum_digit]

def run_test(inputs: str, is_prime: typing.List[bool]) -> None:
    if is_valid_or_whatever_idk(inputs.strip(), is_prime):
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