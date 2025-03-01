def round(number: str) -> str:
    n = len(number)
    carry = False
    for i in range(n - 1, 0, -1):
        carry = int(number[i]) + carry >= 5
    value = f'{int(number[0]) + carry}'
    return value + '0' * (n - 1)

def run_test() -> None:
    number = input()
    print(round(number))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()