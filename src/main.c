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

struct Student {
    int studentId;
    char studentName[20];
    char department[20];
} *studentHead;

typedef struct courseList{
    struct Course course;

    struct courseList* next;
    struct courseList* prev;
}courseNode;

struct StudentNode {
    int selectionId;
    int studentId;
    int courseId;
    int score;
};


courseNode courseListHead;


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
                    break;
                case 7:
                    showCourse();
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
               "2) Search student's selected courses\n"
               "3) Edit student's course selection (By id)\n"
               "4) Add newer student's course selection\n"
               "5) Delete student's course selection (By id)\n"
               "6) Show all students' course selection\n"
               "7) Show all the courses\n"
               "8) Show the number of one student's specific course\n\n"
               "99) Quit\n\n"
               "Enter your choice: "
        );
    } while ((choice = getInt()) != 99); //    As long as choice != 99, the program will run.
}


void courseListInitial(){
    malloc(sizeof(courseListHead));
    courseListHead.next = NULL;
    courseListHead.prev = NULL;
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
                    courseListInitial();
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
