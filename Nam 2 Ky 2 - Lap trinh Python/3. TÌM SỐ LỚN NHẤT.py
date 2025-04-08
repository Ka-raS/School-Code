import typing
import re

def extract_numbers(string: str) -> typing.List[int]:
    return [int(number) for number in re.findall(r'\d+', string)]

def run_test() -> None:
    input_string: str = input()
    array: typing.List[int] = extract_numbers(input_string)
    print(max(array))

def main() -> None:
    testcases: int = int(input())
    for test in range(testcases):
        run_test()

if __name__ == '__main__':
    main()