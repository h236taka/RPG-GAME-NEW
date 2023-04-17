#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>
#include "rpg.h"

//敵と味方のスキルに関する機能
int check_playerMP(Player *****st, int skillMP){

  if ( (****st) -> mp < skillMP ){
    printf("MP不足!\n");
    return FALSE;
  }
  else{
    (****st) -> mp -= skillMP;
    return TRUE;
  }

}

void skillEffect_RECOVER1_forBattle(Player *****st, Player *****st2, Player *****st3, int skill_target, int recover_point){
  int beforehp;

  if ( skill_target == PLAYER ){
    beforehp = (****st) -> hp;

    (****st) -> hp += recover_point;
    if ( (****st) -> hp >= (****st) -> maxhp ){
      (****st) -> hp = (****st) -> maxhp;
    }

    printf("%s: HP:%d/%d >> HP:%d/%d\n", (****st) -> name, beforehp, (****st) -> maxhp, (****st) -> hp, (****st) -> maxhp);
    printf("\n");
  }
  else if ( skill_target == PLAYER2 ){
    beforehp = (****st2) -> hp;

    (****st2) -> hp += recover_point;
    if ( (****st2) -> hp >= (****st2) -> maxhp ){
      (****st2) -> hp = (****st2) -> maxhp;
    }

    printf("%s: HP:%d/%d >> HP:%d/%d\n", (****st2) -> name, beforehp, (****st2) -> maxhp, (****st2) -> hp, (****st2) -> maxhp);
    printf("\n");
  }
  else if ( skill_target == PLAYER3 ){
    beforehp = (****st3) -> hp;

    (****st3) -> hp += recover_point;
    if ( (****st3) -> hp >= (****st3) -> maxhp ){
      (****st3) -> hp = (****st3) -> maxhp;
    }

    printf("%s: HP:%d/%d >> HP:%d/%d\n", (****st3) -> name, beforehp, (****st3) -> maxhp, (****st3) -> hp, (****st3) -> maxhp);
    printf("\n");
  }
}

