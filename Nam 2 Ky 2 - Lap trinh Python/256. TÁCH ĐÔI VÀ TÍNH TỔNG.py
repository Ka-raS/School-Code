def split_sum(sequence: str) -> int:
    half = len(sequence) // 2
    sum = int(sequence[:half]) + int(sequence[half:])
    return f'{sum}'

def main() -> None:
    sequence = input()
    while len(sequence) > 1:
        sequence = split_sum(sequence)
        print(sequence)

if __name__ == '__main__':
    main()