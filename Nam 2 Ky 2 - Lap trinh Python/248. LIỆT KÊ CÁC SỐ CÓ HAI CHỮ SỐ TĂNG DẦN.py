from typing import List

def split(sequence: str, length: int) -> List[str]:
    sub_sequences = set()
    for i in range(0, len(sequence) - length + 1, length):
        sub_sequences.add(sequence[i:i+length])
    return sorted(sub_sequences)

def main() -> None:
    sequence = input()
    print(*split(sequence, 2))

if __name__ == '__main__':
    main()