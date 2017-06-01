#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

int main(){
	int i, j, k;
	int ty, tn, ts;
	char c1, c2;
	char name[100][N];
	char score[100][N];
	char a[100][N];
	char c[100][N];
	char name_comp[N];
	char trash[N];
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
	i=0;
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
			name_comp[i++] = '\0';
			break;
		}
		name_comp[i++] = c1;
	}

	i=0;
	while (1){
		if (feof(ifp) != 0)
			break;
				
		fscanf(ifp, "%s\n", name[i]);
		fscanf(ifp, "%s\n", score[i]);
		fprintf(ofp2, "%s\n", name[i]);

		k = strcmp(name[i], name_comp);

		if (k == 0){
			printf("존재하는 이름입니다. 이어하시겠습니까?\n(y:이어하기, n:덮어쓰기, x:취소)\n");
			scanf("%c", &ans);
			break;
		}
		fprintf(ofp2, "%s\n", score[i]);
		i++;
			
		
	}



	if (k != 0 ){
		printf("점수를 입력하세요 : ");
		scanf("%s", &score[i]);
		fprintf(ofp2, "%s\n", name_comp);
		fprintf(ofp2, "%s\n", score[i]);
	}

	if (ans == 'y'){
		ty = i;
		fprintf(ofp2, "%s\n", score[i++]);
	}

	if (ans == 'n'){
		j = 0;
		printf("점수 : ");
		scanf("%s", score[i]);
		tn = i;
		fprintf(ofp2, "%s\n", score[i]);
		i++;
	}

	if (k == 0){		

		while (1){
			if (feof(ifp) != 0)
				break;
			fscanf(ifp, "%s", name[i]);
			if (feof(ifp) != 0)
				break;
			fprintf(ofp2, "%s\n", name[i]);
			if (feof(ifp) != 0)
				break;
			fscanf(ifp, "%s", score[i]);
			if (feof(ifp) != 0)
				break;
			fprintf(ofp2, "%s\n", score[i]);
			if (feof(ifp) != 0)
				break;
			i++;
		}
	}

		
	if (ans != 'x')				
		printf("이름은 : %s\n", name_comp);
   if (ans == 'n')
		printf("점수는 : %s\n", score[tn]);
	if (ans == 'y')
		printf("점수는 : %s\n", score[ty]);
	if (k != 0)
		printf("점수는 : %s\n", score[i]);
	fclose(ifp);
	fclose(ofp);
	fclose(ifp2);
	fclose(ofp2);
	int asd = 1;
	/*
	for (i=0; i<5; i++){
		printf("name : %s\n", name[i]);
		printf("score : %s\n", score[i]);
	}
	*/	
	if (asd == 1){
		char mover[N];
		FILE *ofpfir;
		ofp = fopen("sokoban", "a"); 
		ofpfir = fopen("sokoban", "w");
		ifp = fopen("sokoban", "r");
		ofp2 = fopen("sokoban2", "a");
		ifp2 = fopen("sokoban2", "r");
		fscanf(ifp2, "%s", mover);
		fprintf(ofp, "%s\n", mover);
		printf("mover : %s\n", mover);
		while (1){
			fscanf(ifp2, "%s", mover);
			if (feof(ifp2) != 0)
				break;
			fprintf(ofp, "%s\n", mover);
			if (feof(ifp2) != 0)
				break;
			printf("mover : %s\n", mover);
			if (feof(ifp2) != 0)
				break;
		}
		fclose(ifp);
		fclose(ofp);
		fclose(ifp2);
		fclose(ofp2);
		fclose(ofpfir);
		char so[N] = "sokoban2";
		remove(so);
	}		
}
