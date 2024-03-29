#ifndef RPG_H
#define RPG_H

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

//マクロ定義
#define NAME_LEN 50
#define ENEMY_NAME 100
#define COMMAND 3
//#define POINT 2
#define S_COMMAND 3

#define GOOD 0
#define DEAD 1
#define POISON 2
#define PALYZE 3
#define CHARM 4
#define CLOSE 5
#define STONE 6
#define PANIC 7
#define SLEEP 8
#define CURSE 9

#define SIZE 3

//型定義

//列挙型
typedef enum {
  TRUE = 1,
  FALSE = 0,
} Checkbool;

typedef enum {
  ON = 1,
  OFF = 0,
} Flag;

typedef enum {
  NOT_LEARNING = 0,
  SETTING = 1,
  LEARNED = 2,
  LEARNING = 3,
} Skillstate;

typedef enum {
  LOADGAME = 1,
  NEWGAME = 0,
} Gamemode;

typedef enum {
  BATTLEONLY = 0,
  MENUONLY = 1,
  MENUANDBATTLE = 2,
} Skilltype1;

typedef enum {
  PLAYER = 1,
  PLAYER2 = 2,
  PLAYER3 = 3,
  NOTARGET = 0,
  PARTY = 4,
  ENEMY = 5,
  PARTYALL = 6,
  ENEMYALL = 7,
  ENEMY1 = 8,  //左端の敵
  ENEMY2 = 9, //左から２番目
  ENEMY3 = 10, //左から3番目
  ENEMY4 = 11, //右端の敵
} PlayerAndEnemy;

typedef enum {
  RECOVERTARGET = 1,  //enemy
  RECOVERTARGET1 = 2, //enemy1
  RECOVERTARGET2 = 3, //enemy2
  RECOVERTARGET3 = 4, //enemy3
  RECOVERSKILLTRUE = 100,
  RECOVERSKILLFALSE = -1,
} EnemyRecoverTarget;

typedef enum {
  DEFAULT = 0,
  PLUS1 = 1,
  PLUS2 = 2,
  PLUS3 = 3,
  PLUS4 = 4,
  MINUS1 = -1,
  MINUS2 = -2,
  MINUS3 = -3,
  MINUS4 = -4,
} SupportSkillSituation;

typedef enum {
  WEAKNESS = 200,
  NORMAL150 = 150,
  NORMAL = 100,
  REGIST80 = 80,
  REGIST50 = 50,
  REGIST25 = 25,
  BLOCK = -1,
  ABSORB = -2,
  REFLECT = -3,
} DamageEffective;

typedef enum {
  TURNCHAGE = -100,
} PressTurnChange;

typedef enum {
  RECOVER1 = 1,
  CUREPOISON = 2,
  RECOVER2 = 3,
  ENFA = 4,
  HYODO = 5,
  VOLUA = 6,
  WHIVE = 7,
  RUSH = 8,
  ANALYZE = 9,
} Player_skillId;

typedef enum {
  E_QUAKE = 1,
  E_ENFA = 2,
  E_HYODO = 3,
  E_VOLUA = 4,
  E_WHIVE = 5,
} Enemy_skillId;

typedef enum {
  NOEQUIP = 0,
  HPRING1 = 1,
  MPRING1 = 2,
  HPRING2 = 3,
  MPRING2 = 4,
  POWEREARRINGS = 5,
  MAGICEARRINGS = 6,
  STRENGTHEARRINGS = 7,
  AGILITYEARRINGS = 8,
  LUCKYEARRINGS = 9,
  ONMORAKIEYE = 10,
} Equip_list;

typedef enum {
  MEDICINE = 1,
  LIFESTONE = 2,
  BEAD = 3,
  ANTIPOISON = 4,
  ANTIPALYZE = 5,
  ANTICHARM = 6,
  ANTICLOSE = 7,
  ANTISTONE = 8,
  ANTIPANIC = 9,
  ANTISLEEP = 10,
  ANTICURSE = 11,
  MINDAMIN = 12,
} ItemId;

typedef enum {
  SLIME = 1,
  KOBALT = 2,
  GOBLIN = 3,
  ZOMBIEDOG = 4,
  GHOUL = 5,
  ZOMBIE = 6,
  GOBLINNORMAL = 7,
  ONMORAKI = 8,
  GREMLIN = 9,
  PIXIE = 10,
} EnemyId;


