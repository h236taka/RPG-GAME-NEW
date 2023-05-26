#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <conio.h>
#include <math.h>
#include <wchar.h>
#include "rpg.h"

extern int tempArray[SIZE];

int is_enemy_alive(Enemy **enemy){

  if ( (*enemy) -> badstatus != DEAD ){
    return TRUE;
  }
  else{
    return FALSE;
  }

}

int is_enemyCopy_alive(Enemy *enemy_copy){

  if ( enemy_copy -> badstatus != DEAD ){
    return TRUE;
  }
  else{
    return FALSE;
  }

}

int calculate_evaPer(int eva_base, int eva){
  int turn_decrease;

  for ( int i = 1; i <= eva_base; i++ ){
    if ( i == eva ){
      printf("MISS!\n");
      turn_decrease = -2;
      return turn_decrease; //TRUE
    }
  }

  return FALSE; //回避行動がない(FALSE)
}

double calculate_criticalPer(int critical_base, int critical){
  double turn_decrease;

  for ( int i = 1; i <= critical_base; i++ ){
    if ( i == critical ){
      printf("CRITICAL!\n");
      turn_decrease = 0.1;
      return turn_decrease; //TRUE
    }
  }

  return FALSE; //クリティカルではない(FALSE)
}

void is_damaged_by_playerAttack(Player ******st, Enemy ****enemy, int ***enemy_deadcount, int damage){

  if ( damage >= (***enemy) -> hp ){
    printf("%s<<%dダメージ\n", (***enemy) -> name, damage);
    sleep(1);
    printf("%sは%sを倒した!\n", (*****st) -> name, (***enemy) -> name);
    (***enemy) -> hp = 0;
    (***enemy) -> badstatus = DEAD;
    ***enemy_deadcount++;
  }
  else{
    printf("%s<<%dダメージ\n", (***enemy) -> name, damage);
    (***enemy) -> hp -= damage;
    if ( (***enemy) -> hp <= 0 ){
      (***enemy) -> hp = 0;
      (***enemy) -> badstatus = DEAD;
      ***enemy_deadcount++;
      printf("%sは%sを倒した!\n", (*****st) -> name, (***enemy) -> name);
    }
  }

}

void is_damaged_by_playerAttack_forEnemyCopy(Player ******st, Enemy ***enemy_copy, int ***enemy_deadcount, int damage){

  if ( damage >= (**enemy_copy) -> hp ){
    printf("%s<<%dダメージ\n", (**enemy_copy) -> name, damage);
    sleep(1);
    printf("%sは%sを倒した!\n", (*****st) -> name, (**enemy_copy) -> name);
    (**enemy_copy) -> hp = 0;
    (**enemy_copy) -> badstatus = DEAD;
    ***enemy_deadcount++;
  }
  else{
    printf("%s<<%dダメージ\n", (**enemy_copy) -> name, damage);
    (**enemy_copy) -> hp -= damage;
    if ( (**enemy_copy) -> hp <= 0 ){
      (**enemy_copy) -> hp = 0;
      (**enemy_copy) -> badstatus = DEAD;
      ***enemy_deadcount++;
      printf("%sは%sを倒した!\n", (*****st) -> name, (**enemy_copy) -> name);
    }
  }

}

double check_enemy_normalAttackResist(Player *****st, Enemy ***enemy, int **enemy_deadcount, int damage){
  double turn_decrease;

  if ( (**enemy) -> physical_attack == BLOCK ){  //物理攻撃無効
    sleep(1);
    printf("%s<<BLOCK!\n", (**enemy) -> name);
    turn_decrease = -2;
    return turn_decrease;
  }
  else if ( (**enemy) -> physical_attack == ABSORB ){  //物理攻撃吸収
    (**enemy) -> hp += damage;
    if ( (**enemy) -> hp > (**enemy) -> maxhp ){
      (**enemy) -> hp = (**enemy) -> maxhp;
    }
    printf("ABSORB!\n");
    sleep(1);
    printf("%s<<%dダメージ吸収\n", (**enemy) -> name, damage);
    turn_decrease = TURNCHAGE;
    return turn_decrease;
  }
  else if ( (**enemy) -> physical_attack == REFLECT ){  //物理攻撃反射
    printf("REFLECT!\n");
    sleep(1);
    printf("%s<<%dダメージ反射\n", (****st) -> name, damage);
    if ( (****st) -> hp <= 0 ){
      (****st) -> hp = 0;
      (****st) -> badstatus = DEAD;
      printf("%s<<DEAD\n", (****st) -> name);
    }
    turn_decrease = TURNCHAGE;
    return turn_decrease;
  }
  else if ( (**enemy) -> physical_attack == 100 ){
    //sleep(1);
    damage = damage;
    turn_decrease = -1;
  }
  else if ( (**enemy) -> physical_attack == 120 ){
    damage *= 1.2;
    turn_decrease = -1;
  }
  else if ( (**enemy) -> physical_attack == 150 ){     //物理攻撃1.5倍
    damage *= 1.5;
    turn_decrease = -1;
  }
  else if ( (**enemy) -> physical_attack == 200 ){
    //sleep(1);
    printf("WEAKNESS!!\n");
    damage *= 2;
    turn_decrease = 0.1;
  }
  else if ( (**enemy) -> physical_attack == 80 ){  //物理攻撃ダメージ80%
    damage *= 0.8;
    turn_decrease = -1;
  }
  else if ( (**enemy) -> physical_attack == 50 ){  //物理攻撃半減
    //sleep(1);
    printf("RESIST!\n");
    damage *= 0.5;
    turn_decrease = -1;
  }
  else if ( (**enemy) -> physical_attack == 25 ){  //物理攻撃ダメージ25%
    //sleep(1);
    printf("RESIST!\n");
    damage *= 0.25;
    turn_decrease = -1;
  }

  is_damaged_by_playerAttack(&st,&enemy,&enemy_deadcount,damage);

  return turn_decrease;
}

double check_enemyCopy_normalAttackResist(Player *****st, Enemy **enemy_copy, int **enemy_deadcount, int damage){
  double turn_decrease;

  if ( (*enemy_copy) -> physical_attack == BLOCK ){  //物理攻撃無効
    printf("%s<<BLOCK!\n", (*enemy_copy) -> name);
    turn_decrease = -2;
    return turn_decrease;
  }
  else if ( (*enemy_copy) -> physical_attack == ABSORB ){  //物理攻撃吸収
    (*enemy_copy) -> hp += damage;
    if ( (*enemy_copy) -> hp > (*enemy_copy) -> maxhp ){
      (*enemy_copy) -> hp = (*enemy_copy) -> maxhp;
    }
    printf("ABSORB!\n");
    sleep(1);
    printf("%s<<%dダメージ吸収\n", (*enemy_copy) -> name, damage);
    turn_decrease = TURNCHAGE;
    return turn_decrease;
  }
  else if ( (*enemy_copy) -> physical_attack == REFLECT ){  //物理攻撃反射
    printf("REFLECT!\n");
    sleep(1);
    printf("%s<<%dダメージ反射\n", (****st) -> name, damage);
    if ( (****st) -> hp <= 0 ){
      (****st) -> hp = 0;
      (****st) -> badstatus = DEAD;
      printf("%s<<DEAD\n", (****st) -> name);
    }
    turn_decrease = TURNCHAGE;
    return turn_decrease;
  }
  else if ( (*enemy_copy) -> physical_attack == 100 ){
    damage = damage;
    turn_decrease = -1;
  }
  else if ( (*enemy_copy) -> physical_attack == 120 ){
    damage *= 1.2;
    turn_decrease = -1;
  }
  else if ( (*enemy_copy) -> physical_attack == 150 ){     //物理攻撃1.5倍
    damage *= 1.5;
    turn_decrease = -1;
  }
  else if ( (*enemy_copy) -> physical_attack == 200 ){
    printf("WEAKNESS!!\n");
    damage *= 2;
    turn_decrease = 0.1;
  }
  else if ( (*enemy_copy) -> physical_attack == 80 ){  //物理攻撃ダメージ80%
    damage *= 0.8;
    turn_decrease = -1;
  }
  else if ( (*enemy_copy) -> physical_attack == 50 ){  //物理攻撃半減
    //sleep(1);
    printf("RESIST!\n");
    damage *= 0.5;
    turn_decrease = -1;
  }
  else if ( (*enemy_copy) -> physical_attack == 25 ){  //物理攻撃ダメージ25%
    //sleep(1);
    printf("RESIST!\n");
    damage *= 0.25;
    turn_decrease = -1;
  }

  is_damaged_by_playerAttack_forEnemyCopy(&st,&enemy_copy,&enemy_deadcount,damage);

  return turn_decrease;
}

