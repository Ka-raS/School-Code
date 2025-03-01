import sys
import typing

def find_primes() -> typing.List[bool]:
    MAX = 10_000
    result = [True] * MAX
    result[0] = result[1] = False
    for i in range(2, 100):
        if result[i]:
            for j in range(i ** 2, MAX, i):
                result[j] = False
    return result

def is_digit_prime(sequence: str, is_prime: typing.List[bool]) -> bool:
    length = len(sequence)
    if not is_prime[length]:
        return False
    prime_count = sum(is_prime[int(digit)] for digit in sequence)
    return prime_count > length - prime_count

def run_test(inputs: str, is_prime: typing.List[bool]) -> None:
    if is_digit_prime(inputs.strip(), is_prime):
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