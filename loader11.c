#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

int main(){
	int i, j, k;
	char c1, c2;
	char name[100][N];
	char score[100][N];
	char a[100][N];
	char c[100][N];
	char name_comp[N*100];
	char ans;
	FILE *ofp;
	FILE *ifp;
	FILE *ofp2;
	FILE *ifp2;
	ofp = fopen("sokoban", "a"); 
	ifp = fopen("sokoban", "r");
	ofp2 = fopen("sokoban2", "a");
	ifp2 = fopen("sokoban2", "r");
	if (ifp == NULL){
		printf("입력 파일을 읽을 수 없습니다.\n");
		return 0;
	}

	printf("이름 : ");
	scanf("%s", name_comp);
	i=0;
	int m=0;
	int l=0;
	while (1){
		if (feof(ifp) != 0){
			break;
		}
		fscanf(ifp, "%s", name[i]);
		fscanf(ifp, "%s", score[i]);
		printf("%s\n", name[i]);
		printf("%s\n", score[i]);
		fprintf(ofp2, "%s\n", name[i]);
		k = strcmp(name[i], name_comp);

		if (k == 0){
			printf("존재하는 이름입니다. 이어하시겠습니까?\n (y:이어하기, n:덮어쓰기, x:취소)\n");
			scanf("%c", &ans);
			l = 1;
			if (ans == 'y'){
				fprintf(ofp2, "%s\n", score[i]);
			}
			if (ans == 'n'){
			}
			if (ans == 'x'){
				return 0;
			}
		}
			
		fprintf(ofp2, "%s\n", score[i]);
		i++;
		if (l)
			m++;
	}

	if (ans == 'n'){
		printf("이름은 : %s\n", name[i]);
		printf("점수 : ");
		scanf("%s", score[i]);
		printf("점수는 : %s\n", score[i]);
		i++;
		while (feof(ifp) == 0){
			fscanf(ifp, "%s", name[i]);
			fscanf(ifp, "%s", score[i]);
			fprintf(ofp2, "%s", name[i]);
			fprintf(ofp2, "%s", score[i]);
			i++;
		}
	}
	else{
	i = i-m;
	printf("이름은 : %s\n", name[i]);
	printf("점수는 : %s\n", score[i]);
	}
	fclose(ifp);
	fclose(ofp);
	
}
