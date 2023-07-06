#pragma once
using namespace std;

// This function represents the AI logic to check the ship's status and make the next move.
//void PC_AI_Check_Ship(char** field_visible, int& size, Ship* ships, int& ships_count, int* arr, int& arr_size)
//{
//	
//	int ranv1 = rand() % 100;
//	int ranv2 = rand() % 100;
//	int ranv3 = rand() % 100;
//	int ranv4 = rand() % 100;
//
//	int ranh1 = rand() % 100;
//	int ranh2 = rand() % 100;
//	int ranh3 = rand() % 100;
//	int ranh4 = rand() % 100;
//
//	for (int k = 0; k < ships_count; k++)
//	{
//		if (ships[k].on_watter == false)
//		{
//			continue;
//		}
//		if (ships[k].orient == 1) // Vertical orientation
//		{
//			for (int i = 0; i < ships[k].ship_size; i++)
//			{
//				if (field_visible[ships[k].number + i][ships[k].letter] == cross
//					&& (field_visible[ships[k].number + i - 1][ships[k].letter] == cross
//						|| field_visible[ships[k].number + i + 1][ships[k].letter] == cross))
//				{
//					if (ranv1 >= 50)
//					{
//						if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 11)
//						{
//							arr[0] = ships[k].number + i + 1;
//							arr[1] = ships[k].letter;
//						}
//						else if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)//
//						{
//							arr[0] = ships[k].number + i - 1;
//							arr[1] = ships[k].letter;
//						}
//						else
//						{
//							continue;
//						}
//						break;
//					}
//					else
//					{
//						if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)//
//						{
//							arr[0] = ships[k].number + i - 1;
//							arr[1] = ships[k].letter;
//						}
//						else if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 11)
//						{
//							arr[0] = ships[k].number + i + 1;
//							arr[1] = ships[k].letter;
//						}
//						else
//						{
//							continue;
//						}
//						break;
//					}
//				}
//				else if (field_visible[ships[k].number + i][ships[k].letter] == cross)
//				{
//					if (ranv2 <= difficulty)
//					{
//						if (ranv3 >= 50)
//						{
//							if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 11)
//							{
//								arr[0] = ships[k].number + i + 1;
//								arr[1] = ships[k].letter;
//							}
//							else if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)
//							{
//								arr[0] = ships[k].number + i - 1;
//								arr[1] = ships[k].letter;
//							}
//							if (field_visible[ships[k].number + i][ships[k].letter + 1] == space && ships[k].letter + 1 != 11)
//							{
//								arr[0] = ships[k].number + i;
//								arr[1] = ships[k].letter + 1;
//							}
//							else if (field_visible[ships[k].number + i][ships[k].letter - 1] == space && ships[k].letter - 1 != 0)
//							{
//								arr[0] = ships[k].number + i;
//								arr[1] = ships[k].letter - 1;
//							}
//							else
//							{
//								continue;
//							}
//							break;
//						}
//						else
//						{
//							if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)
//							{
//								arr[0] = ships[k].number + i - 1;
//								arr[1] = ships[k].letter;
//							}
//							else if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 11)
//							{
//								arr[0] = ships[k].number + i + 1;
//								arr[1] = ships[k].letter;
//							}
//							if (field_visible[ships[k].number + i][ships[k].letter + 1] == space && ships[k].letter + 1 != 11)
//							{
//								arr[0] = ships[k].number + i;
//								arr[1] = ships[k].letter + 1;
//							}
//							else if (field_visible[ships[k].number + i][ships[k].letter - 1] == space && ships[k].letter - 1 != 0)
//							{
//								arr[0] = ships[k].number + i;
//								arr[1] = ships[k].letter - 1;
//							}
//							else
//							{
//								continue;
//							}
//							break;
//						}
//					}
//					else
//					{
//						if (ranv4 >= 50)
//						{
//							if (field_visible[ships[k].number + i][ships[k].letter + 1] == space && ships[k].letter + 1 != 11)
//							{
//								arr[0] = ships[k].number + i;
//								arr[1] = ships[k].letter + 1;
//							}
//							else if (field_visible[ships[k].number + i][ships[k].letter - 1] == space && ships[k].letter - 1 != 0)
//							{
//								arr[0] = ships[k].number + i;
//								arr[1] = ships[k].letter - 1;
//							}
//							else if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 11)
//							{
//								arr[0] = ships[k].number + i + 1;
//								arr[1] = ships[k].letter;
//							}
//							else if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)
//							{
//								arr[0] = ships[k].number + i - 1;
//								arr[1] = ships[k].letter;
//							}
//							else
//							{
//								continue;
//							}
//							break;
//						}
//						else
//						{
//							if (field_visible[ships[k].number + i][ships[k].letter - 1] == space && ships[k].letter - 1 != 0)
//							{
//								arr[0] = ships[k].number + i;
//								arr[1] = ships[k].letter - 1;
//							}
//							else if (field_visible[ships[k].number + i][ships[k].letter + 1] == space && ships[k].letter + 1 != 11)
//							{
//								arr[0] = ships[k].number + i;
//								arr[1] = ships[k].letter + 1;
//							}
//							else if (field_visible[ships[k].number + i + 1][ships[k].letter] == space && ships[k].number + i + 1 != 11)
//							{
//								arr[0] = ships[k].number + i + 1;
//								arr[1] = ships[k].letter;
//							}
//							else if (field_visible[ships[k].number + i - 1][ships[k].letter] == space && ships[k].number + i - 1 != 0)
//							{
//								arr[0] = ships[k].number + i - 1;
//								arr[1] = ships[k].letter;
//							}
//							else
//							{
//								continue;
//							}
//							break;
//						}
//					}
//				}
//			}
//		}
//		else if (ships[k].orient == 2)
//		{
//			for (int i = 0; i < ships[k].ship_size; i++)
//			{
//				if (field_visible[ships[k].number][ships[k].letter + i] == cross
//					&& (field_visible[ships[k].number][ships[k].letter + i - 1] == cross
//						|| field_visible[ships[k].number][ships[k].letter + i + 1] == cross))
//				{
//					if (ranh1 >= 50)
//					{
//						if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 11)
//						{
//							arr[0] = ships[k].number;
//							arr[1] = ships[k].letter + i + 1;
//						}
//						else if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
//						{
//							arr[0] = ships[k].number;
//							arr[1] = ships[k].letter + i - 1;
//						}
//						else
//						{
//							continue;
//						}
//						break;
//					}
//					else
//					{
//						if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
//						{
//							arr[0] = ships[k].number;
//							arr[1] = ships[k].letter + i - 1;
//						}
//						else if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 11)
//						{
//							arr[0] = ships[k].number;
//							arr[1] = ships[k].letter + i + 1;
//						}
//						else
//						{
//							continue;
//						}
//						break;
//					}
//				}
//				else if (field_visible[ships[k].number][ships[k].letter + i] == cross)
//				{
//					if (ranh2 <= difficulty)
//					{
//						if (ranh3 >= 50)
//						{
//							if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
//							{
//								arr[0] = ships[k].number;
//								arr[1] = ships[k].letter + i - 1;
//							}
//							else if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 11)
//							{
//								arr[0] = ships[k].number;
//								arr[1] = ships[k].letter + i + 1;
//							}
//							else if (field_visible[ships[k].number + 1][ships[k].letter + i] == space && ships[k].number + 1 != 11)
//							{
//								arr[0] = ships[k].number + 1;
//								arr[1] = ships[k].letter + i;
//							}
//							else if (field_visible[ships[k].number - 1][ships[k].letter + i] == space && ships[k].number - 1 != 0)
//							{
//								arr[0] = ships[k].number - 1;
//								arr[1] = ships[k].letter + i;
//							}
//							else
//							{
//								continue;
//							}
//							break;
//						}
//						else
//						{
//							if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 11)
//							{
//								arr[0] = ships[k].number;
//								arr[1] = ships[k].letter + i + 1;
//							}
//							else if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
//							{
//								arr[0] = ships[k].number;
//								arr[1] = ships[k].letter + i - 1;
//							}
//							else if (field_visible[ships[k].number + 1][ships[k].letter + i] == space && ships[k].number + 1 != 11)
//							{
//								arr[0] = ships[k].number + 1;
//								arr[1] = ships[k].letter + i;
//							}
//							else if (field_visible[ships[k].number - 1][ships[k].letter + i] == space && ships[k].number - 1 != 0)
//							{
//								arr[0] = ships[k].number - 1;
//								arr[1] = ships[k].letter + i;
//							}
//							else
//							{
//								continue;
//							}
//							break;
//						}
//					}
//					else
//					{
//						if (ranh4 >= 50)
//						{
//							if (field_visible[ships[k].number - 1][ships[k].letter + i] == space && ships[k].number - 1 != 0)
//							{
//								arr[0] = ships[k].number - 1;
//								arr[1] = ships[k].letter + i;
//							}
//							else if (field_visible[ships[k].number + 1][ships[k].letter + i] == space && ships[k].number + 1 != 11)
//							{
//								arr[0] = ships[k].number + 1;
//								arr[1] = ships[k].letter + i;
//							}
//							else if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
//							{
//								arr[0] = ships[k].number;
//								arr[1] = ships[k].letter + i - 1;
//							}
//							else if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 11)
//							{
//								arr[0] = ships[k].number;
//								arr[1] = ships[k].letter + i + 1;
//							}
//							else
//							{
//								continue;
//							}
//							break;
//						}
//						else
//						{
//							if (field_visible[ships[k].number - 1][ships[k].letter + i] == space && ships[k].number - 1 != 0)
//							{
//								arr[0] = ships[k].number - 1;
//								arr[1] = ships[k].letter + i;
//							}
//							else if (field_visible[ships[k].number + 1][ships[k].letter + i] == space && ships[k].number + 1 != 11)
//							{
//								arr[0] = ships[k].number + 1;
//								arr[1] = ships[k].letter + i;
//							}
//							else if (field_visible[ships[k].number][ships[k].letter + i + 1] == space && ships[k].letter + i + 1 != 11)
//							{
//								arr[0] = ships[k].number;
//								arr[1] = ships[k].letter + i + 1;
//							}
//							else if (field_visible[ships[k].number][ships[k].letter + i - 1] == space && ships[k].letter + i - 1 != 0)
//							{
//								arr[0] = ships[k].number;
//								arr[1] = ships[k].letter + i - 1;
//							}
//							else
//							{
//								continue;
//							}
//							break;
//						}
//					}
//				}
//			}
//		}
//	}
//}


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
	

	for (int k = 0; k < ships_count; k++)
	{
		if (ships[k].on_watter == false)
		{
			continue;
		}

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
		}
		else
		{
			R_6 = 1;
		}

		if (ships[k].orient == 1) // Vertical orientation
		{
			for (int i = 0; i < ships[k].ship_size; i++)
			{
				if (field_visible[ships[k].number + i][ships[k].letter] == cross
					&& (field_visible[ships[k].number + i - 1][ships[k].letter] == cross
						|| field_visible[ships[k].number + i + 1][ships[k].letter] == cross))
				{
					if (field_visible[ships[k].number + i + R_5 - R_6][ships[k].letter] == space 
						&& ships[k].number + i + R_5 - R_6 != 11 
						&& ships[k].number + i + R_5 - R_6 != 0)
					{
						arr[0] = ships[k].number + i + R_5 - R_6;
						arr[1] = ships[k].letter;
					}
					else if (field_visible[ships[k].number + i + R_6 - R_5][ships[k].letter] == space 
						&& ships[k].number + i + R_6 - R_5 != 11 
						&& ships[k].number + i + R_6 - R_5 != 0)//
					{
						arr[0] = ships[k].number + i + R_6 - R_5;
						arr[1] = ships[k].letter;
					}
					else
					{
						continue;
					}
					break;
				}
				else if (field_visible[ships[k].number + i][ships[k].letter] == cross)
				{
					if (field_visible[ships[k].number + i + R_1 - R_2][ships[k].letter + R_3 - R_4] == space
						&& (ships[k].number + i + R_1 - R_2 != 11
							&& ships[k].number + i + R_1 - R_2 != 0
							&& ships[k].letter + R_3 - R_4 != 11
							&& ships[k].letter + R_3 - R_4 != 0))
					{
						arr[0] = ships[k].number + i + R_1 - R_2;
						arr[1] = ships[k].letter + R_3 - R_4;
					}
					else if (field_visible[ships[k].number + i + R_2 - R_1][ships[k].letter + R_4 - R_3] == space
						&& (ships[k].number + i + R_2 - R_1 != 11
							&& ships[k].number + i + R_2 - R_1 != 0
							&& ships[k].letter + R_4 - R_3 != 11
							&& ships[k].letter + R_4 - R_3 != 0))
					{
						arr[0] = ships[k].number + i + R_2 - R_1;
						arr[1] = ships[k].letter + R_4 - R_3;
					}
					else if (field_visible[ships[k].number + i + R_3 - R_4][ships[k].letter + R_1 - R_2] == space
						&& (ships[k].number + i + R_3 - R_4 != 11
							&& ships[k].number + i + R_3 - R_4 != 0
							&& ships[k].letter + R_1 - R_2 != 11
							&& ships[k].letter + R_1 - R_2 != 0))
					{
						arr[0] = ships[k].number + i + R_3 - R_4;
						arr[1] = ships[k].letter + R_1 - R_2;
					}
					else if (field_visible[ships[k].number + i + R_4 - R_3][ships[k].letter + R_2 - R_1] == space
						&& (ships[k].number + i + R_4 - R_3 != 11
							&& ships[k].number + i + R_4 - R_3 != 0
							&& ships[k].letter + R_2 - R_1 != 11
							&& ships[k].letter + R_2 - R_1 != 0))
					{
						arr[0] = ships[k].number + i + R_4 - R_3;
						arr[1] = ships[k].letter + R_2 - R_1;
					}
					else
					{
						continue;
					}
					break;
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
					if (field_visible[ships[k].number][ships[k].letter + i + R_5 - R_6] == space
						&& ships[k].letter + i + R_5 - R_6 != 11
						&& ships[k].letter + i + R_5 - R_6 != 0)
					{
						arr[0] = ships[k].number;
						arr[1] = ships[k].letter + i + R_5 - R_6;
					}
					else if (field_visible[ships[k].number][ships[k].letter + i + R_6 - R_5] == space
						&& ships[k].letter + i + R_6 - R_5 != 11
						&& ships[k].letter + i + R_6 - R_5 != 0)
					{
						arr[0] = ships[k].number;
						arr[1] = ships[k].letter + i + R_6 - R_5;
					}
					else
					{
						continue;
					}
					break;
				}
				else if (field_visible[ships[k].number][ships[k].letter + i] == cross)
				{
					if (field_visible[ships[k].number + R_1 - R_2][ships[k].letter + i + R_3 - R_4] == space
						&& (ships[k].number + R_1 - R_2 != 11
							&& ships[k].number + R_1 - R_2 != 0
							&& ships[k].letter + i + R_3 - R_4 != 11
							&& ships[k].letter + i + R_3 - R_4 != 0))
					{
						arr[0] = ships[k].number + R_1 - R_2;
						arr[1] = ships[k].letter + i + R_3 - R_4;
					}
					else if (field_visible[ships[k].number + R_2 - R_1][ships[k].letter + i + R_4 - R_3] == space
						&& (ships[k].number + R_2 - R_1 != 11
							&& ships[k].number + R_2 - R_1 != 0
							&& ships[k].letter + i + R_4 - R_3 != 11
							&& ships[k].letter + i + R_4 - R_3 != 0))
					{
						arr[0] = ships[k].number + R_2 - R_1;
						arr[1] = ships[k].letter + i + R_4 - R_3;
					}
					else if (field_visible[ships[k].number + R_3 - R_4][ships[k].letter + i + R_1 - R_2] == space
						&& (ships[k].number + R_3 - R_4 != 11
							&& ships[k].number + R_3 - R_4 != 0
							&& ships[k].letter + i + R_1 - R_2 != 11
							&& ships[k].letter + i + R_1 - R_2 != 0))
					{
						arr[0] = ships[k].number + R_3 - R_4;
						arr[1] = ships[k].letter + i + R_1 - R_2;
					}
					else if (field_visible[ships[k].number + R_4 - R_3][ships[k].letter + i + R_2 - R_1] == space
						&& (ships[k].number + R_4 - R_3 != 11
							&& ships[k].number + R_4 - R_3 != 0
							&& ships[k].letter + i + R_2 - R_1 != 11
							&& ships[k].letter + i + R_2 - R_1 != 0))
					{
						arr[0] = ships[k].number + R_4 - R_3;
						arr[1] = ships[k].letter + i + R_2 - R_1;
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

void PC_Start_Tactic_1(char** field_visible, int& size, int* arr, int& arr_size)
{
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
