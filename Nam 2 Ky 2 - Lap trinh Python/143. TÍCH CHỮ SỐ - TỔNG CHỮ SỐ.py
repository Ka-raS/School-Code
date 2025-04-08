import sys
import typing

def product_and_sum(sequence: str) -> typing.Tuple[int, int]:
    product_even = 1
    sum_odd = 0

    for i, digit in enumerate(sequence):
        value = ord(digit) - 48
        if i % 2 != 0:
            sum_odd += value
        elif value:
            product_even *= value

    return product_even, sum_odd

def run_test(inputs: str) -> None:
    print(*product_and_sum(inputs[:-1]))    

def main() -> None:
    sys.stdin.readline()
    for inputs in sys.stdin:
        run_test(inputs)

if __name__ == '__main__':
    main()