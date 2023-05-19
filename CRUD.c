#include "CRUD.h"

int createRecruit(Recruit *s, int i){
  printf("\n출발지 입력: ");
	scanf("%s", (s+i)->depart);
  
	printf("도착지 입력: ");
	scanf("%s", (s+i)->arrive );
  
	printf("출발날짜 (예, 0522): ");
  scanf("%hd", &(s+i)->date);
  
	printf("출발시간 (예, 1940): ₩1");
  scanf("%hd", &(s+i)->time);
  
	while(1){
        printf("모집 인원 (2~4): ");
        scanf("%hd", &(s+i)->num);
        if((s+i)->num < 2 || (s+i)->num > 4) printf("모집 인원은 2~4명이어야 합니다\n");
        else break;
  }

  printf("모집종류 (택시 : T, 카풀 : C: ");
  scanf(" %c", &s->type);
  
  s->now_num = 1;

  printf("메모(없으면 0입력): ");
  getchar(); // 입력버퍼 지움
  fgets((s+i)-> memo, sizeof((s+i) -> memo), stdin);
  (s+i) -> memo[strlen((s+i) -> memo) -1 ] = '\0';

  while(1){
        printf("비밀번호 (4자리 숫자): ");
        scanf("%hd", &(s+i)->pw);
        while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 
        if((s+i)->pw < 1000 || (s+i)->pw > 9999) printf("비밀번호는 4자리 숫자로 입력해주세요.\n");
        else if(!((s+i)->pw)) printf("숫자로 입력해주세요.");
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

int updateRecruit(Recruit *s, int i){
  printf("\n출발지 입력: ");
  scanf("%s", (s+i)->depart);

  printf("도착지 입력: ");
  scanf("%s", (s+i)->arrive );

  printf("출발날짜 (예, 0522): ");
  scanf("%04hd", &(s+i)->date);

  printf("출발시간 (예, 1940): ");
  scanf("%04hd", &(s+i)->time);
  
  while(1){
        printf("모집 인원 (2~4): ");
        scanf("%hd", &(s+i)->num);
        if((s+i)->num < 2 || (s+i)->num > 4) printf("모집 인원은 2~4명이어야 합니다.\n");
        else break;
  }

  printf("모집종류 (택시 : T, 카풀 : C): ");
  scanf(" %c", &(s+i)->type);

  s->now_num = 1;

  printf("메모(없으면 엔터 입력): ");
  getchar(); // 입력버퍼 지움
  fgets((s+i)-> memo, sizeof((s+i) -> memo), stdin);
  (s+i) -> memo[strlen((s+i) -> memo) -1 ] = '\0';

  while(1){
        printf("비밀번호 (4자리 숫자): ");
        scanf("%hd", &(s+i)->pw);
        while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 
        if((s+i)->pw < 1000 || (s+i)->pw > 9999) printf("비밀번호는 4자리 숫자로 입력해주세요.\n");
        else if(!((s+i)->pw)) printf("숫자로 입력해주세요.");
        else break;
  }

  return 1;
}

int deleteRecruit(Recruit *s, int i){
  short int password;

  while(1){
        printf("비밀번호 (4자리 숫자): ");
        scanf("%hd", &password );
        while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 
        if(s->pw != password) printf("비밀번호가 다릅니다.\n");
        else break;
  }
  if(s+i) free(s+i);

  return 1;
}