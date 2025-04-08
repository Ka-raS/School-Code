import typing

MAX_VALUE: int = 10 ** 6 + 1

def find_primes() -> typing.List[bool]:
    is_prime: typing.List[bool] = [True] * MAX_VALUE
    is_prime[0] = is_prime[1] = False

    for i in range(2, 1000):
        if is_prime[i]:
            for j in range(i * i, MAX_VALUE, i):
                is_prime[j] = False
    
    return is_prime

def find_emirp_numbers() -> typing.List[int]:
    is_prime: typing.List[bool] = find_primes()

    idx: int = 0
    emirp_numbers: typing.List[int] = [None] * 11184

    for number in range(MAX_VALUE):
        if is_prime[number]:
            reverse: int = int(str(number)[::-1])
            if number < reverse and is_prime[reverse]:
                emirp_numbers[idx] = number
                idx += 1
                emirp_numbers[idx] = reverse
                idx += 1

    return emirp_numbers

def run_tests(emirp_numbers: typing.List[int]) -> None:
    upper_bound: int = int(input())
    
    for i in range(1, 11184, 2):
        if emirp_numbers[i - 1] >= upper_bound:
            break

        if emirp_numbers[i] < upper_bound:
            print(emirp_numbers[i - 1], emirp_numbers[i], end=' ')
    print()

def main() -> None:
    emirp_numbers: typing.List[int] = find_emirp_numbers()

    tests: int = int(input())
    for test in range(tests):
        run_tests(emirp_numbers)

if __name__ == '__main__':
    main()