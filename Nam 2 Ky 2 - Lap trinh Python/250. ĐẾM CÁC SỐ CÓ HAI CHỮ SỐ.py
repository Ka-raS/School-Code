from collections import Counter
from typing import ItemsView

def split_count(sequence: str, length: int) -> ItemsView[str, int]:
    counter: Counter[str, int] = Counter()
    for i in range(0, len(sequence) - length + 1, length):
        counter[sequence[i:i+length]] += 1
    return counter.items()

def main() -> None:
    sequence = input()
    for sub_sequence, count in split_count(sequence, 2):
        print(sub_sequence, count)

if __name__ == '__main__':
    main()