/*
Skyy Civil has too many bugs
*/
//   LEGEND: TEXT ADVENTURE VERSION   \\
#include <stdlib.h>
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

	int playerAttack;
	char* mySecret = getenv("crtl+n");
int UpgradeNum;
/*
Declaring functions
*/
int main();
void Menu();
void Login();
void Credits(); 
void LevelStart();
void GameMenu();
void StoryMode();
void LvlUp();
int LvlWin();
int LvlUpReq();
int XpClear();
void PotionShop();
int AddCoins();
void ClearScreen();
void ElementChange();
void WeaponShop();
void Codex();
void DrawLine(int n, char symbol);
void drawLine(int n, char symbol);
void rules();
int Casino();
int CoinDrop();
void Upgrades();
void SecondCredits();
int Upgrade();
int WeaponStats();
int MonsterLevelUp();

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
struct Hero {
	string element;
	int health;
	int mana;
};

// Create shop choices




struct Attacks {
	string attack1;
	string attack2;
	string attack3;
	string attack4;
	string attack5;
	string attack6;
	string attack7;

	// Add melee attacks (attacks 5, 6, 7) \\
	Now I can put text here that wont effect the code.
	int damageAttack1;
	int damageAttack2;
	int damageAttack3;
	int damageAttack4;
	int damageAttack5;
	int damageAttack6;
	int damageAttack7;

	// Mana used per attack, attacks 5, 6, 7 are melee and do not use mana

	int manaAttack1 =10;
	int manaAttack2 =20;
	int manaAttack3 =30;
	int manaAttack4 =50;
	int manaAttack5 = 0;
	int manaAttack6 = 0;
	int manaAttack7 = 0;
};

struct Inventory {

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

struct PotionShop {
	string item1;
	string item2;
	string item3;
	int item1Price;
	int item2Price;
	int item3Price;
};

struct WeaponShop {
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


// Codex
struct CodexAscii{
	string ascii1;
	string ascii2;
	string ascii3;
	string ascii4;
	string ascii5;
	string ascii6;
	string ascii7;
	string ascii8;
	string ascii9;
	string ascii10;
};


// Elements
struct Element {
	string element1;
	string element2;
	string element3;
	string element4;
};

// Weapon stats
struct WeaponStats{
	string WeaponName;
	int damage;
	
