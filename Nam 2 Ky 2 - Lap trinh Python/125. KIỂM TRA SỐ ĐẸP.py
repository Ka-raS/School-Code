import sys

def is_pretty(sequence: str) -> bool:
    if sequence[0] == sequence[1]:
        return False
    target = (sequence[0], sequence[1])
    for i in range(2, len(sequence)):
        if sequence[i] != target[i & 1]:
            return False
    return True

def run_test(inputs: str) -> None:
    if is_pretty(inputs.strip()):
        print('YES')
    else:
        print('NO')

def main() -> None:
    sys.stdin.readline()
    for inputs in sys.stdin:
        run_test(inputs)

if __name__ == '__main__':
    main()