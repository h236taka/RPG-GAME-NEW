#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <conio.h>
#include <wchar.h>
#include "rpg.h"

//セーブとロード

extern time_t start_time, end_time;
extern int play_time;

int saveFile = 0;

//セーブデータのバイト数をreturn
//long 型よりもさらに大きな数を表現できる型
long long int getFileSize(const char *fileName){
  struct stat st;

  if ( stat(fileName, &st) != 0 ){
    return -1LL;
  }

  //ファイルであるかチェック
  if ( (st.st_mode & S_IFMT) != S_IFREG ){
    return -1LL;
  }

  return st.st_size;
}

void copy_saveData(){
  int input, result;
  FILE *fpSrc;
  FILE *fpDest;

  do {
    printf("何番のセーブデータをコピーしますか?(コピーしない場合はcを入力)\n");
    printf("1:SAVEDATA FILE1\n");
    printf("2:SAVEDATA FILE2\n");
    printf("3:SAVEDATA FILE3\n");

    result = 1;
    input = _getch();

    if ( input == '1' ){
      const char *file = "SaveData/save1.dat";
      fpSrc = fopen("SaveData/save1.dat", "rb");
      if ( fpSrc == NULL ){
        printf("セーブデータ1を確認できませんでした...\n");
        fclose(fpSrc);
        exit(EXIT_FAILURE);
      }

      do {
        printf("\n");
        printf("コピー先のセーブデータを選んでください(コピーしない場合はcを入力)\n");
        printf("2:SAVEDATA FILE2\n");
        printf("3:SAVEDATA FILE3\n");

        input = _getch();

        if ( input == 'c' ){
          printf("コピーを中止します...");
          exit(EXIT_SUCCESS);
        }
        else if ( input == '2' ){
          fpDest = fopen("SaveData/save2.dat", "wb");
          if ( fpDest == NULL ){
            printf("セーブデータ2を確認できませんでした...\n");
            fclose(fpDest);
            exit(EXIT_FAILURE);
          }

          for (;;) {  //無限ループ
            char c;
            // 1バイト読み込む
            if ( fread(&c, sizeof(c), 1, fpSrc) < 1 ) {
              if ( feof(fpSrc) ) {  //ファイルの読み込みが終了位置に到達したかチェック
                break;
              }
              else {
                result = 0;
                break;
              }
            }

            // 1バイト書き込む
            if ( fwrite(&c, sizeof(c), 1, fpDest) < 1 ) {
              result = 0;
              break;
            }
          }

          if ( result != 0 ){
            printf("コピーが完了しました...\n");
            exit(EXIT_SUCCESS);
          }
          else{
            printf("コピーに失敗しました...\n");
            exit(EXIT_FAILURE);
          }

        }
        else if ( input == '3' ){
          fpDest = fopen("SaveData/save3.dat", "wb");
          if ( fpDest == NULL ){
            printf("セーブデータ3を確認できませんでした...\n");
            fclose(fpDest);
            exit(EXIT_FAILURE);
          }

          for (;;) {
            char c;
            // 1バイト読み込む
            if ( fread(&c, sizeof(c), 1, fpSrc) < 1 ) {
              if ( feof(fpSrc) ) {
                break;
              }
              else {
                result = 0;
                break;
              }
            }

            // 1バイト書き込む
            if ( fwrite(&c, sizeof(c), 1, fpDest) < 1 ) {
              result = 0;
              break;
            }
          }

          if ( result != 0 ){
            printf("コピーが完了しました...\n");
            exit(EXIT_SUCCESS);
          }
          else{
            printf("コピーに失敗しました...\n");
            exit(EXIT_FAILURE);
          }
        }

      } while ( input != 'c' );
    }
    else if ( input == '2' ){
      const char *file = "SaveData/save2.dat";
      fpSrc = fopen("SaveData/save2.dat", "rb");
      if ( fpSrc == NULL ){
        printf("セーブデータ2を確認できませんでした...\n");
        fclose(fpSrc);
        exit(EXIT_FAILURE);
      }

      do {
        printf("\n");
        printf("コピー先のセーブデータを選んでください(コピーしない場合はcを入力)\n");
        printf("1:SAVEDATA FILE2\n");
        printf("3:SAVEDATA FILE3\n");

        input = _getch();

        if ( input == 'c' ){
          printf("コピーを中止します...");
          exit(EXIT_SUCCESS);
        }
        else if ( input == '1' ){
          fpDest = fopen("SaveData/save1.dat", "wb");
          if ( fpDest == NULL ){
            printf("セーブデータ1を確認できませんでした...\n");
            fclose(fpDest);
            exit(EXIT_FAILURE);
          }

          for (;;) {
            char c;
            // 1バイト読み込む
            if ( fread(&c, sizeof(c), 1, fpSrc) < 1 ) {
              if ( feof(fpSrc) ) {
                break;
              }
              else {
                result = 0;
                break;
              }
            }

            // 1バイト書き込む
            if ( fwrite(&c, sizeof(c), 1, fpDest) < 1 ) {
              result = 0;
              break;
            }
          }

          if ( result != 0 ){
            printf("コピーが完了しました...\n");
            exit(EXIT_SUCCESS);
          }
          else{
            printf("コピーに失敗しました...\n");
            exit(EXIT_FAILURE);
          }

        }
        else if ( input == '3' ){
          fpDest = fopen("SaveData/save3.dat", "wb");
          if ( fpDest == NULL ){
            printf("セーブデータ3を確認できませんでした...\n");
            fclose(fpDest);
            exit(EXIT_FAILURE);
          }

          for (;;) {
            char c;
            // 1バイト読み込む
            if ( fread(&c, sizeof(c), 1, fpSrc) < 1 ) {
              if ( feof(fpSrc) ) {
                break;
              }
              else {
                result = 0;
                break;
              }
            }

            // 1バイト書き込む
            if ( fwrite(&c, sizeof(c), 1, fpDest) < 1 ) {
              result = 0;
              break;
            }
          }

          if ( result != 0 ){
            printf("コピーが完了しました...\n");
            exit(EXIT_SUCCESS);
          }
          else{
            printf("コピーに失敗しました...\n");
            exit(EXIT_FAILURE);
          }
        }

      } while ( input != 'c' );

    }
    else if ( input == '3' ){
      const char *file = "SaveData/save3.dat";
      fpSrc = fopen("SaveData/save3.dat", "rb");
      if ( fpSrc == NULL ){
        printf("セーブデータ3を確認できませんでした...\n");
        fclose(fpSrc);
        exit(EXIT_FAILURE);
      }

      do {
        printf("\n");
        printf("コピー先のセーブデータを選んでください(コピーしない場合はcを入力)\n");
        printf("1:SAVEDATA FILE2\n");
        printf("2:SAVEDATA FILE3\n");

        input = _getch();

        if ( input == 'c' ){
          printf("コピーを中止します...");
          exit(EXIT_SUCCESS);
        }
        else if ( input == '1' ){
          fpDest = fopen("SaveData/save1.dat", "wb");
          if ( fpDest == NULL ){
            printf("セーブデータ1を確認できませんでした...\n");
            fclose(fpDest);
            exit(EXIT_FAILURE);
          }

          for (;;) {
            char c;
            // 1バイト読み込む
            if ( fread(&c, sizeof(c), 1, fpSrc) < 1 ) {
              if ( feof(fpSrc) ) {
                break;
              }
              else {
                result = 0;
                break;
              }
            }

            // 1バイト書き込む
            if ( fwrite(&c, sizeof(c), 1, fpDest) < 1 ) {
              result = 0;
              break;
            }
          }

          if ( result != 0 ){
            printf("コピーが完了しました...\n");
            exit(EXIT_SUCCESS);
          }
          else{
            printf("コピーに失敗しました...\n");
            exit(EXIT_FAILURE);
          }

        }
        else if ( input == '2' ){
          fpDest = fopen("SaveData/save2.dat", "wb");
          if ( fpDest == NULL ){
            printf("セーブデータ2を確認できませんでした...\n");
            fclose(fpDest);
            exit(EXIT_FAILURE);
          }

          for (;;) {
            char c;
            // 1バイト読み込む
            if ( fread(&c, sizeof(c), 1, fpSrc) < 1 ) {
              if ( feof(fpSrc) ) {
                break;
              }
              else {
                result = 0;
                break;
              }
            }

            // 1バイト書き込む
            if ( fwrite(&c, sizeof(c), 1, fpDest) < 1 ) {
              result = 0;
              break;
            }
          }

          if ( result != 0 ){
            printf("コピーが完了しました...\n");
            exit(EXIT_SUCCESS);
          }
          else{
            printf("コピーに失敗しました...\n");
            exit(EXIT_FAILURE);
          }
        }

      } while ( input != 'c' );
    }
    else if ( input == 'c' ){
      printf("コピーを中止します...\n");
      exit(EXIT_SUCCESS);
    }

  } while( input != 'c' );
}