double player_attack_for_enemy(Player ****st, Enemy **enemy, int *enemy_deadcount){
  int damage_base, damage, i, eva, critical, max_damage, temp;
  double eva_base, critical_base;
  double turn_decrease;

  printf("%s>>通常攻撃!\n", (***st) -> name);
  sleep(1);

  if ( (***st) -> lv <= 3 ){
    damage_base = ( ( ( (***st) -> lv + (***st) -> atk ) * 32 ) / 15 ) - (*enemy) -> str;
  }
  else{
    damage_base = ( ( ( (***st) -> lv + (***st) -> atk ) * 32 ) / 16 ) - (*enemy) -> str;
  }
  if ( damage_base < 0 ){
    damage_base = 1;
  }
  eva_base = 3 + ( (*enemy) -> agi * 0.1 ) + ( (*enemy) -> luk * 0.1 ) - ( (***st) -> agi * 0.2) - ( (***st) -> luk * 0.1);   //回避率計算

  //麻痺状態では攻撃の命中率が下がる
  if ( (***st) -> badstatus == PALYZE ){
    eva_base += 50;
    if ( eva_base > 100 ){
      eva_base = 100;
    }
  }


  //printf("before eva_base = %f\n", eva_base);
  eva_base = round(eva_base);
  //printf("after eva_base = %f\n", eva_base);

  if ( eva_base < 3 ){
    eva_base = 3;     //回避率最小値3%
  }

  eva = (rand() % ( 100 - 1 + 1 ) + 1);  //回避率の乱数
  //printf("eva number = %d\n", eva);

  turn_decrease = calculate_evaPer(eva_base,eva);
  if ( turn_decrease == -2 ){
    return turn_decrease;
  }

  critical_base = 1 + ( (***st) -> luk * 0.2 ) + ( (***st) -> agi * 0.2 )- ( (*enemy) -> luk * 0.1 );  //critical率の計算
  if ( critical_base < 1 ){
    critical_base = 1;       //critical最小値1%
  }
  //printf("before critical_base = %f\n", critical_base);
  critical_base = round(critical_base);
  //printf("after critical_base = %f\n", critical_base);

  critical = (rand() % ( 100 - 1 + 1 ) + 1);   //critical率の乱数
  //printf("critical number = %d\n", critical);

  turn_decrease = calculate_criticalPer(critical_base, critical);
  if ( turn_decrease == 0.1 ){
    max_damage = damage_base * 1.5;   //ダメージの最大乱数はdamage_baseの1.5倍
    sleep(1);
    damage = (rand() % ( max_damage - damage_base + 1 )) + damage_base; //(rand()%(max - min + 1)) + min;
    damage *= 2;     //criticalでダメージ2倍
    if ( damage > 9999 ){
      damage = 9999;
    }
    //is_damaged_by_playerAttack(&st,&enemy,damage);pointerの数が合わないため下に直接ダメージ計算プログラムを記述
    if ( damage >= (*enemy) -> hp ){
      printf("%s<<%dダメージ\n", (*enemy) -> name, damage);
      sleep(1);
      printf("%sは%sを倒した!\n", (***st) -> name, (*enemy) -> name);
      (*enemy) -> hp = 0;
      (*enemy) -> badstatus = DEAD;
      *enemy_deadcount++;
    }
    else{
      printf("%s<<%dダメージ\n", (*enemy) -> name, damage);
      (*enemy) -> hp -= damage;
      if ( (*enemy) -> hp <= 0 ){
        (*enemy) -> hp = 0;
        (*enemy) -> badstatus = DEAD;
        printf("%sは%sを倒した!\n", (***st) -> name, (*enemy) -> name);
        *enemy_deadcount++;
      }
    }
    
    return turn_decrease;
  }

  max_damage = damage_base * 1.3;

  damage = (rand() % ( max_damage - damage_base + 1) ) + damage_base; //(rand()%(max - min + 1)) + min;
  if ( damage > 9999 ){
    damage = 9999;
  }
  //敵の耐性判断
  turn_decrease = check_enemy_normalAttackResist(&st,&enemy,&enemy_deadcount,damage);

  return turn_decrease;
}

double player_attack_for_enemyCopy(Player ****st, Enemy *enemy_copy, int *enemy_deadcount){
  int damage_base, damage, i, eva, critical, max_damage, temp;
  double eva_base, critical_base;
  double turn_decrease;

  printf("%s>>通常攻撃!\n", (***st) -> name);
  sleep(1);

  if ( (***st) -> lv <= 3 ){
    damage_base = ( ( ( (***st) -> lv + (***st) -> atk ) * 32 ) / 15 ) - enemy_copy -> str;
  }
  else{
    damage_base = ( ( ( (***st) -> lv + (***st) -> atk ) * 32 ) / 16 ) - enemy_copy -> str;
  }
  if ( damage_base < 0 ){
    damage_base = 1;
  }
  eva_base = 3 + ( enemy_copy -> agi * 0.1 ) + ( enemy_copy -> luk * 0.1 ) - ( enemy_copy -> agi * 0.2) - ( enemy_copy -> luk * 0.1);   //回避率計算

  //麻痺状態では攻撃の命中率が下がる
  if ( (***st) -> badstatus == PALYZE ){
    eva_base += 50;
    if ( eva_base > 100 ){
      eva_base = 100;
    }
  }

  //printf("before eva_base = %f\n", eva_base);
  eva_base = round(eva_base);
  //printf("after eva_base = %f\n", eva_base);

  if ( eva_base < 3 ){
    eva_base = 3;     //回避率最小値3%
  }

  eva = (rand() % ( 100 - 1 + 1 ) + 1);  //回避率の乱数
  //printf("eva number = %d\n", eva);

  turn_decrease = calculate_evaPer(eva_base,eva);
  if ( turn_decrease == -2 ){
    return turn_decrease;
  }

  critical_base = 1 + ( (***st) -> luk * 0.2 ) + ( (***st) -> agi * 0.2 )- ( enemy_copy -> luk * 0.1 );  //critical率の計算
  if ( critical_base < 1 ){
    critical_base = 1;       //critical最小値1%
  }
  //printf("before critical_base = %f\n", critical_base);
  critical_base = round(critical_base);
  //printf("after critical_base = %f\n", critical_base);

  critical = (rand() % ( 100 - 1 + 1 ) + 1);   //critical率の乱数
  //printf("critical number = %d\n", critical);

  turn_decrease = calculate_criticalPer(critical_base, critical);
  if ( turn_decrease == 0.1 ){
    printf("%s>>通常攻撃!\n", (***st) -> name);
    sleep(1);
    max_damage = damage_base * 1.5;   //ダメージの最大乱数はdamage_baseの1.5倍
    sleep(1);
    printf("CRITICAL!!\n");
    damage = (rand() % ( max_damage - damage_base + 1 )) + damage_base; //(rand()%(max - min + 1)) + min;
    damage *= 2;     //criticalでダメージ2倍
    if ( damage > 9999 ){
      damage = 9999;
    }
    if ( damage >= enemy_copy -> hp ){
      printf("%s<<%dダメージ\n", enemy_copy -> name, damage);
      sleep(1);
      printf("%sは%sを倒した!\n", (***st) -> name, enemy_copy -> name);
      enemy_copy -> hp = 0;
      enemy_copy -> badstatus = DEAD;
      *enemy_deadcount++;
    }
    else{
      printf("%s<<%dダメージ\n", enemy_copy -> name, damage);
      enemy_copy -> hp -= damage;
      if ( enemy_copy -> hp <= 0 ){
        enemy_copy -> hp = 0;
        enemy_copy -> badstatus = DEAD;
        printf("%sは%sを倒した!\n", (***st) -> name, enemy_copy -> name);
        *enemy_deadcount++;
      }
    }
    return turn_decrease;
  }

  max_damage = damage_base * 1.3;

  damage = (rand() % ( max_damage - damage_base + 1) ) + damage_base; //(rand()%(max - min + 1)) + min;
  if ( damage > 9999 ){
    damage = 9999;
  }
  //敵の耐性判断
  turn_decrease = check_enemyCopy_normalAttackResist(&st,&enemy_copy,&enemy_deadcount,damage);

  return turn_decrease;
}

