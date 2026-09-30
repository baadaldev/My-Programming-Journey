#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void welcomeMsg();
void headerMsg(char *message);
void developer();
void adminLogin();
void studentLogin();
void about();
void mainMenu();
void userRole();
void addQuestion();

int choice;
#define MAX_QUESTIONS  100
#define MAX_Q_LEN      256
#define MAX_OPT_LEN    128

typedef struct {
    char question[MAX_Q_LEN];
    char options[4][MAX_OPT_LEN];
    int  correctOption;
} Question;

Question questionBank[MAX_QUESTIONS];
int questionCount = 0;

void welcomeMsg() {
    system("cls");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t        =*******************************************=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                  M C Q                    =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =                   APP                     =");
    printf("\n\t\t\t        =*******************************************=");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}

void headerMsg(char *message) {
    system("cls");
    printf("\n\t\t\t***********************************************");
    printf("\n\t\t\t                 MCQ SYSTEM APP                ");
    printf("\n\t\t\t***********************************************");


    printf("\n\t\t\t\t\t  %s", message);

    printf("\n\t\t\t-----------------------------------------------");
}

void developer() {
    headerMsg("Developer Menu");
    printf("\n\n\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =              Developers Information              =");
    printf("\n\t\t\t        =**************************************************=");
    printf("\n\t\t\t        =               Name                     ID        =");
    printf("\n\t\t\t        =**************************************************=");
    printf("\n\t\t\t        =    1. Name:Joarder Al Rafi      ID: 253-15-671   =");
    printf("\n\t\t\t        =    2. Name:MD. Rejuyanul Islam  ID: 253-15-721   =");
    printf("\n\t\t\t        =    3. Name:MD. Ahanaf Shahriar  ID: 253-15-122   =");
    printf("\n\t\t\t        =    4. Name:MD.Rakibul Islam     ID: 253-15-370   =");
    printf("\n\t\t\t        =    5. Name:Shafayet Ullah Nayem ID: 253-15-685   =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}
void viewQuestions() {
    int i;

    if (questionCount == 0) {
        headerMsg("VIEW QUESTIONS");

        printf("\n\n\t\t\tNo questions available!");
        printf("\n\n\t\t\tPress any key to return...");
        getch();
        return;
    }

    for (i = 0; i < questionCount; i++) {

        headerMsg("VIEW QUESTIONS");

        printf("\n\n\t\t\tQuestion %d:\n", i + 1);
        printf("\n\t\t\tQ: %s", questionBank[i].question);
        printf("\n\t\t\tA) %s", questionBank[i].options[0]);
        printf("\n\t\t\tB) %s", questionBank[i].options[1]);
        printf("\n\t\t\tC) %s", questionBank[i].options[2]);
        printf("\n\t\t\tD) %s", questionBank[i].options[3]);

        printf("\n\n\t\t\tCorrect Answer: %c",
               'A' + questionBank[i].correctOption - 1);

        printf("\n\n\t\t\t---------------------------------------");
        printf("\n\t\t\tPress any key for next...");
        getch();
    }
}
void addQuestion() {
    int addMore = 1;
    int optNum, correctOpt;
    char optLabels[] = {'A','B','C','D'};

    while (addMore) {

        system("cls");

        Question q;

        printf("\n\t--- ADD QUESTION ---\n");

        printf("\nEnter Question: ");
        getchar();
        fgets(q.question, MAX_Q_LEN, stdin);

        system("cls");

        printf("\nQuestion: %s\n", q.question);

        for (optNum = 0; optNum < 4; optNum++) {
            printf("Option %c: ", optLabels[optNum]);
            fgets(q.options[optNum], MAX_OPT_LEN, stdin);
        }
        do {
            system("cls");

            printf("\nQuestion: %s\n", q.question);
            printf("\nA) %s", q.options[0]);
            printf("B) %s", q.options[1]);
            printf("C) %s", q.options[2]);
            printf("D) %s", q.options[3]);

            printf("\nEnter correct option (1-4): ");
            scanf("%d", &correctOpt);

            if (correctOpt < 1 || correctOpt > 4) {
                printf("\nInvalid! Try again.");
                getch();
            }

        } while (correctOpt < 1 || correctOpt > 4);

        q.correctOption = correctOpt;
        questionBank[questionCount] = q;
        questionCount++;

        system("cls");

        printf("\nSaved successfully!\n");
        printf("\nAdd more? (1=yes / 0=no): ");
        scanf("%d", &addMore);
    }
}

void adminLogin() {
    char username[20];
    char userpwd[8];
    int i;

    headerMsg("Admin Login");
    printf("\n\n\t\t\tEnter your username : ");
    scanf("%s", username);
    printf("\t\t\tEnter your password : ");

    for(i = 0; i < 5; i++) {
        userpwd[i] = getch();
        printf("*");
    }
    userpwd[i] = '\0';
    if(strcmp(username, "admin") == 0 && strcmp(userpwd, "admin") == 0) {
        printf("\n\n\t\t\tLogged In Successful!");
        getch();
        mainMenu();
    } else {
        printf("\n\n\t\t\tIncorrect credentials! Try again...");
        getch();
        userRole();
    }
}
void TAKEQUIZ() {
    int i;

    if (questionCount == 0) {
        headerMsg("TAKE QUIZ");
        printf("\n\n\t\t\tNo questions available in the bank!");
        printf("\n\n\t\t\tPress any key to return...");
        getch();
        return;
    }

    for (i = 0; i < questionCount; i++) {
        headerMsg("QUIZ IN PROGRESS");

        printf("\n\n\t\t\tQuestion %d:\n", i + 1);
        printf("\n\t\t\tQ: %s", questionBank[i].question);
        printf("\n\t\t\tA) %s", questionBank[i].options[0]);
        printf("\n\t\t\tB) %s", questionBank[i].options[1]);
        printf("\n\t\t\tC) %s", questionBank[i].options[2]);
        printf("\n\t\t\tD) %s", questionBank[i].options[3]);



        printf("\n\t\t\t---------------------------------------");
        printf("\n\t\t\tPress any key for next...");
        getch();
    }

    headerMsg("QUIZ FINISHED");
    printf("\n\n\t\t\tYou have reached the end of the quiz!");
    printf("\n\n\t\t\tPress any key to return to panel...");
    getch();
}


void takeQuiz() {
    int i;
    int score = 0;
    char studentAnswer;

    if (questionCount == 0) {
        headerMsg("TAKE QUIZ");
        printf("\n\n\t\t\tNo questions available!");
        printf("\n\n\t\t\tPress any key to return...");
        getch();
        return;
    }

    for (i = 0; i < questionCount; i++) {
        headerMsg("QUIZ IN PROGRESS");

        printf("\n\n\t\t\tQuestion %d:\n", i + 1);
        printf("\n\t\t\tQ: %s", questionBank[i].question);
        printf("\n\t\t\tA) %s", questionBank[i].options[0]);
        printf("\n\t\t\tB) %s", questionBank[i].options[1]);
        printf("\n\t\t\tC) %s", questionBank[i].options[2]);
        printf("\n\t\t\tD) %s", questionBank[i].options[3]);

        printf("\n\t\t\tYour Answer (A, B, C, or D): ");
        scanf(" %c", &studentAnswer);

        if(studentAnswer >= 'a' && studentAnswer <= 'z') studentAnswer -= 32;

        if (studentAnswer == ('A' + questionBank[i].correctOption - 1)) {
            score++;
        }
        printf("\n\t\t\tAnswer recorded! Press any key for next...");
        getch();
    }

    headerMsg("QUIZ RESULT");
    printf("\n\n\t\t\tQuiz Completed!");
    printf("\n\t\t\t---------------------------------------");
    printf("\n\t\t\tYour Total Score: %d out of %d", score, questionCount);
    printf("\n\t\t\t---------------------------------------");
    printf("\n\n\t\t\tPress any key to return to panel...");
    getch();
}


void studentPanel() {
    do {
        headerMsg("STUDENT PANEL");
        printf("\n\t\t\t1. Take Quiz");
        printf("\n\t\t\t2. Exit");
        printf("\n\n\t\t\tEnter choice => ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: takeQuiz(); break;
            case 2: userRole(); break;
            case 0: return;
            default:
                printf("\n\t\t\tINVALID INPUT!!!");
                getch();
        }
    } while(choice != 0);
}
void studentLogin() {
    char studentname[20];
    char userpwd[8];
    int i;

    headerMsg("Student Login");
    printf("\n\n\t\t\tEnter Student Name : ");
    scanf("%s", studentname);
    printf("\t\t\tEnter your password : ");

    for(i = 0; i < 7; i++) {
        userpwd[i] = getch();
        printf("*");
    }
    userpwd[i] = '\0';

    if(strcmp(studentname, "student") == 0 && strcmp(userpwd, "student") == 0) {
        printf("\n\n\t\t\tLogged In Successful!");
        getch();
        studentPanel();
    } else {
        printf("\n\n\t\t\tIncorrect credentials! Try again...");
        getch();
        userRole();
    }
}
void about() {
    headerMsg("About");
    printf("\n\n\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =              Project Information                 =");
    printf("\n\t\t\t        =**************************************************=");
    printf("\n\t\t\t        = Course Name: Programming and Problem Solving Lab =");
    printf("\n\t\t\t        = Course Code: CSE 114                             =");
    printf("\n\t\t\t        = Teacher Name: Mr. Abdullah Al Mamun              =");
    printf("\n\t\t\t        = Designation: Lecturer                            =");
    printf("\n\t\t\t        = Project Name: MCQ QUIZ APP                       =");
    printf("\n\t\t\t        = Date of Submission: 18.04.2026                   =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}

void mainMenu() {
    do {
        headerMsg("ADMIN PANEL");
        printf("\n\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =       Questions in bank : %-3d     =",questionCount);
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\n\t\t\t1. Developer Information");
        printf("\n\t\t\t2. ADD QUESTION");
        printf("\n\t\t\t3. View All Questions");
        printf("\n\t\t\t4. Exit");
        printf("\n\n\t\t\tEnter choice => ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: developer();    break;
            case 2: addQuestion();  break;
            case 3: viewQuestions(); break;
            case 4: userRole(); break;
            case 0: return;
            default:
                printf("\n\t\t\tINVALID INPUT!!!");
                getch();
        }
    } while(choice != 0);
}

void userRole() {
    do {
        headerMsg("User Role");
        printf("\n\n\t\t\t        -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        printf("\n\t\t\t        =       Login to any panel      =");
        printf("\n\t\t\t        =*******************************=");
        printf("\n\t\t\t        =        1. Admin Panel         =");
        printf("\n\t\t\t        =        2. Student Panel       =");
        printf("\n\t\t\t        =        3. About               =");
        printf("\n\t\t\t        =        0. Exit Application    =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\n\t\t\t Enter your choice.....");
        scanf("%d", &choice);

        switch(choice) {
            case 1: adminLogin();  break;
            case 2: studentLogin(); break;
            case 3: about(); break;
            case 0: exit(0);
            default:
                printf("\n\t\t\tINVALID INPUT!!!");
                getch();
        }
    } while(choice != 0);
}

int main() {
    welcomeMsg();
    userRole();
    return 0;

}
