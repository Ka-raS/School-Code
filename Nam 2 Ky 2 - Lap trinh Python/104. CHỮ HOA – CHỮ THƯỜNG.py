def standardize(string: str) -> str:
    lower_count = sum(1 for letter in string if letter.islower())
    if lower_count >= len(string) - lower_count:
        return string.lower()
    return string.upper()

def main() -> None:
    string = input()
    print(standardize(string))

if __name__ == '__main__':
    main()