typedef struct enemy {
  char name[ENEMY_NAME];
  int hp;
  int maxhp;
  int mp;
  int maxmp;
  int atk;
  int magic;
  int str;
  int agi;
  int luk;
  int lv;
  int exp;
  int gold;
  int badstatus;
  int physical_attack; //物理攻撃
  int gun_attack; //銃攻撃
  int fire;       //火炎攻撃
  int ice;        //氷結攻撃
  int elec;       //電撃攻撃
  int wave;       //衝撃攻撃
  int almighty;   //万能攻撃
  int death;      //呪殺攻撃
  int expel;      //破魔攻撃
  int poison;     //毒耐性
  int palyze;     //麻痺耐性
  int charm;      //魅了耐性
  int close;      //魔封耐性
  int stone;      //石化耐性
  int panic;      //混乱耐性
  int sleep;      //睡眠耐性
  int curse;      //呪い耐性
  int boss_count;
  int enemy_id;  //敵識別ID
} Enemy;

/*playerのスキル  skill[0] : SETTING or NOT_LEARNING or LEARNED or LEARNING
skill[1] : MENUONLY or BATTLEONLY or MENUANDBATTLE
skill[2] : このスキルに関して獲得した熟練度
skill[3] : 獲得に必要な熟練度*/
typedef struct player_skill {
  int recover1[4]; //ケディア
  int cure_poison[4]; //毒治療
  int recover2[4]; //ケディアス
  int enfa[4]; //エンファ
  int hyodo[4]; //ヒョウド
  int volua[4]; //ボルア
  int whive[4]; //ウィーブ
  int rush[4];  //突撃
  int analyze[4]; //アナライズ
} P_skill;

typedef struct save_data_player_skill {
  int recover1[4]; //ケディア
  int cure_poison[4]; //毒治療
  int recover2[4]; //ケディアス
  int enfa[4]; //エンファ
  int hyodo[4]; //ヒョウド
  int volua[4]; //ボルア
  int whive[4]; //ウィーブ
  int rush[4];  //突撃
  int analyze[4]; //アナライズ
} Save_data_player_skill;

typedef struct setting_skill {  //setting済みのスキル
  int set_skill[10];  //10種類のスキルをセット可能
} Setting_skill;

typedef struct player {
  char name[NAME_LEN];
  int hp;
  int maxhp;
  int mp;
  int maxmp;
  int atk;
  int magic;
  int str;
  int agi;
  int luk;
  int lv;
  int exp;
  int sumexp;
  int nextexp;
  int leftoverexp;
  int gold;
  int badstatus;
  int physical_attack; //物理攻撃
  int gun_attack; //銃攻撃
  int fire;       //火炎攻撃
  int ice;        //氷結攻撃
  int elec;       //電撃攻撃
  int wave;       //衝撃攻撃
  int almighty;   //万能攻撃
  int death;      //呪殺攻撃
  int expel;      //破魔攻撃
  int poison;     //毒耐性
  int palyze;     //麻痺耐性
  int charm;      //魅了耐性
  int close;      //魔封耐性
  int stone;      //石化耐性
  int panic;      //混乱耐性
  int sleep;      //睡眠耐性
  int curse;      //呪い耐性
  double stage_clear;
  int playtime;
  int recover1;
  int cure_poison;
} Player;

typedef struct map {
  int x;   //x座標
  int y;   //y座標
  int walk_step;  //歩数
} Map;

typedef struct area {
  double dangeonId;  //ダンジョン識別ID
  int event1a;
  int event1b;
  int event1c;
  int event1d;
  int boss1;
  int event2a;
  int boss2;
  int boss3;
  int encount; //敵とエンカウントするか否か 0ならばエンカウントしない 1ならばエンカウント
} Area;

typedef struct searchDangeon{
  int search_item1;
  int search_item2;
} SearchDangeon;

//パーティのセーブデータ
typedef struct save_data_players{
  char name[NAME_LEN];
  int hp;
  int maxhp;
  int mp;
  int maxmp;
  int atk;
  int magic;
  int str;
  int agi;
  int luk;
  int lv;
  int exp;
  int sumexp;
  int nextexp;
  int leftoverexp;
  int gold;
  int badstatus;
  int physical_attack; //物理攻撃
  int gun_attack; //銃攻撃
  int fire;       //火炎攻撃
  int ice;        //氷結攻撃
  int elec;       //電撃攻撃
  int wave;       //衝撃攻撃
  int almighty;   //万能攻撃
  int death;      //呪殺攻撃
  int expel;      //破魔攻撃
  int poison;     //毒耐性
  int palyze;     //麻痺耐性
  int charm;      //魅了耐性
  int close;      //魔封耐性
  int stone;      //石化耐性
  int panic;      //混乱耐性
  int sleep;      //睡眠耐性
  int curse;      //呪い耐性
  double stage_clear;
  int playtime;
} Save_data_players;

