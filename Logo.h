#pragma once
using namespace std;


void Logo()
{

}

void Win_Logo()
{
	int pause = 0;
	if (player_score == 20)
	{
		cout << "WIN";
		cin >> pause;
	}
	else if (pc_score == 20)
	{
		cout << "LOOSE";
		cin >> pause;
	}
}