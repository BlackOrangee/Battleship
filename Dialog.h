#pragma once
#include <string>
using namespace std;

// Definition of the Ship struct
struct Ship
{
	bool on_watter = false; // Flag to indicate if the ship is on water (initialized to false by default)
	int number = 0; // Base number coordinate of the ship
	int letter = 0; // Base letter coordinate of the ship
	int orient = 0; // Orientation of the ship (1 for vertical, 2 for horizontal)
	int ship_size = 0; // Size of the ship

	// Method to save ship details
	void save(bool in_on_watter, int in_number, int in_letter, int in_orient, int in_ship_size)
	{
		on_watter = in_on_watter; // Set the on_watter flag
		number = in_number; // Set the number coordinate
		letter = in_letter; // Set the letter coordinate
		orient = in_orient; // Set the ship orientation
		ship_size = in_ship_size; // Set the ship size
	}
};

// User input function
// 
int* Input(int& size)
{
	char letter_in = NULL;
	int number = 0;
	int letter = 0;
	string str;

	do
	{
		number = 0;
		letter = 0;

		cout << "\n\n\tEnter Letter and Number ";
		cin >> str;

		for (int i = 0; i < str.length(); i++)
		{
			// Checking if the character is an uppercase letter (A to J)
			if (str[i] >= 65 && str[i] <= 74)
			{
				letter_in = str[i];
				letter = letter_in;
				letter = letter - 65; // Convert letter to a number between 0 and 9
				letter++;
			}
			// Checking if the character is a lowercase letter (a to j)
			else if (str[i] >= 97 && str[i] <= 106)
			{
				letter_in = str[i];
				letter = letter_in;
				letter = letter - 97; // Convert letter to a number between 0 and 9
				letter++;
			}

			// Checking if the character is a digit (1 to 9)
			if (i == 0)
			{
				continue; // Skip the first character
			}
			if ((str[i] >= 49 && str[i] <= 57) && i != str.length())
			{
				number = str[i] - 48; // Convert the character to the corresponding digit
			}
			// Checking if the number is 10 (represented as "10" or "1" followed by "0")
			else if (i != 0 && str[i - 1] == 49 && str[i] == 48)
			{
				number = 10;
			}
		}
	} while (letter == 0 || number == 0 || number > 10);

	int* arr = new int[size];
	arr[0] = number; // Store the number at index 0 of the array
	arr[1] = letter; // Store the letter at index 1 of the array
	return arr;
}

// Check the area around the ship for vertical orientation
int Place_check_vertical(int ship_size, char** field, int& size, int* input, int input_size)
{
	for (int i = 0; i < ship_size + 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (field[input[0] + i - 1][input[1] + j - 1] != space)
			{
				return 1; // Return 1 if any adjacent position is occupied
			}
		}
	}
	return 0; // Return 0 if all adjacent positions are free
}

// Check the area around the ship for horizontal orientation
int Place_check_horizontal(int ship_size, char** field, int& size, int* input, int input_size)
{
	for (int i = 0; i < ship_size + 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (field[input[0] + j - 1][input[1] + i - 1] != space)
			{
				return 1; // Return 1 if any adjacent position is occupied
			}
		}
	}
	return 0; // Return 0 if all adjacent positions are free
}

// Check the validity of the ship placement
int Place_check(int ship_size, int orient, char** field, int& size, int* input, int input_size)
{
	if (orient == 1) // Vertical orientation
	{
		if (input[0] + ship_size > 11)
		{
			return 1; // Return 1 if the ship goes beyond the field boundaries
		}
		return Place_check_vertical(ship_size, field, size, input, input_size);
	}
	else if (orient == 2) // Horizontal orientation
	{
		if (input[1] + ship_size > 11)
		{
			return 1; // Return 1 if the ship goes beyond the field boundaries
		}
		return Place_check_horizontal(ship_size, field, size, input, input_size);
	}
	return 0; // Return 0 for an invalid orientation (should not happen)
}

// Print the available ships and their counts
void Avilable_ships_Print(char& ship_c, int& ship_1, int& ship_2, int& ship_3, int& ship_4)
{
	cout << "\n\tAvilable ships:\n\t"; // Print the header for available ships
	cout << "\n\t" << ship_c << ship_c << ship_c << ship_c << " X " << ship_4; // Print the count of ship_4
	cout << "\n\t" << ship_c << ship_c << ship_c << " X " << ship_3; // Print the count of ship_3
	cout << "\n\t" << ship_c << ship_c << " X " << ship_2; // Print the count of ship_2
	cout << "\n\t" << ship_c << " X " << ship_1; // Print the count of ship_1
}