typedef struct items {
  int medicine;      //傷薬
  int lifestone;     //魔石
  int antipoison;    //アンタイポイズン
  int bead;          //宝玉
  int antipalyze;    //アンタイパライズ
  int anticharm;
  int anticlose;
  int antistone;
  int antipanic;
  int antisleep;
  int anticurse;
  int mindamin;
  int onmorakiPiece;  //オンモラキのレアドロップ
  int isGetRareDrop;  //レアドロップを入手したかどうか
  int isEverVisitDissectingRoom; //解剖室へ初めて行ったか
} Items;

typedef struct equip {
  int HpRing1;  //味方1人の最大HPを5%増加 No:1
  int MpRing1;  //味方1人の最大MPを5%増加 No:2
  int HpRing2;  //味方1人の最大HPを10%増加 No.3
  int MpRing2;  //味方1人の最大MPを10%増加 No.4
  int PowerEarrings;  //味方1人の力を1増加 No.5
  int MagicEarrings;  //味方1人の魔を1増加 No.6
  int StrengthEarrings;  //味方1人の体を1増加 No.7
  int AgilityEarrings;  //味方1人の速を1増加 No.8
  int LuckyEarrings;  //味方1人の運を1増加 No.9
  int OnmorakiEye;  //味方1人の火炎魔法の威力を1.2倍、魔を1増加 No.10
  int isEquip;  //味方が何か装備しているか(0:装備していない),している場合はその番号を代入
} Equip;

typedef struct save_data_items {
  int medicine;
  int lifestone;
  int antipoison;
  int bead;
  int antipalyze;
  int anticharm;
  int anticlose;
  int antistone;
  int antipanic;
  int antisleep;
  int anticurse;
  int mindamin;
  int onmorakiPiece;  //オンモラキのレアドロップ
  int isGetRareDrop;  //レアドロップを入手したかどうか
  int isEverVisitDissectingRoom; //解剖室へ初めて行ったか
} Save_data_items;

typedef struct save_data_equip {
  int HpRing1;  //味方1人の最大HPを5%増加 No:1
  int MpRing1;  //味方1人の最大MPを5%増加 No:2
  int HpRing2;  //味方1人の最大HPを10%増加 No.3
  int MpRing2;  //味方1人の最大MPを10%増加 No.4
  int PowerEarrings;  //味方1人の力を1増加 No.5
  int MagicEarrings;  //味方1人の魔を1増加 No.6
  int StrengthEarrings;  //味方1人の体を1増加 No.7
  int AgilityEarrings;  //味方1人の速を1増加 No.8
  int LuckyEarrings;  //味方1人の運を1増加 No.9
  int OnmorakiEye;  //味方1人の火炎魔法の威力を1.2倍、魔を1増加 No.10
  int isEquip;  //味方が何か装備しているか(0:装備していない),している場合はその番号を代入
} Save_data_equip;

typedef struct Save_data_search{
  int search_item1;
  int search_item2;
} Save_data_search;

typedef struct save_data_setting_skill {
  int set_skill[10];
} Save_data_setting_skill;

//rpg_save_load.c
void check_AutoMapFile();

void load_items(Items **items, Save_data_items *save_data_items); //セーブデータからアイテム情報を読み込み

void load_equip(Equip **equip, Save_data_equip *save_data_equip);

void load_playersSkill(P_skill **player_skill, Save_data_player_skill *save_data_players);

void save_load(Player *st, Player *st2, Player *st3, P_skill *player_skill, P_skill *player_skill2, P_skill *player_skill3, Setting_skill *setting_skill, Setting_skill *setting_skill2, Setting_skill *setting_skill3, Items *items, Equip *pEquip, Equip *p2Equip, Equip *p3Equip, SearchDangeon *search, int load);

void save_inSchool(Player **st, Player **st2, Player **st3, P_skill **player_skill, P_skill **player_skill2, P_skill **player_skill3, Setting_skill **setting_skill, Setting_skill **setting_skill2, Setting_skill **setting_skill3, Items **items, Equip **pEquip, Equip **p2Equip, Equip **p3Equip, SearchDangeon **search);

