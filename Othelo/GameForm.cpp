#include "GameForm.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace Othelo;

System::Void GameForm::restart()
{
	delete player1;
	delete player2;

	if (gameMode == GameMode::H_V_H)
	{
		player1 = new Player("Player 1", "Black", PlayerType::HUMAN);
		player2 = new Player("Player 2", "White", PlayerType::HUMAN);
	}
	else if (gameMode == GameMode::C_V_H)
	{
		player1 = new Player("Human", "Black", PlayerType::HUMAN);
		player2 = new Player("Computer", "White", PlayerType::COMPUTER);
	}
	else if (gameMode == GameMode::C_V_C)
	{
		player1 = new Player("Computer 1", "Black", PlayerType::COMPUTER);
		player2 = new Player("Computer 2", "White", PlayerType::COMPUTER);
	}

	delete board;
	board = new std::vector<std::vector<uint8_t>>(BOARD_SIZE);

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		board->at(i).resize(BOARD_SIZE);
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board->at(i)[j] = BOARD_EMPTY;
		}
	}
	board->at(3)[3] = board->at(4)[4] = BOARD_WHITE;
	board->at(4)[3] = board->at(3)[4] = BOARD_BLACK;
	// board->at(2)[3] = board->at(3)[2] = board->at(4)[5] = board->at(5)[4] = BOARD_EMPTY_LEGAL;

	// TODO - remove
	// board->at(3)[3] = BOARD_WHITE;
	// board->at(4)[3] = board->at(3)[4] = board->at(4)[4] = BOARD_BLACK;
	// board->at(2)[3] = board->at(3)[2] = board->at(4)[5] = board->at(5)[4] = board->at(2)[2] = BOARD_EMPTY_LEGAL;

	// board->at(3)[3] = BOARD_WHITE;
	// board->at(4)[3] = board->at(3)[4] = board->at(4)[4] = BOARD_BLACK;
	// board->at(2)[3] = board->at(3)[2] = board->at(4)[5] = board->at(5)[4] = board->at(5)[5] = BOARD_EMPTY_LEGAL;

	// board->at(3)[3] = board->at(4)[4] = board->at(2)[5] = BOARD_WHITE;
	// board->at(4)[3] = board->at(3)[4] = BOARD_BLACK;
	// board->at(2)[3] = board->at(3)[2] = board->at(4)[5] = board->at(5)[2] = board->at(5)[4] = BOARD_EMPTY_LEGAL;

	// board->at(3)[3] = board->at(4)[4] = board->at(5)[2] = BOARD_WHITE;
	// board->at(4)[3] = board->at(3)[4] = BOARD_BLACK;
	// board->at(2)[3] = board->at(3)[2] = board->at(4)[5] = board->at(5)[4] = board->at(2)[5] = BOARD_EMPTY_LEGAL;

	std::string labelText = player1->name + " (" + player1->color + ") : ";
	lbl_player_1_score_fixed->Text = msclr::interop::marshal_as<System::String ^>(labelText);
	lbl_player_1_score->Text = gcnew System::String(player1->score.ToString());
	labelText = player2->name + " (" + player2->color + ") : ";
	lbl_player_2_score_fixed->Text = msclr::interop::marshal_as<System::String ^>(labelText);
	lbl_player_2_score->Text = gcnew System::String(player2->score.ToString());

	timer_start_play->Interval = 50;
	timer_start_play->Enabled = false;

	currentPlayer = nullptr;
	changeTurns();
	calcLegalMoves(board, currentPlayer);

	game_matrix->Refresh();
}

System::Void GameForm::changeTurns()
{
}

System::Void GameForm::gameOver(int win)
{
}

System::Drawing::Point ^ GameForm::GetRowColIndex(TableLayoutPanel ^ tlp, System::Drawing::Point ^ point)
{
}

System::Void GameForm::updateBoard(Graphics ^ g)
{
}

System::Void GameForm::makeMove(uint8_t row, uint8_t col)
{
}

System::Void GameForm::placeAndFlip(std::vector<std::vector<uint8_t>> *currBoard, Player *player, uint8_t row, uint8_t col)
{
}

uint8_t GameForm::calcLegalMoves(std::vector<std::vector<uint8_t>> *currBoard, Player *player)
{
}

uint8_t GameForm::updateScore()
{
}

std::pair<uint8_t, uint8_t> GameForm::aiThink()
{
}

double GameForm::minMaxAlphaBeta(std::vector<std::vector<uint8_t>> *currBoard, Player *player, bool isMax, uint8_t depth, uint8_t maxDepth, int &alpha, int &beta)
{
}

double GameForm::calcHeuristic(std::vector<std::vector<uint8_t>> *currBoard, Player *player)
{
}

/* Event Handlers */

System::Void GameForm::GameForm_FormClosed(System::Object ^ sender, System::Windows::Forms::FormClosedEventArgs ^ e)
{
	if (!isReturnToMenu)
		Application::Exit();
}

System::Void GameForm::btn_main_menu_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	isReturnToMenu = true;
	mainMenu->Show();
	this->Close();
}

System::Void GameForm::GameForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	restart();
}

System::Void GameForm::btn_restart_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	restart();
}

System::Void GameForm::game_matrix_MouseClick(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
{
	System::Drawing::Point ^ cursorPosition = game_matrix->PointToClient(System::Windows::Forms::Cursor::Position);
	System::Drawing::Point ^ cellPos = GetRowColIndex(game_matrix, cursorPosition);
	uint8_t row = cellPos->Y;
	uint8_t col = cellPos->X;

	if (currentPlayer->type == PlayerType::HUMAN && board->at(row)[col] == BOARD_EMPTY_LEGAL)
		makeMove(row, col);
}

System::Void GameForm::game_matrix_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
{
	Graphics ^ g = e->Graphics;
	updateBoard(g);
}

System::Void GameForm::timer_start_play_Tick(System::Object ^ sender, System::EventArgs ^ e)
{
	timer_start_play->Enabled = false;
	std::pair<uint8_t, uint8_t> cell = aiThink();
	makeMove(cell.first, cell.second);
}