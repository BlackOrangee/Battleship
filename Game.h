#pragma once

using namespace std;

int Player_Fire(int* input, int& input_size, char** field_2_Enemy, char** field_Enemy, int& size)
{
	if (field_Enemy[input[0]][input[1]] == ship)
	{
		field_Enemy[input[0]][input[1]] = cross;
		field_2_Enemy[input[0]][input[1]] = cross;
		return 1;
	}

	if (field_Enemy[input[0]][input[1]] == space || field_Enemy[input[0]][input[1]] == point)
	{
		field_Enemy[input[0]][input[1]] = point;
		field_2_Enemy[input[0]][input[1]] = point;
		return 0;
	}

}

void PC_Fire_Check()
{

}

int PC_Fire(char** field_1_Player, char** field_Enemy_Memory, int& size)
{

	const int input_size = 2;
	int* input = new int[input_size];
	int ran = rand() % 10 + 1;
	input[0] = ran;
	ran = rand() % 10 + 1;
	input[1] = ran;

	if (field_1_Player[input[0]][input[1]] == space || field_1_Player[input[0]][input[1]] == point)
	{
		field_1_Player[input[0]][input[1]] = point;
		field_Enemy_Memory[input[0]][input[1]] = point;
		return 0;
	}
	else if (field_1_Player[input[0]][input[1]] == ship)
	{
		field_1_Player[input[0]][input[1]] = cross;
		field_Enemy_Memory[input[0]][input[1]] = cross;
		return 1;
	}
	
}

void Check_Ship(char** field_2_unvisible, int& size, Ship* ships, int& ships_count)
{
	

	for (int k = 0; k < ships_count; k++)
	{
		/*if (!ships[k].on_watter)
		{
			continue;
		}*/

		bool* on_watter = new bool[ships[k].ship_size];
		for (int i = 0; i < ships[k].ship_size; i++)
		{
			on_watter[i] = true;
		}

		switch (ships[k].orient)
		{
		case 1:
			for (int i = 0; i < ships[k].ship_size; i++)
			{
				if (field_2_unvisible[ships[k].number + i][ships[k].letter] == cross)
				{
					on_watter[i] = false;
				}
			}
			break;
		case 2:
			for (int i = 0; i < ships[k].ship_size; i++)
			{
				if (field_2_unvisible[ships[k].number][ships[k].letter + i] == cross)
				{
					on_watter[i] = false;
				}
			}
			break;
		default:
			break;
		}
		if (ships[k].ship_size == 4)
		{
			if (!on_watter[0] && !on_watter[1] && !on_watter[2] && !on_watter[3])
			{
				ships[k].on_watter = false;
			}
		}
		else if (ships[k].ship_size == 3)
		{
			if (!on_watter[0] && !on_watter[1] && !on_watter[2])
			{
				ships[k].on_watter = false;
			}
		}
		else if (ships[k].ship_size == 2)
		{
			if (!on_watter[0] && !on_watter[1])
			{
				ships[k].on_watter = false;
			}
		}
		else if (ships[k].ship_size == 1)
		{
			if (!on_watter[0])
			{
				ships[k].on_watter = false;
			}
		}
	}
}

void Pointer(char** field_1_visible, char** field_2_unvisible, int& size, Ship* ships, int& ships_count)
{
	

	for (int k = 0; k < ships_count; k++)
	{
		if (ships[k].on_watter)
		{
			continue;
		}
		switch (ships[k].orient)
		{
		case 1:
			for (int i = 0; i < ships[k].ship_size + 2; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (field_2_unvisible[ships[k].number + i - 1][ships[k].letter + j - 1] != cross)
					{
						field_2_unvisible[ships[k].number + i - 1][ships[k].letter + j - 1] = point;
						field_1_visible[ships[k].number + i - 1][ships[k].letter + j - 1] = point;
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < ships[k].ship_size + 2; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (field_2_unvisible[ships[k].number + j - 1][ships[k].letter + i - 1] != cross)
					{
						field_2_unvisible[ships[k].number + j - 1][ships[k].letter + i - 1] = point;
						field_1_visible[ships[k].number + j - 1][ships[k].letter + i - 1] = point;
					}
				}
			}
			break;
		default:
			break;
		}
	}
	
}

int Score_check(int& score)
{
	if (score == 20)// Player won
	{
		return 0;
	}
}
//
//void Players_Turn(char** field_1_Player, char** field_2_Enemy, char** field_Enemy, char** field_Enemy_Memory, int& size, Ship* PC_Ships, int& ship_count)
//{
//start:
//	Field_Print(field_1_Player, field_2_Enemy, size);
//	int input_size = 2;
//	int* input = Input(input_size);
//
//	if (Player_Fire(input, input_size, field_2_Enemy, field_Enemy, size))
//	{
//		player_score++;
//		Check_Ship(field_Enemy, size, PC_Ships, ship_count);
//		Pointer(field_2_Enemy, field_Enemy, size, PC_Ships, ship_count);
//
//		if (Score_check(player_score))
//		{
//			goto start;
//		}
//		else
//		{
//			Win_Logo();
//		}
//	}
//	//////////////
//	//goto start;///
//	//////////////
//}
//
//
//void PC_Turn(char** field_1_Player, char** field_2_Enemy, char** field_Enemy, char** field_Enemy_Memory, int& size, Ship* Players_Ships, int& ship_count)
//{
//startpc:
//
//	if (PC_Fire(field_1_Player, field_Enemy_Memory, size))
//	{
//		pc_score++;
//		Check_Ship(field_1_Player, size, Players_Ships, ship_count);
//		Pointer(field_Enemy_Memory, field_1_Player, size, Players_Ships, ship_count);
//
//		if (Score_check(player_score))
//		{
//			goto startpc;
//		}
//		else
//		{
//			Win_Logo();
//		}
//	}
//	
//}