#include "stdio.h"
#include "../lib/cJSON.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
// Data struct

//  Course structure
struct Course {
    int courseId;
    char courseName[20];
    char teacher[20];
    char department[20];
    int credit;
};

typedef struct courseList {
    struct Course course;

    struct courseList *next;
    struct courseList *prev;
} courseNode;

struct Student {
    int listId;
    int studentId;
    char studentName[20];
    char department[20];
};

typedef struct studentList {
    struct Student student;

    struct studentList *next;
    struct studentList *prev;
} studentNode;


struct Selection {
    int selectionID;
    int studentID;
    int courseID;
    char courseName[20];
    char teacherName[20];
    char studentName[20];
    int courseScore;
};

typedef struct selectionList {
    struct Selection selection;

    struct selectionList *next;
    struct selectionList *prev;

} selectionNode;


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


void pause(){
    // Pasue wait for user input
    printf("\nPlease press ENTER to continue.");
    getch();
}

void showCourse() {
//    Traversal course list
    courseNode *head;   // Create Node
    head = courseListHead.next; //  Copy listHead node to function node
    while (head != NULL) {
        printf("\nCourse id: %d\t", head->course.courseId);
        printf("Course name:%s \t", head->course.courseName);
        printf("department:%s \t", head->course.department);
        printf("teacher:%s \t", head->course.teacher);
        printf("credit:%d\n", head->course.credit);
        head = head->next;
    }
    pause();
}

void showStudent() {
//    Traversal course list
    int flag = 0;
    studentNode *head;   // Create Node
    head = studentListHead.next; //  Copy listHead node to function node

    while (head != NULL) {
        printf("\nList Id:%d\t", head->student.listId);
        printf("Student name: %s\t", head->student.studentName);
        printf("Student department:%s \t", head->student.department);
        printf("Student's ID:%d", head->student.studentId);
        head = head->next;
        flag = 1;
    }
    if (flag == 0){
        printf("\nThe list is empty\n");
    }
    pause();
}

void showSelection() {
//    Traversal course list
    int flag = 0;
    selectionNode *head;   // Create Node
    head = selectionListHead.next; //  Copy listHead node to function node
    while (head != NULL) {
        flag = 1;
        printf("\nSelection ID: %d\t", head->selection.selectionID);
        printf("Course ID: %d\t", head->selection.courseID);
        printf("Course name: %s\t", head->selection.courseName);
        printf("Student's ID: %d\t", head->selection.studentID);
        printf("Course Score: %d\t", head->selection.courseScore);

        head = head->next;
    }
    if (flag == 0){
        printf("\nThe list is empty!\n");
    }
    pause();
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

    if (courseListHead.next == NULL) {
        NewData->course.courseId = 1;
        courseListHead.next = NewData;
        courseListHead.prev = NewData;

        NewData->prev = &courseListHead;
        NewData->next = NULL;

    } else {
        NewData->course.courseId = courseListHead.prev->course.courseId + 1;
        courseListHead.prev->next = NewData;
        NewData->next = NULL;
        NewData->prev = courseListHead.prev;
        courseListHead.prev = NewData;
    }
    printf("\nUpdate successful\n");
    pause();

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

    if (studentListHead.next == NULL) {
        NewData->student.listId = 1;
        studentListHead.next = NewData;
        studentListHead.prev = NewData;

        NewData->prev = &studentListHead;
        NewData->next = NULL;

    } else {
        NewData->student.listId = studentListHead.prev->student.listId + 1;
        studentListHead.prev->next = NewData;
        NewData->next = NULL;
        NewData->prev = studentListHead.prev;
        studentListHead.prev = NewData;
    }

    printf("\nUpdate successful\n");
    pause();

}


int verifyCourse(int courseID) {
    //    Verify whether the course exists
//    If course exists return 1 else return 0
    int flag = 0;
    courseNode *head;   // Create Node
    head = courseListHead.next; //  Copy listHead node to function node
    while (head != NULL) {
        if (head->course.courseId == courseID) {
            flag = 1;
        }
        head = head->next;
    }
    return flag;
}


