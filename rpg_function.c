#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <conio.h>
#include <wchar.h>
#include "rpg.h"

extern int tempArray[SIZE];

//細かな機能

void Debug_Mode(Player *st, Player *st2, Player *st3){

  printf("デバッグモードを記述します...\n");
  exit(EXIT_SUCCESS);
}

void display_status(Player **st, Player **st2, Player **st3){

  printf("パーティの能力を表示します\n");
  printf("\n");

  //主人公
  printf("%sの能力は・・・\n", (*st) -> name);
  printf("%s LV:%d EXP:%d NEXT EXP:%d\n", (*st) -> name, (*st) -> lv, (*st) -> sumexp, (*st) -> nextexp);
  printf("HP:%d/%d MP:%d/%d\n", (*st) -> hp, (*st) -> maxhp, (*st) -> mp, (*st) -> maxmp);

  printf("力:%d\n", (*st) -> atk);
  printf("魔:%d\n", (*st) -> magic);
  printf("体:%d\n", (*st) -> str);
  printf("速:%d\n", (*st) -> agi);
  printf("運:%d\n", (*st) -> luk);
  printf("GOLD:%d\n", (*st) -> gold);

  //２人目
  printf("%sの能力は・・・\n", (*st2) -> name);
  printf("%s LV:%d EXP:%d NEXT EXP:%d\n", (*st2) -> name, (*st2) -> lv, (*st2) -> sumexp, (*st2) -> nextexp);
  printf("HP:%d/%d MP:%d/%d\n", (*st2) -> hp, (*st2) -> maxhp, (*st2) -> mp, (*st2) -> maxmp);

  printf("力:%d\n", (*st2) -> atk);
  printf("魔:%d\n", (*st2) -> magic);
  printf("体:%d\n", (*st2) -> str);
  printf("速:%d\n", (*st2) -> agi);
  printf("運:%d\n", (*st2) -> luk);

  //３人目
  printf("%sの能力は・・・\n", (*st3) -> name);
  printf("%s LV:%d EXP:%d NEXT EXP:%d\n", (*st3) -> name, (*st3) -> lv, (*st3) -> sumexp, (*st3) -> nextexp);
  printf("HP:%d/%d MP:%d/%d\n", (*st3) -> hp, (*st3) -> maxhp, (*st3) -> mp, (*st3) -> maxmp);

  printf("力:%d\n", (*st3) -> atk);
  printf("魔:%d\n", (*st3) -> magic);
  printf("体:%d\n", (*st3) -> str);
  printf("速:%d\n", (*st3) -> agi);
  printf("運:%d\n", (*st3) -> luk);

  printf("\n");
}

void display_playerStatusPoint(int point){

  for ( int i = 0; i < point; i++ ){
    printf("*");
  }

  printf("\n");

}

int school_command(Items **items){
  int input;

  printf("1.保健室へ行く\n");
  printf("2.美術室へ行く\n");
  printf("3.化学実験室へ行く\n");
  printf("4.ダンジョンへ行く\n");
  printf("5.ゲームをセーブせずに終了する\n");
  printf("6.セーブする\n");
  if ( (*items) -> isGetRareDrop == ON ){
    printf("7.解剖室へ行く\n");
  }

  input = _getch();

  return input;
}

void full_recover(Player **st, Player **st2, Player **st3){
  (*st) -> badstatus = GOOD;
  (*st2) -> badstatus = GOOD;
  (*st3) -> badstatus = GOOD;

  (*st) -> hp = (*st) -> maxhp;
  (*st) -> mp = (*st) -> maxmp;

  (*st2) -> hp = (*st2) -> maxhp;
  (*st2) -> mp = (*st2) -> maxmp;

  (*st3) -> hp = (*st3) -> maxhp;
  (*st3) -> mp = (*st3) -> maxmp;
}

void infirmary_full_recover(Player ***st, Player ***st2, Player ***st3){

  (**st) -> badstatus = GOOD;
  (**st2) -> badstatus = GOOD;
  (**st3) -> badstatus = GOOD;

  (**st) -> hp = (**st) -> maxhp;
  (**st) -> mp = (**st) -> maxmp;

  (**st2) -> hp = (**st2) -> maxhp;
  (**st2) -> mp = (**st2) -> maxmp;

  (**st3) -> hp = (**st3) -> maxhp;
  (**st3) -> mp = (**st3) -> maxmp;
}

int calculate_RecoverSkill_price(int input, int money){

  if ( input == '0' ){
    money -= 500;
  }
  else if( input == '1' ){
    money -= 500;
  }
  else if ( input == '2' ){
    money -= 4000;
  }

  return money;
}

int calculate_FireSkill_price(int input, int money){

  if ( input == '0' ){
    money -= 700;
  }

  return money;
}

int calculate_IceSkill_price(int input, int money){

  if ( input == '0' ){
    money -= 700;
  }

  return money;
}

int calculate_ElecSkill_price(int input, int money){

  if ( input == '0' ){
    money -= 700;
  }

  return money;
}

int calculate_WaveSkill_price(int input, int money){

  if ( input == '0' ){
    money -= 700;
  }

  return money;
}

void check_PhysicalSkill_state(P_skill *****player_skill){


}

void check_FireSkill_state(P_skill *****player_skill, int num){

  if ( num == 0 ){
    if ( (****player_skill) -> enfa[0] == LEARNED || (****player_skill) -> enfa[0] == SETTING ){
      printf("MASTER★\n");
    }
    else if ( (****player_skill) -> enfa[0] == LEARNING ){
      printf("習得中\n");
    }
    else{
      printf("未習得\n");
    }

    return;
  }
}