void skillEffect_CUREPOISON_forBattle(Player *****st, Player *****st2, Player *****st3, int skill_target){

  if ( skill_target == PLAYER ){
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
  else if ( skill_target == PLAYER2 ){
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
  else if ( skill_target == PLAYER3 ){
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

int player_skill_forParty(Player ****st, Player ****st2, Player ****st3, P_skill ****player_skill, int use_skill_count, int skill_target, int skill_user){
  int turn_decrease;
  int recover_point, base, beforehp;
  int damage;

  if ( use_skill_count == RECOVER1 ){

    //skill使用者
    if ( skill_user == PLAYER ){
      printf("%s>>ケディア\n", (***st) -> name);
      sleep(1);

      if ( check_playerMP(&st,3) == TRUE ){
        base = 25;
        recover_point = (rand() % ( base + (***st) -> magic * 3 + (***st) -> luk - base + 1) ) + base; //(rand()%(max - min + 1)) + min;
        skillEffect_RECOVER1_forBattle(&st,&st2,&st3,skill_target,recover_point);
      }
    }
    else if ( skill_user == PLAYER2 ){
      printf("%s>>ケディア\n", (***st2) -> name);
      sleep(1);

      if ( check_playerMP(&st2,3) == TRUE ){
        base = 25;
        recover_point = (rand() % ( base + (***st2) -> magic * 3 + (***st2) -> luk - base + 1) ) + base; //(rand()%(max - min + 1)) + min;
        skillEffect_RECOVER1_forBattle(&st,&st2,&st3,skill_target,recover_point);
      }
    }
    else if ( skill_user == PLAYER3 ){
      printf("%s>>ケディア\n", (***st3) -> name);
      sleep(1);

      if ( check_playerMP(&st3,3) == TRUE ){
        base = 25;
        recover_point = (rand() % ( base + (***st3) -> magic * 3 + (***st3) -> luk - base + 1) ) + base; //(rand()%(max - min + 1)) + min;
        skillEffect_RECOVER1_forBattle(&st,&st2,&st3,skill_target,recover_point);
      }
    }
  }
  else if ( use_skill_count == CUREPOISON ){  //キュアポ
    //skill使用者
    if ( skill_user == PLAYER ){
      printf("%s>>キュアポ\n", (***st) -> name);
      sleep(1);

      if ( check_playerMP(&st,4) == TRUE ){
        skillEffect_CUREPOISON_forBattle(&st,&st2,&st3,skill_target);
      }
    }
    else if ( skill_user == PLAYER2 ){
      printf("%s>>キュアポ\n", (***st2) -> name);
      sleep(1);

      if ( check_playerMP(&st2,4) == TRUE ){
        skillEffect_CUREPOISON_forBattle(&st,&st2,&st3,skill_target);
      }
    }
    else if ( skill_user == PLAYER3 ){
      printf("%s>>キュアポ\n", (***st3) -> name);
      sleep(1);

      if ( check_playerMP(&st3,4) == TRUE ){
        skillEffect_CUREPOISON_forBattle(&st,&st2,&st3,skill_target);
      }
    }
  }
  else if ( use_skill_count == RECOVER2 ){

  }

  turn_decrease = -1;

  return turn_decrease;
}

int player_skill_forEnemy(Player ****st, P_skill ****player_skill, Enemy **enemy, int use_skill_count){
  int turn_decrease;
  int eva_count, eva_base;
  int magic_power;
  int damage_base, max_damage, temp, damage;

  if ( use_skill_count == ENFA ){
    if ( check_playerMP(&st,4) != TRUE ){
      return -1;
    }

    printf("%s>>エンファ\n", (***st) -> name);
    sleep(1);
    printf("%sは小さな火球を飛ばした!\n", (***st) -> name);
    sleep(1);

    eva_count = 0;
    magic_power = 10;

    if ( (*enemy) -> fire == -1 ){  //火炎攻撃無効
      sleep(1);
      printf("%s<<BLOCK!\n", (*enemy) -> name);

      turn_decrease = -2;
    }
    else if ( (*enemy) -> fire == -2 ){  //火炎攻撃吸収
      damage_base = ( magic_power * (***st) -> magic ) / ( (*enemy) -> magic * 2 );
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      max_damage = damage_base * 1.3;
      damage = (rand() % ( max_damage - damage_base + 1 )) + damage_base;
      temp = damage;
      damage = -2;
      (*enemy) -> hp += temp;
      if ( (*enemy) -> hp > (*enemy) -> maxhp ){
        (*enemy) -> hp = (*enemy) -> maxhp;
      }
      printf("Absorb!\n");
      sleep(1);
      printf("%s<<%dダメージ吸収\n", (*enemy) -> name, temp);
      turn_decrease = -2;
    }
    else if ( (*enemy) -> fire == -3 ){  //火炎攻撃反射
      damage_base = ( magic_power * (***st) -> magic ) / ( (*enemy) -> magic * 2 );
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      max_damage = damage_base * 1.3;
      temp = damage;
      damage = -3;
      (***st) -> hp -= temp;
      printf("Reflect!\n");
      sleep(1);
      printf("%s<<%dダメージ\n", (***st) -> name, temp);
      if ( (***st) -> hp <= 0 ){
        (***st) -> hp = 0;
        (***st) -> badstatus = DEAD;
        printf("%sは倒れた\n", (***st) -> name);
      }
      turn_decrease = -2;
    }
    else{
      damage_base = ( magic_power * (***st) -> magic ) / ( (*enemy) -> magic * 2 );
      //printf("damage_base:%d\n", damage_base);
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      //回避率5%
      eva_base = 5 + ( (*enemy) -> agi * 0.2 ) + ( (*enemy) -> luk * 0.1 ) - ( (***st) -> agi * 0.1) - ( (***st) -> luk * 0.1);   //回避率計算

      eva_base = round(eva_base);

      if ( eva_base < 5 ){
        eva_base = 5;     //回避率最小値5%
      }

      max_damage = damage_base * 1.3;
      damage = (rand() % ( max_damage - damage_base + 1) ) + damage_base; //(rand()%(max - min + 1)) + min;
      //printf("damage:%d\n", damage);
      //printf("damage:%d\n", damage);
      //耐性判断
      if ( (*enemy) -> fire == 100 ){
        damage = damage;
        turn_decrease = -1;
      }
      else if ( (*enemy) -> fire == 150 ){     //火炎攻撃1.5倍
        damage *= 1.5;
        turn_decrease = -1;
      }
      else if ( (*enemy) -> fire == 200 ){
        sleep(1);
        printf("WEAKNESS!!\n");
        damage *= 2;
        turn_decrease = 0.1;
      }
      else if ( (*enemy) -> fire == 80 ){  //火炎攻撃ダメージ80%
        damage *= 0.8;
        turn_decrease = -1;
      }
      else if ( (*enemy) -> fire == 50 ){  //火炎攻撃半減
        sleep(1);
        printf("RESIST!\n");
        damage *= 0.5;
        turn_decrease = -1;
      }
      else if ( (*enemy) -> fire == 25 ){  //火炎攻撃ダメージ25%
        sleep(1);
        printf("RESIST!\n");
        damage *= 0.25;
        turn_decrease = -1;
      }

      if ( damage < 0 ){
        damage = 1;
      }

      if ( damage >= (*enemy) -> hp ){
        sleep(1);
        printf("%s<<%dダメージ\n", (*enemy) -> name, damage);
        sleep(1);
        printf("%sは死んでしまった!\n", (*enemy) -> name);
        (*enemy) -> hp = 0;
        (*enemy) -> badstatus = DEAD;
      }
      else{
        printf("%s<<%dダメージ\n", (*enemy) -> name, damage);
        (*enemy) -> hp -= damage;
        if ( (*enemy) -> hp <= 0 ){
          (*enemy) -> hp = 0;
          (*enemy) -> badstatus = DEAD;
        }
      }

    }

  }

  return turn_decrease;
}

int player_skill_forEnemyCopy(Player ****st, P_skill ****player_skill, Enemy *enemy_copy, int use_skill_count){
  int turn_decrease;
  int eva_count, eva_base;
  int magic_power;
  int damage_base, max_damage, temp, damage;

  if ( use_skill_count == ENFA ){
    if ( check_playerMP(&st,4) != TRUE ){
      return -1;
    }

    printf("%s>>エンファ\n", (***st) -> name);
    sleep(1);
    printf("%sは小さな火球を飛ばした!\n", (***st) -> name);
    sleep(1);

    eva_count = 0;
    magic_power = 10;

    if ( enemy_copy -> fire == -1 ){  //火炎攻撃無効
      sleep(1);
      printf("%s<<BLOCK!\n", enemy_copy -> name);

      turn_decrease = -2;
    }
    else if ( enemy_copy -> fire == -2 ){  //火炎攻撃吸収
      damage_base = ( magic_power * (***st) -> magic ) / ( enemy_copy -> magic * 2 );
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      max_damage = damage_base * 1.3;
      damage = (rand() % ( max_damage - damage_base + 1 )) + damage_base;
      temp = damage;
      damage = -2;
      enemy_copy -> hp += temp;
      if ( enemy_copy -> hp > enemy_copy -> maxhp ){
        enemy_copy -> hp = enemy_copy -> maxhp;
      }
      printf("Absorb!\n");
      sleep(1);
      printf("%s<<%dダメージ吸収\n", enemy_copy -> name, temp);
      turn_decrease = -2;
    }
    else if ( enemy_copy -> fire == -3 ){  //火炎攻撃反射
      damage_base = ( magic_power * (***st) -> magic ) / ( enemy_copy -> magic * 2 );
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      max_damage = damage_base * 1.3;
      temp = damage;
      damage = -3;
      (***st) -> hp -= temp;
      printf("Reflect!\n");
      sleep(1);
      printf("%s<<%dダメージ\n", (***st) -> name, temp);
      if ( (***st) -> hp <= 0 ){
        (***st) -> hp = 0;
        (***st) -> badstatus = DEAD;
        printf("%sは倒れた\n", (***st) -> name);
      }
      turn_decrease = -2;
    }
    else{
      damage_base = ( magic_power * (***st) -> magic ) / ( enemy_copy -> magic * 2 );
      //printf("damage_base:%d\n", damage_base);
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      //回避率5%
      eva_base = 5 + ( enemy_copy -> agi * 0.2 ) + ( enemy_copy -> luk * 0.1 ) - ( (***st) -> agi * 0.1) - ( (***st) -> luk * 0.1);   //回避率計算

      eva_base = round(eva_base);

      if ( eva_base < 5 ){
        eva_base = 5;     //回避率最小値5%
      }

      max_damage = damage_base * 1.3;
      damage = (rand() % ( max_damage - damage_base + 1) ) + damage_base; //(rand()%(max - min + 1)) + min;
      //printf("damage:%d\n", damage);
      //printf("damage:%d\n", damage);
      //耐性判断
      if ( enemy_copy -> fire == 100 ){
        damage = damage;
        turn_decrease = -1;
      }
      else if ( enemy_copy -> fire == 150 ){     //火炎攻撃1.5倍
        damage *= 1.5;
        turn_decrease = -1;
      }
      else if ( enemy_copy -> fire == 200 ){
        sleep(1);
        printf("WEAKNESS!!\n");
        damage *= 2;
        turn_decrease = 0.1;
      }
      else if ( enemy_copy -> fire == 80 ){  //火炎攻撃ダメージ80%
        damage *= 0.8;
        turn_decrease = -1;
      }
      else if ( enemy_copy -> fire == 50 ){  //火炎攻撃半減
        sleep(1);
        printf("RESIST!\n");
        damage *= 0.5;
        turn_decrease = -1;
      }
      else if ( enemy_copy -> fire == 25 ){  //火炎攻撃ダメージ25%
        sleep(1);
        printf("RESIST!\n");
        damage *= 0.25;
        turn_decrease = -1;
      }

      if ( damage < 0 ){
        damage = 1;
      }

      if ( damage >= enemy_copy -> hp ){
        sleep(1);
        printf("%s<<%dダメージ\n", enemy_copy -> name, damage);
        sleep(1);
        printf("%sは死んでしまった!\n", enemy_copy -> name);
        enemy_copy -> hp = 0;
        enemy_copy -> badstatus = DEAD;
      }
      else{
        printf("%s<<%dダメージ\n", enemy_copy -> name, damage);
        enemy_copy -> hp -= damage;
        if ( enemy_copy -> hp <= 0 ){
          enemy_copy -> hp = 0;
          enemy_copy -> badstatus = DEAD;
        }
      }

    }
  }

  return turn_decrease;
}

int select_player_skillTarget(Player ****st, Player ****st2, Player ****st3){
  int skill_target;
  int command;

  do{
    printf("使用する対象を選択してください(使用しない場合はcを入力)\n");
    if ( (***st) -> badstatus == DEAD ){
      //nothing
    }
    else{
      printf("1:%s ", (***st) -> name);
    }

    if ( (***st2) -> badstatus == DEAD ){
      //nothing
    }
    else{
      printf("2:%s ", (***st2) -> name);
    }

    if ( (***st3) -> badstatus == DEAD ){
      //nothing
    }
    else{
      printf("3:%s ", (***st3) -> name);
    }
    printf("\n");

    command =  _getch();
    if ( command == '1' ){
      if ( (***st) -> badstatus == DEAD ){
        command = 'e';  //error
      }
      else{
        skill_target = PLAYER;
      }
    }
    else if ( command == '2' ){
      if ( (***st2) -> badstatus == DEAD ){
        command = 'e';
      }
      else{
        skill_target = PLAYER2;
      }
    }
    else if ( command == '3' ){
      if ( (***st3) -> badstatus == DEAD ){
        command = 'e';
      }
      else{
        skill_target = PLAYER3;
      }
    }
    else if ( command == 'c' ){
      skill_target = NOTARGET;
    }
  }while ( command != '1' && command != '2' && command != '3' && command != 'c' );


  return skill_target;
}

int select_encount_pattern2_skillTarget(Enemy **enemy, Enemy *enemy_copy1){
  int skill_target;
  int command;

  if ( (*enemy) -> badstatus != DEAD && enemy_copy1 -> badstatus != DEAD ){
    printf("対象を選んでください(戻る場合はcを入力してください)\n");
    printf("1.%s 2.%s\n", (*enemy) -> name, enemy_copy1 -> name);
    printf("\n");
    command =  _getch();
    if ( command == 'c' ){
      return NOTARGET;
    }
    else if ( command == '1' ){
      skill_target = ENEMY1;
    }
    else if ( command == '2' ){
      skill_target = ENEMY2;
    }

  }
  if ( (*enemy) -> badstatus != DEAD && enemy_copy1 -> badstatus == DEAD ){
    do {
      printf("対象を選んでください(戻る場合はcを入力してください)\n");
      printf("1.%s\n", (*enemy) -> name);
      printf("\n");
      command =  _getch();
      if ( command == 'c' ){
        return NOTARGET;
      }
      skill_target = ENEMY1;
    } while ( command != '1' );
  }
  if ( (*enemy) -> badstatus == DEAD && enemy_copy1 -> badstatus != DEAD ){
    do {
      printf("対象を選んでください(戻る場合はcを入力してください)\n");
      printf("2.%s\n", enemy_copy1 -> name);
      printf("\n");
      command =  _getch();
      if ( command == 'c' ){
        return NOTARGET;
      }
      skill_target = ENEMY2;
    } while ( command != '2' );
  }

  return skill_target;
}

int select_encount_pattern3_skillTarget(Enemy **enemy, Enemy *enemy_copy1, Enemy *enemy_copy2){
  int skill_target;
  int command;

  if ( (*enemy) -> badstatus != DEAD && enemy_copy1 -> badstatus != DEAD && enemy_copy2 -> badstatus != DEAD ){
    printf("対象を選んでください(戻る場合はcを入力してください)\n");
    printf("1.%s 2.%s 3.%s\n", (*enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
    printf("\n");
    command =  _getch();
    if ( command == 'c' ){
      return NOTARGET;
    }
    else if ( command == '1' ){
      skill_target = ENEMY1;
    }
    else if ( command == '2' ){
      skill_target = ENEMY2;
    }
    else if ( command == '3' ){
      skill_target = ENEMY3;
    }
  }
  if ( (*enemy) -> badstatus != DEAD ){
    if ( enemy_copy1 -> badstatus != DEAD && enemy_copy2 -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s 2.%s\n", (*enemy) -> name, enemy_copy1 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          skill_target = ENEMY1;
        }
        else if ( command == '2' ){
          skill_target = ENEMY2;
        }
      } while ( command != '1' && command != '2' );
    }
    if ( enemy_copy1 -> badstatus == DEAD && enemy_copy2 -> badstatus != DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s 3.%s\n", (*enemy) -> name, enemy_copy2 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          skill_target = ENEMY1;
        }
        else if ( command == '3' ){
          skill_target = ENEMY3;
        }
      } while ( command != '1' && command != '3' );
    }
    if ( enemy_copy1 -> badstatus == DEAD && enemy_copy2 -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s\n", (*enemy) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          skill_target = ENEMY1;
        }
      } while ( command != '1' );
    }
  }
  if ( enemy_copy1 -> badstatus != DEAD ){
    if ( (*enemy) -> badstatus == DEAD && enemy_copy2 -> badstatus != DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("2.%s 3.%s\n", enemy_copy1 -> name, enemy_copy2 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '2' ){
          skill_target = ENEMY2;
        }
        else if ( command == '3' ){
          skill_target = ENEMY3;
        }
      } while ( command != '2' && command != '3' );
    }
    if ( (*enemy) -> badstatus == DEAD && enemy_copy2 -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("2.%s\n", enemy_copy1 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '2' ){
          return ENEMY2;
        }
      } while ( command != '2' );
    }
  }
  if ( enemy_copy2 -> badstatus != DEAD ){
    if ( (*enemy) -> badstatus == DEAD && enemy_copy1 -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("3.%s\n", enemy_copy2 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '3' ){
          skill_target = ENEMY3;
        }
      } while ( command != '3' );
    }
  }

  return skill_target;
}

