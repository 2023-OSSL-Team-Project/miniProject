#include "extra.h"

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

void listRecruit(Recruit *s, int count){ // 모집 리스트 출력
  printf("\nNo 출발지 -> 도착지 출발날짜 출발시간 모집현황 모집종류\n");
  printf("======================================================\n");
  for(int i=0; i<count; i++){
    if(s[i].date == -1) continue;
    printf("%d  ",i+1);
    readRecruit(s[i]);
  }
}

int selectDataNo(Recruit *s, int count){ // 데이터 번호 선택
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

void searchPlace(Recruit *s, int count){

    int scnt = 0;
    char depart[20];
    char arrive[20];

    printf("검색할 출발지 ");
    scanf("%s", depart);

    printf("검색할 도착지 ");
    scanf("%s", arrive);
    
    printf("=========================\n");
    printf("\n");

    for(int i = 0; i < count; i++){
        if(s[i].date== -1) continue;

        if(strstr(s[i].depart, depart) && strstr(s[i].arrive, arrive)){     
            printf("NO.%2d\n", i+1);
            printf("\n");
            readRecruit(s[i]);
            printf("\n");
            printf("=========================\n");
            printf("\n");
            scnt++;
        }
    }

    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void searchDay(Recruit *s, int count){

    int scnt = 0;
    short int search;

    printf("검색할 날짜 (예, 0326) ");
    scanf("%hd", &search);
    
    printf("=========================\n");
    printf("\n");

    for(int i = 0; i < count; i++){
        if(s[i].date== -1) continue;

        if(s[i].date == search){     
            printf("NO.%2d\n", i+1);
            printf("\n");
            readRecruit(s[i]);
            printf("\n");
            printf("=========================\n");
            printf("\n");
            scnt++;
        }
    }

    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