void check_IceSkill_state(P_skill *****player_skill, int num){

  if ( num == 0 ){
    if ( (****player_skill) -> hyodo[0] == LEARNED || (****player_skill) -> hyodo[0] == SETTING ){
      printf("MASTER★\n");
    }
    else if ( (****player_skill) -> hyodo[0] == LEARNING ){
      printf("習得中\n");
    }
    else{
      printf("未習得\n");
    }

    return;
  }
}

void check_ElecSkill_state(P_skill *****player_skill, int num){

  if ( num == 0 ){
    if ( (****player_skill) -> volua[0] == LEARNED || (****player_skill) -> volua[0] == SETTING ){
      printf("MASTER★\n");
    }
    else if ( (****player_skill) -> volua[0] == LEARNING ){
      printf("習得中\n");
    }
    else{
      printf("未習得\n");
    }

    return;
  }
}

void check_WaveSkill_state(P_skill *****player_skill, int num){

  if ( num == 0 ){
    if ( (****player_skill) -> whive[0] == LEARNED || (****player_skill) -> whive[0] == SETTING ){
      printf("MASTER★\n");
    }
    else if ( (****player_skill) -> whive[0] == LEARNING ){
      printf("習得中\n");
    }
    else{
      printf("未習得\n");
    }

    return;
  }
}

void check_RecoverSkill_state(P_skill *****player_skill, int num){

  if ( num == 0 ){
    if ( (****player_skill) -> recover1[0] == LEARNED || (****player_skill) -> recover1[0] == SETTING ){
      printf("MASTER★\n");
    }
    else if ( (****player_skill) -> recover1[0] == LEARNING ){
      printf("習得中\n");
    }
    else{
      printf("未習得\n");
    }

    return;
  }

  if ( num == 1 ){
    if ( (****player_skill) -> cure_poison[0] == LEARNED || (****player_skill) -> cure_poison[0] == SETTING ){
      printf("MASTER★\n");
    }
    else if ( (****player_skill) -> cure_poison[0] == LEARNING ){
      printf("習得中\n");
    }
    else{
      printf("未習得\n");
    }

    return;
  }

  if ( num == 2 ){
    if ( (****player_skill) -> recover2[0] == LEARNED || (****player_skill) -> recover2[0] == SETTING ){
      printf("MASTER★\n");
    }
    else if ( (****player_skill) -> recover2[0] == LEARNING ){
      printf("習得中\n");
    }
    else{
      printf("未習得\n");
    }

    return;
  }

}

int procedure_getFireSkill(int input, P_skill *****player_skill, int money){

  if ( input == '0' ){
    if ( (****player_skill) -> enfa[0] == NOT_LEARNING ){
      if ( money < 700 ){
        printf("所持金が足りません!\n");
        return NOT_LEARNING;
      }
      else{
        printf("ヘルメス「エンファについて学ぶが良い！」\n");
        (****player_skill) -> enfa[0] = LEARNING;
        (****player_skill) -> enfa[1] = BATTLEONLY;
        (****player_skill) -> enfa[2] = 0;
        (****player_skill) -> enfa[3] = 2;
        return LEARNING;
      }
    }
    else if ( (****player_skill) -> enfa[0] == LEARNING ){
      printf("このスキルは習得中です!\n");
      return LEARNING;
    }
    else{
      printf("既にMASTERしています!\n");
      return LEARNED;
    }
  }
  else if ( input == '1' && ( (****player_skill) -> enfa[0] == SETTING || (****player_skill) -> enfa[0] == LEARNED ) ){
    printf("未実装\n");
    return NOT_LEARNING;
    if ( (****player_skill) -> cure_poison[0] == NOT_LEARNING ){
      if ( money < 500 ){
        printf("所持金が足りません!\n");
        return NOT_LEARNING;
      }
      else{
        printf("ヘルメス「エンファスについて学ぶが良い！」\n");
        (****player_skill) -> cure_poison[0] = LEARNING;
        return LEARNING;
      }
    }
    else{
      printf("既にMASTERしています!\n");
      return LEARNED;
    }
  }
}

int procedure_getIceSkill(int input, P_skill *****player_skill, int money){

  if ( input == '0' ){
    if ( (****player_skill) -> hyodo[0] == NOT_LEARNING ){
      if ( money < 700 ){
        printf("所持金が足りません!\n");
        return NOT_LEARNING;
      }
      else{
        printf("ヘルメス「ヒョウドについて学ぶが良い！」\n");
        (****player_skill) -> hyodo[0] = LEARNING;
        (****player_skill) -> hyodo[1] = BATTLEONLY;
        (****player_skill) -> hyodo[2] = 0;
        (****player_skill) -> hyodo[3] = 2;
        return LEARNING;
      }
    }
    else if ( (****player_skill) -> hyodo[0] == LEARNING ){
      printf("このスキルは習得中です!\n");
      return LEARNING;
    }
    else{
      printf("既にMASTERしています!\n");
      return LEARNED;
    }
  }
}

int procedure_getElecSkill(int input, P_skill *****player_skill, int money){

  if ( input == '0' ){
    if ( (****player_skill) -> volua[0] == NOT_LEARNING ){
      if ( money < 700 ){
        printf("所持金が足りません!\n");
        return NOT_LEARNING;
      }
      else{
        printf("ヘルメス「ボルアについて学ぶが良い！」\n");
        (****player_skill) -> volua[0] = LEARNING;
        (****player_skill) -> volua[1] = BATTLEONLY;
        (****player_skill) -> volua[2] = 0;
        (****player_skill) -> volua[3] = 2;
        return LEARNING;
      }
    }
    else if ( (****player_skill) -> volua[0] == LEARNING ){
      printf("このスキルは習得中です!\n");
      return LEARNING;
    }
    else{
      printf("既にMASTERしています!\n");
      return LEARNED;
    }
  }
}