void delete_saveData(){
  int input;
  FILE *fp;


  do{
    printf("何番のセーブデータを削除しますか？(削除しない場合はcを入力)\n");
    printf("1:SAVEDATA FILE1\n");
    printf("2:SAVEDATA FILE2\n");
    printf("3:SAVEDATA FILE3\n");
    input = _getch();
    if ( input == '1' ){
      const char *file = "SaveData/save1.dat";
      fp = fopen("SaveData/save1.dat", "rb");
      if ( fp == NULL ){
        printf("セーブデータ1を読み込めませんでした...\n");
        fclose(fp);
        exit(EXIT_FAILURE);
      }
      else{
        fclose(fp);
        if ( remove(file) == 0 ){
          printf("セーブデータ1を削除しました!\n");
          input = 1;
          delete_AUtoMapFile(input);
          fp = fopen( "SaveData/save1.dat", "wb+");
        }
        else{
          printf("セーブデータ1を削除できませんでした...\n");
          exit(EXIT_FAILURE);
        }
      }
    }
    else if ( input == '2' ){
      const char *file = "SaveData/save2.dat";
      fp = fopen("SaveData/save2.dat", "rb");
      if ( fp == NULL ){
        printf("セーブデータ2を読み込めませんでした...\n");
        fclose(fp);
        exit(EXIT_FAILURE);
      }
      else{
        fclose(fp);
        if ( remove(file) == 0 ){
          printf("セーブデータ2を削除しました!\n");
          input = 2;
          delete_AUtoMapFile(input);
          fp = fopen( "SaveData/save2.dat", "wb+");
        }
        else{
          printf("セーブデータ2を削除できませんでした...\n");
          exit(EXIT_FAILURE);
        }
      }
    }
    else if ( input == '3' ){
      const char *file = "SaveData/save3.dat";
      fp = fopen("SaveData/save3.dat", "rb");
      if ( fp == NULL ){
        printf("セーブデータ3を読み込めませんでした...\n");
        fclose(fp);
        exit(EXIT_FAILURE);
      }
      else{
        fclose(fp);
        if ( remove(file) == 0 ){
          printf("セーブデータ3を削除しました!\n");
          input = 3;
          delete_AUtoMapFile(input);
          fp = fopen( "SaveData/save3.dat", "wb+");
        }
        else{
          printf("セーブデータ3を削除できませんでした...\n");
          exit(EXIT_FAILURE);
        }
      }
    }
    else if ( input == 'c' ){
      break;
    }
    else{
      printf("1,2,3のいずれかを入力してください...\n");
    }

  }while( input != '1' && input != '2' && input != '3' );

  exit(EXIT_SUCCESS);

}

void check_AutoMapFile(){
  FILE *fp;

  if ( ( fp = fopen( "AutoMapArea2/saveFile1_AutoMapArea2.dat", "rb" ) ) == NULL ){
    fp = fopen("AutoMapArea2/saveFile1_AutoMapArea2.dat", "wb+");
  }
  if ( ( fp = fopen( "AutoMapArea2/saveFile2_AutoMapArea2.dat", "rb" ) ) == NULL ){
    fp = fopen("AutoMapArea2/saveFile2_AutoMapArea2.dat", "wb+");
  }
  if ( ( fp = fopen( "AutoMapArea2/saveFile3_AutoMapArea2.dat", "rb" ) ) == NULL ){
    fp = fopen("AutoMapArea2/saveFile3_AutoMapArea2.dat", "wb+");
  }

  fclose(fp);
}

void delete_AUtoMapFile(int input){
  FILE *fp;

  if ( input == 1 ){
    char *file = "AutoMapArea2/saveFile1_AutoMapArea2.dat";
    if ( ( fp = fopen( "AutoMapArea2/saveFile1_AutoMapArea2.dat", "rb" ) ) == NULL ){
      //printf("マップデータは存在しません...\n");
      fclose(fp);
      exit(EXIT_SUCCESS);
    }
    else{
      fclose(fp);
      if ( remove(file) == 0 ){
        //printf("マップデータを削除しました!\n");
      }
      else{
        //printf("マップデータを削除できませんでした...\n");
      }
      fclose(fp);
      exit(EXIT_SUCCESS);
    }
  }
  else if ( input == 2 ){
    char *file = "AutoMapArea2/saveFile2_AutoMapArea2.dat";
    if ( ( fp = fopen( "AutoMapArea2/saveFile2_AutoMapArea2.dat", "rb" ) ) == NULL ){
      ///printf("マップデータは存在しません...\n");
      fclose(fp);
      exit(EXIT_SUCCESS);
    }
    else{
      fclose(fp);
      if ( remove(file) == 0 ){
        //printf("マップデータを削除しました!\n");
      }
      else{
        //printf("マップデータを削除できませんでした...\n");
      }
      fclose(fp);
      exit(EXIT_SUCCESS);
    }
  }
  else if ( input == 3 ){
    char *file = "AutoMapArea2/saveFile3_AutoMapArea2.dat";
    if ( ( fp = fopen( "AutoMapArea2/saveFile3_AutoMapArea2.dat", "rb" ) ) == NULL ){
      //printf("マップデータは存在しません...\n");
      fclose(fp);
      exit(EXIT_SUCCESS);
    }
    else{
      fclose(fp);
      if ( remove(file) == 0 ){
        //printf("マップデータを削除しました!\n");
      }
      else{
        //printf("マップデータを削除できませんでした...\n");
      }
      fclose(fp);
      exit(EXIT_SUCCESS);
    }
  }
}

void load_items(Items **items, Save_data_items *save_data_items){

  (*items) -> medicine = save_data_items -> medicine;
  (*items) -> lifestone = save_data_items -> lifestone;
  (*items) -> antipoison = save_data_items -> antipoison;
  (*items) -> bead = save_data_items -> bead;
}

void load_equip(Equip **equip, Save_data_equip *save_data_equip){

  (*equip) -> HpRing1 = save_data_equip -> HpRing1;
  (*equip) -> MpRing1 = save_data_equip -> MpRing1;
  (*equip) -> isEquip = save_data_equip -> isEquip;
}

void load_playersSkill(P_skill **player_skill, Save_data_player_skill *save_data_player_skill){

  for ( int i = 0; i < 4; i++ ){
    (*player_skill) -> recover1[i] = save_data_player_skill -> recover1[i];
  }

  for ( int i = 0; i < 4; i++ ){
    (*player_skill) -> cure_poison[i] = save_data_player_skill -> cure_poison[i];
  }

  for ( int i = 0; i < 4; i++ ){
    (*player_skill) -> recover2[i] = save_data_player_skill -> recover2[i];
  }

  for ( int i = 0; i < 4; i++ ){
    (*player_skill) -> enfa[i] = save_data_player_skill -> enfa[i];
  }

  for ( int i = 0; i < 4; i++ ){
    (*player_skill) -> hyodo[i] = save_data_player_skill -> hyodo[i];
  }

  for ( int i = 0; i < 4; i++ ){
    (*player_skill) -> volua[i] = save_data_player_skill -> volua[i];
  }

  for ( int i = 0; i < 4; i++ ){
    (*player_skill) -> whive[i] = save_data_player_skill -> whive[i];
  }

}

