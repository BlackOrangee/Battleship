// Battleship.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

#include "Var.h"
#include "windows.h"
#include "Field.h"
#include "Dialog.h"
#include "Game.h"
#include "Logo.h"


int main()
{
restart:

	srand(time(NULL));
	Logo();

	int size = 12;
	char** field_1_Player = Create_Field(size);
	char** field_2_Enemy = Create_Field(size);
	char** field_Enemy = Create_Field(size);
	char** field_Enemy_Memory = Create_Field(size);

	int ship_count = 10;

	Ship* PC_Ships = Random_Ship_Placer(field_Enemy, size, ship_count);//pc ships
	
	Start_Menu();
	Ship* Players_Ships = NULL;

	if (filing == 1)
	{
		Players_Ships = Random_Ship_Placer(field_1_Player, size, ship_count);
	}
	else if (filing == 2)
	{
		
		Players_Ships = Ship_Placer(field_1_Player, field_2_Enemy, size, ship_count);
	}

	//Field_Print(field_Enemy, field_Enemy_Memory, size);
start:
	if (end_game)
	{
		int menu = Win_Logo();
		if (menu == 1)
		{
			player_score = 0;
			pc_score = 0;
			end_game = false;
			goto restart;
		}
		else
		{
			return 0;
		}
	}
	Player_Turn(field_1_Player, field_2_Enemy, field_Enemy, size, Players_Ships, PC_Ships, ship_count);

	if (end_game)
	{
		goto start;
	}
	
	PC_Turn(field_1_Player, field_2_Enemy, field_Enemy_Memory, size, Players_Ships, PC_Ships, ship_count);
	
	goto start;
}