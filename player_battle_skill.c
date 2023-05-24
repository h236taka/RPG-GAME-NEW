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

void skillEffect_RECOVER_forBattle(Player *****st, Player *****st2, Player *****st3, int skill_target, int recover_point){
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

void skillEffect_RECOVERBADSTATUS_forBattle(Player *****st, Player *****st2, Player *****st3, int skill_target, int badstatus){

  if ( skill_target == PLAYER ){
    if ( (****st) -> badstatus == badstatus ){
      (****st) -> badstatus = GOOD;
      printf("%sの状態異常は消えた!\n", (****st) -> name);
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
      printf("%sの状態異常は消えた!\n", (****st2) -> name);
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
      printf("%sの状態異常は消えた!\n", (****st3) -> name);
      printf("\n");
    }
    else{
      printf("無効果\n");
      printf("\n");
    }
  }
}

void analyze_enemyCopy_skill(Enemy **enemy_copy){

  printf("%sのステータスを表示します...\n", (*enemy_copy) -> name);
  sleep(1);
  if ( (*enemy_copy) -> boss_count != 0 ){
    printf("ステータスをアナライズ出来ませんでした...\n");
    printf("\n");
    return;
  }

  printf("%s LV:%d\n", (*enemy_copy) -> name, (*enemy_copy) -> lv);
  printf("HP:%d/%d MP:%d/%d\n", (*enemy_copy) -> hp, (*enemy_copy) -> maxhp, (*enemy_copy) -> mp, (*enemy_copy) -> maxmp);
  printf("力:%d\n", (*enemy_copy) -> atk);
  printf("魔:%d\n", (*enemy_copy) -> magic);
  printf("体:%d\n", (*enemy_copy) -> str);
  printf("速:%d\n", (*enemy_copy) -> agi);
  printf("運:%d\n", (*enemy_copy) -> luk);
  printf("所持スキル:");
  if ( (*enemy_copy) -> enemy_id == SLIME || (*enemy_copy) -> enemy_id == KOBALT || (*enemy_copy) -> enemy_id == ZOMBIEDOG ){
    printf("なし\n");
  }
  else{
    if ( (*enemy_copy) -> enemy_id == GHOUL ){
      printf("ポイゾガ\n");
    }
    else if ( (*enemy_copy) -> enemy_id == ZOMBIE ){
      printf("パララズ\n");
    }
    else if ( (*enemy_copy) -> enemy_id == GOBLINNORMAL ){
      printf("クエイク\n");
    }
    else if ( (*enemy_copy) -> enemy_id == ONMORAKI ){
      printf("エンファ\n");
    }
  }

  //耐性表示
  if ( (*enemy_copy) -> physical_attack == 200 ){
    printf("物理弱点 ");
  }
  else if ( (*enemy_copy) -> physical_attack == 25 || (*enemy_copy) -> physical_attack == 50 || (*enemy_copy) -> physical_attack == 75 ){
    printf("物理耐性 ");
  }
  else if ( (*enemy_copy) -> physical_attack == -1 ){
    printf("物理無効 ");
  }
  else if ( (*enemy_copy) -> physical_attack == -2 ){
    printf("物理吸収 ");
  }
  else if ( (*enemy_copy) -> physical_attack == -3 ){
    printf("物理反射 ");
  }

  if ( (*enemy_copy) -> gun_attack == 200 ){
    printf("銃撃弱点 ");
  }
  else if ( (*enemy_copy) -> gun_attack == 25 || (*enemy_copy) -> gun_attack == 50 || (*enemy_copy) -> gun_attack == 75 ){
    printf("銃撃耐性 ");
  }
  else if ( (*enemy_copy) -> gun_attack == -1 ){
    printf("銃撃無効 ");
  }
  else if ( (*enemy_copy) -> gun_attack == -2 ){
    printf("銃撃吸収 ");
  }
  else if ( (*enemy_copy) -> gun_attack == -3 ){
    printf("銃撃反射 ");
  }

  if ( (*enemy_copy) -> fire == 200 ){
    printf("火炎弱点 ");
  }
  else if ( (*enemy_copy) -> fire == 25 || (*enemy_copy) -> fire == 50 || (*enemy_copy) -> fire == 75 ){
    printf("火炎耐性 ");
  }
  else if ( (*enemy_copy) -> fire == -1 ){
    printf("火炎無効 ");
  }
  else if ( (*enemy_copy) -> fire == -2 ){
    printf("火炎吸収 ");
  }
  else if ( (*enemy_copy) -> fire == -3 ){
    printf("火炎反射 ");
  }

  if ( (*enemy_copy) -> ice == 200 ){
    printf("氷結弱点 ");
  }
  else if ( (*enemy_copy) -> ice == 25 || (*enemy_copy) -> ice == 50 || (*enemy_copy) -> ice == 75 ){
    printf("氷結耐性 ");
  }
  else if ( (*enemy_copy) -> ice == -1 ){
    printf("氷結無効 ");
  }
  else if ( (*enemy_copy) -> ice == -2 ){
    printf("氷結吸収 ");
  }
  else if ( (*enemy_copy) -> ice == -3 ){
    printf("氷結反射 ");
  }

  if ( (*enemy_copy) -> elec == 200 ){
    printf("電撃弱点 ");
  }
  else if ( (*enemy_copy) -> elec == 25 || (*enemy_copy) -> elec == 50 || (*enemy_copy) -> elec == 75 ){
    printf("電撃耐性 ");
  }
  else if ( (*enemy_copy) -> elec == -1 ){
    printf("電撃無効 ");
  }
  else if ( (*enemy_copy) -> elec == -2 ){
    printf("電撃吸収 ");
  }
  else if ( (*enemy_copy) -> elec == -3 ){
    printf("電撃反射 ");
  }

  if ( (*enemy_copy) -> wave == 200 ){
    printf("衝撃弱点 ");
  }
  else if ( (*enemy_copy) -> wave == 25 || (*enemy_copy) -> wave == 50 || (*enemy_copy) -> wave == 75 ){
    printf("衝撃耐性 ");
  }
  else if ( (*enemy_copy) -> wave == -1 ){
    printf("衝撃無効 ");
  }
  else if ( (*enemy_copy) -> wave == -2 ){
    printf("衝撃吸収 ");
  }
  else if ( (*enemy_copy) -> wave == -3 ){
    printf("衝撃反射 ");
  }

  if ( (*enemy_copy) -> almighty == 25 || (*enemy_copy) -> almighty == 50 || (*enemy_copy) -> almighty == 75 ){
    printf("万能耐性 ");
  }

  if ( (*enemy_copy) -> death == 200 ){
    printf("呪殺弱点 ");
  }
  else if ( (*enemy_copy) -> death == 25 || (*enemy_copy) -> death == 50 || (*enemy_copy) -> death == 75 ){
    printf("呪殺耐性 ");
  }
  else if ( (*enemy_copy) -> death == -1 ){
    printf("呪殺無効 ");
  }
  else if ( (*enemy_copy) -> death == -2 ){
    printf("呪殺吸収 ");
  }
  else if ( (*enemy_copy) -> death == -3 ){
    printf("呪殺反射 ");
  }

  if ( (*enemy_copy) -> expel == 200 ){
    printf("破魔弱点 ");
  }
  else if ( (*enemy_copy) -> expel == 25 || (*enemy_copy) -> expel == 50 || (*enemy_copy) -> expel == 75 ){
    printf("破魔耐性 ");
  }
  else if ( (*enemy_copy) -> expel == -1 ){
    printf("破魔無効 ");
  }
  else if ( (*enemy_copy) -> expel == -2 ){
    printf("破魔吸収 ");
  }
  else if ( (*enemy_copy) -> expel == -3 ){
    printf("破魔反射 ");
  }

  if ( (*enemy_copy) -> poison == -1 && (*enemy_copy) -> palyze == -1 && (*enemy_copy) -> charm == -1 && (*enemy_copy) -> close == -1 && (*enemy_copy) -> stone == -1 && (*enemy_copy) -> panic == -1 && (*enemy_copy) -> sleep == -1 && (*enemy_copy) -> curse == -1 ){
    printf("バットステータス無効\n");
    return;
  }

  if ( (*enemy_copy) -> poison == 200 ){
    printf("毒弱点 ");
  }
  else if ( (*enemy_copy) -> poison == 25 || (*enemy_copy) -> poison == 50 || (*enemy_copy) -> poison == 75 ){
    printf("毒耐性 ");
  }
  else if ( (*enemy_copy) -> poison == -1 ){
    printf("毒無効 ");
  }
  else if ( (*enemy_copy) -> poison == -2 ){
    printf("毒吸収 ");
  }
  else if ( (*enemy_copy) -> poison == -3 ){
    printf("毒反射 ");
  }

  if ( (*enemy_copy) -> palyze == 200 ){
    printf("麻痺弱点 ");
  }
  else if ( (*enemy_copy) -> palyze == 25 || (*enemy_copy) -> palyze == 50 || (*enemy_copy) -> palyze == 75 ){
    printf("麻痺耐性 ");
  }
  else if ( (*enemy_copy) -> palyze == -1 ){
    printf("麻痺無効 ");
  }
  else if ( (*enemy_copy) -> palyze == -2 ){
    printf("麻痺吸収 ");
  }
  else if ( (*enemy_copy) -> palyze == -3 ){
    printf("麻痺反射 ");
  }

  if ( (*enemy_copy) -> charm == 200 ){
    printf("魅了弱点 ");
  }
  else if ( (*enemy_copy) -> charm == 25 || (*enemy_copy) -> charm == 50 || (*enemy_copy) -> charm == 75 ){
    printf("魅了耐性 ");
  }
  else if ( (*enemy_copy) -> charm == -1 ){
    printf("魅了無効 ");
  }
  else if ( (*enemy_copy) -> charm == -2 ){
    printf("魅了吸収 ");
  }
  else if ( (*enemy_copy) -> charm == -3 ){
    printf("魅了反射 ");
  }

  if ( (*enemy_copy) -> close == 200 ){
    printf("魔封弱点 ");
  }
  else if ( (*enemy_copy) -> close == 25 || (*enemy_copy) -> close == 50 || (*enemy_copy) -> close == 75 ){
    printf("魔封耐性 ");
  }
  else if ( (*enemy_copy) -> close == -1 ){
    printf("魔封無効 ");
  }
  else if ( (*enemy_copy) -> close == -2 ){
    printf("魔封吸収 ");
  }
  else if ( (*enemy_copy) -> close == -3 ){
    printf("魔封反射 ");
  }

  if ( (*enemy_copy) -> stone == 200 ){
    printf("石化弱点 ");
  }
  else if ( (*enemy_copy) -> stone == 25 || (*enemy_copy) -> stone == 50 || (*enemy_copy) -> stone == 75 ){
    printf("石化耐性 ");
  }
  else if ( (*enemy_copy) -> stone == -1 ){
    printf("石化無効 ");
  }
  else if ( (*enemy_copy) -> stone == -2 ){
    printf("石化吸収 ");
  }
  else if ( (*enemy_copy) -> stone == -3 ){
    printf("石化反射 ");
  }

  if ( (*enemy_copy) -> panic == 200 ){
    printf("混乱弱点 ");
  }
  else if ( (*enemy_copy) -> panic == 25 || (*enemy_copy) -> panic == 50 || (*enemy_copy) -> panic == 75 ){
    printf("混乱耐性 ");
  }
  else if ( (*enemy_copy) -> panic == -1 ){
    printf("混乱無効 ");
  }
  else if ( (*enemy_copy) -> panic == -2 ){
    printf("混乱吸収 ");
  }
  else if ( (*enemy_copy) -> panic == -3 ){
    printf("混乱反射 ");
  }

  if ( (*enemy_copy) -> sleep == 200 ){
    printf("睡眠弱点 ");
  }
  else if ( (*enemy_copy) -> sleep == 25 || (*enemy_copy) -> sleep == 50 || (*enemy_copy) -> sleep == 75 ){
    printf("睡眠耐性 ");
  }
  else if ( (*enemy_copy) -> sleep == -1 ){
    printf("睡眠無効 ");
  }
  else if ( (*enemy_copy) -> sleep == -2 ){
    printf("睡眠吸収 ");
  }
  else if ( (*enemy_copy) -> sleep == -3 ){
    printf("睡眠反射 ");
  }

  if ( (*enemy_copy) -> curse == 200 ){
    printf("呪い弱点 ");
  }
  else if ( (*enemy_copy) -> curse == 25 || (*enemy_copy) -> curse == 50 || (*enemy_copy) -> curse == 75 ){
    printf("呪い耐性 ");
  }
  else if ( (*enemy_copy) -> curse == -1 ){
    printf("呪い無効 ");
  }
  else if ( (*enemy_copy) -> curse == -2 ){
    printf("呪い吸収 ");
  }
  else if ( (*enemy_copy) -> curse == -3 ){
    printf("呪い反射 ");
  }

  printf("\n");
  printf("\n");

}

void analyze_enemy_skill(Enemy ***enemy){

  printf("%sのステータスを表示します...\n", (**enemy) -> name);
  sleep(1);
  if ( (**enemy) -> boss_count != 0 ){
    printf("ステータスをアナライズ出来ませんでした...\n");
    printf("\n");
    return;
  }

  printf("%s LV:%d\n", (**enemy) -> name, (**enemy) -> lv);
  printf("HP:%d/%d MP:%d/%d\n", (**enemy) -> hp, (**enemy) -> maxhp, (**enemy) -> mp, (**enemy) -> maxmp);
  printf("力:%d\n", (**enemy) -> atk);
  printf("魔:%d\n", (**enemy) -> magic);
  printf("体:%d\n", (**enemy) -> str);
  printf("速:%d\n", (**enemy) -> agi);
  printf("運:%d\n", (**enemy) -> luk);
  printf("所持スキル:");
  if ( (**enemy) -> enemy_id == SLIME || (**enemy) -> enemy_id == KOBALT || (**enemy) -> enemy_id == ZOMBIEDOG ){
    printf("なし\n");
  }
  else{
    if ( (**enemy) -> enemy_id == GHOUL ){
      printf("ポイゾガ\n");
    }
    else if ( (**enemy) -> enemy_id == ZOMBIE ){
      printf("パララズ\n");
    }
    else if ( (**enemy) -> enemy_id == GOBLINNORMAL ){
      printf("クエイク\n");
    }
    else if ( (**enemy) -> enemy_id == ONMORAKI ){
      printf("エンファ\n");
    }

  }

  //耐性表示
  if ( (**enemy) -> physical_attack == 200 ){
    printf("物理弱点 ");
  }
  else if ( (**enemy) -> physical_attack == 25 || (**enemy) -> physical_attack == 50 || (**enemy) -> physical_attack == 75 ){
    printf("物理耐性 ");
  }
  else if ( (**enemy) -> physical_attack == -1 ){
    printf("物理無効 ");
  }
  else if ( (**enemy) -> physical_attack == -2 ){
    printf("物理吸収 ");
  }
  else if ( (**enemy) -> physical_attack == -3 ){
    printf("物理反射 ");
  }

  if ( (**enemy) -> gun_attack == 200 ){
    printf("銃撃弱点 ");
  }
  else if ( (**enemy) -> gun_attack == 25 || (**enemy) -> gun_attack == 50 || (**enemy) -> gun_attack == 75 ){
    printf("銃撃耐性 ");
  }
  else if ( (**enemy) -> gun_attack == -1 ){
    printf("銃撃無効 ");
  }
  else if ( (**enemy) -> gun_attack == -2 ){
    printf("銃撃吸収 ");
  }
  else if ( (**enemy) -> gun_attack == -3 ){
    printf("銃撃反射 ");
  }

  if ( (**enemy) -> fire == 200 ){
    printf("火炎弱点 ");
  }
  else if ( (**enemy) -> fire == 25 || (**enemy) -> fire == 50 || (**enemy) -> fire == 75 ){
    printf("火炎耐性 ");
  }
  else if ( (**enemy) -> fire == -1 ){
    printf("火炎無効 ");
  }
  else if ( (**enemy) -> fire == -2 ){
    printf("火炎吸収 ");
  }
  else if ( (**enemy) -> fire == -3 ){
    printf("火炎反射 ");
  }

  if ( (**enemy) -> ice == 200 ){
    printf("氷結弱点 ");
  }
  else if ( (**enemy) -> ice == 25 || (**enemy) -> ice == 50 || (**enemy) -> ice == 75 ){
    printf("氷結耐性 ");
  }
  else if ( (**enemy) -> ice == -1 ){
    printf("氷結無効 ");
  }
  else if ( (**enemy) -> ice == -2 ){
    printf("氷結吸収 ");
  }
  else if ( (**enemy) -> ice == -3 ){
    printf("氷結反射 ");
  }

  if ( (**enemy) -> elec == 200 ){
    printf("電撃弱点 ");
  }
  else if ( (**enemy) -> elec == 25 || (**enemy) -> elec == 50 || (**enemy) -> elec == 75 ){
    printf("電撃耐性 ");
  }
  else if ( (**enemy) -> elec == -1 ){
    printf("電撃無効 ");
  }
  else if ( (**enemy) -> elec == -2 ){
    printf("電撃吸収 ");
  }
  else if ( (**enemy) -> elec == -3 ){
    printf("電撃反射 ");
  }

  if ( (**enemy) -> wave == 200 ){
    printf("衝撃弱点 ");
  }
  else if ( (**enemy) -> wave == 25 || (**enemy) -> wave == 50 || (**enemy) -> wave == 75 ){
    printf("衝撃耐性 ");
  }
  else if ( (**enemy) -> wave == -1 ){
    printf("衝撃無効 ");
  }
  else if ( (**enemy) -> wave == -2 ){
    printf("衝撃吸収 ");
  }
  else if ( (**enemy) -> wave == -3 ){
    printf("衝撃反射 ");
  }

  if ( (**enemy) -> almighty == 25 || (**enemy) -> almighty == 50 || (**enemy) -> almighty == 75 ){
    printf("万能耐性 ");
  }

  if ( (**enemy) -> death == 200 ){
    printf("呪殺弱点 ");
  }
  else if ( (**enemy) -> death == 25 || (**enemy) -> death == 50 || (**enemy) -> death == 75 ){
    printf("呪殺耐性 ");
  }
  else if ( (**enemy) -> death == -1 ){
    printf("呪殺無効 ");
  }
  else if ( (**enemy) -> death == -2 ){
    printf("呪殺吸収 ");
  }
  else if ( (**enemy) -> death == -3 ){
    printf("呪殺反射 ");
  }

  if ( (**enemy) -> expel == 200 ){
    printf("破魔弱点 ");
  }
  else if ( (**enemy) -> expel == 25 || (**enemy) -> expel == 50 || (**enemy) -> expel == 75 ){
    printf("破魔耐性 ");
  }
  else if ( (**enemy) -> expel == -1 ){
    printf("破魔無効 ");
  }
  else if ( (**enemy) -> expel == -2 ){
    printf("破魔吸収 ");
  }
  else if ( (**enemy) -> expel == -3 ){
    printf("破魔反射 ");
  }

  if ( (**enemy) -> poison == -1 && (**enemy) -> palyze == -1 && (**enemy) -> charm == -1 && (**enemy) -> close == -1 && (**enemy) -> stone == -1 && (**enemy) -> panic == -1 && (**enemy) -> sleep == -1 && (**enemy) -> curse == -1 ){
    printf("バットステータス無効\n");
    return;
  }

  if ( (**enemy) -> poison == 200 ){
    printf("毒弱点 ");
  }
  else if ( (**enemy) -> poison == 25 || (**enemy) -> poison == 50 || (**enemy) -> poison == 75 ){
    printf("毒耐性 ");
  }
  else if ( (**enemy) -> poison == -1 ){
    printf("毒無効 ");
  }
  else if ( (**enemy) -> poison == -2 ){
    printf("毒吸収 ");
  }
  else if ( (**enemy) -> poison == -3 ){
    printf("毒反射 ");
  }

  if ( (**enemy) -> palyze == 200 ){
    printf("麻痺弱点 ");
  }
  else if ( (**enemy) -> palyze == 25 || (**enemy) -> palyze == 50 || (**enemy) -> palyze == 75 ){
    printf("麻痺耐性 ");
  }
  else if ( (**enemy) -> palyze == -1 ){
    printf("麻痺無効 ");
  }
  else if ( (**enemy) -> palyze == -2 ){
    printf("麻痺吸収 ");
  }
  else if ( (**enemy) -> palyze == -3 ){
    printf("麻痺反射 ");
  }

  if ( (**enemy) -> charm == 200 ){
    printf("魅了弱点 ");
  }
  else if ( (**enemy) -> charm == 25 || (**enemy) -> charm == 50 || (**enemy) -> charm == 75 ){
    printf("魅了耐性 ");
  }
  else if ( (**enemy) -> charm == -1 ){
    printf("魅了無効 ");
  }
  else if ( (**enemy) -> charm == -2 ){
    printf("魅了吸収 ");
  }
  else if ( (**enemy) -> charm == -3 ){
    printf("魅了反射 ");
  }

  if ( (**enemy) -> close == 200 ){
    printf("魔封弱点 ");
  }
  else if ( (**enemy) -> close == 25 || (**enemy) -> close == 50 || (**enemy) -> close == 75 ){
    printf("魔封耐性 ");
  }
  else if ( (**enemy) -> close == -1 ){
    printf("魔封無効 ");
  }
  else if ( (**enemy) -> close == -2 ){
    printf("魔封吸収 ");
  }
  else if ( (**enemy) -> close == -3 ){
    printf("魔封反射 ");
  }

  if ( (**enemy) -> stone == 200 ){
    printf("石化弱点 ");
  }
  else if ( (**enemy) -> stone == 25 || (**enemy) -> stone == 50 || (**enemy) -> stone == 75 ){
    printf("石化耐性 ");
  }
  else if ( (**enemy) -> stone == -1 ){
    printf("石化無効 ");
  }
  else if ( (**enemy) -> stone == -2 ){
    printf("石化吸収 ");
  }
  else if ( (**enemy) -> stone == -3 ){
    printf("石化反射 ");
  }

  if ( (**enemy) -> panic == 200 ){
    printf("混乱弱点 ");
  }
  else if ( (**enemy) -> panic == 25 || (**enemy) -> panic == 50 || (**enemy) -> panic == 75 ){
    printf("混乱耐性 ");
  }
  else if ( (**enemy) -> panic == -1 ){
    printf("混乱無効 ");
  }
  else if ( (**enemy) -> panic == -2 ){
    printf("混乱吸収 ");
  }
  else if ( (**enemy) -> panic == -3 ){
    printf("混乱反射 ");
  }

  if ( (**enemy) -> sleep == 200 ){
    printf("睡眠弱点 ");
  }
  else if ( (**enemy) -> sleep == 25 || (**enemy) -> sleep == 50 || (**enemy) -> sleep == 75 ){
    printf("睡眠耐性 ");
  }
  else if ( (**enemy) -> sleep == -1 ){
    printf("睡眠無効 ");
  }
  else if ( (**enemy) -> sleep == -2 ){
    printf("睡眠吸収 ");
  }
  else if ( (**enemy) -> sleep == -3 ){
    printf("睡眠反射 ");
  }

  if ( (**enemy) -> curse == 200 ){
    printf("呪い弱点 ");
  }
  else if ( (**enemy) -> curse == 25 || (**enemy) -> curse == 50 || (**enemy) -> curse == 75 ){
    printf("呪い耐性 ");
  }
  else if ( (**enemy) -> curse == -1 ){
    printf("呪い無効 ");
  }
  else if ( (**enemy) -> curse == -2 ){
    printf("呪い吸収 ");
  }
  else if ( (**enemy) -> curse == -3 ){
    printf("呪い反射 ");
  }

  printf("\n");
  printf("\n");

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
        skillEffect_RECOVER_forBattle(&st,&st2,&st3,skill_target,recover_point);
      }
    }
    else if ( skill_user == PLAYER2 ){
      printf("%s>>ケディア\n", (***st2) -> name);
      sleep(1);

      if ( check_playerMP(&st2,3) == TRUE ){
        base = 25;
        recover_point = (rand() % ( base + (***st2) -> magic * 3 + (***st2) -> luk - base + 1) ) + base; //(rand()%(max - min + 1)) + min;
        skillEffect_RECOVER_forBattle(&st,&st2,&st3,skill_target,recover_point);
      }
    }
    else if ( skill_user == PLAYER3 ){
      printf("%s>>ケディア\n", (***st3) -> name);
      sleep(1);

      if ( check_playerMP(&st3,3) == TRUE ){
        base = 25;
        recover_point = (rand() % ( base + (***st3) -> magic * 3 + (***st3) -> luk - base + 1) ) + base; //(rand()%(max - min + 1)) + min;
        skillEffect_RECOVER_forBattle(&st,&st2,&st3,skill_target,recover_point);
      }
    }
  }
  else if ( use_skill_count == CUREPOISON ){  //キュアポ
    //skill使用者
    if ( skill_user == PLAYER ){
      printf("%s>>キュアポ\n", (***st) -> name);
      sleep(1);

      if ( check_playerMP(&st,4) == TRUE ){
        skillEffect_RECOVERBADSTATUS_forBattle(&st,&st2,&st3,skill_target,POISON);
      }
    }
    else if ( skill_user == PLAYER2 ){
      printf("%s>>キュアポ\n", (***st2) -> name);
      sleep(1);

      if ( check_playerMP(&st2,4) == TRUE ){
        skillEffect_RECOVERBADSTATUS_forBattle(&st,&st2,&st3,skill_target,POISON);
      }
    }
    else if ( skill_user == PLAYER3 ){
      printf("%s>>キュアポ\n", (***st3) -> name);
      sleep(1);

      if ( check_playerMP(&st3,4) == TRUE ){
        skillEffect_RECOVERBADSTATUS_forBattle(&st,&st2,&st3,skill_target,POISON);
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

    damage_base = ( magic_power * (***st) -> magic ) / ( (*enemy) -> magic * 2 );
    if ( damage_base < 0 ){
      damage_base = 1;
    }
    max_damage = damage_base * 1.3;
    damage = (rand() % ( max_damage - damage_base + 1 )) + damage_base;

    turn_decrease = check_enemy_fireResist(&st,&enemy,damage);
  }
  else if ( use_skill_count == ANALYZE ){
    if ( check_playerMP(&st,3) != TRUE ){
      return -1;
    }
    analyze_enemy_skill(&enemy);
    turn_decrease = -1;
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

    damage_base = ( magic_power * (***st) -> magic ) / ( enemy_copy -> magic * 2 );
    if ( damage_base < 0 ){
      damage_base = 1;
    }
    max_damage = damage_base * 1.3;
    damage = (rand() % ( max_damage - damage_base + 1 )) + damage_base;
    turn_decrease = check_enemyCopy_fireResist(&st,&enemy_copy,damage);
  }
  else if ( use_skill_count == ANALYZE ){
    if ( check_playerMP(&st,3) != TRUE ){
      return -1;
    }
    printf("%sのステータスを表示します...\n", enemy_copy -> name);
    if ( enemy_copy -> boss_count != 0 ){
      printf("ステータスをアナライズ出来ませんでした...\n");
    }
    else{
      analyze_enemyCopy_skill(&enemy_copy);
    }
    turn_decrease = -1;
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
  else if ( (****setting_skill) -> set_skill[idx] == ANALYZE ){
    printf("%d:アナライズ 消費MP:3 (敵単体のステータスを表示)\n", idx);
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

double check_enemy_fireResist(Player *****st, Enemy ***enemy, int damage){
  double turn_decrease;

  if ( (**enemy) -> fire == BLOCK ){
    sleep(1);
    printf("%s<<BLOCK!\n", (**enemy) -> name);
    turn_decrease = -2;
  }
  else if ( (**enemy) -> fire == ABSORB ){
    (**enemy) -> hp += damage;
    if ( (**enemy) -> hp > (**enemy) -> maxhp ){
      (**enemy) -> hp = (**enemy) -> maxhp;
    }
    printf("Absorb!\n");
    sleep(1);
    printf("%s<<%dダメージ吸収\n", (**enemy) -> name, damage);
    turn_decrease = TURNCHAGE;
  }
  else if ( (**enemy) -> fire == REFLECT ){
    (****st) -> hp -= damage;
    printf("Reflect!\n");
    sleep(1);
    printf("%s<<%dダメージ\n", (****st) -> name, damage);
    if ( (****st) -> hp <= 0 ){
      (****st) -> hp = 0;
      (****st) -> badstatus = DEAD;
      printf("%sは反射ダメージで倒れた\n", (****st) -> name);
    }
    turn_decrease = TURNCHAGE;
  }
  else if ( (**enemy) -> fire == 100 ){
    damage = damage;
    turn_decrease = -1;
  }
  else if ( (**enemy) -> fire == 120 ){
    damage *= 1.2;
    turn_decrease = -1;
  }
  else if ( (**enemy) -> fire == 150 ){     //火炎攻撃1.5倍
    damage *= 1.5;
    turn_decrease = -1;
  }
  else if ( (**enemy) -> fire == 200 ){
    sleep(1);
    printf("WEAKNESS!!\n");
    damage *= 1.7;
    turn_decrease = 0.1;
  }
  else if ( (**enemy) -> fire == 80 ){  //火炎攻撃ダメージ80%
    damage *= 0.8;
    turn_decrease = -1;
  }
  else if ( (**enemy) -> fire == 50 ){  //火炎攻撃半減
    sleep(1);
    printf("RESIST!\n");
    damage *= 0.5;
    turn_decrease = -1;
  }
  else if ( (**enemy) -> fire == 25 ){  //火炎攻撃ダメージ25%
    sleep(1);
    printf("RESIST!\n");
    damage *= 0.25;
    turn_decrease = -1;
  }

  if ( damage >= (**enemy) -> hp ){
    sleep(1);
    printf("%s<<%dダメージ\n", (**enemy) -> name, damage);
    sleep(1);
    printf("%sは%sを倒した!\n",(****st) -> name, (**enemy) -> name);
    (**enemy) -> hp = 0;
    (**enemy) -> badstatus = DEAD;
  }
  else{
    printf("%s<<%dダメージ\n", (**enemy) -> name, damage);
    (**enemy) -> hp -= damage;
    if ( (**enemy) -> hp <= 0 ){
      (**enemy) -> hp = 0;
      (**enemy) -> badstatus = DEAD;
    }
  }

  return turn_decrease;
}

double check_enemyCopy_fireResist(Player *****st, Enemy **enemy_copy, int damage){
  double turn_decrease;

  if ( (*enemy_copy) -> fire == BLOCK ){
    sleep(1);
    printf("%s<<BLOCK!\n", (*enemy_copy) -> name);
    turn_decrease = -2;
  }
  else if ( (*enemy_copy) -> fire == ABSORB ){
    (*enemy_copy) -> hp += damage;
    if ( (*enemy_copy) -> hp > (*enemy_copy) -> maxhp ){
      (*enemy_copy) -> hp = (*enemy_copy) -> maxhp;
    }
    printf("Absorb!\n");
    sleep(1);
    printf("%s<<%dダメージ吸収\n", (*enemy_copy) -> name, damage);
    turn_decrease = TURNCHAGE;
  }
  else if ( (*enemy_copy) -> fire == REFLECT ){
    (****st) -> hp -= damage;
    printf("Reflect!\n");
    sleep(1);
    printf("%s<<%dダメージ\n", (****st) -> name, damage);
    if ( (****st) -> hp <= 0 ){
      (****st) -> hp = 0;
      (****st) -> badstatus = DEAD;
      printf("%sは反射ダメージで倒れた\n", (****st) -> name);
    }
    turn_decrease = TURNCHAGE;
  }
  else if ( (*enemy_copy) -> fire == 100 ){
    damage = damage;
    turn_decrease = -1;
  }
  else if ( (*enemy_copy) -> fire == 120 ){
    damage *= 1.2;
    turn_decrease = -1;
  }
  else if ( (*enemy_copy) -> fire == 150 ){     //火炎攻撃1.5倍
    damage *= 1.5;
    turn_decrease = -1;
  }
  else if ( (*enemy_copy) -> fire == 200 ){
    sleep(1);
    printf("WEAKNESS!!\n");
    damage *= 1.7;
    turn_decrease = 0.1;
  }
  else if ( (*enemy_copy) -> fire == 80 ){  //火炎攻撃ダメージ80%
    damage *= 0.8;
    turn_decrease = -1;
  }
  else if ( (*enemy_copy) -> fire == 50 ){  //火炎攻撃半減
    sleep(1);
    printf("RESIST!\n");
    damage *= 0.5;
    turn_decrease = -1;
  }
  else if ( (*enemy_copy) -> fire == 25 ){  //火炎攻撃ダメージ25%
    sleep(1);
    printf("RESIST!\n");
    damage *= 0.25;
    turn_decrease = -1;
  }

  if ( damage >= (*enemy_copy) -> hp ){
    sleep(1);
    printf("%s<<%dダメージ\n", (*enemy_copy) -> name, damage);
    sleep(1);
    printf("%sは%sを倒した!\n",(****st) -> name, (*enemy_copy) -> name);
    (*enemy_copy) -> hp = 0;
    (*enemy_copy) -> badstatus = DEAD;
  }
  else{
    printf("%s<<%dダメージ\n", (*enemy_copy) -> name, damage);
    (*enemy_copy) -> hp -= damage;
    if ( (*enemy_copy) -> hp <= 0 ){
      (*enemy_copy) -> hp = 0;
      (*enemy_copy) -> badstatus = DEAD;
    }
  }

  return turn_decrease;
}
