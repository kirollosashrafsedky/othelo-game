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
	if (currentPlayer == player1)
	{
		currentPlayer = player2;
	}
	else
	{
		currentPlayer = player1;
	}

	std::string labelText = currentPlayer->name + "'s turn - (" + currentPlayer->color + ")";
	lbl_status->Text = msclr::interop::marshal_as<System::String^>(labelText);

	if (currentPlayer->type == PlayerType::COMPUTER)
	{
		timer_start_play->Enabled = true;
	}
}

System::Void GameForm::gameOver(int win)
{
	std::string playerText;
	if (win == 0)
	{
		playerText = player1->name + " (" + player1->color + ")";
		lbl_status->Text = "Game Over - " + msclr::interop::marshal_as<System::String ^>(playerText) + " won";
	}
	else if (win == 1)
	{
		playerText = player2->name + " (" + player2->color + ")";
		lbl_status->Text = "Game Over - " + msclr::interop::marshal_as<System::String ^>(playerText) + " won";
	}
	else
	{
		lbl_status->Text = "Game Over - Tie";
	}
}

System::Drawing::Point ^ GameForm::GetRowColIndex(TableLayoutPanel ^ tlp, System::Drawing::Point ^ point)
{
	if (point->X > tlp->Width || point->Y > tlp->Height)
		return nullptr;

	int w = tlp->Width;
	int h = tlp->Height;
	cli::array<int>^ widths = tlp->GetColumnWidths();

	int i;
	for (i = widths->Length - 1; i >= 0 && point->X < w; i--)
		w -= widths[i];
	int col = i + 1;

	cli::array<int>^ heights = tlp->GetRowHeights();
	for (i = heights->Length - 1; i >= 0 && point->Y < h; i--)
		h -= heights[i];

	int row = i + 1;

	return gcnew System::Drawing::Point(col, row);
}

System::Void GameForm::updateBoard(Graphics ^ g)
{
	int rowCount = game_matrix->RowCount;
	int columnCount = game_matrix->ColumnCount;

	g->SmoothingMode = Drawing::Drawing2D::SmoothingMode::HighQuality;


	for (int row = 0; row < rowCount; row++)
	{
		for (int column = 0; column < columnCount; column++)
		{
			Color color;
			if (board->at(row)[column] == BOARD_EMPTY)
			{
				continue;
			}
			else if (board->at(row)[column] == BOARD_WHITE)
			{
				color = Color::FromArgb(255, 255, 255);
			}
			else
			{
				color = Color::FromArgb(40, 40, 40);
			}

			// Calculate the size of each cell
			int cellWidth = game_matrix->Width / columnCount;
			int cellHeight = game_matrix->Height / rowCount;

			// Calculate the size of the circle based on the smaller dimension of the cell
			int circleSize = Math::Min(cellWidth, cellHeight) - 10;

			// Calculate the position of the circle to be centered in the cell
			int circleX = column * cellWidth + (cellWidth - circleSize) / 2;
			int circleY = row * cellHeight + (cellHeight - circleSize) / 2;

			// Draw the circle
			if (board->at(row)[column] == BOARD_EMPTY_LEGAL)
			{
				if (currentPlayer->type == PlayerType::HUMAN)
				{
					Pen^ pen = gcnew Pen(color);
					g->DrawEllipse(pen, circleX, circleY, circleSize, circleSize);
				}
			}
			else
			{
				SolidBrush^ brush = gcnew SolidBrush(color);
				g->FillEllipse(brush, circleX, circleY, circleSize, circleSize);
			}
		}
	}
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
	double mobility = 0, coinParity = 0, cornersCaptured = 0;
	double maxCount = 0, minCount = 0;

	uint8_t maxCellColor, minCellColor;
	if (player->color == "Black")
	{
		maxCellColor = BOARD_BLACK;
		minCellColor = BOARD_WHITE;
	}
	else
	{
		maxCellColor = BOARD_WHITE;
		minCellColor = BOARD_BLACK;
	}

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (currBoard->at(i)[j] == maxCellColor)
			{
				maxCount++;
			}
			else if (currBoard->at(i)[j] == minCellColor)
			{
				minCount++;
			}
		}
	}
	coinParity = (100 * (maxCount - minCount)) / (maxCount + minCount);

	maxCount = minCount = 0;

	if (currBoard->at(0)[0] == maxCellColor)
		maxCount++;
	else if (currBoard->at(0)[0] == minCount)
		minCount++;
	if (currBoard->at(0)[7] == maxCellColor)
		maxCount++;
	else if (currBoard->at(0)[7] == minCount)
		minCount++;
	if (currBoard->at(7)[0] == maxCellColor)
		maxCount++;
	else if (currBoard->at(7)[0] == minCount)
		minCount++;
	if (currBoard->at(7)[7] == maxCellColor)
		maxCount++;
	else if (currBoard->at(7)[7] == minCount)
		minCount++;

	if (maxCount + minCount != 0)
	{
		cornersCaptured = (100 * (maxCount - minCount)) / (maxCount + minCount);
	}

	Player *opponent;

	if (player == player1)
		opponent = player2;
	else
		opponent = player1;

	maxCount = calcLegalMoves(currBoard, player);
	minCount = calcLegalMoves(currBoard, opponent);

	if (maxCount + minCount != 0)
	{
		mobility = (100 * (maxCount - minCount)) / (maxCount + minCount);
	}

	return (mobility + coinParity + cornersCaptured);
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