int procedure_getWaveSkill(int input, P_skill *****player_skill, int money){

  if ( input == '0' ){
    if ( (****player_skill) -> whive[0] == NOT_LEARNING ){
      if ( money < 700 ){
        printf("所持金が足りません!\n");
        return NOT_LEARNING;
      }
      else{
        printf("ヘルメス「ウィーブについて学ぶが良い！」\n");
        (****player_skill) -> whive[0] = LEARNING;
        (****player_skill) -> whive[1] = BATTLEONLY;
        (****player_skill) -> whive[2] = 0;
        (****player_skill) -> whive[3] = 2;
        return LEARNING;
      }
    }
    else if ( (****player_skill) -> whive[0] == LEARNING ){
      printf("このスキルは習得中です!\n");
      return LEARNING;
    }
    else{
      printf("既にMASTERしています!\n");
      return LEARNED;
    }
  }
}

int procedure_getRecoverSkill(int input, P_skill *****player_skill, int money){

  if ( input == '0' ){
    if ( (****player_skill) -> recover1[0] == NOT_LEARNING ){
      if ( money < 500 ){
        printf("所持金が足りません!\n");
        return NOT_LEARNING;
      }
      else{
        printf("ヘルメス「ケディアについて学ぶが良い！」\n");
        (****player_skill) -> recover1[0] = LEARNING;
        return LEARNING;
      }
    }
    else if ( (****player_skill) -> recover1[0] == LEARNING ){
      printf("このスキルは習得中です!\n");
      return LEARNING;
    }
    else{
      printf("既にMASTERしています!\n");
      return LEARNED;
    }
  }
  else if ( input == '1' ){
    if ( (****player_skill) -> cure_poison[0] == NOT_LEARNING ){
      if ( money < 500 ){
        printf("所持金が足りません!\n");
        return NOT_LEARNING;
      }
      else{
        printf("ヘルメス「キュアポについて学ぶが良い！」\n");
        (****player_skill) -> cure_poison[0] = LEARNING;
        return LEARNING;
      }
    }
    else if ( (****player_skill) -> cure_poison[0] == LEARNING ){
      printf("このスキルは習得中です!\n");
      return LEARNING;
    }
    else{
      printf("既にMASTERしています!\n");
      return LEARNED;
    }
  }
  else if ( input == '2' ){
    if ( (****player_skill) -> recover2[0] == NOT_LEARNING ){
      if ( money < 4000 ){
        printf("所持金が足りません!\n");
        return NOT_LEARNING;
      }
      else{
        printf("ヘルメス「ケディアスについて学ぶが良い！」\n");
        (****player_skill) -> recover2[0] = LEARNING;
        return LEARNING;
      }
    }
    else if ( (****player_skill) -> recover2[0] == LEARNING ){
      printf("このスキルは習得中です!\n");
      return LEARNING;
    }
    else{
      printf("既にMASTERしています!\n");
      return LEARNED;
    }
  }

}


void getSkill_Physical(Player ****st, P_skill ****player_skill, int money){
  int input;
  int num;

  do{
    num = 0;
    printf("\n");
    printf("所持金:%dG\n", money);
    printf("<<<物理スキル>>>\n");
    printf("0.突撃(消費HP:最大体力の8%% 単体に物理小ダメージ) ");
    check_PhysicalSkill_state(&player_skill);
    num++;

    printf("習得したいスキルを選んでください(終了する場合はcを入力)\n");
    input = _getch();

  }while( input != 'c' );
}

int getSkill_Fire(Player ****st, P_skill ****player_skill, int money){
  int input;
  int num;
  int isLearned;

  do{
    num = 0;
    printf("\n");
    printf("所持金:%dG\n", money);
    printf("<<<火炎スキル>>>\n");
    printf("0.エンファ 700G(消費MP:4 単体に火炎小ダメージ) ");
    check_FireSkill_state(&player_skill,num);
    num++;

    if ( (***player_skill) -> enfa[0] == LEARNED ){
      printf("1.エンファス 3500G(消費MP:8 敵全体に火炎小ダメージ)\n");
    }
    check_FireSkill_state(&player_skill,num);
    num++;

    printf("習得したいスキルを選んでください(終了する場合はcを入力)\n");
    input = _getch();

    if ( input == 'c' ){
      return money;
    }

    isLearned = procedure_getFireSkill(input,&player_skill,money);
    if ( isLearned == LEARNING ){
      money = calculate_FireSkill_price(input,money);
      return money;
    }

  }while( input != 'c' );

}

int getSkill_Ice(Player ****st, P_skill ****player_skill, int money){
  int input;
  int num;
  int isLearned;

  do{
    num = 0;
    printf("\n");
    printf("所持金:%dG\n", money);
    printf("<<<氷結スキル>>>\n");
    printf("0.ヒョウド 700G(消費MP:4 単体に氷結小ダメージ) ");
    check_IceSkill_state(&player_skill,num);
    num++;

    /*if ( (***player_skill) -> enfa[0] == LEARNED ){
      printf("1.ヒョウドス 3500G(消費MP:8 敵全体に氷結小ダメージ)\n");
    }*/
    check_IceSkill_state(&player_skill,num);
    num++;

    printf("習得したいスキルを選んでください(終了する場合はcを入力)\n");
    input = _getch();

    if ( input == 'c' ){
      return money;
    }

    isLearned = procedure_getIceSkill(input,&player_skill,money);
    if ( isLearned == LEARNING ){
      money = calculate_IceSkill_price(input,money);
      return money;
    }

  }while( input != 'c' );

}