double calculate_enemy_turn(double enemy_turn, double turn_decrease){

  if ( turn_decrease == -1 ){  //ターンを1消費
    if ( enemy_turn == 4 || enemy_turn == 3 || enemy_turn == 2 || enemy_turn == 1 ){
      enemy_turn += turn_decrease;
    }
    else if ( enemy_turn == 4.4 ){
      enemy_turn = 3.3;
    }
    else if ( enemy_turn == 4.3 ){
      enemy_turn = 3.2;
    }
    else if ( enemy_turn == 4.2 ){
      enemy_turn = 3.1;
    }
    else if ( enemy_turn == 4.1 ){
      enemy_turn = 3.0;
    }
    else if ( enemy_turn == 3.3 ){
      enemy_turn = 2.2;
    }
    else if ( enemy_turn == 3.2 ){
      enemy_turn = 2.1;
    }
    else if ( enemy_turn == 3.1 ){
      enemy_turn = 2.0;
    }
    else if ( enemy_turn == 2.2 ){
      enemy_turn = 1.1;
    }
    else if ( enemy_turn == 2.1 ){
      enemy_turn = 1.0;
    }
    else if ( enemy_turn == 1.1 ){
      enemy_turn = 0.0;
    }
  }
  else if ( turn_decrease == -2 ){
    if ( enemy_turn == 4 || enemy_turn == 3 || enemy_turn == 2 || enemy_turn == 1 ){
      enemy_turn += turn_decrease;
    }
    else if ( enemy_turn == 4.4 ){
      enemy_turn = 2.2;
    }
    else if ( enemy_turn == 4.3 ){
      enemy_turn = 2.1;
    }
    else if ( enemy_turn == 4.2 ){
      enemy_turn = 2.0;
    }
    else if ( enemy_turn == 4.1 ){
      enemy_turn = 2.0;
    }
    else if ( enemy_turn == 3.3 ){
      enemy_turn = 1.1;
    }
    else if ( enemy_turn == 3.2 ){
      enemy_turn = 1.0;
    }
    else if ( enemy_turn == 3.1 ){
      enemy_turn == 1.0;
    }
    else if ( enemy_turn == 2.2 || enemy_turn == 2.1 || enemy_turn == 1.1 ){
      enemy_turn = 0.0;
    }
  }
  else if ( turn_decrease == TURNCHAGE ){
    enemy_turn = 0.0;
  }
  //turn増加
  else if ( turn_decrease == 0.1 ){
    if ( enemy_turn == 4 || enemy_turn == 3 || enemy_turn == 2 || enemy_turn == 1 ){
      //printf("here\n");
      enemy_turn += turn_decrease;
      //printf("enemy_turn:%f\n", enemy_turn);
    }
    else if ( enemy_turn == 4.4 ){
      enemy_turn = 3.3;
    }
    else if ( enemy_turn == 4.3 || enemy_turn == 4.2 || enemy_turn == 4.1 ){
      enemy_turn += turn_decrease;
    }
    else if ( enemy_turn == 3.3 ){
      enemy_turn = 3.2;
    }
    else if ( enemy_turn == 3.2 || enemy_turn == 3.1 ){
      enemy_turn += turn_decrease;
    }
    else if ( enemy_turn == 2.2 ){
      enemy_turn = 1.1;
    }
    else if ( enemy_turn == 2.1 ){
      enemy_turn += turn_decrease;
    }
    else if ( enemy_turn == 1.1 ){
      enemy_turn = 0.0;
    }
  }

  return enemy_turn;
}