void save_load(Player *st, Player *st2, Player *st3, P_skill *player_skill, P_skill *player_skill2, P_skill *player_skill3, Setting_skill *setting_skill, Setting_skill *setting_skill2, Setting_skill *setting_skill3, Items *items, Equip *pEquip, Equip *p2Equip, Equip *p3Equip, SearchDangeon *search, int load){

  int save_count, load_count, input, savedata_num, savedata_lv1, savedata_lv2, savedata_lv3, temp, hours, minutes;
  char savedata_name1[7], savedata_name2[7], savedata_name3[7];
  FILE *fp;
  const char *file;
  int n;

  Save_data_players save_data_players;
  Save_data_players save_data_players2;
  Save_data_players save_data_players3;

  Save_data_player_skill save_data_player_skill;
  Save_data_player_skill save_data_player_skill2;
  Save_data_player_skill save_data_player_skill3;

  Save_data_items save_data_items;

  Save_data_equip save_data_pEquip;
  Save_data_equip save_data_p2Equip;
  Save_data_equip save_data_p3Equip;

  Save_data_search Save_data_search;

  Save_data_setting_skill save_data_setting_skill;
  Save_data_setting_skill save_data_setting_skill2;
  Save_data_setting_skill save_data_setting_skill3;

  check_AutoMapFile();


  if ( load == LOADGAME ){       //load
    do{
      load_count = 0;

      printf("\n");
      printf("何番のセーブデータを読み込みますか？\n");

      if ( ( fp = fopen( "SaveData/save1.dat", "rb" ) ) == NULL ){
        //can't open file. So create new file
        fp = fopen( "SaveData/save1.dat", "wb+");
        printf("1:NO DATA\n");
      }
      else{
        if ( getFileSize( "SaveData/save1.dat") == 0 ){                   //fileのbyteが０ならデータがない
          //printf("セーブデータを読み込めませんでした・・・\n");
          printf("1:NO DATA\n");
        }
        else{
          fread(&save_data_players, sizeof(save_data_players), 1, fp);
          strcpy(savedata_name1, save_data_players.name);
          savedata_lv1 = save_data_players.lv;

          //printf("playtime:%d\n", save_data_players.playtime);
          temp = save_data_players.playtime;
          //temp -= 1000;
          if ( temp >= 3600 ){
            hours = temp / 3600;
            minutes = temp % 3600 / 60;
          }
          else{
            hours = 0;
            printf("seconds:%d\n", temp);
            minutes = 0;
            while ( temp >= 60 ){
              temp -= 60;
              minutes++;
            }
          }

          if ( minutes < 10 ){
            printf("1:%s LV%d プレイ時間 %d:0%d\n", savedata_name1, savedata_lv1, hours, minutes);
            fclose(fp);
          }
          else{
            printf("1:%s LV%d プレイ時間 %d:%d\n", savedata_name1, savedata_lv1, hours, minutes);
            fclose(fp);
          }

        }
      }

      if ( ( fp = fopen( "SaveData/save2.dat", "rb" ) ) == NULL ){
        //can't open file. So create new file
        fp = fopen( "SaveData/save2.dat", "wb+");
        printf("2:NO DATA\n");
      }
      else{
        if ( getFileSize( "SaveData/save2.dat") == 0 ){                   //fileのbyteが０ならデータがない
          //printf("セーブデータを読み込めませんでした・・・\n");
          printf("2:NO DATA\n");
        }
        else{
          fread(&save_data_players, sizeof(Save_data_players), 1, fp);
          strcpy(savedata_name2, save_data_players.name);
          savedata_lv2 = save_data_players.lv;

          temp = save_data_players.playtime;
          if ( temp >= 3600 ){
            hours = temp / 3600;
            minutes = temp % 3600 / 60;
          }
          else{
            hours = 0;
            minutes = temp / 60 % 60;
          }

          if ( minutes < 10 ){
            printf("2:%s LV%d プレイ時間 %d:0%d\n", savedata_name1, savedata_lv1, hours, minutes);
            fclose(fp);
          }
          else{
            printf("2:%s LV%d プレイ時間 %d:%d\n", savedata_name1, savedata_lv1, hours, minutes);
            fclose(fp);
          }

        }
      }

      if ( ( fp = fopen( "SaveData/save3.dat", "rb" ) ) == NULL ){
        //can't open file. So create new file
        fp = fopen( "SaveData/save3.dat", "wb+");
        printf("3:NO DATA\n");
      }
      else{
        if ( getFileSize( "SaveData/save3.dat") == 0 ){                   //fileのbyteが０ならデータがない
          //printf("セーブデータを読み込めませんでした・・・\n");
          printf("3:NO DATA\n");
        }
        else{
          fread(&save_data_players, sizeof(Save_data_players), 1, fp);
          strcpy(savedata_name3, save_data_players.name);
          savedata_lv3 = save_data_players.lv;
          temp = save_data_players.playtime;
          if ( temp >= 3600 ){
            hours = temp / 3600;
            minutes = temp % 3600 / 60;
          }
          else{
            hours = 0;
            minutes = temp / 60 % 60;
          }

          if ( minutes < 10 ){
            printf("3:%s LV%d プレイ時間 %d:0%d\n", savedata_name1, savedata_lv1, hours, minutes);
            fclose(fp);
          }
          else{
            printf("3:%s LV%d プレイ時間 %d:%d\n", savedata_name1, savedata_lv1, hours, minutes);
            fclose(fp);
          }

        }
      }

      printf("1~3の数字を入力してください!\n");
      printf("セーブデータの読み込みを中止するときはnを入力してください!\n");
      input = _getch();

      if ( input == '1' ){
        //ファイル処理
        if ( ( fp = fopen( "SaveData/save1.dat", "rb" ) ) == NULL ){
          printf("セーブデータがありません\n");
        }
        else{
          //セーブデータの読み込み
          if ( getFileSize( "SaveData/save1.dat") == 0 ){                   //fileのbyteが０ならデータがない
            printf("セーブデータを読み込めませんでした・・・\n");
          }
          else{
            fread(&save_data_players, sizeof(save_data_players), 1, fp);
            fread(&save_data_players2, sizeof(save_data_players2), 1, fp);
            fread(&save_data_players3, sizeof(save_data_players3), 1, fp);
            fread(&save_data_player_skill, sizeof(save_data_player_skill), 1, fp);
            fread(&save_data_player_skill2, sizeof(save_data_player_skill2), 1, fp);
            fread(&save_data_player_skill3, sizeof(save_data_player_skill3), 1, fp);
            fread(&save_data_items, sizeof(save_data_items), 1, fp);
            fread(&save_data_pEquip, sizeof(save_data_pEquip), 1, fp);
            fread(&save_data_p2Equip, sizeof(save_data_p2Equip), 1, fp);
            fread(&save_data_p3Equip, sizeof(save_data_p3Equip), 1, fp);
            fread(&Save_data_search, sizeof(Save_data_search), 1, fp);
            fread(&save_data_setting_skill, sizeof(save_data_setting_skill), 1, fp);
            fread(&save_data_setting_skill2, sizeof(save_data_setting_skill2), 1, fp);
            fread(&save_data_setting_skill3, sizeof(save_data_setting_skill3), 1, fp);
            fclose(fp);
            load_count++;
            saveFile = 1;
          }
        }
      }
      else if ( input == '2' ){
        //ファイル処理
        if ( ( fp = fopen( "SaveData/save2.dat", "rb" ) ) == NULL ){
          printf("セーブデータがありません\n");
        }
        else{
          //セーブデータの読み込み
          if ( getFileSize( "SaveData/save2.dat") == 0 ){
            printf("セーブデータを読み込めませんでした・・・\n");
          }
          else{
            fread(&save_data_players, sizeof(Save_data_players), 1, fp);
            fread(&save_data_players2, sizeof(save_data_players2), 1, fp);
            fread(&save_data_players3, sizeof(save_data_players3), 1, fp);
            fread(&save_data_player_skill, sizeof(save_data_player_skill), 1, fp);
            fread(&save_data_player_skill2, sizeof(save_data_player_skill2), 1, fp);
            fread(&save_data_player_skill3, sizeof(save_data_player_skill3), 1, fp);
            fread(&save_data_items, sizeof(save_data_items), 1, fp);
            fread(&save_data_pEquip, sizeof(save_data_pEquip), 1, fp);
            fread(&save_data_p2Equip, sizeof(save_data_p2Equip), 1, fp);
            fread(&save_data_p3Equip, sizeof(save_data_p3Equip), 1, fp);
            fread(&Save_data_search, sizeof(Save_data_search), 1, fp);
            fread(&save_data_setting_skill, sizeof(save_data_setting_skill), 1, fp);
            fread(&save_data_setting_skill2, sizeof(save_data_setting_skill2), 1, fp);
            fread(&save_data_setting_skill3, sizeof(save_data_setting_skill3), 1, fp);
            fclose(fp);
            load_count++;
            saveFile = 2;
          }
        }
      }
      else if ( input == '3' ){
        //ファイル処理
        if ( ( fp = fopen( "SaveData/save2.dat", "rb" ) ) == NULL ){
          printf("セーブデータがありません\n");
        }
        else{
          //セーブデータの読み込み
          if ( getFileSize( "SaveData/save3.dat") == 0 ){
            printf("セーブデータを読み込めませんでした・・・\n");
          }
          else{
            fread(&save_data_players, sizeof(Save_data_players), 1, fp);
            fread(&save_data_players2, sizeof(save_data_players2), 1, fp);
            fread(&save_data_players3, sizeof(save_data_players3), 1, fp);
            fread(&save_data_player_skill, sizeof(save_data_player_skill), 1, fp);
            fread(&save_data_player_skill2, sizeof(save_data_player_skill2), 1, fp);
            fread(&save_data_player_skill3, sizeof(save_data_player_skill3), 1, fp);
            fread(&save_data_items, sizeof(save_data_items), 1, fp);
            fread(&save_data_pEquip, sizeof(save_data_pEquip), 1, fp);
            fread(&save_data_p2Equip, sizeof(save_data_p2Equip), 1, fp);
            fread(&save_data_p3Equip, sizeof(save_data_p3Equip), 1, fp);
            fread(&Save_data_search, sizeof(Save_data_search), 1, fp);
            fread(&save_data_setting_skill, sizeof(save_data_setting_skill), 1, fp);
            fread(&save_data_setting_skill2, sizeof(save_data_setting_skill2), 1, fp);
            fread(&save_data_setting_skill3, sizeof(save_data_setting_skill3), 1, fp);
            fclose(fp);
            load_count++;
            saveFile = 3;
          }
        }
      }
      else if ( input == 'n' ){
        printf("セーブデータのロードを中止します・・・\n");
        //st -> stage_clear = 0;
        return;
      }
      else{
        load_count = 0;
      }
    }while ( load_count == 0 );

    printf("セーブデータをロードしています・・・・\n");
    sleep(2);
    printf("ロードが完了しました!\n");
    start_time = time(NULL);

    //主人公のセーブデータ
    strcpy(st -> name, save_data_players.name);
    st -> hp = save_data_players.hp;
    st -> maxhp = save_data_players.maxhp;
    st -> mp = save_data_players.mp;
    st -> maxmp = save_data_players.maxmp;
    st -> atk = save_data_players.atk;
    st -> magic = save_data_players.magic;
    st -> str = save_data_players.str;
    st -> agi = save_data_players.agi;
    st -> luk = save_data_players.luk;
    st -> lv = save_data_players.lv;
    st -> exp = save_data_players.exp;
    st -> sumexp = save_data_players.sumexp;
    st -> nextexp = save_data_players.nextexp;
    st -> leftoverexp = save_data_players.leftoverexp;
    st -> gold = save_data_players.gold;
    st -> badstatus = save_data_players.badstatus;
    st -> physical_attack = save_data_players.physical_attack;
    st -> gun_attack = save_data_players.gun_attack;
    st -> fire = save_data_players.fire;
    st -> ice = save_data_players.ice;
    st -> elec = save_data_players.elec;
    st -> wave = save_data_players.wave;
    st -> almighty = save_data_players.almighty;
    st -> death = save_data_players.death;
    st -> expel = save_data_players.expel;
    st -> poison = save_data_players.poison;
    st -> palyze = save_data_players.palyze;
    st -> charm = save_data_players.charm;
    st -> close = save_data_players.close;
    st -> stone = save_data_players.stone;
    st -> panic = save_data_players.panic;
    st -> sleep = save_data_players.sleep;
    st -> curse = save_data_players.curse;
    st -> stage_clear = save_data_players.stage_clear;
    st -> playtime = save_data_players.playtime;

    //２人目のセーブデータ
    strcpy(st2 -> name, save_data_players2.name);
    st2 -> hp = save_data_players2.hp;
    st2 -> maxhp = save_data_players2.maxhp;
    st2 -> mp = save_data_players2.mp;
    st2 -> maxmp = save_data_players2.maxmp;
    st2 -> atk = save_data_players2.atk;
    st2 -> magic = save_data_players2.magic;
    st2 -> str = save_data_players2.str;
    st2 -> agi = save_data_players2.agi;
    st2 -> luk = save_data_players2.luk;
    st2 -> lv = save_data_players2.lv;
    st2 -> exp = save_data_players2.exp;
    st2 -> sumexp = save_data_players2.sumexp;
    st2 -> nextexp = save_data_players2.nextexp;
    st2 -> leftoverexp = save_data_players2.leftoverexp;
    st2 -> gold = save_data_players2.gold;
    st2-> badstatus = save_data_players2.badstatus;
    st2 -> physical_attack = save_data_players2.physical_attack;
    st2 -> gun_attack = save_data_players2.gun_attack;
    st2 -> fire = save_data_players2.fire;
    st2 -> ice = save_data_players2.ice;
    st2 -> elec = save_data_players2.elec;
    st2 -> wave = save_data_players2.wave;
    st2 -> almighty = save_data_players2.almighty;
    st2 -> death = save_data_players2.death;
    st2 -> expel = save_data_players2.expel;
    st2 -> poison = save_data_players2.poison;
    st2 -> palyze = save_data_players2.palyze;
    st2 -> charm = save_data_players2.charm;
    st2 -> close = save_data_players2.close;
    st2 -> stone = save_data_players2.stone;
    st2 -> panic = save_data_players2.panic;
    st2 -> sleep = save_data_players2.sleep;
    st2 -> curse = save_data_players2.curse;
    st2 -> stage_clear = save_data_players2.stage_clear;

    //３人目のセーブデータ
    strcpy(st3 -> name, save_data_players3.name);
    st3 -> hp = save_data_players3.hp;
    st3 -> maxhp = save_data_players3.maxhp;
    st3 -> mp = save_data_players3.mp;
    st3 -> maxmp = save_data_players3.maxmp;
    st3 -> atk = save_data_players3.atk;
    st3 -> magic = save_data_players3.magic;
    st3 -> str = save_data_players3.str;
    st3 -> agi = save_data_players3.agi;
    st3 -> luk = save_data_players3.luk;
    st3 -> lv = save_data_players3.lv;
    st3 -> exp = save_data_players3.exp;
    st3 -> sumexp = save_data_players3.sumexp;
    st3 -> nextexp = save_data_players3.nextexp;
    st3 -> leftoverexp = save_data_players3.leftoverexp;
    st3 -> gold = save_data_players3.gold;
    st3 -> badstatus = save_data_players3.badstatus;
    st3 -> physical_attack = save_data_players3.physical_attack;
    st3 -> gun_attack = save_data_players3.gun_attack;
    st3 -> fire = save_data_players3.fire;
    st3 -> ice = save_data_players3.ice;
    st3 -> elec = save_data_players3.elec;
    st3 -> wave = save_data_players3.wave;
    st3 -> almighty = save_data_players3.almighty;
    st3 -> death = save_data_players3.death;
    st3 -> expel = save_data_players3.expel;
    st3 -> poison = save_data_players3.poison;
    st3 -> palyze = save_data_players3.palyze;
    st3 -> charm = save_data_players3.charm;
    st3 -> close = save_data_players3.close;
    st3 -> stone = save_data_players3.stone;
    st3 -> panic = save_data_players3.panic;
    st3 -> sleep = save_data_players3.sleep;
    st3 -> curse = save_data_players3.curse;
    st3 -> stage_clear = save_data_players3.stage_clear;

    load_items(&items,&save_data_items);

    load_equip(&pEquip,&save_data_pEquip);
    load_equip(&p2Equip,&save_data_p2Equip);
    load_equip(&p3Equip,&save_data_p3Equip);

    search -> search_item1 = Save_data_search.search_item1;
    //printf("medicine:%d個\n", save_data_items.medicine);

    load_playersSkill(&player_skill,&save_data_player_skill);
    load_playersSkill(&player_skill2,&save_data_player_skill2);
    load_playersSkill(&player_skill3,&save_data_player_skill3);

    for ( int i = 0; i < 10; i++ ){
      setting_skill -> set_skill[i] = save_data_setting_skill.set_skill[i];
    }

    for ( int i = 0; i < 10; i++ ){
      setting_skill2 -> set_skill[i] = save_data_setting_skill2.set_skill[i];
    }

    for ( int i = 0; i < 10; i++ ){
      setting_skill3 -> set_skill[i] = save_data_setting_skill3.set_skill[i];
    }

  }
  else{              //save
    sleep(2);
    if ( st -> stage_clear == 1 ){
      printf("現在の状態をセーブします...\n");
      input = '1';
    }
    else{
      printf("今の状態をSaveしますか?\n");
      printf("1:yes 2:no\n");
      printf("1か2を入力してください!\n");
      input = _getch();
    }
    if ( input == '1' ){

      end_time = time(NULL);
      //printf("start_time:%d\n", start_time);
      //printf("end_time:%d\n", end_time);
      play_time = difftime(end_time, start_time);  //endとstartの差分
      printf("play_time:%d\n", play_time);
      //play_time = difftime(end_time, start_time);

      //プレイヤーデータの代入(主人公)
      strcpy(save_data_players.name, st -> name);
      save_data_players.hp = st -> hp;
      save_data_players.maxhp = st -> maxhp;
      save_data_players.mp = st -> mp;
      save_data_players.maxmp = st -> maxmp;
      save_data_players.atk = st -> atk;
      save_data_players.magic = st -> magic;
      save_data_players.str = st -> str;
      save_data_players.agi = st -> agi;
      save_data_players.luk = st -> luk;
      save_data_players.lv = st -> lv;
      save_data_players.exp = st -> exp;
      save_data_players.sumexp = st -> sumexp;
      save_data_players.nextexp = st -> nextexp;
      save_data_players.leftoverexp = st -> leftoverexp;
      save_data_players.gold = st -> gold;
      save_data_players.badstatus = st -> badstatus;
      save_data_players.physical_attack = st -> physical_attack;
      save_data_players.gun_attack = st -> gun_attack;
      save_data_players.fire = st -> fire;
      save_data_players.ice = st -> ice;
      save_data_players.elec = st -> elec;
      save_data_players.wave = st -> wave;
      save_data_players.almighty = st -> almighty;
      save_data_players.death = st -> death;
      save_data_players.expel = st -> expel;
      save_data_players.poison = st -> poison;
      save_data_players.palyze = st -> palyze;
      save_data_players.charm = st -> charm;
      save_data_players.close = st -> close;
      save_data_players.stone = st -> stone;
      save_data_players.panic = st -> panic;
      save_data_players.sleep = st -> sleep;
      save_data_players.curse = st -> curse;
      save_data_players.stage_clear = st -> stage_clear;
      //printf("save_data_players.playtime:%d\n", save_data_players.playtime);
      if ( st -> stage_clear == 1 ){
        //printf("First Play\n");
        save_data_players.playtime = play_time;
      }
      else{
        //printf("Continue Play\n");
        save_data_players.playtime += play_time;
      }
      //save_data_players.playtime = play_time;
      //printf("save_data_players.playtime:%d\n", save_data_players.playtime);

      //２人目のセーブデータの書き込み
      strcpy(save_data_players2.name, st2 -> name);
      save_data_players2.hp = st2 -> hp;
      save_data_players2.maxhp = st2 -> maxhp;
      save_data_players2.mp = st2 -> mp;
      save_data_players2.maxmp = st2 -> maxmp;
      save_data_players2.atk = st2 -> atk;
      save_data_players2.magic = st2 -> magic;
      save_data_players2.str = st2 -> str;
      save_data_players2.agi = st2 -> agi;
      save_data_players2.luk = st2 -> luk;
      save_data_players2.lv = st2 -> lv;
      save_data_players2.exp = st2 -> exp;
      save_data_players2.sumexp = st2 -> sumexp;
      save_data_players2.nextexp = st2 -> nextexp;
      save_data_players2.leftoverexp = st2 -> leftoverexp;
      save_data_players2.gold = 0;
      save_data_players2.badstatus = st2 -> badstatus;
      save_data_players2.physical_attack = st2 -> physical_attack;
      save_data_players2.gun_attack = st2 -> gun_attack;
      save_data_players2.fire = st2 -> fire;
      save_data_players2.ice = st2 -> ice;
      save_data_players2.elec = st2 -> elec;
      save_data_players2.wave = st2 -> wave;
      save_data_players2.almighty = st2 -> almighty;
      save_data_players2.death = st2 -> death;
      save_data_players2.expel = st2 -> expel;
      save_data_players2.poison = st2 -> poison;
      save_data_players2.palyze = st2 -> palyze;
      save_data_players2.charm = st2 -> charm;
      save_data_players2.close = st2 -> close;
      save_data_players2.stone = st2 -> stone;
      save_data_players2.panic = st2 -> panic;
      save_data_players2.sleep = st2 -> sleep;
      save_data_players2.curse = st2 -> curse;
      save_data_players2.stage_clear = 0;
      save_data_players2.playtime = 0;

      //３人目のセーブデータの書き込み
      strcpy(save_data_players3.name, st3 -> name);
      save_data_players3.hp = st3 -> hp;
      save_data_players3.maxhp = st3 -> maxhp;
      save_data_players3.mp = st3 -> mp;
      save_data_players3.maxmp = st3 -> maxmp;
      save_data_players3.atk = st3 -> atk;
      save_data_players3.magic = st3 -> magic;
      save_data_players3.str = st3 -> str;
      save_data_players3.agi = st3 -> agi;
      save_data_players3.luk = st3 -> luk;
      save_data_players3.lv = st3 -> lv;
      save_data_players3.exp = st3 -> exp;
      save_data_players3.sumexp = st3 -> sumexp;
      save_data_players3.nextexp = st3 -> nextexp;
      save_data_players3.leftoverexp = st3 -> leftoverexp;
      save_data_players3.gold = 0;
      save_data_players3.badstatus = st3 -> badstatus;
      save_data_players3.physical_attack = st3 -> physical_attack;
      save_data_players3.gun_attack = st3 -> gun_attack;
      save_data_players3.fire = st3 -> fire;
      save_data_players3.ice = st3 -> ice;
      save_data_players3.elec = st3 -> elec;
      save_data_players3.wave = st3 -> wave;
      save_data_players3.almighty = st3 -> almighty;
      save_data_players3.death = st3 -> death;
      save_data_players3.expel = st3 -> expel;
      save_data_players3.poison = st3 -> poison;
      save_data_players3.palyze = st3 -> palyze;
      save_data_players3.charm = st3 -> charm;
      save_data_players3.close = st3 -> close;
      save_data_players3.stone = st3 -> stone;
      save_data_players3.panic = st3 -> panic;
      save_data_players3.sleep = st3 -> sleep;
      save_data_players3.curse = st3 -> curse;
      save_data_players3.stage_clear = 0;
      save_data_players3.playtime = 0;

      save_data_items.medicine = items -> medicine;
      save_data_items.lifestone = items -> lifestone;
      save_data_items.antipoison = items -> antipoison;
      save_data_items.bead = items -> bead;

      save_data_pEquip.HpRing1 = pEquip -> HpRing1;
      save_data_pEquip.MpRing1 = pEquip -> MpRing1;
      save_data_pEquip.isEquip = pEquip -> isEquip;

      //printf("%d\n", save_data_pEquip.HpRing1);

      save_data_p2Equip.HpRing1 = p2Equip -> HpRing1;
      save_data_p2Equip.MpRing1 = p2Equip -> MpRing1;
      save_data_p2Equip.isEquip = p2Equip -> isEquip;

      save_data_p3Equip.HpRing1 = p3Equip -> HpRing1;
      save_data_p3Equip.MpRing1 = p3Equip -> MpRing1;
      save_data_p3Equip.isEquip = p3Equip -> isEquip;

      Save_data_search.search_item1 = search -> search_item1;

      for ( int i = 0; i < 4; i++ ){
        save_data_player_skill.recover1[i] = player_skill -> recover1[i];
        save_data_player_skill2.recover1[i] = player_skill2 -> recover1[i];
        save_data_player_skill2.recover1[i] = player_skill3 -> recover1[i];
      }

      for ( int i = 0; i < 4; i++ ){
        save_data_player_skill.cure_poison[i] = player_skill -> cure_poison[i];
        save_data_player_skill2.cure_poison[i] = player_skill2 -> cure_poison[i];
        save_data_player_skill3.cure_poison[i] = player_skill3 -> cure_poison[i];
      }

      for ( int i = 0; i < 4; i++ ){
        save_data_player_skill.recover2[i] = player_skill -> recover2[i];
        save_data_player_skill2.recover2[i] = player_skill2 -> recover2[i];
        save_data_player_skill3.recover2[i] = player_skill3 -> recover2[i];
      }

      for ( int i = 0; i < 4; i++ ){
        save_data_player_skill.enfa[i] = player_skill -> enfa[i];
        save_data_player_skill2.enfa[i] = player_skill2 -> enfa[i];
        save_data_player_skill3.enfa[i] = player_skill3 -> enfa[i];
      }

      for ( int i = 0; i < 10; i++ ){
        save_data_setting_skill.set_skill[i] = setting_skill -> set_skill[i];
      }

      for ( int i = 0; i < 10; i++ ){
        save_data_setting_skill2.set_skill[i] = setting_skill2 -> set_skill[i];
      }

      for ( int i = 0; i < 10; i++ ){
        save_data_setting_skill3.set_skill[i] = setting_skill3 -> set_skill[i];
      }

      do{
        save_count = 0;
        printf("\n");
        printf("何番のセーブデータにセーブしますか？\n");
        printf("1:\n");
        printf("2:\n");
        printf("3:\n");
        printf("1~3の数字を入力してください!\n");
        printf("セーブを中止する場合はnを入力してください!\n");
        savedata_num = _getch();

        if ( savedata_num == '1' ){
          //ファイル処理
          if ( ( fp = fopen( "SaveData/save1.dat", "wb" ) ) == NULL ){
            printf("セーブデータがありません\n");
          }
          else{
            if ( st -> stage_clear == 1 ){
              //ファイルを削除し再生成
              remove("SaveData/save1.dat");
              fp = fopen( "SaveData/save1.dat", "wb+");
            }
            //セーブデータの書き込み
            fwrite(&save_data_players, sizeof(save_data_players), 1, fp);
            fwrite(&save_data_players2, sizeof(save_data_players2), 1, fp);
            fwrite(&save_data_players3, sizeof(save_data_players3), 1, fp);
            fwrite(&save_data_player_skill, sizeof(save_data_player_skill), 1, fp);
            fwrite(&save_data_player_skill2, sizeof(save_data_player_skill2), 1, fp);
            fwrite(&save_data_player_skill3, sizeof(save_data_player_skill3), 1, fp);
            fwrite(&save_data_items, sizeof(save_data_items), 1, fp);
            fwrite(&save_data_pEquip, sizeof(save_data_pEquip), 1, fp);
            fwrite(&save_data_p2Equip, sizeof(save_data_p2Equip), 1, fp);
            fwrite(&save_data_p3Equip, sizeof(save_data_p3Equip), 1, fp);
            fwrite(&Save_data_search, sizeof(Save_data_search), 1, fp);
            fwrite(&save_data_setting_skill, sizeof(save_data_setting_skill), 1, fp);
            fwrite(&save_data_setting_skill2, sizeof(save_data_setting_skill2), 1, fp);
            fwrite(&save_data_setting_skill3, sizeof(save_data_setting_skill3), 1, fp);

            fclose(fp);
            save_count++;
          }
        }
        else if ( savedata_num  == '2' ){
          //ファイル処理
          if ( ( fp = fopen( "SaveData/save2.dat", "wb" ) ) == NULL ){
            printf("セーブデータがありません\n");
          }
          else{
            if ( st -> stage_clear == 1 ){
              //ファイルを削除し再生成
              remove("SaveData/save2.dat");
              fp = fopen( "SaveData/save2.dat", "wb+");
            }
            //セーブデータの書き込み
            fwrite(&save_data_players, sizeof(Save_data_players), 1, fp);
            fwrite(&save_data_players2, sizeof(save_data_players2), 1, fp);
            fwrite(&save_data_players3, sizeof(save_data_players3), 1, fp);
            fwrite(&save_data_player_skill, sizeof(save_data_player_skill), 1, fp);
            fwrite(&save_data_player_skill2, sizeof(save_data_player_skill2), 1, fp);
            fwrite(&save_data_player_skill3, sizeof(save_data_player_skill3), 1, fp);
            fwrite(&save_data_items, sizeof(save_data_items), 1, fp);
            fwrite(&save_data_pEquip, sizeof(save_data_pEquip), 1, fp);
            fwrite(&save_data_p2Equip, sizeof(save_data_p2Equip), 1, fp);
            fwrite(&save_data_p3Equip, sizeof(save_data_p3Equip), 1, fp);
            fwrite(&Save_data_search, sizeof(Save_data_search), 1, fp);
            fwrite(&save_data_setting_skill, sizeof(save_data_setting_skill), 1, fp);
            fwrite(&save_data_setting_skill2, sizeof(save_data_setting_skill2), 1, fp);
            fwrite(&save_data_setting_skill3, sizeof(save_data_setting_skill3), 1, fp);
            fclose(fp);
            save_count++;
          }
        }
        else if ( savedata_num == '3' ){
          //ファイル処理
          if ( ( fp = fopen( "SaveData/save3.dat", "wb" ) ) == NULL ){
            printf("セーブデータがありません\n");
          }
          else{
            if ( st -> stage_clear == 1 ){
              //ファイルを削除し再生成
              remove("SaveData/save3.dat");
              fp = fopen( "SaveData/save3.dat", "wb+");
            }
            //セーブデータの書き込み
            fwrite(&save_data_players, sizeof(Save_data_players), 1, fp);
            fwrite(&save_data_players2, sizeof(save_data_players2), 1, fp);
            fwrite(&save_data_players3, sizeof(save_data_players3), 1, fp);
            fwrite(&save_data_player_skill, sizeof(save_data_player_skill), 1, fp);
            fwrite(&save_data_player_skill2, sizeof(save_data_player_skill2), 1, fp);
            fwrite(&save_data_player_skill3, sizeof(save_data_player_skill3), 1, fp);
            fwrite(&save_data_items, sizeof(save_data_items), 1, fp);
            fwrite(&save_data_pEquip, sizeof(save_data_pEquip), 1, fp);
            fwrite(&save_data_p2Equip, sizeof(save_data_p2Equip), 1, fp);
            fwrite(&save_data_p3Equip, sizeof(save_data_p3Equip), 1, fp);
            fwrite(&Save_data_search, sizeof(Save_data_search), 1, fp);
            fwrite(&save_data_setting_skill, sizeof(save_data_setting_skill), 1, fp);
            fwrite(&save_data_setting_skill2, sizeof(save_data_setting_skill2), 1, fp);
            fwrite(&save_data_setting_skill3, sizeof(save_data_setting_skill3), 1, fp);
            fclose(fp);
            save_count++;
          }
        }
        else if ( savedata_num == 'n' && st -> stage_clear != 1 ){
          printf("セーブを中止します・・・\n");
          return;
        }
        else{
          save_count = 0;
        }
      }while ( save_count == 0 );

      printf("Save中です・・・\n");
      sleep(2);
      printf("Saveが完了しました!\n");
      printf("\n");

      /*
    }
    printf("\n");
  }*/
  start_time = time(NULL);
}
}

}

