/* 
Skyy Civil
*/
//   LEGEND \\

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <random>
#include <vector>
#include <unistd.h>

using namespace std;

	/*
	Global variables
	*/
	int XP = 0;
	int Lvl = 0;
	int LvlCount;
	int coins;
	string username;
	string password;

/*
Declaring functions
*/
int main();
void Menu();
void Login();
void LevelStart();
void GameMenu();
void LvlUp();
int LvlWin();
int LvlUpReq();
int XpClear();
void PotionShop();
int AddCoins();
void ClearScreen();
void ElementChange();
void WeaponShop();
/* No files, struct instead.

structing monsters and hero and damage
*/
struct Monster
{
	int monsterCount;
	string monsterType;
	int monsterHealth;
	
};

// Hero
struct Hero{
	string element;
	int health;
	int mana;
};

// Create shop choices




struct Attacks{
	string attack1;
	string attack2;
	string attack3;
	string attack4;
	string attack5;
	string attack6;
	string attack7;

	// Add melee attacks (attakcs 5, 6, 7) \\
	Now I can put text here that wont effect the code.
	int damageAttack1;
	int damageAttack2;
	int damageAttack3;
	int damageAttack4;
	int damageAttack5;
	int damageAttack6;
	int damageAttack7;

	// Mana used per attack, attacks 5, 6, 7 are melee and do not use mana

	int manaAttack1;
	int manaAttack2;
	int manaAttack3;
	int manaAttack4;
	int manaAttack5=0;
	int manaAttack6=0;
	int manaAttack7=0;
};

struct Inventory{

	// Items \\
	Owned

	string purchasedItem1;
	string purchasedItem2;
	string purchesedItem3;
	string PowerUp;
	// Effect \\
	Effect for each item
	int HP1;
	int HP2;
	int HP3;
	int HP4;
	// How many of each item
	int item1cnt;
	int item2cnt;
	int item3cnt;
};

// Shop of potions

struct PotionShop{
		string item1;
	string item2;
	string item3;
	int item1Price;
	int item2Price;
	int item3Price;
};

struct WeaponShop{
	string item1;
	string item2;
	string item3;
	string item4;
	string item5;
	string item6;
	string item7;
	string item8;
	string item9;
	string item10;

	string equippedItem1;
	string equippedItem2;
	string equippedItem3;
	string equippedItem4;
	string equippedItem5;
	string equippedItem6;
	string equippedItem7;
	string equippedItem8;
	string equippedItem9;
	string equippedItem10;


	int price1;
	int price2;
	int price3;
	int price4;
	int price5;
	int price6;
	int price7;
	int price8;
};



// Elements
struct Element{
	string element1;
	string element2;
	string element3;
	string element4;
};

// Clear screen, pretty pathetic eh?
  void ClearScreen()
    {
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );
    }





/*
Requirements for leveling Leveling up
*/

int LvlUpReq(int XP, int Lvl){
	int LvlUpReq;
	LvlUpReq = 200;

	if(XP >= LvlUpReq){
		LvlUpReq++;
	}

	return (LvlUpReq);
}


// If player win the Level
int LvlWin(int XP){
	XP = XP + 100;
	coins += 100;
	return (XP);
}

// Level up

