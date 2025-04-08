def is_lucky(sequence: str) -> bool:
    for digit in sequence:
        if digit != '6' and digit != '8':
            return False
    return True

def is_pretty(sequence: str) -> bool:
    return sequence.find('888') == -1

def main() -> None:
    sequence = input()
    if is_lucky(sequence) and is_pretty(sequence):
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    main()