double enemy_attack(Player *****st, Player *****st2, Player *****st3, Enemy ***enemy, int player_guard, int player_guard2, int player_guard3, double enemy_turn){
  int damage_base, damage, eva, critical, eva_count, critical_count, i, max_damage;
  int temp, target_base, target;
  double eva_base, critical_base, turn_decrease;

  eva_count = 0;
  critical_count = 0;
  //damage_base = ( (****enemy) -> atk + (****enemy) -> lv ) * 5 - ( (****st) -> str + (****st) -> lv ) * 2;
  printf("%sの攻撃!\n", (**enemy) -> name);
  sleep(1);
  //eva_base = 3 + ( (****st) -> agi * 0.2 ) + ( (****st) -> luk * 0.1 ) - ( (****enemy) -> agi * 0.1) - ( (****enemy) -> luk * 0.1);   //回避率計算

  //攻撃する味方を選択
  target_base = (rand() % ( 3 - 1 + 1 ) + 1); //各メンバーへの攻撃確率は33%
  if ( target_base == 1 && (****st) -> badstatus == DEAD ){  //targetが死亡していたときtarget変更
    if ( (****st2) -> badstatus == DEAD ){
      target_base = 3;
    }
    else{
      target_base = 2;
    }
  }
  if ( target_base == 2 && (****st2) -> badstatus == DEAD ){
    if ( (****st3) -> badstatus == DEAD ){
      target_base = 1;
    }
    else{
      target_base = 3;
    }
  }
  if ( target_base == 3 && (****st3) -> badstatus == DEAD ){
    if ( (****st) -> badstatus == DEAD ){
      target_base = 2;
    }
    else{
      target_base = 1;
    }
  }
  if ( target_base == 1 ){  //主人公
    if ( (****st) -> physical_attack == -1 ){  //物理攻撃無効
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else if ( (****st) -> physical_attack == -2 ){  //物理攻撃吸収
      damage_base = ( ( ( (**enemy) -> lv + (**enemy) -> atk ) * 32 ) / 15 ) - (****st) -> str * 2;
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      max_damage = damage_base * 1.3;
      damage = (rand() % ( max_damage - damage_base + 1 )) + damage_base;
      temp = damage;
      damage = -2;
      (****st) -> hp += temp;
      if ( (****st) -> hp > (****st) -> maxhp ){
        (****st) -> hp = (****st) -> maxhp;
      }
      printf("Absorb!\n");
      sleep(1);
      printf("%s<<%dダメージ吸収\n", (****st) -> name, temp);
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else if ( (****st) -> physical_attack == -3 ){  //物理攻撃反射
      damage_base = ( ( ( (**enemy) -> lv + (**enemy) -> atk ) * 32 ) / 15 ) - (****st) -> str * 2;
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      max_damage = damage_base * 1.3;
      temp = damage;
      damage = -3;
      (**enemy) -> hp -= temp;
      printf("Reflect!\n");
      sleep(1);
      printf("%s<<%dダメージ\n", (**enemy) -> name, temp);
      if ( (**enemy) -> hp <= 0 ){
        (**enemy) -> hp = 0;
        (**enemy) -> badstatus = DEAD;
        printf("%s<<DEAD\n", (**enemy) -> name);
      }
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else{
      target = 1;   //主人公
      damage_base = ( ( ( (**enemy) -> lv + (**enemy) -> atk ) * 32 ) / 15 ) - (****st) -> str * 2;
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      eva_base = 3 + ( (****st) -> agi * 0.2 ) + ( (****st) -> luk * 0.1 ) - ( (**enemy) -> agi * 0.1) - ( (**enemy) -> luk * 0.1);   //回避率計算
    }
  }
  else if ( target_base == 2 ){   //2人目のメンバー
    if ( (****st2) -> physical_attack == -1 ){  //物理攻撃無効
      damage = -1;
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else if ( (****st2) -> physical_attack == -2 ){  //物理攻撃吸収
      damage_base = ( ( ( (**enemy) -> lv + (**enemy) -> atk ) * 32 ) / 15 ) - (****st2) -> str * 2;
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      max_damage = damage_base * 1.3;
      temp = damage;
      damage = -2;
      (****st2) -> hp += temp;
      if ( (****st2) -> hp > (****st2) -> maxhp ){
        (****st2) -> hp = (****st2) -> maxhp;
      }
      printf("Absorb!\n");
      sleep(1);
      printf("%s<<%dダメージ吸収\n", (****st2) -> name, temp);
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else if ( (****st2) -> physical_attack == -3 ){  //物理攻撃反射
      damage_base = ( ( ( (**enemy) -> lv + (**enemy) -> atk ) * 32 ) / 15 ) - (****st2) -> str * 2;
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      max_damage = damage_base * 1.3;
      temp = damage;
      damage = -3;
      (**enemy) -> hp -= temp;
      printf("Reflect!\n");
      sleep(1);
      printf("%s<<%dダメージ\n", (**enemy) -> name, temp);
      if ( (**enemy) -> hp <= 0 ){
        (**enemy) -> hp = 0;
        (**enemy) -> badstatus = DEAD;
        printf("%s<<DEAD\n", (**enemy) -> name);
      }
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else{
      target = 2;
      damage_base = ( ( ( (**enemy) -> lv + (**enemy) -> atk ) * 32 ) / 15 ) - (****st2) -> str * 2;
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      eva_base = 3 + ( (****st2) -> agi * 0.2 ) + ( (****st2) -> luk * 0.1 ) - ( (**enemy) -> agi * 0.1) - ( (**enemy) -> luk * 0.1);   //回避率計算
    }
  }
  else if ( target_base == 3 ){   //３人目のメンバー
    if ( (****st3) -> physical_attack == -1 ){  //物理攻撃無効
      damage = -1;
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else if ( (****st3) -> physical_attack == -2 ){  //物理攻撃吸収
      damage_base = ( ( ( (**enemy) -> lv + (**enemy) -> atk ) * 32 ) / 15 ) - (****st3) -> str * 2;
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      max_damage = damage_base * 1.3;
      temp = damage;
      damage = -2;
      (****st) -> hp += temp;
      if ( (****st3) -> hp > (****st3) -> maxhp ){
        (****st3) -> hp = (****st3) -> maxhp;
      }
      printf("Absorb!\n");
      sleep(1);
      printf("%s<<%dダメージ吸収\n", (****st3) -> name, temp);
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else if ( (****st3) -> physical_attack == -3 ){  //物理攻撃反射
      damage_base = ( ( ( (**enemy) -> lv + (**enemy) -> atk ) * 32 ) / 15 ) - (****st3) -> str * 2;
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      max_damage = damage_base * 1.3;
      temp = damage;
      damage = -3;
      (**enemy) -> hp -= temp;
      printf("Reflect!\n");
      sleep(1);
      printf("%s<<%dダメージ\n", (**enemy) -> name, temp);
      if ( (**enemy) -> hp <= 0 ){
        (**enemy) -> hp = 0;
        (**enemy) -> badstatus = DEAD;
        printf("%s<<DEAD\n", (**enemy) -> name);
      }
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else{
      target = 3;
      damage_base = ( ( ( (**enemy) -> lv + (**enemy) -> atk ) * 32 ) / 15 ) - (****st3) -> str * 2;
      if ( damage_base < 0 ){
        damage_base = 1;
      }
      eva_base = 3 + ( (****st3) -> agi * 0.2 ) + ( (****st3) -> luk * 0.1 ) - ( (**enemy) -> agi * 0.1) - ( (**enemy) -> luk * 0.1);   //回避率計算
    }
  }

  //printf("target:%d\n", target);

  //printf("before eva_base = %f\n", eva_base);
  eva_base = round(eva_base);
  //printf("after eva_base = %f\n", eva_base);

  if ( eva_base < 3 ){
    eva_base = 3;     //回避率最小値3%
  }

  eva = (rand() % ( 100 - 1 + 1 ) + 1);  //回避率の乱数
  //printf("eva number = %d\n", eva);
  for ( i = 3; i <= eva_base; i++ ){
    if ( eva_base == i ){
      if ( eva >= 1 && eva <= i ){   //回避率eva_base%
        damage = 0;
        printf("MISS!\n");
        turn_decrease = -2;
        enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        eva_count++;
      }
    }
  }

  if ( eva_count == 0 ){
    if ( target == 1 ){
      critical_base = 1 + ( (**enemy) -> luk * 0.2) - ( (****st) -> luk * 0.1);  //critical率の計算
      if ( critical_base < 1 ){
        critical_base = 1;       //critical最小値1%
      }
    }
    else if ( target == 2 ){
      critical_base = 1 + ( (**enemy) -> luk * 0.2) - ( (****st2) -> luk * 0.1);  //critical率の計算
      if ( critical_base < 1 ){
        critical_base = 1;       //critical最小値1%
      }
    }
    else if ( target == 3 ){
      critical_base = 1 + ( (**enemy) -> luk * 0.2) - ( (****st3) -> luk * 0.1);  //critical率の計算
      if ( critical_base < 1 ){
        critical_base = 1;       //critical最小値1%
      }
    }
    //printf("before critical_base = %f\n", critical_base);
    critical_base = round(critical_base);
    //printf("after critical_base = %f\n", critical_base);

    critical = (rand() % ( 100 - 1 + 1 ) + 1);   //critical率の乱数
    //printf("critical number = %d\n", critical);

    for ( i = 1; i <= critical_base; i++ ){
      if ( critical_base == i ){
        if ( critical >= 1 && critical <= i ){   //回避率critical_base%
          max_damage = damage_base * 1.3;   //ダメージの最大乱数はdamage_baseの1.3倍
          sleep(1);
          printf("CRITICAL!!\n");
          damage = (rand() % ( max_damage - damage_base + 1 )) + damage_base; //(rand()%(max - min + 1)) + min;
          damage *= 2;     //criticalでダメージ2倍
          critical_count++;
          turn_decrease = 0.1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
      }
    }

    max_damage = damage_base * 1.3;
    if ( critical_count == 0 ){
      damage = (rand() % ( max_damage - damage_base + 1) ) + damage_base; //(rand()%(max - min + 1)) + min;
      //味方の耐性判断
      if ( target == 1 ){
        if ( (****st) -> physical_attack == 100 ){
          damage = damage;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st) -> physical_attack == 150 ){     //物理攻撃1.5倍
          damage *= 1.5;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st) -> physical_attack == 200 ){
          sleep(1);
          printf("WEAKNESS!!\n");
          damage *= 2;
          turn_decrease = 0.1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st) -> physical_attack == 80 ){  //物理攻撃ダメージ80%
          damage *= 0.8;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st) -> physical_attack == 50 ){  //物理攻撃半減
          sleep(1);
          printf("RESIST!\n");
          damage *= 0.5;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st) -> physical_attack == 25 ){  //物理攻撃ダメージ25%
          sleep(1);
          printf("RESIST!\n");
          damage *= 0.25;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }

        if ( player_guard == 1 ){
          damage /= 1.6;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
      }
      else if ( target == 2 ){
        if ( (****st2) -> physical_attack == 100 ){
          damage = damage;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st2) -> physical_attack == 150 ){     //物理攻撃1.5倍
          damage *= 1.5;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st2) -> physical_attack == 200 ){
          sleep(1);
          printf("WEAKNESS!!\n");
          damage *= 2;
          turn_decrease = 0.1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st2) -> physical_attack == 80 ){  //物理攻撃ダメージ80%
          damage *= 0.8;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st2) -> physical_attack == 50 ){  //物理攻撃半減
          sleep(1);
          printf("RESIST!\n");
          damage *= 0.5;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st2) -> physical_attack == 25 ){  //物理攻撃ダメージ25%
          sleep(1);
          printf("RESIST!\n");
          damage *= 0.25;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }

        if ( player_guard2 == 1 ){
          damage /= 1.6;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
      }
      else if ( target == 3 ){
        if ( (****st3) -> physical_attack == 100 ){
          damage = damage;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st3) -> physical_attack == 150 ){     //物理攻撃1.5倍
          damage *= 1.5;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st3) -> physical_attack == 200 ){
          sleep(1);
          printf("WEAKNESS!!\n");
          damage *= 2;
          turn_decrease = 0.1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st3) -> physical_attack == 80 ){  //物理攻撃ダメージ80%
          damage *= 0.8;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st3) -> physical_attack == 50 ){  //物理攻撃半減
          sleep(1);
          printf("RESIST!\n");
          damage *= 0.5;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st3) -> physical_attack == 25 ){  //物理攻撃ダメージ25%
          sleep(1);
          printf("RESIST!\n");
          damage *= 0.25;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }

        if ( player_guard3 == 1 ){
          damage /= 1.6;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
      }

      if ( damage < 0 ){
        damage = 1;
      }
    }

    if ( target == 1 ){
      if ( damage >= (****st) -> hp ){
        sleep(1);
        printf("%s<<%dダメージ\n", (****st) -> name, damage);
        sleep(1);
        printf("%s<<DEAD\n", (****st) -> name);
        (****st) -> hp = 0;
        (****st) -> badstatus = DEAD;
      }
      else{
        printf("%s<<%dダメージ\n", (****st) -> name, damage);
        (****st) -> hp -= damage;
        if ( (****st) -> hp <= 0 ){
          (****st) -> hp = 0;
          (****st) -> badstatus = DEAD;
        }
      }
    }
    else if ( target == 2 ){
      if ( damage >= (****st2) -> hp ){
        sleep(1);
        printf("%s<<%dダメージ\n", (****st2) -> name, damage);
        sleep(1);
        printf("%s<<DEAD\n", (****st2) -> name);
        (****st2) -> hp = 0;
        (****st2) -> badstatus = DEAD;
      }
      else{
        printf("%s<<%dダメージ\n", (****st2) -> name, damage);
        (****st2) -> hp -= damage;
        if ( (****st2) -> hp <= 0 ){
          (****st2) -> hp = 0;
          (****st2) -> badstatus = DEAD;
        }
      }
    }
    else{
      if ( damage >= (****st2) -> hp ){
        sleep(1);
        printf("%s<<%dダメージ\n", (****st3) -> name, damage);
        sleep(1);
        printf("%s<<DEAD\n", (****st3) -> name);
        (****st3) -> hp = 0;
        (****st3) -> badstatus = DEAD;
      }
      else{
        printf("%s<<%dダメージ\n", (****st3) -> name, damage);
        (****st3) -> hp -= damage;
        if ( (****st3) -> hp <= 0 ){
          (****st3) -> hp = 0;
          (****st3) -> badstatus = DEAD;
        }
      }
    }
  }

  player_guard = 0;
  player_guard2 = 0;
  player_guard3 = 0;

  //printf("enemy_attack's enemy_turn:%f\n", enemy_turn);

  return enemy_turn;
}