int LvlUp(int XP, int Lvl){
    Lvl += XP / LvlUpReq(XP, Lvl);
		XP = 0;
    return Lvl;
		
}
/*
		Global constructors
*/

	struct Hero player;
	struct Attacks playerAttacks;
	struct Attacks monsterAttacks;
	struct Inventory playerInv;
	struct Monster levelMonster;
	struct PotionShop elemShopChoice;
	struct Element elems;
	struct WeaponShop weapons;
	

		/*
				Weapon Shoppe
		*/

		void WeaponShop(){
			int ui = 100;
			string weaponshopChoice;
			weapons.item1 = "Knife";
			weapons.item2 = "Sword";
			weapons.item3 = "Claymore";
			weapons.item4 = "Giant Hammer";
			weapons.item5 = "Dual Swords";
			weapons.item6 = "Dual Kamas";
			weapons.item7 = "Chains";

			weapons.price1 = 100;
			weapons.price2 = 300;
			weapons.price3 = 500;
			weapons.price4 = 600;
			weapons.price5 = 800;
			weapons.price6 = 700;

			cout << "(1) " << weapons.item1 << endl;
			cout << "(2) " << weapons.item2 << endl;
			cout << "(3) " << weapons.item3 << endl;
			cout << "(4) " << weapons.item4 << endl;
			cout << "(5) " << weapons.item5 << endl;
			cout << "(6) " << weapons.item6 << endl;
			
			cin >> weaponshopChoice;

				while(ui == 100){

					if(weaponshopChoice == "1"){
						ClearScreen();
						cout << weapons.item1 << endl;
						cout << "Price: " << weapons.price1 << endl;
						cout << "(a) Confirm" << endl;
						cout << "(b) cancel" << endl;
						cin >> weaponshopChoice;
						if(weaponshopChoice == "b"){
							ClearScreen();
							cout << "(1) " << weapons.item1 << endl;
							cout << "(2) " << weapons.item2 << endl;
							cout << "(3) " << weapons.item3 << endl;
							cout << "(4) " << weapons.item4 << endl;
							cout << "(5) " << weapons.item5 << endl;
							cout << "(6) " << weapons.item6 << endl;
							cin >> weaponshopChoice;
						}
						if(weaponshopChoice == "a"){
							ClearScreen();
						cout << "Enter your password: ";
							cin >> weaponshopChoice;
							if(weaponshopChoice == password){
							
								coins -= weapons.price1;
								weapons.item1 = weapons.equippedItem1;
							}
							if(weaponshopChoice != password){
								cout << "password invalid!";
								sleep(2);
								ClearScreen();
											cout << "(1) " << weapons.item1 << endl;
							cout << "(2) " << weapons.item2 << endl;
							cout << "(3) " << weapons.item3 << endl;
							cout << "(4) " << weapons.item4 << endl;
							cout << "(5) " << weapons.item5 << endl;
							cout << "(6) " << weapons.item6 << endl;
							cin >> weaponshopChoice;
							}
						}
					}

										if(weaponshopChoice == "2"){
						ClearScreen();
						cout << weapons.item1 << endl;
						cout << "Price: " << weapons.price2 << endl;
						cout << "(a) Confirm" << endl;
						cout << "(b) cancel" << endl;
						cin >> weaponshopChoice;
						if(weaponshopChoice == "b"){
							ClearScreen();
							cout << "(1) " << weapons.item1 << endl;
							cout << "(2) " << weapons.item2 << endl;
							cout << "(3) " << weapons.item3 << endl;
							cout << "(4) " << weapons.item4 << endl;
							cout << "(5) " << weapons.item5 << endl;
							cout << "(6) " << weapons.item6 << endl;
							cin >> weaponshopChoice;
						}
						if(weaponshopChoice == "a"){
							ClearScreen();
						cout << "Enter your password: ";
							cin >> weaponshopChoice;
							if(weaponshopChoice == password){
								
								weapons.item2 = weapons.equippedItem2;
							}
							if(weaponshopChoice != password){
								cout << "password invalid!";
								sleep(2);
								ClearScreen();
											cout << "(1) " << weapons.item1 << endl;
							cout << "(2) " << weapons.item2 << endl;
							cout << "(3) " << weapons.item3 << endl;
							cout << "(4) " << weapons.item4 << endl;
							cout << "(5) " << weapons.item5 << endl;
							cout << "(6) " << weapons.item6 << endl;
							cin >> weaponshopChoice;
							}
						}
					}

										if(weaponshopChoice == "3"){
						ClearScreen();
						cout << weapons.item3 << endl;
						cout << "Price: " << weapons.price1 << endl;
						cout << "(a) Confirm" << endl;
						cout << "(b) cancel" << endl;
						cin >> weaponshopChoice;
						if(weaponshopChoice == "b"){
							ClearScreen();
							cout << "(1) " << weapons.item1 << endl;
							cout << "(2) " << weapons.item2 << endl;
							cout << "(3) " << weapons.item3 << endl;
							cout << "(4) " << weapons.item4 << endl;
							cout << "(5) " << weapons.item5 << endl;
							cout << "(6) " << weapons.item6 << endl;
							cin >> weaponshopChoice;
						}
						if(weaponshopChoice == "a"){
							ClearScreen();
						cout << "Enter your password: ";
							cin >> weaponshopChoice;
							if(weaponshopChoice == password){
								
								coins -= weapons.price2;
								weapons.item3 = weapons.equippedItem3;
							}
							if(weaponshopChoice != password){
								cout << "password invalid!";
								sleep(2);
								ClearScreen();
											cout << "(1) " << weapons.item1 << endl;
							cout << "(2) " << weapons.item2 << endl;
							cout << "(3) " << weapons.item3 << endl;
							cout << "(4) " << weapons.item4 << endl;
							cout << "(5) " << weapons.item5 << endl;
							cout << "(6) " << weapons.item6 << endl;
							cin >> weaponshopChoice;
							}
						}
					}

										if(weaponshopChoice == "4"){
						ClearScreen();
						cout << weapons.item1 << endl;
						cout << "Price: " << weapons.price4 << endl;
						cout << "(a) Confirm" << endl;
						cout << "(b) cancel" << endl;
						cin >> weaponshopChoice;
						if(weaponshopChoice == "b"){
							ClearScreen();
							cout << "(1) " << weapons.item1 << endl;
							cout << "(2) " << weapons.item2 << endl;
							cout << "(3) " << weapons.item3 << endl;
							cout << "(4) " << weapons.item4 << endl;
							cout << "(5) " << weapons.item5 << endl;
							cout << "(6) " << weapons.item6 << endl;
							cin >> weaponshopChoice;
						}
						if(weaponshopChoice == "a"){
							ClearScreen();
						cout << "Enter your password: ";
							cin >> weaponshopChoice;
							if(weaponshopChoice == password){
								coins -= weapons.price4;
								weapons.item4 = weapons.equippedItem4;
							}
							if(weaponshopChoice != password){
								cout << "password invalid!";
								sleep(2);
								ClearScreen();
											cout << "(1) " << weapons.item1 << endl;
							cout << "(2) " << weapons.item2 << endl;
							cout << "(3) " << weapons.item3 << endl;
							cout << "(4) " << weapons.item4 << endl;
							cout << "(5) " << weapons.item5 << endl;
							cout << "(6) " << weapons.item6 << endl;
							cin >> weaponshopChoice;
							}
						}
					}

										if(weaponshopChoice == "5"){
						ClearScreen();
						cout << weapons.item1 << endl;
						cout << "Price: " << weapons.price5 << endl;
						cout << "(a) Confirm" << endl;
						cout << "(b) cancel" << endl;
						cin >> weaponshopChoice;
						if(weaponshopChoice == "b"){
							ClearScreen();
							cout << "(1) " << weapons.item1 << endl;
							cout << "(2) " << weapons.item2 << endl;
							cout << "(3) " << weapons.item3 << endl;
							cout << "(4) " << weapons.item4 << endl;
							cout << "(5) " << weapons.item5 << endl;
							cout << "(6) " << weapons.item6 << endl;
							cin >> weaponshopChoice;
						}
						if(weaponshopChoice == "a"){
							ClearScreen();
						cout << "Enter your password: ";
							cin >> weaponshopChoice;
							if(weaponshopChoice == password){
								coins -= weapons.price5;
								weapons.item5 = weapons.equippedItem5;
							}
							if(weaponshopChoice != password){
								cout << "password invalid!";
								sleep(2);
								ClearScreen();
											cout << "(1) " << weapons.item1 << endl;
							cout << "(2) " << weapons.item2 << endl;
							cout << "(3) " << weapons.item3 << endl;
							cout << "(4) " << weapons.item4 << endl;
							cout << "(5) " << weapons.item5 << endl;
							cout << "(6) " << weapons.item6 << endl;
							cin >> weaponshopChoice;
							}
						}
					}

										if(weaponshopChoice == "1"){
						ClearScreen();
						cout << weapons.item1 << endl;
						cout << "Price: " << weapons.price1 << endl;
						cout << "(a) Confirm" << endl;
						cout << "(b) cancel" << endl;
						cin >> weaponshopChoice;
						if(weaponshopChoice == "b"){
							ClearScreen();
							cout << "(1) " << weapons.item1 << endl;
							cout << "(2) " << weapons.item2 << endl;
							cout << "(3) " << weapons.item3 << endl;
							cout << "(4) " << weapons.item4 << endl;
							cout << "(5) " << weapons.item5 << endl;
							cout << "(6) " << weapons.item6 << endl;
							cin >> weaponshopChoice;
						}
						if(weaponshopChoice == "a"){
							ClearScreen();
						cout << "Enter your password: ";
							cin >> weaponshopChoice;
							if(weaponshopChoice == password){
								coins -= weapons.price1;
								weapons.item6 = weapons.equippedItem6;
							}
							if(weaponshopChoice != password){
								cout << "password invalid!";
								sleep(2);
								ClearScreen();
											cout << "(1) " << weapons.item1 << endl;
							cout << "(2) " << weapons.item2 << endl;
							cout << "(3) " << weapons.item3 << endl;
							cout << "(4) " << weapons.item4 << endl;
							cout << "(5) " << weapons.item5 << endl;
							cout << "(6) " << weapons.item6 << endl;
							cin >> weaponshopChoice;
							}
						}
					}

										if(weaponshopChoice == "1"){
						ClearScreen();
						cout << weapons.item1 << endl;
						cout << "Price: " << weapons.price1 << endl;
						cout << "(a) Confirm" << endl;
						cout << "(b) cancel" << endl;
						cin >> weaponshopChoice;
						if(weaponshopChoice == "b"){
							ClearScreen();
							cout << "(1) " << weapons.item1 << endl;
							cout << "(2) " << weapons.item2 << endl;
							cout << "(3) " << weapons.item3 << endl;
							cout << "(4) " << weapons.item4 << endl;
							cout << "(5) " << weapons.item5 << endl;
							cout << "(6) " << weapons.item6 << endl;
							cin >> weaponshopChoice;
						}
						if(weaponshopChoice == "a"){
							ClearScreen();
						cout << "Enter your password: ";
							cin >> weaponshopChoice;
							if(weaponshopChoice == password){
								coins -= weapons.price6;
								weapons.item7 = weapons.equippedItem7;
							}
							if(weaponshopChoice != password){
								cout << "password invalid!";
								sleep(2);
								ClearScreen();
											cout << "(1) " << weapons.item1 << endl;
							cout << "(2) " << weapons.item2 << endl;
							cout << "(3) " << weapons.item3 << endl;
							cout << "(4) " << weapons.item4 << endl;
							cout << "(5) " << weapons.item5 << endl;
							cout << "(6) " << weapons.item6 << endl;
							cin >> weaponshopChoice;
							}
						}
					}

									
					
			}
		}




	/*
	Changing element
	*/
	void ElementChange(){
		int changeCnt;
		string elemChoice;
		elems.element1 = "Fire";
		elems.element2 = "Ice";
		elems.element3 = "Darkness";
		elems.element4 = "Earth";
		cout << "Choose an Element";
		cout << "\n(a) "<< elems.element1 << endl;
		cout << "(b) "<< elems.element2<<endl;
		cout <<"(c) "<< elems.element3<<endl;
		cout <<"(d) "<< elems.element4<<endl;
		cin >> elemChoice;
		if(elemChoice == "a"){
			player.element = "Fire";
			GameMenu();
		}

		if(elemChoice == "b"){
			player.element = "Ice";
			GameMenu();
		}

		if(elemChoice == "c"){
			player.element = "Darkness";
			GameMenu();
		}

		if(elemChoice == "d"){
			player.element = "Earth";
			GameMenu();
		}

	}
	

