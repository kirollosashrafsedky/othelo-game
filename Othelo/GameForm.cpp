#include "GameForm.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace Othelo;

System::Void GameForm::restart()
{
	
}

System::Void GameForm::changeTurns()
{
	
}

System::Void GameForm::gameOver(int win)
{
	
}

System::Drawing::Point^ GameForm::GetRowColIndex(TableLayoutPanel^ tlp, System::Drawing::Point^ point)
{
	
}

System::Void GameForm::updateBoard(Graphics^ g)
{
	
}

System::Void GameForm::makeMove(uint8_t row, uint8_t col)
{
	
}

System::Void GameForm::placeAndFlip(std::vector<std::vector<uint8_t>>* currBoard, Player* player, uint8_t row, uint8_t col)
{
	
}

uint8_t GameForm::calcLegalMoves(std::vector<std::vector<uint8_t>>* currBoard, Player* player)
{
	
}

uint8_t GameForm::updateScore()
{
	
}

std::pair<uint8_t, uint8_t> GameForm::aiThink()
{
	
}

double GameForm::minMaxAlphaBeta(std::vector<std::vector<uint8_t>>* currBoard, Player* player, bool isMax, uint8_t depth, uint8_t maxDepth, int &alpha, int &beta)
{
	
}

double GameForm::calcHeuristic(std::vector<std::vector<uint8_t>>* currBoard, Player* player)
{
	
}

/* Event Handlers */

System::Void GameForm::GameForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	if(!isReturnToMenu)
		Application::Exit();
}

System::Void GameForm::btn_main_menu_Click(System::Object^ sender, System::EventArgs^ e)
{
	isReturnToMenu = true;
	mainMenu->Show();
	this->Close();
}

System::Void GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	restart();
}

System::Void GameForm::btn_restart_Click(System::Object^ sender, System::EventArgs^ e)
{
	restart();
}

System::Void GameForm::game_matrix_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	System::Drawing::Point^ cursorPosition = game_matrix->PointToClient(System::Windows::Forms::Cursor::Position);
	System::Drawing::Point^ cellPos = GetRowColIndex(game_matrix, cursorPosition);
	uint8_t row = cellPos->Y;
	uint8_t col = cellPos->X;

	if(currentPlayer->type == PlayerType::HUMAN && board->at(row)[col] == BOARD_EMPTY_LEGAL)
		makeMove(row, col);
}

System::Void GameForm::game_matrix_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	Graphics^ g = e->Graphics;
	updateBoard(g);
}

System::Void GameForm::timer_start_play_Tick(System::Object^ sender, System::EventArgs^ e)
{
	timer_start_play->Enabled = false;
	std::pair<uint8_t, uint8_t> cell = aiThink();
	makeMove(cell.first, cell.second);
}