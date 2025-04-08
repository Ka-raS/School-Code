class Student:
    def __init__(self, name: str, accepted: int, submitted: int) -> None:
        self.name = name
        self.accepted = accepted
        self.submitted = submitted
    
    def __str__(self) -> str:
        return f'{self.name} {self.accepted} {self.submitted}'

def main() -> None:
    student_count = int(input())
    students: list[Student] = []

    for _ in range(student_count):
        name = input()
        accepted, submitted = map(int, input().split())
        students.append(Student(name, accepted, submitted))
    
    students.sort(key=lambda student: (-student.accepted, student.submitted, student.name))

    for student in students:
        print(student)

if __name__ == '__main__':
    main()