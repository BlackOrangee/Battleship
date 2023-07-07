#pragma once
using namespace std;

void PC_AI_Random(int& rndm, int& R_1, int R_2, int& R_3, int& R_4, int& R_5, int& R_6, int& R_7, int& R_8, int& V, int& H)
{
	R_1 = 0;
	R_2 = 0;
	R_3 = 0;
	R_4 = 0;
	R_5 = 0;
	R_6 = 0;
	rndm = rand() % 100;

	if (rndm < 25)
	{
		R_1 = 1;
	}
	else if (rndm >= 25 && rndm < 50)
	{
		R_2 = 1;
	}
	else if (rndm >= 50 && rndm < 75)
	{
		R_3 = 1;
	}
	else
	{
		R_4 = 1;
	}


	if (rndm < 50)
	{
		R_5 = 1;
		R_7 = 1;
	}
	else
	{
		R_6 = 1;
		R_8 = 1;
	}
}

void PC_AI_Orient(int& orient, int& V, int& H, int& R_5, int& R_6, int& R_7, int& R_8, int& i)
{
	if (orient == 1)
	{
		V = i;
		H = 0;
		R_7 = 0;
		R_8 = 0;
	}
	else if (orient == 2)
	{
		V = 0;
		H = i;
		R_5 = 0;
		R_6 = 0;
	}
}

void PC_AI_Fixer(int& R_1, int& R_2, int& R_3, int& R_4)
{
	if (R_1 + R_2 + R_3 + R_4 == 1)
	{
		return;
	}
	else
	{
		if (R_1 == 1)
		{
			R_1 = 0;
		}
		else if (R_2 == 1)
		{
			R_2 = 0;
		}
		else if (R_3 == 1)
		{
			R_3 = 0;
		}
		else if (R_4 == 1)
		{
			R_4 = 0;
		}
	}
}

// This function represents the AI logic to check the ship's status and make the next move.
void PC_AI_Check_Ship(char** field_visible, int& size, Ship* ships, int& ships_count, int* arr, int& arr_size)
{
	int rndm = 0;
	int R_1 = 0;
	int R_2 = 0;
	int R_3 = 0;
	int R_4 = 0;
	int R_5 = 0;
	int R_6 = 0;
	int R_7 = 0;
	int R_8 = 0;
	int V = 0;
	int H = 0;

	for (int k = 0; k < ships_count; k++)
	{
		if (ships[k].on_watter == false)
		{
			continue;
		}

		PC_AI_Random(rndm, R_1, R_2, R_3, R_4, R_5, R_6, R_7, R_8, V, H);

		for (int i = 0; i < ships[k].ship_size; i++)
		{
			PC_AI_Orient(ships[k].orient, V, H, R_5, R_6, R_7, R_8, i);			

			if (field_visible[ships[k].number + V][ships[k].letter + H] == cross
				&& (field_visible[ships[k].number + V + R_5 - R_6][ships[k].letter + H + R_7 - R_8] == cross
					|| field_visible[ships[k].number + V + R_6 - R_5][ships[k].letter + H + R_8 - R_7] == cross))
			{
				PC_AI_Fixer(R_5, R_6, R_7, R_8);
				if (field_visible[ships[k].number + V + R_5 - R_6][ships[k].letter + H + R_7 - R_8] == space
					&& ships[k].number + V + R_5 - R_6 != 11
					&& ships[k].number + V + R_5 - R_6 != 0
					&& ships[k].letter + H + R_7 - R_8 != 11
					&& ships[k].letter + H + R_7 - R_8 != 0)
				{
					arr[0] = ships[k].number + V + R_5 - R_6;
					arr[1] = ships[k].letter + H + R_7 - R_8;
				}
				else if (field_visible[ships[k].number + V + R_6 - R_5][ships[k].letter + H + R_8 - R_7] == space
					&& ships[k].number + V + R_6 - R_5 != 11
					&& ships[k].number + V + R_6 - R_5 != 0
					&& ships[k].letter + H + R_8 - R_7 != 11
					&& ships[k].letter + H + R_8 - R_7 != 0)
				{
					arr[0] = ships[k].number + V + R_6 - R_5;
					arr[1] = ships[k].letter + H + R_8 - R_7;
				}
				else
				{
					continue;
				}
				break;
			}
			else if (field_visible[ships[k].number + V][ships[k].letter + H] == cross)
			{
				PC_AI_Fixer(R_1, R_2, R_3, R_4);
				if (field_visible[ships[k].number + V + R_1 - R_2][ships[k].letter + H + R_3 - R_4] == space
					&& (ships[k].number + V + R_1 - R_2 != 11
						&& ships[k].number + V + R_1 - R_2 != 0
						&& ships[k].letter + H + R_3 - R_4 != 11
						&& ships[k].letter + H + R_3 - R_4 != 0))
				{
					arr[0] = ships[k].number + V + R_1 - R_2;
					arr[1] = ships[k].letter + H + R_3 - R_4;
				}
				else if (field_visible[ships[k].number + V + R_2 - R_1][ships[k].letter + H + R_4 - R_3] == space
					&& (ships[k].number + V + R_2 - R_1 != 11
						&& ships[k].number + V + R_2 - R_1 != 0
						&& ships[k].letter + H + R_4 - R_3 != 11
						&& ships[k].letter + H + R_4 - R_3 != 0))
				{
					arr[0] = ships[k].number + V + R_2 - R_1;
					arr[1] = ships[k].letter + H + R_4 - R_3;
				}
				else if (field_visible[ships[k].number + V + R_3 - R_4][ships[k].letter + H + R_1 - R_2] == space
					&& (ships[k].number + V + R_3 - R_4 != 11
						&& ships[k].number + V + R_3 - R_4 != 0
						&& ships[k].letter + H + R_1 - R_2 != 11
						&& ships[k].letter + H + R_1 - R_2 != 0))
				{
					arr[0] = ships[k].number + V + R_3 - R_4;
					arr[1] = ships[k].letter + H + R_1 - R_2;
				}
				else if (field_visible[ships[k].number + V + R_4 - R_3][ships[k].letter + H + R_2 - R_1] == space
					&& (ships[k].number + V + R_4 - R_3 != 11
						&& ships[k].number + V + R_4 - R_3 != 0
						&& ships[k].letter + H + R_2 - R_1 != 11
						&& ships[k].letter + H + R_2 - R_1 != 0))
				{
					arr[0] = ships[k].number + V + R_4 - R_3;
					arr[1] = ships[k].letter + H + R_2 - R_1;
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


void PC_Start_Tactic_2(char** field_visible, int& size, int* arr, int& arr_size)
{
	if (arr[0] || arr[1])
	{
		return;
	}
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

void PC_Start_Tactic_1(char** field_visible, int& size, int* arr, int& arr_size)
{
	if (arr[0] || arr[1])
	{
		return;
	}
	int j = 1;
	for (int i = size - 2; i > 0; i--)
	{
		if (field_visible[j][i] == space)
		{
			arr[0] = j;
			arr[1] = i;
			return;
		}
		j++;
	}
}