int select_encount_pattern4_skillTarget(Enemy **enemy, Enemy *enemy_copy1, Enemy *enemy_copy2, Enemy *enemy_copy3){
  int skill_target;
  int command;

  if ( (*enemy) -> badstatus != DEAD && enemy_copy1 -> badstatus != DEAD && enemy_copy2 -> badstatus != DEAD && enemy_copy3 -> badstatus != DEAD ){
    printf("対象を選んでください(戻る場合はcを入力してください)\n");
    printf("1.%s 2.%s 3.%s 4.%s\n", (*enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name, enemy_copy3 -> name);
    printf("\n");
    command =  _getch();
    if ( command == 'c' ){
      return NOTARGET;
    }
    else if ( command == '1' ){
      return ENEMY1;
    }
    else if ( command == '2' ){
      return ENEMY2;
    }
    else if ( command == '3' ){
      return ENEMY3;
    }
    else if ( command == '4' ){
      return ENEMY4;
    }
  }

  if ( (*enemy) -> badstatus != DEAD ){
    if ( enemy_copy1 -> badstatus != DEAD && enemy_copy2 -> badstatus == DEAD && enemy_copy3 -> badstatus != DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s 2.%s 4.%s\n", (*enemy) -> name, enemy_copy1 -> name, enemy_copy3 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          skill_target = ENEMY1;
        }
        else if ( command == '2' ){
          skill_target = ENEMY2;
        }
        else if ( command == '4' ){
          skill_target = ENEMY4;
        }
      } while ( command != '1' && command != '2' && command != '4' );
    }
    if ( enemy_copy1 -> badstatus != DEAD && enemy_copy2 -> badstatus != DEAD && enemy_copy3 -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s 2.%s 3.%s\n", (*enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          skill_target = ENEMY1;
        }
        else if ( command == '2' ){
          skill_target = ENEMY2;
        }
        else if ( command == '3' ){
          skill_target = ENEMY3;
        }
      } while ( command != '1' && command != '2' && command != '3' );
    }
    if ( enemy_copy1 -> badstatus != DEAD && enemy_copy2 -> badstatus == DEAD && enemy_copy3 -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s 2.%s\n", (*enemy) -> name, enemy_copy1 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          skill_target = ENEMY1;
        }
        else if ( command == '2' ){
          skill_target = ENEMY2;
        }
      } while ( command != '1' && command != '2' );
    }
    if ( enemy_copy1 -> badstatus == DEAD && enemy_copy2 -> badstatus == DEAD && enemy_copy3 -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s\n", (*enemy) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          skill_target = ENEMY1;
        }
      } while ( command != '1' );
    }
    if ( enemy_copy1 -> badstatus == DEAD && enemy_copy2 -> badstatus != DEAD && enemy_copy3 -> badstatus != DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s 3.%s 4.%s\n", (*enemy) -> name, enemy_copy2 -> name, enemy_copy3 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          skill_target = ENEMY1;
        }
        else if ( command == '3' ){
          skill_target = ENEMY3;
        }
        else if ( command == '4' ){
          skill_target = ENEMY4;
        }
      } while ( command != '1' && command != '3' && command != '4' );
    }
    if ( enemy_copy1 -> badstatus == DEAD && enemy_copy2 -> badstatus == DEAD && enemy_copy3 -> badstatus != DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s 4.%s\n", (*enemy) -> name, enemy_copy3 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '4' ){
          skill_target = ENEMY4;
        }
      } while ( command != '1' && command != '4' );
    }
  }

  if ( enemy_copy1 -> badstatus != DEAD ){
    if ( (*enemy) -> badstatus == DEAD && enemy_copy2 -> badstatus != DEAD && enemy_copy3 -> badstatus != DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("2.%s 3.%s 4.%s\n", enemy_copy1 -> name, enemy_copy2 -> name, enemy_copy3 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '2' ){
          skill_target = ENEMY2;
        }
        else if ( command == '3' ){
          skill_target = ENEMY3;
        }
        else if ( command == '4' ){
          skill_target = ENEMY4;
        }
      } while ( command != '2' && command != '3' && command != '4' );
    }
    if ( (*enemy) -> badstatus == DEAD && enemy_copy2 -> badstatus != DEAD && enemy_copy3 -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("2.%s 3.%s\n", enemy_copy1 -> name, enemy_copy2 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '2' ){
          skill_target = ENEMY2;
        }
        else if ( command == '3' ){
          skill_target = ENEMY3;
        }
      } while ( command != '2' && command != '3' );
    }
    if ( (*enemy) -> badstatus == DEAD && enemy_copy2 -> badstatus == DEAD && enemy_copy3 -> badstatus != DEAD ){
      do{
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("2.%s 4.%s\n", enemy_copy1 -> name, enemy_copy3 -> name);
        printf("\n");
        command = _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '2' ){
          skill_target = ENEMY2;
        }
        else if ( command == '4' ){
          skill_target = ENEMY4;
        }
      }while( command != '2' && command != '4' );
    }
    if ( (*enemy) -> badstatus == DEAD && enemy_copy2 -> badstatus == DEAD && enemy_copy3 -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("2.%s\n", enemy_copy1 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '2' ){
          skill_target = ENEMY2;
        }
      } while ( command != '2' );
    }
  }
  if ( enemy_copy2 -> badstatus != DEAD ){
    if ( (*enemy) -> badstatus == DEAD && enemy_copy1 -> badstatus == DEAD && enemy_copy3 -> badstatus != DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("3.%s 4.%s\n", enemy_copy2 -> name, enemy_copy3 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '3' ){
          skill_target = ENEMY3;
        }
        else if ( command == '4' ){
          skill_target = ENEMY4;
        }
      } while ( command != '3' && command != '4' );
    }
  }
  if ( enemy_copy3 -> badstatus != DEAD ){
    if ( (*enemy) -> badstatus == DEAD && enemy_copy1 -> badstatus == DEAD && enemy_copy2 -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("4.%s\n", enemy_copy3 -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '4' ){
          skill_target = ENEMY4;
        }
      } while ( command != '4' );
    }
  }

  return skill_target;
}

