#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <conio.h>
#include <wchar.h>
#include "rpg.h"

//main関数

//メモ：構造体は相当な領域を使用することから構造体変数を関数に渡すのではなく、参照渡し(pointer)を行った方がよい

//プレイ時間に関するグローバルな型・変数
time_t start_time, end_time;
int play_time;

int main(void){
  int load, input;   //input:プレイヤーの入力
  Player player;
  Player player2;
  Player player3;
  Items items = {0};
  Equip pEquip = {0};  //1人目のplayer
  Equip p2Equip = {0}; //2人目のメンバー
  Equip p3Equip = {0}; //3人目のメンバー

  Area area = {0};

  SearchDangeon search = {0};

  //boss_count = １ならばボス扱い
  //boss_count = 2ならば強制戦闘
  //enemy_skillが0以外なら敵はスキルを使用

  //name hp, maxhp, mp, maxmp, atk, magic, str, agi, luk, lv, exp, gold, badstatus, physical_attack, gun_attack, fire, ice, elec, wave, almighty, death, expel, poison, palyze, charm, close, stone, panic, sleep, curse, boss_count, enemy_id
  Enemy slime = {"スライム", 10, 10, 0, 0, 2, 1, 1, 1, 1, 1, 5, 30, 0, 150, 100, 200, 100, 100, 100, 100, 100, 200, 100, 100, 100, 100, 100, 100, 100, 100, 0, 1};
  Enemy kobalt = {"コボルト", 20, 20, 0, 0, 2, 1, 2, 1, 1, 2, 10, 55, 0, 80, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 0, 2};
  Enemy goblin = {"ゴブリン", 65, 65, 0, 0, 3, 1, 2, 2, 1, 3, 25, 500, 0, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 1, 3}; //boss
  Enemy zombiedog = {"ゾンビドッグ", 30, 30, 0, 0, 2, 1, 3, 5, 1, 3, 8, 45, 0, 100, 100, 200, 200, 100, 100, 100, -1, 200, 100, 100, 100, 100, 100, 100, 100, 100, 0, 4};
  Enemy ghoul = {"グール", 30, 30, 10, 10, 1, 1, 1, 1, 1, 2, 10, 60, 0, 100, 100, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 0, 5};
  Enemy zombie = {"ゾンビ", 55, 55, 12, 12, 3, 1, 3, 2, 1, 2, 6, 40, 0, 100, 100, 200, 100, 200, 100, 100, -1, 200, 100, 100, 100, 100, 100, 100, 100, -1, 0, 6};
  Enemy goblin_normal = {"ゴブリン", 70, 70, 0, 0, 3, 1, 3, 2, 1, 3, 10, 70, 0, 100, 150, 100, 100, 100, 200, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 0, 7};  //通常敵
  Enemy onmoraki = {"オンモラキ", 50, 50, 15, 15, 2, 3, 2, 3, 2, 4, 12, 65, 0, 80, 100, -1, 200, 100, 100, 100, -1, 100, 100, 100, 100, 100, 100, 100, 100, 100, 0, 8};
  Enemy gremlin = {"グレムリン", 350, 350, 500, 500, 4, 5, 4, 5, 5, 6, 100, 800, 0, 100, 100, 200, 200, 100, 100, 100, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 9}; //boss
  //Enemy pixie = {"ピクシー", 55, 55, 15, 15, 1, 3, 1, 5, 5, 3, 25, 40, 0, 100, 150, 100, 100, 50, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 0, 101};
  //Enemy angel = {"エンジェル", 108, 108, 30, 30, 2, 5, 3, 5, 2, 4, 50, 100, 0, 100, 100, 100, 100, 150, 100, 100, 200, 100, 100, 100, 100, 100, 100, 100, 100, 100, 1, 101};

  srand((unsigned int)time(NULL));

  P_skill player_skill = {0};
  P_skill player_skill2 = {0};
  P_skill player_skill3 = {0};
  Setting_skill setting_skill = {0};
  Setting_skill setting_skill2 = {0};
  Setting_skill setting_skill3 = {0};

  do{
    printf("MAIN MENU\n");
    printf("1:<<<LOAD GAME>>>\n");
    printf("2:<<<NEW  GAME>>>\n");
    printf("3:<<<DELETE SAVE DATA>>>\n");
    printf("4:<<<COPY SAVE DATA>>>\n");
    printf("5.<<<DELETE AUTO MAP DATA>>>\n");
    printf("6.<<<DEBUG MODE>>>\n");
    printf("1~6を入力してください(ゲームを起動しない場合はcを入力してください)\n");
    input = _getch();
    if ( input == '1' ){
      load = LOADGAME;
      save_load(&player, &player2, &player3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, load);
    }
    else if ( input == '2' ){
      //new gameでは、player.stage_clearは0
      //prologue();
      start_time = time(NULL);
      //printf("start_time:%d\n", start_time);
      game_start(&player, &player2, &player3);
      load = NEWGAME;
      game_story1(&player, &player2, &player3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, &area, &slime, &kobalt, &goblin);
      save_load(&player, &player2, &player3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, load);
    }
    else if ( input == '3' ){
      delete_savedata();
    }
    else if ( input == '4' ){
      copy_savedata();
    }
    else if ( input == '5' ){
      delete_AUtoMapFile();
    }
    else if ( input == '6' ){
      Debug_Mode(&player,&player2,&player3);
    }
    else if ( input == '' ){
      printf("強制終了\n");
      exit(EXIT_FAILURE);
    }
    else if ( input == 'c' ){
      printf("ゲームを終了します・・・\n");
      exit(EXIT_SUCCESS);
    }
  }while ( input != '1' && input != '2' && input != '3' );

  //printf("%d\n", player.stage_clear);
  load = 0;
  if ( player.stage_clear == 1 || player.stage_clear == 1.1 ){
    //start_time = time(NULL);
    game_story2(&player, &player2, &player3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items,&pEquip, &p2Equip, &p3Equip, &search, &area,&zombie,&slime,&goblin_normal,&kobalt,&zombiedog,&onmoraki,&gremlin);//図書館ステージ
    save_load(&player, &player2, &player3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, load);
  }
  else if ( player.stage_clear == 2 ){
    printf("Wait・・・\n");
  }

  return 0;
}