int getSkill_Elec(Player ****st, P_skill ****player_skill, int money){
  int input;
  int num;
  int isLearned;

  do{
    num = 0;
    printf("\n");
    printf("所持金:%dG\n", money);
    printf("<<<電撃スキル>>>\n");
    printf("0.ボルア 700G(消費MP:4 単体に電撃小ダメージ) ");
    check_ElecSkill_state(&player_skill,num);
    num++;

    /*if ( (***player_skill) -> enfa[0] == LEARNED ){
      printf("1.ヒョウドス 3500G(消費MP:8 敵全体に氷結小ダメージ)\n");
    }*/
    check_ElecSkill_state(&player_skill,num);
    num++;

    printf("習得したいスキルを選んでください(終了する場合はcを入力)\n");
    input = _getch();

    if ( input == 'c' ){
      return money;
    }

    isLearned = procedure_getElecSkill(input,&player_skill,money);
    if ( isLearned == LEARNING ){
      money = calculate_ElecSkill_price(input,money);
      return money;
    }

  }while( input != 'c' );

}

int getSkill_Wave(Player ****st, P_skill ****player_skill, int money){
  int input;
  int num;
  int isLearned;

  do{
    num = 0;
    printf("\n");
    printf("所持金:%dG\n", money);
    printf("<<<衝撃スキル>>>\n");
    printf("0.ウィーブ 700G(消費MP:4 単体に衝撃小ダメージ) ");
    check_WaveSkill_state(&player_skill,num);
    num++;

    check_WaveSkill_state(&player_skill,num);
    num++;

    printf("習得したいスキルを選んでください(終了する場合はcを入力)\n");
    input = _getch();

    if ( input == 'c' ){
      return money;
    }

    isLearned = procedure_getWaveSkill(input,&player_skill,money);
    if ( isLearned == LEARNING ){
      money = calculate_WaveSkill_price(input,money);
      return money;
    }

  }while( input != 'c' );

}

int getSKill_almighty(Player ****st, P_skill ****player_skill, int money){

  return money;
}

int getSkill_death(Player ****st, P_skill ****player_skill, int money){

  return money;
}

int getSkill_expel(Player ****st, P_skill ****player_skill, int money){

  return money;
}

int getSkill_Recover(Player ****st, P_skill ****player_skill, int money){
  int input;
  int num;
  int isLearned;

  do{
    num = 0;
    printf("\n");
    printf("所持金:%dG\n", money);
    printf("<<<回復スキル>>>\n");
    printf("0.ケディア 500G(消費MP:3 単体のHPを小回復) ");
    check_RecoverSkill_state(&player_skill,num);
    num++;
    printf("1.キュアポ 500G(消費MP:4 単体のPOISONを回復) ");
    check_RecoverSkill_state(&player_skill,num);
    num++;
    printf("2.ケディアス 4000G(消費MP:8 全体のHPを小回復)");
    check_RecoverSkill_state(&player_skill,num);
    num++;

    printf("習得したいスキルを選んでください(終了する場合はcを入力)\n");
    input = _getch();

    if ( input == 'c' ){
      return money;
    }

    isLearned = procedure_getRecoverSkill(input,&player_skill,money);
    if ( isLearned == LEARNING ){
      money = calculate_RecoverSkill_price(input,money);
      return money;
    }

  }while( input != 'c' );
}

int getSkill_support(Player ****st, P_skill ****player_skill, int money){

  return money;
}

int getSkill_statusEffect(Player ****st, P_skill ****player_skill, int money){

  return money;
}

int getSkill_block(Player ****st, P_skill ****player_skill, int money){

  return money;
}

int getSkill_autoEffect(Player ****st, P_skill ****player_skill, int money){

  return money;
}

int getSkillAll(Player ***st, P_skill ***player_skill, int money){
  int input;

  printf("\n");
  do {
    printf("習得したいスキルを選んでください(終了したらcを入力してください)\n");
    printf("1.物理スキル  ");
    printf("2.火炎スキル\n");
    printf("3.氷結スキル  ");
    printf("4.電撃スキル\n");
    printf("5.衝撃スキル  ");
    printf("6.万能スキル\n");
    printf("7.呪殺スキル  ");
    printf("8.破魔スキル\n");
    printf("9.回復スキル  ");
    printf("a.補助スキル\n");
    printf("b.状態異常スキル   ");
    printf("d.属性防御スキル   ");
    printf("e.自動効果スキル\n");

    input = _getch();

    if ( input == '1' ){
      getSkill_Physical(&st,&player_skill,money);
      return money;
    }
    else if ( input == '2' ){
      money = getSkill_Fire(&st,&player_skill,money);
      return money;
    }
    else if ( input == '3' ){
      money = getSkill_Ice(&st,&player_skill,money);
      return money;
    }
    else if ( input == '4' ){
      money = getSkill_Elec(&st,&player_skill,money);
      return money;
    }
    else if ( input == '5' ){
      money = getSkill_Wave(&st,&player_skill,money);
      return money;
    }
    else if ( input == '6' ){
      money = getSKill_almighty(&st,&player_skill,money);
      return money;
    }
    else if ( input == '7' ){
      money = getSkill_death(&st,&player_skill,money);
      return money;
    }
    else if ( input == '8' ){
      money = getSkill_expel(&st,&player_skill,money);
      return money;
    }
    else if ( input == '9' ){
      money = getSkill_Recover(&st,&player_skill,money);
      return money;
    }
    else if ( input == 'a' ){
      money = getSkill_support(&st,&player_skill,money);
    }
    else if ( input == 'b' ){
      money = getSkill_statusEffect(&st,&player_skill,money);
    }
    else if ( input == 'd' ){
      money = getSkill_block(&st,&player_skill,money);
    }
    else if ( input == 'e' ){
      money = getSkill_autoEffect(&st,&player_skill,money);
    }

  } while ( input != 'c' );

}

