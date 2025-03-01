def is_balance(sequence: str) -> bool:
    

def run_test() -> None:
    sequence = input()
    if is_balance(sequence):
        print('YES')
    else:
        print('NO')

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()