#pragma once
#include <fstream>
using namespace std;

char** Create_Field(int& size)
{
	char** field = new char* [size];

	for (int i = 0; i < size; i++)
	{
		field[i] = new char[size];

		for (int j = 0; j < size; j++)
		{
			field[i][j] = space;
		}
	}
	return field;
}


void Standart_Field(char** field_1, char** field_2, int& size)
{
		
	cout << "\n\n\n";

	printf("\t  /|==| Your Field  |==|\\       /|==| Enemy Field |==|\\\n");
	printf("\t  ||A|B|C|D|E|F|G|H|I|J||       ||A|B|C|D|E|F|G|H|I|J||\n");
	for (int i = 1; i < size - 1; i++)
	{
		if (i != 10)
		{
			printf("\t %d||%c|%c|%c|%c|%c|%c|%c|%c|%c|%c||", i, field_1[i][1], field_1[i][2], field_1[i][3], field_1[i][4], field_1[i][5], field_1[i][6], field_1[i][7], field_1[i][8], field_1[i][9], field_1[i][10]);
			printf("      %d||%c|%c|%c|%c|%c|%c|%c|%c|%c|%c||\n", i, field_2[i][1], field_2[i][2], field_2[i][3], field_2[i][4], field_2[i][5], field_2[i][6], field_2[i][7], field_2[i][8], field_2[i][9], field_2[i][10]);
		}
		else
		{
			printf("\t%d||%c|%c|%c|%c|%c|%c|%c|%c|%c|%c||", i, field_1[i][1], field_1[i][2], field_1[i][3], field_1[i][4], field_1[i][5], field_1[i][6], field_1[i][7], field_1[i][8], field_1[i][9], field_1[i][10]);
			printf("     %d||%c|%c|%c|%c|%c|%c|%c|%c|%c|%c||\n", i, field_2[i][1], field_2[i][2], field_2[i][3], field_2[i][4], field_2[i][5], field_2[i][6], field_2[i][7], field_2[i][8], field_2[i][9], field_2[i][10]);
		}
	}
	printf("\t  \\|===================|/       \\|===================|/\n");
}

void Alternative_1_Field_Print(char** field_1, char** field_2, int& size)
{
	cout << "\n\n\n";

	printf("\t  /|==| Your Field  |==|\\       /|==| Enemy Field |==|\\\n");
	printf("\t  ||A.B.C.D.E.F.G.H.I.J||       ||A.B.C.D.E.F.G.H.I.J||\n");
	for (int i = 1; i < size - 1; i++)
	{
		if (i != 10)
		{
			printf("\t %d||%c.%c.%c.%c.%c.%c.%c.%c.%c.%c||", i, field_1[i][1], field_1[i][2], field_1[i][3], field_1[i][4], field_1[i][5], field_1[i][6], field_1[i][7], field_1[i][8], field_1[i][9], field_1[i][10]);
			printf("      %d||%c.%c.%c.%c.%c.%c.%c.%c.%c.%c||\n", i, field_2[i][1], field_2[i][2], field_2[i][3], field_2[i][4], field_2[i][5], field_2[i][6], field_2[i][7], field_2[i][8], field_2[i][9], field_2[i][10]);
		}
		else
		{
			printf("\t%d||%c.%c.%c.%c.%c.%c.%c.%c.%c.%c||", i, field_1[i][1], field_1[i][2], field_1[i][3], field_1[i][4], field_1[i][5], field_1[i][6], field_1[i][7], field_1[i][8], field_1[i][9], field_1[i][10]);
			printf("     %d||%c.%c.%c.%c.%c.%c.%c.%c.%c.%c||\n", i, field_2[i][1], field_2[i][2], field_2[i][3], field_2[i][4], field_2[i][5], field_2[i][6], field_2[i][7], field_2[i][8], field_2[i][9], field_2[i][10]);
		}
	}
	printf("\t  \\|===================|/       \\|===================|/\n");

}

