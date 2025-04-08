from typing import (
    List,
    Tuple
)

def topic_questions(lines: List[str]) -> List[Tuple[str, int]]:
    result: List[Tuple[str, int]] = []
    
    end = len(lines)
    topic_position = 0

    while topic_position < end:
        try:
            break_position = lines.index('', topic_position)
        except ValueError:
            break_position = end

        question_count = break_position - topic_position - 1
        result.append((lines[topic_position], question_count))
        topic_position = break_position + 1
    
    return result

def main() -> None:
    line_count = int(input())
    lines = [
        input()
        for line in range(line_count)
    ]

    for topic, count in topic_questions(lines):
        print(f'{topic}: {count}')

if __name__ == '__main__':
    main()