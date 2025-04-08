from typing import List

def lengths(array: List[int], length: int) -> List[int]:
    result = [None] * length
    indices: List[int] = []

    for i in range(length):
        while indices and array[indices[-1]] <= array[i]:
            indices.pop()
        
        if not indices:
            result[i] = i + 1
        else:
            result[i] = i - indices[-1]
        indices.append(i)
    
    return result

def run_test() -> None:
    length = int(input())
    array = list(map(int, input().split()))
    print(*lengths(array, length))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()