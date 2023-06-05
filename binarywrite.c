#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _User{
		char id[255];
		char age[255];
		char HP[255];
		double xp, yp;
		char* friend[255];
}User;

int main() {
    FILE* file; 
    char input[100] = "TEST";
		int menu = 0;
    
    // 파일 열기
    file = fopen("userdata.bin", "ab");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.");
        return 1;
    }

		while(1){
			printf("1. 플레이어 정보 기록\n");
			printf("2. 플레이어 정보 확인\n");
			printf("3. 종료\n");
			printf("입력하세요>");

			scanf("%d",&menu);


			if(menu == 1){
				User u1;
				int cnt = 0;
				char* con;
				
				printf("ID를 입력하세요: ");
				scanf("%s",u1.id);
				printf("나이를 입력하세요: ");
				scanf("%s",u1.age);
				printf("HP를 입력하세요: ");
				scanf("%s",u1.HP);
				printf("X좌표를 입력하세요: ");
				scanf("%lf",&u1.xp);
				printf("Y좌표를 입력하세요: ");
				scanf("%lf",&u1.yp);
				while(1){
					printf("동맹 ID를 입력하세요:");
					scanf("%s",u1.friend[cnt++]);
					printf("동맹을 계속 추가할까요?:");
					scanf("%s",con);
					if(!strcmp(con,"Y")) break;
				}
				break;
			}
			if(menu == 2){
				printf("2\n");
			}
			if(menu == 3){
				return 0;
			}
		}
    // 사용자로부터 입력 받기

    // 파일에 데이터 쓰기
    fwrite(input, sizeof(char), sizeof(input), file);

    // 파일 닫기
    fclose(file);

    printf("파일 쓰기가 완료되었습니다.\n");

    return 0;
}

