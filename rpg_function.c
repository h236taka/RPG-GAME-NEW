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

int school_command(){
  int input;

  printf("1.保健室へ行く\n");
  printf("2.美術室へ行く\n");
  printf("3.化学実験室へ行く\n");
  printf("4.ダンジョンへ行く\n");
  printf("5.ゲームをセーブせずに終了する\n");
  printf("6.セーブする\n");
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

  do{
    printf("\n");
    printf("所持金:%dG\n", money);
    printf("<<<物理スキル>>>\n");
    printf("0.突撃(消費HP:最大体力の8%% 単体に物理小ダメージ) ");
    check_PhysicalSkill_state(&player_skill);

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
    else if ( input == '9' ){
      money = getSkill_Recover(&st,&player_skill,money);
      return money;
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
    printf("3.美術室を出る\n");
    printf("h.話を聞く\n");
    input = _getch();

    if ( input == '1' ){
      equip_shop(&st,&st2,&st3,&pEquip,&p2Equip,&p3Equip);
    }
    else if ( input == 'h' ){
      printf("岡本先生「ここでは、私が作った装備品を販売するよ」\n");
      sleep(2);
      printf("岡本先生「装備品はきっとあなたたちの助けになるはずだから、購入したら忘れずに装備してね」\n");
      sleep(2);
      printf("岡本先生「ラインナップについては、時間が経てば増えるはずだから待ってて」\n");
      sleep(1);
    }

  } while ( input != '3' );
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
    printf("2.化学準備室を出る\n");
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
        tempArray[0] = FALSE;

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

  } while ( input != '2' );
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

  if ( goods_number == 1 ){
    (***items) -> medicine += count;
  }
  else if ( goods_number == 2 ){
    (***items) -> antipoison += count;
  }
  else if ( goods_number == 3 ){
    (***items) -> antipalyze += count;
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
    printf("c.購入を止める\n");
    input = _getch();

    if ( input == '1' ){
      goods_number = 1;
      price = 100;
      buy_goods(&st,&items,goods_number, price);
    }
    else if ( input == '2' ){
      goods_number = 2;
      price = 150;
      buy_goods(&st,&items,goods_number, price);
    }
    else if ( input == '3' ){
      goods_number = 3;
      price = 150;
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
      return;
    }
  }

  printf("\n");
  printf("%d個購入しました\n", count);
  printf("\n");

  (***st) -> gold -= sum;

  if ( equip_number == 1 ){
    (***pEquip) -> HpRing1 += count;
    (***p2Equip) -> HpRing1 += count;
    (***p3Equip) -> HpRing1 += count;
  }
  else if ( equip_number == 2 ){
    (***pEquip) -> MpRing1 += count;
    (***p2Equip) -> MpRing1 += count;
    (***p3Equip) -> MpRing1 += count;
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
    printf("1.HPリング1: 500G(味方1人の最大HPを5%増加)\n");
    if ( (**st) -> stage_clear >= 2 ){
      printf("2.MPリング1: 800G(味方1人の最大MPを5%増加)\n");
    }
    printf("c.購入を止める\n");

    input = _getch();
    if ( input == '1' ){
      equip_number = 1;
      price = 500;
      buy_equips(&st,&pEquip,&p2Equip,&p3Equip,equip_number,price);
    }
    else if ( input == '2' && (**st) -> stage_clear >= 2 ){
      equip_number = 2;
      price = 800;
      buy_equips(&st,&pEquip,&p2Equip,&p3Equip,equip_number,price);
    }

    printf("\n");
  } while ( input != 'c' );
}
