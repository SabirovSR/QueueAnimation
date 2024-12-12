#pragma once

#include<string>
#include<time.h>
#include<msclr\marshal_cppstd.h>
#include"../Queue/TQueue.h"

namespace QAnimation {

	using namespace System;
	using namespace ComponentModel;
	using namespace Collections;
	using namespace Windows::Forms;
	using namespace Data;
	using namespace Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public Form
	{
		double p;
		double q;
		int PushCount = 0;
		int PopCount = 0;
		TQueue<int>* CircleQueue;

		int X = 500;
		int Y = 85;
		int W = 150;
		int H = 150;

		Random^ rnd = gcnew Random();
		int startflag = 0;

		int exflag = 0;

		void Draw()
		{
			int Start = 360 * CircleQueue->GetHeadIndex() / CircleQueue->GetMaxSize();
			int Finish = 360 * CircleQueue->GetCurrentSize() / CircleQueue->GetMaxSize();
			Pen^ MyDrawPen = gcnew Pen(Color::DarkSeaGreen);
			MyDrawPen->Width = 20.0F;
			Graphics^ gr = this->CreateGraphics();
			gr->DrawArc(MyDrawPen, X, Y, W, H, Start, Finish);
		}

		void Clear()
		{
			int Start = 360 * CircleQueue->GetHeadIndex() / CircleQueue->GetMaxSize();
			int Finish = 360 * CircleQueue->GetCurrentSize() / CircleQueue->GetMaxSize();
			Pen^ MyClearPen = gcnew Pen(Color::Snow);
			MyClearPen->Width = 20.0F;
			Graphics^ gr = this->CreateGraphics();
			gr->DrawArc(MyClearPen, X, Y, W, H, Start, Finish);
		}

	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		Label^ label14;
		Label^ label12;
		Label^ label13;
		Button^ button1;
		Timer^ timer1;
		Button^ button2;
		Label^ label1;
		TextBox^ textBox1;
		Label^ label2;
		TextBox^ textBox2;
		Label^ label3;
		TextBox^ textBox3;
		Label^ label4;
		Label^ label5;
		Label^ label6;
		Label^ label8;
		Label^ label9;
		TextBox^ textBox4;
		Label^ label10;
		Label^ label11;
		Label^ label7;
		Button^ button3;
		IContainer^ components;
		GroupBox^ groupBox1;
		GroupBox^ groupBox2;
		GroupBox^ groupBox3;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent()
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew Button());
			this->timer1 = (gcnew Timer(this->components));
			this->button2 = (gcnew Button());
			this->button3 = (gcnew Button());
			this->label1 = (gcnew Label());
			this->textBox1 = (gcnew TextBox());
			this->label2 = (gcnew Label());
			this->textBox2 = (gcnew TextBox());
			this->label3 = (gcnew Label());
			this->label8 = (gcnew Label());
			this->label9 = (gcnew Label());
			this->textBox4 = (gcnew TextBox());
			this->label10 = (gcnew Label());
			this->label11 = (gcnew Label());
			this->label12 = (gcnew Label());
			this->label13 = (gcnew Label());
			this->label14 = (gcnew Label());
			this->groupBox1 = (gcnew GroupBox());
			this->groupBox2 = (gcnew GroupBox());
			this->groupBox3 = (gcnew GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = Color::DarkSeaGreen;
			this->button1->FlatStyle = FlatStyle::Flat;
			this->button1->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 14, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->button1->ForeColor = Color::Black;
			this->button1->Location = Point(475, 12);
			this->button1->Name = L"button1";
			this->button1->Size = Drawing::Size(61, 33);
			this->button1->TabIndex = 0;
			this->button1->Text = L"▶";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew EventHandler(this, &MyForm::playButton_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->BackColor = Color::Wheat;
			this->button2->FlatStyle = FlatStyle::Flat;
			this->button2->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 14, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->button2->ForeColor = Color::Black;
			this->button2->Location = Point(542, 12);
			this->button2->Name = L"button2";
			this->button2->Size = Drawing::Size(61, 33);
			this->button2->TabIndex = 1;
			this->button2->Text = L"❚❚";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew EventHandler(this, &MyForm::pauseButton_Click);
			// 
			// button3
			// 
			this->button3->BackColor = Color::Salmon;
			this->button3->FlatStyle = FlatStyle::Flat;
			this->button3->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 14, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->button3->ForeColor = Color::Black;
			this->button3->Location = Point(609, 12);
			this->button3->Name = L"button3";
			this->button3->Size = Drawing::Size(61, 33);
			this->button3->TabIndex = 2;
			this->button3->Text = L"◼";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew EventHandler(this, &MyForm::resetButton_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew Drawing::Font(L"Comic Sans MS", 14.25F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->label1->ForeColor = SystemColors::ActiveCaptionText;
			this->label1->ImageAlign = ContentAlignment::MiddleRight;
			this->label1->Location = Point(11, 45);
			this->label1->Name = L"label1";
			this->label1->Size = Drawing::Size(301, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L" Максимальная длина очереди:  \r\n";
			this->label1->TextAlign = ContentAlignment::MiddleRight;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = Color::LightGray;
			this->textBox1->BorderStyle = BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 11.5F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->textBox1->Location = Point(321, 45);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = Drawing::Size(75, 25);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextAlign = HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->Font = (gcnew Drawing::Font(L"Comic Sans MS", 14.25F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->label2->ForeColor = SystemColors::ActiveCaptionText;
			this->label2->Location = Point(15, 85);
			this->label2->Name = L"label2";
			this->label2->Size = Drawing::Size(297, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Вероятность добавления:\r\n";
			this->label2->TextAlign = ContentAlignment::MiddleRight;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = Color::LightGray;
			this->textBox2->BorderStyle = BorderStyle::FixedSingle;
			this->textBox2->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 11.5F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->textBox2->Location = Point(321, 85);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = Drawing::Size(75, 25);
			this->textBox2->TabIndex = 6;
			this->textBox2->TextAlign = HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->Font = (gcnew Drawing::Font(L"Comic Sans MS", 14.25F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->label3->ForeColor = SystemColors::ActiveCaptionText;
			this->label3->Location = Point(15, 128);
			this->label3->Name = L"label3";
			this->label3->Size = Drawing::Size(297, 25);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Вероятность исключения:\r\n";
			this->label3->TextAlign = ContentAlignment::MiddleRight;
			// 
			// label8
			// 
			this->label8->Font = (gcnew Drawing::Font(L"Comic Sans MS", 14.25F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->label8->ForeColor = SystemColors::ActiveCaptionText;
			this->label8->Location = Point(14, 44);
			this->label8->Name = L"label8";
			this->label8->Size = Drawing::Size(297, 25);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Добавлено в очередь:\r\n";
			this->label8->TextAlign = ContentAlignment::MiddleRight;
			// 
			// label9
			// 
			this->label9->Font = (gcnew Drawing::Font(L"Comic Sans MS", 14.25F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->label9->ForeColor = SystemColors::ActiveCaptionText;
			this->label9->Location = Point(14, 81);
			this->label9->Name = L"label9";
			this->label9->Size = Drawing::Size(297, 25);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Удалено из очереди:\r\n";
			this->label9->TextAlign = ContentAlignment::MiddleRight;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = Color::LightGray;
			this->textBox4->BorderStyle = BorderStyle::FixedSingle;
			this->textBox4->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 11.5F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->textBox4->Location = Point(321, 128);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = Drawing::Size(75, 25);
			this->textBox4->TabIndex = 10;
			this->textBox4->TextAlign = HorizontalAlignment::Center;
			// 
			// label10
			// 
			this->label10->BackColor = Color::LightGoldenrodYellow;
			this->label10->BorderStyle = BorderStyle::FixedSingle;
			this->label10->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 11.5F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->label10->ForeColor = SystemColors::ActiveCaptionText;
			this->label10->Location = Point(320, 44);
			this->label10->Name = L"label10";
			this->label10->Size = Drawing::Size(75, 25);
			this->label10->TabIndex = 11;
			this->label10->TextAlign = ContentAlignment::MiddleCenter;
			// 
			// label11
			// 
			this->label11->BackColor = Color::LightGoldenrodYellow;
			this->label11->BorderStyle = BorderStyle::FixedSingle;
			this->label11->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 11.5F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->label11->ForeColor = SystemColors::ActiveCaptionText;
			this->label11->Location = Point(320, 81);
			this->label11->Name = L"label11";
			this->label11->Size = Drawing::Size(75, 25);
			this->label11->TabIndex = 12;
			this->label11->TextAlign = ContentAlignment::MiddleCenter;
			// 
			// label12
			// 
			this->label12->BackColor = Color::Transparent;
			this->label12->Font = (gcnew Drawing::Font(L"Comic Sans MS", 14.25F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->label12->ForeColor = SystemColors::ActiveCaptionText;
			this->label12->Location = Point(14, 118);
			this->label12->Name = L"label12";
			this->label12->Size = Drawing::Size(297, 25);
			this->label12->TabIndex = 13;
			this->label12->Text = L"Элементов в очереди:\r\n";
			this->label12->TextAlign = ContentAlignment::MiddleRight;
			// 
			// label13
			// 
			this->label13->BackColor = Color::LightGoldenrodYellow;
			this->label13->BorderStyle = BorderStyle::FixedSingle;
			this->label13->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 11.5F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->label13->ForeColor = SystemColors::ActiveCaptionText;
			this->label13->Location = Point(320, 118);
			this->label13->Name = L"label13";
			this->label13->Size = Drawing::Size(75, 25);
			this->label13->TabIndex = 14;
			this->label13->TextAlign = ContentAlignment::MiddleCenter;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew Drawing::Font(L"Comic Sans MS", 15, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->label14->ForeColor = Color::FromArgb(static_cast<Int32>(static_cast<Byte>(192)), static_cast<Int32>(static_cast<Byte>(0)),
				static_cast<Int32>(static_cast<Byte>(0)));
			this->label14->Location = Point(16, 34);
			this->label14->Name = L"label14";
			this->label14->Size = Drawing::Size(0, 28);
			this->label14->TabIndex = 15;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Font = (gcnew Drawing::Font(L"Comic Sans MS", 14.25F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->groupBox1->Location = Point(10, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = Drawing::Size(412, 168);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Входные параметры:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Font = (gcnew Drawing::Font(L"Comic Sans MS", 14.25F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->groupBox2->Location = Point(11, 188);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = Drawing::Size(411, 160);
			this->groupBox2->TabIndex = 18;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Результат работы:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Font = (gcnew Drawing::Font(L"Comic Sans MS", 14.25F, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<Byte>(204)));
			this->groupBox3->Location = Point(428, 269);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = Drawing::Size(270, 79);
			this->groupBox3->TabIndex = 19;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Ошибка:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = SizeF(6, 13);
			this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
			this->BackColor = Color::Snow;
			this->ClientSize = Drawing::Size(712, 359);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->ForeColor = SystemColors::ControlLightLight;
			this->Name = L"MyForm";
			this->Text = L"Визуализация очереди";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	Void playButton_Click(Object^ sender, EventArgs^ e) {

		label14->Text = " ";

		if (textBox2->Text == ""
			|| textBox4->Text == ""
			|| textBox1->Text == "")
		{
			label14->Text = "Введите параметры!";
			return;
		}

		p = Convert::ToDouble(textBox2->Text);
		q = Convert::ToDouble(textBox4->Text);
		if (startflag == 0)
		{
			int MaxSize = Convert::ToInt32(textBox1->Text);
			CircleQueue = new TQueue<int>(MaxSize);
			startflag = 1;
			for (int i = 0; i < 10; i++)
			{
				CircleQueue->Push(1);
			}

		}
		timer1->Enabled = true;
	}

	Void timer1_Tick(Object^ sender, EventArgs^ e) {
		try
		{
			if (!CircleQueue->empty())
			{
				Clear();
			}

			//try {
				if (rnd->Next(0, 101) < p)
				{
					CircleQueue->Push(1);
					PushCount++;

				}
				if (rnd->Next(0, 101) < q)
				{
					CircleQueue->Pop();
					PopCount++;
				}
			//}
			//catch (const std::exception& ex) {
			//	// ignore
			//}

			Draw();

			label10->Text = Convert::ToString(PushCount);
			label11->Text = Convert::ToString(PopCount);
			label13->Text = Convert::ToString(CircleQueue->NumberOfElements());

			Sleep(100);
		}
		catch (const std::exception& ex)
		{
			label14->Text = gcnew String(ex.what());
			timer1->Enabled = false;
			Clear();
			delete CircleQueue;
			startflag = 0;
			PushCount = 0;
			PopCount = 0;
			label10->Text = Convert::ToString(0);
			label11->Text = Convert::ToString(0);
			label13->Text = Convert::ToString(0);
			exflag = 1;
		}
	}

	Void pauseButton_Click(Object^ sender, EventArgs^ e) {
		timer1->Enabled = false;
	}

	Void resetButton_Click(Object^ sender, EventArgs^ e) {
		timer1->Enabled = false;
		if (exflag == 0)
		{
			Clear();
			delete CircleQueue;
			startflag = 0;
			PushCount = 0;
			PopCount = 0;
			label10->Text = Convert::ToString(0);
			label11->Text = Convert::ToString(0);
			label13->Text = Convert::ToString(0);
		}
	}
	};
}
