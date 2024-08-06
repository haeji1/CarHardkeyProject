#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INPUT_FILE "hardkey_event" // 원본 파일 이름
#define TEMP_FILE "temp_file"      // 임시 파일 이름
#define MAX_LINE_LENGTH 256        // 한 줄의 최대 길이

// 특정 명령어의 값을 업데이트하는 함수
void updateValuesInFile(const char *command, int new_values[], int num_values) {
    FILE *file = fopen(INPUT_FILE, "r");    // 원본 파일을 읽기 모드로 엽니다.
    FILE *temp = fopen(TEMP_FILE, "w");     // 임시 파일을 쓰기 모드로 엽니다.

    if (file == NULL || temp == NULL) {
        perror("Error opening file");       // 파일 열기 실패 시 에러 메시지를 출력합니다.
        return;
    }

    char line[MAX_LINE_LENGTH];
    int found_command = 0;   // 명령어가 발견되었는지 여부를 추적합니다.
    int value_index = 0;     // 업데이트할 값의 인덱스를 추적합니다.

    // 원본 파일을 한 줄씩 읽으면서 처리합니다.
    while (fgets(line, sizeof(line), file)) {
        // 명령어가 현재 줄의 시작 부분과 일치하는 경우
        if (strncmp(line, command, strlen(command)) == 0) {
            found_command = 1;     // 명령어가 발견되었음을 표시합니다.
            fprintf(temp, "%s", line); // 임시 파일에 원본 명령어를 그대로 복사합니다.
            continue;
        }

        if (found_command) {
            // 현재 줄이 숫자로 시작하면 값을 업데이트합니다.
            if ((isdigit(line[0]) || (line[0] == '-' && isdigit(line[1]))) && value_index < num_values) {
                fprintf(temp, "%d   // Updated value\n", new_values[value_index++]);
                // 원본 줄의 주석 부분을 복사합니다.
                if (strchr(line, '/') != NULL) {
                    fprintf(temp, "%s", strchr(line, '/') + 1);
                }
                continue;
            }

            // 공백 줄을 만나면 명령어 블록이 끝났음을 표시합니다.
            if (line[0] == '\n') {
                found_command = 0;
            }

            // 주석을 유지하면서 나머지 내용을 그대로 복사합니다.
            fprintf(temp, "%s", line);
        } else {
            // 명령어를 찾기 전의 내용을 그대로 복사합니다.
            fprintf(temp, "%s", line);
        }
    }

    fclose(file);  // 원본 파일을 닫습니다.
    fclose(temp);  // 임시 파일을 닫습니다.

    // 원본 파일을 삭제하고 임시 파일을 원본 파일로 이름을 변경합니다.
    remove(INPUT_FILE);
    rename(TEMP_FILE, INPUT_FILE);
}

// 특정 명령어의 값을 읽어오는 함수
int* readValuesForCommand(const char *command, int *num_values) {
    FILE *file = fopen(INPUT_FILE, "r");    // 원본 파일을 읽기 모드로 엽니다.
    if (file == NULL) {
        perror("Error opening file");       // 파일 열기 실패 시 에러 메시지를 출력합니다.
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    int found_command = 0; // 명령어가 발견되었는지 여부를 추적합니다.
    *num_values = 0;       // 값의 개수를 초기화합니다.

    // 원본 파일을 한 줄씩 읽으면서 명령어 뒤에 오는 값의 개수를 셉니다.
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, command, strlen(command)) == 0) {
            found_command = 1;     // 명령어가 발견되었음을 표시합니다.
            continue;
        }

        if (found_command) {
            // 현재 줄이 숫자로 시작하면 값의 개수를 셉니다.
            if (isdigit(line[0]) || (line[0] == '-' && isdigit(line[1]))) {
                (*num_values)++;
            } else if (line[0] == '\n') {
                break; // 공백 줄을 만나면 명령어 블록이 끝났음을 표시합니다.
            }
        }
    }

    if (*num_values == 0) {
        printf("No values found for command '%s'.\n", command); // 값이 없는 경우 메시지를 출력합니다.
        fclose(file);  // 파일을 닫습니다.
        return NULL;
    }

    // 값을 저장할 메모리를 할당합니다.
    int *values = (int *)malloc((*num_values) * sizeof(int));
    if (values == NULL) {
        perror("Error allocating memory"); // 메모리 할당 실패 시 에러 메시지를 출력합니다.
        fclose(file);  // 파일을 닫습니다.
        return NULL;
    }

    // 파일 포인터를 처음으로 되돌리고 값을 읽어옵니다.
    fseek(file, 0, SEEK_SET);
    found_command = 0; // 명령어 발견 플래그를 초기화합니다.
    int index = 0;     // 값의 인덱스를 초기화합니다.

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, command, strlen(command)) == 0) {
            found_command = 1; // 명령어가 발견되었음을 표시합니다.
            continue;
        }

        if (found_command) {
            // 현재 줄이 숫자로 시작하면 값을 저장합니다.
            if (isdigit(line[0]) || (line[0] == '-' && isdigit(line[1]))) {
                values[index++] = atoi(line); // 문자열을 정수로 변환하여 저장합니다.
            } else if (line[0] == '\n') {
                break; // 공백 줄을 만나면 명령어 블록이 끝났음을 표시합니다.
            }
        }
    }

    fclose(file);  // 파일을 닫습니다.
    return values; // 읽어온 값을 반환합니다.
}

