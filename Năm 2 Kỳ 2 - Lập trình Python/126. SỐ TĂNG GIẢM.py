import sys

def is_bimodal(sequence: str) -> bool:
    n = len(sequence)
    if n < 3 or sequence[0] > sequence[1]:
        return False
    
    i = 1
    while i < n and sequence[i - 1] < sequence[i]:
        i += 1
    while i < n and sequence[i - 1] > sequence[i]:
        i += 1
    return i == n

def run_test(inputs: str) -> None:
    if is_bimodal(inputs.strip()):
        print('YES')
    else:
        print('NO')

def main() -> None:
    sys.stdin.readline()
    for inputs in sys.stdin:
        run_test(inputs)

if __name__ == '__main__':
    main()