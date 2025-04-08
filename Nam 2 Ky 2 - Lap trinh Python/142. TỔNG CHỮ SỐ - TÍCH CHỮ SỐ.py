import sys
import typing

def sum_and_product(sequence: str) -> typing.Tuple[int, int]:
    sum_even = 0
    product_odd = 1
    is_multiplied = False

    for i, digit in enumerate(sequence):
        value = ord(digit) - 48
        if i % 2 == 0:
            sum_even += value
        elif value:
            product_odd *= value
            is_multiplied = True

    return sum_even, is_multiplied * product_odd

def run_test(inputs: str) -> None:
    print(*sum_and_product(inputs[:-1]))    

def main() -> None:
    sys.stdin.readline()
    for inputs in sys.stdin:
        run_test(inputs)

if __name__ == '__main__':
    main()