long long int getFileSize(const char *fileName);

void copy_saveData();

void delete_saveData();

void delete_AUtoMapFile(int input);

void display_condition(Player ***st);

void Debug_Mode(Player *st, Player *st2, Player *st3);

void display_status(Player **st, Player **st2, Player **st3);

void display_playerStatusPoint(int point);  //status画面に各能力を視覚的に表示

int school_command(Items **items);

int calculate_RecoverSkill_price(int input, int money);

void check_PhysicalSkill_state(P_skill *****player_skill);

void check_FireSkill_state(P_skill *****player_skill, int num);

void check_RecoverSkill_state(P_skill *****player_skill, int num);

int procedure_getFireSkill(int input, P_skill *****player_skill, int money);

int procedure_getRecoverSkill(int input, P_skill *****player_skill, int money);

void getSkill_Physical(Player ****st, P_skill ****player_skill, int money);

int getSkill_Fire(Player ****st, P_skill ****player_skill, int money);

int getSkill_Recover(Player ****st, P_skill ****player_skill, int money);

int getSkillAll(Player ***st, P_skill ***player_skill, int money);

void goTo_infirmary(Player **st, Player **st2, Player **st3, Items **items);

void goTo_artRoom(Player **st, Player **st2, Player **st3, Equip **pEquip, Equip **p2Equip, Equip **p3Equip);

void goTo_labo(Player **st, Player **st2, Player **st3, P_skill **player_skill, P_skill **player_skill2, P_skill **player_skill3);

int check_number_of_item_possession(Items *****items, int goods_number, int count);

void buy_goods(Player ****st, Items ****items, int goods_number, int price);

void goods_shop(Player ***st, Items ***items);

int check_number_of_equip_possession(Equip *****pEquip, Equip *****p2Equip, Equip *****p3Equip, int equip_number, int count);

void buy_equips(Player ****st, Equip ****pEquip, Equip ****p2Equip, Equip ****p3Equip, int equip_number, int price);

void equip_shop(Player ***st, Player ***st2, Player ***st3, Equip ***pEquip, Equip ***p2Equip, Equip ***p3Equip);

void sell_equip(Player ***st, Equip ***pEquip, Equip ***p2Equip, Equip ***p3Equip);

int synthesize_rareItems(Player ****st, Items ****items, Equip ****pEquip, Equip ****p2Equip, Equip ****p3Equip, int price, int item_number);

void provide_element(Player ***st, Items ***items, Equip ***pEquip, Equip ***p2Equip, Equip ***p3Equip);

void goTo_DissectingRoom(Player **st, Items **items, Equip **pEquip, Equip **p2Equip, Equip **p3Equip);

void prologue(void);

int check_player_name(Player **st);

void game_start(Player *player, Player *player2, Player *player3);

//rpg.c -> rpg_story.c
void game_story1(Player *st, Player *st2, Player *st3, P_skill *player_skill, P_skill *player_skill2, P_skill *player_skill3, Setting_skill *setting_skill, Setting_skill *setting_skill2, Setting_skill *setting_skill3, Items *items, Equip *pEquip, Equip *p2Equip, Equip *p3Equip, SearchDangeon *search, Area *area);

void map_tutorial(void);

//HP,MP,STATUS全回復
void full_recover(Player **st, Player **st2, Player **st3);

void game_story2(Player *st, Player *st2, Player * st3, P_skill *player_skill, P_skill *player_skill2, P_skill *player_skill3, Setting_skill *setting_skill, Setting_skill *setting_skill2, Setting_skill *setting_skill3, Items *items, Equip *pEquip, Equip *p2Equip, Equip *p3Equip, SearchDangeon *search, Area *area);

//map.c
void area1_map(Area **area, Player **st, Player **st2, Player **st3, P_skill **player_skill, P_skill **player_skill2, P_skill **player_skill3, Setting_skill **setting_skill, Setting_skill **setting_skill2, Setting_skill **setting_skill3, Items **items, Equip **pEquip, Equip **p2Equip, Equip **p3Equip, SearchDangeon **search);

void area2_map(Area **area, Player **st, Player **st2, Player **st3, P_skill **player_skill, P_skill **player_skill2, P_skill **player_skill3, Setting_skill **setting_skill, Setting_skill **setting_skill2, Setting_skill **setting_skill3, Items **items, Equip **pEquip, Equip **p2Equip, Equip **p3Equip, SearchDangeon **search);