// 명령어의 값을 출력하는 함수
void printValuesForCommand(const char *command) {
    int num_values;
    int *values = readValuesForCommand(command, &num_values);

    if (values == NULL) {
        return; // 값을 읽어오지 못한 경우 함수를 종료합니다.
    }

    printf("Current values for command '%s':\n", command);
    for (int i = 0; i < num_values; i++) {
        printf("%d\n", values[i]); // 값을 출력합니다.
    }

    free(values); // 할당된 메모리를 해제합니다.
}

// 명령어의 값을 입력받아 파일을 업데이트하는 함수
void processUpdate(const char *command) {
    int num_values;
    int *current_values = readValuesForCommand(command, &num_values);

    if (current_values == NULL) {
        return; // 값을 읽어오지 못한 경우 함수를 종료합니다.
    }

    printf("Current values for command '%s':\n", command);
    for (int i = 0; i < num_values; i++) {
        printf("%d\n", current_values[i]); // 현재 값을 출력합니다.
    }

    int *new_values = (int *)malloc(num_values * sizeof(int));
    if (new_values == NULL) {
        perror("Error allocating memory"); // 메모리 할당 실패 시 에러 메시지를 출력합니다.
        free(current_values); // 할당된 메모리를 해제합니다.
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Enter new values for '%s' (total %d values):\n", command, num_values);
    for (int i = 0; i < num_values; i++) {
        printf("Value %d: ", i + 1);
        if (fgets(line, sizeof(line), stdin) != NULL) {
            new_values[i] = atoi(line); // 입력된 값을 정수로 변환하여 저장합니다.
        }
    }

    updateValuesInFile(command, new_values, num_values); // 파일을 업데이트합니다.
    free(current_values); // 할당된 메모리를 해제합니다.
    free(new_values);     // 할당된 메모리를 해제합니다.
    printf("Values for '%s' have been updated.\n", command);
}

int main() {
    char command[MAX_LINE_LENGTH];

    while (1) {
        printf("Enter the command to update or read (or type 'exit' to quit): ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            perror("Input error"); // 입력 오류 발생 시 에러 메시지를 출력합니다.
            exit(EXIT_FAILURE);   // 프로그램을 종료합니다.
        }

        command[strcspn(command, "\n")] = '\0'; // 개행 문자를 제거합니다.

        if (strcmp(command, "exit") == 0) {
            break; // 'exit'을 입력하면 프로그램을 종료합니다.
        }

        printf("Do you want to read or update the values for '%s'? (r/u): ", command);
        char option_line[MAX_LINE_LENGTH];
        if (fgets(option_line, sizeof(option_line), stdin) == NULL) {
            perror("Input error"); // 입력 오류 발생 시 에러 메시지를 출력합니다.
            exit(EXIT_FAILURE);   // 프로그램을 종료합니다.
        }
        char option = option_line[0];

        if (option == 'r') {
            printValuesForCommand(command); // 값을 읽어 출력합니다.
        } else if (option == 'u') {
            processUpdate(command); // 값을 업데이트합니다.
        } else {
            printf("Invalid option. Please enter 'r' to read or 'u' to update.\n");
        }
    }

    return 0; // 프로그램 종료
}
