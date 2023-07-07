#pragma once

using namespace std;

// This function removes the "bang" symbol from the game field and replaces it with the "point" symbol.
void Bang_Remover(char** field, int& size)
{
	// Iterate over each cell in the field, excluding the outer boundary cells
	for (int i = 1; i < size - 1; i++)
	{
		for (int j = 1; j < size - 1; j++)
		{
			// Check if the current cell contains the "bang" symbol
			if (field[i][j] == bang)
			{
				// Replace the "bang" symbol with the "point" symbol
				field[i][j] = point;
			}
		}
	}
}

// This function handles the firing action on the game field.
// It checks the specified coordinates on the unvisible field and updates the visible field accordingly.
// It returns 0 for a miss, 1 for a hit, and 2 for an invalid move.
int Fire(char** field_unvisible, char** field_visible, int& size, int* input, int input_size)
{
	Bang_Remover(field_unvisible, size);
	Bang_Remover(field_visible, size);
	// Check the value at the specified coordinate on the field_unvisible
	if (field_unvisible[input[0]][input[1]] == space)
	{
		// If the coordinate is empty, mark it as a hit (bang) on both the unvisible and visible fields
		field_unvisible[input[0]][input[1]] = bang;
		field_visible[input[0]][input[1]] = bang;
		return 0; // Return 0 to indicate a miss
	}
	else if (field_unvisible[input[0]][input[1]] == point || field_unvisible[input[0]][input[1]] == cross)
	{
		// If the coordinate has already been targeted (either hit or missed), return 2 to indicate an invalid move
		return 2;
	}
	else if (field_unvisible[input[0]][input[1]] == ship)
	{
		// If the coordinate contains a ship, mark it as a hit (cross) on both the unvisible and visible fields
		field_unvisible[input[0]][input[1]] = cross;
		field_visible[input[0]][input[1]] = cross;
		return 1; // Return 1 to indicate a hit
	}
}

// This function checks if a ship is vertically hit on the unvisible field.
void Check_Ship_Vertical(char** field_2_unvisible, int& size, Ship* ships, int& ships_count, bool* on_watter, int& k)
{
	// Iterate over the ship's length
	for (int i = 0; i < ships[k].ship_size; i++)
	{
		// Check if the corresponding position on the field contains a hit (cross)
		if (field_2_unvisible[ships[k].number + i][ships[k].letter] == cross)
		{
			on_watter[i] = false; // Set the corresponding on_watter value to false
		}
	}
}

// This function checks if a ship is horizontally hit on the unvisible field.
void Check_Ship_Horizontal(char** field_2_unvisible, int& size, Ship* ships, int& ships_count, bool* on_watter, int& k)
{
	// Iterate over the ship's length
	for (int i = 0; i < ships[k].ship_size; i++)
	{
		// Check if the corresponding position on the field contains a hit (cross)
		if (field_2_unvisible[ships[k].number][ships[k].letter + i] == cross)
		{
			on_watter[i] = false; // Set the corresponding on_watter value to false
		}
	}
}

// Check the ship's size and the on_watter values to determine if the ship is still on the water
void Check_Ship_Booler(Ship* ships, int& ships_count, bool* on_watter, int& k)
{
	if (ships[k].ship_size == 4)
	{
		if (!on_watter[0] && !on_watter[1] && !on_watter[2] && !on_watter[3])
		{
			ships[k].on_watter = false; // Set the on_watter value of the ship to false
		}
	}
	else if (ships[k].ship_size == 3)
	{
		if (!on_watter[0] && !on_watter[1] && !on_watter[2])
		{
			ships[k].on_watter = false; // Set the on_watter value of the ship to false
		}
	}
	else if (ships[k].ship_size == 2)
	{
		if (!on_watter[0] && !on_watter[1])
		{
			ships[k].on_watter = false; // Set the on_watter value of the ship to false
		}
	}
	else if (ships[k].ship_size == 1)
	{
		if (!on_watter[0])
		{
			ships[k].on_watter = false; // Set the on_watter value of the ship to false
		}
	}
}

// Check ship status and change
void Check_Ship(char** field_2_unvisible, int& size, Ship* ships, int& ships_count)
{
	for (int k = 0; k < ships_count; k++)
	{
		// Create an array to store the on_watter values for the ship's length
		bool* on_watter = new bool[ships[k].ship_size];
		for (int i = 0; i < ships[k].ship_size; i++)
		{
			on_watter[i] = true; // Initialize the on_watter values to true
		}

		if (ships[k].orient == 1)
		{
			Check_Ship_Vertical(field_2_unvisible, size, ships, ships_count, on_watter, k); // Call the helper function for vertical ships
		}
		else if (ships[k].orient == 2)
		{
			Check_Ship_Horizontal(field_2_unvisible, size, ships, ships_count, on_watter, k); // Call the helper function for horizontal ships
		}
		Check_Ship_Booler(ships, ships_count, on_watter, k); // Change the ship's on_watter status

		delete[] on_watter; // Deallocate the on_watter array
	}
}

