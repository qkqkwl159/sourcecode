#include <stdio.h>

int main() {
    FILE* file;
    char input[100];
    
    // 파일 열기
    file = fopen("userdata.bin", "wb");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.");
        return 1;
    }

    // 사용자로부터 입력 받기
    printf("파일에 저장할 데이터를 입력하세요: ");
    scanf("%s", input);

    // 파일에 데이터 쓰기
    fwrite(input, sizeof(char), sizeof(input), file);

    // 파일 닫기
    fclose(file);

    printf("파일 쓰기가 완료되었습니다.\n");

    return 0;
}

