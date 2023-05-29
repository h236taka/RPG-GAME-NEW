#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <conio.h>
#include <math.h>
#include <wchar.h>
#include <ctype.h>
#include <mbctype.h>
#include <mbstring.h>
#include "rpg.h"

extern int tempArray[SIZE];
//encountpatternが5のとき

int check_enemyDeadCount5(Enemy **enemy, Enemy **enemy1){
  int enemy_deadcount;

  enemy_deadcount = 2;
  if ( (*enemy) -> badstatus == DEAD ){
    //nothing
  }
  else{
    enemy_deadcount--;
  }

  if ( (*enemy1) -> badstatus == DEAD ){
    //nothing
  }
  else{
    enemy_deadcount--;
  }

  return enemy_deadcount;
}

void enemy_full_recover5(Enemy **enemy, Enemy **enemy1){

  (*enemy) -> badstatus = GOOD;
  (*enemy1) -> badstatus = GOOD;
  (*enemy) -> hp = (*enemy) -> maxhp;
  (*enemy) -> mp = (*enemy) -> maxmp;
  (*enemy1) -> hp = (*enemy1) -> maxhp;
  (*enemy1) -> mp = (*enemy1) -> maxmp;
}

//encount_pattern = 5;
void game_battle_encount_pattern5(Player ***st, Player ***st2, Player ***st3, P_skill ***player_skill, P_skill ***player_skill2, P_skill ***player_skill3, Setting_skill ***setting_skill, Setting_skill ***setting_skill2, Setting_skill ***setting_skill3, Items ***items, Equip ***pEquip, Equip ***p2Equip, Equip ***p3Equip, Enemy *enemy, Enemy *enemy1, int encount_pattern){

  int player_damage, enemy_damage, enemy_move, player_guard, player_guard2, player_guard3, move_finish;
  int skill_count, use_skill_count, skill_reaction, recover_point, battle_display_condition_count, enemy_temp;
  int result_exp, result_gold;
  int command;
  int skill_command;
  int skill_target, skill_user;
  double player_turn, enemy_turn, turn_decrease, enemy_turn_temp;
  int enemy_deadcount;
  int backAttack;

  //敵が回復スキルを使用した時の変数
  int enemyrecovertarget;
  int isEnemyUsedRecoverSkill;

  //player側の補助魔法の状況
  int playerAttackSupportSkill = DEFAULT;
  int playerMagicSupportSkill = DEFAULT;
  int playerDefendSupportSkill = DEFAULT;
  int playerEvaSupportSkill = DEFAULT;

  //enemy側の補助魔法の状況
  int enemyAttackSupportSkill = DEFAULT;
  int enemyMagicSupportSkill = DEFAULT;
  int enemyDefendSupportSkill = DEFAULT;
  int enemyEvaSupportSkill = DEFAULT;

  //経過ターン数
  int BattleTurn = 1;

  //逃走回数
  int escape_number = 0;

  if ( enemy -> boss_count == 0 ){
    printf("<<<<<<NORMAL BATTLE>>>>>>\n");
    printf("\a");
    sleep(1);
    if ( encount_pattern == 5 ){  //違う敵2体
      printf("%sと%sが現れた!\n", enemy -> name, enemy1 -> name);
      enemy_temp = 2;
      sleep(1);
    }
    printf("\n");
    sleep(1);
    backAttack = FALSE;
    if ( is_backAttack(&st,&st2,&st3) == TRUE ){
      backAttack = TRUE;
    }
  }
  else if ( enemy -> boss_count == 2 ){
    backAttack = FALSE;
    printf("------MID BOSS BATTLE------\n");
    printf("\a");
    sleep(1);
    if ( encount_pattern == 5 ){
      printf("%sと%sが現れた!\n", enemy -> name, enemy1 -> name);
      enemy_temp = 2;
      sleep(1);
    }

    printf("\n");
    sleep(1);
  }
  else{
    backAttack = FALSE;
    printf("<<<<<<<BOSS BATTLE>>>>>>>\n");
    sleep(1);
    printf("\a");
    if ( encount_pattern == 5 ){
      printf("%sと%sが現れた!\n", enemy -> name, enemy1 -> name);
      enemy_temp = 2;
      sleep(1);
    }
    printf("\n");
    sleep(1);
  }

  player_turn = 3;
  //味方パーティが生きている人数を初期プレイヤーターンとして設定
  if ( (**st) -> badstatus == DEAD ){
    player_turn--;
  }
  if ( (**st2) -> badstatus == DEAD ){
    player_turn--;
  }
  if ( (**st3) -> badstatus == DEAD ){
    player_turn--;
  }

  enemy_deadcount = 0; //enemyが死んだか判定
  skill_count = 0; //skillがあるか判定
  use_skill_count = 0; //skillの使用に関する判定
  do {
    skill_reaction = 1;
    //printf("enemy_deadcount:%d\n", enemy_deadcount);
    if ( backAttack == FALSE ){
      printf("                 <<<<<<<PLAYER TURN>>>>>>>\n");
      printf("\n");
      //戦闘画面のレイアウト
      encount_pattern5_layout(&enemy,&enemy1,encount_pattern);
      printf("\n");

      printf("       %2s                  %2s                 %2s\n", (**st) -> name, (**st2) -> name, (**st3) -> name);

      printf(" HP:%d/%d MP:%d/%d       HP:%d/%d MP:%d/%d        HP:%d/%d MP:%d/%d\n", (**st) -> hp, (**st) -> maxhp, (**st) -> mp, (**st) -> maxmp, (**st2) -> hp, (**st2) -> maxhp, (**st2) -> mp, (**st2) -> maxmp, (**st3) -> hp, (**st3) -> maxhp, (**st3) -> mp, (**st3) -> maxmp);

      //HPをグラフィックに表現
      hp_graphycal_display(&st,&st2,&st3);
      //MPをグラフィックに表現
      mp_graphycal_display(&st,&st2,&st3);

      //partyの状態異常ステータスを表示
      battle_display_condition_count = 0;
      battle_display_condition(&st, battle_display_condition_count);

      battle_display_condition_count++;
      battle_display_condition(&st2, battle_display_condition_count);

      battle_display_condition_count++;
      battle_display_condition(&st3, battle_display_condition_count);
      battle_display_condition_count = 0;
      printf("\n");
      printf("\n");
    }
    //player_turnの処理
    //主人公のターン
    player_turn = 3;
    do{
      if ( backAttack == TRUE ){
        backAttack = FALSE;
        break;
      }
      do{
        move_finish = 0;  //各playerがplayer_turnが減少する行動を行ったら1になる
        player_guard = 0; //主人公のガードを使用に関する判定
        if ( (**st) -> badstatus == DEAD ){
          printf("%sは死んでいて行動できない!\n", (**st) -> name);
          printf("\n");
          sleep(1);
          move_finish++;
          turn_decrease = -1;
          player_turn = calculate_player_turn(player_turn, turn_decrease);
        }
        else if ( (**st) -> badstatus == STONE ){
          printf("%sは石化しているため行動できない!\n", (**st) -> name);
          printf("\n");
          sleep(1);
          move_finish++;
          turn_decrease = -1;
          player_turn = calculate_player_turn(player_turn, turn_decrease);
        }
        else{
          display_player_turn(&st, player_turn);
          printf("1.ATTACK 2.SKILL 3.GUARD 4.ITEMS 5.ESCAPE 6.NEXT TURN\n");
          //printf("enemy_deadcount:%d\n", enemy_deadcount);
          printf("\n");
          printf("1~6を入力してください\n");
          command =  _getch();
          if ( command == '1' ){   //攻撃コマンド
            if ( encount_pattern == 5 ){    //敵2体
              do{
                //どちらの敵に攻撃するかチェック
                command = player_normal_attack_target5(&enemy,&enemy1);

                if ( command == '1' ){
                  turn_decrease = player_attack_for_enemy(&st, &enemy, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '2' ){
                  turn_decrease = player_attack_for_enemy(&st, &enemy1, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == 'c' ){
                  break;
                }
                else{
                  printf("1か２を入力してください\n");
                }
              }while ( command != '1' && command != '2' );

              enemy_deadcount = check_enemyDeadCount5(&enemy,&enemy1);
            }

          }
          else if ( command == '2' ){ //skillコマンド
            skill_count = battle_player_skill_list(&player_skill,&setting_skill);

            if ( skill_count != 0 ){
              do {
                skill_target = NOTARGET;
                printf("使用したいSKILL番号を入力してください! (使用しない場合はcを入力してください)\n");
                skill_command = _getch();
                if ( skill_command == '0' ){
                  if ( (**setting_skill) -> set_skill[0] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[0];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '1' ){
                  if ( (**setting_skill) -> set_skill[1] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[1];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '2' ){
                  if ( (**setting_skill) -> set_skill[2] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[2];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '3' ){
                  if ( (**setting_skill) -> set_skill[3] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[3];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '4' ){
                  if ( (**setting_skill) -> set_skill[4] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[4];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                        turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '5' ){
                  if ( (**setting_skill) -> set_skill[5] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[5];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '6' ){
                  if ( (**setting_skill) -> set_skill[6] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[6];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '7' ){
                  if ( (**setting_skill) -> set_skill[7] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[7];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '8' ){
                  if ( (**setting_skill) -> set_skill[8] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[8];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '9' ){
                  if ( (**setting_skill) -> set_skill[9] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[9];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == 'c' ){
                  printf("\n");
                  break;
                }
              }while ( skill_user == NOTARGET );    //skillを使うと数値は0ではない
            }
          }
          else if ( command == '3' ){  //防御コマンド

            //enemy_attackのテンプレート
            player_guard++;
            move_finish++;
            turn_decrease = -1;
            player_turn = calculate_player_turn(player_turn, turn_decrease);

          }
          else if ( command == '4' ){  //item使用
            turn_decrease = battle_item_use(&items,&st,&st2,&st3);
            //printf("turn_decrease:%f\n", turn_decrease);
            if ( turn_decrease == 0 ){
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish = 0;
            }
            else{
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish = 1;
            }

          }
          else if ( command == '5' ){  //逃走する
            if ( enemy -> boss_count == 0 ){
              printf("逃走中・・・\n");
              sleep(2);
              if ( battle_escape(&st,&escape_number) == 1 ){
                enemy_full_recover5(&enemy,&enemy1);
                return;
              }
              else{
                player_turn = 0;
                move_finish = 1;
              }
            }
            else{
              printf("逃走失敗!\n");
              sleep(1);
              player_turn = 0;
              move_finish = 1;
            }
          }
          else if ( command == '6' ){
            turn_decrease = 0.1;
            player_turn = calculate_player_turn(player_turn, turn_decrease);
            move_finish = 1;
            player_guard = 0;
          }
          //イレギュラーな入力が行われるとenemy_deadcountの値が最大までインクリメントされてしまうのでこの処理を追加
          else{
            if ( encount_pattern == 5 ){
              enemy_deadcount = check_enemyDeadCount5(&enemy,&enemy1);
            }

            printf("コマンドを正しく入力してください\n");
            system("pause");
            printf("\n");
          }

          if ( (**st) -> badstatus == POISON ){ //毒状態時
            poison_effect(&st);
          }
        }
        //printf("enemy_deadcount:%d\n", enemy_deadcount);
      }while ( move_finish != 1 );

      if ( enemy_deadcount == enemy_temp ){
        break;
      }

      if ( player_turn == 0 ){
        break;
      }

      printf("                 <<<<<<<PLAYER TURN>>>>>>>\n");
      printf("\n");

      //戦闘画面のレイアウト
      if ( encount_pattern == 5 ){
        encount_pattern5_layout(&enemy,&enemy1,encount_pattern);
      }

      printf("       %2s                  %2s                 %2s\n", (**st) -> name, (**st2) -> name, (**st3) -> name);

      printf(" HP:%d/%d MP:%d/%d       HP:%d/%d MP:%d/%d        HP:%d/%d MP:%d/%d\n", (**st) -> hp, (**st) -> maxhp, (**st) -> mp, (**st) -> maxmp, (**st2) -> hp, (**st2) -> maxhp, (**st2) -> mp, (**st2) -> maxmp, (**st3) -> hp, (**st3) -> maxhp, (**st3) -> mp, (**st3) -> maxmp);

      //HPをグラフィックに表現
      hp_graphycal_display(&st,&st2,&st3);
      //MPをグラフィックに表現
      mp_graphycal_display(&st,&st2,&st3);

      //partyの状態異常ステータスを表示
      battle_display_condition_count = 0;
      battle_display_condition(&st, battle_display_condition_count);

      battle_display_condition_count++;
      battle_display_condition(&st2, battle_display_condition_count);

      battle_display_condition_count++;
      battle_display_condition(&st3, battle_display_condition_count);
      battle_display_condition_count = 0;
      printf("\n");
      printf("\n");

      do{
        //２人目のターン
        move_finish = 0;
        player_guard2 = 0;

        if ( (**st2) -> badstatus == DEAD ){
          printf("%sは死んでいて行動できない!\n", (**st2) -> name);
          printf("\n");
          sleep(1);
          turn_decrease = -1;
          player_turn = calculate_player_turn(player_turn, turn_decrease);
          move_finish++;
        }
        else if ( (**st2) -> badstatus == STONE ){
          printf("%sは石化しているため行動できない!\n", (**st2) -> name);
          printf("\n");
          sleep(1);
          move_finish++;
          turn_decrease = -1;
          player_turn = calculate_player_turn(player_turn, turn_decrease);
        }
        else{
          //printf("%f\n", player_turn);
          display_player_turn(&st2, player_turn);
          printf("1.ATTACK 2.SKILL 3.GUARD 4.ITEMS 5.ESCAPE 6.NEXT TURN\n");
          //printf("enemy_deadcount:%d\n", enemy_deadcount);
          printf("\n");
          printf("1~6を入力してください\n");
          command =  _getch();
          if ( command == '1' ){   //攻撃コマンド
            if ( encount_pattern == 5 ){    //敵2体
              do{
                //どちらの敵に攻撃するかチェック
                command = player_normal_attack_target5(&enemy,&enemy1);

                if ( command == '1' ){
                  turn_decrease = player_attack_for_enemy(&st2, &enemy, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '2' ){
                  turn_decrease = player_attack_for_enemy(&st2, &enemy1, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == 'c' ){
                  break;
                }
                else{
                  printf("1か２を入力してください\n");
                }
              }while ( command != '1' && command != '2' );

              enemy_deadcount = check_enemyDeadCount5(&enemy,&enemy1);
            }

          }
          else if ( command == '2' ){ //skillコマンド
            skill_count = battle_player_skill_list(&player_skill2,&setting_skill2);

            if ( skill_count != 0 ){
              do {
                skill_target = NOTARGET;
                printf("使用したいSKILL番号を入力してください! (使用しない場合はcを入力してください)\n");
                skill_command = _getch();
                if ( skill_command == '0' ){
                  if ( (**setting_skill2) -> set_skill[0] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[0];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '1' ){
                  if ( (**setting_skill2) -> set_skill[1] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[1];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '2' ){
                  if ( (**setting_skill2) -> set_skill[2] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[2];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '3' ){
                  if ( (**setting_skill2) -> set_skill[3] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[3];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '4' ){
                  if ( (**setting_skill2) -> set_skill[4] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[4];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '5' ){
                  if ( (**setting_skill2) -> set_skill[5] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[5];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '6' ){
                  if ( (**setting_skill2) -> set_skill[6] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[6];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '7' ){
                  if ( (**setting_skill2) -> set_skill[7] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[7];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '8' ){
                  if ( (**setting_skill2) -> set_skill[8] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[8];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '9' ){
                  if ( (**setting_skill2) -> set_skill[9] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[9];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == 'c' ){
                  printf("\n");
                  break;
                }
              }while ( skill_user == NOTARGET );    //skillを使うと数値は0ではない
            }
          }
          else if ( command == '3' ){  //防御コマンド

            //enemy_attackのテンプレート
            player_guard2++;
            turn_decrease = -1;
            player_turn = calculate_player_turn(player_turn, turn_decrease);
            move_finish++;
          }
          else if ( command == '4' ){  //item使用
            turn_decrease = battle_item_use(&items,&st,&st2,&st3);
            if ( turn_decrease == 0 ){
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish = 0;
            }
            else{
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish = 1;
            }

          }
          else if ( command == '5' ){  //逃走する
            if ( enemy -> boss_count == 0 ){
              printf("逃走中・・・\n");
              sleep(2);
              if ( battle_escape(&st2,&escape_number) == 1 ){
                enemy_full_recover5(&enemy,&enemy1);
                return;
              }
              else{
                player_turn = 0;
                move_finish = 1;
              }
            }
            else{
              printf("逃走失敗!\n");
              sleep(1);
              move_finish = 1;
              player_turn = 0;
            }
          }
          else if ( command == '6' ){
            turn_decrease = 0.1;
            player_turn = calculate_player_turn(player_turn, turn_decrease);
            move_finish = 1;
            player_guard2 = 0;
          }
          //イレギュラーな入力が行われるとenemy_deadcountの値が最大までインクリメントされてしまうのでこの処理を追加
          else{
            if ( encount_pattern == 5 ){
              enemy_deadcount = check_enemyDeadCount5(&enemy,&enemy1);
            }
            printf("コマンドを正しく入力してください\n");
            system("pause");
            printf("\n");
          }

          if ( (**st2) -> badstatus == POISON ){ //毒状態時
            poison_effect(&st2);
          }
        }
      }while ( move_finish != 1 );

      if ( enemy_deadcount == enemy_temp ){
        break;
      }

      if ( player_turn == 0 ){
        break;
      }

      printf("                 <<<<<<<PLAYER TURN>>>>>>>\n");
      printf("\n");

      //戦闘画面のレイアウト
      if ( encount_pattern == 5 ){
        encount_pattern5_layout(&enemy,&enemy1,encount_pattern);
      }

      printf("       %2s                  %2s                 %2s\n", (**st) -> name, (**st2) -> name, (**st3) -> name);

      printf(" HP:%d/%d MP:%d/%d       HP:%d/%d MP:%d/%d        HP:%d/%d MP:%d/%d\n", (**st) -> hp, (**st) -> maxhp, (**st) -> mp, (**st) -> maxmp, (**st2) -> hp, (**st2) -> maxhp, (**st2) -> mp, (**st2) -> maxmp, (**st3) -> hp, (**st3) -> maxhp, (**st3) -> mp, (**st3) -> maxmp);

      //HPをグラフィックに表現
      hp_graphycal_display(&st,&st2,&st3);
      //MPをグラフィックに表現
      mp_graphycal_display(&st,&st2,&st3);

      //partyの状態異常ステータスを表示
      battle_display_condition_count = 0;
      battle_display_condition(&st, battle_display_condition_count);

      battle_display_condition_count++;
      battle_display_condition(&st2, battle_display_condition_count);

      battle_display_condition_count++;
      battle_display_condition(&st3, battle_display_condition_count);
      battle_display_condition_count = 0;
      printf("\n");
      printf("\n");

      do{
        move_finish = 0;
        player_guard3 = 0;

        if ( (**st3) -> badstatus == DEAD ){
          printf("%sは死んでいて行動できない!\n", (**st3) -> name);
          printf("\n");
          sleep(1);
          turn_decrease = -1;
          player_turn = calculate_player_turn(player_turn, turn_decrease);
          move_finish++;
        }
        else if ( (**st3) -> badstatus == STONE ){
          printf("%sは石化しているため行動できない!\n", (**st3) -> name);
          printf("\n");
          sleep(1);
          move_finish++;
          turn_decrease = -1;
          player_turn = calculate_player_turn(player_turn, turn_decrease);
        }
        else{
          //printf("%f\n", player_turn);
          display_player_turn(&st3, player_turn);
          printf("1.ATTACK 2.SKILL 3.GUARD 4.ITEMS 5.ESCAPE 6.NEXT TURN\n");
          //printf("enemy_deadcount:%d\n", enemy_deadcount);
          printf("\n");
          printf("1~6を入力してください\n");
          command =  _getch();
          if ( command == '1' ){   //攻撃コマンド
            if ( encount_pattern == 5 ){    //敵5体
              do{
                //どちらの敵に攻撃するかチェック
                command = player_normal_attack_target5(&enemy,&enemy1);

                if ( command == '1' ){
                  turn_decrease = player_attack_for_enemy(&st3, &enemy, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '2' ){
                  turn_decrease = player_attack_for_enemy(&st3, &enemy1, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == 'c' ){
                  break;
                }
                else{
                  printf("1か２を入力してください\n");
                }
              }while ( command != '1' && command != '2' );

              enemy_deadcount = check_enemyDeadCount5(&enemy,&enemy1);
            }
          }
          else if ( command == '2' ){ //skillコマンド
            skill_count = battle_player_skill_list(&player_skill3,&setting_skill3);

            if ( skill_count != 0 ){
              do {
                skill_target = NOTARGET;
                printf("使用したいSKILL番号を入力してください! (使用しない場合はcを入力してください)\n");
                skill_command = _getch();
                if ( skill_command == '0' ){
                  if ( (**setting_skill3) -> set_skill[0] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[0];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '1' ){
                  if ( (**setting_skill3) -> set_skill[1] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[1];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '2' ){
                  if ( (**setting_skill3) -> set_skill[2] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[2];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '3' ){
                  if ( (**setting_skill3) -> set_skill[3] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[3];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '4' ){
                  if ( (**setting_skill3) -> set_skill[4] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[4];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '5' ){
                  if ( (**setting_skill3) -> set_skill[5] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[5];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          player_skill_forEnemy(&st3,&player_skill3,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '6' ){
                  if ( (**setting_skill3) -> set_skill[6] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[6];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '7' ){
                  if ( (**setting_skill3) -> set_skill[7] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[7];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '8' ){
                  if ( (**setting_skill3) -> set_skill[8] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[8];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '9' ){
                  if ( (**setting_skill3) -> set_skill[9] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[9];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      skill_target = select_encount_pattern5_skillTarget(&enemy,&enemy1);
                      if ( skill_target == ENEMY1 ){
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( skill_target == ENEMY2 ){
                        if ( is_enemy_alive(&enemy1) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy1,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == 'c' ){
                  printf("\n");
                  break;
                }
              }while ( skill_user == NOTARGET );    //skillを使うと数値は0ではない
            }
          }
          else if ( command == '3' ){  //防御コマンド

            //enemy_attackのテンプレート
            player_guard3++;
            player_turn--;
            move_finish++;
          }
          else if ( command == '4' ){  //item使用
            turn_decrease = battle_item_use(&items,&st,&st2,&st3);
            if ( turn_decrease == 0 ){
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish = 0;
            }
            else{
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish = 1;
            }

          }
          else if ( command == '5' ){  //逃走する
            if ( enemy -> boss_count == 0 ){
              printf("逃走中・・・\n");
              sleep(2);
              if ( battle_escape(&st3,&escape_number) == 1 ){
                enemy_full_recover5(&enemy,&enemy1);
                return;
              }
              else{
                player_turn = 0;
                move_finish = 1;
              }
            }
            else{
              printf("逃走失敗!\n");
              sleep(1);
              move_finish = 1;
              player_turn = 0;
            }
          }
          else if ( command == '6' ){
            turn_decrease = 0.1;
            player_turn = calculate_player_turn(player_turn, turn_decrease);
            move_finish = 1;
            player_guard3 = 0;
          }
          //イレギュラーな入力が行われるとenemy_deadcountの値が最大までインクリメントされてしまうのでこの処理を追加
          else{
            if ( encount_pattern == 5 ){
              enemy_deadcount = check_enemyDeadCount5(&enemy,&enemy1);
            }

            printf("コマンドを正しく入力してください\n");
            system("pause");
            printf("\n");
          }

          if ( (**st3) -> badstatus == POISON ){ //毒状態時
            poison_effect(&st3);
          }
        }

      }while ( move_finish != 1 );

      if ( enemy_deadcount == enemy_temp ){
        break;
      }

    }while ( player_turn != 0 );

    //enemy_turn;
    if ( enemy_deadcount == enemy_temp ){
      break;
    }

    //関係のない値の代入
    enemy_turn_temp = -2;

    //敵の攻撃
    do {
      enemy_turn = 2;
      if ( enemy -> badstatus == DEAD ){
        enemy_turn--;
      }
      if ( enemy1 -> badstatus == DEAD ){
        enemy_turn--;
      }
      //printf("enemy_turn:%f\n", enemy_turn);
      //printf("enemy_turn_temp:%f\n", enemy_turn_temp);

      if ( enemy_turn != enemy_turn_temp && enemy_turn_temp != -2 ){
        enemy_turn = enemy_turn_temp;
      }
      //printf("enemy_turn:%f\n", enemy_turn);
      //printf("enemy_turn_temp:%f\n", enemy_turn_temp);

      printf("                 <<<<<<<ENEMY TURN>>>>>>>\n");
      printf("\n");
      encount_pattern5_layout(&enemy,&enemy1,encount_pattern);
      printf("\n");
      sleep(1);

      printf("       %3s                   %3s                 %3s\n", (**st) -> name, (**st2) -> name, (**st3) -> name);
      printf(" HP:%d/%d MP:%d/%d       HP:%d/%d MP:%d/%d       HP:%d/%d MP:%d/%d\n", (**st) -> hp, (**st) -> maxhp, (**st) -> mp, (**st) -> maxmp, (**st2) -> hp, (**st2) -> maxhp, (**st2) -> mp, (**st2) -> maxmp, (**st3) -> hp, (**st3) -> maxhp, (**st3) -> mp, (**st3) -> maxmp);
      battle_display_condition_count = 0;
      hp_graphycal_display(&st,&st2,&st3);
      mp_graphycal_display(&st,&st2,&st3);
      battle_display_condition(&st, battle_display_condition_count);
      battle_display_condition_count++;
      battle_display_condition(&st2, battle_display_condition_count);
      battle_display_condition_count++;
      battle_display_condition(&st3, battle_display_condition_count);
      printf("\n");
      //printf("enemy's badstatus:%d\n", enemy -> badstatus);
      //printf("enemy_copy1's badstatus:%d\n", enemy_copy1.badstatus);
      if ( enemy -> badstatus != DEAD ){
        display_enemy_turn(&enemy, enemy_turn);
        //enemyの攻撃
        //printf("%f\n", enemy_turn);
        sleep(1);
        enemy_turn = enemy_attack_pattern(&st, &st2, &st3, &pEquip, &p2Equip, &p3Equip, &enemy, player_guard, player_guard2, player_guard3, enemy_turn);
        sleep(1);
        //printf("%f\n", enemy_turn);
        printf("\n");
      }

      if ( (**st) -> badstatus == DEAD && (**st2) -> badstatus == DEAD && (**st3) -> badstatus == DEAD ){
        display_gameover();
      }
      if ( enemy_turn <= 0 ){
        break;
      }

      if ( enemy1 -> badstatus != DEAD ){
        sleep(1);
        display_enemy_turn(&enemy1, enemy_turn);
        //enemyの攻撃
        //printf("%f\n", enemy_turn);
        sleep(1);
        enemy_turn = enemy_attack_pattern(&st, &st2, &st3, &pEquip, &p2Equip, &p3Equip, &enemy1, player_guard, player_guard2, player_guard3, enemy_turn);
        sleep(1);
        //printf("%f\n", enemy_turn);
      }

      if ( (**st) -> badstatus == DEAD && (**st2) -> badstatus == DEAD && (**st3) -> badstatus == DEAD ){
        display_gameover();
      }
      if ( enemy_turn <= 0 ){
        break;
      }

      enemy_turn_temp = enemy_turn;

    }while ( enemy_turn > 0 );

  }while( enemy_deadcount != enemy_temp || ( (**st) -> badstatus != DEAD && (**st2) -> badstatus != DEAD && (**st3) -> badstatus != DEAD ) );

  //encount_pattern = 5;
  enemy_full_recover5(&enemy,&enemy1);

  result_exp = 0;
  result_gold = 0;
  int battle_experience = 0;
  if ( encount_pattern == 5 ){
    result_exp = enemy -> exp + enemy1 -> exp;
    result_gold = enemy -> gold + enemy1 -> gold;
    battle_experience = enemy -> lv + enemy1 -> lv;
  }

  printf("\a");
  sleep(1);
  printf("%s達は戦闘に勝利した!\n", (**st) -> name);
  printf("------RESULT------\n");
  printf("  EXP:%d GOLD:%d\n", result_exp, result_gold);
  printf("  EP:%d\n", battle_experience);
  printf("\n");

  //スキルの熟練度チェック
  if ( is_skill_learning(&player_skill) == TRUE ){
    add_battleExperience(&st,&player_skill,battle_experience);
  }
  if ( is_skill_learning(&player_skill2) == TRUE ){
    add_battleExperience(&st2,&player_skill2,battle_experience);
  }
  if ( is_skill_learning(&player_skill3) == TRUE ){
    add_battleExperience(&st3,&player_skill3,battle_experience);
  }


  //アイテムドロップ
  item_drop(&st,&st2,&st3,&enemy,&items,encount_pattern);
  item_drop(&st,&st2,&st3,&enemy1,&items,encount_pattern);

  if ( (**st) -> badstatus == DEAD ){
    //経験値獲得無し
  }
  else{
    (**st) -> exp += result_exp;
    (**st) -> sumexp += result_exp;
    level_up(&st, &player_skill,&setting_skill);
  }
  if ( (**st2) -> badstatus == DEAD ){
    //獲得経験値なし
  }
  else{
    (**st2) -> exp += result_exp;
    (**st2) -> sumexp += result_exp;
    level_up(&st2, &player_skill2,&setting_skill2);
  }
  if ( (**st3) -> badstatus == DEAD ){
    //獲得経験値なし
  }
  else{
    (**st3) -> exp += result_exp;
    (**st3) -> sumexp += result_exp;
    level_up(&st3, &player_skill3,&setting_skill3);
  }

  (**st) -> gold += result_gold;

  player_badstatus_recover(&st);
  player_badstatus_recover(&st2);
  player_badstatus_recover(&st3);

}