// This function updates the unvisible and visible fields by marking the surrounding area of a vertically oriented ship with points.
void Pointer_Vertical(char** field_1_visible, char** field_2_unvisible, int& size, Ship* ships, int& ships_count, int& k)
{
	for (int i = 0; i < ships[k].ship_size + 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// Check if the position on the unvisible field is not already marked as a hit (cross)
			if (field_2_unvisible[ships[k].number + i - 1][ships[k].letter + j - 1] != cross)
			{
				// Mark the position as a point on both unvisible and visible fields
				field_2_unvisible[ships[k].number + i - 1][ships[k].letter + j - 1] = point;
				field_1_visible[ships[k].number + i - 1][ships[k].letter + j - 1] = point;
			}
		}
	}
}

// This function updates the unvisible and visible fields by marking the surrounding area of a horizontally oriented ship with points.
void Pointer_Horizontal(char** field_1_visible, char** field_2_unvisible, int& size, Ship* ships, int& ships_count, int& k)
{
	for (int i = 0; i < ships[k].ship_size + 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// Check if the position on the unvisible field is not already marked as a hit (cross)
			if (field_2_unvisible[ships[k].number + j - 1][ships[k].letter + i - 1] != cross)
			{
				// Mark the position as a point on both unvisible and visible fields
				field_2_unvisible[ships[k].number + j - 1][ships[k].letter + i - 1] = point;
				field_1_visible[ships[k].number + j - 1][ships[k].letter + i - 1] = point;
			}
		}
	}
}

// This function updates the unvisible and visible fields by marking the surrounding area of ships with points.
void Pointer(char** field_1_visible, char** field_2_unvisible, int& size, Ship* ships, int& ships_count)
{
	for (int k = 0; k < ships_count; k++)
	{
		// Check if the ship is still on the water
		if (ships[k].on_watter)
		{
			continue; // Skip this ship if it's still on the water
		}

		if (ships[k].orient == 1)
		{
			Pointer_Vertical(field_1_visible, field_2_unvisible, size, ships, ships_count, k); // Call the helper function for vertical ships
		}
		else if (ships[k].orient == 2)
		{
			Pointer_Horizontal(field_1_visible, field_2_unvisible, size, ships, ships_count, k); // Call the helper function for horizontal ships
		}
	}
}

// This function checks the score and returns 0 if it reaches 20.
int Score_check(int& score)
{
	if (score == 20)
	{
		return 0; // Return 0 if the score reaches 20
	}
	// No explicit return statement if the condition is not met
}


// This function represents the turn of the PC (computer player) in the game.
void PC_Turn(char** field_1_Player, char** field_2_Enemy, char** field_Enemy_Memory, int& size, Ship* Players_Ships, Ship* PC_Ships, int& ship_count)
{
	int pc_input_size = 2;
	int* pc_input = new int[pc_input_size];
	int fire = 0;
	int ran = 0;

	Field_Print(field_1_Player, field_2_Enemy, size); // Print the game field
	Statistic(Players_Ships, PC_Ships, ship_count); // Print the game statistics
	do
	{
		pc_input[0] = 0;
		pc_input[1] = 0;

		PC_AI_Check_Ship(field_Enemy_Memory, size, Players_Ships, ship_count, pc_input, pc_input_size); // Generate the PC's input coordinates
		//PC_Supporter(field_1_Player, size, pc_input, pc_input_size, Players_Ships, ship_count);

		if (tactic_1)
		{
			PC_Start_Tactic_1(field_Enemy_Memory, size, pc_input, pc_input_size);
			if (pc_input[0] == 0 && pc_input[1] == 0)
			{
				tactic_1 = false;
			}
		}
		else
		{
			PC_Start_Tactic_2(field_Enemy_Memory, size, pc_input, pc_input_size);
			if (pc_input[0] == 0 && pc_input[1] == 0)
			{
				tactic_1 = true;
			}
		}


		if (pc_input[0] == 0 && pc_input[1] == 0)
		{
			ran = rand() % 10 + 1;
			pc_input[0] = ran;
			ran = rand() % 10 + 1;
			pc_input[1] = ran;
		}

		fire = Fire(field_1_Player, field_Enemy_Memory, size, pc_input, pc_input_size); // Fire at the player's field using the generated input

		if (fire != 2)
		{
			Sleep(500);
			Field_Print(field_1_Player, field_2_Enemy, size); // Print the game field
			Statistic(Players_Ships, PC_Ships, ship_count); // Print the game statistics
		}

		if (fire == 1) // If the fire hits a ship
		{
			pc_score++; // Increment the PC's score
			Check_Ship(field_1_Player, size, Players_Ships, ship_count); // Check if a ship is sunk
			Pointer(field_Enemy_Memory, field_1_Player, size, Players_Ships, ship_count); // Update the PC's memory field
			Sleep(500);
			Field_Print(field_1_Player, field_2_Enemy, size); // Print the game field
			Statistic(Players_Ships, PC_Ships, ship_count); // Print the game statistics

			if (!Score_check(pc_score)) // Check if the PC's score reaches the winning condition
			{
				end_game = true; // Set the end_game flag to true
			}
		}
	} while (fire && !end_game);

	delete[] pc_input; // Deallocate the dynamically allocated memory
}

