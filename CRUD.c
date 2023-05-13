#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CRUD.h"

int createRecruit(Recruit *s){
  printf("\n출발지 입력 ");
	scanf(" %[^\n]s", s->depart);
  
	printf("도착지 입력 ");
	scanf(" %[^\n]s", s->arrive );
  
	printf("출발날짜 (예, 0326) ");
  scanf("%hd", &s->date);
  
	printf("출발시간 (예, 1940) ");
  scanf("%hd", &s->time);
  
	while(1){
        printf("모집 인원 (2~4): ");
        scanf("%hd", &s->num);
        if(s->num < 2 || s->num > 4) printf("모집 인원은 2~4명이어야 합니다\n");
        else break;
  }

  printf("모집종류 (택시 : T, 카풀 : C) ");
  scanf(" %c", &s->type);
  
  s->now_num = 1;

  printf("메모: ");
  fgets(s -> memo, sizeof(s -> memo), stdin);
  s -> memo[strlen((s) -> memo) -1 ] = '\0';

	while(1){
        printf("비밀번호 (4자리 숫자): ");
        scanf("%hd", &s->pw);
        while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 
        if(s->pw < 0 || s->pw > 4) printf("비밀번호는 4자리 숫자로 입력해주세요.\n");
        else if(!(s->pw)) printf("숫자로 입력해주세요.");
        else break;
  }

  printf("=> 추가됨!\n");
  return 1;
}

void readRecruit(Recruit s){
  printf("%s -> %s %04hd %04hd %hd/%hd %c\n", s.depart,s.arrive,s.date,s.time,s.now_num,s.num,s.type);
}

int updateRecruit(Recruit *s){
  printf("\n출발지 입력 ");
  scanf(" %[^\n]s", s->depart);

  printf("도착지 입력 ");
  scanf(" %[^\n]s", s->arrive );

  printf("출발날짜 (예, 0326) ");
  scanf("%hd", &s->date);

  printf("출발시간 (예, 1940) ");
  scanf("%hd", &s->time);

  printf("모집인원 (2~4) ");
  scanf("%hd", &s->num);
  
  while(1){
        printf("모집 인원 (2~4): ");
        scanf("%hd", &s->num);
        if(s->num < 2 || s->num > 4) printf("모집 인원은 2~4명이어야 합니다.\n");
        else break;
  }

  printf("모집종류 (택시 : T, 카풀 : C) ");
  scanf(" %c", &s->type);

  while(1){
        printf("비밀번호 (4자리 숫자): ");
        scanf("%hd", &s->pw);
        while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 
        if(s->pw < 0 || s->pw > 4) printf("비밀번호는 4자리 숫자로 입력해주세요.\n");
        else if(!(s->pw)) printf("숫자로 입력해주세요.");
        else break;
  }

  printf("=> 수정됨!\n");
  return 1;
}

int deleteRecruit(Recruit *s, int index){
  short int password;
  while(1){
        printf("비밀번호 (4자리 숫자): ");
        scanf("%hd", &password );
        while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 
        if(s->pw != password) printf("비밀번호가 다릅니다.\n");
        else break;
  }
  (s + index) -> date = -1;
  return 1;
}