int verifyStudent(int studentID) {
    //    Verify whether the student exists
//    If student exists return 1 else return 0
    int flag = 0;
    studentNode *head;   // Create Node
    head = studentListHead.next; //  Copy listHead node to function node
    while (head != NULL) {
        if (head->student.studentId == studentID) {
            flag = 1;
        }
        head = head->next;
    }
    return flag;
}

void updateSelectionCourseID(selectionNode *head){
    int courseID;
    printf("Please input the courseID you want to change to:");
    scanf("%d", &courseID);
    head->selection.courseID = courseID;

    if (verifyCourse(courseID) == 1) {
        courseNode *shead;   // Create Node
        shead = courseListHead.next; //  Copy listHead node to function node
        while (shead != NULL) {
            if (shead->course.courseId == courseID) {
                strcpy(head->selection.courseName, shead->course.courseName);
            }
            shead = shead->next;
            printf("\nUpdate success\n");
            pause();
        }
    } else {
        printf("Wrong courseID!\n");
    }
}

void updateSelectionScore(selectionNode *head){
    int score;
    printf("Plead input the score: ");
    scanf("%d", &score);
    head->selection.courseScore = score;

    printf("\nUpdate successful\n");
    pause();
}

void editSelection(){
    int flag = 0;
    int selectionID;

    printf("\nPlease input the selectionID: ");
    scanf("%d", &selectionID);

    selectionNode *head;   // Create Node
    head = selectionListHead.next; //  Copy listHead node to function node
    while (head != NULL) {
        if (head->selection.selectionID == selectionID) {
            flag = 1;
            printf("\nSelection ID: %d\t", head->selection.selectionID);
            printf("Student's ID: %d\t", head->selection.studentID);
            printf("Student's Name: %s\t", head->selection.studentName);
            printf("Course ID: %d\t", head->selection.courseID);
            printf("Course Score: %d\t", head->selection.courseScore);

            int choice = 88888;

            //    Keep the program running.
            do {
                if (choice == 88888) {
                } else {
                    switch (choice) {
                        case 1:
                            updateSelectionCourseID(head);
                            break;
                        case 2:
                            updateSelectionScore(head);
                            break;
                        default:
                            printf("Doesn't have the action!\n");
                            break;
                    }
                }
                //    Print project cover
                showTitleBar();
//    Print suggestions
                printf("\n"
                       "Select from the menu:\n\n"
                       "1) Edit courseID\n"
                       "2) Edit score\n\n"
                       "99) Quit\n\n"
                       "Enter your choice: "
                );
            } while ((choice = getInt()) != 99); //    As long as choice != 99, the program will run.

        }
        head = head->next;
    }
    if (flag == 0) {
        printf("\nNo selection found!");
        pause();
    }
}

void searchSelectionByCourseID() {
    int courseID;
    int flag = 0;
    printf("\nPlease input the course ID: ");
    scanf("%d", &courseID);

    if (verifyCourse(courseID) == 1) {
        selectionNode *head;   // Create Node
        head = selectionListHead.next; //  Copy listHead node to function node
        while (head != NULL) {
            if (head->selection.courseID == courseID) {
                flag = 1;
                printf("\nSelection ID: %d\t", head->selection.selectionID);
                printf("Student's ID: %d\t", head->selection.studentID);
                printf("Student's Name: %s\t", head->selection.studentName);
                printf("Course ID: %d\t", head->selection.courseID);
                printf("Course Score: %d\t", head->selection.courseScore);

                printf("\nUpdate successful\n");
                pause();
            }
            head = head->next;
        }
    } else {
        flag = 1;
        printf("Wrong courseID!\n");
        pause();
    }
    if (flag == 0){
        printf("\nNo selection information available.\n");
        pause();
    }
}

void searchSelectionByCourseName() {
    char courseName[20];
    int flag = 0;

    printf("\nPlease input the course name: ");
    scanf("%s", courseName);

    selectionNode *head;   // Create Node
    head = selectionListHead.next; //  Copy listHead node to function node
    while (head != NULL) {
        if (strcmp(head->selection.courseName, courseName) == 0) {
            flag = 1;
            printf("\nSelection ID: %d\t", head->selection.selectionID);
            printf("Student's ID: %d\t", head->selection.studentID);
            printf("Student's Name: %s\t", head->selection.studentName);
            printf("Course ID: %d\t", head->selection.courseID);
            printf("Course Score: %d\t", head->selection.courseScore);
            pause();
        }
        head = head->next;
    }
    if (flag == 0) {
        printf("\nNo course was found!");
        pause();
    }
}