void Alternative_2_Field_Print(char** field_1, char** field_2, int& size)
{
	cout << "\n\n\n";

	printf("\t  /|==| Your Field  |==|\\       /|==| Enemy Field |==|\\\n");
	printf("\t  ||A B C D E F G H I J||       ||A B C D E F G H I J||\n");
	for (int i = 1; i < size - 1; i++)
	{
		if (i != 10)
		{
			printf("\t %d||%c %c %c %c %c %c %c %c %c %c||", i, field_1[i][1], field_1[i][2], field_1[i][3], field_1[i][4], field_1[i][5], field_1[i][6], field_1[i][7], field_1[i][8], field_1[i][9], field_1[i][10]);
			printf("      %d||%c %c %c %c %c %c %c %c %c %c||\n", i, field_2[i][1], field_2[i][2], field_2[i][3], field_2[i][4], field_2[i][5], field_2[i][6], field_2[i][7], field_2[i][8], field_2[i][9], field_2[i][10]);
		}
		else
		{
			printf("\t%d||%c %c %c %c %c %c %c %c %c %c||", i, field_1[i][1], field_1[i][2], field_1[i][3], field_1[i][4], field_1[i][5], field_1[i][6], field_1[i][7], field_1[i][8], field_1[i][9], field_1[i][10]);
			printf("     %d||%c %c %c %c %c %c %c %c %c %c||\n", i, field_2[i][1], field_2[i][2], field_2[i][3], field_2[i][4], field_2[i][5], field_2[i][6], field_2[i][7], field_2[i][8], field_2[i][9], field_2[i][10]);
		}
	}
	printf("\t  \\|===================|/       \\|===================|/\n");

}

void Alternative_3_Field_Print(char** field_1, char** field_2, int& size)
{
	cout << "\n\n\n";

	printf("\t  /|==| Your Field  |==|\\       /|==| Enemy Field |==|\\\n");
	printf("\t  ||A_B_C_D_E_F_G_H_I_J||       ||A_B_C_D_E_F_G_H_I_J||\n");
	for (int i = 1; i < size - 1; i++)
	{
		if (i != 10)
		{
			printf("\t %d||%c_%c_%c_%c_%c_%c_%c_%c_%c_%c||", i, field_1[i][1], field_1[i][2], field_1[i][3], field_1[i][4], field_1[i][5], field_1[i][6], field_1[i][7], field_1[i][8], field_1[i][9], field_1[i][10]);
			printf("      %d||%c_%c_%c_%c_%c_%c_%c_%c_%c_%c||\n", i, field_2[i][1], field_2[i][2], field_2[i][3], field_2[i][4], field_2[i][5], field_2[i][6], field_2[i][7], field_2[i][8], field_2[i][9], field_2[i][10]);
		}
		else
		{
			printf("\t%d||%c_%c_%c_%c_%c_%c_%c_%c_%c_%c||", i, field_1[i][1], field_1[i][2], field_1[i][3], field_1[i][4], field_1[i][5], field_1[i][6], field_1[i][7], field_1[i][8], field_1[i][9], field_1[i][10]);
			printf("     %d||%c_%c_%c_%c_%c_%c_%c_%c_%c_%c||\n", i, field_2[i][1], field_2[i][2], field_2[i][3], field_2[i][4], field_2[i][5], field_2[i][6], field_2[i][7], field_2[i][8], field_2[i][9], field_2[i][10]);
		}
	}
	printf("\t  \\|===================|/       \\|===================|/\n");

}



void Field_Print(char** field_1, char** field_2, int& size)
{
	system("cls");	
	switch (f_style)
	{
	case 0:
		Standart_Field(field_1, field_2, size);
		break;
	case 1:
		Alternative_1_Field_Print(field_1, field_2, size);
		break;
	case 2:
		Alternative_1_Field_Print(field_1, field_2, size);
		break;
	case 3:
		Alternative_1_Field_Print(field_1, field_2, size);
		break;
	default:
		break;
	}
}