void goTo_infirmary(Player **st, Player **st2, Player **st3, Items **items){
  int input;

  printf("\n");
  printf("%s達は保健室へ行った...\n", (*st) -> name);
  sleep(1);
  do{
    printf("\n");
    printf("---保健室---\n");
    printf("1.回復する\n");
    printf("2.道具を買う\n");
    printf("3.保健室を出る\n");
    printf("h.話を聞く\n");
    input = _getch();

    if ( input == '1' ){
      sleep(1);
      infirmary_full_recover(&st,&st2,&st3);
      printf("%s達は全回復した！\n", (*st) -> name);
    }
    else if ( input == '2' ){
      goods_shop(&st,&items);
    }
    else if ( input == 'h' ){
      printf("香山先生「ここでは、あなたたちの治療と回復アイテムを販売するわ」\n");
      sleep(2);
      printf("香山先生「治療に関しては無料でしてあげるけど、アイテムは有料だから覚えといて」\n");
      sleep(1);
    }
  } while ( input != '3' );

}

void goTo_artRoom(Player **st, Player **st2, Player **st3, Equip **pEquip, Equip **p2Equip, Equip **p3Equip){
  int input;

  printf("\n");
  printf("%s達は美術室へ行った...\n", (*st) -> name);
  sleep(1);
  do {
    printf("\n");
    printf("---美術室---\n");
    printf("1.装備を購入する\n");
    printf("2.装備を売却する\n");
    printf("c.美術室を出る\n");
    printf("h.話を聞く\n");
    input = _getch();

    if ( input == '1' ){
      equip_shop(&st,&st2,&st3,&pEquip,&p2Equip,&p3Equip);
    }
    else if ( input == '2' ){
      sell_equip(&st,&pEquip,&p2Equip,&p3Equip);
    }
    else if ( input == 'h' ){
      printf("岡本先生「ここでは、私が作った装備品を販売するよ」\n");
      sleep(2);
      printf("岡本先生「装備品はきっとあなたたちの助けになるはずだから、購入したら忘れずに装備してね」\n");
      sleep(2);
      printf("岡本先生「ラインナップについては、時間が経てば増えるはずだから待ってて」\n");
      sleep(1);
    }

  } while ( input != 'c' );
}

void goTo_labo(Player **st, Player **st2, Player **st3, P_skill **player_skill, P_skill **player_skill2, P_skill **player_skill3){
  int input;
  int money;

  printf("\n");
  printf("%s達は化学準備室へ行った...\n", (*st) -> name);
  sleep(1);


  do {
    money = (*st) -> gold;
    printf("\n");
    printf("---化学準備室---\n");
    printf("1.スキルの知識を得る\n");
    printf("c.化学準備室を出る\n");
    printf("h.話を聞く\n");
    input = _getch();

    if ( input == '1' ){
      do {
        printf("スキルを習得したい人を選んでください(終了したい場合はcを入力してください)\n");
        printf("1.%s\n", (*st) -> name);
        printf("2.%s\n", (*st2) -> name);
        printf("3.%s\n", (*st3) -> name);

        input = _getch();

        if ( input == '1' ){
          money = getSkillAll(&st,&player_skill,money);
          (*st) -> gold = money;
        }
        else if ( input == '2' ){
          money = getSkillAll(&st2,&player_skill2,money);
          (*st) -> gold = money;
        }
        else if ( input == '3' ){
          money = getSkillAll(&st3,&player_skill3,money);
          (*st) -> gold = money;
        }

      } while ( input != 'c' );

    }
    else if ( input == 'h' ){
      printf("ヘルメス「私は錬金術の神、ヘルメスである」\n");
      sleep(2);
      printf("ヘルメス「汝らの助けになるようにと、ある御方から命を受けた」\n");
      sleep(2);
      printf("ヘルメス「汝らの旅に必要なスキルを代価と引き換えに授けよう」\n");
      sleep(2);
      printf("ヘルメス「スキルを習得するには、戦いの経験が必要である」\n");
      sleep(2);
      printf("ヘルメス「敵とたくさん戦い、経験を積むがよい」\n");
      sleep(2);
      printf("ヘルメス「ただし、途中でスキルの経験を積むことを止めた場合、再びやり直しになることは留意するように」\n");
      sleep(1);
    }

  } while ( input != 'c' );
}

void buy_goods(Player ****st, Items ****items, int goods_number,  int price){
  int sum, count;
  int input;

  printf("何個購入しますか?(1~99個まで,購入を止める場合は0を入力,入力が完了したらエンターキーを押してください)\n");
  scanf("%d", &count);

  if ( count == 0 ){
    return;
  }

  if ( count < 1 || count > 99 ){
    printf("個数を入力し直してください\n");
    return;
  }

  sum = 0;
  for ( int i = 1; i <= count; i++ ){
    sum += price;
    if ( (***st) -> gold < sum ){
      printf("\n");
      printf("所持金が足りません...\n");
      return;
    }
  }

  printf("\n");
  printf("%d個購入しました\n", count);
  printf("\n");

  (***st) -> gold -= sum;

  if ( goods_number == MEDICINE ){
    (***items) -> medicine += count;
  }
  else if ( goods_number == ANTIPOISON ){
    (***items) -> antipoison += count;
  }
  else if ( goods_number == ANTIPALYZE ){
    (***items) -> antipalyze += count;
  }
  else if ( goods_number == ANTICHARM ){
    (***items) -> anticharm += count;
  }
  else if ( goods_number == ANTICLOSE ){
    (***items) -> anticlose += count;
  }
  else if ( goods_number == ANTISTONE ){
    (***items) -> antistone += count;
  }
  else if ( goods_number == ANTIPANIC ){
    (***items) -> antipanic += count;
  }
  else if ( goods_number == ANTISLEEP ){
    (***items) -> antisleep += count;
  }
  else if ( goods_number == ANTICURSE ){
    (***items) -> anticurse += count;
  }

}

