#pragma once
using namespace std;

// This function represents the AI logic to check the ship's status and make the next move.
void PC_AI_Check_Ship(char** field_visible, int& size, Ship* ships, int& ships_count, int* arr, int& arr_size)
{
	
	int ran;

	for (int k = 0; k < ships_count; k++)
	{
		if (ships[k].on_watter == false)
		{
			continue;
		}
		if (ships[k].orient == 1) // Vertical orientation
		{
			for (int i = 0; i < ships[k].ship_size; i++)
			{
				if (field_visible[ships[k].number + i][ships[k].letter] == cross
					&& (field_visible[ships[k].number + i - 1][ships[k].letter] == cross
						|| field_visible[ships[k].number + i + 1][ships[k].letter] == cross))
				{
					ran = rand() % 100;
					if (ran >= 50)
					{
						if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 11)
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
						break;
					}
					else
					{
						if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)//
						{
							arr[0] = ships[k].number + i - 1;
							arr[1] = ships[k].letter;
						}
						else if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 11)
						{
							arr[0] = ships[k].number + i + 1;
							arr[1] = ships[k].letter;
						}
						else
						{
							continue;
						}
						break;
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
							if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 11)
							{
								arr[0] = ships[k].number + i + 1;
								arr[1] = ships[k].letter;
							}
							else if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)
							{
								arr[0] = ships[k].number + i - 1;
								arr[1] = ships[k].letter;
							}
							if (field_visible[ships[k].number + i][ships[k].letter + 1] == space && ships[k].letter + 1 != 11)
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
							break;
						}
						else
						{
							if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)
							{
								arr[0] = ships[k].number + i - 1;
								arr[1] = ships[k].letter;
							}
							else if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 11)
							{
								arr[0] = ships[k].number + i + 1;
								arr[1] = ships[k].letter;
							}
							if (field_visible[ships[k].number + i][ships[k].letter + 1] == space && ships[k].letter + 1 != 11)
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
							break;
						}
					}
					else
					{
						ran = rand() % 100;
						if (ran >= 50)
						{
							if (field_visible[ships[k].number + i][ships[k].letter + 1] == space && ships[k].letter + 1 != 11)
							{
								arr[0] = ships[k].number + i;
								arr[1] = ships[k].letter + 1;
							}
							else if (field_visible[ships[k].number + i][ships[k].letter - 1] == space && ships[k].letter - 1 != 0)
							{
								arr[0] = ships[k].number + i;
								arr[1] = ships[k].letter - 1;
							}
							else if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 11)
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
							break;
						}
						else
						{
							if (field_visible[ships[k].number + i][ships[k].letter - 1] == space && ships[k].letter - 1 != 0)
							{
								arr[0] = ships[k].number + i;
								arr[1] = ships[k].letter - 1;
							}
							else if (field_visible[ships[k].number + i][ships[k].letter + 1] == space && ships[k].letter + 1 != 11)
							{
								arr[0] = ships[k].number + i;
								arr[1] = ships[k].letter + 1;
							}
							else if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 11)
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
							break;
						}
					}
				}
			}
		}
		else if (ships[k].orient == 2)
		{
			for (int i = 0; i < ships[k].ship_size; i++)
			{
				if (field_visible[ships[k].number][ships[k].letter + i] == cross
					&& (field_visible[ships[k].number][ships[k].letter + i - 1] == cross
						|| field_visible[ships[k].number][ships[k].letter + i + 1] == cross))
				{
					ran = rand() % 100;
					if (ran >= 50)
					{
						if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 11)
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
						break;
					}
					else
					{
						if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
						{
							arr[0] = ships[k].number;
							arr[1] = ships[k].letter + i - 1;
						}
						else if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 11)
						{
							arr[0] = ships[k].number;
							arr[1] = ships[k].letter + i + 1;
						}
						else
						{
							continue;
						}
						break;
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
							else if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 11)
							{
								arr[0] = ships[k].number;
								arr[1] = ships[k].letter + i + 1;
							}
							else if (field_visible[ships[k].number + 1][ships[k].letter + i] == space && ships[k].number + 1 != 11)
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
							break;
						}
						else
						{
							if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 11)
							{
								arr[0] = ships[k].number;
								arr[1] = ships[k].letter + i + 1;
							}
							else if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
							{
								arr[0] = ships[k].number;
								arr[1] = ships[k].letter + i - 1;
							}
							else if (field_visible[ships[k].number + 1][ships[k].letter + i] == space && ships[k].number + 1 != 11)
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
							break;
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
							else if (field_visible[ships[k].number + 1][ships[k].letter + i] == space && ships[k].number + 1 != 11)
							{
								arr[0] = ships[k].number + 1;
								arr[1] = ships[k].letter + i;
							}
							else if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
							{
								arr[0] = ships[k].number;
								arr[1] = ships[k].letter + i - 1;
							}
							else if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 11)
							{
								arr[0] = ships[k].number;
								arr[1] = ships[k].letter + i + 1;
							}
							else
							{
								continue;
							}
							break;
						}
						else
						{
							if (field_visible[ships[k].number - 1][ships[k].letter + i] == space && ships[k].number - 1 != 0)
							{
								arr[0] = ships[k].number - 1;
								arr[1] = ships[k].letter + i;
							}
							else if (field_visible[ships[k].number + 1][ships[k].letter + i] == space && ships[k].number + 1 != 11)
							{
								arr[0] = ships[k].number + 1;
								arr[1] = ships[k].letter + i;
							}
							else if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 11)
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
							break;
						}
					}
				}
			}
		}
	}
}

void PC_Start_Tactic_1(char** field_visible, int& size, int* arr, int& arr_size)
{
	for (int i = 1; i < size - 1; i++)
	{
		if (field_visible[i][i] == space)
		{
			arr[0] = i;
			arr[1] = i;
			return;
		}
	}
}

void PC_Start_Tactic_2(char** field_visible, int& size, int* arr, int& arr_size)
{
	for (int i = 1; i < size - 1; i++)
	{
		if (field_visible[i][i] == space)
		{
			arr[0] = i;
			arr[1] = i;
			return;
		}
	}
}