// Decrement ship counts based on availability
void ship_decrimenter(int& ship_1, int& ship_2, int& ship_3, int& ship_4)
{
	if (ship_4)
	{
		ship_4--; // Decrement ship_4 count
	}
	else if (ship_3)
	{
		ship_3--; // Decrement ship_3 count
	}
	else if (ship_2)
	{
		ship_2--; // Decrement ship_2 count
	}
	else if (ship_1)
	{
		ship_1--; // Decrement ship_1 count
	}
}

// Determine the ship size based on availability
void ship_sizer(int& ship_1, int& ship_2, int& ship_3, int& ship_size)
{
	if (ship_3)
	{
		ship_size = 3; // Set ship_size to 3 if ship_3 count is available
	}
	else if (ship_2)
	{
		ship_size = 2; // Set ship_size to 2 if ship_2 count is available
	}
	else if (ship_1)
	{
		ship_size = 1; // Set ship_size to 1 if ship_1 count is available
	}
	else
	{
		ship_size = 0; // Set ship_size to 0 if no ships are available
	}
}

void Place_Ship_to_the_field(int& orient, int& ship_size, char& ship_c, int* input, int& input_size, char** field, int& size)
{
	if (orient == 1) // Vertical orientation
	{
		for (int i = 0; i < ship_size; i++)
		{
			field[input[0] + i][input[1]] = ship_c; // Place the ship symbol in the field_1_Player array for each position of the ship
		}
	}
	else if (orient == 2) // Horizontal orientation
	{
		for (int i = 0; i < ship_size; i++)
		{
			field[input[0]][input[1] + i] = ship_c; // Place the ship symbol in the field_1_Player array for each position of the ship
		}
	}
}

// Place ships on the field
Ship* Ship_Placer(char** field_1_Player, char** field_2_Enemy, int& size, int ship_count)
{
	Ship* Players_Ships = new Ship[ship_count];

	char ship_c = ship; // Character symbol for the ships
	int ship_4 = 1; // Initial count of ship_4
	int ship_3 = 2; // Initial count of ship_3
	int ship_2 = 3; // Initial count of ship_2
	int ship_1 = 4; // Initial count of ship_1
	int ship_size = 4; // Initial ship size (starting with the largest ship)
	ship_count = -1; // Initialize ship_count to -1

	do
	{
		Field_Print(field_1_Player, field_2_Enemy, size); // Print the fields
		Avilable_ships_Print(ship_c, ship_1, ship_2, ship_3, ship_4); // Print available ships

		int* input = NULL;
		int input_size = 2;
		int orient = 0;
		
		do
		{
			if (orient)
			{
				cerr << "\n\tWrong place\n"; // Print error message for incorrect placement
			}

			cout << "\n\tEnter base coordinates";
			input = Input(input_size);

			if (ship_size != 1)
			{
				orient = 0;
				cout << "\n\tEnter orientation:\n\t1 -- Vertical\n\t2 -- Horizontal\n\t";	cin >> orient; // Get the ship orientation from the user
			}
			else
			{
				orient = 1;
			}
		} while (Place_check(ship_size, orient, field_1_Player, size, input, input_size)); // Check the validity of the ship placement

		ship_count++;
		Players_Ships[ship_count].save(true, input[0], input[1], orient, ship_size); // Save ship details in Players_Ships array

		Place_Ship_to_the_field(orient, ship_size, ship_c, input, input_size, field_1_Player, size);

		ship_decrimenter(ship_1, ship_2, ship_3, ship_4); // Decrement ship counts based on the ship size
		ship_sizer(ship_1, ship_2, ship_3, ship_size); // Determine the next ship size based on available counts

	} while (ship_size);

	return Players_Ships; // Return the array of placed ships
}

// Randomly determine the ship orientation
void Random_orient(int& ran, int& orient)
{
	if (ran > 50)
	{
		orient = 2; // Set orientation to 2 (horizontal) if ran is greater than 50
	}
	else
	{
		orient = 1; // Set orientation to 1 (vertical) if ran is less than or equal to 50
	}
}

