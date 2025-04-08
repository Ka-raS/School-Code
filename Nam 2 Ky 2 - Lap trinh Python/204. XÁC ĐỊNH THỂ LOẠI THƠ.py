from typing import List, Iterable

def find_forms(lines: Iterable[str]) -> List[int]:
    word_counts = [
        len(line.split())
        for line in lines
    ]
    
    i = 0
    n = len(word_counts)
    forms: List[int] = []

    while i < n:
        if word_counts[i] == 6:
            forms.append(1)
            while i < n and word_counts[i] == 6:
                i += 2
        else:
            forms.append(2)
            i += 4
            
    return forms

def main() -> None:
    line_count = int(input())
    lines = [input() for _ in range(line_count)]

    forms = find_forms(lines)
    print(len(forms))
    for form in forms:
        print(form)

if __name__ == '__main__':
    main()