int select_encount_pattern5_skillTarget(Enemy **enemy, Enemy **enemy1){
  int command;
  int skill_target;

  if ( (*enemy) -> badstatus != DEAD && (*enemy1) -> badstatus != DEAD ){
    printf("対象を選んでください(戻る場合はcを入力してください)\n");
    printf("1.%s 2.%s\n", (*enemy) -> name, (*enemy1) -> name);
    printf("\n");
    command =  _getch();
    if ( command == 'c' ){
      return NOTARGET;
    }
    else if ( command == '1' ){
      skill_target = ENEMY1;
    }
    else if ( command == '2' ){
      skill_target = ENEMY2;
    }
  }
  if ( (*enemy) -> badstatus != DEAD && (*enemy1) -> badstatus == DEAD ){
    do {
      printf("対象を選んでください(戻る場合はcを入力してください)\n");
      printf("1.%s\n", (*enemy) -> name);
      printf("\n");
      command =  _getch();
      if ( command == 'c' ){
        return NOTARGET;
      }
      else if ( command == '1' ){
        skill_target = ENEMY1;
      }
    } while ( command != '1' );
  }
  if ( (*enemy) -> badstatus == DEAD && (*enemy1) -> badstatus != DEAD ){
    do {
      printf("対象を選んでください(戻る場合はcを入力してください)\n");
      printf("2.%s\n", (*enemy1) -> name);
      printf("\n");
      command =  _getch();
      if ( command == 'c' ){
        return NOTARGET;
      }
      else if ( command == '2' ){
        skill_target = ENEMY2;
      }
    } while ( command != '2' );
  }

  return skill_target;
}

