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
  getchar(); // 입력버퍼 지움
  fgets(s -> memo, sizeof(s -> memo), stdin);
  s -> memo[strlen((s) -> memo) -1 ] = '\0';

	while(1){
        printf("비밀번호 (4자리 숫자): ");
        scanf("%hd", &s->pw);
        while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 
        if(s->pw < 1000 || s->pw > 9999) printf("비밀번호는 4자리 숫자로 입력해주세요.\n");
        else if(!(s->pw)) printf("숫자로 입력해주세요.");
        else break;
  }

  printf("=> 추가됨!\n");
  return 1;
}

void readRecruit(Recruit s){
  printf("%s -> %s %04hd %04hd %hd/%hd %c\n", s.depart,s.arrive,s.date,s.time,s.now_num,s.num,s.type);
  printf("메모 : %s\n", s.memo);
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

/*
// extra.c
int selectMenu(){ // 메뉴 선택
    int menu;
    printf("\n*** iTaxi ***\n");
    printf("1. 조회 ");
    printf("2. 모집 ");
    printf("3. 모집정보수정 ");
    printf("4. 모집삭제 ");
    printf("5. 모집참여 ");
    printf("6. 모집참여취소 ");
    printf("7. 출발지->도착지검색 ");
    printf("8. 출발날짜검색 ");
    printf("0. 종료 >> ");
    scanf("%d", &menu);
    return menu;
}

void listRecruit(Recruit *s[], int count){ // 모집 리스트 출력
  printf("\nNo 출발지 -> 도착지 출발날짜 출발시간 모집현황 모집종류\n");
  printf("======================================================\n");
  for(int i=0; i<count; i++){
    if(s[i] == NULL) continue;
    printf("%d  ",i+1);
    readRecruit(*s[i]);
  }
}

int selectDataNo(Recruit *s[], int count){ // 데이터 번호 선택
  int no;
  listRecruit(s,count);
  printf("\n번호는 (취소 :0)? ");
  scanf("%d",&no);
  return no;
}

int joinRecruit(Recruit *s){ // 모집 참여
  int joinok;
  if(s->now_num == s->num){
    printf("이미 마감된 모집입니다.\n");
    return 0;
  }
  printf("해당 모집에 참여하시겠습니까?(참여 :1) ");
  scanf("%d",&joinok);
  if(joinok == 1){
    s->now_num++;
    return 1;
  }
  return 0;
}

int exitjoinRecruit(Recruit *s){ // 모집 참여 취소 
  int exitjoinok;
  if(s->now_num == 1){
    printf("해당 모집에 참여하지 않으셨습니다.\n");
    return 0;
  }
  printf("해당 모집에서 나가시시겠습니까?(참여 :1) ");
  scanf("%d",&exitjoinok);
  if(exitjoinok == 1){
    s->now_num--;
    return 1;
  }
  return 0;
}

void searchPlace(Recruit *s[], int count){
  int scnt = 0;
  char search_d[20];
  char search_a[20];
  printf("출발지를 입력하세요. ");
    scanf("%s", search_d);
  printf("도착지를 입력하세요. ");
    scanf("%s", search_a);
    printf("\nNo 출발지 -> 도착지 출발날짜 출발시간 모집현황 모집종류\n");
    printf("======================================================\n");
  for(int i =0; i <count ; i++){
    if(s[i]->type == -1) continue;
    if(strstr(s[i]->depart, search_d) && strstr(s[i]->depart, search_a)){
      printf("%2d ", i+1);
      readRecruit(*s[i]);
      scnt++;
    }
  }
  if(scnt == 0) printf("=> 검색된 데이터 없음!");
  printf("\n");
}

void searchDay(Recruit *s[], int count){
  int scnt = 0;
  short int search;
  printf("출발날짜를 입력하세요. ");
    scanf("%hd", &search);
    printf("\nNo 출발지 -> 도착지 출발날짜 출발시간 모집현황 모집종류\n");
    printf("======================================================\n");
  for(int i =0; i <count ; i++){
    if(s[i]->type == -1) continue;
    if(s[i]->date == search){
      printf("%2d ", i+1);
      readRecruit(*s[i]);
      scnt++;
    }
  }
  if(scnt == 0) printf("=> 검색된 데이터 없음!");
  printf("\n");
}
*/