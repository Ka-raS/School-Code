def merge(source: str, target: str, index: int) -> str:
    return source[:index] + target + source[index:]

def main() -> None:
    source = input()
    target = input()
    index = int(input()) - 1
    print(merge(source, target, index))

if __name__ == '__main__':
    main()