from typing import Iterable, List

def union(words1: Iterable[str], words2: Iterable[str]) -> List[str]:
    return sorted(set(words1).union(words2))

def intersection(words1: Iterable[str], words2: Iterable[str]) -> List[str]:
    return sorted(set(words1).intersection(words2))

def main() -> None:
    words1 = input().lower().split()
    words2 = input().lower().split()
    print(*union(words1, words2))
    print(*intersection(words1, words2))

if __name__ == '__main__':
    main()