void save_inSchool(Player **st, Player **st2, Player **st3, P_skill **player_skill, P_skill **player_skill2, P_skill **player_skill3, Setting_skill **setting_skill, Setting_skill **setting_skill2, Setting_skill **setting_skill3, Items **items, Equip **pEquip, Equip **p2Equip, Equip **p3Equip, SearchDangeon **search){

  int save_count, load_count, input, savedata_num, savedata_lv1, savedata_lv2, savedata_lv3, temp, hours, minutes;
  char savedata_name1[7], savedata_name2[7], savedata_name3[7];
  FILE *fp;
  const char *file;
  int n;

  Save_data_players save_data_players;
  Save_data_players save_data_players2;
  Save_data_players save_data_players3;

  Save_data_player_skill save_data_player_skill;
  Save_data_player_skill save_data_player_skill2;
  Save_data_player_skill save_data_player_skill3;

  Save_data_items save_data_items;

  Save_data_equip save_data_pEquip;
  Save_data_equip save_data_p2Equip;
  Save_data_equip save_data_p3Equip;

  Save_data_search Save_data_search;

  Save_data_setting_skill save_data_setting_skill;
  Save_data_setting_skill save_data_setting_skill2;
  Save_data_setting_skill save_data_setting_skill3;
  //save
  sleep(2);
  printf("今の状態をSaveしますか?\n");
  printf("1:yes 2:no\n");
  printf("1か2を入力してください!\n");
  input = _getch();
  if ( input == '1' ){

    end_time = time(NULL);
    //printf("start_time:%d\n", start_time);
    //printf("end_time:%d\n", end_time);
    play_time = difftime(end_time, start_time);  //endとstartの差分

    if ( ( fp = fopen( "SaveData/save1.dat", "rb" ) ) == NULL ){
      //can't open file. So create new file
      fp = fopen( "SaveData/save1.dat", "wb+");
      printf("1:NO DATA\n");
    }
    else{
      if ( getFileSize( "SaveData/save1.dat") == 0 ){                   //fileのbyteが０ならデータがない
        //printf("セーブデータを読み込めませんでした・・・\n");
        printf("1:NO DATA\n");
      }
      else{
        fread(&save_data_players, sizeof(Save_data_players), 1, fp);
        strcpy(savedata_name1, save_data_players.name);
        savedata_lv1 = save_data_players.lv;

        //printf("playtime:%d\n", save_data_players.playtime);
        temp = save_data_players.playtime;
        //temp -= 1000;
        if ( temp >= 3600 ){
          hours = temp / 3600;
          minutes = temp % 3600 / 60;
        }
        else{
          hours = 0;
          printf("seconds:%d\n", temp);
          minutes = 0;
          while ( temp >= 60 ){
            temp -= 60;
            minutes++;
          }
        }

        if ( minutes < 10 ){
          printf("1:%s LV%d プレイ時間 %d:0%d\n", savedata_name1, savedata_lv1, hours, minutes);
          fclose(fp);
        }
        else{
          printf("1:%s LV%d プレイ時間 %d:%d\n", savedata_name1, savedata_lv1, hours, minutes);
          fclose(fp);
        }

      }
    }

    if ( ( fp = fopen( "SaveData/save2.dat", "rb" ) ) == NULL ){
      //can't open file. So create new file
      fp = fopen( "SaveData/save2.dat", "wb+");
      printf("2:NO DATA\n");
    }
    else{
      if ( getFileSize( "SaveData/save2.dat") == 0 ){                   //fileのbyteが０ならデータがない
        //printf("セーブデータを読み込めませんでした・・・\n");
        printf("2:NO DATA\n");
      }
      else{
        fread(&save_data_players, sizeof(Save_data_players), 1, fp);
        strcpy(savedata_name2, save_data_players.name);
        savedata_lv2 = save_data_players.lv;

        temp = save_data_players.playtime;
        //temp -= 1000;
        if ( temp >= 3600 ){
          hours = temp / 3600;
          minutes = temp % 3600 / 60;
        }
        else{
          hours = 0;
          minutes = temp / 60 % 60;
        }

        if ( minutes < 10 ){
          printf("2:%s LV%d プレイ時間 %d:0%d\n", savedata_name1, savedata_lv1, hours, minutes);
          fclose(fp);
        }
        else{
          printf("2:%s LV%d プレイ時間 %d:%d\n", savedata_name1, savedata_lv1, hours, minutes);
          fclose(fp);
        }

      }
    }

    if ( ( fp = fopen( "SaveData/save3.dat", "rb" ) ) == NULL ){
      //can't open file. So create new file
      fp = fopen( "SaveData/save3.dat", "wb+");
      printf("3:NO DATA\n");
    }
    else{
      if ( getFileSize( "SaveData/save3.dat") == 0 ){                   //fileのbyteが０ならデータがない
        //printf("セーブデータを読み込めませんでした・・・\n");
        printf("3:NO DATA\n");
      }
      else{
        fread(&save_data_players, sizeof(Save_data_players), 1, fp);
        strcpy(savedata_name3, save_data_players.name);
        savedata_lv3 = save_data_players.lv;
        temp = save_data_players.playtime;
        //temp -= 1000;
        if ( temp >= 3600 ){
          hours = temp / 3600;
          minutes = temp % 3600 / 60;
        }
        else{
          hours = 0;
          minutes = temp / 60 % 60;
        }

        if ( minutes < 10 ){
          printf("3:%s LV%d プレイ時間 %d:0%d\n", savedata_name1, savedata_lv1, hours, minutes);
          fclose(fp);
        }
        else{
          printf("3:%s LV%d プレイ時間 %d:%d\n", savedata_name1, savedata_lv1, hours, minutes);
          fclose(fp);
        }

      }
    }

    end_time = time(NULL);
    //printf("start_time:%d\n", start_time);
    //printf("end_time:%d\n", end_time);
    play_time = difftime(end_time, start_time);  //endとstartの差分
    //printf("play_time:%d\n", play_time);
    //play_time = difftime(end_time, start_time);

    //プレイヤーデータの代入(主人公)
    strcpy(save_data_players.name, (*st) -> name);
    save_data_players.hp = (*st) -> hp;
    save_data_players.maxhp = (*st) -> maxhp;
    save_data_players.mp = (*st) -> mp;
    save_data_players.maxmp = (*st) -> maxmp;
    save_data_players.atk = (*st) -> atk;
    save_data_players.magic = (*st) -> magic;
    save_data_players.str = (*st) -> str;
    save_data_players.agi = (*st) -> agi;
    save_data_players.luk = (*st) -> luk;
    save_data_players.lv = (*st) -> lv;
    save_data_players.exp = (*st) -> exp;
    save_data_players.sumexp = (*st) -> sumexp;
    save_data_players.nextexp = (*st) -> nextexp;
    save_data_players.leftoverexp = (*st) -> leftoverexp;
    save_data_players.gold = (*st) -> gold;
    save_data_players.badstatus = (*st) -> badstatus;
    save_data_players.physical_attack = (*st) -> physical_attack;
    save_data_players.gun_attack = (*st) -> gun_attack;
    save_data_players.fire = (*st) -> fire;
    save_data_players.ice = (*st) -> ice;
    save_data_players.elec = (*st) -> elec;
    save_data_players.wave = (*st) -> wave;
    save_data_players.almighty = (*st) -> almighty;
    save_data_players.death = (*st) -> death;
    save_data_players.expel = (*st) -> expel;
    save_data_players.poison = (*st) -> poison;
    save_data_players.palyze = (*st) -> palyze;
    save_data_players.charm = (*st) -> charm;
    save_data_players.close = (*st) -> close;
    save_data_players.stone = (*st) -> stone;
    save_data_players.panic = (*st) -> panic;
    save_data_players.sleep = (*st) -> sleep;
    save_data_players.curse = (*st) -> curse;
    save_data_players.stage_clear = (*st) -> stage_clear;

    if ( save_data_players.playtime == 0 ){
      //printf("First Play\n");
      save_data_players.playtime = play_time;
    }
    else{
      //printf("Continue Play\n");
      save_data_players.playtime += play_time;
    }
    //save_data_players.playtime = play_time;

    //２人目のセーブデータの書き込み
    strcpy(save_data_players2.name, (*st2) -> name);
    save_data_players2.hp = (*st2) -> hp;
    save_data_players2.maxhp = (*st2) -> maxhp;
    save_data_players2.mp = (*st2) -> mp;
    save_data_players2.maxmp = (*st2) -> maxmp;
    save_data_players2.atk = (*st2) -> atk;
    save_data_players2.magic = (*st2) -> magic;
    save_data_players2.str = (*st2) -> str;
    save_data_players2.agi = (*st2) -> agi;
    save_data_players2.luk = (*st2) -> luk;
    save_data_players2.lv = (*st2) -> lv;
    save_data_players2.exp = (*st2) -> exp;
    save_data_players2.sumexp = (*st2) -> sumexp;
    save_data_players2.nextexp = (*st2) -> nextexp;
    save_data_players2.leftoverexp = (*st2) -> leftoverexp;
    save_data_players2.gold = 0;
    save_data_players2.badstatus = (*st2) -> badstatus;
    save_data_players2.physical_attack = (*st2) -> physical_attack;
    save_data_players2.gun_attack = (*st2) -> gun_attack;
    save_data_players2.fire = (*st2) -> fire;
    save_data_players2.ice = (*st2) -> ice;
    save_data_players2.elec = (*st2) -> elec;
    save_data_players2.wave = (*st2) -> wave;
    save_data_players2.almighty = (*st2) -> almighty;
    save_data_players2.death = (*st2) -> death;
    save_data_players2.expel = (*st2) -> expel;
    save_data_players2.poison = (*st2) -> poison;
    save_data_players2.palyze = (*st2) -> palyze;
    save_data_players2.charm = (*st2) -> charm;
    save_data_players2.close = (*st2) -> close;
    save_data_players2.stone = (*st2) -> stone;
    save_data_players2.panic = (*st2) -> panic;
    save_data_players2.sleep = (*st2) -> sleep;
    save_data_players2.curse = (*st2) -> curse;
    save_data_players2.stage_clear = 0;
    save_data_players2.playtime = 0;

    //３人目のセーブデータの書き込み
    strcpy(save_data_players3.name, (*st3) -> name);
    save_data_players3.hp = (*st3) -> hp;
    save_data_players3.maxhp = (*st3) -> maxhp;
    save_data_players3.mp = (*st3) -> mp;
    save_data_players3.maxmp = (*st3) -> maxmp;
    save_data_players3.atk = (*st3) -> atk;
    save_data_players3.magic = (*st3) -> magic;
    save_data_players3.str = (*st3) -> str;
    save_data_players3.agi = (*st3) -> agi;
    save_data_players3.luk = (*st3) -> luk;
    save_data_players3.lv = (*st3) -> lv;
    save_data_players3.exp = (*st3) -> exp;
    save_data_players3.sumexp = (*st3) -> sumexp;
    save_data_players3.nextexp = (*st3) -> nextexp;
    save_data_players3.leftoverexp = (*st3) -> leftoverexp;
    save_data_players3.gold = 0;
    save_data_players3.badstatus = (*st3) -> badstatus;
    save_data_players3.physical_attack = (*st3) -> physical_attack;
    save_data_players3.gun_attack = (*st3) -> gun_attack;
    save_data_players3.fire = (*st3) -> fire;
    save_data_players3.ice = (*st3) -> ice;
    save_data_players3.elec = (*st3) -> elec;
    save_data_players3.wave = (*st3) -> wave;
    save_data_players3.almighty = (*st3) -> almighty;
    save_data_players3.death = (*st3) -> death;
    save_data_players3.expel = (*st3) -> expel;
    save_data_players3.poison = (*st3) -> poison;
    save_data_players3.palyze = (*st3) -> palyze;
    save_data_players3.charm = (*st3) -> charm;
    save_data_players3.close = (*st3) -> close;
    save_data_players3.stone = (*st3) -> stone;
    save_data_players3.panic = (*st3) -> panic;
    save_data_players3.sleep = (*st3) -> sleep;
    save_data_players3.curse = (*st3) -> curse;
    save_data_players3.stage_clear = 0;
    save_data_players3.playtime = 0;

    save_data_items.medicine = (*items) -> medicine;
    save_data_items.lifestone = (*items) -> lifestone;
    save_data_items.antipoison = (*items) -> antipoison;
    save_data_items.bead = (*items) -> bead;

    save_data_pEquip.HpRing1 = (*pEquip) -> HpRing1;
    save_data_pEquip.MpRing1 = (*pEquip) -> MpRing1;
    save_data_pEquip.isEquip = (*pEquip) -> isEquip;

    save_data_p2Equip.HpRing1 = (*p2Equip) -> HpRing1;
    save_data_p2Equip.MpRing1 = (*p2Equip) -> MpRing1;
    save_data_p2Equip.isEquip = (*p2Equip) -> isEquip;

    save_data_p3Equip.HpRing1 = (*p3Equip) -> HpRing1;
    save_data_p3Equip.MpRing1 = (*p3Equip) -> MpRing1;
    save_data_p3Equip.isEquip = (*p3Equip) -> isEquip;

    Save_data_search.search_item1 = (*search) -> search_item1;

    for ( int i = 0; i < 4; i++ ){
      save_data_player_skill.recover1[i] = (*player_skill) -> recover1[i] ;
      save_data_player_skill2.recover1[i] = (*player_skill2) -> recover1[i];
      save_data_player_skill2.recover1[i] = (*player_skill3) -> recover1[i];
    }

    for ( int i = 0; i < 4; i++ ){
      save_data_player_skill.cure_poison[i] = (*player_skill) -> cure_poison[i];
      save_data_player_skill2.cure_poison[i] = (*player_skill2) -> cure_poison[i];
      save_data_player_skill3.cure_poison[i] = (*player_skill3) -> cure_poison[i];
    }

    for ( int i = 0; i < 4; i++ ){
      save_data_player_skill.recover2[i] = (*player_skill) -> recover2[i];
      save_data_player_skill2.recover2[i] = (*player_skill2) -> recover2[i];
      save_data_player_skill3.recover2[i] = (*player_skill3) -> recover2[i];
    }

    for ( int i = 0; i < 4; i++ ){
      save_data_player_skill.enfa[i] = (*player_skill) -> enfa[i];
      save_data_player_skill2.enfa[i] = (*player_skill2) -> enfa[i];
      save_data_player_skill3.enfa[i] = (*player_skill3) -> enfa[i];
    }

    for ( int i = 0; i < 10; i++ ){
      save_data_setting_skill.set_skill[i] = (*setting_skill) -> set_skill[i];
    }

    for ( int i = 0; i < 10; i++ ){
      save_data_setting_skill2.set_skill[i] = (*setting_skill2) -> set_skill[i];
    }

    for ( int i = 0; i < 10; i++ ){
      save_data_setting_skill3.set_skill[i] = (*setting_skill3) -> set_skill[i];
    }

    //printf("%d\n", save_data_pEquip.HpRing1);
    //printf("%d\n", save_data_p2Equip.MpRing1);

    //printf("medicine:%d個\n", save_data_items.medicine);

    do{
      save_count = 0;
      printf("\n");
      printf("何番のセーブデータにセーブしますか？\n");
      /*printf("1:\n");
      printf("2:\n");
      printf("3:\n");*/
      printf("1~3の数字を入力してください!\n");
      printf("セーブを中止する場合はnを入力してください!\n");
      savedata_num = _getch();

      if ( savedata_num == '1' ){
        //ファイル処理
        if ( ( fp = fopen( "SaveData/save1.dat", "wb" ) ) == NULL ){
          printf("セーブデータがありません\n");
        }
        else{
          //セーブデータの書き込み
          fwrite(&save_data_players, sizeof(Save_data_players), 1, fp);
          fwrite(&save_data_players2, sizeof(save_data_players2), 1, fp);
          fwrite(&save_data_players3, sizeof(save_data_players3), 1, fp);
          fwrite(&save_data_player_skill, sizeof(save_data_player_skill), 1, fp);
          fwrite(&save_data_player_skill2, sizeof(save_data_player_skill2), 1, fp);
          fwrite(&save_data_player_skill3, sizeof(save_data_player_skill3), 1, fp);
          fwrite(&save_data_items, sizeof(save_data_items), 1, fp);
          fwrite(&save_data_pEquip, sizeof(save_data_pEquip), 1, fp);
          fwrite(&save_data_p2Equip, sizeof(save_data_p2Equip), 1, fp);
          fwrite(&save_data_p3Equip, sizeof(save_data_p3Equip), 1, fp);
          fwrite(&Save_data_search, sizeof(Save_data_search), 1, fp);
          fwrite(&save_data_setting_skill, sizeof(save_data_setting_skill), 1, fp);
          fwrite(&save_data_setting_skill2, sizeof(save_data_setting_skill2), 1, fp);
          fwrite(&save_data_setting_skill3, sizeof(save_data_setting_skill3), 1, fp);
          fclose(fp);
          save_count++;
        }
      }
      else if ( savedata_num  == '2' ){
        //ファイル処理
        if ( ( fp = fopen( "SaveData/save2.dat", "wb" ) ) == NULL ){
          printf("セーブデータがありません\n");
        }
        else{
          //セーブデータの書き込み
          fwrite(&save_data_players, sizeof(Save_data_players), 1, fp);
          fwrite(&save_data_players2, sizeof(save_data_players2), 1, fp);
          fwrite(&save_data_players3, sizeof(save_data_players3), 1, fp);
          fwrite(&save_data_player_skill, sizeof(save_data_player_skill), 1, fp);
          fwrite(&save_data_player_skill2, sizeof(save_data_player_skill2), 1, fp);
          fwrite(&save_data_player_skill3, sizeof(save_data_player_skill3), 1, fp);
          fwrite(&save_data_items, sizeof(save_data_items), 1, fp);
          fwrite(&save_data_pEquip, sizeof(save_data_pEquip), 1, fp);
          fwrite(&save_data_p2Equip, sizeof(save_data_p2Equip), 1, fp);
          fwrite(&save_data_p3Equip, sizeof(save_data_p3Equip), 1, fp);
          fwrite(&Save_data_search, sizeof(Save_data_search), 1, fp);
          fwrite(&save_data_setting_skill, sizeof(save_data_setting_skill), 1, fp);
          fwrite(&save_data_setting_skill2, sizeof(save_data_setting_skill2), 1, fp);
          fwrite(&save_data_setting_skill3, sizeof(save_data_setting_skill3), 1, fp);
          fclose(fp);
          save_count++;
        }
      }
      else if ( savedata_num == '3' ){
        //ファイル処理
        if ( ( fp = fopen( "SaveData/save3.dat", "wb" ) ) == NULL ){
          printf("セーブデータがありません\n");
        }
        else{
          //セーブデータの書き込み
          fwrite(&save_data_players, sizeof(Save_data_players), 1, fp);
          fwrite(&save_data_players2, sizeof(save_data_players2), 1, fp);
          fwrite(&save_data_players3, sizeof(save_data_players3), 1, fp);
          fwrite(&save_data_player_skill, sizeof(save_data_player_skill), 1, fp);
          fwrite(&save_data_player_skill2, sizeof(save_data_player_skill2), 1, fp);
          fwrite(&save_data_player_skill3, sizeof(save_data_player_skill3), 1, fp);
          fwrite(&save_data_items, sizeof(save_data_items), 1, fp);
          fwrite(&save_data_pEquip, sizeof(save_data_pEquip), 1, fp);
          fwrite(&save_data_p2Equip, sizeof(save_data_p2Equip), 1, fp);
          fwrite(&save_data_p3Equip, sizeof(save_data_p3Equip), 1, fp);
          fwrite(&Save_data_search, sizeof(Save_data_search), 1, fp);
          fwrite(&save_data_setting_skill, sizeof(save_data_setting_skill), 1, fp);
          fwrite(&save_data_setting_skill2, sizeof(save_data_setting_skill2), 1, fp);
          fwrite(&save_data_setting_skill3, sizeof(save_data_setting_skill3), 1, fp);
          fclose(fp);
          save_count++;
        }
      }
      else if ( savedata_num == 'n' ){
        printf("セーブを中止します・・・\n");
        return;
      }
      else{
        save_count = 0;
      }
    }while ( save_count == 0 );

    printf("Save中です・・・\n");
    sleep(2);
    printf("Saveが完了しました!\n");
    printf("\n");

    /*
  }
  printf("\n");
}*/
start_time = time(NULL);
}

}
