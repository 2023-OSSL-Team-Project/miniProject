#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "extra.h"

int main(void){
  Recruit *sp[20];
  int count = 0, main0, menu1, menu2; //count : 데이터 개수
  int index = 0; // 데이터 번호

  while (1){
    main0 = selectMenu_main();
    if (main0 == 0){
      int exitok;
      printf("\n=> 종료하시겠습니까? (종료 : 0) ");
      scanf("%d",&exitok);
      if(exitok == 0) break;
    }
    
    else if (main0 == 1){
      while (1){
        menu1 = selectMenu1();
        if (menu1 == 1){
          if (count > 0)
            listRecruit(sp[0], index);
          else
            printf("=> 조회된 데이터 없음!\n");
        }

        else if (menu1 == 2){
          int no = selectDataNo(sp[0], index);

          if(no == 0){
            printf("취소됨!");
            break;
          }

          if(joinRecruit(sp[no-1]) == 1)
            printf("=> 모집에 참여되었습니다.\n");
        }

        else if (menu1 == 3){
          int no = selectDataNo(sp[0], index);

          if(no == 0){
            printf("취소됨!");
            continue;
          }

          if(exitjoinRecruit(sp[no-1]) == 1)
            printf("=> 모집에서 나갔습니다.\n");
        }

        else if (menu1 == 7){
          searchPlace(sp[0], index);
        }

        else if (menu1 == 8){
          searchDay(sp[0], index);
        }

        else if (menu1 == 0){
          continue;
        }

        else return 0;
      }
    }

    else if (main0 == 2){
      while (1){
        menu2 = selectMenu2();

        if (menu2 == 1){
          sp[index]=(Recruit*)malloc(sizeof(Recruit));
          count += createRecruit(sp[0], index);

          if(&sp[0] == NULL){
            exit(1);
          }

          printf("=> 추가됨!\n");
          index++;
        }

        else if (menu2 == 2){
          int no = selectDataNo(sp[0], index);

          if(no == 0){
            printf("취소됨!");
            continue;
          }

          int a = updateRecruit(sp[0], no-1);
          if(a == 1) printf("=> 수정성공!\n");
        }

        else if (menu2 == 3){
          int no = selectDataNo(sp[0], index);
          int deleteok;

          if(no == 0){
            printf("취소됨!");
            continue;
          }

          printf("정말로 삭제하시겠습니까?(삭제 :1) ");
          scanf("%d",&deleteok);

          if(deleteok == 1){
            count -= deleteRecruit(sp[0], no-1);
            sp[no-1] = NULL;
            printf("\n");
            printf("=> 삭제됨!\n");
          }
        }

        else if(menu2 == 4){
          int no = selectDataNo(sp[0], index);
          updateMemo(sp[0], no - 1);
          printf("\n");
          printf("=> 저장됨!!\n");
        }

        else if (menu2 == 0){
          break;
        }

        else return 0;
      }
    }
  }
}
