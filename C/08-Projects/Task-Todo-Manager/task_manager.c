#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME 50
#define MAX_TIME 6
#define TASKS_FILE "tasks.txt"

// Task structure
typedef struct {
    int id;
    char name[MAX_TASK_NAME];
    char time[MAX_TIME];      // HH:MM format
    int completed;
    char createdAt[20];       // BUG FIX #3: was 50 but column showed 13 — now consistent 20 chars
} Task;

// Global variables
Task tasks[MAX_TASKS];
int taskCount = 0;

// Function prototypes
void displayMenu();
void addTask();
void viewTasks();
void deleteTask();
void markTaskComplete();
void saveTasks();
void loadTasks();
void sortTasksByTime(Task* arr, int count); // BUG FIX #6: now works on a copy
void displayStats();
char* getCurrentTime();
void clearInputBuffer();
int isValidTime(const char* time);
int isValidTaskName(const char* name);
void reassignIDs();  // BUG FIX #2: new helper

// Main function
int main() {
    printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║    🧠 BRAIN APP - Task Manager      ║\n");
    printf("║    Organize Your Tasks & Time        ║\n");
    printf("╚══════════════════════════════════════╝\n\n");

    loadTasks();

    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("❌ Invalid input! Please enter a number.\n\n");
            continue;
        }
        clearInputBuffer();

        printf("\n");

        switch (choice) {
            case 1: addTask();          break;
            case 2: viewTasks();        break;
            case 3: markTaskComplete(); break;
            case 4: deleteTask();       break;
            case 5: displayStats();     break;
            case 6:
                printf("Thank you for using Brain App! 👋\n");
                printf("Your tasks have been saved.\n");
                saveTasks();
                exit(0);
            default:
                printf("❌ Invalid choice! Please try again.\n\n");
        }
    }

    return 0;
}

// Display main menu
void displayMenu() {
    printf("╔══════════════════════════════════════╗\n");
    printf("║          📋 MAIN MENU                ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  1. ➕ Add Task                       ║\n");
    printf("║  2. 📋 View All Tasks                ║\n");
    printf("║  3. ✅ Mark Task Complete            ║\n");
    printf("║  4. 🗑️  Delete Task                  ║\n");
    printf("║  5. 📊 View Statistics               ║\n");
    printf("║  6. 🚪 Exit                          ║\n");
    printf("╚══════════════════════════════════════╝\n");
}

// Add a new task
void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("❌ Task limit reached! Cannot add more tasks.\n\n");
        return;
    }

    printf("╔══════════════════════════════════════╗\n");
    printf("║      ➕ ADD NEW TASK                 ║\n");
    printf("╚══════════════════════════════════════╝\n\n");

    char taskName[MAX_TASK_NAME];
    char timeStr[MAX_TIME];

    // Get task name
    printf("Enter task name (e.g., Study, Gym, Sleep): ");
    fgets(taskName, MAX_TASK_NAME, stdin);
    taskName[strcspn(taskName, "\n")] = 0;

    if (!isValidTaskName(taskName)) {
        printf("❌ Invalid task name! Task name cannot be empty.\n\n");
        return;
    }

    // Get time
    printf("Enter time in HH:MM format (24-hour): ");
    fgets(timeStr, sizeof(timeStr), stdin);
    timeStr[strcspn(timeStr, "\n")] = 0;

    // BUG FIX #5: flush any extra chars if input was longer than MAX_TIME-1
    // (fgets stops at MAX_TIME-1, so remaining chars stay in buffer)
    if (strlen(timeStr) == MAX_TIME - 1) {
        clearInputBuffer();
    }

    if (!isValidTime(timeStr)) {
        printf("❌ Invalid time format! Please use HH:MM format (00:00 - 23:59).\n\n");
        return;
    }

    tasks[taskCount].id = taskCount + 1;
    strcpy(tasks[taskCount].name, taskName);
    strcpy(tasks[taskCount].time, timeStr);
    tasks[taskCount].completed = 0;
    strcpy(tasks[taskCount].createdAt, getCurrentTime());

    taskCount++;

    printf("\n✅ Task added successfully!\n\n");
    saveTasks();
}

// View all tasks — BUG FIX #6: sort a COPY so original array order is preserved
void viewTasks() {
    if (taskCount == 0) {
        printf("┌──────────────────────────────────────┐\n");
        printf("│  No tasks yet. Add one to get started! 🚀\n");
        printf("└──────────────────────────────────────┘\n\n");
        return;
    }

    // Work on a local copy so original IDs/order stay intact
    Task sorted[MAX_TASKS];
    memcpy(sorted, tasks, taskCount * sizeof(Task));
    sortTasksByTime(sorted, taskCount);

    // BUG FIX #3: column widths adjusted to fit actual data
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                      📋 YOUR TASKS                             ║\n");
    printf("╠════╦═══════════════════╦═══════╦═══════════╦═══════════════════╣\n");
    printf("║ ID ║ Task Name         ║ Time  ║ Status    ║ Created At        ║\n");
    printf("╠════╬═══════════════════╬═══════╬═══════════╬═══════════════════╣\n");

    for (int i = 0; i < taskCount; i++) {
        const char* status = sorted[i].completed ? "✅ Done  " : "⏳ Pending";
        printf("║ %2d ║ %-17s ║ %s ║ %s ║ %-17s ║\n",
               sorted[i].id,
               sorted[i].name,
               sorted[i].time,
               status,
               sorted[i].createdAt);
    }

    printf("╚════╩═══════════════════╩═══════╩═══════════╩═══════════════════╝\n\n");
}

