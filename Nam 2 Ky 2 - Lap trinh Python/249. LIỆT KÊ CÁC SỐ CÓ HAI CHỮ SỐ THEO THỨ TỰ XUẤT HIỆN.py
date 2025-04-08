from typing import KeysView

def split(sequence: str, length: int) -> KeysView[str]:
    sub_sequences: dict[str, None] = {}
    for i in range(0, len(sequence) - length + 1, length):
        sub_sequences[sequence[i:i+length]] = None
    return sub_sequences.keys()

def main() -> None:
    sequence = input()
    print(*split(sequence, 2))

if __name__ == '__main__':
    main()