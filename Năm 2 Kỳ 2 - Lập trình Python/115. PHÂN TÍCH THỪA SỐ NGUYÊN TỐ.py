def print_exponential(base: int, exponent: int) -> None:
    print(f' * {base}^{exponent}', end='')

def print_prime_factorization(number: int) -> None:
    print(1, end='')

    dividend = 2
    while dividend ** 2 <= number:
        count = 0
        while number % dividend == 0:
            count += 1
            number //= dividend
        if count:
            print_exponential(dividend, count)
        dividend += 1

    if number != 1:
        print_exponential(number, 1)
    print()

def run_test() -> None:
    number = int(input())
    print_prime_factorization(number)

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()