def run_tests() -> None:
    number: str = input()
    
    if number[0] == number[-1]:
        print('YES')
    else:
        print('NO')

def main() -> None:
    tests: int = int(input())
    for test in range(tests):
        run_tests()

if __name__ == '__main__':
    main()