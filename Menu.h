#pragma once

using namespace std;

// Style menu for selecting the field style
void Style_Menu()
{
	int size = 12; // Size of the field
	int ship_count = 10; // Number of ships to place
	char** Style_demo = Create_Field(size); // Create a field for the style demonstration
	char** Style_demo_blink = Create_Field(size); // Create a blinking field for the style demonstration

	Ship* demo = Random_Ship_Placer(Style_demo, size, ship_count); // Place ships randomly on the style demonstration field

	cout << "\n\n\t\tStyle - 0\n";
	Standart_Field(Style_demo, Style_demo_blink, size); // Print the style 0 field

	cout << "\n\n\t\tStyle - 1\n";
	Alternative_1_Field_Print(Style_demo, Style_demo_blink, size); // Print the style 1 field

	cout << "\n\n\t\tStyle - 2\n";
	Alternative_2_Field_Print(Style_demo, Style_demo_blink, size); // Print the style 2 field

	cout << "\n\n\t\tStyle - 3\n";
	Alternative_3_Field_Print(Style_demo, Style_demo_blink, size); // Print the style 3 field

	int menu = 0;

	cout << "\n\n\tEnter style num: ";	cin >> menu;
	switch (menu)
	{
	case 0:
		f_style = 0; // Set the selected style to style 0
		break;
	case 1:
		f_style = 1; // Set the selected style to style 1
		break;
	case 2:
		f_style = 2; // Set the selected style to style 2
		break;
	case 3:
		f_style = 3; // Set the selected style to style 3
		break;
	default:
		f_style = 0; // Set the default style to style 0
		break;
	}
}

// Field menu for selecting the field filling method
void field_menu()
{
	int menu = 0;
	cout << "\n\n\tFilling\n\t1 -- Random\n\t2 -- Manual\n\t";	cin >> menu;

	switch (menu)
	{
	case 1:
		filing = 1; // Set the field filling method to random
		break;
	case 2:
		filing = 2; // Set the field filling method to manual
		break;
	default:
		field_menu(); // Display the field menu again for invalid input
		break;
	}
}

// Difficulty menu for selecting the game difficulty
void diff_menu()
{
	int menu = 0;
	cout << "\n\n\tDifficulty";
	cout << "\n\n\t1 -- Ease\n\t2 -- Normal\n\t3 -- Harder\n\t4 -- Hard\n\t";	cin >> menu;

	switch (menu)
	{
	case 1:
		difficulty = 40; // Set the difficulty to easy (40% hit probability)
		break;
	case 2:
		difficulty = 50; // Set the difficulty to normal (50% hit probability)
		break;
	case 3:
		difficulty = 70; // Set the difficulty to harder (70% hit probability)
		break;
	case 4:
		difficulty = 100; // Set the difficulty to hard (100% hit probability)
		break;
	default:
		diff_menu(); // Display the difficulty menu again for invalid input
		break;
	}
}


void Gamemode_menu()
{
	int menu = 0;
	cout << "\n\n\tGamemode";
	cout << "\n\n\t1 -- Player VS Computer\n\t2 -- Computer VS Computer\n\t";	cin >> menu;

	switch (menu)
	{
	case 1:
		gamemode = 1;
		break;
	case 2:
		gamemode = 0;
		break;
	default:
		Gamemode_menu();
		break;
	}
}

// Start menu for the main menu options
void Start_Menu()
{
	bool exit = false;
	int menu = 0;
	do
	{
		menu = 0;
		cout << "\n\n\t1 -- Play\n\t2 -- Change filing type\n\t3 -- Change Difficulty\n\t4 -- Change gamemode\n\t5 -- Change style\n\t";	cin >> menu;

		switch (menu)
		{
		case 1:
			exit = true; // Exit the start menu
			break;
		case 2:
			field_menu(); // Show the field menu for selecting the field filling method
			exit = false; // Continue the start menu
			break;
		case 3:
			diff_menu(); // Show the difficulty menu for selecting the game difficulty
			exit = false; // Continue the start menu
			break;
		case 4:
			Gamemode_menu();
			exit = false; // Continue the start menu
			break;
		case 5:
			Style_Menu(); // Show the style menu for selecting the field style
			exit = false; // Continue the start menu
		default:
			break;
		}
	} while (!exit);
}

void restart_Menu()
{
	int menu = Win_Logo(); // Display the win logo and options
	if (menu == 1)
	{
		player_score = 0; // Reset player's score
		pc_score = 0; // Reset enemy's score
		end_game = false; // Reset the end game flag
		restart = true; // Set restart flag to true
		tactic_1 = false;
		tactic_2 = false;
	}
	else
	{
		restart = false; // Set restart flag to false, exit the game
	}
}