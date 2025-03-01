def run_test() -> None:
    number = input()
    if number[-2:] == '86':
        print('YES')
    else:
        print('NO')

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()