// Randomly place ships on the field
Ship* Random_Ship_Placer(char** field, int& size, int ship_count)
{
	Ship* Ships_arr = new Ship[ship_count];

	char ship_c = ship; // Character symbol for the ships
	int ship_4 = 1; // Initial count of ship_4
	int ship_3 = 2; // Initial count of ship_3
	int ship_2 = 3; // Initial count of ship_2
	int ship_1 = 4; // Initial count of ship_1
	int ship_size = 4; // Initial ship size (starting with the largest ship)
	ship_count = -1; // Initialize ship_count to -1
	int input_size = 2;
	int* input = new int[input_size]; // Array to store input coordinates
	int ran = 0; // Random number for determining coordinates and orientation
	int orient = 0; // Ship orientation

	do
	{
		do
		{
			ran = rand() % 10 + 1; // Generate a random number between 1 and 10 for x-coordinate
			input[0] = ran;
			ran = rand() % 10 + 1; // Generate a random number between 1 and 10 for y-coordinate
			input[1] = ran;
			ran = rand() % 100; // Generate a random number between 0 and 99
			orient = 0;

			Random_orient(ran, orient); // Randomly determine the ship orientation

		} while (Place_check(ship_size, orient, field, size, input, input_size)); // Check the validity of the random ship placement

		ship_count++;
		Ships_arr[ship_count].save(true, input[0], input[1], orient, ship_size); // Save ship details in Ships_arr array

		Place_Ship_to_the_field(orient, ship_size, ship_c, input, input_size, field, size); // Place the ship on the field
		ship_decrimenter(ship_1, ship_2, ship_3, ship_4); // Decrement ship counts based on the ship size
		ship_sizer(ship_1, ship_2, ship_3, ship_size); // Determine the next ship size based on available counts

	} while (ship_size);

	return Ships_arr; // Return the array of placed ships
}

// Count the number of ships of each size for statistics
void Statistic_Counter(Ship* ships, int ship_count, int& i, int& ship_1, int& ship_2, int& ship_3, int& ship_4)
{
	if (ships[i].on_watter) // Check if the ship is on the water
	{
		if (ships[i].ship_size == 4) // Check if the ship size is 4
		{
			ship_4++; // Increment the count of 4-sized ships
		}
		else if (ships[i].ship_size == 3) // Check if the ship size is 3
		{
			ship_3++; // Increment the count of 3-sized ships
		}
		else if (ships[i].ship_size == 2) // Check if the ship size is 2
		{
			ship_2++; // Increment the count of 2-sized ships
		}
		else if (ships[i].ship_size == 1) // Check if the ship size is 1
		{
			ship_1++; // Increment the count of 1-sized ships
		}
	}
}

// Print the game statistics
void Print_Game_Statistic(int& p_ship_1, int& p_ship_2, int& p_ship_3, int& p_ship_4, int& pc_ship_1, int& pc_ship_2, int& pc_ship_3, int& pc_ship_4)
{
	cout << "\n\tYour ships:\t\t\tEnemy's ships\n\t";

	// Print the count of 4-sized ships for the player and the enemy
	cout << "\n\t" << ship << ship << ship << ship << " X " << p_ship_4 << "\t\t\t" << ship << ship << ship << ship << " X " << pc_ship_4;

	// Print the count of 3-sized ships for the player and the enemy
	cout << "\n\t" << ship << ship << ship << " X " << p_ship_3 << "\t\t\t\t" << ship << ship << ship << " X " << pc_ship_3;

	// Print the count of 2-sized ships for the player and the enemy
	cout << "\n\t" << ship << ship << " X " << p_ship_2 << "\t\t\t\t" << ship << ship << " X " << pc_ship_2;

	// Print the count of 1-sized ships for the player and the enemy
	cout << "\n\t" << ship << " X " << p_ship_1 << "\t\t\t\t" << ship << " X " << pc_ship_1;
}

// Calculate and print the game statistics
void Statistic(Ship* player, Ship* pc, int ship_count)
{
	ship_count = 10; // Set the ship count to 10

	// Initialize variables for player ship counts
	int p_ship_4 = 0;
	int p_ship_3 = 0;
	int p_ship_2 = 0;
	int p_ship_1 = 0;

	// Initialize variables for enemy ship counts
	int pc_ship_4 = 0;
	int pc_ship_3 = 0;
	int pc_ship_2 = 0;
	int pc_ship_1 = 0;

	// Iterate through each ship and update the ship counts
	for (int i = 0; i < ship_count; i++)
	{
		Statistic_Counter(player, ship_count, i, p_ship_1, p_ship_2, p_ship_3, p_ship_4); // Update player ship counts
		Statistic_Counter(pc, ship_count, i, pc_ship_1, pc_ship_2, pc_ship_3, pc_ship_4); // Update enemy ship counts
	}

	// Print the game statistics
	Print_Game_Statistic(p_ship_1, p_ship_2, p_ship_3, p_ship_4, pc_ship_1, pc_ship_2, pc_ship_3, pc_ship_4);
}

void Tactic_Determinator()
{
	if ((rand() % 100) >= 50)
	{
		tactic_1 = true;
	}
	if ((rand() % 100) >= 50)
	{
		tactic_2 = true;
	}
}
