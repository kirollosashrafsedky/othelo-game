#include "MainForm.h"
#include "GameForm.h"
#include "common.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Othelo;

[STAThread]
void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Othelo::MainForm mainForm;
    Application::Run(% mainForm);
}

System::Void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	this->combo_mode->SelectedIndex = 0;
	this->combo_difficulty->SelectedIndex = 0;
}

System::Void MainForm::combo_mode_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->combo_mode->SelectedIndex == 0)
	{
		this->combo_difficulty->Enabled = false;
	}
	else
	{
		this->combo_difficulty->Enabled = true;
	}
}

System::Void MainForm::btn_start_Click(System::Object^ sender, System::EventArgs^ e)
{
	GameMode gameMode = static_cast<GameMode>(this->combo_mode->SelectedIndex);
	GameDifficulty gameDifficulty = static_cast<GameDifficulty>(this->combo_difficulty->SelectedIndex);

	Form^ gameForm = gcnew GameForm(this, gameMode, gameDifficulty);
	gameForm->Show();
	this->Hide();
}