// Battleship.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
int ship_int = 254;
int point_int = 249;
char ship = ship_int;
char point = point_int;
char space = ' ';
char cross = 'X';

int f_style = 0;

int player_score = 0;
int pc_score = 0;

#include "Field.h"
#include "Dialog.h"
#include "Game.h"
#include "Logo.h"
using namespace std;


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

	Ship* Rand_Placed = Random_Ship_Placer(field_Enemy, size, ship_count);//pc ships
	Ship* Players_Ships = Start_Menu(field_1_Player, field_2_Enemy, size, ship_count);

	
	// player fire
start:
	Field_Print(field_1_Player, field_2_Enemy, size);
	int input_size = 2;
	int* input = Input(input_size);

	if (Player_Fire(input, input_size, field_2_Enemy, field_Enemy, size))
	{
		player_score++;
		Check_Ship(field_Enemy, size, Rand_Placed, ship_count);
		Pointer(field_2_Enemy, field_Enemy, size, Rand_Placed, ship_count);

		if (Score_check(player_score))
		{
			Win_Logo();
		}
		
		goto start;
	}
	goto start;
	Field_Print(field_1_Player, field_2_Enemy, size);

	

}