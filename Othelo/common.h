#ifndef _COMMON_H_
#define _COMMON_H_

#include <string>

#define BOARD_SIZE 8

#define BOARD_WHITE 0
#define BOARD_BLACK 1
#define BOARD_EMPTY 2
#define BOARD_EMPTY_LEGAL 3

enum class GameMode {
	H_V_H, C_V_H, C_V_C
};

enum class GameDifficulty {
	EASY, MEDIUM, HARD
};

enum class PlayerType {
	HUMAN, COMPUTER
};

struct Player {
	Player(std::string name, std::string color, PlayerType type)
		: name(name), color(color), type(type)
	{
		score = 2;
	}

	std::string name;
	std::string color;
	PlayerType type;
	int score;
	
};

#endif /* _COMMON_H_ */