void goods_shop(Player ***st, Items ***items){
  int input;
  int goods_number, price;

  do{
    goods_number = 0;
    printf("\n");
    printf("---SHOP---\n");
    printf("何を買いますか？(所持金: %dG)\n", (**st) -> gold);
    printf("1.傷薬:100G(味方１人のHPを50回復)\n");
    printf("2.アンタイポイズン:150G(味方1人のPOISONを回復)\n");
    printf("3.アンタイパライズ:150G(味方1人のPALYZEを回復)\n");
    if ( (**st) -> stage_clear >= 2 ){
      printf("4.アンタイチャーム:200G(味方1人のCHARMを回復)\n");
      printf("5.アンタイクローズ:150G(味方1人のCLOSEを回復)\n");
      printf("6.アンタイストーン:250G(味方1人のSTONEを回復)\n");
      printf("7.アンタイパニック:200G(味方1人のPANICを回復)\n");
      printf("8.アンタイスリープ:200G(味方1人のSLEEPを回復)\n");
      printf("9.アンタイカース:250G(味方1人のCURSEを回復)\n");
      printf("c.購入を止める\n");
    }
    input = _getch();

    if ( input == '1' ){
      goods_number = MEDICINE;
      price = 100;
      buy_goods(&st,&items,goods_number, price);
    }
    else if ( input == '2' ){
      goods_number = ANTIPOISON;
      price = 150;
      buy_goods(&st,&items,goods_number, price);
    }
    else if ( input == '3' ){
      goods_number = ANTIPALYZE;
      price = 150;
      buy_goods(&st,&items,goods_number, price);
    }
    else if ( input == '4' && (**st) -> stage_clear >= 2 ){
      goods_number = ANTICHARM;
      price = 200;
      buy_goods(&st,&items,goods_number, price);
    }
    else if ( input == '5' && (**st) -> stage_clear >= 2 ){
      goods_number = ANTICLOSE;
      price = 150;
      buy_goods(&st,&items,goods_number, price);
    }
    else if ( input == '6' && (**st) -> stage_clear >= 2 ){
      goods_number = ANTISTONE;
      price = 250;
      buy_goods(&st,&items,goods_number, price);
    }
    else if ( input == '7' && (**st) -> stage_clear >= 2 ){
      goods_number = ANTIPANIC;
      price = 200;
      buy_goods(&st,&items,goods_number, price);
    }
    else if ( input == '8' && (**st) -> stage_clear >= 2 ){
      goods_number = ANTISLEEP;
      price = 200;
      buy_goods(&st,&items,goods_number, price);
    }
    else if ( input == '9' && (**st) -> stage_clear >= 2 ){
      goods_number = ANTICURSE;
      price = 250;
      buy_goods(&st,&items,goods_number, price);
    }

    printf("\n");
  } while ( input != 'c' );

}

void buy_equips(Player ****st, Equip ****pEquip, Equip ****p2Equip, Equip ****p3Equip, int equip_number, int price){

  int sum, count;
  int input;

  printf("何個購入しますか?(1~99個まで,購入を止める場合は0を入力,が完了したらエンターキーを押してください)\n");
  scanf("%d", &count);

  if ( count == 0 ){
    return;
  }

  if ( count < 1 || count > 99 ){
    printf("個数を入力し直してください\n");
    return;
  }

  sum = 0;
  for ( int i = 1; i <= count; i++ ){
    sum += price;
    if ( (***st) -> gold < sum ){
      printf("\n");
      printf("所持金が足りません...\n");
      printf("\n");
      return;
    }
  }

  printf("\n");
  printf("%d個購入しました\n", count);
  printf("\n");

  (***st) -> gold -= sum;

  if ( equip_number == HPRING1 ){
    (***pEquip) -> HpRing1 += count;
    (***p2Equip) -> HpRing1 += count;
    (***p3Equip) -> HpRing1 += count;
  }
  else if ( equip_number == MPRING1 ){
    (***pEquip) -> MpRing1 += count;
    (***p2Equip) -> MpRing1 += count;
    (***p3Equip) -> MpRing1 += count;
  }
  else if ( equip_number == HPRING2 ){
    (***pEquip) -> HpRing2 += count;
    (***p2Equip) -> HpRing2 += count;
    (***p3Equip) -> HpRing2 += count;
  }
  else if ( equip_number == POWEREARRINGS ){
    (***pEquip) -> HpRing2 += count;
    (***p2Equip) -> HpRing2 += count;
    (***p3Equip) -> HpRing2 += count;
  }
  else if ( equip_number == MAGICEARRINGS ){
    (***pEquip) -> HpRing2 += count;
    (***p2Equip) -> HpRing2 += count;
    (***p3Equip) -> HpRing2 += count;
  }
  else if ( equip_number == STRENGTHEARRINGS ){
    (***pEquip) -> HpRing2 += count;
    (***p2Equip) -> HpRing2 += count;
    (***p3Equip) -> HpRing2 += count;
  }
  else if ( equip_number == AGILITYEARRINGS ){
    (***pEquip) -> HpRing2 += count;
    (***p2Equip) -> HpRing2 += count;
    (***p3Equip) -> HpRing2 += count;
  }
  else if ( equip_number == LUCKYEARRINGS ){
    (***pEquip) -> HpRing2 += count;
    (***p2Equip) -> HpRing2 += count;
    (***p3Equip) -> HpRing2 += count;
  }

}

