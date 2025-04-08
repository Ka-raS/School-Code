def sum_digit(sequence: str) -> int:
    sum = 0
    for digit in sequence:
        sum += ord(digit) - 48
    return sum

def convert_steps(sequence: str) -> int:
    step = 0
    while len(sequence) > 1:
        sequence = f'{sum_digit(sequence)}'
        step += 1
    return step

def main() -> None:
    sequence = input()
    print(convert_steps(sequence))

if __name__ == '__main__':
    main()