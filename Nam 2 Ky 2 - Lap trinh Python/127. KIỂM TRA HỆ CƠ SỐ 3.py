import sys

def is_ternary(sequence: str) -> bool:
    return all(digit in {'0', '1', '2'} for digit in sequence)

def run_test(inputs: str) -> None:
    if is_ternary(inputs.strip()):
        print('YES')
    else:
        print('NO')

def main() -> None:
    sys.stdin.readline()
    for inputs in sys.stdin:
        run_test(inputs)

if __name__ == '__main__':
    main()