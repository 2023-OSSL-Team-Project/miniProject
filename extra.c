#include "extra.h"

int selectMenu_main(){ // 메인화면 메뉴 선택
    int main0;

    printf("1. 조회\n");
    printf("2. 모집\n");
    printf("0. 종료\n");
    printf("\n원하는 메뉴는? ");
    scanf("%d", &main0);
}

int selectMenu1(){ // 조회 메뉴 선택
    int manu1;

    printf("1. 모집조회\n");
    printf("2. 모집참여\n");
    printf("3. 모집참여취소\n");
    printf("4. 장소검색\n");
    printf("5. 시간검색\n");
    printf("0. 뒤로가기\n");
    printf("\n원하는 메뉴는? ");
    scanf("%d", &manu1);
}

int selectMenu2(){ // 모집 메뉴 선택
    int manu2;

    printf("1. 모집글 작성\n");
    printf("2. 모집정보수정\n");
    printf("3. 모집삭제\n");
    printf("0. 뒤로가기\n");
    printf("\n원하는 메뉴는? ");
    scanf("%d", &manu2);
}

void listRecruit(Recruit *s, int index){ // 모집 리스트 출력
    printf("=========================\n");
    printf("\n");
    for(int i = 0; i < index; i++){
        //if(s[i].date == -1) continue;
        printf("NO.%2d\n", i+1);
        printf("\n");
        readRecruit(s[i]);
        printf("\n");
        printf("=========================\n");
        printf("\n");
    }
}

int selectDataNo(Recruit *s, int index){ // 데이터 번호 선택
  int no;

  listRecruit(s,index);

  while(1){
    printf("\n번호는 (취소 :0)? ");
    scanf("%d",&no);
    if(no >= 0 || no < index) break;
  }
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

void searchPlace(Recruit *s, int index){

    int scnt = 0;
    char depart[20];
    char arrive[20];

    printf("검색할 출발지 ");
    scanf("%s", depart);

    printf("검색할 도착지 ");
    scanf("%s", arrive);
    
    printf("=========================\n");
    printf("\n");

    for(int i = 0; i < index; i++){
        if(s[i].date== -1) continue;

        if((strstr(s[i].depart, depart)) && (strstr(s[i].arrive, arrive))){     
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

void updateMemo(Recruit *sp, int index){
    getchar();

    char newmemo[20];

    printf("new memo? ");
    fgets(newmemo, sizeof(newmemo), stdin);
    newmemo[strlen(newmemo)-1] = '\0';

    char newmemo_with_space[strlen(newmemo) + 1];
    strcpy(newmemo_with_space, ", ");
    strcat(newmemo_with_space, newmemo);

    strcat(sp[index].memo, newmemo_with_space);
}