void save_area2(int area_data_line, int area_data_len, int automap_area[area_data_line][area_data_len]);

void save_autoMap(Area ***area, int area_data_line, int area_data_len, int automap_area[area_data_line][area_data_len]);

void check_dangeonId(Area ****area);

int search_dangeon(Area ****area, Map **map, SearchDangeon ****search, int area_data_line, int area_data_len, int area_data[area_data_line][area_data_len]);

void get_search_event(int search_id, Player ****st, Items ****items, Equip ****pEquip, Equip ****p2Equip, Equip ****p3Equip);

void player_move(Player ***st, Player ***st2, Player ***st3, P_skill ***player_skill, P_skill ***player_skill2, P_skill ***player_skill3, Setting_skill ***setting_skill, Setting_skill ***setting_skill2, Setting_skill ***setting_skill3, Items ***items, Equip ***pEquip, Equip ***p2Equip, Equip ***p3Equip, SearchDangeon ***search, Map *map, Area ***area, int area_data_line, int area_data_len, int area_data[area_data_line][area_data_len], int automap_area[area_data_line][area_data_len]);

//about menu function in map.c
void display_menu(Player ****st, Player ****st2, Player ****st3, P_skill ****player_skill, P_skill ****player_skill2, P_skill ****player_skill3, Setting_skill ****setting_skill, Setting_skill ****setting_skill2, Setting_skill ****setting_skill3, Items ****items, Equip ****pEquip, Equip ****p2Equip, Equip ****p3Equip, Map **map, Area ****area, int area_data_line, int area_data_len, int automap_area[area_data_line][area_data_len]);

void display_graphycalHP_for_menu(Player *****st, Player *****st2, Player *****st3);

void display_graphycalMP_for_menu(Player *****st, Player *****st2, Player *****st3);

void menu_display_condition(Player *****st, int battle_display_condition_count);

void menu_player_effective(Player *******st);

void menu_player_status(Player ******st);

int menu_item_useselect(Player *******st, Player *******st2, Player *******st3, Items *******items);

void menu_HPRecoverItem_process(Player ********st, int recover_point);

void menu_BadStatusRecoverItem_process(Player ********st, int Badstatus);

void menu_use_items_effect(Player *******st, Player *******st2, Player *******st3, int item_number, int item_target);

void menu_item_use(Player ******st, Player ******st2, Player ******st3, Items ******items, int command);

void check_set_skillID(Setting_skill ********setting_skill, int idx);

int learned_PhysicalSkill_list(P_skill ********player_skill, Setting_skill ********setting_skill);

int learned_FireSkill_list(P_skill ********player_skill, Setting_skill ********setting_skill);

void set_skill_list(P_skill *******player_skill, Setting_skill *******setting_skill);

void skill_set(Player ******st, P_skill ******player_skill, Setting_skill ******setting_skill);

void item_menu(Player *****st, Player *****st2, Player *****st3, Items *****items);

void equip_change(int command, int input, Equip *******pEquip, Equip *******p2Equip, Equip *******p3Equip);

int equip_command_check(int command, Equip *******pEquip);

void isEquip_check(Equip *******pEquip, Equip *******p2Equip, Equip *******p3Equip);

void before_equip_plus(int input, Equip *******pEquip, Equip *******p2Equip, Equip *******p3Equip);

void reflect_equipEffect(Player ********st, Equip ********pEquip, int equipInfo);

void equip_effect(Player *******st, Equip *******pEquip, int input);

void display_isEquip(Equip *******pEquip);

void display_menu_isEquip(Equip ******pEquip);

void unequip(Player ******st, Player ******st2, Player ******st3, Equip ******pEquip, Equip ******p2Equip, Equip ******p3Equip);

void display_equip_change(Player ******st, Equip ******pEquip, Equip ******p2Equip, Equip ******p3Equip, int input);

void skill_menu(Player *****st, Player *****st2, Player *****st3, P_skill *****player_skill, P_skill *****player_skill2, P_skill *****player_skill3, Setting_skill *****setting_skill, Setting_skill *****setting_skill2, Setting_skill *****setting_skill3);

void equip_menu(Player *****st, Player *****st2, Player *****st3, Equip *****pEquip, Equip *****p2Equip, Equip *****p3Equip);

void set_menu(Player *****st, Player *****st2, Player *****st3, P_skill *****player_skill, P_skill *****player_skill2, P_skill *****player_skill3, Setting_skill *****setting_skill, Setting_skill *****setting_skill2, Setting_skill *****setting_skill3);

