#pragma once
using namespace std;

// This function assigns values based on the value of random.
void PC_AI_Random_Sup_1(int& random, int& Random_1,
	int& Random_2, int& Random_3, int& Random_4)
{
	if (random < 25)
	{
		Random_1 = 1;
	}
	else if (random >= 25 && random < 50)
	{
		Random_2 = 1;
	}
	else if (random >= 50 && random < 75)
	{
		Random_3 = 1;
	}
	else
	{
		Random_4 = 1;
	}
}

// This function assigns values based on the value of random.
void PC_AI_Random_Sup_2(int& random, int& Random_5,
	int& Random_6, int& Random_7, int& Random_8)
{
	if (random < 50)
	{
		Random_5 = 1;
		Random_7 = 1;
		return;
	}
	Random_6 = 1;
	Random_8 = 1;
}

// This function generates a random number 
// between 0 and 99 and assigns it to the variable random.
void Random_100(int& random)
{
	random = rand() % 100;
}

// This function generates random values for the variables.
void PC_AI_Random(int& random, int& Random_1, int Random_2,
	int& Random_3, int& Random_4, int& Random_5, int& Random_6, 
	int& Random_7, int& Random_8, int& Vertical, int& Horizontal)
{
	Random_1 = 0;
	Random_2 = 0;
	Random_3 = 0;
	Random_4 = 0;
	Random_5 = 0;
	Random_6 = 0;
	Random_100(random);

	PC_AI_Random_Sup_1(random, Random_1, Random_2, Random_3, Random_4);
	PC_AI_Random_Sup_2(random, Random_5, Random_6, Random_7, Random_8);
}

// This function determines the orientation (vertical or horizontal) of a ship based on the value of orient.
void Ship_Orient(int& orient, int& index, int& Vertical, int& Horizontal)
{
	if (orient == 1)
	{
		Horizontal = 0;
		Vertical = index;
		return;
	}
	Vertical = 0;
	Horizontal = index;
}

// This function assigns values based on the value of orient.
void PC_AI_Orient(int& orient, int& Random_5, int& Random_6, int& Random_7, int& Random_8)
{
	if (orient == 1)
	{
		Random_7 = 0;
		Random_8 = 0;
		return;
	}
	Random_5 = 0;
	Random_6 = 0;
}

// This function ensures that only one of the variables has a value of 1.
void PC_AI_Fixer(int& Random_1, int& Random_2, int& Random_3, int& Random_4)
{
	if (Random_1 + Random_2 + Random_3 + Random_4 != 1)
	{
		if (Random_1 == 1)
		{
			Random_1 = 0;
		}
		else if (Random_2 == 1)
		{
			Random_2 = 0;
		}
		else if (Random_3 == 1)
		{
			Random_3 = 0;
		}
		else if (Random_4 == 1)
		{
			Random_4 = 0;
		}
	}
}

