#include "stdio.h"
#include "../lib/cJSON.h"
#include "stdlib.h"
#include "string.h"

// Data struct

//  Course structure
struct Course{
    int courseId;
    char courseName[20];
    char teacher[20];
    char department[20];
    int credit;
};

typedef struct courseList{
    struct Course course;

    struct courseList* next;
    struct courseList* prev;
}courseNode;

struct Student {
    int listId;
    int studentId;
    char studentName[20];
    char department[20];
};

typedef struct studentList{
    struct Student student;

    struct studentList* next;
    struct studentList* prev;
}studentNode;


struct Selection {
    int selectionID;
    int studentID;
    int courseID;
    int courseScore;
};

typedef struct selectionList {
    struct Selection selection;

    struct selectionList* next;
    struct selectionList* prev;

}selectionNode;




courseNode courseListHead;  //  Create courselist
studentNode studentListHead;
selectionNode selectionListHead;

int getInt() {
//    Get user's input
//    Return int

    int number;
    scanf("%d", &number);
    return number;
}


void showCourse() {
//    Traversal course list
    courseNode *head;   // Create Node
    head = courseListHead.next; //  Copy listHead node to function node
    while (head != NULL){
        printf("\nCourse id: %d\t", head->course.courseId);
        printf("Course name:%s \t", head->course.courseName);
        printf("department:%s \t", head->course.department);
        printf("teacher:%s \t", head->course.teacher);
        printf("credit:%d\n", head->course.credit);
        head = head->next;
    }
}

void showStudent() {
//    Traversal course list
    studentNode *head;   // Create Node
    head = studentListHead.next; //  Copy listHead node to function node
    while (head != NULL){
        printf("\nList Id:%d\t", head->student.listId);
        printf("Student name: %s\t", head->student.studentName);
        printf("Student department:%s \t", head->student.department);
        printf("Student's ID:%d", head->student.studentId);
        head = head->next;
    }
}

void showSelection() {
//    Traversal course list
    selectionNode *head;   // Create Node
    head = selectionListHead.next; //  Copy listHead node to function node
    while (head != NULL){
        printf("\nSelection ID:%d\t", head->selection.selectionID);
        printf("Student's ID:%d", head->selection.studentID);
        printf("Course ID:%d", head->selection.courseID);
        printf("Course Score:%d", head->selection.courseScore);
        head = head->next;
    }
}

//  Main function:
void addCourse() {
    char courseName[20];
    char teacher[20];
    char department[20];
    int credit;
    printf("\nPlease input the course name: ");
    scanf("%s", courseName);
    printf("\nPlease input the department name: ");
    scanf("%s", department);
    printf("\nWho is going to teach this course: ");
    scanf("%s", teacher);
    printf("\nHow much credits: ");
    scanf("%d", &credit);



//    strcpy(CourseHead->course.courseName, courseName);

    courseNode *NewData = (courseNode *) malloc(sizeof(courseNode));


    strcpy(NewData->course.courseName, courseName);
    strcpy(NewData->course.teacher, teacher);
    strcpy(NewData->course.department, department);
    NewData->course.credit = credit;

    if (courseListHead.next == NULL){
        NewData->course.courseId = 1;
        courseListHead.next = NewData;
        courseListHead.prev = NewData;

        NewData->prev = &courseListHead;
        NewData->next = NULL;

    } else{
        NewData->course.courseId = courseListHead.prev->course.courseId + 1;
        courseListHead.prev->next = NewData;
        NewData->next = NULL;
        NewData->prev = courseListHead.prev;
        courseListHead.prev = NewData;
        printf("UpdateTrue\n");
    }


}

void addStudent() {
    int studentID;
    char studentName[20];
    char department[20];

    printf("\nPlease input the student's name: ");
    scanf("%s", studentName);
    printf("\nPlease input the student's ID: ");
    scanf("%d", &studentID);
    printf("\nPlease input the department name: ");
    scanf("%s", department);

    studentNode *NewData = (studentNode *) malloc(sizeof(studentNode));

    strcpy(NewData->student.studentName, studentName);
    strcpy(NewData->student.department, department);
    NewData->student.studentId = studentID;

    if (studentListHead.next == NULL){
        NewData->student.listId = 1;
        studentListHead.next = NewData;
        studentListHead.prev = NewData;

        NewData->prev = &studentListHead;
        NewData->next = NULL;

    } else{
        NewData->student.listId = studentListHead.prev->student.listId + 1;
        studentListHead.prev->next = NewData;
        NewData->next = NULL;
        NewData->prev = studentListHead.prev;
        studentListHead.prev = NewData;
        printf("UpdateTrue\n");
    }


}