double enemy_copy_attack(Player *****st, Player *****st2, Player *****st3, Enemy **enemy_copy1, int player_guard, int player_guard2, int player_guard3, double enemy_turn){
  int damage_base, damage, eva, critical, eva_count, critical_count, i, max_damage;
  int temp, target_base, target;
  double eva_base, critical_base, turn_decrease;

  eva_count = 0;
  critical_count = 0;
  //damage_base = ( (****enemy) -> atk + (****enemy) -> lv ) * 5 - ( (****st) -> str + (****st) -> lv ) * 2;
  printf("%sの攻撃!\n", (*enemy_copy1) -> name);
  sleep(1);
  //eva_base = 3 + ( (****st) -> agi * 0.2 ) + ( (****st) -> luk * 0.1 ) - ( (****enemy) -> agi * 0.1) - ( (****enemy) -> luk * 0.1);   //回避率計算

  //攻撃する味方を選択
  target_base = (rand() % ( 3 - 1 + 1 ) + 1); //各メンバーへの攻撃確率は33%
  if ( target_base == 1 ){  //主人公
    if ( (****st) -> physical_attack == -1 ){  //物理攻撃無効
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else if ( (****st) -> physical_attack == -2 ){  //物理攻撃吸収
      damage_base = ( ( ( (*enemy_copy1) -> lv + (*enemy_copy1) -> atk ) * 32 ) / 15 ) - (****st) -> str * 2;
      max_damage = damage_base * 1.3;
      damage = (rand() % ( max_damage - damage_base + 1 )) + damage_base;
      temp = damage;
      damage = -2;
      (****st) -> hp += temp;
      if ( (****st) -> hp > (****st) -> maxhp ){
        (****st) -> hp = (****st) -> maxhp;
      }
      printf("Absorb!\n");
      sleep(1);
      printf("%s<<%dダメージ吸収\n", (****st) -> name, temp);
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else if ( (****st) -> physical_attack == -3 ){  //物理攻撃反射
      damage_base = ( ( ( (*enemy_copy1) -> lv + (*enemy_copy1) -> atk ) * 32 ) / 15 ) - (****st) -> str * 2;
      max_damage = damage_base * 1.3;
      temp = damage;
      damage = -3;
      (*enemy_copy1) -> hp -= temp;
      printf("Reflect!\n");
      sleep(1);
      printf("%s<<%dダメージ\n", (*enemy_copy1) -> name, temp);
      if ( (*enemy_copy1) -> hp <= 0 ){
        (*enemy_copy1) -> hp = 0;
        (*enemy_copy1) -> badstatus = DEAD;
        printf("%s<<DEAD\n", (*enemy_copy1) -> name);
      }
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else{
      target = 1;   //主人公
      damage_base = ( ( ( (*enemy_copy1) -> lv + (*enemy_copy1) -> atk ) * 32 ) / 15 ) - (****st) -> str * 2;
      eva_base = 3 + ( (****st) -> agi * 0.2 ) + ( (****st) -> luk * 0.1 ) - ( (*enemy_copy1) -> agi * 0.1) - ( (*enemy_copy1) -> luk * 0.1);   //回避率計算
    }
  }
  else if ( target_base == 2 ){   //2人目のメンバー
    if ( (****st2) -> physical_attack == -1 ){  //物理攻撃無効
      damage = -1;
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else if ( (****st2) -> physical_attack == -2 ){  //物理攻撃吸収
      damage_base = ( ( ( (*enemy_copy1) -> lv + (*enemy_copy1) -> atk ) * 32 ) / 15 ) - (****st2) -> str * 2;
      max_damage = damage_base * 1.3;
      temp = damage;
      damage = -2;
      (****st2) -> hp += temp;
      if ( (****st2) -> hp > (****st2) -> maxhp ){
        (****st2) -> hp = (****st2) -> maxhp;
      }
      printf("Absorb!\n");
      sleep(1);
      printf("%s<<%dダメージ吸収\n", (****st2) -> name, temp);
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else if ( (****st2) -> physical_attack == -3 ){  //物理攻撃反射
      damage_base = ( ( ( (*enemy_copy1) -> lv + (*enemy_copy1) -> atk ) * 32 ) / 15 ) - (****st2) -> str * 2;
      max_damage = damage_base * 1.3;
      temp = damage;
      damage = -3;
      (*enemy_copy1) -> hp -= temp;
      printf("Reflect!\n");
      sleep(1);
      printf("%s<<%dダメージ\n", (*enemy_copy1) -> name, temp);
      if ( (*enemy_copy1) -> hp <= 0 ){
        (*enemy_copy1) -> hp = 0;
        (*enemy_copy1) -> badstatus = DEAD;
        printf("%s<<DEAD\n", (*enemy_copy1) -> name);
      }
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else{
      target = 2;
      damage_base = ( ( ( (*enemy_copy1) -> lv + (*enemy_copy1) -> atk ) * 32 ) / 15 ) - (****st2) -> str * 2;
      eva_base = 3 + ( (****st2) -> agi * 0.2 ) + ( (****st2) -> luk * 0.1 ) - ( (*enemy_copy1) -> agi * 0.1) - ( (*enemy_copy1) -> luk * 0.1);   //回避率計算
    }
  }
  else if ( target_base == 3 ){   //３人目のメンバー
    if ( (****st3) -> physical_attack == -1 ){  //物理攻撃無効
      damage = -1;
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else if ( (****st3) -> physical_attack == -2 ){  //物理攻撃吸収
      damage_base = ( ( ( (*enemy_copy1) -> lv + (*enemy_copy1) -> atk ) * 32 ) / 15 ) - (****st3) -> str * 2;
      max_damage = damage_base * 1.3;
      temp = damage;
      damage = -2;
      (****st) -> hp += temp;
      if ( (****st3) -> hp > (****st3) -> maxhp ){
        (****st3) -> hp = (****st3) -> maxhp;
      }
      printf("Absorb!\n");
      sleep(1);
      printf("%s<<%dダメージ吸収\n", (****st3) -> name, temp);
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else if ( (****st3) -> physical_attack == -3 ){  //物理攻撃反射
      damage_base = ( ( ( (*enemy_copy1) -> lv + (*enemy_copy1) -> atk ) * 32 ) / 15 ) - (****st3) -> str * 2;
      max_damage = damage_base * 1.3;
      temp = damage;
      damage = -3;
      (*enemy_copy1) -> hp -= temp;
      printf("Reflect!\n");
      sleep(1);
      printf("%s<<%dダメージ\n", (*enemy_copy1) -> name, temp);
      if ( (*enemy_copy1) -> hp <= 0 ){
        (*enemy_copy1) -> hp = 0;
        (*enemy_copy1) -> badstatus = DEAD;
        printf("%s<<DEAD\n", (*enemy_copy1) -> name);
      }
      turn_decrease = -2;
      enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
      return enemy_turn;
    }
    else{
      target = 3;
      damage_base = ( ( ( (*enemy_copy1) -> lv + (*enemy_copy1) -> atk ) * 32 ) / 15 ) - (****st3) -> str * 2;
      eva_base = 3 + ( (****st3) -> agi * 0.2 ) + ( (****st3) -> luk * 0.1 ) - ( (*enemy_copy1) -> agi * 0.1) - ( (*enemy_copy1) -> luk * 0.1);   //回避率計算
    }
  }

  //printf("target:%d\n", target);

  //printf("before eva_base = %f\n", eva_base);
  eva_base = round(eva_base);
  //printf("after eva_base = %f\n", eva_base);

  if ( eva_base < 3 ){
    eva_base = 3;     //回避率最小値3%
  }

  eva = (rand() % ( 100 - 1 + 1 ) + 1);  //回避率の乱数
  //printf("eva number = %d\n", eva);

  for ( i = 3; i <= eva_base; i++ ){
    if ( eva_base == i ){
      if ( eva >= 1 && eva <= i ){   //回避率eva_base%
        damage = 0;
        printf("MISS!\n");
        eva_count++;
        turn_decrease = -2;
        enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        return enemy_turn;
      }
    }
  }

  if ( eva_count == 0 ){
    if ( target == 1 ){
      critical_base = 1 + ( (*enemy_copy1) -> luk * 0.2) - ( (****st) -> luk * 0.1);  //critical率の計算
      if ( critical_base < 1 ){
        critical_base = 1;       //critical最小値1%
      }
    }
    else if ( target == 2 ){
      critical_base = 1 + ( (*enemy_copy1) -> luk * 0.2) - ( (****st2) -> luk * 0.1);  //critical率の計算
      if ( critical_base < 1 ){
        critical_base = 1;       //critical最小値1%
      }
    }
    else if ( target == 3 ){
      critical_base = 1 + ( (*enemy_copy1) -> luk * 0.2) - ( (****st3) -> luk * 0.1);  //critical率の計算
      if ( critical_base < 1 ){
        critical_base = 1;       //critical最小値1%
      }
    }
    //printf("before critical_base = %f\n", critical_base);
    critical_base = round(critical_base);
    //printf("after critical_base = %f\n", critical_base);

    critical = (rand() % ( 100 - 1 + 1 ) + 1);   //critical率の乱数
    //printf("critical number = %d\n", critical);

    for ( i = 1; i <= critical_base; i++ ){
      if ( critical_base == i ){
        if ( critical >= 1 && critical <= i ){   //回避率critical_base%
          max_damage = damage_base * 1.3;   //ダメージの最大乱数はdamage_baseの1.3倍
          sleep(1);
          printf("CRITICAL!!\n");
          damage = (rand() % ( max_damage - damage_base + 1 )) + damage_base; //(rand()%(max - min + 1)) + min;
          damage *= 2;     //criticalでダメージ2倍
          critical_count++;

          turn_decrease = 0.1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
      }
    }

    max_damage = damage_base * 1.3;
    if ( critical_count == 0 ){
      damage = (rand() % ( max_damage - damage_base + 1) ) + damage_base; //(rand()%(max - min + 1)) + min;
      //味方の耐性判断
      if ( target == 1 ){
        if ( (****st) -> physical_attack == 100 ){
          damage = damage;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st) -> physical_attack == 150 ){     //物理攻撃1.5倍
          damage *= 1.5;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st) -> physical_attack == 200 ){
          sleep(1);
          printf("WEAKNESS!!\n");
          damage *= 2;
          turn_decrease = 0.1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st) -> physical_attack == 80 ){  //物理攻撃ダメージ80%
          damage *= 0.8;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st) -> physical_attack == 50 ){  //物理攻撃半減
          sleep(1);
          printf("RESIST!\n");
          damage *= 0.5;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st) -> physical_attack == 25 ){  //物理攻撃ダメージ25%
          sleep(1);
          printf("RESIST!\n");
          damage *= 0.25;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }

        if ( player_guard == 1 ){
          damage /= 1.6;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
      }
      else if ( target == 2 ){
        if ( (****st2) -> physical_attack == 100 ){
          damage = damage;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st2) -> physical_attack == 150 ){     //物理攻撃1.5倍
          damage *= 1.5;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st2) -> physical_attack == 200 ){
          sleep(1);
          printf("WEAKNESS!!\n");
          damage *= 2;
          turn_decrease = 0.1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st2) -> physical_attack == 80 ){  //物理攻撃ダメージ80%
          damage *= 0.8;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st2) -> physical_attack == 50 ){  //物理攻撃半減
          sleep(1);
          printf("RESIST!\n");
          damage *= 0.5;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st2) -> physical_attack == 25 ){  //物理攻撃ダメージ25%
          sleep(1);
          printf("RESIST!\n");
          damage *= 0.25;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }

        if ( player_guard2 == 1 ){
          damage /= 1.6;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }

      }
      else if ( target == 3 ){
        if ( (****st3) -> physical_attack == 100 ){
          damage = damage;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st3) -> physical_attack == 150 ){     //物理攻撃1.5倍
          damage *= 1.5;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st3) -> physical_attack == 200 ){
          sleep(1);
          printf("WEAKNESS!!\n");
          damage *= 2;
          turn_decrease = 0.1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st3) -> physical_attack == 80 ){  //物理攻撃ダメージ80%
          damage *= 0.8;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st3) -> physical_attack == 50 ){  //物理攻撃半減
          sleep(1);
          printf("RESIST!\n");
          damage *= 0.5;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
        else if ( (****st3) -> physical_attack == 25 ){  //物理攻撃ダメージ25%
          sleep(1);
          printf("RESIST!\n");
          damage *= 0.25;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }

        if ( player_guard3 == 1 ){
          damage /= 1.6;
          turn_decrease = -1;
          enemy_turn = calculate_enemy_turn(enemy_turn, turn_decrease);
        }
      }
    }

    if ( target == 1 ){
      if ( damage >= (****st) -> hp ){
        sleep(1);
        printf("%s<<%dダメージ\n", (****st) -> name, damage);
        sleep(1);
        printf("%s<<DEAD\n", (****st) -> name);
        (****st) -> hp = 0;
        (****st) -> badstatus = DEAD;
      }
      else{
        printf("%s<<%dダメージ\n", (****st) -> name, damage);
        (****st) -> hp -= damage;
        if ( (****st) -> hp <= 0 ){
          (****st) -> hp = 0;
          (****st) -> badstatus = DEAD;
        }
      }
    }
    else if ( target == 2 ){
      if ( damage >= (****st2) -> hp ){
        sleep(1);
        printf("%s<<%dダメージ\n", (****st2) -> name, damage);
        sleep(1);
        printf("%s<<DEAD\n", (****st2) -> name);
        (****st2) -> hp = 0;
        (****st2) -> badstatus = DEAD;
      }
      else{
        printf("%s<<%dダメージ\n", (****st2) -> name, damage);
        (****st2) -> hp -= damage;
        if ( (****st2) -> hp <= 0 ){
          (****st2) -> hp = 0;
          (****st2) -> badstatus = DEAD;
        }
      }
    }
    else{
      if ( damage >= (****st2) -> hp ){
        sleep(1);
        printf("%s<<%dダメージ\n", (****st3) -> name, damage);
        sleep(1);
        printf("%s<<DEAD\n", (****st3) -> name);
        (****st3) -> hp = 0;
        (****st3) -> badstatus = DEAD;
      }
      else{
        printf("%s<<%dダメージ\n", (****st3) -> name, damage);
        (****st3) -> hp -= damage;
        if ( (****st3) -> hp <= 0 ){
          (****st3) -> hp = 0;
          (****st3) -> badstatus = DEAD;
        }
      }
    }
  }

  player_guard = 0;
  player_guard2 = 0;
  player_guard3 = 0;

  return enemy_turn;
}

