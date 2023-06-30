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

int* PC_II_Check_Ship(char** field_visible, int& size, Ship* ships, int& ships_count)
{

	int* arr = new int[size];
	arr[0] = 0;
	arr[1] = 0;

	int ran;

	for (int k = 0; k < ships_count; k++)
	{
		if (ships[k].on_watter == false)
		{
			continue;
		}
		switch (ships[k].orient)
		{
		case 1:
			for (int i = 0; i < ships[k].ship_size; i++)
			{
				if (field_visible[ships[k].number + i][ships[k].letter] == cross && (field_visible[ships[k].number + i - 1][ships[k].letter] == cross || field_visible[ships[k].number + i + 1][ships[k].letter] == cross))
				{
					ran = rand() % 100;
					if (ran >= 50)
					{
						if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 12)
						{
							arr[0] = ships[k].number + i + 1;
							arr[1] = ships[k].letter;
						}
						else if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)//
						{
							arr[0] = ships[k].number + i - 1;
							arr[1] = ships[k].letter;
						}
						else
						{
							continue;
						}
						return arr;
					}
					else
					{
						if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)//
						{
							arr[0] = ships[k].number + i - 1;
							arr[1] = ships[k].letter;
						}
						else if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 12)
						{
							arr[0] = ships[k].number + i + 1;
							arr[1] = ships[k].letter;
						}
						else
						{
							continue;
						}
						return arr;
					}
				}
				else if (field_visible[ships[k].number + i][ships[k].letter] == cross)
				{
					ran = rand() % 100;
					if (ran <= difficulty)
					{
						ran = rand() % 100;
						if (ran >= 50)
						{
							if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 12)
							{
								arr[0] = ships[k].number + i + 1;
								arr[1] = ships[k].letter;
							}
							else if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)
							{
								arr[0] = ships[k].number + i - 1;
								arr[1] = ships[k].letter;
							}
							if (field_visible[ships[k].number + i][ships[k].letter + 1] == space && ships[k].letter + 1 != 12)
							{
								arr[0] = ships[k].number + i;
								arr[1] = ships[k].letter + 1;
							}
							else if (field_visible[ships[k].number + i][ships[k].letter - 1] == space && ships[k].letter - 1 != 0)
							{
								arr[0] = ships[k].number + i;
								arr[1] = ships[k].letter - 1;
							}
							else
							{
								continue;
							}
							return arr;
						}
						else
						{
							if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)
							{
								arr[0] = ships[k].number + i - 1;
								arr[1] = ships[k].letter;
							}
							else if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 12)
							{
								arr[0] = ships[k].number + i + 1;
								arr[1] = ships[k].letter;
							}
							if (field_visible[ships[k].number + i][ships[k].letter + 1] == space && ships[k].letter + 1 != 12)
							{
								arr[0] = ships[k].number + i;
								arr[1] = ships[k].letter + 1;
							}
							else if (field_visible[ships[k].number + i][ships[k].letter - 1] == space && ships[k].letter - 1 != 0)
							{
								arr[0] = ships[k].number + i;
								arr[1] = ships[k].letter - 1;
							}
							else
							{
								continue;
							}
							return arr;
						}
					}
					else
					{
						ran = rand() % 100;
						if (ran >= 50)
						{
							if (field_visible[ships[k].number + i][ships[k].letter + 1] == space && ships[k].letter + 1 != 12)
							{
								arr[0] = ships[k].number + i;
								arr[1] = ships[k].letter + 1;
							}
							else if (field_visible[ships[k].number + i][ships[k].letter - 1] == space && ships[k].letter - 1 != 0)
							{
								arr[0] = ships[k].number + i;
								arr[1] = ships[k].letter - 1;
							}
							else if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 12)
							{
								arr[0] = ships[k].number + i + 1;
								arr[1] = ships[k].letter;
							}
							else if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)
							{
								arr[0] = ships[k].number + i - 1;
								arr[1] = ships[k].letter;
							}
							else
							{
								continue;
							}
							return arr;
						}
						else
						{
							 if (field_visible[ships[k].number + i][ships[k].letter - 1] == space && ships[k].letter - 1 != 0)
							 {
								arr[0] = ships[k].number + i;
								arr[1] = ships[k].letter - 1;
							 }
							else if (field_visible[ships[k].number + i][ships[k].letter + 1] == space && ships[k].letter + 1 != 12)
							 {
								arr[0] = ships[k].number + i;
								arr[1] = ships[k].letter + 1;
							 }
							 else if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 12)
							 {
								arr[0] = ships[k].number + i + 1;
								arr[1] = ships[k].letter;
							 }
							else if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)
							{
								arr[0] = ships[k].number + i - 1;
								arr[1] = ships[k].letter;
							}
							else
							{
								continue;
							}
							return arr;
						}
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < ships[k].ship_size; i++)
			{
				if (field_visible[ships[k].number][ships[k].letter + i] == cross && (field_visible[ships[k].number][ships[k].letter + i - 1] == cross || field_visible[ships[k].number][ships[k].letter + i + 1] == cross))
				{
					ran = rand() % 100;
					if (ran >= 50)
					{
						if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 12)
						{
							arr[0] = ships[k].number;
							arr[1] = ships[k].letter + i + 1;
						}
						else if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
						{
							arr[0] = ships[k].number;
							arr[1] = ships[k].letter + i - 1;
						}
						else
						{
							continue;
						}
						return arr;
					}
					else
					{
						if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
						{
							arr[0] = ships[k].number;
							arr[1] = ships[k].letter + i - 1;
						}
						else if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 12)
						{
							 arr[0] = ships[k].number;
							 arr[1] = ships[k].letter + i + 1;
						}
						else
						{
							continue;
						}
						return arr;
					}
				}
				else if (field_visible[ships[k].number][ships[k].letter + i] == cross)
				{
					ran = rand() % 100;
					if (ran <= difficulty)
					{
						ran = rand() % 100;
						if (ran >= 50)
						{
							if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
							{
								arr[0] = ships[k].number;
								arr[1] = ships[k].letter + i - 1;
							}
							else if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 12)
							{
								arr[0] = ships[k].number;
								arr[1] = ships[k].letter + i + 1;
							}
							else if (field_visible[ships[k].number + 1][ships[k].letter + i] == space && ships[k].number + 1 != 12)
							{
								arr[0] = ships[k].number + 1;
								arr[1] = ships[k].letter + i;
							}
							else if (field_visible[ships[k].number - 1][ships[k].letter + i] == space && ships[k].number - 1 != 0)
							{
								arr[0] = ships[k].number - 1;
								arr[1] = ships[k].letter + i;
							}
							else
							{
								continue;
							}
							return arr;
						}
						else
						{
							if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 12)
							{
								arr[0] = ships[k].number;
								arr[1] = ships[k].letter + i + 1;
							}
							else if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
							{
								arr[0] = ships[k].number;
								arr[1] = ships[k].letter + i - 1;
							}
							else if (field_visible[ships[k].number + 1][ships[k].letter + i] == space && ships[k].number + 1 != 12)
							{
								arr[0] = ships[k].number + 1;
								arr[1] = ships[k].letter + i;
							}
							else if (field_visible[ships[k].number - 1][ships[k].letter + i] == space && ships[k].number - 1 != 0)
							{
								arr[0] = ships[k].number - 1;
								arr[1] = ships[k].letter + i;
							}
							else
							{
								continue;
							}
							return arr;
						}
					}
					else
					{
						ran = rand() % 100;
						if (ran >= 50)
						{
							if (field_visible[ships[k].number - 1][ships[k].letter + i] == space && ships[k].number - 1 != 0)
							{
								arr[0] = ships[k].number - 1;
								arr[1] = ships[k].letter + i;
							}
							else if (field_visible[ships[k].number + 1][ships[k].letter + i] == space && ships[k].number + 1 != 12)
							{
								arr[0] = ships[k].number + 1;
								arr[1] = ships[k].letter + i;
							}
							else if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
							{
								arr[0] = ships[k].number;
								arr[1] = ships[k].letter + i - 1;
							}
							else if(field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 12)
							{
								arr[0] = ships[k].number;
								arr[1] = ships[k].letter + i + 1;
							}
							else
							{
								continue;
							}
							return arr;
						}
						else
						{
							if (field_visible[ships[k].number - 1][ships[k].letter + i] == space && ships[k].number - 1 != 0)
							{
								arr[0] = ships[k].number - 1;
								arr[1] = ships[k].letter + i;
							}
							else if (field_visible[ships[k].number + 1][ships[k].letter + i] == space && ships[k].number + 1 != 12)
							{
								arr[0] = ships[k].number + 1;
								arr[1] = ships[k].letter + i;
							}
							else if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 12)
							{
								arr[0] = ships[k].number;
								arr[1] = ships[k].letter + i + 1;
							}
							else if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
							{
								arr[0] = ships[k].number;
								arr[1] = ships[k].letter + i - 1;
							}
							else 
							{
								continue;
							}
							return arr;
						}
					}
				}
			}
			break;
		default:
			break;
		}
	}
	return arr;
}

int PC_Fire(char** field_1_Player, char** field_Enemy_Memory, int& size, int* input, int input_size)
{
	if (field_1_Player[input[0]][input[1]] == space)
	{
		field_1_Player[input[0]][input[1]] = point;
		field_Enemy_Memory[input[0]][input[1]] = point;
		return 0;
	}
	else if (field_1_Player[input[0]][input[1]] == point || field_1_Player[input[0]][input[1]] == cross)
	{
		return 2;
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