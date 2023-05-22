#include "CRUD.h"

int createRecruit(Recruit *s, int index){

  printf("\n출발지 입력: ");
	scanf("%s", (s+index) -> depart);
  
	printf("도착지 입력: ");
	scanf("%s", (s+index) -> arrive );
  
	printf("출발날짜 (예, 0522): ");
  scanf("%hd", &(s+index) -> date);
  
	printf("출발시간 (예, 1940): ");
  scanf("%hd", &(s+index) -> time);
  
	while(1){
        printf("모집 인원 (2~4): ");
        
	
	if (!scanf("%hd", &(s+index) -> num)){
		printf("숫자가 아닙니다. ");
	}
        else if((s+index) -> num < 2 || (s+index) -> num > 4) printf("모집 인원은 2~4명이어야 합니다\n");
        else break;
  }

  printf("모집종류 (택시 : T, 카풀 : C): ");
  scanf(" %c", &(s+index) -> type);
  
  (s+index) -> now_num = 1;

  printf("메모(없으면 엔터): ");

  getchar(); // 입력버퍼 지움

  fgets((s+index) -> memo, sizeof((s+index) -> memo), stdin);
  (s+index) -> memo[strlen((s+index) -> memo) -1 ] = '\0';

  while(1){
    printf("비밀번호 (4자리 숫자): ");
    scanf("%hd", &(s+index) -> pw);

    while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 

    if((s+index) -> pw < 1000 || (s+index) -> pw > 9999) printf("비밀번호는 4자리 숫자로 입력해주세요.\n");
    else if(!((s+index) -> pw)) printf("숫자로 입력해주세요.");
    else break;
  }

  return 1;
}

void readRecruit(Recruit s){
  printf("출발지: %s\n", s.depart);
  printf("도착지: %s\n", s.arrive);
  printf("날짜: %04hd\n", s.date);
  printf("시간: %04hd\n", s.time);
  printf("모집 현황(현재 인원 / 목표 인원): %hd / %hd\n", s.now_num, s.num);
  printf("모집 종류(T: 택시, C: 카풀): %c\n", s.type);
  printf("메모 : %s\n", s.memo);
}

int updateRecruit(Recruit *s, int index){
  printf("\n출발지 입력: ");
  scanf("%s", (s+index) -> depart);

  printf("도착지 입력: ");
  scanf("%s", (s+index) -> arrive );

  printf("출발날짜 (예, 0522): ");
  scanf("%04hd", &(s+index) -> date);

  printf("출발시간 (예, 1940): ");
  scanf("%04hd", &(s+index) -> time);
  
  while(1){
        printf("모집 인원 (2~4): ");
        scanf("%hd", &(s+index) -> num);

        if((s+index) -> num < 2 || (s+index) -> num > 4) printf("모집 인원은 2~4명이어야 합니다.\n");
        else break;
  }

  printf("모집종류 (택시 : T, 카풀 : C): ");
  scanf(" %c", &(s+index) -> type);

  getchar(); // 입력버퍼 지움

  (s+index) -> now_num = 1;

  printf("메모(없으면 엔터 입력): ");

  getchar();

  fgets((s+index) -> memo, sizeof((s+index) -> memo), stdin);
  (s+index) -> memo[strlen((s+index) -> memo) -1 ] = '\0';

  while(1){
        printf("비밀번호 (4자리 숫자): ");
        scanf("%hd", &(s+index) -> pw);

        while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 

        if((s+index) -> pw < 1000 || (s+index) -> pw > 9999) printf("비밀번호는 4자리 숫자로 입력해주세요.\n");
        else if(!((s+index) -> pw)) printf("숫자로 입력해주세요.");
        else break;
  }

  return 1;
}

int deleteRecruit(Recruit *s, int index){
  short int password;

  while(1){
    printf("비밀번호 (4자리 숫자): ");
    scanf("%hd", &password );

    while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 

    if((s+index) -> pw != password) printf("비밀번호가 다릅니다.\n");
    else break;
  }

  (s+index) -> date = -1;

  return 1;
}

void saveData(Recruit *s, int index){
    FILE *fp;
    fp = fopen("itaxi.txt", "wt");

    for(int i = 0; i < index; i++){
        if(s[i].date == -1) continue;
        fprintf(fp,"\t%s %s %hd %hd %hd %c %hd %s\n", s[i].depart, s[i].arrive, s[i].date, s[i].time, s[i].num, s[i].type, s[i].now_num, s[i].memo);
    }

    fclose(fp);
    printf("저장됨! \n");
}

int loadData(Recruit *s){
    int i = 0;

    FILE *fp;
    fp = fopen("itaxi.txt", "rt");

    if(fp == NULL){
        printf("=> 파일 없음!\n");
    }

    else{
        for(; i < 20; i++){
            fscanf(fp, "%s", (s[i].depart));
            fgetc(fp);
            if(feof(fp)) break;
            fscanf(fp, "%s", (s[i].arrive));
            fgetc(fp);
            fscanf(fp,"%hd", &(s[i].date));
            fgetc(fp);
            fscanf(fp, "%hd", &(s[i].time));
            fgetc(fp);
            fscanf(fp, "%hd", &(s[i].num));
            fgetc(fp);
            fscanf(fp, "%c", &(s[i].type));
            fgetc(fp);
            fscanf(fp, "%hd", &(s[i].now_num));
            fgetc(fp);
            fgets((s+i) -> memo, sizeof((s+i) -> memo), fp);
            (s + i) -> memo[strlen((s + i) -> memo) - 1] = '\0';
        }

        fclose(fp);
        printf("=> 로딩 성공!\n");
    }

    return i;
}