void display_gameover(void){

  sleep(1);
  printf("・・・・・・\n");
  sleep(2);
  printf("あなた達には失望しましたよ\n");
  sleep(2);
  printf("やはり人間には荷が重すぎましたか・・・\n");
  printf("\n");
  sleep(1);
  printf("\a");
  printf("---------------\n");
  printf("---GAME OVER---\n");
  printf("---------------\n");

  exit(EXIT_SUCCESS);
}

void poison_effect(Player ****st){
  int poison_damage;

  poison_damage = (***st) -> maxhp * 0.15;
  (***st) -> hp -= poison_damage;
  if ( (***st) -> hp <= 0 ){
    printf("%sは毒により%dダメージを受けた!\n", (***st) -> name, poison_damage);
    printf("%s<<DEAD\n");
    (***st) -> badstatus = DEAD;
  }
  else{
    printf("%sは毒により%dダメージを受けた!\n", (***st) -> name, poison_damage);
  }
}


void enemy_data_copy(Enemy **enemy, Enemy *enemy_copy){

  strcpy(enemy_copy -> name, (*enemy) -> name);
  enemy_copy -> hp = (*enemy) -> hp;
  enemy_copy -> maxhp = (*enemy) -> maxhp;
  enemy_copy -> mp = (*enemy) -> maxmp;
  enemy_copy -> maxmp = (*enemy) -> maxmp;
  enemy_copy -> atk = (*enemy) -> atk;
  enemy_copy -> magic = (*enemy) -> magic;
  enemy_copy -> str = (*enemy) -> str;
  enemy_copy -> agi = (*enemy) -> agi;
  enemy_copy -> luk = (*enemy) -> luk;
  enemy_copy -> lv = (*enemy) -> lv;
  enemy_copy -> exp = (*enemy) -> exp;
  enemy_copy -> gold = (*enemy) -> gold;
  enemy_copy -> badstatus = (*enemy) -> badstatus;
  enemy_copy -> physical_attack = (*enemy) -> physical_attack;
  enemy_copy -> gun_attack = (*enemy) -> gun_attack;
  enemy_copy -> fire = (*enemy) -> fire;
  enemy_copy -> ice = (*enemy) -> ice;
  enemy_copy -> elec = (*enemy) -> elec;
  enemy_copy -> wave = (*enemy) -> wave;
  enemy_copy -> almighty = (*enemy) -> almighty;
  enemy_copy -> death = (*enemy) -> death;
  enemy_copy -> expel = (*enemy) -> expel;
  enemy_copy -> poison = (*enemy) -> poison;
  enemy_copy -> palyze = (*enemy) -> palyze;
  enemy_copy -> charm = (*enemy) -> charm;
  enemy_copy -> close = (*enemy) -> close;
  enemy_copy -> stone = (*enemy) -> stone;
  enemy_copy -> panic = (*enemy) -> panic;
  enemy_copy -> sleep = (*enemy) -> sleep;
  enemy_copy -> curse = (*enemy) -> curse;
  enemy_copy -> boss_count = (*enemy) -> boss_count;
  enemy_copy -> enemy_id = (*enemy) -> enemy_id;
}