void equip_shop(Player ***st, Player ***st2, Player ***st3, Equip ***pEquip, Equip ***p2Equip, Equip ***p3Equip){
  int input;
  int equip_number, price;

  do {
    equip_number = 0;
    printf("\n");
    printf("---SHOP---\n");
    printf("何を購入しますか?(所持金: %dG)\n", (**st) -> gold);
    printf("1.HPリング1: 500G(味方1人の最大HPを5%%増加)\n");
    printf("2.MPリング1: 800G(味方1人の最大MPを5%%増加)\n");
    if ( (**st) -> stage_clear >= 2 ){
      printf("3.HPリング2: 1000G(味方1人の最大HPを10%%増加)\n");
      printf("4.パワーピアス: 1000G(味方1人の力を1ポイント増加)\n");
      printf("5.マジックピアス: 1000G(味方1人の魔を1ポイント増加)\n");
      printf("6.ストレングスピアス: 1000G(味方1人の体を1ポイント増加)\n");
      printf("7.スピードピアス: 1000G(味方1人の速を1ポイント増加)\n");
      printf("8.ラックピアス: 1000G(味方1人の運を1ポイント増加)\n");
    }
    printf("c.購入を止める\n");

    input = _getch();
    if ( input == '1' ){
      equip_number = HPRING1;
      price = 500;
      buy_equips(&st,&pEquip,&p2Equip,&p3Equip,equip_number,price);
    }
    else if ( input == '2' ){
      equip_number = MPRING1;
      price = 800;
      buy_equips(&st,&pEquip,&p2Equip,&p3Equip,equip_number,price);
    }
    else if ( input == '3' ){
      equip_number = HPRING2;
      price = 1000;
      buy_equips(&st,&pEquip,&p2Equip,&p3Equip,equip_number,price);
    }
    else if ( input == '4' ){
      equip_number = POWEREARRINGS;
      price = 1000;
      buy_equips(&st,&pEquip,&p2Equip,&p3Equip,equip_number,price);
    }
    else if ( input == '5' ){
      equip_number = MAGICEARRINGS;
      price = 1000;
      buy_equips(&st,&pEquip,&p2Equip,&p3Equip,equip_number,price);
    }
    else if ( input == '6' ){
      equip_number = STRENGTHEARRINGS;
      price = 1000;
      buy_equips(&st,&pEquip,&p2Equip,&p3Equip,equip_number,price);
    }
    else if ( input == '7' ){
      equip_number = AGILITYEARRINGS;
      price = 1000;
      buy_equips(&st,&pEquip,&p2Equip,&p3Equip,equip_number,price);
    }
    else if ( input == '8' ){
      equip_number = LUCKYEARRINGS;
      price = 1000;
      buy_equips(&st,&pEquip,&p2Equip,&p3Equip,equip_number,price);
    }


    printf("\n");
  } while ( input != 'c' );
}

void procedure_sell_equip(Player ****st, Equip ****pEquip, Equip ****p2Equip, Equip ****p3Equip, int input, int number){

  if ( input == HPRING1 ){
    if ( (***pEquip) -> HpRing1 < number ){
      printf("所持数より売却したい数がオーバーしています...\n");
      return;
    }

    (***pEquip) -> HpRing1 -= number;
    (***p2Equip) -> HpRing1 -= number;
    (***p3Equip) -> HpRing1 -= number;

    (***st) -> gold += 250 * number;
  }
  else if ( input == MPRING1 ){
    if ( (***pEquip) -> MpRing1 < number ){
      printf("所持数より売却したい数がオーバーしています...\n");
      return;
    }

    (***pEquip) -> MpRing1 -= number;
    (***p2Equip) -> MpRing1 -= number;
    (***p3Equip) -> MpRing1 -= number;

    (***st) -> gold += 400 * number;
  }
  else if ( input == HPRING2 ){
    if ( (***pEquip) -> HpRing2 < number ){
      printf("所持数より売却したい数がオーバーしています...\n");
      return;
    }

    (***pEquip) -> HpRing2 -= number;
    (***p2Equip) -> HpRing2 -= number;
    (***p3Equip) -> HpRing2 -= number;

    (***st) -> gold += 500 * number;
  }
  else if ( input == MPRING2 ){
    //発売未定
  }
  else if ( input == POWEREARRINGS ){
    if ( (***pEquip) -> PowerEarrings < number ){
      printf("所持数より売却したい数がオーバーしています...\n");
      return;
    }

    (***pEquip) -> PowerEarrings -= number;
    (***p2Equip) -> PowerEarrings -= number;
    (***p3Equip) -> PowerEarrings -= number;

    (***st) -> gold += 500 * number;
  }
  else if ( input == MAGICEARRINGS ){
    if ( (***pEquip) -> MagicEarrings < number ){
      printf("所持数より売却したい数がオーバーしています...\n");
      return;
    }

    (***pEquip) -> MagicEarrings -= number;
    (***p2Equip) -> MagicEarrings -= number;
    (***p3Equip) -> MagicEarrings -= number;

    (***st) -> gold += 500 * number;
  }
  else if ( input == STRENGTHEARRINGS ){
    if ( (***pEquip) -> StrengthEarrings < number ){
      printf("所持数より売却したい数がオーバーしています...\n");
      return;
    }

    (***pEquip) -> StrengthEarrings -= number;
    (***p2Equip) -> StrengthEarrings -= number;
    (***p3Equip) -> StrengthEarrings -= number;

    (***st) -> gold += 500 * number;
  }
  else if ( input == AGILITYEARRINGS ){
    if ( (***pEquip) -> AgilityEarrings < number ){
      printf("所持数より売却したい数がオーバーしています...\n");
      return;
    }

    (***pEquip) -> AgilityEarrings -= number;
    (***p2Equip) -> AgilityEarrings -= number;
    (***p3Equip) -> AgilityEarrings -= number;

    (***st) -> gold += 500 * number;
  }
  else if ( input == LUCKYEARRINGS ){
    if ( (***pEquip) -> LuckyEarrings < number ){
      printf("所持数より売却したい数がオーバーしています...\n");
      return;
    }

    (***pEquip) -> LuckyEarrings -= number;
    (***p2Equip) -> LuckyEarrings -= number;
    (***p3Equip) -> LuckyEarrings -= number;

    (***st) -> gold += 500 * number;
  }

}