int select_encount_pattern6_skillTarget(Enemy **enemy, Enemy **enemy1, Enemy **enemy2){
  int command;
  int skill_target;

  if ( (*enemy) -> badstatus != DEAD && (*enemy1) -> badstatus != DEAD && (*enemy2) -> badstatus != DEAD ){
    printf("対象を選んでください(戻る場合はcを入力してください)\n");
    printf("1.%s 2.%s 3.%s\n", (*enemy) -> name, (*enemy1) -> name, (*enemy2) -> name);
    printf("\n");
    command =  _getch();
    if ( command == 'c' ){
      return NOTARGET;
    }
    else if ( command == '1' ){
      return ENEMY1;
    }
    else if ( command == '2' ){
      return ENEMY2;
    }
    else if ( command == '3' ){
      return ENEMY3;
    }
  }
  if ( (*enemy) -> badstatus != DEAD ){
    if ( (*enemy1) -> badstatus != DEAD && (*enemy2) -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s 2.%s\n", (*enemy) -> name, (*enemy1) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          return ENEMY1;
        }
        else if ( command == '2' ){
          return ENEMY2;
        }
      } while ( command != '1' && command != '2' );
    }
    if ( (*enemy1) -> badstatus == DEAD && (*enemy2) -> badstatus != DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s 3.%s\n", (*enemy) -> name, (*enemy2) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          return ENEMY1;
        }
        else if ( command == '3' ){
          return ENEMY3;
        }
      } while ( command != '1' && command != '3' );
    }
    if ( (*enemy1) -> badstatus == DEAD && (*enemy2) -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s\n", (*enemy) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          return ENEMY1;
        }
      } while ( command != '1' );
    }
  }
  if ( (*enemy1) -> badstatus != DEAD ){
    if ( (*enemy) -> badstatus == DEAD && (*enemy2) -> badstatus != DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("2.%s 3.%s\n", (*enemy1) -> name, (*enemy2) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '2' ){
          return ENEMY2;
        }
        else if ( command == '3' ){
          return ENEMY3;
        }
      } while ( command != '2' && command != '3' );
    }
    if ( (*enemy) -> badstatus == DEAD && (*enemy2) -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("2.%s\n", (*enemy1) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '2' ){
          return ENEMY2;
        }
      } while ( command != '2' );
    }
  }
  if ( (*enemy2) -> badstatus != DEAD ){
    if ( (*enemy) -> badstatus == DEAD && (*enemy1) -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("3.%s\n", (*enemy2) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '3' ){
          return ENEMY3;
        }
      } while ( command != '3' );
    }
  }
}

