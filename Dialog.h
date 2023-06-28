#pragma once
#include <string>
using namespace std;



struct Ship
{
	bool on_watter = false;
	int number = 0;
	int letter = 0;
	int orient = 0;
	int ship_size = 0;

	void save(bool in_on_watter, int in_number, int in_letter, int in_orient, int in_ship_size)
	{
		on_watter = in_on_watter;
		number = in_number;
		letter = in_letter;
		orient = in_orient;
		ship_size = in_ship_size;
	}
};
int Check_Input(char input)
{
	int letter = -1;
	if (input >= 65 && input <= 74)
	{
		letter = input - 65;
		return letter;
	}
	else if (input >= 97 && input <= 106)
	{
		letter = input - 97;
		return letter;
	}
	/*if (input == 'a' || input == 'A')
	{
		letter = 1;
		
	}
	else if (input == 'b' || input == 'B')
	{
		letter = 2;
	}
	else if (input == 'c' || input == 'C')
	{
		letter = 3;
	}
	else if (input == 'd' || input == 'D')
	{
		letter = 4;
	}
	else if (input == 'e' || input == 'E')
	{
		letter = 5;
	}
	else if (input == 'f' || input == 'F')
	{
		letter = 6;
	}
	else if (input == 'g' || input == 'G')
	{
		letter = 7;
	}
	else if (input == 'h' || input == 'H')
	{
		letter = 8;
	}
	else if (input == 'i' || input == 'I')
	{
		letter = 9;
	}
	else if (input == 'j' || input == 'J')
	{
		letter = 10;
	}*/
	return letter;
}

int* Input(int& size)
{
	char letter_in = '0';
	int number = 0;
	int letter = 0;

input_start:

	cout << "\n\n\tEnter Letter and Number ";	cin >> letter_in;	cin >> number;

	letter = Check_Input(letter_in);

	if (letter != -1 && number != 0 && number <= 10)
	{
		
		letter++;
	}
	else
	{
		goto input_start;
	}

	int* arr = new int[size];
	arr[0] = number;
	arr[1] = letter;
	return arr;
}



int Place_check(int ship_size, int orient, char** field, int& size, int* input, int input_size)
{
	switch (orient)
	{
	case 1:
		if (input[0] + ship_size > 11)
		{
			return 1;
		}
		for (int i = 0; i < ship_size + 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (field[input[0] + i - 1][input[1] + j - 1] != space)
				{
					return 1;
				}
			}
			
		}
		
		break;
	case 2:
		if (input[1] + ship_size > 11)
		{
			return 1;
		}
		for (int i = 0; i < ship_size + 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (field[input[0] + j - 1][input[1] + i - 1] != space)
				{
					return 1;
				}
			}

		}
		break;
	default:
		break;
	}
	return 0;
}



Ship* Ship_Placer(char** field_1_Player, char** field_2_Enemy, int& size, int& ship_count)
{
	Ship* Players_Ships = new Ship[ship_count];

	char ship_c = ship;
	int ship_4 = 1;
	int ship_3 = 2;
	int ship_2 = 3;
	int ship_1 = 4;
	int ship_size = 4;
	ship_count = -1;

continue_placing:

	Field_Print(field_1_Player, field_2_Enemy, size);

	cout << "\n\tAvilable ships:\n\t";
	cout << "\n\t" << ship_c << ship_c << ship_c << ship_c << " X " << ship_4;
	cout << "\n\t" << ship_c << ship_c << ship_c << " X " << ship_3;
	cout << "\n\t" << ship_c << ship_c << " X " << ship_2;
	cout << "\n\t" << ship_c << " X " << ship_1;

enter_coordinates:

	cout << "\n\n\tEnter base coordinates\n";
	int input_size = 2;
	int* input = Input(input_size);

	int orient = 0;
	cout << "\n\n\tEnter orientation\n";	cin >> orient;
	

	if (Place_check(ship_size, orient, field_1_Player, size, input, input_size))
	{
		cerr << "\n\n\tWrong place";
		goto enter_coordinates;
	}
	else
	{
		ship_count++;
		Players_Ships[ship_count].save(true, input[0], input[1], orient, ship_size);
	}

	switch (orient)
	{
	case 1: //vertical
		
		for (int i = 0; i < ship_size; i++)
		{
			field_1_Player[input[0] + i][input[1]] = ship_c;

		}
		break;
	case 2: //horizontal
		for (int i = 0; i < ship_size; i++)
		{
			field_1_Player[input[0]][input[1] + i] = ship_c;
		}
		break;
	default:
		break;
	}

	if (ship_4)
	{
		ship_4--;
	}
	else if (ship_3)
	{
		ship_3--;
	}
	else if (ship_2)
	{
		ship_2--;
	}
	else if (ship_1)
	{
		ship_1--;
	}

	if (ship_3)
	{
		ship_size = 3;
	}
	else if (ship_2)
	{
		ship_size = 2;
	}
	else if (ship_1)
	{
		ship_size = 1;
	}
	else
	{
		ship_size = 0;
	}

	if (ship_size)
	{
		goto continue_placing;
	}

	return Players_Ships;
}