//encount_pattern = 1; 敵１体
//encount_pattern = 2; 同じ敵2体
//encount_pattern = 3; 同じ敵３体
//encount_pattern = 4; 同じ敵４体
//encount_pattern = 5; 違う敵２体
//encount_pattern = 6; 違う敵３体
//encount_pattern = 7; 違う敵４体
//encount_pattern = 8; 敵４体(敵２体を１グループとして２グループ)

//未実装
//encount_pattern = 9; 敵４体(同じ敵３体と違う敵１体)
//encount_pattern = 10; 敵３体(同じ敵２体と違う敵１体)

int battle_escape(Player ****st, int *escape_number){
  int escape, i;
  double escape_base;
  int escape_min; //逃走確率の最小値

  escape_min = 30 + 15 * (*escape_number);
  //printf("escape_min:%d\n", escape_min);
  escape_base = escape_min + ( (***st) -> agi * 0.2 + (***st) -> luk * 0.2);   //逃走確率の最小値30% + 逃走を選択したキャラの速と運の値
  escape_base = round(escape_base);
  if ( escape_base > 100 ){
    escape_base = 100;
  }
  //printf("escape_base = %f\n", escape_base);
  escape = (rand() % ( 100 - 1 + 1 ) + 1);
  //printf("escape number = %d\n", escape);
  for ( i = 1; i <= escape_base; i++ ){
    if ( i == escape ){
      printf("逃走成功!!\n");
      printf("%s達は戦闘から逃走した!\n", (***st) -> name);
      return 1;
    }
  }

  //for文を抜けた場合逃走失敗
  printf("逃走失敗\n");
  *escape_number += 1;
  return -1;

}

//player_turnについては株式会社ATLUSのRPGで多く用いられているプレスターンバトルシステムを参考
double calculate_player_turn(double player_turn, double turn_decrease){

  if ( turn_decrease == -1 ){  //ターンを1消費
    if ( player_turn == 3 || player_turn == 2 || player_turn == 1 || player_turn == 0 ){
      player_turn += turn_decrease;
    }
    else if ( player_turn == 3.3 ){
      player_turn = 2.2;
    }
    else if ( player_turn == 3.2 ){
      player_turn = 2.1;
    }
    else if ( player_turn == 3.1 ){
      player_turn = 2.0;
    }
    else if ( player_turn == 2.2 ){
      player_turn = 1.1;
    }
    else if ( player_turn == 1.1 ){
      player_turn = 0;
    }
    else if ( player_turn == 2.1 ){
      player_turn = 1;
    }
  }
  else if ( turn_decrease == -2 ){
    if ( player_turn == 3 || player_turn == 2 || player_turn == 1 ){
      player_turn += turn_decrease;
      //printf("%f\n", player_turn);
      if ( player_turn < 0 ){
        player_turn = 0;
      }
    }
    else if ( player_turn == 1.1 || player_turn == 2.1 || player_turn == 2.2 ){
      player_turn = 0;
    }
    else if ( player_turn == 3.3 ){
      player_turn = 1.1;
    }
    else if ( player_turn == 3.2 ){
      player_turn = 1;
    }
    else if ( player_turn == 3.1 ){
      player_turn = 1;
    }
  }
  else if ( turn_decrease == TURNCHAGE ){
    player_turn = 0.0;
  }
  //プレスターン増加
  else if ( turn_decrease == 0.1 ){
    if ( player_turn == 3 || player_turn == 2 || player_turn == 1 ){
      player_turn += turn_decrease;
    }
    else if ( player_turn == 1.1 ){
      player_turn = 0;
    }
    else if ( player_turn == 2.1 ){
      player_turn = 2.2;
    }
    else if ( player_turn == 2.2 ){
      player_turn = 1.1;
    }
    else if ( player_turn == 3.1 ){
      player_turn = 3.2;
    }
    else if ( player_turn == 3.2 ){
      player_turn = 3.3;
    }
    else if ( player_turn == 3.3 ){
      player_turn = 2.2;
    }
  }
  //turn消費無し
  else if ( turn_decrease == 0.0 ){
    player_turn = player_turn;
  }

  return player_turn;
}

