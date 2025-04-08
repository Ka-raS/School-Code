def is_increasing(sequence: str) -> bool:
    for i in range(1, len(sequence)):
        if sequence[i - 1] > sequence[i]:
            return False
    return True

def run_test() -> None:
    sequence = input()
    if is_increasing(sequence):
        print('YES')
    else:
        print('NO')

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()