from typing import List

def convert(decimal: int, to_base: int) -> List[int]:
    result: List[int] = []
    while decimal > 0:
        value = decimal % to_base
        result.append(value)
        decimal //= to_base
    return result

def run_test(inputs: str) -> None:
    decimal, to_base1, to_base2 = map(int, inputs.split())
    base1 = convert(decimal, to_base1)
    base2 = convert(decimal, to_base2)

    if base1 == base1[::-1] and base2 == base2[::-1]:
        print('YES')
    else:
        print('NO')
 
def main() -> None:
    while True:
        inputs = input()
        if inputs == '-1':
            break
        run_test(inputs)

if __name__ == '__main__':
    main()