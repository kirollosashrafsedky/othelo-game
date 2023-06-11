#pragma once
#include "common.h"
#include <vector>

namespace Othelo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(Form^ mainMenu, GameMode gameMode, GameDifficulty gameDifficulty)
			: mainMenu(mainMenu), gameMode(gameMode), gameDifficulty(gameDifficulty)
		{
			InitializeComponent();
			isReturnToMenu = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GameForm()
		{
			delete player1;
			delete player2;
			delete board;

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_main_menu;
	private: System::Windows::Forms::Label^ lbl_status;
	private: System::Windows::Forms::Panel^ pnl_game;

	private: System::Windows::Forms::Panel^ pnl_score;


	private: System::Windows::Forms::Label^ lbl_score;
	private: System::Windows::Forms::Panel^ pnl_score_inner;
	private: System::Windows::Forms::Panel^ pnl_score_2;
	private: System::Windows::Forms::Panel^ pnl_score_1;
	private: System::Windows::Forms::Panel^ pnl_btns;
	private: System::Windows::Forms::Button^ btn_restart;
	private: System::Windows::Forms::Label^ lbl_player_2_score;
	private: System::Windows::Forms::Label^ lbl_player_2_score_fixed;
	private: System::Windows::Forms::Label^ lbl_player_1_score;
	private: System::Windows::Forms::Label^ lbl_player_1_score_fixed;
	private: System::Windows::Forms::TableLayoutPanel^ game_matrix;
	private: System::Windows::Forms::Timer^ timer_start_play;
	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btn_main_menu = (gcnew System::Windows::Forms::Button());
			this->lbl_status = (gcnew System::Windows::Forms::Label());
			this->pnl_game = (gcnew System::Windows::Forms::Panel());
			this->game_matrix = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pnl_score = (gcnew System::Windows::Forms::Panel());
			this->pnl_score_inner = (gcnew System::Windows::Forms::Panel());
			this->pnl_score_2 = (gcnew System::Windows::Forms::Panel());
			this->lbl_player_2_score = (gcnew System::Windows::Forms::Label());
			this->lbl_player_2_score_fixed = (gcnew System::Windows::Forms::Label());
			this->pnl_score_1 = (gcnew System::Windows::Forms::Panel());
			this->lbl_player_1_score = (gcnew System::Windows::Forms::Label());
			this->lbl_player_1_score_fixed = (gcnew System::Windows::Forms::Label());
			this->lbl_score = (gcnew System::Windows::Forms::Label());
			this->pnl_btns = (gcnew System::Windows::Forms::Panel());
			this->btn_restart = (gcnew System::Windows::Forms::Button());
			this->timer_start_play = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnl_game->SuspendLayout();
			this->pnl_score->SuspendLayout();
			this->pnl_score_inner->SuspendLayout();
			this->pnl_score_2->SuspendLayout();
			this->pnl_score_1->SuspendLayout();
			this->pnl_btns->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_main_menu
			// 
			this->btn_main_menu->Font = (gcnew System::Drawing::Font(L"Calibri", 14));
			this->btn_main_menu->Location = System::Drawing::Point(70, 13);
			this->btn_main_menu->Name = L"btn_main_menu";
			this->btn_main_menu->Size = System::Drawing::Size(190, 42);
			this->btn_main_menu->TabIndex = 6;
			this->btn_main_menu->Text = L"Main Menu";
			this->btn_main_menu->UseVisualStyleBackColor = true;
			this->btn_main_menu->Click += gcnew System::EventHandler(this, &GameForm::btn_main_menu_Click);
			// 
			// lbl_status
			// 
			this->lbl_status->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lbl_status->Dock = System::Windows::Forms::DockStyle::Top;
			this->lbl_status->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_status->Location = System::Drawing::Point(0, 0);
			this->lbl_status->Name = L"lbl_status";
			this->lbl_status->Size = System::Drawing::Size(532, 47);
			this->lbl_status->TabIndex = 7;
			this->lbl_status->Text = L"Game Over";
			this->lbl_status->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pnl_game
			// 
			this->pnl_game->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnl_game->Controls->Add(this->game_matrix);
			this->pnl_game->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnl_game->Location = System::Drawing::Point(0, 47);
			this->pnl_game->Margin = System::Windows::Forms::Padding(5);
			this->pnl_game->Name = L"pnl_game";
			this->pnl_game->Size = System::Drawing::Size(532, 532);
			this->pnl_game->TabIndex = 8;
			// 
			// game_matrix
			// 
			this->game_matrix->BackColor = System::Drawing::SystemColors::ControlLight;
			this->game_matrix->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->game_matrix->ColumnCount = 8;
			this->game_matrix->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->Dock = System::Windows::Forms::DockStyle::Fill;
			this->game_matrix->Location = System::Drawing::Point(0, 0);
			this->game_matrix->Name = L"game_matrix";
			this->game_matrix->RowCount = 8;
			this->game_matrix->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->game_matrix->Size = System::Drawing::Size(530, 530);
			this->game_matrix->TabIndex = 0;
			this->game_matrix->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameForm::game_matrix_Paint);
			this->game_matrix->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::game_matrix_MouseClick);
			// 
			// pnl_score
			// 
			this->pnl_score->Controls->Add(this->pnl_score_inner);
			this->pnl_score->Controls->Add(this->lbl_score);
			this->pnl_score->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnl_score->Location = System::Drawing::Point(0, 579);
			this->pnl_score->Name = L"pnl_score";
			this->pnl_score->Size = System::Drawing::Size(532, 53);
			this->pnl_score->TabIndex = 9;
			// 
			// pnl_score_inner
			// 
			this->pnl_score_inner->Controls->Add(this->pnl_score_2);
			this->pnl_score_inner->Controls->Add(this->pnl_score_1);
			this->pnl_score_inner->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnl_score_inner->Location = System::Drawing::Point(76, 0);
			this->pnl_score_inner->Name = L"pnl_score_inner";
			this->pnl_score_inner->Size = System::Drawing::Size(456, 53);
			this->pnl_score_inner->TabIndex = 1;
			// 
			// pnl_score_2
			// 
			this->pnl_score_2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnl_score_2->Controls->Add(this->lbl_player_2_score);
			this->pnl_score_2->Controls->Add(this->lbl_player_2_score_fixed);
			this->pnl_score_2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnl_score_2->Location = System::Drawing::Point(228, 0);
			this->pnl_score_2->Name = L"pnl_score_2";
			this->pnl_score_2->Size = System::Drawing::Size(228, 53);
			this->pnl_score_2->TabIndex = 1;
			// 
			// lbl_player_2_score
			// 
			this->lbl_player_2_score->AutoSize = true;
			this->lbl_player_2_score->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->lbl_player_2_score->Location = System::Drawing::Point(174, 17);
			this->lbl_player_2_score->Name = L"lbl_player_2_score";
			this->lbl_player_2_score->Size = System::Drawing::Size(19, 21);
			this->lbl_player_2_score->TabIndex = 2;
			this->lbl_player_2_score->Text = L"0";
			// 
			// lbl_player_2_score_fixed
			// 
			this->lbl_player_2_score_fixed->AutoSize = true;
			this->lbl_player_2_score_fixed->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->lbl_player_2_score_fixed->Location = System::Drawing::Point(7, 16);
			this->lbl_player_2_score_fixed->Name = L"lbl_player_2_score_fixed";
			this->lbl_player_2_score_fixed->Size = System::Drawing::Size(131, 21);
			this->lbl_player_2_score_fixed->TabIndex = 1;
			this->lbl_player_2_score_fixed->Text = L"Player 2 (White) :";
			// 
			// pnl_score_1
			// 
			this->pnl_score_1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnl_score_1->Controls->Add(this->lbl_player_1_score);
			this->pnl_score_1->Controls->Add(this->lbl_player_1_score_fixed);
			this->pnl_score_1->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnl_score_1->Location = System::Drawing::Point(0, 0);
			this->pnl_score_1->Name = L"pnl_score_1";
			this->pnl_score_1->Size = System::Drawing::Size(228, 53);
			this->pnl_score_1->TabIndex = 0;
			// 
			// lbl_player_1_score
			// 
			this->lbl_player_1_score->AutoSize = true;
			this->lbl_player_1_score->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->lbl_player_1_score->Location = System::Drawing::Point(174, 16);
			this->lbl_player_1_score->Name = L"lbl_player_1_score";
			this->lbl_player_1_score->Size = System::Drawing::Size(19, 21);
			this->lbl_player_1_score->TabIndex = 1;
			this->lbl_player_1_score->Text = L"0";
			// 
			// lbl_player_1_score_fixed
			// 
			this->lbl_player_1_score_fixed->AutoSize = true;
			this->lbl_player_1_score_fixed->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->lbl_player_1_score_fixed->Location = System::Drawing::Point(6, 16);
			this->lbl_player_1_score_fixed->Name = L"lbl_player_1_score_fixed";
			this->lbl_player_1_score_fixed->Size = System::Drawing::Size(125, 21);
			this->lbl_player_1_score_fixed->TabIndex = 0;
			this->lbl_player_1_score_fixed->Text = L"Player 1 (Black) :";
			// 
			// lbl_score
			// 
			this->lbl_score->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lbl_score->Dock = System::Windows::Forms::DockStyle::Left;
			this->lbl_score->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->lbl_score->Location = System::Drawing::Point(0, 0);
			this->lbl_score->Name = L"lbl_score";
			this->lbl_score->Size = System::Drawing::Size(76, 53);
			this->lbl_score->TabIndex = 0;
			this->lbl_score->Text = L"Score: ";
			this->lbl_score->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pnl_btns
			// 
			this->pnl_btns->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnl_btns->Controls->Add(this->btn_restart);
			this->pnl_btns->Controls->Add(this->btn_main_menu);
			this->pnl_btns->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnl_btns->Location = System::Drawing::Point(0, 632);
			this->pnl_btns->Name = L"pnl_btns";
			this->pnl_btns->Size = System::Drawing::Size(532, 61);
			this->pnl_btns->TabIndex = 10;
			// 
			// btn_restart
			// 
			this->btn_restart->Font = (gcnew System::Drawing::Font(L"Calibri", 14));
			this->btn_restart->Location = System::Drawing::Point(266, 13);
			this->btn_restart->Name = L"btn_restart";
			this->btn_restart->Size = System::Drawing::Size(190, 42);
			this->btn_restart->TabIndex = 7;
			this->btn_restart->Text = L"Restart";
			this->btn_restart->UseVisualStyleBackColor = true;
			this->btn_restart->Click += gcnew System::EventHandler(this, &GameForm::btn_restart_Click);
			// 
			// timer_start_play
			// 
			this->timer_start_play->Tick += gcnew System::EventHandler(this, &GameForm::timer_start_play_Tick);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 693);
			this->Controls->Add(this->pnl_btns);
			this->Controls->Add(this->pnl_score);
			this->Controls->Add(this->pnl_game);
			this->Controls->Add(this->lbl_status);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(550, 740);
			this->MinimumSize = System::Drawing::Size(550, 740);
			this->Name = L"GameForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Othelo Game";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &GameForm::GameForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->pnl_game->ResumeLayout(false);
			this->pnl_score->ResumeLayout(false);
			this->pnl_score_inner->ResumeLayout(false);
			this->pnl_score_2->ResumeLayout(false);
			this->pnl_score_2->PerformLayout();
			this->pnl_score_1->ResumeLayout(false);
			this->pnl_score_1->PerformLayout();
			this->pnl_btns->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void GameForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void btn_main_menu_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void GameForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_restart_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void game_matrix_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void game_matrix_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	private: System::Void timer_start_play_Tick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void restart();
	private: System::Void changeTurns();
	private: System::Void gameOver(int win);
	private: System::Drawing::Point^ GetRowColIndex(TableLayoutPanel^ tlp, System::Drawing::Point^ point);
	private: System::Void updateBoard(Graphics^ g);
	private: System::Void placeAndFlip(std::vector<std::vector<uint8_t>>* currBoard, Player* player, uint8_t row, uint8_t col);
	private: System::Void makeMove(uint8_t row, uint8_t col);
	private: uint8_t calcLegalMoves(std::vector<std::vector<uint8_t>>* currBoard, Player* player);
	private: uint8_t updateScore();
	private: std::pair<uint8_t, uint8_t> aiThink();
	private: double minMaxAlphaBeta(std::vector<std::vector<uint8_t>>* currBoard, Player* player, bool isMax, uint8_t depth, uint8_t maxDepth, int &alpha, int &beta);
	private: double calcHeuristic(std::vector<std::vector<uint8_t>>* currBoard, Player* player);

	private:
		Form^ mainMenu;
		GameMode gameMode;
		GameDifficulty gameDifficulty;
		bool isReturnToMenu;
		Player *player1;
		Player *player2;
		Player* currentPlayer;
		std::vector<std::vector<uint8_t>> *board;



};

}
