#include "extra.h"

int selectMenu_main(){ // 메인화면 메뉴 선택
    int main0;
    
    printf("\n");
    printf("     +--------------+\n");
    printf("     |              |\n");
    printf(" +---+    ITAXI     +---+\n");
    printf(" |                      |  == ** *\n");
    printf(" +----------------------+\n");
    printf("     ***         ***\n");
    printf("\n");
    printf("\n*** iTaxi Menu***\n");
    printf("\n");
    
    printf("1. 조회\n");
    printf("2. 모집\n");
    printf("3. 저장\n");
    printf("0. 종료\n");
    printf("\n원하는 메뉴는? ");
    scanf("%d", &main0);

    while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 
  
    if(!(main0 >= 0)) printf("숫자로 입력해주세요.\n");
    else if(main0 > 3 || main0 < 0) printf("메뉴 안에 있는 숫자로 입력 바랍니다.\n");
    
    return main0;
}

int selectMenu1(){ // 조회 메뉴 선택
    int menu1;
    
    printf("\n***조회***\n");
    printf("1. 모집조회\n");
    printf("2. 모집참여\n");
    printf("3. 모집참여취소\n");
    printf("4. 장소검색\n");
    printf("5. 시간검색\n");
    printf("0. 뒤로가기\n");
    printf("\n원하는 메뉴는? ");
    scanf("%d", &menu1);

    while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 

    if(!(menu1 >= 0)) printf("=>숫자로 입력해주세요.\n");
    else if(menu1 > 5 || menu1 < 0) printf("=>메뉴 안에 있는 숫자로 입력 바랍니다.\n");

    return menu1;
}

int selectMenu2(){ // 모집 메뉴 선택
    int menu2;
    
    printf("\n***모집***\n");
    printf("1. 모집글 작성\n");
    printf("2. 모집정보수정\n");
    printf("3. 모집삭제\n");
    printf("4. 메모 추가\n");
    printf("0. 뒤로가기\n");
    printf("\n원하는 메뉴는? ");
    scanf("%d", &menu2);

    while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 

    if(!(menu2 >= 0 )) printf("=>숫자로 입력해주세요.\n");
    else if(menu2 > 4 || menu2 < -1) printf("=>메뉴 안에 있는 숫자로 입력 바랍니다.\n");
    
    
    return menu2;
}

void listRecruit(Recruit *s, int index){ // 모집 리스트 출력
    printf("=============================\n");
    printf("\n");

    for(int i = 0; i < index; i++){
        if(s[i].date == -1) continue;
        printf("NO.%2d\n", i+1);
        printf("\n");
        readRecruit(s[i]);
        printf("\n");
        printf("=============================\n");
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

int joinRecruit(Recruit *s, int index){ // 모집 참여
  int joinok;

  if((s+index) -> now_num == (s+index) -> num){
    printf("이미 마감된 모집입니다.\n");
    return 0;
  }

  printf("해당 모집에 참여하시겠습니까?(참여: 1): ");
  scanf("%d", &joinok);

  if(joinok == 1){
    (s+index) -> now_num++;
    return 1;
  }

  return 0;
}

int exitjoinRecruit(Recruit *s, int index){ // 모집 참여 취소 
  int exitjoinok;

  if((s+index) -> now_num == 1){
    printf("해당 모집에 참여하지 않으셨습니다.\n");
    return 0;
  }

  printf("해당 모집에서 나가시시겠습니까?(참여: 1):  ");
  scanf("%d", &exitjoinok);

  if(exitjoinok == 1){
    (s+index) -> now_num--;
    return 1;
  }

  return 0;
}

void searchPlace(Recruit *s, int index){

    int scnt = 0;
    char depart[20];
    char arrive[20];

    printf("검색 할 출발지: ");
    scanf("%s", depart);

    printf("검색 할 도착지: ");
    scanf("%s", arrive);
    
    printf("=========================\n");
    printf("\n");

    for(int i = 0; i < index; i++){
        if(s[i].date == -1) continue;

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

    printf("검색할 날짜 (예, 0522): ");
    scanf("%hd", &search);
    
    printf("=========================\n");
    printf("\n");

    for(int i = 0; i < count; i++){
        if(s[i].date == -1) continue;

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

void updateMemo(Recruit *s, int index){
    getchar();

    char newmemo[50];

    printf("new memo? ");
    fgets(newmemo, sizeof(newmemo), stdin);
    newmemo[strlen(newmemo) - 1] = '\0';

    char newmemo_with_space[strlen(newmemo) + 3];

    strcpy(newmemo_with_space, "");  // 초기화

    if(strlen(s[index].memo) != 0)
      strcpy(newmemo_with_space, ", ");
  
    strcat(newmemo_with_space, newmemo);

    strcat(s[index].memo, newmemo_with_space);
}