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

def run_test(inputs: str, is_prime: typing.List[bool]) -> None:
    number = int(inputs[-5:-1])
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