void status_menu(Player *****st, Player *****st2, Player *****st3);

void map_menu(Map ***map, Area *****area, int area_data_line, int area_data_len, int automap_area[area_data_line][area_data_len]);

//map.c -> rpg_battle_same_enemy.c
int is_backAttack(Player ****st, Player ****st2, Player ****st3);

void game_battle(Player ***st, Player ***st2, Player ***st3, P_skill ***player_skill, P_skill ***player_skill2, P_skill ***player_skill3, Setting_skill ***setting_skill, Setting_skill ***setting_skill2, Setting_skill ***setting_skill3, Items ***items, Equip ***pEquip, Equip ***p2Equip, Equip ***p3Equip, Enemy *enemy, int encount_pattern);

int is_enemy_alive(Enemy **enemy);

int is_enemyCopy_alive(Enemy *enemy_copy);

int calculate_evaPer(int eva_base, int eva);  //回避率計算関数(rpg_battle_function.c)

double calculate_criticalPer(int critical_base, int critical);  //クリティカル率計算関数(rpg_battle_function.c)

void is_damaged_by_playerAttack(Player ******st, Enemy ****enemy, int ***enemy_deadcount, int damage);  //playerの通常攻撃で敵が生きるか死ぬかチェック(生きる場合はダメージ計算)(rpg_battle_function.c)

void is_damaged_by_playerAttack_forEnemyCopy(Player ******st, Enemy ***enemy_copy, int ***enemy_deadcount, int damage);

double check_enemyCopy_normalAttackResist(Player *****st, Enemy **enemy_copy, int **enemy_deadcount, int damage);

int player_panicMove(Player *****st);

void player_curseMove(Player *****st, int damage);

double player_attack_for_enemy(Player ****st, Enemy **enemy, int *enemy_deadcount);

double player_attack_for_enemyCopy(Player ****st, Enemy *enemy_copy, int *enemy_deadcount);

double enemy_attack(Player *****st, Player *****st2, Player *****st3, Enemy ***enemy, int player_guard, int player_guard2, int player_guard3, double enemy_turn);

double enemy_copy_attack(Player *****st, Player *****st2, Player *****st3, Enemy **enemy_copy1, int player_guard, int player_guard2, int player_guard3, double enemy_turn);

void enemy_data_copy(Enemy **enemy, Enemy *enemy_copy);

int battle_escape(Player ****st, int *escape_number);

void poison_effect(Player ****st);

int is_skill_learning(P_skill ****player_skill);

void add_battleExperience(Player ****st, P_skill ****player_skill, int battle_experience);

void player_badstatus_recover(Player ****st);

void display_gameover(void);

//rpg_battle_encount_pattern5.c
void game_battle_encount_pattern5(Player ***st, Player ***st2, Player ***st3, P_skill ***player_skill, P_skill ***player_skill2, P_skill ***player_skill3, Setting_skill ***setting_skill, Setting_skill ***setting_skill2, Setting_skill ***setting_skill3, Items ***items, Equip ***pEquip, Equip ***p2Equip, Equip ***p3Equip, Enemy *enemy, Enemy *enemy1, int encount_pattern);

void enemy_full_recover5(Enemy **enemy, Enemy **enemy1);

//rpg_battle_encount_pattern6.c

void game_battle_encount_pattern6(Player ***st, Player ***st2, Player ***st3, P_skill ***player_skill, P_skill ***player_skill2, P_skill ***player_skill3, Setting_skill ***setting_skill, Setting_skill ***setting_skill2, Setting_skill ***setting_skill3, Items ***items, Equip ***pEquip, Equip ***p2Equip, Equip ***p3Equip, Enemy *enemy, Enemy *enemy1, Enemy *enemy2, int encount_pattern);

void enemy_full_recover6(Enemy **enemy, Enemy **enemy1, Enemy **enemy2);

//rpg_battle_encount_pattern7.c

void game_battle_encount_pattern7(Player ***st, Player ***st2, Player ***st3, P_skill ***player_skill, P_skill ***player_skill2, P_skill ***player_skill3, Setting_skill ***setting_skill, Setting_skill ***setting_skill2, Setting_skill ***setting_skill3, Items ***items, Equip ***pEquip, Equip ***p2Equip, Equip ***p3Equip, Enemy *enemy, Enemy *enemy1, Enemy *enemy2, Enemy *enemy3, int encount_pattern);

