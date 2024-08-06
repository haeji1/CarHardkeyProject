//
// Created by MinseokK on 24. 8. 6.
//
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <unistd.h> // For sleep function (POSIX)
// #include <time.h>   // For time functions
// #include "observer.h"
//
//
// #define INPUT_FILE "hardkey_event"  // 파일 이름을 정의
// #define MAX_LINE_LENGTH 256        // 한 줄의 최대 길이를 정의
//
//
// #define MAX_COMMAND_LENGTH 50
//
// // Define a structure to handle commands
// typedef struct {
//     char command[MAX_LINE_LENGTH];
//     void (*handler)(int);
// } CommandHandler;
//
// // Function prototypes for processing commands
// void processIgnition(int state);
// void processHorn(int signal);
// void processHeadlights(int state);
//
// // Function prototypes for command handlers
// void processIgnitionHandler(int value);
// void processHornHandler(int value);
// void processHeadlightsHandler(int value);
//
// // Function prototypes for registering, unregistering, and executing commands
// void registerCommand(const char *command, void (*handler)(int));
// void unregisterCommand(const char *command);
// void executeCommand(const char *command);
//
//
// // Function to write or update value to the file
// void writeOrUpdateValueToFile(HardKey key, int value) {
//         // 파일을 읽기 및 쓰기 모드로 열기
//         int new_value;
//         FILE *file = fopen(INPUT_FILE, "r+");
//         if (file == NULL) {
//             perror("Error opening file");  // 파일 열기 오류 출력
//             return;
//         }
//
//         char line[MAX_LINE_LENGTH];  // 파일에서 읽은 한 줄을 저장할 배열
//         int found = 0;               // 명령어를 찾았는지 여부를 나타내는 플래그
//         long int pos = -1;           // 명령어가 발견된 위치를 저장할 변수
//
//         // 파일을 한 줄씩 읽으면서 명령어와 값을 찾기
//         while (fgets(line, sizeof(line), file)) {
//             // 현재 줄이 명령어와 일치하는지 확인
//             if (strcmp(line, key) == 0) {
//                 found = 1;               // 명령어를 찾았으므로 플래그를 설정
//                 pos = ftell(file);       // 명령어 위치를 저장
//                 continue;                // 다음 줄로 넘어감
//             }
//
//             // 명령어를 찾았고 현재 줄이 숫자로 시작하는지 확인
//             if (found && isdigit(line[0])) {
//                 fseek(file, pos, SEEK_SET);  // 명령어 위치로 파일 포인터를 되돌림
//                 fprintf(file, "%d   // Updated value\n", new_value); // 새 값을 파일에 작성
//                 fflush(file);  // 파일의 변경 사항을 디스크에 기록
//                 break;         // 작업 완료 후 루프 종료
//             }
//         }
//
//         fclose(file);  // 파일 닫기
//     }
//
