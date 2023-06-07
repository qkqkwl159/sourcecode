#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
#define LENGTH 50

int main(){


	FILE *before = fopen("test1_sample.txt", "r");
	//FILE *after = fopen(argv[2], "w");

	char line[1000];
	char temp[1000] = "";
	char flist[1000] = "";
	int cnt =0 ;
	int firstline = 1; //항목 제외 를위한 조건 변수ㅐ
	int datacheck = 1;
	int dint = 1;

	strcat(flist,"@");
	printf("%s\n",flist);


	 while (fgets(line, 1000, before) != NULL) { 
		 if (strchr(line, '*') != NULL) {
			 cnt++; 
		 }
		 if(cnt == 3){
				if(firstline == 1){
					firstline = 0;
					continue;
				}
				char *ptr = strtok(line, ":");
				while (ptr != NULL){
					ptr = strtok(NULL, ":");   
					//데이터가 있는경우 
					if(ptr != NULL){

						//개행문자 제거
						char *data = strchr(ptr, '\n');
						if(data != NULL){
							*data = '\0';
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
						*(end + 1) = '\0';

						strcat(temp,start);
						printf("%s\n",temp);


					}
				}
			}
    }
	

  fclose(before); 
	return 0;
}