void searchSelectionByTeacher() {
    char teacherName[20];
    int flag = 0;

    printf("\nPlease input the teacher name: ");
    scanf("%s", teacherName);

    selectionNode *head;   // Create Node
    head = selectionListHead.next; //  Copy listHead node to function node
    while (head != NULL) {
        if (strcmp(head->selection.teacherName, teacherName) == 0) {
            flag = 1;
            printf("\nSelection ID: %d\t", head->selection.selectionID);
            printf("Student's ID: %d\t", head->selection.studentID);
            printf("Student's Name: %s\t", head->selection.studentName);
            printf("Course ID: %d\t", head->selection.courseID);
            printf("Course Score: %d\t", head->selection.courseScore);
            pause();
        }
        head = head->next;
    }
    if (flag == 0) {
        printf("\nNo teacher found!");
        pause();
    }
}

void addSelection() {
    int studentID;
    int courseID;

    printf("\nPlease input the student's ID: ");
    scanf("%d", &studentID);
    printf("\nPlease input the course ID: ");
    scanf("%d", &courseID);

    if (verifyCourse(courseID) * verifyStudent(studentID) == 1) {
        selectionNode *NewData = (selectionNode *) malloc(sizeof(selectionNode));

        NewData->selection.courseID = courseID;
        NewData->selection.studentID = studentID;
        NewData->selection.courseScore = NULL;

        courseNode *head;   // Create Node
        head = courseListHead.next; //  Copy listHead node to function node
        while (head != NULL) {
            if (head->course.courseId == courseID) {
                strcpy(NewData->selection.courseName, head->course.courseName);
                strcpy(NewData->selection.teacherName, head->course.teacher);
            }
            head = head->next;
        }

        studentNode *studentHead;   // Create Node
        studentHead = studentListHead.next; //  Copy listHead node to function node
        while (studentHead != NULL) {
            if (studentHead->student.studentId == studentID) {
                strcpy(NewData->selection.studentName, studentHead->student.studentName);
            }
            studentHead = studentHead->next;
        }


        if (selectionListHead.next == NULL) {
            NewData->selection.selectionID = 1;
            selectionListHead.next = NewData;
            selectionListHead.prev = NewData;

            NewData->prev = &selectionListHead;
            NewData->next = NULL;
            printf("Update successful\n");
            pause();

        } else {
            NewData->selection.selectionID = selectionListHead.prev->selection.selectionID + 1;
            selectionListHead.prev->next = NewData;
            NewData->next = NULL;
            NewData->prev = selectionListHead.prev;
            selectionListHead.prev = NewData;
            printf("Update successful\n");
            pause();
        }
    } else {
        printf("ERROR courseID or studentID");
        pause();
    }
}



void deleteSelection(){
    int selectionID;
    int flag;
    printf("Please input the selectionID you want to deleted:");
    scanf("%d", &selectionID);

    selectionNode *head;   // Create Node
    head = &selectionListHead; //  Copy listHead node to function node
    if (head->next == NULL){
        flag = 3;
        printf("The list is empty!");
        pause();
    } else{
        while (head != NULL) {
            if (head->selection.selectionID == selectionID && head->next == NULL) {
                flag = 1;
                head->prev->next = NULL;
                selectionListHead.prev = head->prev;
                free(head);
            }
            else if (head->selection.selectionID == selectionID && head->next != NULL){
                flag = 1;
                head->prev->next = head->next;
                head->next->prev = head->prev;
                free(head);
            }
            head = head->next;
        }
    }

    if (flag == 0) {
        printf("\nNo selectionID was found!");
        pause();
    }
    else if (flag == 1){
        selectionNode *shead;
        shead = selectionListHead.next;
        while (shead != NULL){
            shead->selection.selectionID = shead->prev->selection.selectionID + 1;
            shead = shead->next;
        }
        printf("\nUpdate successful");
        pause();
    }
}

