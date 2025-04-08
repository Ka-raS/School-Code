from typing import List

def convert(mat: List[List[int]], length: int) -> List[int]:
    if length == 2:
        return [mat[0][1] // 2] * 2
    
    # B[0][1] = A[0] + A[1]
    # B[0][2] = A[0] + A[2]
    # B[1][2] = A[1] + A[2]
    # 2 * A[0] = B[0][1] + B[0][2] - B[1][2]

    zero = (mat[0][1] + mat[0][2] - mat[1][2]) // 2
    result = [
        num - zero
        for num in mat[0]
    ]
    result[0] = zero
    return result

def main() -> None:
    length = int(input())
    matrix = [
        list(map(int, input().split()))
        for row in range(length)
    ]
    print(*convert(matrix, length))

if __name__ == '__main__':
    main()