// This function represents the AI logic 
// to check the ship's status and make the next move.
bool PC_AI_Check_Ship(char** field_visible, int& size, 
	Ship* ships, int& ships_count, int* arr, int& arr_size)
{
	int random = 0;
	int Random_1 = 0;
	int Random_2 = 0;
	int Random_3 = 0;
	int Random_4 = 0;
	int Random_5 = 0;
	int Random_6 = 0;
	int Random_7 = 0;
	int Random_8 = 0;
	int Vertical = 0;
	int Horizontal = 0;

	// Iterate over each ship
	for (int k = 0; k < ships_count; k++)
	{
		// Skip ships that are already sunk
		if (!ships[k].on_watter)
		{
			continue;
		}

		PC_AI_Random(random, Random_1, Random_2, Random_3, Random_4, 
			Random_5, Random_6, Random_7, Random_8, Vertical, Horizontal);

		// Iterate over each position of the ship
		for (int i = 0; i < ships[k].ship_size; i++)
		{
			PC_AI_Orient(ships[k].orient, Random_5, Random_6, Random_7, Random_8);			
			Ship_Orient(ships[k].orient, i, Vertical, Horizontal);

			// Check if the ship's current position is a hit and neighboring positions are possible moves
			if (field_visible[ships[k].number + Vertical][ships[k].letter + Horizontal] == cross
				&& (field_visible[ships[k].number + Vertical + Random_5 - Random_6][ships[k].letter + Horizontal + Random_7 - Random_8] == cross
					|| field_visible[ships[k].number + Vertical + Random_6 - Random_5][ships[k].letter + Horizontal + Random_8 - Random_7] == cross))
			{
				// Check if the neighboring positions are empty and within the field boundaries
				if (field_visible[ships[k].number + Vertical + Random_5 - Random_6][ships[k].letter + Horizontal + Random_7 - Random_8] == space
					&& ships[k].number + Vertical + Random_5 - Random_6 != 11
					&& ships[k].number + Vertical + Random_5 - Random_6 != 0
					&& ships[k].letter + Horizontal + Random_7 - Random_8 != 11
					&& ships[k].letter + Horizontal + Random_7 - Random_8 != 0)
				{
					arr[0] = ships[k].number + Vertical + Random_5 - Random_6;
					arr[1] = ships[k].letter + Horizontal + Random_7 - Random_8;
					return true;
				}
				else if (field_visible[ships[k].number + Vertical + Random_6 - Random_5][ships[k].letter + Horizontal + Random_8 - Random_7] == space
					&& ships[k].number + Vertical + Random_6 - Random_5 != 11
					&& ships[k].number + Vertical + Random_6 - Random_5 != 0
					&& ships[k].letter + Horizontal + Random_8 - Random_7 != 11
					&& ships[k].letter + Horizontal + Random_8 - Random_7 != 0)
				{
					arr[0] = ships[k].number + Vertical + Random_6 - Random_5;
					arr[1] = ships[k].letter + Horizontal + Random_8 - Random_7;
					return true;
				}
				else
				{
					continue;
				}
				break;
			}
			else if (field_visible[ships[k].number + Vertical][ships[k].letter + Horizontal] == cross)
			{
				PC_AI_Fixer(Random_1, Random_2, Random_3, Random_4);
				if (field_visible[ships[k].number + Vertical + Random_1 - Random_2][ships[k].letter + Horizontal + Random_3 - Random_4] == space
					&& (ships[k].number + Vertical + Random_1 - Random_2 != 11
						&& ships[k].number + Vertical + Random_1 - Random_2 != 0
						&& ships[k].letter + Horizontal + Random_3 - Random_4 != 11
						&& ships[k].letter + Horizontal + Random_3 - Random_4 != 0))
				{
					arr[0] = ships[k].number + Vertical + Random_1 - Random_2;
					arr[1] = ships[k].letter + Horizontal + Random_3 - Random_4;
					return true;
				}
				else if (field_visible[ships[k].number + Vertical + Random_2 - Random_1][ships[k].letter + Horizontal + Random_4 - Random_3] == space
					&& (ships[k].number + Vertical + Random_2 - Random_1 != 11
						&& ships[k].number + Vertical + Random_2 - Random_1 != 0
						&& ships[k].letter + Horizontal + Random_4 - Random_3 != 11
						&& ships[k].letter + Horizontal + Random_4 - Random_3 != 0))
				{
					arr[0] = ships[k].number + Vertical + Random_2 - Random_1;
					arr[1] = ships[k].letter + Horizontal + Random_4 - Random_3;
					return true;
				}
				else if (field_visible[ships[k].number + Vertical + Random_3 - Random_4][ships[k].letter + Horizontal + Random_1 - Random_2] == space
					&& (ships[k].number + Vertical + Random_3 - Random_4 != 11
						&& ships[k].number + Vertical + Random_3 - Random_4 != 0
						&& ships[k].letter + Horizontal + Random_1 - Random_2 != 11
						&& ships[k].letter + Horizontal + Random_1 - Random_2 != 0))
				{
					arr[0] = ships[k].number + Vertical + Random_3 - Random_4;
					arr[1] = ships[k].letter + Horizontal + Random_1 - Random_2;
					return true;
				}
				else if (field_visible[ships[k].number + Vertical + Random_4 - Random_3][ships[k].letter + Horizontal + Random_2 - Random_1] == space
					&& (ships[k].number + Vertical + Random_4 - Random_3 != 11
						&& ships[k].number + Vertical + Random_4 - Random_3 != 0
						&& ships[k].letter + Horizontal + Random_2 - Random_1 != 11
						&& ships[k].letter + Horizontal + Random_2 - Random_1 != 0))
				{
					arr[0] = ships[k].number + Vertical + Random_4 - Random_3;
					arr[1] = ships[k].letter + Horizontal + Random_2 - Random_1;
					return true;
				}
				else
				{
					continue;
				}
				break;
			}
		}
	}
	return false;
}

// This function represents the second tactic for the PC's start move.
bool PC_Start_Tactic_2(char** field_visible, int& size, int* arr, int& arr_size)
{
	for (int i = 1; i < size - 1; i++)
	{
		// Check if the diagonal position on the field is empty
		if (field_visible[i][i] == space)
		{
			arr[0] = i;
			arr[1] = i;
			return true;
		}
	}
	return false;
}

// This function represents the first tactic for the PC's start move.
bool PC_Start_Tactic_1(char** field_visible, int& size, int* arr, int& arr_size)
{
	int j = 1;
	for (int i = size - 2; i > 0; i--)
	{
		// Check if the position on the secondary diagonal of the field is empty
		if (field_visible[j][i] == space)
		{
			arr[0] = j;
			arr[1] = i;
			return true;
		}
		j++;
	}
	return false;
}

// This function provides support for the PC's next move.
void PC_Supporter(char** field_unvisible, int& size, 
	int* arr, int& arr_size, Ship* ships, int& ships_count)
{
	// If the PC has already chosen a move, return
	if (arr[0] || arr[1])
	{
		return;
	}

	int Vertical = 0;
	int Horizontal = 0;
	int random = 0;

	Random_100(random);

	// Randomly choose a ship and its position to target
	if (10 > random)
	{
		for (int k = 0; k < ships_count; k++)
		{
			if (!ships[k].on_watter)
			{
				continue;
			}
			for (int i = 0; i < ships[k].ship_size; i++)
			{
				Random_100(random);
				if (random < 1)
				{
					Ship_Orient(ships[k].orient, i, Vertical, Horizontal);
					// Check if the targeted position contains a ship
					if (field_unvisible[ships[k].number + Vertical][ships[k].letter + Horizontal] == ship)
					{
						arr[0] = ships[k].number + Vertical;
						arr[1] = ships[k].letter + Horizontal;
						return;
					}
				}
			}
		}
	}
}
