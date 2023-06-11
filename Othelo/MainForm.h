#pragma once

namespace Othelo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl_header;
	protected:
	private: System::Windows::Forms::Label^ lbl_mode;
	private: System::Windows::Forms::Label^ lbl_difficulty;
	private: System::Windows::Forms::ComboBox^ combo_mode;
	private: System::Windows::Forms::ComboBox^ combo_difficulty;
	private: System::Windows::Forms::Button^ btn_start;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbl_header = (gcnew System::Windows::Forms::Label());
			this->lbl_mode = (gcnew System::Windows::Forms::Label());
			this->lbl_difficulty = (gcnew System::Windows::Forms::Label());
			this->combo_mode = (gcnew System::Windows::Forms::ComboBox());
			this->combo_difficulty = (gcnew System::Windows::Forms::ComboBox());
			this->btn_start = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbl_header
			// 
			this->lbl_header->Dock = System::Windows::Forms::DockStyle::Top;
			this->lbl_header->Font = (gcnew System::Drawing::Font(L"Calibri", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_header->Location = System::Drawing::Point(0, 0);
			this->lbl_header->Name = L"lbl_header";
			this->lbl_header->Size = System::Drawing::Size(532, 184);
			this->lbl_header->TabIndex = 0;
			this->lbl_header->Text = L"Othelo Game";
			this->lbl_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_mode
			// 
			this->lbl_mode->AutoSize = true;
			this->lbl_mode->Font = (gcnew System::Drawing::Font(L"Calibri", 16));
			this->lbl_mode->Location = System::Drawing::Point(50, 184);
			this->lbl_mode->Name = L"lbl_mode";
			this->lbl_mode->Size = System::Drawing::Size(86, 33);
			this->lbl_mode->TabIndex = 1;
			this->lbl_mode->Text = L"Mode:";
			// 
			// lbl_difficulty
			// 
			this->lbl_difficulty->AutoSize = true;
			this->lbl_difficulty->Font = (gcnew System::Drawing::Font(L"Calibri", 16));
			this->lbl_difficulty->Location = System::Drawing::Point(50, 254);
			this->lbl_difficulty->Name = L"lbl_difficulty";
			this->lbl_difficulty->Size = System::Drawing::Size(125, 33);
			this->lbl_difficulty->TabIndex = 2;
			this->lbl_difficulty->Text = L"Difficulty :";
			// 
			// combo_mode
			// 
			this->combo_mode->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->combo_mode->Font = (gcnew System::Drawing::Font(L"Calibri", 14));
			this->combo_mode->FormattingEnabled = true;
			this->combo_mode->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Human VS Human", L"Computer VS Human", L"Computer VS Computer" });
			this->combo_mode->Location = System::Drawing::Point(190, 181);
			this->combo_mode->Name = L"combo_mode";
			this->combo_mode->Size = System::Drawing::Size(283, 36);
			this->combo_mode->TabIndex = 3;
			this->combo_mode->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::combo_mode_SelectedIndexChanged);
			// 
			// combo_difficulty
			// 
			this->combo_difficulty->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->combo_difficulty->Font = (gcnew System::Drawing::Font(L"Calibri", 14));
			this->combo_difficulty->FormattingEnabled = true;
			this->combo_difficulty->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Easy", L"Medium", L"Hard" });
			this->combo_difficulty->Location = System::Drawing::Point(190, 251);
			this->combo_difficulty->Name = L"combo_difficulty";
			this->combo_difficulty->Size = System::Drawing::Size(283, 36);
			this->combo_difficulty->TabIndex = 4;
			// 
			// btn_start
			// 
			this->btn_start->Font = (gcnew System::Drawing::Font(L"Calibri", 16));
			this->btn_start->Location = System::Drawing::Point(180, 347);
			this->btn_start->Name = L"btn_start";
			this->btn_start->Size = System::Drawing::Size(190, 53);
			this->btn_start->TabIndex = 5;
			this->btn_start->Text = L"Start";
			this->btn_start->UseVisualStyleBackColor = true;
			this->btn_start->Click += gcnew System::EventHandler(this, &MainForm::btn_start_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 503);
			this->Controls->Add(this->btn_start);
			this->Controls->Add(this->combo_difficulty);
			this->Controls->Add(this->combo_mode);
			this->Controls->Add(this->lbl_difficulty);
			this->Controls->Add(this->lbl_mode);
			this->Controls->Add(this->lbl_header);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(550, 550);
			this->MinimumSize = System::Drawing::Size(550, 550);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Othelo Game";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void combo_mode_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void btn_start_Click(System::Object^ sender, System::EventArgs^ e);
};
}
