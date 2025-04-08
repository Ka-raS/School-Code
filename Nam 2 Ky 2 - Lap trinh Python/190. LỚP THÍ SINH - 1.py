from typing import Iterable

class Student:
    def __init__(self, name: str, birthdate: str, grades: Iterable[int]) -> None:
        self.name = name
        self.birthdate = birthdate
        self.total_grade = sum(grades)

    def __str__(self) -> str:
        return f'{self.name} {self.birthdate} {self.total_grade:.1f}'

def main() -> None:
    name = input()
    birthdate = input()
    grades = [float(input()) for _ in range(3)]

    student = Student(name, birthdate, grades)
    print(student)

if __name__ == '__main__':
    main()