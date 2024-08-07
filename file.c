#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INPUT_FILE "hardkey_event"  // 입력 파일의 이름 정의
#define TEMP_FILE "hardkey_event.tmp"  // 임시 파일의 이름 정의
#define MAX_LINE_LENGTH 256  // 파일에서 읽을 한 줄의 최대 길이
#define MAX_VALUES 5  // 최대 값 개수

// CommandInfo 구조체 정의
typedef struct {
    const char *command;  // 명령어 문자열
    int num_values;  // 명령어에 관련된 값의 개수
} CommandInfo;

// 가능한 명령어와 해당 값의 개수 정의
CommandInfo commands[] = {
    {"IGNITION", 1},
    {"HORN", 1},
    {"HEADLIGHTS", 1},
    {"TURN_SIGNALS", 1},
    {"WINDSHIELD_WIPERS", 1},
    {"HAZARD_LIGHTS", 1},
    {"CRUISE_CONTROL", 2},
    {"RADIO_VOLUME", 1},
    {"RADIO_TUNING", 1},
    {"RADIO_SOURCE", 1},
    {"CLIMATE_TEMP", 1},
    {"CLIMATE_FAN", 1},
    {"CLIMATE_AIRFLOW", 1},
    {"DEFROST", 1},
    {"POWER_WINDOWS", 2},
    {"WINDOW_LOCK", 1},
    {"DOOR_LOCKS", 1},
    {"MIRROR_ADJUST", 2},
    {"SEAT_ADJUST", 3},
    {"SUNROOF_CONTROL", 1},
    {"TRUNK_RELEASE", 1},
    {"FUEL_CAP_RELEASE", 1},
    {"PARKING_BRAKE", 1},
    {"DRIVE_MODE", 1},
    {"TRACTION_CONTROL", 1},
    {"HEATED_SEATS", 2},
    {"COOLED_SEATS", 2},
    {"STEERING_ADJUST", 1},
    {"INTERIOR_LIGHT", 1},
    {"REAR_DEFROST", 1},
    {"CHILD_LOCK", 1},
    {"MUTE_BUTTON", 1},
    {"VOICE_COMMAND", 1},
    {"PHONE_ANSWER", 1},
    {"PHONE_END_CALL", 1},
    {"NAVIGATION", 2},
    {"LANE_ASSIST", 1},
    {"PARKING_ASSIST", 1},
    {"HILL_DESCENT", 1},
    {"HUD_ADJUST", 1},
    {"GLOVE_BOX_RELEASE", 1},
    {"FOG_LIGHTS", 1},
    {"EMERGENCY_BRAKE", 1},
    {"TRAILER_CONTROL", 1},
    {"AUTO_HOLD", 1},
    {"HANDS_FREE", 1},
    {"SEAT_HEATER", 2},
    {"SEAT_COOLER", 2}
};

#define NUM_COMMANDS (sizeof(commands) / sizeof(commands[0]))  // 명령어 배열의 총 개수

// 파일에서 명령어와 값을 읽어오는 함수
int readValuesFromFile(const char *command, int *values, int max_values) {
    FILE *file = fopen(INPUT_FILE, "r");
    if (file == NULL) {
        perror("Error opening file");  // 파일 열기 오류 처리
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int found_command = 0;
    int num_read_values = 0;

    // 파일의 각 줄을 읽어오는 루프
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;  // 줄 끝의 개행 문자 제거

        if (found_command && isdigit(line[0])) {
            values[num_read_values] = atoi(line);  // 문자열을 정수로 변환
            num_read_values++;
            if (num_read_values >= max_values) {
                break;  // 최대 값 개수에 도달하면 종료
            }
        }
        if (strcmp(line, command) == 0) {
            found_command = 1;  // 명령어 찾음
        } else if (!isdigit(line[0])) {
            found_command = 0;  // 명령어가 아니면 초기화
        }
    }

    fclose(file);
    return num_read_values;
}

