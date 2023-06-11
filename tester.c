#include <stdio.h>
#include <string.h>

void rle_encode(const char* str) {
    int len = strlen(str);
    
    // 예외 처리: 빈 문자열
    if (len == 0) {
        printf("입력된 문자열이 없습니다.\n");
        return;
    }
    
    char prev = str[0];
    int count = 1;
    
    for (int i = 1; i < len; i++) {
        if (str[i] == prev) {
            count++;
        } else {
            printf("%c%d", prev, count);
            prev = str[i];
            count = 1;
        }
    }
    
    // 마지막 문자 처리
    printf("%c%d\n", prev, count);
}

int main() {
    char str1[] = "AABBBAADDEEGAGG11";
    char str2[] = "AAAABBCBBCBBC";
    char str3[] = "HELLO";
    char str4[] = "AAABBBAADDEEGAGG22";
    char str5[] = "AAAABBCBBCBBC";
    char str6[] = "AAABBBAADDEEGAGG33";
    char str7[] = "AAAABBCBBCBBC";
    char str8[] = "HELLO";
    char str9[] = "ZZKKZZKKKKKK";
    char str10[] = "AAABBBAADDEEGAGG";
    char str11[] = "BBCBBCBBCBBCBBC";
    
    printf("압축 결과:\n");
    rle_encode(str1);
    rle_encode(str2);
    rle_encode(str3);
    rle_encode(str4);
    rle_encode(str5);
    rle_encode(str6);
    rle_encode(str7);
    rle_encode(str8);
    rle_encode(str9);
    rle_encode(str10);
    rle_encode(str11);
    
    return 0;
}

