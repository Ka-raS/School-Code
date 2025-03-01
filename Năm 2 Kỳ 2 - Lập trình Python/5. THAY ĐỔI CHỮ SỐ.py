import typing

def get_inputs() -> typing.List[str]:
    input_strings: typing.List[str] = []
    while len(input_strings) < 4:
        input_strings.extend(input().split())
    return input_strings

def replace(number: str, from_digit: str, to_digit: str) -> str:
    result: str = ''
    for digit in number:
        if digit == from_digit:
            digit = to_digit
        result += digit
    return result

def min_sum(digit1: str, digit2: str, number1: str, number2: str) -> int:
    value1: int = int(replace(number1, digit2, digit1))
    value2: int = int(replace(number2, digit2, digit1))
    return value1 + value2

def max_sum(digit1: str, digit2: str, number1: str, number2: str) -> int:
    value1: int = int(replace(number1, digit1, digit2))
    value2: int = int(replace(number2, digit1, digit2))
    return value1 + value2


def run_test() -> None:
    digit1, digit2, number1, number2 = get_inputs()
    min: str = min_sum(digit1, digit2, number1, number2)
    max: str = max_sum(digit1, digit2, number1, number2)
    print(min, max)    

def main() -> None:
    testcases: int = int(input())
    for _ in range(testcases):
        run_test()

if __name__ == '__main__':
    main()