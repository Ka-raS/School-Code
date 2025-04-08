from typing import List

def grade_average(grades: List[float]) -> float:
    result = 2 * (grades[0] + grades[1])
    for i in range(2, 10):
        result += grades[i]
    return result / 10 / 1.2

def ranking(grade: float) -> str:
    if grade >= 9:
        return 'XUAT SAC'
    if grade >= 8:
        return 'GIOI'
    if grade >= 7:
        return 'KHA'
    if grade >= 5:
        return 'TB'
    return 'YEU'

class Student:
    def __init__(self, id: str, name: str, grades: List[float]) -> None:
        self.id = id
        self.name = name
        self.grade = grade_average(grades)

    def __str__(self) -> str:
        return f'{self.id} {self.name} {self.grade:.1f} {ranking(self.grade)}'

def main() -> None:
    students: list[Student] = []
    student_count = int(input())

    for index in range(1, student_count + 1):
        id = f'HS{index:02}'
        name = input()
        grades = list(map(float, input().split()))
        students.append(Student(id, name, grades))

    students.sort(key=lambda student: (-student.grade, student.id))
    for student in students:
        print(student)

if __name__ == '__main__':
    main()