from collections import Counter
from typing import List, Tuple

def split_count(sequence: str, length: int, min_count: int) -> List[Tuple[str, int]]:
    counter: Counter[str, int] = Counter()
    for i in range(0, len(sequence) - length + 1, length):
        counter[sequence[i:i+length]] += 1
    
    result: List[Tuple[str, int]] = []
    for sub_sequence, count in counter.items():
        if count >= min_count:
            result.append((sub_sequence, count))
    
    result.sort()
    return result

def main() -> None:
    sequence = input()
    min_count = int(input())
    counter = split_count(sequence, 2, min_count)
    if counter:
        for sub_sequence, count in counter:
            print(sub_sequence, count)
    else:
        print('NOT FOUND')

if __name__ == '__main__':
    main()