Ship* Random_Ship_Placer(char** field, int& size, int& ship_count)
{
	Ship* Ships_arr = new Ship[ship_count];
	
	char ship_c = ship;
	int ship_4 = 1;
	int ship_3 = 2;
	int ship_2 = 3;
	int ship_1 = 4;
	int ship_size = 4;
	ship_count = -1;

continue_placing:
enter_coordinates:

	const int input_size = 2;
	int* input = new int[input_size];
	int ran = rand() % 10 + 1;
	input[0] = ran;
	ran = rand() % 10 + 1;
	input[1] = ran;
	ran = rand() % 100;
	int orient = 0;
	if (ran > 50)
	{
		orient = 2;
	}
	else
	{
		orient = 1;
	}
	if (Place_check(ship_size, orient, field, size, input, input_size))
	{
		goto enter_coordinates;
	}
	else
	{
		ship_count++;
		Ships_arr[ship_count].save(true, input[0], input[1], orient, ship_size);
	}

	switch (orient)
	{
	case 1:

		for (int i = 0; i < ship_size; i++)
		{
			field[input[0] + i][input[1]] = ship_c;
		}
		break;
	case 2:
		for (int i = 0; i < ship_size; i++)
		{
			field[input[0]][input[1] + i] = ship_c;
		}
		break;
	default:
		break;
	}
	if (ship_4)
	{
		ship_4--;
	}
	else if (ship_3)
	{
		ship_3--;
	}
	else if (ship_2)
	{
		ship_2--;
	}
	else if (ship_1)
	{
		ship_1--;
	}
	if (ship_3)
	{
		ship_size = 3;
	}
	else if (ship_2)
	{
		ship_size = 2;
	}
	else if (ship_1)
	{
		ship_size = 1;
	}
	else
	{
		ship_size = 0;
	}
	if (ship_size)
	{
		goto continue_placing;
	}
	ship_count = 10;
	return Ships_arr;
}

void Style_Menu()
{
	int size = 12;
	int ship_count = 10;
	char** Style_demo = Create_Field(size);
	char** Style_demo_blink = Create_Field(size);

	Ship* demo = Random_Ship_Placer(Style_demo, size, ship_count);

	cout << "\n\n\t\tStyle - 0\n";
	Standart_Field(Style_demo, Style_demo_blink, size);

	cout << "\n\n\t\tStyle - 1\n";
	Alternative_1_Field_Print(Style_demo, Style_demo_blink, size);

	cout << "\n\n\t\tStyle - 2\n";
	Alternative_2_Field_Print(Style_demo, Style_demo_blink, size);

	cout << "\n\n\t\tStyle - 3\n";
	Alternative_3_Field_Print(Style_demo, Style_demo_blink, size);

	int menu = 0;

	cout << "\n\n\tEnter style num: ";	cin >> menu;
	switch (menu)
	{
	case 0:
		f_style = 0;
		break;
	case 1:
		f_style = 1;
		break;
	case 2:
		f_style = 2;
		break;
	case 3:
		f_style = 3;
		break;
	default:
		break;
	}
}
Ship* Play_Menu(char** field_1_Player, char** field_2_Enemy, int& size, int& ship_count)
{
	int menu = 0;
	cout << "\n\n\t1 -- Auto place ships\n\t2 -- Manual place ships\n\t";	cin >> menu;

	switch (menu)
	{
	case 1:
		Ship * Players_Ships = Random_Ship_Placer(field_1_Player, size, ship_count);
		return Players_Ships;
		break;
	case 2:
		Ship * Players_Ships = Ship_Placer(field_1_Player, field_2_Enemy, size, ship_count);
		return Players_Ships;
		break;
	default:
		break;
	}
}
Ship* Start_Menu(char** field_1_Player, char** field_2_Enemy, int& size, int& ship_count)
{
start_menu:

	int menu = 0;
	cout << "\n\n\t1 -- Play\n\t2 -- Change style\n\t";	cin >> menu;

	switch (menu)
	{
	case 1:
		 Ship* Players_Ships = Play_Menu(field_1_Player, field_2_Enemy, size, ship_count);
		 return Players_Ships;
		break;
	case 2:
		Style_Menu();
		goto start_menu;
		break;
	default:
		break;
	}

}

