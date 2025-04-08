def is_valid(number: str) -> bool:
    sum_digit = int(number[0])
    for i in range(1, len(number)):
        if abs(int(number[i]) - int(number[i - 1])) != 2:
            return False
        sum_digit += int(number[i])
    return sum_digit % 10 == 0

def run_test() -> None:
    number = input()
    if is_valid(number):
        print('YES')
    else:
        print('NO')

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()