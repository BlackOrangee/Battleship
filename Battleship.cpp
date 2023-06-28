// Battleship.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

int ship_int = 254;
int point_int = 249;
char ship = ship_int;
char point = point_int;
char space = ' ';
char cross = 'X';

int f_style = 0;

int player_score = 0;
int pc_score = 0;

bool end_game = false;
#include "windows.h"
#include "Field.h"
#include "Dialog.h"
#include "Game.h"
#include "Logo.h"


int main()
{
	srand(time(NULL));
	Logo();

	int size = 12;
	char** field_1_Player = Create_Field(size);
	char** field_2_Enemy = Create_Field(size);
	char** field_Enemy = Create_Field(size);
	char** field_Enemy_Memory = Create_Field(size);

	

	int ship_count = 10;
	

	Ship* PC_Ships = Random_Ship_Placer(field_Enemy, size, ship_count);//pc ships
	int menu = Start_Menu();

	Ship* Players_Ships = Random_Ship_Placer(field_1_Player, size, ship_count);;

	//Ship* Players_Ships = Ship_Placer(field_1_Player, field_2_Enemy, size, ship_count);

	

	

	// player fire



	//Players_Turn(field_1_Player, field_2_Enemy, field_Enemy, field_Enemy_Memory, size, PC_Ships, ship_count);

	//Field_Print(field_1_Player, field_2_Enemy, size);

start:



	//Field_Print(field_Enemy, field_Enemy_Memory, size);
	Field_Print(field_1_Player, field_2_Enemy, size);

	if (end_game)
	{
		Win_Logo();
	}

	int input_size = 2;
	int* input = Input(input_size);

	if (Player_Fire(input, input_size, field_2_Enemy, field_Enemy, size))
	{
		player_score++;
		Check_Ship(field_Enemy, size, PC_Ships, ship_count);
		Pointer(field_2_Enemy, field_Enemy, size, PC_Ships, ship_count);

		if (Score_check(player_score))
		{
			goto start;
		}
		else
		{
			end_game = true;
		}
	}
	if (end_game)
	{
		goto start;
	}
	///////////////
	//goto start;//
	///////////////
	Field_Print(field_1_Player, field_2_Enemy, size);

	bool hit = false;

startpc:


	int pc_input_size = 2;
	int* pc_input = new int[input_size];
	pc_input = PC_II_Check_Ship(field_Enemy_Memory, size, Players_Ships, ship_count);


	if (pc_input[0] == 0 && pc_input[1] == 0)
	{
		int ran = rand() % 10 + 1;
		pc_input[0] = ran;
		ran = rand() % 10 + 1;
		pc_input[1] = ran;
	}
	
	int fire = PC_Fire(field_1_Player, field_Enemy_Memory, size, pc_input, pc_input_size);

	if (fire != 2)
	{
		Sleep(1000);
		Field_Print(field_1_Player, field_2_Enemy, size);
	}
	if (fire == 1)
	{
		pc_score++;
		Check_Ship(field_1_Player, size, Players_Ships, ship_count);
		Pointer(field_Enemy_Memory, field_1_Player, size, Players_Ships, ship_count);

		if (Score_check(player_score))
		{
			hit = true;
			goto startpc;
		}
		else
		{
			end_game = true;
		}
	}
	else if (fire == 2)
	{
		goto startpc;
	}

	goto start;


}