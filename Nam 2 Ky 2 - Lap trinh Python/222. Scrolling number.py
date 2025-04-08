def sum_digit(number: int) -> int:
    result = 0
    for digit in f'{number}':
        result += ord(digit) - 48
    return result

def divisor_9(num: int) -> int:
    while sum_digit(num) % 9 != 0:
        num += 1    
    return num

def run_test(inputs: str) -> None:
    number = int(inputs)
    print(divisor_9(number))

def main() -> None:
    while True:
        inputs = input()
        if inputs == '-1':
            break
        run_test(inputs)

if __name__ == '__main__':
    main()