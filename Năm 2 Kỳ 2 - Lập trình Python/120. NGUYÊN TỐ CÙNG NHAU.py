import math

def print_coprimes(number: int, digit_count: int) -> bool:
    count = 0
    for value in range(10 ** (digit_count - 1), 10 ** digit_count):
        if math.gcd(number, value) == 1:
            print(value, end=' ')
            count += 1
            if count == 10:
                print()
                count = 0


def main() -> None:
    number, digit_count = map(int, input().split())
    print_coprimes(number, digit_count)

if __name__ == '__main__':
    main()