// Mark task as complete
void markTaskComplete() {
    if (taskCount == 0) {
        printf("❌ No tasks to mark! Add some tasks first.\n\n");
        return;
    }

    printf("╔══════════════════════════════════════╗\n");
    printf("║      ✅ MARK TASK COMPLETE           ║\n");
    printf("╚══════════════════════════════════════╝\n\n");

    viewTasks();

    int taskId;
    printf("Enter task ID to mark complete: ");
    if (scanf("%d", &taskId) != 1) {
        clearInputBuffer();
        printf("❌ Invalid input!\n\n");
        return;
    }
    clearInputBuffer();

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == taskId) {
            if (tasks[i].completed) {
                printf("⚠️  Task is already completed!\n\n");
            } else {
                tasks[i].completed = 1;
                printf("✅ Task marked as complete!\n\n");
                saveTasks();
            }
            return;
        }
    }

    printf("❌ Task not found!\n\n");
}

// Delete a task
void deleteTask() {
    if (taskCount == 0) {
        printf("❌ No tasks to delete!\n\n");
        return;
    }

    printf("╔══════════════════════════════════════╗\n");
    printf("║      🗑️  DELETE TASK                 ║\n");
    printf("╚══════════════════════════════════════╝\n\n");

    viewTasks();

    int taskId;
    printf("Enter task ID to delete: ");
    if (scanf("%d", &taskId) != 1) {
        clearInputBuffer();
        printf("❌ Invalid input!\n\n");
        return;
    }
    clearInputBuffer();

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == taskId) {
            printf("\n🔄 Are you sure? (Type 'yes' to confirm): ");
            char confirm[10];
            fgets(confirm, sizeof(confirm), stdin);
            confirm[strcspn(confirm, "\n")] = 0;
f
            if (strcmp(confirm, "yes") == 0) {
                for (int j = i; j < taskCount - 1; j++) {
                    tasks[j] = tasks[j + 1];
                }
                taskCount--;
                reassignIDs();  // BUG FIX #2: fix IDs after deletion
                printf("✅ Task deleted successfully!\n\n");
                saveTasks();
            } else {
                printf("❌ Deletion cancelled.\n\n");
            }
            return;
        }
    }

    printf("❌ Task not found!\n\n");
}

// Display statistics
void displayStats() {
    int completed = 0;
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].completed) completed++;
    }

    printf("╔══════════════════════════════════════╗\n");
    printf("║         📊 STATISTICS                ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║ Total Tasks:        %2d               ║\n", taskCount);
    printf("║ Completed:          %2d               ║\n", completed);
    printf("║ Pending:            %2d               ║\n", taskCount - completed);
    if (taskCount > 0) {
        int percentage = (completed * 100) / taskCount;
        printf("║ Completion Rate:    %2d%%              ║\n", percentage);
    }
    printf("╚══════════════════════════════════════╝\n\n");
}

// Save tasks to file
void saveTasks() {
    FILE *file = fopen(TASKS_FILE, "w");
    if (file == NULL) {
        printf("❌ Error saving tasks!\n");
        return;
    }

    fprintf(file, "%d\n", taskCount);
    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "%d|%s|%s|%d|%s\n",
                tasks[i].id,
                tasks[i].name,
                tasks[i].time,
                tasks[i].completed,
                tasks[i].createdAt);
    }

    fclose(file);
}

// BUG FIX #4: fixed fscanf format — use %19[^\n] to match createdAt[20]
void loadTasks() {
    FILE *file = fopen(TASKS_FILE, "r");
    if (file == NULL) {
        printf("📝 No saved tasks found. Starting fresh.\n\n");
        return;
    }

    if (fscanf(file, "%d\n", &taskCount) != 1) {
        printf("❌ Error reading tasks file. Starting fresh.\n\n");
        taskCount = 0;
        fclose(file);
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        if (fscanf(file, "%d|%49[^|]|%5[^|]|%d|%19[^\n]\n",
                   &tasks[i].id,
                   tasks[i].name,
                   tasks[i].time,
                   &tasks[i].completed,
                   tasks[i].createdAt) != 5) {
            printf("⚠️  Warning: task #%d could not be read properly.\n", i + 1);
            taskCount = i;  // truncate to successfully loaded tasks
            break;
        }
    }

    fclose(file);
    printf("✅ %d task(s) loaded successfully.\n\n", taskCount);
}

// BUG FIX #6: sort operates on passed array, not global
void sortTasksByTime(Task* arr, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(arr[j].time, arr[j + 1].time) > 0) {
                Task temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// BUG FIX #2: reassign sequential IDs after deletion
void reassignIDs() {
    for (int i = 0; i < taskCount; i++) {
        tasks[i].id = i + 1;
    }
}

// Get current time — returns "YYYY-MM-DD HH:MM" (16 chars, fits in 20-char field)
char* getCurrentTime() {
    static char buffer[20];
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", timeinfo);
    return buffer;
}

// Clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// BUG FIX #1: proper digit validation added
int isValidTime(const char* time) {
    if (strlen(time) != 5) return 0;
    if (!isdigit(time[0]) || !isdigit(time[1])) return 0;
    if (time[2] != ':') return 0;
    if (!isdigit(time[3]) || !isdigit(time[4])) return 0;

    int hour   = (time[0] - '0') * 10 + (time[1] - '0');
    int minute = (time[3] - '0') * 10 + (time[4] - '0');

    if (hour < 0 || hour > 23)   return 0;
    if (minute < 0 || minute > 59) return 0;

    return 1;
}

// Validate task name
int isValidTaskName(const char* name) {
    return strlen(name) > 0;
}
