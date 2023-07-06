#pragma once

int ship_int = 254; // Integer value representing the ship symbol
int point_int = 249; // Integer value representing the point symbol
int bang_int = 271;
char ship = ship_int; // Character symbol for the ship
char point = point_int; // Character symbol for the point
char bang = bang_int;
char space = ' '; // Character symbol for an empty space
char cross = 'X'; // Character symbol for a cross (used for marking hits/misses)
int f_style = 0; // Field style (0 for default, 1-3 for alternative styles)
int player_score = 0; // Player's score
int pc_score = 0; // Computer's score
bool end_game = false; // Flag to indicate if the game has ended
int difficulty = 70; // Game difficulty (percentage of hit probability)
int filing = 1; // Field filling method (0 for unspecified, 1 for random, 2 for manual)
bool restart = false; // Flag to indicate if the game should restart
int gamemode = 1;	// Game mode (1 for player vs. computer | 0 for computere vs. computer)
bool tactic_1 = false;
bool tactic_2 = false;