void sell_equip(Player ***st, Equip ***pEquip, Equip ***p2Equip, Equip ***p3Equip){
  int input;
  int number;

  do{
    printf("何を売却しますか?\n");
    if ( (**pEquip) -> HpRing1 > 0 ){
      printf("1.HPリング1:%d個\n", (**pEquip) -> HpRing1);
    }
    if ( (**pEquip) -> MpRing1 > 0 ){
      printf("2.MPリング1:%d個\n", (**pEquip) -> MpRing1);
    }
    if ( (**pEquip) -> HpRing2 > 0 ){
      printf("3.HPリング2:%d個\n", (**pEquip) -> HpRing2);
    }
    if ( (**pEquip) -> MpRing2 > 0 ){
      printf("4.MPリング2:%d個\n", (**pEquip) -> MpRing2);
    }
    if ( (**pEquip) -> PowerEarrings > 0 ){
      printf("5.パワーピアス:%d個\n", (**pEquip) -> PowerEarrings);
    }
    if ( (**pEquip) -> MagicEarrings > 0 ){
      printf("6.マジックピアス:%d個\n", (**pEquip) -> MagicEarrings);
    }
    if ( (**pEquip) -> StrengthEarrings > 0 ){
      printf("7.ストレングスピアス:%d個\n", (**pEquip) -> StrengthEarrings);
    }
    if ( (**pEquip) -> AgilityEarrings > 0 ){
      printf("8.スピードピアス:%d個\n", (**pEquip) -> AgilityEarrings);
    }
    if ( (**pEquip) -> LuckyEarrings > 0 ){
      printf("9.ラッキーピアス:%d個\n", (**pEquip) -> LuckyEarrings);
    }
    if ( (**pEquip) -> OnmorakiEye > 0 ){
      printf("10.オンモラキアイ:%d個\n", (**pEquip) -> OnmorakiEye);
    }

    printf("売却したいアイテムのナンバーを入力してください(入力確定はエンターを入力し、キャンセルする場合は0を入力)\n");
    scanf("%d", &input);
    if ( input == 0 ){
      return;
    }

    printf("\n");
    printf("売却したい個数を入力してください(入力確定はエンターを入力し、キャンセルする場合は0を入力)\n");
    scanf("%d", &number);

    procedure_sell_equip(&st,&pEquip,&p2Equip,&p3Equip,input,number);

  }while( input != 0 || number != 0 );
}

int check_rareItems_number(Equip *****pEquip, int item_number){

  if ( item_number == ONMORAKIEYE ){
    if ( (****pEquip) -> OnmorakiEye > 99 ){
      printf("このアイテムはこれ以上所持出来ません...\n");
      return FALSE;
    }
  }

  return TRUE;
}

int synthesize_rareItems(Player ****st, Items ****items, Equip ****pEquip, Equip ****p2Equip, Equip ****p3Equip, int price, int item_number){

  if ( price > (***st) -> gold ){
    printf("所持金が足りません...\n");
    printf("\n");
    return FALSE;
  }

  if ( check_rareItems_number(&pEquip,item_number) == FALSE ){
    printf("\n");
    return FALSE;
  }

  (***st) -> gold -= price;

  printf("アイテムを合成中です...\n");
  sleep(2);

  return TRUE;
}

void provide_element(Player ***st, Items ***items, Equip ***pEquip, Equip ***p2Equip, Equip ***p3Equip){
  int input;
  int price;
  int item_number;

  do{
    if ( (**items) -> onmorakiPiece > 0 ){
      printf("1.オンモラキアイ:1000G(オンモラキの破片:1個) 所持数:%d個\n", (**items) -> onmorakiPiece);
    }

    printf("合成したいアイテムを選択してください!(キャンセルする場合はcを入力してください)\n");
    input = _getch();

    if ( input == '1' && (**items) -> onmorakiPiece > 0 ){
      price = 1000;
      item_number = ONMORAKIEYE;
      if ( synthesize_rareItems(&st,&items,&pEquip,&p2Equip,&p3Equip,price,item_number) == TRUE ){
        (**pEquip) -> OnmorakiEye++;
        (**p2Equip) -> OnmorakiEye++;
        (**p3Equip) -> OnmorakiEye++;
        printf("%sはオンモラキアイを手に入れた!\n", (**st) -> name);
      }
    }

  }while( input != 'c' );

}

void goTo_DissectingRoom(Player **st, Items **items, Equip **pEquip, Equip **p2Equip, Equip **p3Equip){
  int input;

  if ( (*items) -> isEverVisitDissectingRoom == OFF ){
    printf("\n");
    sleep(1);
    printf("???「ようこそ、解剖室へ・・・\n");
    sleep(2);
    printf("???「私は、生物教師の池田です」\n");
    sleep(2);
    printf("池田「君たちがここにやってきたということは、貴重な素材を持っているということだね」\n");
    sleep(2);
    printf("池田「私は生物の解剖を研究しているのだが、今は悪魔の素材に興味があってね」\n");
    sleep(2);
    printf("池田「もし、悪魔の素材があれば、私に持ってきてほしい」\n");
    sleep(2);
    printf("池田「持ってきてくれたら、代わりに素材から貴重なものを作ってあげよう」\n");
    sleep(1);
    (*items) -> isEverVisitDissectingRoom = ON;
  }

  do{
    printf("\n");
    printf("池田「さて、どうする?」\n");
    printf("1.素材を渡す\n");
    printf("2.素材を売る\n");
    printf("c.部屋を売る\n");

    input = _getch();

    if ( input == '1' ){
      provide_element(&st,&items,&pEquip,&p2Equip,&p3Equip);
    }
    else if ( input == '2' ){

    }

  }while( input != 'c' );

}