/*
	Shoppe
*/

void PotionShop(int coins){
	
	int ui = 1;
	int choice;
	elemShopChoice.item1 = "Small health potion";
	elemShopChoice.item1Price = 100;
	elemShopChoice.item2 = "Medium potion";
	elemShopChoice.item2Price = 300;
	elemShopChoice.item3 = "Large potion";
	elemShopChoice.item3Price = 500;
	cout << 
"░██████╗██╗░░██╗░█████╗░██████╗░\n"
"██╔════╝██║░░██║██╔══██╗██╔══██╗\n"
"╚█████╗░███████║██║░░██║██████╔╝\n"
"░╚═══██╗██╔══██║██║░░██║██╔═══╝░\n"
"██████╔╝██║░░██║╚█████╔╝██║░░░░░\n"
"╚═════╝░╚═╝░░╚═╝░╚════╝░╚═╝░░░░░\n\n\n";
while(ui == 1){
cout << "(1) " << elemShopChoice.item1 << endl;
cout <<  "Price: " << elemShopChoice.item1Price << endl;
cout << "(2) "<< elemShopChoice.item2 << endl;
cout << "Price: " << elemShopChoice.item2Price<<endl;
cout <<"(3) "<< elemShopChoice.item3<<endl;
cout << "Price: " << elemShopChoice.item3Price <<endl;
cout << "(4) Back to game menu\n";
cin >> choice;

if (choice == 1){
	if (coins >= elemShopChoice.item1Price){
		playerInv.purchasedItem1 = elemShopChoice.item1;
		playerInv.item1cnt += 1;
		coins -= elemShopChoice.item1Price;
		cout << "\n\nPurchase Complete\n\n";

	}
	if (coins < elemShopChoice.item1Price){
		cout << "\nTry again\n > ";
	}

}

if (choice == 2){
	if (coins >= elemShopChoice.item2Price){
		playerInv.purchasedItem1 = elemShopChoice.item2;
		playerInv.item2cnt += 1;
		coins -= elemShopChoice.item2Price;
	cout << "\nPurchase Complete\n";
	}
	if (coins < elemShopChoice.item2Price){
		cout << "Try again\n > ";
	}

}
if (choice == 3){
	if (coins >= elemShopChoice.item3Price){
		playerInv.purchasedItem1 = elemShopChoice.item3;
		playerInv.item3cnt += 1;
		coins -= elemShopChoice.item3Price;
		cout << "\n\nPurchase Complete!\n";

	}
if (coins < elemShopChoice.item3Price){
		cout << "Try again\n > ";
	}
}
if (choice == 4){
	GameMenu();
}

}
}

/*
		The actual level starts here
*/


