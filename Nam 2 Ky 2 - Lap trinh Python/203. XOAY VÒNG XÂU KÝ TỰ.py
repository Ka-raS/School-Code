from typing import List

def rotate(source: str, target: str) -> int:
    for rotation in range(len(source)):
        if source == target:
            return rotation
        source = source[1:] + source[0]
        
    return -1

def min_rotations(strings: List[str], length: int) -> int:
    result = float('inf')

    for i in range(length):
        current_rotations = 0

        for j in range(length):
            rotations = rotate(strings[j], strings[i])
            if rotations == -1:
                return -1
            current_rotations += rotations
        
        result = min(result, current_rotations)

    return result

def main() -> None:
    length = int(input())
    strings = [input() for _ in range(length)]
    print(min_rotations(strings, length))

if __name__ == '__main__':
    main()