// 파일에 명령어와 값을 작성 또는 업데이트하는 함수
void writeOrUpdateValueToFile(const char *command, int *values, int num_values) {
    FILE *file = fopen(INPUT_FILE, "r");
    if (file == NULL) {
        perror("Error opening file");  // 파일 열기 오류 처리
        return;
    }

    FILE *tempFile = fopen(TEMP_FILE, "w");
    if (tempFile == NULL) {
        perror("Error creating temporary file");  // 임시 파일 생성 오류 처리
        fclose(file);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int found_command = 0;
    int command_updated = 0;

    // 파일의 각 줄을 읽어오는 루프
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;  // 줄 끝의 개행 문자 제거

        if (strcmp(line, command) == 0) {
            found_command = 1;
            fprintf(tempFile, "%s\n", line);
            for (int i = 0; i < num_values; ++i) {
                fprintf(tempFile, "%d\n", values[i]);  // 새 값 작성
            }
            fprintf(tempFile, "   // Updated values\n");
            command_updated = 1;
            continue;
        }

        if (found_command && isdigit(line[0])) {
            while (fgets(line, sizeof(line), file) && isdigit(line[0])) {
                // 이전 값 건너뛰기
            }
            if (line) {
                fprintf(tempFile, "%s\n", line);
            }
            found_command = 0;
            continue;
        }

        fprintf(tempFile, "%s\n", line);  // 원본 파일의 나머지 내용 작성
    }

    if (!command_updated) {
        fprintf(tempFile, "%s\n", command);
        for (int i = 0; i < num_values; ++i) {
            fprintf(tempFile, "%d\n", values[i]);  // 새 명령어 및 값 추가
        }
        fprintf(tempFile, "   // Updated values\n");
    }

    fclose(file);
    fclose(tempFile);

    // 원본 파일 삭제 및 임시 파일로 대체
    if (remove(INPUT_FILE) != 0) {
        perror("Error deleting original file");
        return;
    }

    if (rename(TEMP_FILE, INPUT_FILE) != 0) {
        perror("Error renaming temporary file");
    }
}

// 파일에서 명령어의 현재 값을 출력하는 함수
void printCurrentValues(const char *command, int num_values) {
    int current_values[MAX_VALUES];
    int num_read_values = readValuesFromFile(command, current_values, num_values);
    if (num_read_values > 0) {
        printf("Current values for '%s': ", command);
        for (int i = 0; i < num_read_values; ++i) {
            printf("%d ", current_values[i]);
        }
        printf("\n");
    } else {
        printf("No values found for '%s'.\n", command);
    }
}

// 명령어 값을 업데이트하는 함수
void handleUpdateCommand() {
    char command[256];
    printf("Enter the command to update (e.g., 'IGNITION'): ");
    fgets(command, sizeof(command), stdin);

    size_t len = strlen(command);
    if (len > 0 && command[len - 1] == '\n') {
        command[len - 1] = '\0';  // 개행 문자 제거
    }

    int num_values = 0;
    int values[MAX_VALUES];
    int command_found = 0;

    // 명령어가 유효한지 확인
    for (int i = 0; i < NUM_COMMANDS; ++i) {
        if (strcmp(commands[i].command, command) == 0) {
            num_values = commands[i].num_values;
            command_found = 1;
            break;
        }
    }

    if (!command_found) {
        printf("Command not found.\n");
        return;
    }

    // 사용자로부터 값 입력 받기
    printf("Enter %d value(s):\n", num_values);
    for (int i = 0; i < num_values; ++i) {
        printf("Value %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    writeOrUpdateValueToFile(command, values, num_values);
    printf("Values updated successfully.\n");
}

int handlefiles() {
    char action;
    // 초기 테스트용으로 "IGNITION" 명령어를 업데이트
    int values[] = {3};  // 값 배열 정의
    writeOrUpdateValueToFile("IGNITION", values, 1);  // 배열의 주소를 전달
    printCurrentValues("IGNITION", 1);

    while (1) {
        printf("Enter 'r' to read a command's values, 'u' to update values, or 'q' to quit: ");

        int result = scanf(" %c", &action);
        if (result != 1) {
            printf("Failed to read input. Exiting...\n");
            return 1;
        }

        while (getchar() != '\n');

        if (action == 'r') {
            char command[256];
            printf("Enter the command to read (e.g., 'IGNITION'): ");
            fgets(command, sizeof(command), stdin);

            size_t len = strlen(command);
            if (len > 0 && command[len - 1] == '\n') {
                command[len - 1] = '\0';  // 개행 문자 제거
            }

            int num_values = 0;
            for (int i = 0; i < NUM_COMMANDS; ++i) {
                if (strcmp(commands[i].command, command) == 0) {
                    num_values = commands[i].num_values;
                    break;
                }
            }

            if (num_values > 0) {
                printCurrentValues(command, num_values);
            } else {
                printf("Command not found.\n");
            }
        } else if (action == 'u') {
            handleUpdateCommand();
        } else if (action == 'q') {
            printf("Quitting...\n");
            break;
        } else {
            printf("Invalid option. Please enter 'r', 'u', or 'q'.\n");
        }
    }

    return 0;
}