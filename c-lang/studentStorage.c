#include<stdio.h>

typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

void storeStudentData(Student* student) {
    FILE *file = fopen("files/student_data.txt", "a");
    if (file != NULL) {
        fprintf(file, "Name: %s, Age: %d, Grade: %.2f\n", student->name, student->age, student->grade);
        fclose(file);
        printf("Student data stored successfully.\n");
    } else {
        printf("Error opening file for writing.\n");
    }
}

int main() {
    Student student1;
    printf("Enter student's name: ");
    scanf("%49s", student1.name);
    printf("Enter student's age: ");
    scanf("%d", &student1.age);
    printf("Enter student's grade: ");
    scanf("%f", &student1.grade);   
    
    storeStudentData(&student1);

    return 0;
}