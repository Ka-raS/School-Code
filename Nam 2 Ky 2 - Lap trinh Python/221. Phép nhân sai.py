def wrong_muliply(num: int, sum: int) -> int:
    sum_digit = 0
    for digit in f'{num}':
        sum_digit += ord(digit) - 48
    return sum // sum_digit

def run_test(inputs: str) -> None:
    num, sum = map(int, inputs.split())
    print(wrong_muliply(num, sum))

def main() -> None:
    while True:
        inputs = input()
        if inputs == '-1':
            break
        run_test(inputs)

if __name__ == '__main__':
    main()