void LevelStart(int XP, int Lvl){
	
	int playerAttack;

	int PwrUpCnt = 1;

	// Inventory
	
	playerInv.PowerUp = "POWER UP!";
	playerInv.HP1 = 15;
	playerInv.HP2 = 30;
	playerInv.HP3 = 40;
	playerInv.HP4=100;


	// Player attacks and stats
	
	player.health = 200;
	player.mana = 150;

	if(player.element == "Fire"){
	playerAttacks.attack1 = "FireBall";
	playerAttacks.attack2 = "Fire Slash";
	playerAttacks.attack3 = "Fire Barrage";
	playerAttacks.attack4 = "Blue Flame Bomb";


playerAttacks.damageAttack1 = 25;
	playerAttacks.damageAttack2 = 35;
	playerAttacks.damageAttack3 = 40;
	playerAttacks.damageAttack4 = 50;

		playerAttacks.manaAttack1 = 10;
	playerAttacks.manaAttack2 = 15;
	playerAttacks.manaAttack3 = 25;
	playerAttacks.manaAttack4 = 60;
	}

if (player.element == "Ice"){
	playerAttacks.attack1 = "Ice spear";
	playerAttacks.attack2 = "Ice shard barrage";
	playerAttacks.attack3 = "Ice pillar";
	playerAttacks.attack4 = "Absolute Zero";

playerAttacks.damageAttack1 = 15;
	playerAttacks.damageAttack2 = 25;
	playerAttacks.damageAttack3 = 30;
	playerAttacks.damageAttack4 = 40;

		playerAttacks.manaAttack1 = 15;
	playerAttacks.manaAttack2 = 25;
	playerAttacks.manaAttack3 = 35;
	playerAttacks.manaAttack4 = 40;
}

if(player.element == "Darkness"){
	playerAttacks.attack1 = "Beam of Darkness";
	playerAttacks.attack2 = "Shadow Claw"; // Epic
	playerAttacks.attack3 = "Black Hole";
	playerAttacks.attack4 = "Umbra Boom"; // Nice

		playerAttacks.damageAttack1 = 20;
	playerAttacks.damageAttack2 = 35;
	playerAttacks.damageAttack3 = 40;
	playerAttacks.damageAttack4 = 60;

		playerAttacks.manaAttack1 = 10;
	playerAttacks.manaAttack2 = 25;
	playerAttacks.manaAttack3 = 45;
	playerAttacks.manaAttack4 = 100;
}

if (player.element == "Earth"){
	// Attacks

	playerAttacks.attack1 = "Rock barrage";
	playerAttacks.attack2 = "Rock pillar";
	playerAttacks.attack3 = "Hot rocks";
	playerAttacks.attack4 = "Rock bomb";

// Damages per attack

		playerAttacks.damageAttack1 = 15;
	playerAttacks.damageAttack2 = 20;
	playerAttacks.damageAttack3 = 30;
	playerAttacks.damageAttack4 = 50;

	playerAttacks.manaAttack1 = 10;
	playerAttacks.manaAttack2 = 15;
	playerAttacks.manaAttack3 = 25;
	playerAttacks.manaAttack4 = 60;
}

if(weapons.item1 == weapons.equippedItem1){

 playerAttacks.attack5 = "Basic slash";
 playerAttacks.attack6 = "Spin slash";
 playerAttacks.attack7="Slicing combo";
}
	if(weapons.item2 == weapons.equippedItem2){
	// Sword attacks
	playerAttacks.attack5 = "Rush Pierce";
	playerAttacks.attack6 = "Core Slash";
	playerAttacks.attack7 = "Divine Burst";
}
	if(weapons.item3 == weapons.equippedItem3){
		playerAttacks.attack5 = 	
	}


	playerAttacks.damageAttack1 = 10;
	playerAttacks.damageAttack2 = 15;
	playerAttacks.damageAttack3 = 20;
	playerAttacks.damageAttack4 = 40;
	playerAttacks.damageAttack5 = 5;
	playerAttacks.damageAttack6=10;
	playerAttacks.damageAttack7=15;
	// Mana

	playerAttacks.manaAttack5 = 0;
	playerAttacks.manaAttack6=0;
	playerAttacks.manaAttack7=0;
	// Monster attacks and stats
	
	levelMonster.monsterCount = 1;
	levelMonster.monsterType = "Phynxis";


	string monsterAttack[3] = {"Bash", "Spin Attack", "Heavy Punch"};
	int monsterAttackDamage[3] = {10, 15, 50};
		levelMonster.monsterHealth = 200 + LvlCount * 1.5;


	
// -----------------MAKING ATTACKS---------------------\\
	cout << "HP: " << player.health << endl;
	cout << "Monsters: " << levelMonster.monsterCount;
	cout << "Monster HP: " << levelMonster.monsterHealth;
	cout << "\n\n Monster type: " << levelMonster.monsterType;
	cout << "\n\n\nMAGIC ATTACKS\n";
	cout << "\n\n (1) " << playerAttacks.attack1 << " DMG-" << playerAttacks.damageAttack1 << "     Mana-" << playerAttacks.manaAttack1;
	cout << "\n\n (2) " << playerAttacks.attack2 << " DMG-" << playerAttacks.damageAttack2 << "     Mana-" << playerAttacks.manaAttack2;
	cout << "\n\n (3) " << playerAttacks.attack3 << " DMG-" << playerAttacks.damageAttack3 << "     Mana-" << playerAttacks.manaAttack3;
	cout << "\n\n (4) " << playerAttacks.attack4 << " DMG-" << playerAttacks.damageAttack4 << "     Mana-" << playerAttacks.manaAttack4;
	cout << "\n\n\nMELEE ATTACKS\n";
	cout << "\n\n (5) " << playerAttacks.attack5 << " DMG-" << playerAttacks.damageAttack5 << "     Mana-" << playerAttacks.manaAttack5;
	cout << "\n\n (6) " << playerAttacks.attack6 << " DMG-" << playerAttacks.damageAttack6 << "     Mana-" << playerAttacks.manaAttack6;
	cout << "\n\n (7) " << playerAttacks.attack7 << " DMG-" << playerAttacks.damageAttack7 << "     Mana-" << playerAttacks.manaAttack7;
	cout << "\n\n (8) Inventory";
	cout << "\n > ";
	
	// While loop

	while((levelMonster.monsterCount = 1)){
	cin >> playerAttack;
	// Attack 1 Loop
	if(playerAttack == 1){
		ClearScreen();
		levelMonster.monsterHealth = levelMonster.monsterHealth - playerAttacks.damageAttack1;
		int RandAtk = rand() % 3;
		int RandDmg = rand() % 3;
		player.mana -= playerAttacks.manaAttack1;
		cout << endl <<endl<< levelMonster.monsterType << " used " << monsterAttack[RandAtk] << " and dealt " << monsterAttackDamage[RandDmg] << endl;
		player.health = player.health - monsterAttackDamage[RandDmg];
	
			cout << "\nHP: " << player.health << endl;
			cout << "\nMana: " << player.mana << endl;
			cout << "\nMonsters: " << levelMonster.monsterCount << endl;
			cout << "Monster health: " << levelMonster.monsterHealth << endl;
	cout << "\n\n Monster type: " << levelMonster.monsterType;
	cout << "\n\n\nMAGIC ATTACKS\n";
	cout << "\n\n (1) " << playerAttacks.attack1 << " DMG-" << playerAttacks.damageAttack1 << "     Mana-" << playerAttacks.manaAttack1;
	cout << "\n\n (2) " << playerAttacks.attack2 << " DMG-" << playerAttacks.damageAttack2 << "     Mana-" << playerAttacks.manaAttack2;
	cout << "\n\n (3) " << playerAttacks.attack3 << " DMG-" << playerAttacks.damageAttack3 << "     Mana-" << playerAttacks.manaAttack3;
	cout << "\n\n (4) " << playerAttacks.attack4 << " DMG-" << playerAttacks.damageAttack4 << "     Mana-" << playerAttacks.manaAttack4;
	cout << "\n\n\nMELEE ATTACKS\n";
	cout << "\n\n (5) " << playerAttacks.attack5 << " DMG-" << playerAttacks.damageAttack5 << "     Mana-" << playerAttacks.manaAttack5;
	cout << "\n\n (6) " << playerAttacks.attack6 << " DMG-" << playerAttacks.damageAttack6 << "     Mana-" << playerAttacks.manaAttack6;
	cout << "\n\n (7) " << playerAttacks.attack7 << " DMG-" << playerAttacks.damageAttack7 << "     Mana-" << playerAttacks.manaAttack7;
	cout << "\n\n (8) Inventory";
	cout << "\n > ";

	if(player.mana < playerAttacks.manaAttack1){
		cout << "Not enough Mana!\n > ";
	}

	}

	// Attack 2 loop
	if(playerAttack == 2){
		ClearScreen();
		int RandAtk = rand() % 3;
		int RandDmg = rand() % 3;
		player.mana -= playerAttacks.manaAttack2;
		cout << endl <<endl<< levelMonster.monsterType << " used " << monsterAttack[RandAtk] << " and dealt " << monsterAttackDamage[RandDmg] << endl;
		levelMonster.monsterHealth = levelMonster.monsterHealth - playerAttacks.damageAttack2;
		cout << "HP: " << player.health << endl;
		cout << "\nMana: " << player.mana << endl;
			cout << "Monsters: " << levelMonster.monsterCount << endl;
			cout << "Monster health: " << levelMonster.monsterHealth;
	cout << "\n\n Monster type: " << levelMonster.monsterType;
	cout << "\n\n\nMAGIC ATTACKS\n";
	cout << "\n\n (1) " << playerAttacks.attack1 << " DMG-" << playerAttacks.damageAttack1 << "     Mana-" << playerAttacks.manaAttack1;
	cout << "\n\n (2) " << playerAttacks.attack2 << " DMG-" << playerAttacks.damageAttack2 << "     Mana-" << playerAttacks.manaAttack2;
	cout << "\n\n (3) " << playerAttacks.attack3 << " DMG-" << playerAttacks.damageAttack3 << "     Mana-" << playerAttacks.manaAttack3;
	cout << "\n\n (4) " << playerAttacks.attack4 << " DMG-" << playerAttacks.damageAttack4 << "     Mana-" << playerAttacks.manaAttack4;
	cout << "\n\n\nMELEE ATTACKS\n";
	cout << "\n\n (5) " << playerAttacks.attack5 << " DMG-" << playerAttacks.damageAttack5 << "     Mana-" << playerAttacks.manaAttack5;
	cout << "\n\n (6) " << playerAttacks.attack6 << " DMG-" << playerAttacks.damageAttack6 << "     Mana-" << playerAttacks.manaAttack6;
	cout << "\n\n (7) " << playerAttacks.attack7 << " DMG-" << playerAttacks.damageAttack7 << "     Mana-" << playerAttacks.manaAttack7;
	cout << "\n\n (8) Inventory";
	cout << "\n > ";
		if(player.mana < playerAttacks.manaAttack2){
		cout << "Not enough Mana!\n > ";
	}
	}

	// Attack 3 loop

	if(playerAttack == 3){
		ClearScreen();
		int RandAtk = rand() % 3;
		int RandDmg = rand() % 3;
		player.mana -= playerAttacks.manaAttack3;
				cout << endl <<endl<< levelMonster.monsterType << " used " << monsterAttack[RandAtk] << " and dealt " << monsterAttackDamage[RandDmg] << endl;
		levelMonster.monsterHealth = levelMonster.monsterHealth - playerAttacks.damageAttack3;
		cout << "\nHP: " << player.health << endl;
		cout << "\nMana: " << player.mana << endl;
			cout << "Monsters: " << levelMonster.monsterCount << endl;
			cout << "Monster health: " << levelMonster.monsterHealth;
	cout << "\n\n Monster type: " << levelMonster.monsterType;
	cout << "\n\n\nMAGIC ATTACKS\n";
	cout << "\n\n (1) " << playerAttacks.attack1 << " DMG-" << playerAttacks.damageAttack1 << "     Mana-" << playerAttacks.manaAttack1;
	cout << "\n\n (2) " << playerAttacks.attack2 << " DMG-" << playerAttacks.damageAttack2 << "     Mana-" << playerAttacks.manaAttack2;
	cout << "\n\n (3) " << playerAttacks.attack3 << " DMG-" << playerAttacks.damageAttack3 << "     Mana-" << playerAttacks.manaAttack3;
	cout << "\n\n (4) " << playerAttacks.attack4 << " DMG-" << playerAttacks.damageAttack4 << "     Mana-" << playerAttacks.manaAttack4;
	cout << "\n\n\nMELEE ATTACKS\n";
	cout << "\n\n (5) " << playerAttacks.attack5 << " DMG-" << playerAttacks.damageAttack5 << "     Mana-" << playerAttacks.manaAttack5;
	cout << "\n\n (6) " << playerAttacks.attack6 << " DMG-" << playerAttacks.damageAttack6 << "     Mana-" << playerAttacks.manaAttack6;
	cout << "\n\n (7) " << playerAttacks.attack7 << " DMG-" << playerAttacks.damageAttack7 << "     Mana-" << playerAttacks.manaAttack7;
	cout << "\n\n (8) Inventory";
	cout << "\n > ";
		if(player.mana < playerAttacks.manaAttack3){
		cout << "Not enough Mana!\n > ";
	}
	}

	// Attack 4 loop
	if(playerAttack == 4){
		ClearScreen();
		// Random monster attacks
		int RandAtk = rand() % 3;
		int RandDmg = rand() % 3;
		player.mana -= playerAttacks.manaAttack4;
				player.health -= monsterAttackDamage[RandDmg];
  levelMonster.monsterHealth = levelMonster.monsterHealth - playerAttacks.damageAttack4;
	cout << endl << endl<< levelMonster.monsterType << " used " << monsterAttack[RandAtk] << " and dealt " << monsterAttackDamage[RandDmg] << endl;
	cout << "HP: " << player.health << endl;
	cout << "\nMana: " << player.mana << endl;
	cout << "Monsters: " << levelMonster.monsterCount << endl;
	cout << "Monster health: " << levelMonster.monsterHealth;
	cout << "\n\n Monster type: " << levelMonster.monsterType;
	cout << "\n\n\nMAGIC ATTACKS\n";
	cout << "\n\n (1) " << playerAttacks.attack1 << " DMG-" << playerAttacks.damageAttack1 << "     Mana-" << playerAttacks.manaAttack1;
	cout << "\n\n (2) " << playerAttacks.attack2 << " DMG-" << playerAttacks.damageAttack2 << "     Mana-" << playerAttacks.manaAttack2;
	cout << "\n\n (3) " << playerAttacks.attack3 << " DMG-" << playerAttacks.damageAttack3 << "     Mana-" << playerAttacks.manaAttack3;
	cout << "\n\n (4) " << playerAttacks.attack4 << " DMG-" << playerAttacks.damageAttack4 << "     Mana-" << playerAttacks.manaAttack4;
	cout << "\n\n\nMELEE ATTACKS\n";
	cout << "\n\n (5) " << playerAttacks.attack5 << " DMG-" << playerAttacks.damageAttack5 << "     Mana-" << playerAttacks.manaAttack5;
	cout << "\n\n (6) " << playerAttacks.attack6 << " DMG-" << playerAttacks.damageAttack6 << "     Mana-" << playerAttacks.manaAttack6;
	cout << "\n\n (7) " << playerAttacks.attack7 << " DMG-" << playerAttacks.damageAttack7 << "     Mana-" << playerAttacks.manaAttack7;
	cout << "\n\n (8) Inventory";
	cout << "\n > ";
		if(player.mana < playerAttacks.manaAttack4){
		cout << "Not enough Mana!\n > ";
	}
	}

	// Attack 5 loop
	if(playerAttack == 5){
		ClearScreen();
		// Random monster attacks
		int RandAtk = rand() % 3;
		int RandDmg = rand() % 3;
		player.mana -= playerAttacks.manaAttack5;
		player.mana += 9;
				player.health = player.health - monsterAttackDamage[RandDmg];
  levelMonster.monsterHealth = levelMonster.monsterHealth - playerAttacks.damageAttack5;
	cout << endl << endl << levelMonster.monsterType << " used " << monsterAttack[RandAtk] << " and dealt " << monsterAttackDamage[RandDmg] << endl;
	cout << "HP: " << player.health << endl;
	cout << "\nMana: " << player.mana << endl;
	cout << "Monsters: " << levelMonster.monsterCount << endl;
	cout << "Monster health: " << levelMonster.monsterHealth;
	cout << "\n\n Monster type: " << levelMonster.monsterType;
	cout << "\n\n\nMAGIC ATTACKS\n";
	cout << "\n\n (1) " << playerAttacks.attack1 << " DMG-" << playerAttacks.damageAttack1 << "     Mana-" << playerAttacks.manaAttack1;
	cout << "\n\n (2) " << playerAttacks.attack2 << " DMG-" << playerAttacks.damageAttack2 << "     Mana-" << playerAttacks.manaAttack2;
	cout << "\n\n (3) " << playerAttacks.attack3 << " DMG-" << playerAttacks.damageAttack3 << "     Mana-" << playerAttacks.manaAttack3;
	cout << "\n\n (4) " << playerAttacks.attack4 << " DMG-" << playerAttacks.damageAttack4 << "     Mana-" << playerAttacks.manaAttack4;
	cout << "\n\n\nMELEE ATTACKS\n";
	cout << "\n\n (5) " << playerAttacks.attack5 << " DMG-" << playerAttacks.damageAttack5 << "     Mana-" << playerAttacks.manaAttack5;
	cout << "\n\n (6) " << playerAttacks.attack6 << " DMG-" << playerAttacks.damageAttack6 << "     Mana-" << playerAttacks.manaAttack6;
	cout << "\n\n (7) " << playerAttacks.attack7 << " DMG-" << playerAttacks.damageAttack7 << "     Mana-" << playerAttacks.manaAttack7;
	cout << "\n\n (8) Inventory";
	cout << "\n > ";

		if(player.mana < playerAttacks.manaAttack5)
		{

		cout << "Not enough Mana!\n > ";
	}
	}
		if(playerAttack == 6){
			ClearScreen();
		levelMonster.monsterHealth = levelMonster.monsterHealth - playerAttacks.damageAttack6;
		int RandAtk = rand() % 3;
		int RandDmg = rand() % 3;
		player.mana -= playerAttacks.manaAttack6;
		cout << endl << levelMonster.monsterType << " used " << monsterAttack[RandAtk] << " and dealt " << monsterAttackDamage[RandDmg] << endl;
		player.health = player.health - monsterAttackDamage[RandDmg];
	
			cout << "\nHP: " << player.health << endl;
			cout << "\nMana: " << player.mana << endl;
			cout << "\nMonsters: " << levelMonster.monsterCount << endl;
			cout << "Monster health: " << levelMonster.monsterHealth << endl;
	cout << "\n\n Monster type: " << levelMonster.monsterType;
	cout << "\n\n\nMAGIC ATTACKS\n";
	cout << "\n\n (1) " << playerAttacks.attack1 << " DMG-" << playerAttacks.damageAttack1 << "     Mana-" << playerAttacks.manaAttack1;
	cout << "\n\n (2) " << playerAttacks.attack2 << " DMG-" << playerAttacks.damageAttack2 << "     Mana-" << playerAttacks.manaAttack2;
	cout << "\n\n (3) " << playerAttacks.attack3 << " DMG-" << playerAttacks.damageAttack3 << "     Mana-" << playerAttacks.manaAttack3;
	cout << "\n\n (4) " << playerAttacks.attack4 << " DMG-" << playerAttacks.damageAttack4 << "     Mana-" << playerAttacks.manaAttack4;
	cout << "\n\n\nMELEE ATTACKS\n";
	cout << "\n\n (5) " << playerAttacks.attack5 << " DMG-" << playerAttacks.damageAttack5 << "     Mana-" << playerAttacks.manaAttack5;
	cout << "\n\n (6) " << playerAttacks.attack6 << " DMG-" << playerAttacks.damageAttack6 << "     Mana-" << playerAttacks.manaAttack6;
	cout << "\n\n (7) " << playerAttacks.attack7 << " DMG-" << playerAttacks.damageAttack7 << "     Mana-" << playerAttacks.manaAttack7;
	cout << "\n\n (8) Inventory";
	cout << "\n > ";

	if(player.mana < playerAttacks.manaAttack6){
		cout << "Not enough Mana!\n > ";
	}

	}

	if(playerAttack == 7){
		ClearScreen();
		levelMonster.monsterHealth = levelMonster.monsterHealth - playerAttacks.damageAttack7;
		int RandAtk = rand() % 3;
		int RandDmg = rand() % 3;
		player.mana -= playerAttacks.manaAttack7;
		cout <<  endl << endl << levelMonster.monsterType << " used " << monsterAttack[RandAtk] << " and dealt " << monsterAttackDamage[RandDmg] << endl;
		player.health = player.health - monsterAttackDamage[RandDmg];
	
			cout << "\nHP: " << player.health << endl;
			cout << "\nMana: " << player.mana << endl;
			cout << "\nMonsters: " << levelMonster.monsterCount << endl;
			cout << "Monster health: " << levelMonster.monsterHealth << endl;
	cout << "\n\n Monster type: " << levelMonster.monsterType;
	cout << "\n\n\nMAGIC ATTACKS\n";
	cout << "\n\n (1) " << playerAttacks.attack1 << " DMG-" << playerAttacks.damageAttack1 << "     Mana-" << playerAttacks.manaAttack1;
	cout << "\n\n (2) " << playerAttacks.attack2 << " DMG-" << playerAttacks.damageAttack2 << "     Mana-" << playerAttacks.manaAttack2;
	cout << "\n\n (3) " << playerAttacks.attack3 << " DMG-" << playerAttacks.damageAttack3 << "     Mana-" << playerAttacks.manaAttack3;
	cout << "\n\n (4) " << playerAttacks.attack4 << " DMG-" << playerAttacks.damageAttack4 << "     Mana-" << playerAttacks.manaAttack4;
	cout << "\n\n\nMELEE ATTACKS\n";
	cout << "\n\n (5) " << playerAttacks.attack5 << " DMG-" << playerAttacks.damageAttack5 << "     Mana-" << playerAttacks.manaAttack5;
	cout << "\n\n (6) " << playerAttacks.attack6 << " DMG-" << playerAttacks.damageAttack6 << "     Mana-" << playerAttacks.manaAttack6;
	cout << "\n\n (7) " << playerAttacks.attack7 << " DMG-" << playerAttacks.damageAttack7 << "     Mana-" << playerAttacks.manaAttack7;
	cout << "\n\n (8) Inventory";
	cout << "\n > ";

	if(player.mana < playerAttacks.manaAttack7){
		cout << "Not enough Mana!\n > ";
	}

	}

	// When player uses Inventory
	if(playerAttack == 8){
		ClearScreen();
		cout << "\n\n\n\n---Inventory---\n\n\n\n\n";
		cout << "(1) Item 1 " << playerInv.purchasedItem1 << " HP+ " << playerInv.HP1;
		cout << "\n\n(2) Item 2 " << playerInv.purchasedItem2 << " HP+ " << playerInv.HP2;
		cout << "\n\n(3) Item 3 " << playerInv.purchesedItem3 << " HP+ " << playerInv.HP3;
		cout << "\n\n(4) Power Up " << playerInv.PowerUp << "HP+ " << playerInv.HP4;
		cout << "\n Small potion count - " << playerInv.item1cnt << "\n Medium potion count - " << playerInv.item2cnt << "\n Large potion count - " << playerInv.item3cnt;
		cout << "\n\n(5) Back to battle";
		cout << "\n > ";
		cin >> playerAttack;
		if(playerAttack == 1){
			ClearScreen();
			player.health += playerInv.HP1;
	cout << "(1) Item 1 " << playerInv.purchasedItem1 << " HP+ " << playerInv.HP1;
		cout << "\n\n(2) Item 2 " << playerInv.purchasedItem2 << " HP+ " << playerInv.HP2;
		cout << "\n\n(3) Item 3 " << playerInv.purchesedItem3 << " HP+ " << playerInv.HP3;
		cout << "\n\n(4) Power Up " << playerInv.PowerUp << "HP+ " << playerInv.HP4;
		cout << "\n Small potion count - " << playerInv.item1cnt << "\n Medium potion count - " << playerInv.item2cnt << "\n Large potion count - " << playerInv.item3cnt;
		cout << "\n\n(5) Back to battle";
		cout << "\n > ";
		}
				if(playerAttack == 2){
					ClearScreen();
			player.health += playerInv.HP2;
		cout << "(1) Item 1 " << playerInv.purchasedItem1 << " HP+ " << playerInv.HP1;
		cout << "\n\n(2) Item 2 " << playerInv.purchasedItem2 << " HP+ " << playerInv.HP2;
		cout << "\n\n(3) Item 3 " << playerInv.purchesedItem3 << " HP+ " << playerInv.HP3;
		cout << "\n\n(4) Power Up " << playerInv.PowerUp << "HP+ " << playerInv.HP4;
		cout << "\n Small potion count - " << playerInv.item1cnt << "\n Medium potion count - " << playerInv.item2cnt << "\n Large potion count - " << playerInv.item3cnt;
		cout << "\n\n(5) Back to battle";
		cout << "\n > ";
		}
				if(playerAttack == 3){
					ClearScreen();
			player.health += playerInv.HP3;
	cout << "(1) Item 1 " << playerInv.purchasedItem1 << " HP+ " << playerInv.HP1;
		cout << "\n\n(2) Item 2 " << playerInv.purchasedItem2 << " HP+ " << playerInv.HP2;
		cout << "\n\n(3) Item 3 " << playerInv.purchesedItem3 << " HP+ " << playerInv.HP3;
		cout << "\n\n(4) Power Up " << playerInv.PowerUp << "HP+ " << playerInv.HP4;
		cout << "\n Small potion count - " << playerInv.item1cnt << "\n Medium potion count - " << playerInv.item2cnt << "\n Large potion count - " << playerInv.item3cnt;
		cout << "\n\n(5) Back to battle";
		cout << "\n > ";
		}
		if(playerAttack == 4){
			ClearScreen();
			if(PwrUpCnt < 0){
				cout << "Out of power ups!\n\n";
					cout << "(1) Item 1 " << playerInv.purchasedItem1 << " HP+ " << playerInv.HP1;
		cout << "\n\n(2) Item 2 " << playerInv.purchasedItem2 << " HP+ " << playerInv.HP2;
		cout << "\n\n(3) Item 3 " << playerInv.purchesedItem3 << " HP+ " << playerInv.HP3;
		cout << "\n\n(4) Power Up " << playerInv.PowerUp << "HP+ " << playerInv.HP4;
		cout << "\n Small potion count - " << playerInv.item1cnt << "\n Medium potion count - " << playerInv.item2cnt << "\n Large potion count - " << playerInv.item3cnt;
		cout << "\n\n(5) Back to battle";
		cout << "\n > ";
			}
			cout << "POWER UP ACTIVATED!\n";
			player.health += playerInv.HP4;
			player.mana += 200;
			PwrUpCnt -= 1;

			playerAttacks.attack1 = "Fire Punches";
	playerAttacks.attack2 = "Fire Walker";
	playerAttacks.attack3 = "Fire collumn";
	playerAttacks.attack4 = "Fire Beam";
 playerAttacks.attack5 = "Heavy Forearm Slash";
 playerAttacks.attack6 = "Air Slash";
 playerAttacks.attack7="Cosmic stab barrage";

 	playerAttacks.damageAttack1 = 20;
	playerAttacks.damageAttack2 = 35;
	playerAttacks.damageAttack3 = 40;
	playerAttacks.damageAttack4 = 50;
	playerAttacks.damageAttack5 = 10;
	playerAttacks.damageAttack6=20;
	playerAttacks.damageAttack7=35;
	// Mana
	playerAttacks.manaAttack1 = 20;
	playerAttacks.manaAttack2 = 35;
	playerAttacks.manaAttack3 = 45;
	playerAttacks.manaAttack4 = 50;
	playerAttacks.manaAttack5 = 0;
	playerAttacks.manaAttack6=0;
	playerAttacks.manaAttack7=0;

				cout << "(1) Item 1 " << playerInv.purchasedItem1 << " HP+ " << playerInv.HP1;
		cout << "\n\n(2) Item 2 " << playerInv.purchasedItem2 << " HP+ " << playerInv.HP2;
		cout << "\n\n(3) Item 3 " << playerInv.purchesedItem3 << " HP+ " << playerInv.HP3;
		cout << "\n\n(4) Power Up " << playerInv.PowerUp << "HP+ " << playerInv.HP4;
		cout << "\n Small potion count - " << playerInv.item1cnt << "\n Medium potion count - " << playerInv.item2cnt << "\n Large potion count - " << playerInv.item3cnt;
		cout << "\n\n(5) Back to battle";
		cout << "\n > ";
		}
				if(playerAttack == 5){
					ClearScreen();
				cout << "\nHP: " << player.health;
	cout << "Monsters: " << levelMonster.monsterCount;
	cout << "Monster HP: " << levelMonster.monsterHealth;
	cout << "\n\n Monster type: " << levelMonster.monsterType;
	cout << "\n\n\nMAGIC ATTACKS\n";
	cout << "\n\n (1) " << playerAttacks.attack1 << " DMG-" << playerAttacks.damageAttack1 << "     Mana-" << playerAttacks.manaAttack1;
	cout << "\n\n (2) " << playerAttacks.attack2 << " DMG-" << playerAttacks.damageAttack2 << "     Mana-" << playerAttacks.manaAttack2;
	cout << "\n\n (3) " << playerAttacks.attack3 << " DMG-" << playerAttacks.damageAttack3 << "     Mana-" << playerAttacks.manaAttack3;
	cout << "\n\n (4) " << playerAttacks.attack4 << " DMG-" << playerAttacks.damageAttack4 << "     Mana-" << playerAttacks.manaAttack4;
	cout << "\n\n\nMELEE ATTACKS\n";
	cout << "\n\n (5) " << playerAttacks.attack5 << " DMG-" << playerAttacks.damageAttack5 << "     Mana-" << playerAttacks.manaAttack5;
	cout << "\n\n (6) " << playerAttacks.attack6 << " DMG-" << playerAttacks.damageAttack6 << "     Mana-" << playerAttacks.manaAttack6;
	cout << "\n\n (7) " << playerAttacks.attack7 << " DMG-" << playerAttacks.damageAttack7 << "     Mana-" << playerAttacks.manaAttack7;
	cout << "\n\n (8) Inventory";
	cout << "\n > ";
			
		}

	}

	// When player wins
if(levelMonster.monsterHealth <= 0){
	ClearScreen();
		XP = LvlWin(XP);
		
		GameMenu();
	}
	else if(player.health <= 0){
		cout << 
		"\n\n▒█░░▒█ ▒█▀▀▀█ ▒█░▒█ 　 ▒█▀▀▄ ▀█▀ ▒█▀▀▀ ▒█▀▀▄\n"
		"▒█▄▄▄█ ▒█░░▒█ ▒█░▒█ 　 ▒█░▒█ ▒█░ ▒█▀▀▀ ▒█░▒█\n"
		"░░▒█░░ ▒█▄▄▄█ ░▀▄▄▀ 　 ▒█▄▄▀ ▄█▄ ▒█▄▄▄ ▒█▄▄▀\n";
		sleep(5);
		GameMenu();
	}

}

}






