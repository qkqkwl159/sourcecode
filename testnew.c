#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compressRLE(const char* str) {
    int length = strlen(str);
    char* compressed = (char*)malloc(sizeof(char) * (length * 2 + 1));  // 최대 길이의 2배 크기로 메모리 할당

    int count = 1;
    int index = 0;
    for (int i = 1; i <= length; i++) {
        if (str[i] == str[i - 1]) {
            count++;
        } else {
            compressed[index++] = count + '0';  // 반복 횟수를 문자로 변환하여 저장
            compressed[index++] = str[i - 1];   // 반복되는 문자 저장
            count = 1;
        }
    }

    compressed[index] = '\0';  // 문자열 종료 문자 추가

    return compressed;
}

int main() {
    const char* data[] = {
        "AABBBAADDEEGAGG11",
        "AAAABBCBBCBBC",
        "HELLO",
        "AAABBBAADDEEGAGG22",
        "AAAABBCBBCBBC",
        "AAABBBAADDEEGAGG33",
        "AAAABBCBBCBBC",
        "HELLO",
        "ZZKKZZKKKKKK",
        "AAABBBAADDEEGAGG",
        "BBCBBCBBCBBCBBC"
    };

    int dataSize = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < dataSize; i++) {
        const char* str = data[i];
        char* compressed = compressRLE(str);
        printf("Original: %s\n", str);
        printf("Compressed: %s\n\n", compressed);
        free(compressed);  // 동적 할당된 메모리 해제
    }

    return 0;
}

