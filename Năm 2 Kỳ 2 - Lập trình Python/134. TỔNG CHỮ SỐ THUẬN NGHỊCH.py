import sys

def is_palindromic_sum_digit(sequence: str) -> bool:
    sum_digit = f'{sum(ord(digit) - 48 for digit in sequence)}'
    return len(sum_digit) > 1 and sum_digit == sum_digit[::-1]

def run_test(inputs: str) -> None:
    if is_palindromic_sum_digit(inputs.strip()):
        print('YES')
    else:
        print('NO')

def main() -> None:
    sys.stdin.readline()
    for line in sys.stdin:
        run_test(line)

if __name__ == '__main__':
    main()