void showTitleBar() {
    printf("\n"
           "   ______                              _____      __          __  _                _____            __               \n"
           "  / ____/___  __  _______________     / ___/___  / /__  _____/ /_(_)___  ____     / ___/__  _______/ /____  ____ ___ \n"
           " / /   / __ \\/ / / / ___/ ___/ _ \\    \\__ \\/ _ \\/ / _ \\/ ___/ __/ / __ \\/ __ \\    \\__ \\/ / / / ___/ __/ _ \\/ __ `__ \\\n"
           "/ /___/ /_/ / /_/ / /  (__  )  __/   ___/ /  __/ /  __/ /__/ /_/ / /_/ / / / /   ___/ / /_/ (__  ) /_/  __/ / / / / /\n"
           "\\____/\\____/\\__,_/_/  /____/\\___/   /____/\\___/_/\\___/\\___/\\__/_/\\____/_/ /_/   /____/\\__, /____/\\__/\\___/_/ /_/ /_/ \n"
           "                                                                                     /____/                          ");
}

void searchSelection() {


    int choice = 88888;

    //    Keep the program running.
    do {
        if (choice == 88888) {
        } else {
            switch (choice) {
                case 1:
                    searchSelectionByCourseID();
                    break;
                case 2:
                    searchSelectionByCourseName();
                    break;
                case 3:
                    searchSelectionByTeacher();
                    break;
                default:
                    printf("Doesn't have the action!\n");
                    break;
            }
        }
        //    Print project cover
        showTitleBar();
//    Print suggestions
        printf("\n"
               "Select from the menu:\n\n"
               "1) Search by courseID\n"
               "2) Search by courseName\n"
               "3) Search by teacher\n\n"
               "99) Quit\n\n"
               "Enter your choice: "
        );
    } while ((choice = getInt()) != 99); //    As long as choice != 99, the program will run.
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
                case 3:
                    addSelection();
                    break;
                case 4:
                    searchSelection();
                    break;
                case 5:
                    editSelection();
                    break;
                case 6:
                    deleteSelection();
                    break;
                case 7:
                    showCourse();
                    break;
                case 8:
                    showSelection();
                    break;
                case 9:
                    addStudent();
                    break;
                case 10:
                    showStudent();
                    break;
                default:
                    printf("Doesn't have the action!2\n");
                    break;
            }
        }
        //    Print project cover
        showTitleBar();
//    Print suggestions
        printf("\n"
               "Select from the menu:\n\n"
               "1) Add course\n"
               "2) Add new student\n"
               "3) Add newer student's course selection\n"
               "4) Search student's selected courses\n"
               "5) Edit student's course selection (By id)\n"
               "6) Delete student's course selection (By id)\n"
               "7) Show all the courses\n"
               "8) Show all students' course selection\n"
               "9) Add student\n"
               "10) Show students\n\n"
               "99) Quit\n\n"
               "Enter your choice: "
        );
    } while ((choice = getInt()) != 99); //    As long as choice != 99, the program will run.
}


void listInitial() {
    malloc(sizeof(courseListHead));
    courseListHead.next = NULL;
    courseListHead.prev = NULL;

    malloc(sizeof(studentListHead));
    studentListHead.next = NULL;
    studentListHead.prev = NULL;

    malloc(sizeof(selectionListHead));
    selectionListHead.next = NULL;
    selectionListHead.prev = NULL;
    selectionListHead.selection.selectionID = 0;
}

void showLoading() {
//    Loading screen
//    Print whether user wants to load from a file or create a new one



    int choice = NULL;

    //    Keep the program running.
    do {
        if (choice == NULL) {
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
                    printf("\nDoesn't have the action!\n");
                    pause();
            }
        }
        showTitleBar();
        printf("\n"
               "1) Create a new database\n"
               "2) Load from existing file\n\n"
               "99) Quit\n\n"
               "Enter your choice: "
               ""
        );
    } while ((choice = getInt()) != 99); //    As long as choice != 99, the program will run.
    end:
    printf("You have exit the program");
}


int main(void) {
    showLoading();
    return 0;
}