void display_player_turn(Player ****st, double player_turn){
  //弱点を付くと〇が◎になる
  //◎を0.1、２つ目の◎を0.2、３つ目の◎を0.3とカウント
  if ( player_turn == 3.0 ){
    printf("%sのTURN! (PLAYER TURN: 〇〇〇)\n", (***st) -> name);
  }
  else if ( player_turn == 2.0 ){
    printf("%sのTURN! (PLAYER TURN: 〇〇)\n", (***st) -> name);
  }
  else if ( player_turn == 1.0 ){
    printf("%sのTURN! (PLAYER TURN: 〇)\n", (***st) -> name);
  }
  else if ( player_turn == 1.1 ){
    printf("%sのTURN! (PLAYER TURN: ◎)\n", (***st) -> name);
  }
  else if ( player_turn == 2.1 ){
    printf("%sのTURN! (PLAYER TURN: ◎〇)\n", (***st) -> name);
  }
  else if ( player_turn == 2.2 ){
    printf("%sのTURN! (PLAYER TURN: ◎◎)\n", (***st) -> name);
  }
  else if ( player_turn == 3.1 ){
    printf("%sのTURN! (PLAYER TURN: ◎〇〇)\n", (***st) -> name);
  }
  else if ( player_turn == 3.2 ){
    printf("%sのTURN! (PLAYER TURN: ◎◎〇)\n", (***st) -> name);
  }
  else if ( player_turn == 3.3 ){
    printf("%sのTURN! (PLAYER TURN: ◎◎◎)\n", (***st) -> name);
  }
}

void display_enemy_turn(Enemy **enemy, double enemy_turn){

  if ( enemy_turn == 4 ){
    printf("%sのTURN! (ENEMY TURN: 〇〇〇〇)\n", (*enemy) -> name);
  }
  else if ( enemy_turn == 3 ){
    printf("%sのTURN! (ENEMY TURN: 〇〇〇)\n", (*enemy) -> name);
  }
  else if ( enemy_turn == 2 ){
    printf("%sのTURN! (ENEMY TURN: 〇〇)\n", (*enemy) -> name);
  }
  else if ( enemy_turn == 1 ){
    printf("%sのTURN! (ENEMY TURN: 〇)\n", (*enemy) -> name);
  }
  else if ( enemy_turn == 4.1 ){
    printf("%sのTURN! (ENEMY TURN: ◎〇〇〇)\n", (*enemy) -> name);
  }
  else if ( enemy_turn == 4.2 ){
    printf("%sのTURN! (ENEMY TURN: ◎◎〇〇)\n", (*enemy) -> name);
  }
  else if ( enemy_turn == 4.3 ){
    printf("%sのTURN! (ENEMY TURN: ◎◎◎〇)\n", (*enemy) -> name);
  }
  else if ( enemy_turn == 4.4 ){
    printf("%sのTURN! (ENEMY TURN: ◎◎◎◎)\n", (*enemy) -> name);
  }
  else if ( enemy_turn == 3.1 ){
    printf("%sのTURN! (ENEMY TURN: ◎〇〇)\n", (*enemy) -> name);
  }
  else if ( enemy_turn == 3.2 ){
    printf("%sのTURN! (ENEMY TURN: ◎◎〇)\n", (*enemy) -> name);
  }
  else if ( enemy_turn == 3.3 ){
    printf("%sのTURN! (ENEMY TURN: ◎◎◎)\n", (*enemy) -> name);
  }
  else if ( enemy_turn == 2.2 ){
    printf("%sのTURN! (ENEMY TURN: ◎◎)\n", (*enemy) -> name);
  }
  else if ( enemy_turn == 2.1 ){
    printf("%sのTURN! (ENEMY TURN: ◎〇)\n", (*enemy) -> name);
  }
  else if ( enemy_turn == 1.1 ){
    printf("%sのTURN! (ENEMY TURN: ◎)\n", (*enemy) -> name);
  }
}

void display_enemy_copy_turn(Enemy *enemy_copy1, double enemy_turn){

  if ( enemy_turn == 4 ){
    printf("%sのTURN! (ENEMY TURN: 〇〇〇〇)\n", enemy_copy1 -> name);
  }
  else if ( enemy_turn == 3 ){
    printf("%sのTURN! (ENEMY TURN: 〇〇〇)\n", enemy_copy1 -> name);
  }
  else if ( enemy_turn == 2 ){
    printf("%sのTURN! (ENEMY TURN: 〇〇)\n", enemy_copy1 -> name);
  }
  else if ( enemy_turn == 1 ){
    printf("%sのTURN! (ENEMY TURN: 〇)\n", enemy_copy1 -> name);
  }
  else if ( enemy_turn == 4.1 ){
    printf("%sのTURN! (ENEMY TURN: ◎〇〇〇)\n", enemy_copy1 -> name);
  }
  else if ( enemy_turn == 4.2 ){
    printf("%sのTURN! (ENEMY TURN: ◎◎〇〇)\n", enemy_copy1 -> name);
  }
  else if ( enemy_turn == 4.3 ){
    printf("%sのTURN! (ENEMY TURN: ◎◎◎〇)\n", enemy_copy1 -> name);
  }
  else if ( enemy_turn == 4.4 ){
    printf("%sのTURN! (ENEMY TURN: ◎◎◎◎)\n", enemy_copy1 -> name);
  }
  else if ( enemy_turn == 3.1 ){
    printf("%sのTURN! (ENEMY TURN: ◎〇〇)\n", enemy_copy1 -> name);
  }
  else if ( enemy_turn == 3.2 ){
    printf("%sのTURN! (ENEMY TURN: ◎◎〇)\n", enemy_copy1 -> name);
  }
  else if ( enemy_turn == 3.3 ){
    printf("%sのTURN! (ENEMY TURN: ◎◎◎)\n", enemy_copy1 -> name);
  }
  else if ( enemy_turn == 2.2 ){
    printf("%sのTURN! (ENEMY TURN: ◎◎)\n", enemy_copy1 -> name);
  }
  else if ( enemy_turn == 2.1 ){
    printf("%sのTURN! (ENEMY TURN: ◎〇)\n", enemy_copy1 -> name);
  }
  else if ( enemy_turn == 1.1 ){
    printf("%sのTURN! (ENEMY TURN: ◎)\n", enemy_copy1 -> name);
  }
}

int is_skill_learning(P_skill ****player_skill){

  //2回目以降の処理での判断
  /*if ( tempArray[0] == TRUE ){
  return TRUE;
}*/

if ( (***player_skill) -> recover1[0] == LEARNING ){
  return TRUE;
}
else if ( (***player_skill) -> cure_poison[0] == LEARNING ){
  return TRUE;
}
else if ( (***player_skill) -> recover2[0] == LEARNING ){
  return TRUE;
}
else if ( (***player_skill) -> enfa[0] == LEARNING ){
  return TRUE;
}

return FALSE;
}

void add_battleExperience(Player ****st, P_skill ****player_skill, int battle_experience){

  if ( (***player_skill) -> recover1[0] == LEARNING ){
    (***player_skill) -> recover1[2] += battle_experience;
    if ( (***player_skill) -> recover1[2] >= (***player_skill) -> recover1[3] ){
      printf("%sはケディアを習得した!!\n", (***st) -> name);
      (***player_skill) -> recover1[0] = LEARNED;
    }
  }
  else if ( (***player_skill) -> cure_poison[0] == LEARNING ){
    (***player_skill) -> cure_poison[2] += battle_experience;
    if ( (***player_skill) -> cure_poison[2] >= (***player_skill) -> cure_poison[3] ){
      printf("%sはキュアポを習得した!!\n", (***st) -> name);
      (***player_skill) -> cure_poison[0] = LEARNED;
    }
  }
  else if ( (***player_skill) -> recover2[0] == LEARNING ){
    (***player_skill) -> recover2[2] += battle_experience;
    if ( (***player_skill) -> recover2[2] >= (***player_skill) -> recover2[3] ){
      printf("%sはケディアスを習得した!!\n", (***st) -> name);
      (***player_skill) -> recover2[0] = LEARNED;
    }
  }
  else if ( (***player_skill) -> enfa[0] == LEARNING ){
    (***player_skill) -> enfa[2] += battle_experience;
    if ( (***player_skill) -> enfa[2] >= (***player_skill) -> enfa[3] ){
      printf("%sはエンファを習得した!!\n", (***st) -> name);
      (***player_skill) -> enfa[0] = LEARNED;
    }
  }

}
