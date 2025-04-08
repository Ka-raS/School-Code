import sys

def product_digit(sequence: str) -> bool:
    product = 1
    for digit in sequence:
        if digit != '0':
            product *= int(digit)
    return product

def run_test(inputs: str) -> None:
    print(product_digit(inputs.strip()))

def main() -> None:
    sys.stdin.readline()
    for line in sys.stdin:
        run_test(line)

if __name__ == '__main__':
    main()