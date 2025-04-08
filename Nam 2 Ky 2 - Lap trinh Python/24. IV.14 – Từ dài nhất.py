def main() -> None:
    strings = input().split()
    longest_string = max(strings, key=len)
    print(longest_string, len(longest_string))

if __name__ == '__main__':
    main()