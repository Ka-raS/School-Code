from typing import (
    List,
    Tuple
)

def is_aligned(vector2: List[Tuple[int, int]]) -> str:
    x1, y1 = vector2[0]
    x2, y2 = vector2[1]
    x_AB = x1 - x2
    y_AB = y1 - y2

    for i in range(2, len(vector2)):
        x, y = vector2[i]
        x_AC = x1 - x
        y_AC = y1 - y

        if x_AB * y_AC != x_AC * y_AB:
            return f'Yes\n1 2 {i + 1}'
    return 'No'

def main() -> None:
    length = int(input())
    vector2 = [tuple(map(int, input().split())) for _ in range(length)]
    print(is_aligned(vector2))

if __name__ == '__main__':
    main()