void PC_2_Turn(char** field_Enemy, char** field_Enemy_Memory, char** field_2_Enemy, char** field_1_Player, int& size, Ship* PC_Ships, Ship* Players_Ships, int& ship_count)
{
	int pc_input_size = 2;
	int* pc_input = new int[pc_input_size];
	int fire = NULL;
	int ran = NULL;

	Field_Print(field_1_Player, field_2_Enemy, size); // Print the game field
	Statistic(Players_Ships, PC_Ships, ship_count); // Print the game statistics
	do
	{
		pc_input[0] = 0;
		pc_input[1] = 0;

		PC_AI_Check_Ship(field_2_Enemy, size, PC_Ships, ship_count, pc_input, pc_input_size); // Generate the PC's input coordinates
		if (tactic_2)
		{
			PC_Start_Tactic_1(field_2_Enemy, size, pc_input, pc_input_size);
			if (pc_input[0] == 0 && pc_input[1] == 0)
			{
				tactic_2 = false;
			}
		}
		else
		{
			PC_Start_Tactic_2(field_2_Enemy, size, pc_input, pc_input_size);
			if (pc_input[0] == 0 && pc_input[1] == 0)
			{
				tactic_2 = true;
			}
		}
		

		if (pc_input[0] == 0 && pc_input[1] == 0)
		{
			ran = rand() % 10 + 1;
			pc_input[0] = ran;
			ran = rand() % 10 + 1;
			pc_input[1] = ran;
		}

		fire = Fire(field_Enemy, field_2_Enemy, size, pc_input, pc_input_size); // Fire at the player's field using the generated input

		if (fire != 2)
		{
			Sleep(500);
			Field_Print(field_1_Player, field_2_Enemy, size); // Print the game field
			Statistic(Players_Ships, PC_Ships, ship_count); // Print the game statistics
		}

		if (fire == 1) // If the fire hits a ship
		{
			player_score++; // Increment the PC's score
			Check_Ship(field_Enemy, size, PC_Ships, ship_count); // Check if a ship is sunk
			Pointer(field_2_Enemy, field_Enemy, size, PC_Ships, ship_count); // Update the PC's memory field
			Sleep(500);
			Field_Print(field_1_Player, field_2_Enemy, size); // Print the game field
			Statistic(Players_Ships, PC_Ships, ship_count); // Print the game statistics

			if (!Score_check(player_score)) // Check if the PC's score reaches the winning condition
			{
				end_game = true; // Set the end_game flag to true
			}
		}
	} while (fire && !end_game);

	delete[] pc_input; // Deallocate the dynamically allocated memory
}

// This function represents the turn of the player in the game.
void Player_Turn(char** field_1_Player, char** field_2_Enemy, char** field_Enemy, int& size, Ship* Players_Ships, Ship* PC_Ships, int& ship_count)
{
	Sleep(400); // Pause for a short duration

	int input_size = 2;
	int* input = NULL;
	int fire = NULL;

	do
	{
		Field_Print(field_1_Player, field_2_Enemy, size); // Print the game field
		Statistic(Players_Ships, PC_Ships, ship_count); // Print the game statistics
		input = Input(input_size); // Get the player's input coordinates

		fire = Fire(field_Enemy, field_2_Enemy, size, input, input_size); // Fire at the enemy's field using the player's input

		if (fire != 2)
		{
			Sleep(400);
			Field_Print(field_1_Player, field_2_Enemy, size); // Print the game field
			Statistic(Players_Ships, PC_Ships, ship_count); // Print the game statistics
		}

		if (fire == 1) // If the fire hits a ship
		{
			player_score++; // Increment the player's score
			Check_Ship(field_Enemy, size, PC_Ships, ship_count); // Check if a ship is sunk
			Pointer(field_2_Enemy, field_Enemy, size, PC_Ships, ship_count); // Update the player's field with hit markers
			if (!Score_check(player_score)) // Check if the player's score reaches the winning condition
			{
				end_game = true; // Set the end_game flag to true
			}
		}
	} while (fire && !end_game);

	delete[] input; // Deallocate the dynamically allocated memory
}