/*
Game menu includes options for the player to choose to play the game
*/

void GameMenu(){

	struct Attacks sword;
	struct Hero player;
	string gameMenuChoice;


		
		fstream stats;
		stats.open("stats.dat", ios::out);
string ascii =
"██╗░░░░░███████╗░██████╗░███████╗███╗░░██╗██████╗░\n"
"██║░░░░░██╔════╝██╔════╝░██╔════╝████╗░██║██╔══██╗\n"
"██║░░░░░█████╗░░██║░░██╗░█████╗░░██╔██╗██║██║░░██║\n"
"██║░░░░░██╔══╝░░██║░░╚██╗██╔══╝░░██║╚████║██║░░██║\n"
"███████╗███████╗╚██████╔╝███████╗██║░╚███║██████╔╝\n"
"╚══════╝╚══════╝░╚═════╝░╚══════╝╚═╝░░╚══╝╚═════╝░\n";

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << ascii;
	
	Lvl = LvlUp(XP, Lvl);
	stats << "\nXP: " << XP << endl;
	stats << "Level: " << Lvl << endl;
	cout << "Coins: " << coins << endl;
	cout << "XP: " << XP << endl;
	cout << "Level: " << Lvl << endl;
	cout << "(a) Play Level\n";
	cout << "(b) Potion Shop\n";
	cout << "(c) Change element\n";
	cout << "(d) Weapon Shop\n";
	cin >> gameMenuChoice;

	if(gameMenuChoice == "a"){
		ClearScreen();
		LevelStart(XP, Lvl);
	}

	if(gameMenuChoice == "b")
	{
		ClearScreen();
		PotionShop(coins);
	}

	if(gameMenuChoice == "c")
	{
		
		double sleep(0.5);
		ElementChange();

	}

	if(gameMenuChoice == "d")
	{
		double sleep(0.5);
			WeaponShop();

	
	}

}