int select_encount_pattern7_skillTarget(Enemy **enemy, Enemy **enemy1, Enemy **enemy2, Enemy **enemy3){
  int command;
  int skill_target;

  if ( (*enemy) -> badstatus != DEAD && (*enemy1) -> badstatus != DEAD && (*enemy2) -> badstatus != DEAD && (*enemy3) -> badstatus != DEAD ){
    printf("対象を選んでください(戻る場合はcを入力してください)\n");
    printf("1.%s 2.%s 3.%s 4.%s\n", (*enemy) -> name, (*enemy1) -> name, (*enemy2) -> name, (*enemy3) -> name);
    printf("\n");
    command =  _getch();
    if ( command == 'c' ){
      return NOTARGET;
    }
    else if ( command == '1' ){
      return ENEMY1;
    }
    else if ( command == '2' ){
      return ENEMY2;
    }
    else if ( command == '3' ){
      return ENEMY3;
    }
    else if ( command == '4' ){
      return ENEMY4;
    }
  }

  if ( (*enemy) -> badstatus != DEAD ){
    if ( (*enemy1) -> badstatus != DEAD && (*enemy2) -> badstatus == DEAD && (*enemy3) -> badstatus != DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s 2.%s 4.%s\n", (*enemy) -> name, (*enemy1) -> name, (*enemy3) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          return ENEMY1;
        }
        else if ( command == '2' ){
          return ENEMY2;
        }
        else if ( command == '4' ){
          return ENEMY4;
        }
      } while ( command != '1' && command != '2' && command != '4' );
    }
    if ( (*enemy1) -> badstatus != DEAD && (*enemy2) -> badstatus != DEAD && (*enemy3) -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s 2.%s 3.%s\n", (*enemy) -> name, (*enemy1) -> name, (*enemy2) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          return ENEMY1;
        }
        else if ( command == '2' ){
          return ENEMY2;
        }
        else if ( command == '3' ){
          return ENEMY3;
        }
      } while ( command != '1' && command != '2' && command != '3' );
    }
    if ( (*enemy1) -> badstatus != DEAD && (*enemy2) -> badstatus == DEAD && (*enemy3) -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s 2.%s\n", (*enemy) -> name, (*enemy1) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          return ENEMY1;
        }
        else if ( command == '2' ){
          return ENEMY2;
        }
      } while ( command != '1' && command != '2' );
    }
    if ( (*enemy1) -> badstatus == DEAD && (*enemy2) -> badstatus == DEAD && (*enemy3) -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s\n", (*enemy) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          return ENEMY1;
        }
      } while ( command != '1' );
    }
    if ( (*enemy1) -> badstatus == DEAD && (*enemy2) -> badstatus != DEAD && (*enemy3) -> badstatus != DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s 3.%s 4.%s\n", (*enemy) -> name, (*enemy2) -> name, (*enemy3) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          return ENEMY1;
        }
        else if ( command == '3' ){
          return ENEMY3;
        }
        else if ( command == '4' ){
          return ENEMY4;
        }
      } while ( command != '1' && command != '3' && command != '4' );
    }
    if ( (*enemy1) -> badstatus == DEAD && (*enemy2) -> badstatus == DEAD && (*enemy3) -> badstatus != DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("1.%s 4.%s\n", (*enemy) -> name, (*enemy3) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '1' ){
          return ENEMY1;
        }
        else if ( command == '4' ){
          return ENEMY4;
        }
      } while ( command != '1' && command != '4' );
    }
  }

  if ( (*enemy1) -> badstatus != DEAD ){
    if ( (*enemy) -> badstatus == DEAD && (*enemy2) -> badstatus != DEAD && (*enemy3) -> badstatus != DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("2.%s 3.%s 4.%s\n", (*enemy1) -> name, (*enemy2) -> name, (*enemy3) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '2' ){
          return ENEMY2;
        }
        else if ( command == '3' ){
          return ENEMY3;
        }
        else if ( command == '4' ){
          return ENEMY4;
        }
      } while ( command != '2' && command != '3' && command != '4' );
    }
    if ( (*enemy) -> badstatus == DEAD && (*enemy2) -> badstatus != DEAD && (*enemy3) -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("2.%s 3.%s\n", (*enemy1) -> name, (*enemy2) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          break;
        }
      } while ( command != '2' && command != '3' );
    }
    if ( (*enemy) -> badstatus == DEAD && (*enemy2) -> badstatus == DEAD && (*enemy3) -> badstatus != DEAD ){
      do{
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("2.%s 4.%s\n", (*enemy1) -> name, (*enemy3) -> name);
        printf("\n");
        command = _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '2' ){
          return ENEMY2;
        }
        else if ( command == '4' ){
          return ENEMY4;
        }
      }while( command != '2' && command != '4' );
    }
    if ( (*enemy) -> badstatus == DEAD && (*enemy2) -> badstatus == DEAD && (*enemy3) -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("2.%s\n", (*enemy1) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '2' ){
          return ENEMY2;
        }

      } while ( command != '2' );
    }
  }
  if ( (*enemy2) -> badstatus != DEAD ){
    if ( (*enemy) -> badstatus == DEAD && (*enemy1) -> badstatus == DEAD && (*enemy3) -> badstatus != DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("3.%s 4.%s\n", (*enemy2) -> name, (*enemy3) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '3' ){
          return ENEMY3;
        }
        else if ( command == '4' ){
          return ENEMY4;
        }
      } while ( command != '3' && command != '4' );
    }
  }
  if ( (*enemy3) -> badstatus != DEAD ){
    if ( (*enemy) -> badstatus == DEAD && (*enemy1) -> badstatus == DEAD && (*enemy2) -> badstatus == DEAD ){
      do {
        printf("対象を選んでください(戻る場合はcを入力してください)\n");
        printf("4.%s\n", (*enemy3) -> name);
        printf("\n");
        command =  _getch();
        if ( command == 'c' ){
          return NOTARGET;
        }
        else if ( command == '4' ){
          return ENEMY4;
        }
      } while ( command != '4' );
    }
  }

}

int who_is_skillTarget(int use_skill_count){

  if ( use_skill_count == RECOVER1 || use_skill_count == CUREPOISON ){
    return PARTY;
  }
  else if ( use_skill_count == RECOVER2 ){
    return PARTYALL;
  }
  else{
    return ENEMY;
  }

}

void check_skillID(Setting_skill *****setting_skill, int idx){

  if ( (****setting_skill) -> set_skill[idx] == RECOVER1 ){
    printf("%d:ケディア 消費MP:3 (味方1人のHP小回復)\n", idx);
  }
  else if ( (****setting_skill) -> set_skill[idx] == CUREPOISON ){
    printf("%d:キュアポ 消費MP:4 (味方1人のPOISON状態を回復)\n", idx);
  }
  else if ( (****setting_skill) -> set_skill[idx] == ENFA ){
    printf("%d:エンファ 消費MP:4 (単体に火炎小ダメージ)\n", idx);
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
