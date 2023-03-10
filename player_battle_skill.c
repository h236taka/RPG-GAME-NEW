#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>
#include "rpg.h"

//敵と味方のスキルに関する機能

int player_ability(Player *****st, Player *****st2, Player *****st3, P_skill *****player_skill, int use_skill_count, int skill_target, int skill_user){
  int recover_point, base, beforehp;

  if ( use_skill_count == 1 ){

    //skill使用者
    if ( skill_user == 1 ){
      printf("%s>>ケディア\n", (****st) -> name);
      sleep(1);

      if ( (****st) -> mp < 3 ){
        printf("MP不足!\n");
      }
      else{
        (****st) -> mp -= 3;

        base = 25;
        recover_point = (rand() % ( base + (****st) -> magic * 3 + (****st) -> luk - base + 1) ) + base; //(rand()%(max - min + 1)) + min;

        if ( skill_target == 1 ){
          beforehp = (****st) -> hp;

          (****st) -> hp += recover_point;
          if ( (****st) -> hp >= (****st) -> maxhp ){
            (****st) -> hp = (****st) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (****st) -> name, beforehp, (****st) -> maxhp, (****st) -> hp, (****st) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == 2 ){
          beforehp = (****st2) -> hp;

          (****st2) -> hp += recover_point;
          if ( (****st2) -> hp >= (****st2) -> maxhp ){
            (****st2) -> hp = (****st2) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (****st2) -> name, beforehp, (****st2) -> maxhp, (****st2) -> hp, (****st2) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == 3 ){
          beforehp = (****st3) -> hp;

          (****st3) -> hp += recover_point;
          if ( (****st3) -> hp >= (****st3) -> maxhp ){
            (****st3) -> hp = (****st3) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (****st3) -> name, beforehp, (****st3) -> maxhp, (****st3) -> hp, (****st3) -> maxhp);
          printf("\n");
        }

      }
    }
    else if ( skill_user == 2 ){
      printf("%s>>ケディア\n", (****st2) -> name);
      sleep(1);

      if ( (****st2) -> mp < 3 ){
        printf("MP不足!\n");
      }
      else{
        (****st2) -> mp -= 3;

        base = 25;
        recover_point = (rand() % ( base + (****st2) -> magic * 3 + (****st2) -> luk - base + 1) ) + base; //(rand()%(max - min + 1)) + min;

        if ( skill_target == 1 ){
          beforehp = (****st) -> hp;

          (****st) -> hp += recover_point;
          if ( (****st) -> hp >= (****st) -> maxhp ){
            (****st) -> hp = (****st) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (****st) -> name, beforehp, (****st) -> maxhp, (****st) -> hp, (****st) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == 2 ){
          beforehp = (****st2) -> hp;

          (****st2) -> hp += recover_point;
          if ( (****st2) -> hp >= (****st2) -> maxhp ){
            (****st2) -> hp = (****st2) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (****st2) -> name, beforehp, (****st2) -> maxhp, (****st2) -> hp, (****st2) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == 3 ){
          beforehp = (****st3) -> hp;

          (****st3) -> hp += recover_point;
          if ( (****st3) -> hp >= (****st3) -> maxhp ){
            (****st3) -> hp = (****st3) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (****st3) -> name, beforehp, (****st3) -> maxhp, (****st3) -> hp, (****st3) -> maxhp);
          printf("\n");
        }

      }
    }
    else if ( skill_user == 3 ){
      printf("%s>>ケディア\n", (****st3) -> name);
      sleep(1);

      if ( (****st3) -> mp < 3 ){
        printf("MP不足!\n");
      }
      else{
        (****st3) -> mp -= 3;

        base = 25;
        recover_point = (rand() % ( base + (****st3) -> magic * 3 + (****st3) -> luk - base + 1) ) + base; //(rand()%(max - min + 1)) + min;

        if ( skill_target == 1 ){
          beforehp = (****st) -> hp;

          (****st) -> hp += recover_point;
          if ( (****st) -> hp >= (****st) -> maxhp ){
            (****st) -> hp = (****st) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (****st) -> name, beforehp, (****st) -> maxhp, (****st) -> hp, (****st) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == 2 ){
          beforehp = (****st2) -> hp;

          (****st2) -> hp += recover_point;
          if ( (****st2) -> hp >= (****st2) -> maxhp ){
            (****st2) -> hp = (****st2) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (****st2) -> name, beforehp, (****st2) -> maxhp, (****st2) -> hp, (****st2) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == 3 ){
          beforehp = (****st3) -> hp;

          (****st3) -> hp += recover_point;
          if ( (****st3) -> hp >= (****st3) -> maxhp ){
            (****st3) -> hp = (****st3) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (****st3) -> name, beforehp, (****st3) -> maxhp, (****st3) -> hp, (****st3) -> maxhp);
          printf("\n");
        }

      }
    }

  }
  else if ( use_skill_count == 2 ){  //キュアポ
    //skill使用者
    if ( skill_user == 1 ){
      printf("%s>>キュアポ\n", (****st) -> name);
      sleep(1);

      if ( (****st) -> mp < 4 ){
        printf("MP不足!\n");
      }
      else{
        (****st) -> mp -= 4;

        if ( skill_target == 1 ){
          if ( (****st) -> badstatus == POISON ){
            (****st) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (****st) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }
        else if ( skill_target == 2 ){
          if ( (****st2) -> badstatus == POISON ){
            (****st2) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (****st2) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }
        else if ( skill_target == 3 ){
          if ( (****st3) -> badstatus == POISON ){
            (****st3) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (****st3) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }

      }
    }
    else if ( skill_user == 2 ){
      printf("%s>>キュアポ\n", (****st2) -> name);
      sleep(1);

      if ( (****st2) -> mp < 4 ){
        printf("MP不足!\n");
      }
      else{
        (****st2) -> mp -= 4;

        if ( skill_target == 1 ){
          if ( (****st) -> badstatus == POISON ){
            (****st) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (****st) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }
        else if ( skill_target == 2 ){
          if ( (****st2) -> badstatus == POISON ){
            (****st2) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (****st2) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }
        else if ( skill_target == 3 ){
          if ( (****st3) -> badstatus == POISON ){
            (****st3) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (****st3) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }

      }
    }
    else if ( skill_user == 3 ){
      printf("%s>>キュアポ\n", (****st3) -> name);
      sleep(1);

      if ( (****st3) -> mp < 4 ){
        printf("MP不足!\n");
      }
      else{
        (****st3) -> mp -= 4;

        if ( skill_target == 1 ){
          if ( (****st) -> badstatus == POISON ){
            (****st) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (****st) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }
        else if ( skill_target == 2 ){
          if ( (****st2) -> badstatus == POISON ){
            (****st2) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (****st2) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }
        else if ( skill_target == 3 ){
          if ( (****st3) -> badstatus == POISON ){
            (****st3) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (****st3) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }

      }
    }
  }

}

int skill_target_select(Player *****st, Player *****st2, Player *****st3, int use_skill_count){
  int skill_target;
  int command;

  do{
    printf("使用する対象を選択してください(使用しない場合はcを入力)\n");
    if ( (****st) -> badstatus == DEAD ){
      //nothing
    }
    else{
      printf("1:%s ", (****st) -> name);
    }

    if ( (****st2) -> badstatus == DEAD ){
      //nothing
    }
    else{
      printf("2:%s ", (****st2) -> name);
    }

    if ( (****st3) -> badstatus == DEAD ){
      //nothing
    }
    else{
      printf("3:%s ", (****st3) -> name);
    }
    printf("\n");

    command =  _getch();
    if ( command == '1' ){
      if ( (****st) -> badstatus == DEAD ){
        command = 'e';  //error
      }
      else{
        skill_target = 1;
      }
    }
    else if ( command == '2' ){
      if ( (****st2) -> badstatus == DEAD ){
        command = 'e';
      }
      else{
        skill_target = 2;
      }
    }
    else if ( command == '3' ){
      if ( (****st3) -> badstatus == DEAD ){
        command = 'e';
      }
      else{
        skill_target = 3;
      }
    }
    else if ( command == 'c' ){
      skill_target = 0;
    }
  }while ( command != '1' && command != '2' && command != '3' && command != 'c' );


  return skill_target;
}

int use_player_skill(Player ****st, Player ****st2, Player ****st3, P_skill ****player_skill, Setting_skill ****setting_skill, int skill_command, int skill_user){
  int use_skill_count, skill_target;

  use_skill_count = 0;
  if ( skill_command == '0' ){
    use_skill_count = (***setting_skill) -> set_skill[0];

  }
  else if ( skill_command == '1' ){
    use_skill_count = (***setting_skill) -> set_skill[1];
  }
  else if ( skill_command == '2' ){
    use_skill_count = (***setting_skill) -> set_skill[2];
  }
  else if ( skill_command == '3' ){
    use_skill_count = (***setting_skill) -> set_skill[3];
  }
  else if ( skill_command == '4' ){
    use_skill_count = (***setting_skill) -> set_skill[4];
  }
  else if ( skill_command == '5' ){
    use_skill_count = (***setting_skill) -> set_skill[5];
  }
  else if ( skill_command == '6' ){
    use_skill_count = (***setting_skill) -> set_skill[6];
  }
  else if ( skill_command == '7' ){
    use_skill_count = (***setting_skill) -> set_skill[7];
  }
  else if ( skill_command == '8' ){
    use_skill_count = (***setting_skill) -> set_skill[8];
  }
  else if ( skill_command == '9' ){
    use_skill_count = (***setting_skill) -> set_skill[9];
  }
  else{
    printf("スキル選択でエラーが発生しました...\n");
    return NOPLAYER;
  }

  if ( use_skill_count == RECOVER1 || use_skill_count == CUREPOISON ){
    skill_target = skill_target_select(&st, &st2, &st3, use_skill_count);
  }

  if ( skill_target != NOPLAYER ){
    player_ability(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
  }

  return skill_target;
}

int check_skillID(Setting_skill *****setting_skill, int idx){

  if ( (****setting_skill) -> set_skill[idx] == RECOVER1 ){
    printf("%d:ケディア 消費MP:3 (味方1人のHP小回復)\n", idx);
  }
  else if ( (****setting_skill) -> set_skill[idx] == CUREPOISON ){
    printf("%d:キュアポ 消費MP:4 (味方1人のPOISON状態を回復)\n", idx);
  }

}

int battle_player_skill_list(P_skill ****player_skill, Setting_skill ****setting_skill){
  int skill_count;

  skill_count = 0;
  printf("<<<<<<SKILL>>>>>>\n");
  for ( int i = 0; i < 10; i++ ){
    if ( (***setting_skill) -> set_skill[i] != 0 ){
      check_skillID(&setting_skill,i);
      skill_count = 1;
    }
  }


  if ( skill_count == 0 ){
    printf("使用可能なSKILLはありません!\n");
  }

  return skill_count;
}