void Login()
{
	string loginChoice;
	
	fstream login;
	login.open("login.dat", ios::out);
	cout << 
"██╗░░░░░░█████╗░░██████╗░██╗███╗░░██╗  ██╗\n"
"██║░░░░░██╔══██╗██╔════╝░██║████╗░██║  ╚═╝\n"
"██║░░░░░██║░░██║██║░░██╗░██║██╔██╗██║  ░░░\n"
"██║░░░░░██║░░██║██║░░╚██╗██║██║╚████║  ░░░\n"
"███████╗╚█████╔╝╚██████╔╝██║██║░╚███║  ██╗\n"
"╚══════╝░╚════╝░░╚═════╝░╚═╝╚═╝░░╚══╝  ╚═╝\n";
	cout << "\n\n\n\n\n\n\nUsername\n";
	cout << "\n > ";
	cin >> username;
	login << "username: " << username << endl;
	cout << "\n\n\n Password\n";
	cout << "\n > ";
	cin >> password;
	login << "Pass: " << password;
	login.close();
	cout << "loading...\n\n\n";
	cout << "(a) Start\n";
	cin >> loginChoice;
	
	if((loginChoice == "a") || (loginChoice == "A")){
		
		GameMenu();
	}
}

// StoryMode

void StoryMode(void)
{
	int storyModeChoice;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n-----------------Welcome to story mode!----------------\n\n";
	cout << "(1) Login\n";
	cin >> storyModeChoice;
	if(storyModeChoice == 1){
		sleep(1);
		ClearScreen();
		Login();
	}
}

