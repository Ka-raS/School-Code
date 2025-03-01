def is_lucky(number: str) -> bool:
    for digit in number:
        if digit != '4' and digit != '7':
            return False
    return True

def run_test() -> None:
    number = input()
    if is_lucky(number):
        print('YES')
    else:
        print('NO')

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()