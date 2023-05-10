#include <stdio.h>
#include <stdlib.h>

int main(void){
  Recruit *sp[20];
  int count = 0, menu; //count : 데이터 개수
  int index = 0; // 데이터 번호


  while (1){
    menu = selectMenu();
    if (menu == 0){
      int exitok;
      printf("\n=> 종료하시겠습니까? (종료 : 0) ");
      scanf("%d",&exitok);
      if(exitok == 0) break;
    }
    if (menu == 1){
      if (count > 0)
        listRecruit(sp, index);
    }
    else if (menu == 2){
      sp[index]=(Recruit*)malloc(sizeof(Recruit));
      count += addRecruit(sp[index++]);
    }
    else if (menu == 3){
      int no = selectDataNo(sp, index);
      if(no == 0){
        printf("취소됨!");
        continue;
      }
      updateRecruit(sp[no-1]);
    }
    else if (menu == 4){
      int no = selectDataNo(sp, index);
      if(no == 0){
        printf("취소됨!");
        continue;
      }
      int deleteok;
      printf("정말로 삭제하시겠습니까?(삭제 :1) ");
      scanf("%d",&deleteok);
      if(deleteok == 1){
        if(sp[no-1]) free(sp[no-1]);
        sp[no-1] = NULL;
          count--;
      }
    }
    else if (menu == 5){
      int no = selectDataNo(sp, index);
      if(no == 0){
        printf("취소됨!");
        continue;
      }
      if(joinRecruit(sp[no-1]) == 1)
        printf("=> 모집에 참여되었습니다.\n");
    }
    else if (menu == 6){
      int no = selectDataNo(sp, index);
      if(no == 0){
        printf("취소됨!");
        continue;
      }
      if(exitjoinRecruit(sp[no-1]) == 1)
        printf("=> 모집에서 나갔습니다.\n");
    }
    else return 0;
  }
  printf("종료됨!\n");
  return 0;
}
