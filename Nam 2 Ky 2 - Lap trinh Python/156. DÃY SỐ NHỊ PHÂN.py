from typing import List

def differences(binaries: List[str], length: int) -> int:
    count = 0
    for i in range(length - 1):
        count += binaries[i] != binaries[i + 1]
    return count

def main() -> None:
    length = int(input())
    binaries = input().split()
    print(differences(binaries, length))

if __name__ == '__main__':
    main()