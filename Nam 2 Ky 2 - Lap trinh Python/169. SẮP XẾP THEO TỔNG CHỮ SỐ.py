def sum_digit(num: str) -> int:
    sum_value = 0
    for digit in num:
        sum_value += ord(digit) - 48
    return sum_value

def run_test() -> None:
    length = int(input())
    array = [(sum_digit(num), int(num)) for num in input().split()]

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