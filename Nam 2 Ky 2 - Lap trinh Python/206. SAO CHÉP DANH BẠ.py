from typing import (
    List,
    TextIO
)

def to_date(date: str) -> str:
    return date[5:]

def is_date(string: str) -> str:
    return len(string) >= 4 and string[:4] == 'Ngay'

def find_contacts(infile: TextIO) -> List[str]:
    contacts = []

    current_date = to_date(infile.readline())
    while True:
        line = infile.readline().strip()
        if not line:
            break

        if is_date(line):
            current_date = to_date(line)
            continue

        name = line
        phone_number = infile.readline().strip()
        contacts.append(f'{name}: {phone_number} {current_date}')
        
    return contacts

def main() -> None:
    with open('SOTAY.txt', 'r') as infile:
        contacts = find_contacts(infile)
    
    with open('DIENTHOAI.txt', 'w') as outfile:
        for contact in contacts:
            outfile.write(contact)

if __name__ == '__main__':
    main()