// Credits
		void Credits(){
	
	int creditsChoice;
	cout << "\n\n\n\n\nExecutive Creator: Skyy Civil he is a furry\n\n";
  	cout << "\n\n\n\n\nCreator: Evan Handshuh\n\n"; // Stop changing these no
	cout << "(1) 	Back to menu\n";
	cout << "(2) 	Continue to story mode\n";
	cin >> creditsChoice;
	if(creditsChoice == 1){
		sleep(1);
		ClearScreen();
		Menu();
	}
	if (creditsChoice == 2){
		sleep(1);
		ClearScreen();
		StoryMode();
	}
}

// Main Menu

void Menu()
{
	string menuChoice;
	int ui= 0;
	while(ui == 0){
	cout << 
"███╗░░░███╗░█████╗░██████╗░███████╗  ░██████╗███████╗██╗░░░░░███████╗░█████╗░████████╗\n"
"████╗░████║██╔══██╗██╔══██╗██╔════╝  ██╔════╝██╔════╝██║░░░░░██╔════╝██╔══██╗╚══██╔══╝\n"
"██╔████╔██║██║░░██║██║░░██║█████╗░░  ╚█████╗░█████╗░░██║░░░░░█████╗░░██║░░╚═╝░░░██║░░░\n"
"██║╚██╔╝██║██║░░██║██║░░██║██╔══╝░░  ░╚═══██╗██╔══╝░░██║░░░░░██╔══╝░░██║░░██╗░░░██║░░░\n"
"██║░╚═╝░██║╚█████╔╝██████╔╝███████╗  ██████╔╝███████╗███████╗███████╗╚█████╔╝░░░██║░░░\n"
"╚═╝░░░░░╚═╝░╚════╝░╚═════╝░╚══════╝  ╚═════╝░╚══════╝╚══════╝╚══════╝░╚════╝░░░░╚═╝░░░\n";
	cout << "(a) Story Mode\n";
	cout << "(b) Credits\n";
	cin >> menuChoice;
	if((menuChoice == "a") || (menuChoice == "A"))
	{
		sleep(1);
		ClearScreen();
		StoryMode();
	}
	if((menuChoice == "b") || (menuChoice == "B"))
	{
		sleep(1);
		ClearScreen();
		Credits();
	}

	}
};

// ------------MAIN--------------- \\

int main()
{
	srand (time(NULL));
	cout << "Loading...";
	sleep(2);
	cout << "Starting!";
	sleep(1);
	ClearScreen(); // Clear screen to avoid any issues
	Menu(); // run Menu functions
}