void addSelection() {
    int studentID;
    int courseID;

    printf("\nPlease input the student's ID: ");
    scanf("%d", &studentID);
    printf("\nPlease input the course ID: ");
    scanf("%d", &courseID);

    selectionNode *NewData = (selectionNode *) malloc(sizeof(selectionNode));

    NewData->selection.courseID = courseID;
    NewData->selection.studentID = studentID;
    NewData->selection.courseScore = NULL;

    if (selectionListHead.next == NULL){
        NewData->selection.selectionID = 1;
        selectionListHead.next = NewData;
        selectionListHead.prev = NewData;

        NewData->prev = &selectionListHead;
        NewData->next = NULL;

    } else{
        NewData->selection.selectionID = selectionListHead.prev->selection.selectionID + 1;
        studentListHead.prev->next = NewData;
        NewData->next = NULL;
        NewData->prev = selectionListHead.prev;
        selectionListHead.prev = NewData;
        printf("UpdateTrue\n");
    }


}


void showMainMenu() {


    int choice = 88888;

    //    Keep the program running.
    do {

        if (choice == 88888) {
        } else {
            switch (choice) {
                case 1:
                    addCourse();
                    break;
                case 2:
                    addStudent();
                    break;
                case 6:
                    showStudent();
                    break;
                case 7:
                    showCourse();
                    break;
                case 9:
                    addStudent();
                    break;
                case 11:
                    showStudent();
                    break;
                default:
                    printf("Doesn't have the action!2\n");
                    break;
            }
        }
        //    Print project cover
        printf("\n"
               "   ______                              _____      __          __  _                _____            __               \n"
               "  / ____/___  __  _______________     / ___/___  / /__  _____/ /_(_)___  ____     / ___/__  _______/ /____  ____ ___ \n"
               " / /   / __ \\/ / / / ___/ ___/ _ \\    \\__ \\/ _ \\/ / _ \\/ ___/ __/ / __ \\/ __ \\    \\__ \\/ / / / ___/ __/ _ \\/ __ `__ \\\n"
               "/ /___/ /_/ / /_/ / /  (__  )  __/   ___/ /  __/ /  __/ /__/ /_/ / /_/ / / / /   ___/ / /_/ (__  ) /_/  __/ / / / / /\n"
               "\\____/\\____/\\__,_/_/  /____/\\___/   /____/\\___/_/\\___/\\___/\\__/_/\\____/_/ /_/   /____/\\__, /____/\\__/\\___/_/ /_/ /_/ \n"
               "                                                                                     /____/                          ");
//    Print suggestions
        printf("\n"
               "Select from the menu:\n\n"
               "1) Add course\n"
               "2) Add newer student's course selection\n"
               "3) Search student's selected courses\n"
               "4) Edit student's course selection (By id)\n"
               "5) Delete student's course selection (By id)\n"
               "6) Show all students' course selection\n"
               "7) Show all the courses\n"
               "9) Add student\n"
               "10) Show the number of one student's specific course\n\n"
               "11) Show students\n"
               "99) Quit\n\n"
               "Enter your choice: "
        );
    } while ((choice = getInt()) != 99); //    As long as choice != 99, the program will run.
}


void listInitial(){
    malloc(sizeof(courseListHead));
    courseListHead.next = NULL;
    courseListHead.prev = NULL;

    malloc(sizeof(studentListHead));
    studentListHead.next = NULL;
    studentListHead.prev = NULL;

    malloc(sizeof(selectionListHead));
    selectionListHead.next = NULL;
    selectionListHead.prev = NULL;
}

void showLoading() {
//    Loading screen
//    Print whether user wants to load from a file or create a new one

    printf("\n"
           "   ______                              _____      __          __  _                _____            __               \n"
           "  / ____/___  __  _______________     / ___/___  / /__  _____/ /_(_)___  ____     / ___/__  _______/ /____  ____ ___ \n"
           " / /   / __ \\/ / / / ___/ ___/ _ \\    \\__ \\/ _ \\/ / _ \\/ ___/ __/ / __ \\/ __ \\    \\__ \\/ / / / ___/ __/ _ \\/ __ `__ \\\n"
           "/ /___/ /_/ / /_/ / /  (__  )  __/   ___/ /  __/ /  __/ /__/ /_/ / /_/ / / / /   ___/ / /_/ (__  ) /_/  __/ / / / / /\n"
           "\\____/\\____/\\__,_/_/  /____/\\___/   /____/\\___/_/\\___/\\___/\\__/_/\\____/_/ /_/   /____/\\__, /____/\\__/\\___/_/ /_/ /_/ \n"
           "                                                                                     /____/                          ");
    printf("\n"
           "1) Create a new database\n"
           "2) Load from existing file\n\n"
           "99) Quit\n\n"
           "Enter your choice: "
           ""
    );

    int choice = 88888;

    //    Keep the program running.
    do {
        if (choice == 88888) {
        } else {
            switch (choice) {
                case 1:
                    listInitial();
                    showMainMenu();
                    goto end;
                    break;
                case 2:
                    printf("Developing");
                    break;
                default:
                    printf("Doesn't have the action!\n");
            }
        }

    } while ((choice = getInt()) != 99); //    As long as choice != 99, the program will run.
    end:
    printf("You have exit the program");
}


int main(void) {
    showLoading();
    return 0;
}
