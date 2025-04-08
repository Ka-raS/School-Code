import sys

def is_sum_digit_dividable_by_3(sequence: str) -> bool:
    sum_digit = sum(int(digit) for digit in sequence)
    return sum_digit % 3 == 0

def run_test(inputs: str) -> None:
    if is_sum_digit_dividable_by_3(inputs.strip()):
        print('YES')
    else:
        print('NO')

def main() -> None:
    sys.stdin.readline()
    for line in sys.stdin:
        run_test(line)

if __name__ == '__main__':
    main()