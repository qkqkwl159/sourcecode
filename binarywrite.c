#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _User{
		char id[255];
		char age[255];
		char HP[255];
		char xp[100];
		char yp[100];
		char* friend[255];
		char buffer[255];
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
				int cnt = 1;
				char con[10];
				
				printf("ID를 입력하세요: ");
				scanf("%s",u1.id);
				strcat(u1.id,",");
				strcpy(u1.buffer,u1.id);

				printf("%s\n",u1.buffer);

				printf("나이를 입력하세요: ");
				scanf("%s",u1.age);
				strcat(u1.age,",");
				strcat(u1.buffer,u1.age);

				printf("%s\n",u1.buffer);

				printf("HP를 입력하세요: ");
				scanf("%s",u1.HP);
				strcat(u1.HP,",");
				strcat(u1.buffer,u1.HP);

				printf("%s\n",u1.buffer);

				printf("X좌표를 입력하세요: ");
				scanf("%s",u1.xp);
				strcat(u1.xp,",");
				strcat(u1.buffer,u1.xp);

				printf("%s\n",u1.buffer);

				printf("Y좌표를 입력하세요: ");
				scanf("%s",u1.yp);
				strcat(u1.yp,",");
				strcat(u1.buffer,u1.yp);

				printf("%s\n",u1.buffer);

//				while(1){
//					printf("동맹 ID를 입력하세요:");
//					scanf("%s",u1.friend[cnt++]);
//					strcat(u1.friend[cnt],",");
//					strcat(u1.buffer,u1.friend[cnt]);
//
//					printf("동맹을 계속 추가할까요?:");
//					scanf("%s",con);
//					if(!strcmp(con,"N")) break;
//				}
				fwrite(&u1.buffer, sizeof(u1.buffer),1,file);

				break;
			}
			if(menu == 2){
				FILE* file = fopen("userdata.bin", "rb"); // 읽기 모드로 바이너리 파일 열기

				if (file == NULL) {
						printf("파일을 열 수 없습니다.\n");
						return 1;
				}

				// 파일 내용 읽기
				User data;

				while (fread(&data, sizeof(data), 1, file) == 1) {
						// 데이터 파싱 및 출력
						printf("ID: %s\n", data.id);
						printf("Age: %s\n", data.age);
						printf("HP: %s\n", data.HP);
						printf("XP: %s\n", data.xp);
						printf("YP: %s\n", data.yp);
						printf("\n");
				}
				// 파일 닫기
				fclose(file);
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

