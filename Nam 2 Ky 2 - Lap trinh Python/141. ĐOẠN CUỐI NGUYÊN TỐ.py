import sys
import typing

def find_primes() -> typing.List[bool]:
    is_prime = [True] * 10_000
    is_prime[0] = is_prime[1] = False
    for i in range(2, 100):
        if is_prime[i]:
            for j in range(i ** 2, 10_000, i):
                is_prime[j] = False
    return is_prime

def run_test(inputs: str, is_prime: typing.List[bool]) -> None:
    number = int(inputs[-5:])
    if is_prime[number]:
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