void enemy_full_recover7(Enemy **enemy, Enemy **enemy1, Enemy **enemy2, Enemy **enemy3);

//to check enemy_deadcount
int check_enemyDeadCount1(Enemy **enemy);

int check_enemyDeadCount2(Enemy **enemy, Enemy *enemy_copy1);

int check_enemyDeadCount3(Enemy **enemy, Enemy *enemy_copy1, Enemy *enemy_copy2);

int check_enemyDeadCount4(Enemy **enemy, Enemy *enemy_copy1, Enemy *enemy_copy2, Enemy *enemy_copy3);

int check_enemyDeadCount5(Enemy **enemy, Enemy **enemy1);

int check_enemyDeadCount6(Enemy **enemy, Enemy **enemy1, Enemy**enemy2);

int check_enemyDeadCount7(Enemy **enemy, Enemy **enemy1, Enemy **enemy2, Enemy **enemy3);

//about battle turns in rpg_battle.c (playerの行動ごとに消費するターン数を計算)
double calculate_player_turn(double player_turn, double turn_decrease);

double calculate_enemy_turn(double enemy_turn, double turn_decrease);

void display_player_turn(Player ****st, double player_turn);

void display_enemy_turn(Enemy **enemy, double enemy_turn);

void display_enemy_copy_turn(Enemy *enemy_copy1, double enemy_turn);

//rpg_battle_display.c (To show graphycal battle)
//select target to attack enemies
int player_normal_attack_target2(Enemy **enemy, Enemy *enemy_copy1);

int player_normal_attack_target3(Enemy **enemy, Enemy *enemy_copy1, Enemy *enemy_copy2);

int player_normal_attack_target4(Enemy **enemy, Enemy *enemy_copy1, Enemy *enemy_copy2, Enemy *enemy_copy3);

int player_normal_attack_target5(Enemy **enemy, Enemy **enemy1);

int player_normal_attack_target6(Enemy **enemy, Enemy **enemy1, Enemy **enemy2);

int player_normal_attack_target7(Enemy **enemy, Enemy **enemy1, Enemy **enemy2, Enemy **enemy3);

//display about players
void hp_graphycal_display(Player ****st, Player ****st2, Player ****st3);

void mp_graphycal_display(Player ****st, Player ****st2, Player ****st3);

void battle_display_condition(Player ****st, int battle_display_condition_count);

//display about enemies

//(敵１体)
void encount_pattern1_layout(Enemy **enemy, int encount_pattern);
//(同じ敵２体)
void encount_pattern2_layout(Enemy **enemy, Enemy *enemy_copy1, int encount_pattern);
//(同じ敵3体)
void encount_pattern3_layout(Enemy **enemy, Enemy *enemy_copy1, Enemy *enemy_copy2, int encount_pattern);

void encount_pattern4_layout(Enemy **enemy, Enemy *enemy_copy1, Enemy *enemy_copy2, Enemy *enemy_copy3, int encount_pattern);

void encount_pattern5_layout(Enemy **enemy, Enemy **enemy1, int encount_pattern);

void encount_pattern6_layout(Enemy **enemy, Enemy **enemy1, Enemy **enemy2, int encount_pattern);

void encount_pattern7_layout(Enemy **enemy, Enemy **enemy1, Enemy **enemy2, Enemy **enemy3, int encount_pattern);

//battle_skill.c ( about players and enemies skills function and to decide enemies move pattern)
int check_playerMP(Player *****st, int skillMP);

void analyze_enemyCopy_skill(Enemy **enemy_copy);

void analyze_enemy_skill(Enemy ***enemy);

int player_skill_forParty(Player ****st, Player ****st2, Player ****st3, P_skill ****player_skill, int use_skill_count, int skill_target, int skill_user);

int player_skill_forEnemy(Player ****st, P_skill ****player_skill, Enemy **enemy, int use_skill_count);

int player_skill_forEnemyCopy(Player ****st, P_skill ****player_skill, Enemy *enemy_copy, int use_skill_count);

int select_player_skillTarget(Player ****st, Player ****st2, Player ****st3);

int use_player_skill(Player ****st, Player ****st2, Player ****st3, P_skill ****player_skill, Setting_skill ****setting_skill, int skill_user);

int select_encount_pattern2_skillTarget(Enemy **enemy, Enemy *enemy_copy1);

int select_encount_pattern3_skillTarget(Enemy **enemy, Enemy *enemy_copy1, Enemy *enemy_copy2);

