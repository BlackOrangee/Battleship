#include <iostream>
using namespace std;

#include "Var.h"
#include "windows.h"
#include "Field.h"
#include "Dialog.h"
#include "Logo.h"
#include "Menu.h"
#include "PC_AI.h"
#include "Game.h"

int main()
{
	// Seed the random number generator
	srand(time(NULL));

	do
	{
		Tactic_Determinator();

		int ship_count = 10; // Number of ships
		int size = 12; // Size of the game field
		char** field_1_Player = Create_Field(size); // Create the player's field
		char** field_2_Enemy = Create_Field(size); // Create the enemy's field
		char** field_Enemy = Create_Field(size); // Create the combined enemy's field (for displaying)
		char** field_Enemy_Memory = Create_Field(size); // Create the memory of the enemy's field

		Ship* PC_Ships = Random_Ship_Placer(field_Enemy, size, ship_count); // Place random ships for the enemy

		Logo(); // Display the game logo
		Start_Menu(); // Display the start menu
		Ship* Players_Ships = NULL;

		if (filing == 1)
		{
			Players_Ships = Random_Ship_Placer(field_1_Player, size, ship_count); // Place random ships for the player
		}
		else if (filing == 2)
		{
			// Allow the player to manually place ships
			Players_Ships = Ship_Placer(field_1_Player, field_2_Enemy, size, ship_count); 
		}

		do
		{
			if (gamemode)
			{
				// If the game mode is player vs. computer
				Player_Turn(field_1_Player, field_2_Enemy, field_Enemy, size, 
					Players_Ships, PC_Ships, ship_count); // Player's turn
			}
			else
			{
				// If the game mode is computer vs. computer
				PC_2_Turn(field_Enemy, field_Enemy_Memory, field_2_Enemy, 
					field_1_Player, size, PC_Ships, Players_Ships, ship_count); // Player's AI turn
			}

			if (end_game)
			{
				break;
			}

			PC_Turn(field_1_Player, field_2_Enemy, field_Enemy_Memory, size, 
				Players_Ships, PC_Ships, ship_count); // Enemy's turn

		} while (!end_game);

		if (end_game)
		{
			restart_Menu();
		}
	} while (restart);
}
