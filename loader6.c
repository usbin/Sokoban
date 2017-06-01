#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

char score2[N];
int main(){
	int i, j, k;
	char c1, c2;
	char name[N] = {};
	char score[N];
	char a[100][N];
	char c[100][N];
	char name_comp[N*100];
	char ans;
	FILE *ofp;
	FILE *ifp;
	FILE *ofp2;
	ofp = fopen("sokoban", "a"); 
	ifp = fopen("sokoban", "r");
	printf("이름을 입력하세요 : ");
	i = 0;
	if (ifp == NULL){
		printf("입력 파일을 읽을 수 없습니다.\n");
		return 0;
	}

	while (1){
		c1 = getchar();
		if ((c1 == ' ') || i == N){
			while ((c1=getchar()) != '\n')
			;	
			printf("이름을 다시 입력하세요 : ");
			i=0;
			continue;
		}
		if (c1 == '\n' || c1 == EOF){
			name[i++] = '\0';
			break;
		}
		name[i++] = c1;
	}
	fflush(stdin);
	i=0;
	while (1){
		fscanf(ifp, "%s", name_comp);
		k = strcmp(name, name_comp);

		if (k == 0){
			printf("존재하는 이름입니다. 이어하시겠습니까?\n(y:이어하기, n:덮어쓰기, x:취소)\n");
			scanf("%c", &ans);
			break;
		}
			
		
		if (feof(ifp) != 0)
			break;
	}




	if (k != 0 ){
		printf("점수를 입력하세요 : ");
		scanf("%s", &score);

		fprintf(ofp, "%s\n", name);
		fprintf(ofp, "%s\n", score);
	}
	if (ans == 'y'){
		fscanf(ifp, "%s", score);
			
	}

	if (ans == 'n'){
		i = 0;
		j = 0;
		int i1=0, i2=0;
		fclose(ifp);
		fclose(ofp);
		ifp = fopen("sokoban", "r+");
		ofp = fopen("sokoban", "a");
		while (1){
			fscanf(ifp, "%s", name_comp);
			k = strcmp(name, name_comp);

			if (k == 0){
				char c = '0';
				fscanf(ifp, "%s", score2);
				fclose(ifp);
				printf("score = %s\n", score2);    //printf
				ifp = fopen("sokoban", "r+");
				i = strlen(score2);
				int k2;
				while (k2==0){
					fscanf(ifp, "%s", name_comp);
					k2 = strcmp(name, name_comp);
				}
				/*while (c != '\n'){
					printf("c != 들어옴\n");   //printf
					printf("score = %s\n", score2);
					c = score2[i];
					printf("c = %c\n", c);
					i++;
					printf("i = %d\n", i);   //printf
				}
				printf("c != 나옴\n");  //printf
				printf("c = %c\n", c);  //printf
				*/
				char nu = '\b';
				char r = 'a';
				fprintf(ifp, "%c", r);
				for (; i>=0; i--){
					fprintf(ifp, "%c", nu);
				}
				
				break;
			}
		}
		/*
		while (feof(ifp) == 0){
			while (a[j][i1] != '\n'){
				fscanf(ifp, "%c", a[j][i1]);
				i1++;
			}
			a[j][i1+1] = '\0';
			
			printf("i1 = %d\n", i1);
			while (c[j][i2] != '\n'){
				fscanf(ifp, "%c", c[j][i2]);
				i2++;
			}
			c[j][i2+1] = '\0';
			j++;
			printf("i2 = %d\n", i2);
		}
		fprintf(ofp2, "%c", a[0][0]);
		int m = 0;
		for(m=0;m<=j;m++){
			int l=0, n=0;
			while (a[m][l-1] != '\0'){
				fprintf(ofp, "%c", a[m][l]);
				l++;
			}
			while (c[m][n-1] != '\0'){
				fprintf(ofp, "%c", c[m][n]);
				n++;
			}

		}
		*/
	}
	printf("%s", score2);	
	printf("이름은 : %s\n", name);
	if (ans == 'n')
		printf("점수는 : %s\n", score2);
	else
		printf("점수는 : %s\n", score);
		
	fclose(ifp);
	fclose(ofp);
	fclose(ofp2);
	
}
