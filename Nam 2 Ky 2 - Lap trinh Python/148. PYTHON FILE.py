def main() -> None:
    file_name = input()
    if file_name[-3:].lower() == '.py':
        print('yes')
    else:
        print('no')

if __name__ == '__main__':
    main()