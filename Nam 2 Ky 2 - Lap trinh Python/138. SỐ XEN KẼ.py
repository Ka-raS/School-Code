import sys

def is_interleaved(sequence: str) -> bool:
    length = len(sequence)
    if length % 2 == 0:
        return False
    for i in range(length, 2):
        if sequence[i] != '2':
            return False
    return True

def run_test(inputs: str) -> None:
    if is_interleaved(inputs.strip()):
        print('YES')
    else:
        print('NO')

def main() -> None:
    sys.stdin.readline()
    for line in sys.stdin:
        run_test(line)

if __name__ == '__main__':
    main()