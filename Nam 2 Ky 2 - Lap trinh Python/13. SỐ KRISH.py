import typing

def find_factories() -> typing.List[int]:
    factories: typing.List[int] = [None] * 10
    factories[0] = 1
    for i in range(1, 10):
        factories[i] = factories[i - 1] * i
    return factories

def is_krish_number(number: int, factories: typing.List[int]) -> bool:
    sum_factories: int = 0
    current_number: int = number
    while current_number > 0:
        digit = current_number % 10
        sum_factories += factories[digit]
        current_number //= 10
    return sum_factories == number

def run_tests(factories: typing.List[int]) -> None:
    number: int = int(input())
    
    if is_krish_number(number, factories):
        print('Yes')
    else:
        print('No')

def main() -> None:
    factories: typing.List[int] = find_factories()

    tests: int = int(input())
    for test in range(tests):
        run_tests(factories)

if __name__ == '__main__':
    main()