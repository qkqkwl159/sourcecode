#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char setnumber(char c){ //반복할 숫자를 int로 변경
    char h = c;

	if(c == '0') h=')';
    else if(c == '1') h='!';	
    else if(c == '2') h='@';
    else if(c == '3') h='#';
    else if(c == '4') h='$';
    else if(c == '5') h='%';
    else if(c == '6') h='`';
    else if(c == '7') h='&';
    else if(c == '8') h='*';
    else if(c == '9') h='(';
    return h;
}

char* rle_encode(const char* str) {
    int len = strlen(str);

    // 예외 처리: 빈 문자열
    if (len == 0) {
        printf("입력된 문자열이 없습니다.\n");
        return NULL;
    }

    char* encoded = (char*)malloc(sizeof(char) * (len * 2 + 1));
    int encoded_index = 0;

		
    char prev = str[0];
		char temp ;
    int count = 1;

    for (int i = 1; i < len; i++) {
			  temp = setnumber(str[i]);
				printf("%c\n",temp);
        if (temp == prev) {
            count++;
        } else {
            encoded_index += sprintf(encoded + encoded_index, "%c%d", prev, count);
            prev = temp;
            count = 1;
        }
    }

    encoded_index += sprintf(encoded + encoded_index, "%c%d", prev, count);
    encoded[encoded_index] = '\0';

    return encoded;
}


int main(){

	FILE *before = fopen("test1_sample.txt", "r");
	//FILE *after = fopen(argv[2], "w");

	char line[1000];
	char temp[1000] = "";
	char temp2[1000] = "";
	char flist[1000] = "";
	int cnt =0 ;
	int firstline = 1;
	int dint = 1;
	char introResult[1000] = "";

	strcat(flist,"@");

 while (fgets(line, 1000, before) != NULL) { 
		 if (strchr(line, '*') != NULL) {
			 cnt++; 
		 }
		 if(cnt == 3){
				char *ptr = strtok(line, ":");

				while (ptr != NULL){

					ptr = strtok(NULL, ":");   
					//데이터가 있는경우 

					if(ptr != NULL){

			//개행문자 제거
						int len = strlen(ptr);
						for(int i = 0; i< len; i++){
							if(ptr[i+1] == '\n'){
								ptr[i] = '\0';
								 
							}
						}
						// 앞뒤 공백 제거
						char *start = ptr;
						char *end = ptr + strlen(ptr) - 1;
						while (start <= end && (*start == ' ' || *start == '\t')) {
								start++;
						}
						while (end >= start && (*end == ' ' || *end == '\t')) {
								end--;
						}

						strcat(temp,start);
						strcat(temp,"#");

					}
		   	}
			}

			if(cnt == 4){
			 if(firstline == 1){
				 firstline = 0;
				 continue;
			 }
				int len = strlen(line);
				for(int i = 0; i< len; i++){
					if(line[i+1] == '\n'){
						line[i] = '\0';
					}
				}
				char *start = line;
				char *end = line + strlen(line) - 1;
				while (start <= end && (*start == ' ' || *start == '\t')) {
						start++;
				}
				while (end >= start && (*end == ' ' || *end == '\t')) {
						end--;
				}
			//	printf("%s\n",line);
				char* result = rle_encode(line);

				strcat(result,"^");
				strcat(introResult,result);
				printf("%s\n", result);
				free(result);

			}
    }
	strcat(flist,temp);
	
	printf("%s\n",flist);
	printf("%s\n",introResult);
	

  fclose(before); 
	return 0;
}