	int power;
};


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
struct WeaponStats weaponStat;
struct WeaponStats weaponStatC;


// Ascii global constructors
struct CodexAscii HeroAscii;
struct CodexAscii MonsterAscii;
struct CodexAscii PotionAscii;
struct CodexAscii WeaponAscii;

// Effect on weapons



// Upgrading weapons

int Upgrade(){
weaponStat.damage += 100;
weaponStat.power += 100;
UpgradeNum += 1;
	
	return Upgrade();
}


// Clear screen, pretty pathetic eh?
void ClearScreen()
{
	int n;
	for (n = 0; n < 10; n++)
		printf("\n\n\n\n\n\n\n\n\n\n");
}





/*
Requirements for leveling Leveling up
*/

int LvlUpReq(int XP, int Lvl) {
	int LvlUpReq;
	LvlUpReq = 200;

	if (XP >= LvlUpReq) {
		LvlUpReq++;
	}

	return (LvlUpReq);
}

// Coin drops

int CoinDrop(){
coins += 100;
return coins;
}


// If player wins the Level
int LvlWin() {
	XP += 100;
	
	return XP;
	
}

// Level up

int LvlUp(int XP, int Lvl) {
	Lvl += XP / LvlUpReq(XP, Lvl);
	XP = 0;
	levelMonster.monsterHealth +=100;
	return Lvl;
	return levelMonster.monsterHealth;
	
}




/*
	Upgrades
*/

void Upgrades(){
	// Upgrades tab soon
	string op;
	string upgradeChoice;
	cout << 
"██╗░░░██╗██████╗░░██████╗░██████╗░░█████╗░██████╗░███████╗░██████╗\n"
"██║░░░██║██╔══██╗██╔════╝░██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝\n"
"██║░░░██║██████╔╝██║░░██╗░██████╔╝███████║██║░░██║█████╗░░╚█████╗░\n"
"██║░░░██║██╔═══╝░██║░░╚██╗██╔══██╗██╔══██║██║░░██║██╔══╝░░░╚═══██╗\n"
"╚██████╔╝██║░░░░░╚██████╔╝██║░░██║██║░░██║██████╔╝███████╗██████╔╝\n"
"░╚═════╝░╚═╝░░░░░╚═════╝░╚═╝░░╚═╝╚═╝░░░╚═╝╚═════╝░╚══════╝╚═════╝░\n\n\n";

	cout << "\n(a) Weapon upgrades\n\n";
	cout << "\n(b) Magic Upgrades\n\n";

	cin >> upgradeChoice;

	// if statements

	if(upgradeChoice == "a"){

		if (weapons.item1 == weapons.equippedItem1){
			cout << "Upgrade this weapon: " << weapons.equippedItem1 << "?" <<  endl;
			cout << "(a) Confirm\n(b) Cancel\n> ";
			cin >> op;
			if (op == "a"){
				cout << "";
			}
			if (op =="b")
			{
				cout << "WIP";
			}
			}

		if (weapons.item2 == weapons.equippedItem2){
			cout << "Upgrade this weapon: " << weapons.equippedItem2  << "?" << endl;

			}

		if (weapons.item3 == weapons.equippedItem3){
			cout << "Upgrade this weapon: " << weapons.equippedItem3  << "?" << endl;
			}
			if (weapons.item3 == weapons.equippedItem4){
			cout << "Upgrade this weapon: " << weapons.equippedItem4  << "?" << endl;

			}
			if (weapons.item3 == weapons.equippedItem5){
			cout << "Upgrade this weapon: " << weapons.equippedItem5  << "?" << endl;
			}
			if (weapons.item3 == weapons.equippedItem6){
			cout << "Upgrade this weapon: " << weapons.equippedItem6  << "?" << endl;

			}
		
		
	}

	if(upgradeChoice == "b"){

	}
	

}


int Casino()
{
	int ui = 100;
    
    int amount; // hold player's balance amount
    int bettingAmount; 
    int guess;
    int dice; // hold computer generated number
    char choice;
    string u;
 
    srand(time(0)); // "Seed" the random generator

    
    cout << "\n\n\n\t"
"░█████╗░░█████╗░░██████╗██╗███╗░░██╗░█████╗░\n"
"██╔══██╗██╔══██╗██╔════╝██║████╗░██║██╔══██╗\n"
"██║░░╚═╝███████║╚█████╗░██║██╔██╗██║██║░░██║\n"
"██║░░██╗██╔══██║░╚═══██╗██║██║╚████║██║░░██║\n"
"╚█████╔╝██║░░██║██████╔╝██║██║░╚███║╚█████╔╝\n"
"░╚════╝░╚═╝░░╚═╝╚═════╝░╚═╝╚═╝░░╚══╝░╚════╝░\n\n\n\n";
  
 cout << "(a) Play Casino\n";
 cout << "(b) Back to Story\n";
 cin >> u;
 if (u == "b"){
	 ClearScreen();
	 sleep(1);
	 StoryMode();
 }
 if (u == "a"){

 
 
    
cout << "Enter deposit amount\n\n";
    cin >> amount;
		while(ui == 100){
			if(amount > coins){
				cout << "Not enugh coins, try again: ";
				cin >> amount;
			}
    
    do
    { // This is a Do While loop (I hate these so much)
        system("cls"); // Just a basic system file declaration
         // Allows you to have the option to display the 
        cout << "\n\nYour current balance is " << amount << "\n"; // Shows player's coin balance
		
		// Get player's betting amount
        do
        {
            cout <<username <<", enter money to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        }while(bettingAmount > amount);
 
		// Get player's numbers
        do
        {
            cout << "Guess your number to bet between 1 to 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Please check the number!! should be between 1 to 10\n"
                    <<"\nRe-enter data`\n ";
        }while(guess <= 0 || guess > 10);
 
        dice = rand()%10 + 1;
    
        if(dice == guess)
        {
            cout << "\n\nGood Luck!! You won $" << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
						coins += bettingAmount;
        }
        else
        {
            cout << "Bad Luck this time !! You lost $ "<< bettingAmount << "\n";
            amount = amount - bettingAmount;
						coins -= bettingAmount;
        }
 
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<< username <<", You have $ " << amount << "\n";
        if(amount == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";		
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    
    cout << "\n\n\n";
    
    cout << "\n\nThanks for playing game. Your balance amount is $ " << amount << "\n\n";
    sleep(2);
    ClearScreen();
    StoryMode();
		}
    
 }
 return 0;
}
 

    






/*
Zeksus
Resinex
Caludor
WHisp
Tephus
Tekkus
Defus
Zekkor
*/

/*
		Codex
*/

void Codex(){
	int ui = 100;
	string CodexChoice;
	// WIP

	// Display Codex Menu
	cout << 
"░█████╗░░█████╗░██████╗░███████╗██╗░░██╗\n"
"██╔══██╗██╔══██╗██╔══██╗██╔════╝╚██╗██╔╝\n"
"██║░░╚═╝██║░░██║██║░░██║█████╗░░░╚███╔╝░\n"
"██║░░██╗██║░░██║██║░░██║██╔══╝░░░██╔██╗░\n"
"╚█████╔╝╚█████╔╝██████╔╝███████╗██╔╝╚██╗\n"
"░╚════╝░░╚════╝░╚═════╝░╚══════╝╚═╝░░╚═╝\n\n\n";
sleep(1.0);
ClearScreen();
	cout << "Welcome to the Codex! Here, you can view information on different monsters and items. You can also view tips on how to play the game!\n\n\n\n";

	cout << "(a) Monsters\n\n";
	cout << "(b) Weapons\n\n";
	cout << "(c) Potions\n\n";
	cout << "(d) Elements\n\n";
	cout << "(e) Tips\n\n";
	cout << "(f) Back to menu\n\n";
	cout << " > ";
	cin >> CodexChoice;
	while(ui == 100){
// If the player picks A on the main menu
	if(CodexChoice == "a"){
		ClearScreen();
		cout << "(a) View information\n";
		cout << "(b) Display\n";
		cout << "(c) Back\n";
		cin >> CodexChoice;

	if(CodexChoice == "a"){
		ClearScreen();
		// Show monsters
		// Monster names
		cout << "(a) Phynxis\n";
		cout << "(b) Majux\n";
		cout << "(c) Zeksus\n";
		cout << "(d) Resinex\n";
		cout << "(e) Caludor\n";
		cout << "(f) Whisp\n";
		cout << "(g) Tephus\n";
		cout << "(h) Tekkus\n";
		cout << "(i) Defus\n";
		cout << "(j) Zekkor\n";
		cout << "(1) Back\n";
		cin >> CodexChoice;


		if(CodexChoice == "b"){
			ClearScreen();
			cout << "Pick a monster to display(WIP)";
					cout << "(a) Phynxis\n";
		cout << "(b) Majux\n";
		cout << "(c) Zeksus\n";
		cout << "(d) Resinex\n";
		cout << "(e) Caludor\n";
		cout << "(f) Whisp\n";
		cout << "(g) Tephus\n";
		cout << "(h) Tekkus\n";
		cout << "(i) Defus\n";
		cout << "(j) Zekkor\n";
			cout << "(1) Back\n";
			cin >> CodexChoice;



						if(CodexChoice == "1"){
		cout << "(a) Monsters\n\n";
		cout << "(b) Weapons\n\n";
		cout << "(c) Potions\n\n";
		cout << "(d) Elements\n\n";
		cout << "(e) Tips\n\n";
		cout << "(f) Back to menu\n\n";
		cout << " > ";
			cin >> CodexChoice;
			}

		}
		if(CodexChoice == "1"){
			ClearScreen();
				cout << "(a) Monsters\n\n";
	cout << "(b) Weapons\n\n";
	cout << "(c) Potions\n\n";
	cout << "(d) Elements\n\n";
	cout << "(e) Tips\n\n";
	cout << "(f) Back to menu\n\n";
	cout << " > ";
		}
	}



	if(CodexChoice == "b"){
	// Display here (I forgot)

	}

	if(CodexChoice == "c"){
		ClearScreen();
			cout << "(a) Monsters\n\n";
	cout << "(b) Weapons\n\n";
	cout << "(c) Potions\n\n";
	cout << "(d) Elements\n\n";
	cout << "(e) Tips\n\n";
	cout << "(f) Back to menu\n\n";
	cout << " > ";
	}


	}




	if(CodexChoice == "b"){
		

				ClearScreen();
		cout << "(a) View information\n";
		cout << "(b) Display\n";
		cout << "(c) Back\n";

		if(CodexChoice == "a"){
			ClearScreen();
			// Info here
		}
		if(CodexChoice == "b"){
			ClearScreen();
			// Show art for the item
		}

		if(CodexChoice == "c"){
					ClearScreen();
			cout << "(a) Monsters\n\n";
	cout << "(b) Weapons\n\n";
	cout << "(c) Potions\n\n";
	cout << "(d) Elements\n\n";
	cout << "(e) Tips\n\n";
	cout << "(f) Back to menu\n\n";
	cout << " > ";
		}

	}

	if(CodexChoice == "c"){
		// stuff here
	}

	if(CodexChoice == "d"){
		// stuff here
	}

	if(CodexChoice == "e"){
		// stuff here
	}

	if(CodexChoice == "f"){
		ClearScreen();
		GameMenu();
	}
	
	}
}



/*
		Weapon Shoppe
*/

void WeaponShop() {


	int ui = 100;
	string weaponshopChoice;
	string EnteredPass;
	cout << 
"░██╗░░░░░░░██╗███████╗░█████╗░██████╗░░█████╗░███╗░░██╗░██████╗\n"
"░██║░░██╗░░██║██╔════╝██╔══██╗██╔══██╗██╔══██╗████╗░██║██╔════╝\n"
"░╚██╗████╗██╔╝█████╗░░███████║██████╔╝██║░░██║██╔██╗██║╚█████╗░\n"
"░░████╔═████║░██╔══╝░░██╔══██║██╔═══╝░██║░░██║██║╚████║░╚═══██╗\n"
"░░╚██╔╝░╚██╔╝░███████╗██║░░██║██║░░░░░╚█████╔╝██║░╚███║██████╔╝\n"
"░░░╚═╝░░░╚═╝░░╚══════╝╚═╝░░╚═╝╚═╝░░░░░░╚════╝░╚═╝░░╚══╝╚═════╝░\n\n\n";
	weapons.item1 = "Knife";
	weapons.item2 = "Sword";
	weapons.item3 = "Claymore";
	weapons.item4 = "Giant Hammer";
	weapons.item5 = "Dual Swords";
	weapons.item6 = "Dual Kamas";
	

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
				cout << "(7) Back to menu";

	cin >> weaponshopChoice;

	while (ui == 100) {

		if (weaponshopChoice == "1") {
			ClearScreen();
			cout << weapons.item1 << endl;
			cout << "Price: " << weapons.price1 << endl;
			cout << "(a) Confirm" << endl;
			cout << "(b) cancel" << endl;
			cin >> weaponshopChoice;
			if (weaponshopChoice == "b") {
				ClearScreen();
				cout << "(1) " << weapons.item1 << endl;
				cout << "(2) " << weapons.item2 << endl;
				cout << "(3) " << weapons.item3 << endl;
				cout << "(4) " << weapons.item4 << endl;
				cout << "(5) " << weapons.item5 << endl;
				cout << "(6) " << weapons.item6 << endl;
				cout << "(7) Back to menu";
				cin >> weaponshopChoice;
			}
			if (weaponshopChoice == "a") {
				ClearScreen();
				cout << "Enter your password: ";
				cin >> EnteredPass;
				if (EnteredPass == password) {
					
					coins -= weapons.price1;
					weapons.item1 = weapons.equippedItem1;
				}
				if (EnteredPass != password) {
					cout << "password invalid!";
					sleep(2);
					ClearScreen();
					cout << "(1) " << weapons.item1 << endl;
					cout << "(2) " << weapons.item2 << endl;
					cout << "(3) " << weapons.item3 << endl;
					cout << "(4) " << weapons.item4 << endl;
					cout << "(5) " << weapons.item5 << endl;
					cout << "(6) " << weapons.item6 << endl;
				cout << "(7) Back to menu";
					cin >> weaponshopChoice;
				}
			}
		}

		if (weaponshopChoice == "2") {
			ClearScreen();
			cout << weapons.item1 << endl;
			cout << "Price: " << weapons.price2 << endl;
			cout << "(a) Confirm" << endl;
			cout << "(b) cancel" << endl;
			cin >> weaponshopChoice;
			if (weaponshopChoice == "b") {
				ClearScreen();
				cout << "(1) " << weapons.item1 << endl;
				cout << "(2) " << weapons.item2 << endl;
				cout << "(3) " << weapons.item3 << endl;
				cout << "(4) " << weapons.item4 << endl;
				cout << "(5) " << weapons.item5 << endl;
				cout << "(6) " << weapons.item6 << endl;
				cout << "(7) Back to menu";
				cin >> weaponshopChoice;
			}
			if (weaponshopChoice == "a") {
				ClearScreen();
				cout << "Enter your password: ";
				cin >> EnteredPass;
				if (EnteredPass == password) {
						coins -= weapons.price2;
					weapons.item2 = weapons.equippedItem2;
				}
				if (EnteredPass != password) {
					cout << "password invalid!";
					sleep(2);
					ClearScreen();
					cout << "(1) " << weapons.item1 << endl;
					cout << "(2) " << weapons.item2 << endl;
					cout << "(3) " << weapons.item3 << endl;
					cout << "(4) " << weapons.item4 << endl;
					cout << "(5) " << weapons.item5 << endl;
					cout << "(6) " << weapons.item6 << endl;
				cout << "(7) Back to menu";
					cin >> weaponshopChoice;
				}
			}
		}

		if (weaponshopChoice == "3") {
			ClearScreen();
			cout << weapons.item3 << endl;
			cout << "Price: " << weapons.price1 << endl;
			cout << "(a) Confirm" << endl;
			cout << "(b) cancel" << endl;
			cin >> weaponshopChoice;
			if (weaponshopChoice == "b") {
				ClearScreen();
				cout << "(1) " << weapons.item1 << endl;
				cout << "(2) " << weapons.item2 << endl;
				cout << "(3) " << weapons.item3 << endl;
				cout << "(4) " << weapons.item4 << endl;
				cout << "(5) " << weapons.item5 << endl;
				cout << "(6) " << weapons.item6 << endl;
				cout << "(7) Back to menu";
				cin >> weaponshopChoice;
			}
			if (weaponshopChoice == "a") {
				ClearScreen();
				cout << "Enter your password: ";
				cin >> EnteredPass;
				if (EnteredPass == password) {

					coins -= weapons.price3;
					weapons.item3 = weapons.equippedItem3;
				}
				if (EnteredPass != password) {
					cout << "password invalid!";
					sleep(2);
					ClearScreen();
					cout << "(1) " << weapons.item1 << endl;
					cout << "(2) " << weapons.item2 << endl;
					cout << "(3) " << weapons.item3 << endl;
					cout << "(4) " << weapons.item4 << endl;
					cout << "(5) " << weapons.item5 << endl;
					cout << "(6) " << weapons.item6 << endl;
				cout << "(7) Back to menu";
					cin >> weaponshopChoice;
				}
			}
		}

		if (weaponshopChoice == "4") {
			ClearScreen();
			cout << weapons.item1 << endl;
			cout << "Price: " << weapons.price4 << endl;
			cout << "(a) Confirm" << endl;
			cout << "(b) cancel" << endl;
			cin >> weaponshopChoice;
			if (weaponshopChoice == "b") {
				ClearScreen();
				cout << "(1) " << weapons.item1 << endl;
				cout << "(2) " << weapons.item2 << endl;
				cout << "(3) " << weapons.item3 << endl;
				cout << "(4) " << weapons.item4 << endl;
				cout << "(5) " << weapons.item5 << endl;
				cout << "(6) " << weapons.item6 << endl;
				cout << "(7) Back to menu";
				cin >> weaponshopChoice;
			}
			if (weaponshopChoice == "a") {
				ClearScreen();
				cout << "Enter your password: ";
				cin >> EnteredPass;
				if (EnteredPass == password) {
					coins -= weapons.price4;
					weapons.item4 = weapons.equippedItem4;
				}
				if (EnteredPass != password) {
					cout << "password invalid!";
					sleep(2);
					ClearScreen();
					cout << "(1) " << weapons.item1 << endl;
					cout << "(2) " << weapons.item2 << endl;
					cout << "(3) " << weapons.item3 << endl;
					cout << "(4) " << weapons.item4 << endl;
					cout << "(5) " << weapons.item5 << endl;
					cout << "(6) " << weapons.item6 << endl;
				cout << "(7) Back to menu";
					cin >> weaponshopChoice;
				}
			}
		}

		if (weaponshopChoice == "5") {
			ClearScreen();
			cout << weapons.item5 << endl;
			cout << "Price: " << weapons.price5 << endl;
			cout << "(a) Confirm" << endl;
			cout << "(b) cancel" << endl;
			cin >> weaponshopChoice;
			if (weaponshopChoice == "b") {
				ClearScreen();
				cout << "(1) " << weapons.item1 << endl;
				cout << "(2) " << weapons.item2 << endl;
				cout << "(3) " << weapons.item3 << endl;
				cout << "(4) " << weapons.item4 << endl;
				cout << "(5) " << weapons.item5 << endl;
				cout << "(6) " << weapons.item6 << endl;
				cout << "(7) Back to menu";
				cin >> weaponshopChoice;
			}
			if (weaponshopChoice == "a") {
				ClearScreen();
				cout << "Enter your password: ";
				cin >> EnteredPass;
				if (EnteredPass == password) {
					coins -= weapons.price5;
					weapons.item5 = weapons.equippedItem5;
				}
				if (EnteredPass != password) {
					cout << "password invalid!";
					sleep(2);
					ClearScreen();
					cout << "(1) " << weapons.item1 << endl;
					cout << "(2) " << weapons.item2 << endl;
					cout << "(3) " << weapons.item3 << endl;
					cout << "(4) " << weapons.item4 << endl;
					cout << "(5) " << weapons.item5 << endl;
					cout << "(6) " << weapons.item6 << endl;
				cout << "(7) Back to menu";
					cin >> weaponshopChoice;
				}
			}
		}

		if (weaponshopChoice == "6") {
			ClearScreen();
			cout << weapons.item6 << endl;
			cout << "Price: " << weapons.price6 << endl;
			cout << "(a) Confirm" << endl;
			cout << "(b) cancel" << endl;
			cin >> weaponshopChoice;
			if (weaponshopChoice == "b") {
				ClearScreen();
				cout << "(1) " << weapons.item1 << endl;
				cout << "(2) " << weapons.item2 << endl;
				cout << "(3) " << weapons.item3 << endl;
				cout << "(4) " << weapons.item4 << endl;
				cout << "(5) " << weapons.item5 << endl;
				cout << "(6) " << weapons.item6 << endl;
			
				cout << "(7) Back to menu";
				cin >> weaponshopChoice;
			}
			if (weaponshopChoice == "a") {
				ClearScreen();
				cout << "Enter your password: ";
				cin >> EnteredPass;
				if (EnteredPass == password) {
					coins -= weapons.price6;
					weapons.item6 = weapons.equippedItem6;
				}
				if (EnteredPass != password) {
					cout << "password invalid!";
					sleep(2);
					ClearScreen();
					cout << "(1) " << weapons.item1 << endl;
					cout << "(2) " << weapons.item2 << endl;
					cout << "(3) " << weapons.item3 << endl;
					cout << "(4) " << weapons.item4 << endl;
					cout << "(5) " << weapons.item5 << endl;
					cout << "(6) " << weapons.item6 << endl;
				cout << "(7) Back to menu";
				
					cin >> weaponshopChoice;
				}
			}
		}



		if(weaponshopChoice == "7"){
			ClearScreen();
			GameMenu();
		}



	}
}




/*
Changing element
*/
void ElementChange() {
	int changeCnt;
	string elemChoice;
	elems.element1 = "Fire";
	elems.element2 = "Ice";
	elems.element3 = "Darkness";
	elems.element4 = "Earth";
	cout << "Choose an Element";
	cout << "\n(a) " << elems.element1 << endl;
	cout << "(b) " << elems.element2 << endl;
	cout << "(c) " << elems.element3 << endl;
	cout << "(d) " << elems.element4 << endl;
	cin >> elemChoice;
	if (elemChoice == "a") {
		player.element = "Fire";
		GameMenu();
	}

	if (elemChoice == "b") {
		player.element = "Ice";
		GameMenu();
	}

	if (elemChoice == "c") {
		player.element = "Darkness";
		GameMenu();
	}

	if (elemChoice == "d") {
		player.element = "Earth";
		GameMenu();
	}

}


/*
	Shoppe
*/

void PotionShop(int coins) {

	int ui = 1;
	int choice;
	elemShopChoice.item1 = "Small health potion";
	elemShopChoice.item1Price = 100;
	//elems
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
	while (ui == 1) {
		cout << "(1) " << elemShopChoice.item1 << endl;
		cout << "Price: " << elemShopChoice.item1Price << endl;
		cout << "(2) " << elemShopChoice.item2 << endl;
		cout << "Price: " << elemShopChoice.item2Price << endl;
		cout << "(3) " << elemShopChoice.item3 << endl;
		cout << "Price: " << elemShopChoice.item3Price << endl;
		cout << "(4) Back to game menu\n";
		cin >> choice;

		if (choice == 1) {
			ClearScreen();
			if (coins >= elemShopChoice.item1Price) {
				playerInv.purchasedItem1 = elemShopChoice.item1;
				playerInv.item1cnt += 1;
				coins -= elemShopChoice.item1Price;
				cout << "\n\nPurchase Complete\n\n";

			}
			if (coins < elemShopChoice.item1Price) {
				cout << "\nTry again\n > ";
			}

		}

		if (choice == 2) {
			ClearScreen();
			if (coins >= elemShopChoice.item2Price) {
				playerInv.purchasedItem1 = elemShopChoice.item2;
				playerInv.item2cnt += 1;
				coins -= elemShopChoice.item2Price;
				cout << "\nPurchase Complete\n";
			}
			if (coins < elemShopChoice.item2Price) {
				cout << "Try again\n > ";
			}

		}
		if (choice == 3) {
			ClearScreen();
			if (coins >= elemShopChoice.item3Price) {
				playerInv.purchasedItem1 = elemShopChoice.item3;
				playerInv.item3cnt += 1;
				coins -= elemShopChoice.item3Price;
				cout << "\n\nPurchase Complete!\n";

			}
			if (coins < elemShopChoice.item3Price) {
				cout << "Try again\n > ";
			}
		}
		if (choice == 4) {
			GameMenu();
		}

	}
}

/*
		The actual level starts here
*/


void LevelStart(int XP, int Lvl) {



	int PwrUpCnt = 1;

	// Inventory

	playerInv.PowerUp = "POWER UP!";
	playerInv.HP1 = 15;
	playerInv.HP2 = 30;
	playerInv.HP3 = 40;
	playerInv.HP4 = 100;


	// Player attacks and stats

	player.health = 200;
	player.mana = 150;

	if (player.element == "Fire") {
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

	if (player.element == "Ice") {
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

	if (player.element == "Darkness") {
		playerAttacks.attack1 = "Beam of Darkness";
		playerAttacks.attack2 = "Shadow Claw"; 
		playerAttacks.attack3 = "Black Hole";
		playerAttacks.attack4 = "Umbra Boom"; 

		playerAttacks.damageAttack1 = 20;
		playerAttacks.damageAttack2 = 35;
		playerAttacks.damageAttack3 = 40;
		playerAttacks.damageAttack4 = 60;

		playerAttacks.manaAttack1 = 10;
		playerAttacks.manaAttack2 = 25;
		playerAttacks.manaAttack3 = 45;
		playerAttacks.manaAttack4 = 100;
	}

	if (player.element == "Earth") {
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

	
		
	if (weapons.item1 == weapons.equippedItem1) {
		// Knife attacks
		playerAttacks.attack5 = "Basic slash";
		playerAttacks.attack6 = "Spin slash";
		playerAttacks.attack7 = "Slicing combo";
		
		// Damages per attack
		
		playerAttacks.damageAttack5 = 5;
		playerAttacks.damageAttack6 = 10;
		playerAttacks.damageAttack7 = 15;
	}

	if (weapons.item2 == weapons.equippedItem2) {
		// Sword attacks
		playerAttacks.attack5 = "Rush Pierce";
		playerAttacks.attack6 = "Core Slash";
		playerAttacks.attack7 = "Divine Burst";
				playerAttacks.damageAttack5 = 10;
		playerAttacks.damageAttack6 = 15;
		playerAttacks.damageAttack7 = 25;

		playerAttacks.manaAttack5 = 0;
		playerAttacks.manaAttack6 = 0;
		playerAttacks.manaAttack7 = 0;
	}
 
	if (weapons.item3 == weapons.equippedItem3) {
		playerAttacks.attack5 = "Heavy Slash";
		playerAttacks.attack6 = "Blade Slam";
		playerAttacks.attack7 = "Heavy Slam";
				playerAttacks.damageAttack5 = 10;
		playerAttacks.damageAttack6 = 20;
		playerAttacks.damageAttack7 = 35;
		playerAttacks.manaAttack5 = 0;
		playerAttacks.manaAttack6 = 0;
		playerAttacks.manaAttack7 = 0;
	}
	if (weapons.item4 == weapons.equippedItem4) {
		// Hammer attacks
		playerAttacks.attack5 = "Hammer Bash";
		playerAttacks.attack6 = "Spinning Hammer";
		playerAttacks.attack7 = "Slam Barrage";

				playerAttacks.damageAttack5 = 5;
		playerAttacks.damageAttack6 = 10;
		playerAttacks.damageAttack7 = 15;

			playerAttacks.manaAttack5 = 0;
		playerAttacks.manaAttack6 = 0;
		playerAttacks.manaAttack7 = 0;
	}

	if (weapons.item5 == weapons.equippedItem5) {
		// Dual swords attacks
		playerAttacks.attack5 = "Dual Sword Slash";
		playerAttacks.attack6 = "Dual Sword Spin";
		playerAttacks.attack7 = "Blazing Barrage";

playerAttacks.damageAttack5 = 15;
		playerAttacks.damageAttack6 = 20;
		playerAttacks.damageAttack7 = 35;
	
		playerAttacks.manaAttack5 = 0;
		playerAttacks.manaAttack6 = 0;
		playerAttacks.manaAttack7 = 0;
	}
	

	if (weapons.item6 == weapons.equippedItem6){
		// Dual Kamas attacks

		playerAttacks.attack5 = "Pull Slam";
		playerAttacks.attack6 = "Meteor Barrage";
		playerAttacks.attack7 = "Rapid Pull Slams";

	playerAttacks.damageAttack5 = 10;
	playerAttacks.damageAttack6 = 20;
	playerAttacks.damageAttack7 = 30;

			playerAttacks.manaAttack5 = 0;
		playerAttacks.manaAttack6 = 0;
		playerAttacks.manaAttack7 = 0;
	}
	 
	
	playerAttacks.attack5 = "Punch";
	playerAttacks.attack6 = "Punch Combo";
	playerAttacks.attack7 = "Heavy Punch Combo";
			playerAttacks.damageAttack5 = 3;
		playerAttacks.damageAttack6 = 7;
		playerAttacks.damageAttack7 = 10;

		playerAttacks.manaAttack5 = 0;
		playerAttacks.manaAttack6 = 0;
		playerAttacks.manaAttack7 = 0;

	// Monster attacks and stats

	levelMonster.monsterCount = 1;
	levelMonster.monsterType = "Phynxis";


	string monsterAttack[5] = { "Bash", "Spin Attack", "Heavy Punch", "Blind Rage", "Power Combo" };
	int monsterAttackDamage[8] = { 0, 10, 15, 40, 18, 5, 30, 50 };
	levelMonster.monsterHealth = 200 + LvlCount * 1.5;



	// -----------------MAKING ATTACKS---------------------\\
		cout << "HP: " << player.health;
		cout << "\nMANA: " << player.mana << endl;
	cout << "Monsters: " << levelMonster.monsterCount << endl;
	cout << "Monster HP: " << levelMonster.monsterHealth << endl;
	cout << "\n\n Monster type: " << levelMonster.monsterType << endl;
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

	while ((levelMonster.monsterCount = 1)) {
		cin >> playerAttack;
		// Attack 1 Loop
		if (playerAttack == 1 && player.mana >= playerAttacks.manaAttack1) {
			ClearScreen();
			levelMonster.monsterHealth = levelMonster.monsterHealth - playerAttacks.damageAttack1;
			int RandAtk = rand() % 5;
			int RandDmg = rand() % 8;
			player.mana -= playerAttacks.manaAttack1;
			ClearScreen();
			cout << "You used " << playerAttacks.attack1 << " And dealt " << playerAttacks.damageAttack1 << endl;
			sleep(1);
			ClearScreen();
			cout << endl << levelMonster.monsterType << " used " << monsterAttack[RandAtk] << " and dealt " << monsterAttackDamage[RandDmg] << endl;
			player.health = player.health - monsterAttackDamage[RandDmg];
			sleep(1);
			ClearScreen();
			cout << "HP: " << player.health << endl;
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

			

		}
		if (player.mana < playerAttacks.manaAttack1) {
			ClearScreen();
			sleep(1);
				cout << "Not enough Mana!\n > ";
				sleep(1);
				ClearScreen();
				cout << "HP: " << player.health << endl;
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
			}

		// Attack 2 loop
		if (playerAttack == 2 && player.mana >= playerAttacks.manaAttack2) {
			ClearScreen();
			int RandAtk = rand() % 5;
			int RandDmg = rand() % 8;
			player.mana -= playerAttacks.manaAttack2;
			ClearScreen();
			cout << "You used " << playerAttacks.attack2 << " And dealt " << playerAttacks.damageAttack2 << endl;
			sleep(1);
			ClearScreen();
			cout << endl << levelMonster.monsterType << " used " << monsterAttack[RandAtk] << " and dealt " << monsterAttackDamage[RandDmg] << endl;
			levelMonster.monsterHealth = levelMonster.monsterHealth - playerAttacks.damageAttack2;
			sleep(1);
			ClearScreen();
			cout << "HP: " << player.health << endl;
			cout << "Mana: " << player.mana << endl;
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
			
		}
		if (player.mana < playerAttacks.manaAttack2) {
			ClearScreen();
			sleep(1);
				cout << "Not enough Mana!\n > ";
				sleep(1);
				ClearScreen();
				cout << "HP: " << player.health << endl;
			cout << "Mana: " << player.mana << endl;
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
				
			}

		// Attack 3 loop

		if (playerAttack == 3 && player.mana >= playerAttacks.manaAttack3) {
			ClearScreen();
			int RandAtk = rand() % 5;
			int RandDmg = rand() % 8;
			player.mana -= playerAttacks.manaAttack3;
			ClearScreen();
			cout << "You used " << playerAttacks.attack3 << " And dealt " << playerAttacks.damageAttack3 << endl;
			sleep(1);
			ClearScreen();
			cout << endl << levelMonster.monsterType << " used " << monsterAttack[RandAtk] << " and dealt " << monsterAttackDamage[RandDmg] << endl;
			levelMonster.monsterHealth = levelMonster.monsterHealth - playerAttacks.damageAttack3;
			sleep(1);
			ClearScreen();
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
			
		}
if (player.mana < playerAttacks.manaAttack3) {
	ClearScreen();
	sleep(1);
				cout << "Not enough Mana!\n > ";
				sleep(1);
				ClearScreen();
				cout << "HP: " << player.health << endl;
			cout << "Mana: " << player.mana << endl;
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
			}
		// Attack 4 loop
		if (playerAttack == 4 && player.mana >= playerAttacks.manaAttack4) {
			ClearScreen();
			// Random monster attacks
			int RandAtk = rand() % 5;
			int RandDmg = rand() % 8;
			player.mana -= playerAttacks.manaAttack4;
			player.health -= monsterAttackDamage[RandDmg];
			ClearScreen();
			cout << "You used " << playerAttacks.attack4 << " And dealt " << playerAttacks.damageAttack4 << endl;
			sleep(2);
			ClearScreen();
			levelMonster.monsterHealth = levelMonster.monsterHealth - playerAttacks.damageAttack4;
			cout << endl << levelMonster.monsterType << " used " << monsterAttack[RandAtk] << " and dealt " << monsterAttackDamage[RandDmg] << endl;
			sleep(1);
			ClearScreen();
			cout << "HP: " << player.health << endl;
			cout << "Mana: " << player.mana << endl;
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
			
		}
			if (player.mana < playerAttacks.manaAttack4) {
				ClearScreen();
				sleep(1);
				cout << "Not enough Mana!\n > ";
				sleep(1);
				ClearScreen();
				cout << "HP: " << player.health << endl;
			cout << "Mana: " << player.mana << endl;
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
			}
		// Attack 5 loop
		if (playerAttack == 5) { // An If statement
			ClearScreen(); // clears the screen using the ClearScreen function up at line 194? i think, somewhere around there
			// Random monster attacks
			
			int RandAtk = rand() % 5; // randomizes monsters attack
			int RandDmg = rand() % 8; // randomizes monsters attack damage
			player.mana -= playerAttacks.manaAttack5; // player mana is depleted by the amoun of mana it COSTS to use the previous attack (attack 5)
			player.mana += 9; // Player mana goes up by 9 (because this is a melee attack)
			player.health = player.health - monsterAttackDamage[RandDmg]; // Player health is depleted from monsters attack
			levelMonster.monsterHealth = levelMonster.monsterHealth - playerAttacks.damageAttack5; // monster health is depleted by player's attack
			ClearScreen();
			cout << "You used " << playerAttacks.attack5 << " And dealt " << playerAttacks.damageAttack5 << endl;
			sleep(2);
			ClearScreen();
			cout << endl << levelMonster.monsterType << " used " << monsterAttack[RandAtk] << " and dealt " << monsterAttackDamage[RandDmg] << endl; // Shows what attack the monster used and how much damage it dealt (randoms are complicated so I wont teach you that yet)
			sleep(1);
			ClearScreen();
			cout << "HP: " << player.health << endl; // Shows player HP
			cout << "Mana: " << player.mana << endl; // Shows player Mana (energy)
			cout << "Monsters: " << levelMonster.monsterCount << endl; // Shows how many monsters are left
			cout << "Monster health: " << levelMonster.monsterHealth; // Shows monster health
			cout << "\n\n Monster type: " << levelMonster.monsterType; // Monster type

			// All the stuff below is just showing the attacks you can use
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
		
		if (playerAttack == 6) {
			ClearScreen();
			levelMonster.monsterHealth = levelMonster.monsterHealth - playerAttacks.damageAttack6;
			int RandAtk = rand() % 5;
			int RandDmg = rand() % 8;
			player.mana -= playerAttacks.manaAttack6;
			ClearScreen();
			cout << "You used " << playerAttacks.attack6 << " And dealt " << playerAttacks.damageAttack6 << endl;
			sleep(2);
			ClearScreen();
			cout << endl << levelMonster.monsterType << " used " << monsterAttack[RandAtk] << " and dealt " << monsterAttackDamage[RandDmg] << endl;
			player.health = player.health - monsterAttackDamage[RandDmg];
			sleep(1);
			ClearScreen();
			cout << "HP: " << player.health << endl;
			cout << "Mana: " << player.mana << endl;
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

			

		}
		

		if (playerAttack == 7) {
			ClearScreen();
			levelMonster.monsterHealth = levelMonster.monsterHealth - playerAttacks.damageAttack7;
			int RandAtk = rand() % 5;
			int RandDmg = rand() % 8;
			player.mana -= playerAttacks.manaAttack7;
			ClearScreen();
			cout << "You used " << playerAttacks.attack7 << " And dealt " << playerAttacks.damageAttack7 << endl;
			sleep(2);
			ClearScreen();
			cout << endl << levelMonster.monsterType << " used " << monsterAttack[RandAtk] << " and dealt " << monsterAttackDamage[RandDmg] << endl;
			player.health = player.health - monsterAttackDamage[RandDmg];
			sleep(1);
			ClearScreen();
			cout << "HP: " << player.health << endl;
			cout << "Mana: " << player.mana << endl;
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

			

		}

		// When player uses Inventory
		if (playerAttack == 8) {
			ClearScreen();
			cout << "\n\n\n\n---Inventory---\n\n\n\n\n";
			cout << "(1) Item 1 " << playerInv.purchasedItem1 << " HP+ " << playerInv.HP1;
			cout << "\n\n(2) Item 2 " << playerInv.purchasedItem2 << " HP+ " << playerInv.HP2;
			cout << "\n\n(3) Item 3 " << playerInv.purchesedItem3 << " HP+ " << playerInv.HP3;
			cout << "\n Small potion count - " << playerInv.item1cnt << "\n Medium potion count - " << playerInv.item2cnt << "\n Large potion count - " << playerInv.item3cnt;
			cout << "\n\n(4) Power Up " << playerInv.PowerUp << "HP+ " << playerInv.HP4;
			
			cout << "\n\n(5) Back to battle";
			cout << "\n > ";
			cin >> playerAttack;
			if (playerAttack == 1) {
				ClearScreen();
				player.health += playerInv.HP1;
				cout << "(1) Item 1 " << playerInv.purchasedItem1 << " HP+ " << playerInv.HP1;
				cout << "\n\n(2) Item 2 " << playerInv.purchasedItem2 << " HP+ " << playerInv.HP2;
				cout << "\n\n(3) Item 3 " << playerInv.purchesedItem3 << " HP+ " << playerInv.HP3;
				cout << "\n Small potion count - " << playerInv.item1cnt << "\n Medium potion count - " << playerInv.item2cnt << "\n Large potion count - " << playerInv.item3cnt;
				cout << "\n\n(4) Power Up " << playerInv.PowerUp << "HP+ " << playerInv.HP4;
				
				cout << "\n\n(5) Back to battle";
				cout << "\n > ";
			}
			if (playerAttack == 2) {
				ClearScreen();
				player.health += playerInv.HP2;
				cout << "(1) Item 1 " << playerInv.purchasedItem1 << " HP+ " << playerInv.HP1;
				cout << "\n\n(2) Item 2 " << playerInv.purchasedItem2 << " HP+ " << playerInv.HP2;
				cout << "\n\n(3) Item 3 " << playerInv.purchesedItem3 << " HP+ " << playerInv.HP3;
				cout << "\n Small potion count - " << playerInv.item1cnt << "\n Medium potion count - " << playerInv.item2cnt << "\n Large potion count - " << playerInv.item3cnt;
				cout << "\n\n(4) Power Up " << playerInv.PowerUp << "HP+ " << playerInv.HP4;
				
				cout << "\n\n(5) Back to battle";
				cout << "\n > ";
			}
			if (playerAttack == 3) {
				ClearScreen();
				player.health += playerInv.HP3;
				cout << "(1) Item 1 " << playerInv.purchasedItem1 << " HP+ " << playerInv.HP1;
				cout << "\n\n(2) Item 2 " << playerInv.purchasedItem2 << " HP+ " << playerInv.HP2;
				cout << "\n\n(3) Item 3 " << playerInv.purchesedItem3 << " HP+ " << playerInv.HP3;
				cout << "\n Small potion count - " << playerInv.item1cnt << "\n Medium potion count - " << playerInv.item2cnt << "\n Large potion count - " << playerInv.item3cnt;
				cout << "\n\n(4) Power Up " << playerInv.PowerUp << "HP+ " << playerInv.HP4;
				
				cout << "\n\n(5) Back to battle";
				cout << "\n > ";
			}
			if (playerAttack == 4) {
				ClearScreen();
				if (PwrUpCnt < 0) {
					cout << "Out of power ups!\n\n";
					cout << "(1) Item 1 " << playerInv.purchasedItem1 << " HP+ " << playerInv.HP1;
					cout << "\n\n(2) Item 2 " << playerInv.purchasedItem2 << " HP+ " << playerInv.HP2;
					cout << "\n\n(3) Item 3 " << playerInv.purchesedItem3 << " HP+ " << playerInv.HP3;
					cout << "\n Small potion count - " << playerInv.item1cnt << "\n Medium potion count - " << playerInv.item2cnt << "\n Large potion count - " << playerInv.item3cnt;
					cout << "\n\n(4) Power Up " << playerInv.PowerUp << "HP+ " << playerInv.HP4;
					
					cout << "\n\n(5) Back to battle";
					cout << "\n > ";
				}
				cout << "POWER UP ACTIVATED!\n";
				player.health += playerInv.HP4;
				player.mana += 200;
				PwrUpCnt -= 1;

				playerAttacks.attack1 = "Cosmic Slam";
				playerAttacks.attack2 = "Cosmic Spiral";
				playerAttacks.attack3 = "Cosmic Beam";
				playerAttacks.attack4 = "Cosmic Burst";
				playerAttacks.attack5 = "Heavy Forearm Slash";
				playerAttacks.attack6 = "Air Slash";
				playerAttacks.attack7 = "Cosmic stab barrage";

				playerAttacks.damageAttack1 = 20;
				playerAttacks.damageAttack2 = 35;
				playerAttacks.damageAttack3 = 40;
				playerAttacks.damageAttack4 = 50;
				playerAttacks.damageAttack5 = 10;
				playerAttacks.damageAttack6 = 20;
				playerAttacks.damageAttack7 = 35;
				// Mana
				playerAttacks.manaAttack1 = 20;
				playerAttacks.manaAttack2 = 35;
				playerAttacks.manaAttack3 = 45;
				playerAttacks.manaAttack4 = 50;
				playerAttacks.manaAttack5 = 0;
				playerAttacks.manaAttack6 = 0;
				playerAttacks.manaAttack7 = 0;

				cout << "(1) Item 1 " << playerInv.purchasedItem1 << " HP+ " << playerInv.HP1;
				cout << "\n\n(2) Item 2 " << playerInv.purchasedItem2 << " HP+ " << playerInv.HP2;
				cout << "\n\n(3) Item 3 " << playerInv.purchesedItem3 << " HP+ " << playerInv.HP3;
				cout << "\n\n(4) Power Up " << playerInv.PowerUp << "HP+ " << playerInv.HP4;
				
				cout << "\n\n(5) Back to battle";
				cout << "\n > ";
			}
			if (playerAttack == 5) {
				ClearScreen();
				cout << "\nHP: " << player.health << endl;
				cout << "Monsters: " << levelMonster.monsterCount << endl;
				cout << "Monster HP: " << levelMonster.monsterHealth << endl;
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
		if (levelMonster.monsterHealth <= 0) {
			
			ClearScreen();
			cout <<
"█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████\n"
"█░░░░░░░░██░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░██░░░░░░████░░░░░░██████████░░░░░░█░░░░░░░░░░█░░░░░░██████████░░░░░░█░░░░░░█\n"
"█░░▄▀▄▀░░██░░▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀░░████░░▄▀░░██████████░░▄▀░░█░░▄▀▄▀▄▀░░█░░▄▀░░░░░░░░░░██░░▄▀░░█░░▄▀░░█\n"
"█░░░░▄▀░░██░░▄▀░░░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░████░░▄▀░░██████████░░▄▀░░█░░░░▄▀░░░░█░░▄▀▄▀▄▀▄▀▄▀░░██░░▄▀░░█░░▄▀░░█\n"
"███░░▄▀▄▀░░▄▀▄▀░░███░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░████░░▄▀░░██████████░░▄▀░░███░░▄▀░░███░░▄▀░░░░░░▄▀░░██░░▄▀░░█░░▄▀░░█\n"
"███░░░░▄▀▄▀▄▀░░░░███░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░████░░▄▀░░██░░░░░░██░░▄▀░░███░░▄▀░░███░░▄▀░░██░░▄▀░░██░░▄▀░░█░░▄▀░░█\n"
"█████░░░░▄▀░░░░█████░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░████░░▄▀░░██░░▄▀░░██░░▄▀░░███░░▄▀░░███░░▄▀░░██░░▄▀░░██░░▄▀░░█░░▄▀░░█\n"
"███████░░▄▀░░███████░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░████░░▄▀░░██░░▄▀░░██░░▄▀░░███░░▄▀░░███░░▄▀░░██░░▄▀░░██░░▄▀░░█░░░░░░█\n"
"███████░░▄▀░░███████░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░████░░▄▀░░░░░░▄▀░░░░░░▄▀░░███░░▄▀░░███░░▄▀░░██░░▄▀░░░░░░▄▀░░████████\n"
"███████░░▄▀░░███████░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░████░░▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀░░█░░░░▄▀░░░░█░░▄▀░░██░░▄▀▄▀▄▀▄▀▄▀░░█░░░░░░█\n"
"███████░░▄▀░░███████░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░████░░▄▀░░░░░░▄▀░░░░░░▄▀░░█░░▄▀▄▀▄▀░░█░░▄▀░░██░░░░░░░░░░▄▀░░█░░▄▀░░█\n"
"███████░░░░░░███████░░░░░░░░░░░░░░█░░░░░░░░░░░░░░████░░░░░░██░░░░░░██░░░░░░█░░░░░░░░░░█░░░░░░██████████░░░░░░█░░░░░░█\n"
"█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████\n";
			sleep(3);
			ClearScreen();
			XP = LvlWin();
			coins = CoinDrop();

			GameMenu();
		}
		else if (player.health <= 0) {
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

void GameMenu() {

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
	
	cout << ascii << endl;
	

	Lvl = LvlUp(XP, Lvl);
	cout << username << endl;
	stats << "\nXP: " << XP << endl;
	stats << "Level: " << Lvl << endl;
	cout << "Coins: " << coins << endl;
	cout << "XP: " << XP << endl;
	cout << "Level: " << Lvl << endl;
	cout << "(a) Play Level\n";
	cout << "(b) Potion Shop\n";
	cout << "(c) Change element\n";
	cout << "(d) Weapon Shop\n";
	cout << "(e) Codex(WIP)\n";
	cout << "(f) Casino(NEW!)\n";
	cout << "(g) Upgrades(WIP)\n";
	cout << "(h) Credits\n";
	cout << " > ";
	cin >> gameMenuChoice;

	if (gameMenuChoice == "a") {
		
		ClearScreen();
		LevelStart(XP, Lvl);
	}

	if (gameMenuChoice == "b")
	{
		ClearScreen();
		PotionShop(coins);
	}

	if (gameMenuChoice == "c")
	{

		double sleep(0.5);
		ClearScreen();
		ElementChange();

	}

	if (gameMenuChoice == "d")
	{
		double sleep(0.5);
		ClearScreen();
		WeaponShop();


	}
	if (gameMenuChoice == "e")
	{
		double sleep(0.5);
		ClearScreen();
		Codex();
	}

	if(gameMenuChoice == "f"){
		double sleep(0.5);
		ClearScreen();
		Casino();
	}

	if(gameMenuChoice == "g"){
		double sleep(0.5);
		ClearScreen();
		Upgrades();
	}

	if(gameMenuChoice == "h"){
		double sleep(0.5);
		ClearScreen();
		SecondCredits();
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
	sleep(1);
	ClearScreen();
	cout << "(a) Start\n";
	cin >> loginChoice;

	if ((loginChoice == "a") || (loginChoice == "A")) {
		ClearScreen();
		ElementChange();
	}
}
// Second set of credits
void SecondCredits(){
int creditsChoice;
	cout << "\n\n\n\n\nCreator: Skyy \n\n";
	cout << "\nConcept Creator and Writer: Evan \n\n"; 
  cout << "\n\n\nMusic Writer: Temmiecat https://www.youtube.com/channel/UC59SDpvh9Zft8Vy-KDBJzew \n\n";
  cout << "\n\n\nSpecial thanks to: \n                   Conner  \n               Kayleigh  \n\n";
  	cout << "\nCaffeine: mccafferty \n\n";
	cout << "(1) 	Back to Mode Select\n";
	cout << "(2) 	Continue Game\n";
	cin >> creditsChoice;
	if (creditsChoice == 1) {
		sleep(1);
		ClearScreen();
		Menu();
	}
	if (creditsChoice == 2) {
		sleep(1);
		ClearScreen();
		GameMenu();
	}
}

// StoryMode

void StoryMode()
{
	int storyModeChoice;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n-----------------Welcome to story mode!----------------\n\n";
	cout << "(1) Login\n";
	cin >> storyModeChoice;
	if (storyModeChoice == 1) {
		sleep(1);
		ClearScreen();
		Login();
	}
}


// Credits
void Credits() {

	int creditsChoice;
	cout << "\n\n\n\n\nCreator: Skyy Civil\n\n";
	cout << "\nConcept Creator and Writer: Evan \n\n";
  cout << "\n\n\nMusic Writer: Temmiecat https://www.youtube.com/channel/UC59SDpvh9Zft8Vy-KDBJzew\n\n";
  cout << "\n\n\nSpecial thanks to: \n                   Conner   \n               Kayleigh  \n                     Liam \n";
  	cout << "\nCaffeine: Coffee \n\n";
	cout << "(1) 	Back to menu\n";
	cout << "(2) 	Continue to story mode\n";
	cin >> creditsChoice;
	if (creditsChoice == 1) {
		sleep(1);
		ClearScreen();
		Menu();
	}
	if (creditsChoice == 2) {
		sleep(1);
		ClearScreen();
		StoryMode();
	}
}

// Main Menu

void Menu()
{
	string menuChoice;
	int ui = 0;
	while (ui == 0) {
		
		
		cout <<

			"███╗░░░███╗░█████╗░██████╗░███████╗  ░██████╗███████╗██╗░░░░░███████╗░█████╗░████████╗\n"
			"████╗░████║██╔══██╗██╔══██╗██╔════╝  ██╔════╝██╔════╝██║░░░░░██╔════╝██╔══██╗╚══██╔══╝\n"
			"██╔████╔██║██║░░██║██║░░██║█████╗░░  ╚█████╗░█████╗░░██║░░░░░█████╗░░██║░░╚═╝░░░██║░░░\n"
			"██║╚██╔╝██║██║░░██║██║░░██║██╔══╝░░  ░╚═══██╗██╔══╝░░██║░░░░░██╔══╝░░██║░░██╗░░░██║░░░\n"
			"██║░╚═╝░██║╚█████╔╝██████╔╝███████╗  ██████╔╝███████╗███████╗███████╗╚█████╔╝░░░██║░░░\n"
			"╚═╝░░░░░╚═╝░╚════╝░╚═════╝░╚══════╝  ╚═════╝░╚══════╝╚══════╝╚══════╝░╚════╝░░░░╚═╝░░░\n";
			
		cout << "(a) Story Mode\n";
		cout << "(b) Credits\n";
		cout << "\n(c) Exit\n>";
		cin >> menuChoice;
		if ((menuChoice == "a") || (menuChoice == "A"))
		{
			sleep(1);
			ClearScreen();
			StoryMode();
		}
		if ((menuChoice == "b") || (menuChoice == "B"))
		{
			sleep(1);
			ClearScreen();
			Credits();
		}
		if (menuChoice == "c"){
			sleep(1);
			ClearScreen();
			cout << "Game Exited\n";
			double sleep(0.5);
			ClearScreen();

			return;
		}

	}
};

// ------------MAIN--------------- \\

int main()
{
	srand(time(NULL));
	cout << "Loading...";
	double sleep(0.5);
	cout << "Starting!";
	ClearScreen(); // Clear screen to avoid any issues with spacing...
	Menu(); // run Menu functions
}
