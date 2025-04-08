def product_digit(num: str) -> int:
    product_value = 1
    for digit in num:
        product_value *= ord(digit) - 48
    return product_value

def run_test() -> None:
    length = int(input())
    array = [(product_digit(num), int(num)) for num in input().split()]

    array.sort()
    for pair in array:
        print(pair[1], end=' ')
    print()

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()