int select_encount_pattern4_skillTarget(Enemy **enemy, Enemy *enemy_copy1, Enemy *enemy_copy2, Enemy *enemy_copy3);

int select_encount_pattern5_skillTarget(Enemy **enemy, Enemy **enemy1);

int select_encount_pattern6_skillTarget(Enemy **enemy, Enemy **enemy1, Enemy **enemy2);

int select_encount_pattern7_skillTarget(Enemy **enemy, Enemy **enemy1, Enemy **enemy2, Enemy **enemy3);

int who_is_skillTarget(int use_skill_count);

void check_skillID(Setting_skill *****setting_skill, int idx);

int battle_player_skill_list(P_skill ****player_skill, Setting_skill ****setting_skill);

double check_enemy_fireResist(Player *****st, Enemy ***enemy, int damage);

double check_enemy_iceResist(Player *****st, Enemy ***enemy, int damage);

double check_enemy_elecResist(Player *****st, Enemy ***enemy, int damage);

double check_enemy_waveResist(Player *****st, Enemy ***enemy, int damage);

double check_enemyCopy_fireResist(Player *****st, Enemy **enemy_copy, int damage);

double check_enemyCopy_iceResist(Player *****st, Enemy **enemy_copy, int damage);

double check_enemyCopy_elecResist(Player *****st, Enemy **enemy_copy, int damage);

double check_enemyCopy_waveResist(Player *****st, Enemy **enemy_copy, int damage);

double enemy_attack_skill(Player ******st, Equip ******pEquip, Equip ******p2Equip, Equip ******p3Equip, Enemy ****enemy, int player_guard, int attack_skill_number);

int enemy_skill_target(Player ******st, Player ******st2, Player ******st3);

double use_enemy_skill(Player *****st, Player *****st2, Player *****st3, Equip *****pEquip, Equip *****p2Equip, Equip *****p3Equip, Enemy ***enemy, int player_guard, int player_guard2, int player_guard3, double enemy_turn);

double use_enemy_copy_skill(Player *****st, Player *****st2, Player *****st3, Equip *****pEquip, Equip *****p2Equip, Equip *****p3Equip, Enemy **enemy_copy1, int player_guard, int player_guard2, int player_guard3, double enemy_turn);

double enemy_attack_pattern(Player ****st, Player ****st2, Player ****st3, Equip ****pEquip, Equip ****p2Equip, Equip ****p3Equip, Enemy **enemy, int player_guard, int player_guard2, int player_guard3, double enemy_turn);

double enemy_copy_attack_pattern(Player ****st, Player ****st2, Player ****st3, Equip ****pEquip, Equip ****p2Equip, Equip ****p3Equip, Enemy *enemy_copy1, int player_guard, int player_guard2, int player_guard3, double enemy_turn);

void is_damaged_byEnemySkill(Player ********st, int damage);

double check_player_physicalRegist(Player *******st, Enemy *****enemy, int damage, int critical_count, int player_guard);

double check_player_fireResist(Player *******st, Enemy *****enemy, int damage, int player_guard);

double check_player_iceResist(Player *******st, Enemy *****enemy, int damage, int player_guard);

double check_player_elecResist(Player *******st, Enemy *****enemy, int damage, int player_guard);

double check_player_waveResist(Player *******st, Enemy *****enemy, int damage, int player_guard);

double check_player_poizonRegist(Player ******st);

double check_player_palyzeRegist(Player ******st);

//rpg_levelup.c ( check levelup and skills whatever players learned)
void player_skill_check(Player ******st, P_skill ******player_skill, Setting_skill ******setting_skill);

void status_lvup(Player *****st, P_skill *****player_skill, Setting_skill *****setting_skill);

void special_status_lvup(Player *****st);

void level_up(Player ****st, P_skill ****player_skill, Setting_skill ****setting_skill);

//item.c
int battle_item_useselect(Items *****items, Player *****st, Player *****st2, Player *****st3);

void battle_HPRecoverItem_process(Player ******st, int recover_point);

void use_items_effect(Player *****st, Player *****st2, Player *****st3, int item_number, int item_target);

int battle_item_use(Items ****items, Player ****st, Player ****st2, Player ****st3);

int item_drop_caluculate(int drop_base, int drop_per);

void item_drop(Player ****st, Player ****st2, Player ****st3, Enemy **enemy, Items ****items, int encount_pattern);

// about events which often happens on the map(dungeon)
void recover_event(Player **st);

#endif
