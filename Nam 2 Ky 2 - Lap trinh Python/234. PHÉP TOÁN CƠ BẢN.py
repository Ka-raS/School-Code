from typing import List

def all_values(number: str) -> List[int]:
    if number[0] != '?':
        ten_digits = number[0]
    else:
        ten_digits = '123456789'

    if number[1] != '?':
        one_digits = number[1]
    else:
        one_digits = '0123456789'

    return [
        int(ten + one)
        for ten in ten_digits
            for one in one_digits
    ]

def finish(equation: str) -> str:
    firsts = all_values(equation[:2])
    seconds = all_values(equation[5:7])
    results = set(all_values(equation[10:]))

    if equation[3] != '?':
        operators = equation[3]
    else:
        operators = '+-*/'
    
    for first in firsts:
        for second in seconds:
            for operator in operators:
                expression = f'{first} {operator} {second}'
                result = eval(expression)
                if result in results:
                    return f'{expression} = {result}'

    return 'WRONG PROBLEM!'

def run_test() -> None:
    unfinished_equation = input()
    print(finish(unfinished_equation))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()