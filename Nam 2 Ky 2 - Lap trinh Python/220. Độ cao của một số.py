def sum_digit(number: int) -> int:
    result = 0
    for digit in f'{number}':
        result += ord(digit) - 48
    return result

def count(limit: int, sum_digit_target: int) -> int:
    result = 0
    for number in range(limit):
        if sum_digit(number) == sum_digit_target:
            result += 1
    return result

def run_test(inputs: str) -> None:
    limit, sum_digit_target = map(int, inputs.split())
    print(count(limit, sum_digit_target))
 
def main() -> None:
    while True:
        inputs = input()
        if inputs == '-1':
            break
        run_test(inputs)

if __name__ == '__main__':
    main()