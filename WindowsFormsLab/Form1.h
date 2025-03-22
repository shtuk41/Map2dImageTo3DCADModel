#pragma once

#include <msclr\marshal_cppstd.h>
#include "ModelView.h"

namespace WindowsFormsLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			pb2D_LeftMouseDown = false;
			modelView = new ModelView();
			modelView->CreateNet((int)numericUpDownRows->Value,(int)numericUpDownColumns->Value);
			widthImageScale = 1.0;
			heightImageScale = 1.0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}

			delete modelView;
		}
	private: System::Windows::Forms::Button^  buttonReset;
	protected: 

	protected: 

	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::PictureBox^  pictureBox2D;

	private: System::Windows::Forms::PictureBox^  pictureBox3D;

	private: System::Windows::Forms::Label^  labelRows;
	private: System::Windows::Forms::Label^  labelColumns;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownRows;

	private: System::Windows::Forms::NumericUpDown^  numericUpDownColumns;

	private: System::Windows::Forms::Button^  buttonSave;
	private: System::Windows::Forms::Label^  labelX;
	private: System::Windows::Forms::Label^  labelY;
	private: System::Windows::Forms::Label^  labelZ;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownX;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownY;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownZ;



	private: System::Windows::Forms::Button^  buttonAdd;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  open2DToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: bool pb2D_LeftMouseDown;
	private: int  pb2D_LeftMouseX;
	private: int  pb2D_LeftMouseY;
	private: ModelView *modelView;
	private: double widthImageScale;
	private: System::Windows::Forms::ToolStripMenuItem^  restoreToolStripMenuItem;
	private: double heightImageScale;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox2D = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3D = (gcnew System::Windows::Forms::PictureBox());
			this->labelRows = (gcnew System::Windows::Forms::Label());
			this->labelColumns = (gcnew System::Windows::Forms::Label());
			this->numericUpDownRows = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownColumns = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->labelX = (gcnew System::Windows::Forms::Label());
			this->labelY = (gcnew System::Windows::Forms::Label());
			this->labelZ = (gcnew System::Windows::Forms::Label());
			this->numericUpDownX = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownY = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownZ = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->open2DToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restoreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2D))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3D))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownRows))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownColumns))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownZ))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonReset
			// 
			this->buttonReset->Location = System::Drawing::Point(1057, 149);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(75, 23);
			this->buttonReset->TabIndex = 0;
			this->buttonReset->Text = L"Reset";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &Form1::buttonPushEvent);
			// 
			// pictureBox2D
			// 
			this->pictureBox2D->Location = System::Drawing::Point(588, 40);
			this->pictureBox2D->Name = L"pictureBox2D";
			this->pictureBox2D->Size = System::Drawing::Size(450, 600);
			this->pictureBox2D->TabIndex = 1;
			this->pictureBox2D->TabStop = false;
			this->pictureBox2D->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox2D_MouseDown);
			this->pictureBox2D->MouseLeave += gcnew System::EventHandler(this, &Form1::pictureBox2D_MouseLeave);
			this->pictureBox2D->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox2D_MouseMove);
			this->pictureBox2D->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox2D_MouseUp);
			// 
			// pictureBox3D
			// 
			this->pictureBox3D->Location = System::Drawing::Point(10, 40);
			this->pictureBox3D->Name = L"pictureBox3D";
			this->pictureBox3D->Size = System::Drawing::Size(450, 600);
			this->pictureBox3D->TabIndex = 2;
			this->pictureBox3D->TabStop = false;
			// 
			// labelRows
			// 
			this->labelRows->AutoSize = true;
			this->labelRows->Location = System::Drawing::Point(1054, 45);
			this->labelRows->Name = L"labelRows";
			this->labelRows->Size = System::Drawing::Size(37, 13);
			this->labelRows->TabIndex = 3;
			this->labelRows->Text = L"Rows:";
			// 
			// labelColumns
			// 
			this->labelColumns->AutoSize = true;
			this->labelColumns->Location = System::Drawing::Point(1054, 92);
			this->labelColumns->Name = L"labelColumns";
			this->labelColumns->Size = System::Drawing::Size(50, 13);
			this->labelColumns->TabIndex = 4;
			this->labelColumns->Text = L"Columns:";
			// 
			// numericUpDownRows
			// 
			this->numericUpDownRows->Location = System::Drawing::Point(1057, 61);
			this->numericUpDownRows->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->numericUpDownRows->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownRows->Name = L"numericUpDownRows";
			this->numericUpDownRows->Size = System::Drawing::Size(75, 20);
			this->numericUpDownRows->TabIndex = 5;
			this->numericUpDownRows->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDownColumns
			// 
			this->numericUpDownColumns->Location = System::Drawing::Point(1057, 108);
			this->numericUpDownColumns->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 23, 0, 0, 0 });
			this->numericUpDownColumns->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownColumns->Name = L"numericUpDownColumns";
			this->numericUpDownColumns->Size = System::Drawing::Size(75, 20);
			this->numericUpDownColumns->TabIndex = 6;
			this->numericUpDownColumns->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(1057, 194);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(75, 23);
			this->buttonSave->TabIndex = 7;
			this->buttonSave->Text = L"Save";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &Form1::buttonSave_Click);
			// 
			// labelX
			// 
			this->labelX->AutoSize = true;
			this->labelX->Location = System::Drawing::Point(477, 45);
			this->labelX->Name = L"labelX";
			this->labelX->Size = System::Drawing::Size(17, 13);
			this->labelX->TabIndex = 8;
			this->labelX->Text = L"X:";
			// 
			// labelY
			// 
			this->labelY->AutoSize = true;
			this->labelY->Location = System::Drawing::Point(477, 91);
			this->labelY->Name = L"labelY";
			this->labelY->Size = System::Drawing::Size(17, 13);
			this->labelY->TabIndex = 9;
			this->labelY->Text = L"Y:";
			// 
			// labelZ
			// 
			this->labelZ->AutoSize = true;
			this->labelZ->Location = System::Drawing::Point(477, 136);
			this->labelZ->Name = L"labelZ";
			this->labelZ->Size = System::Drawing::Size(17, 13);
			this->labelZ->TabIndex = 10;
			this->labelZ->Text = L"Z:";
			// 
			// numericUpDownX
			// 
			this->numericUpDownX->Location = System::Drawing::Point(480, 61);
			this->numericUpDownX->Name = L"numericUpDownX";
			this->numericUpDownX->Size = System::Drawing::Size(87, 20);
			this->numericUpDownX->TabIndex = 11;
			// 
			// numericUpDownY
			// 
			this->numericUpDownY->Location = System::Drawing::Point(480, 108);
			this->numericUpDownY->Name = L"numericUpDownY";
			this->numericUpDownY->Size = System::Drawing::Size(87, 20);
			this->numericUpDownY->TabIndex = 12;
			// 
			// numericUpDownZ
			// 
			this->numericUpDownZ->Location = System::Drawing::Point(480, 152);
			this->numericUpDownZ->Name = L"numericUpDownZ";
			this->numericUpDownZ->Size = System::Drawing::Size(87, 20);
			this->numericUpDownZ->TabIndex = 13;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(480, 208);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(87, 23);
			this->buttonAdd->TabIndex = 14;
			this->buttonAdd->Text = L"Add";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &Form1::buttonAdd_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1169, 24);
			this->menuStrip1->TabIndex = 15;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->open2DToolStripMenuItem,
					this->restoreToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// open2DToolStripMenuItem
			// 
			this->open2DToolStripMenuItem->Name = L"open2DToolStripMenuItem";
			this->open2DToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->open2DToolStripMenuItem->Text = L"Open 2D";
			this->open2DToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::menuItemOpen2D_Click);
			// 
			// restoreToolStripMenuItem
			// 
			this->restoreToolStripMenuItem->Name = L"restoreToolStripMenuItem";
			this->restoreToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->restoreToolStripMenuItem->Text = L"Restore";
			this->restoreToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::menuItemRestore_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1169, 651);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->numericUpDownZ);
			this->Controls->Add(this->numericUpDownY);
			this->Controls->Add(this->numericUpDownX);
			this->Controls->Add(this->labelZ);
			this->Controls->Add(this->labelY);
			this->Controls->Add(this->labelX);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->numericUpDownColumns);
			this->Controls->Add(this->numericUpDownRows);
			this->Controls->Add(this->labelColumns);
			this->Controls->Add(this->labelRows);
			this->Controls->Add(this->pictureBox3D);
			this->Controls->Add(this->pictureBox2D);
			this->Controls->Add(this->buttonReset);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"2D to 3D Mapping Tool";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2D))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3D))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownRows))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownColumns))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownZ))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonPushEvent(System::Object^  sender, System::EventArgs^  e) {
			
				 //this->button1->BackColor = System::Drawing::Color::Red;
				 modelView->CreateNet((int)numericUpDownRows->Value,(int)numericUpDownColumns->Value);
				 this->Invalidate();
				 pictureBox2D->Refresh();
				 
			 }

	private: System::Void menuItemOpen2D_Click(System::Object^ sender, System::EventArgs ^ e)
			 {
				openFileDialog1->Filter = L"JPEG|*.jpg|PNG|*.png";
				openFileDialog1->Title = "Select Image";

				// Show the Dialog.
				// If the user clicked OK in the dialog and
				if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					 //pin_ptr<const wchar_t> wname = PtrToStringChars(openFileDialog1->FileName);
					 //MessageBox(NULL, wname, L"Multiple Instances Found.", MB_ICONINFORMATION | MB_OK);
					 //string str = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
					 //report_reader::ReportReader::LoadFile(str);
					 //oglControl.Reload(&oglControl);

					System::Drawing::Bitmap ^bitmap = gcnew System::Drawing::Bitmap(openFileDialog1->FileName);

					double width = (double)bitmap->Width;
					double height = (double)bitmap->Height;
					double ratio = width / height;

					int widthResized	= 450;
					int heightResized	= 600;
					widthImageScale		= 1.0;
					heightImageScale	= 1.0;

					if (ratio > (3.0 / 4.0))
					{
						heightResized = (int)(height * (450.0 / width));
					}
					else
					{
						widthResized = (int)(width * (600.0 / height));
					}

					widthImageScale		= width / widthResized;
					heightImageScale	= height /  heightResized;

					System::Drawing::Bitmap ^bitmapResized = gcnew System::Drawing::Bitmap(bitmap, widthResized, heightResized);
					this->pictureBox2D->Image = bitmapResized;
					delete bitmap;
				}
			 }
	private:	System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
				{
					Graphics^ pg = e->Graphics;
					Pen^ penBlack = gcnew Pen(Color::Black, 2);
					pg->DrawRectangle(penBlack, 10, 40, 450, 600);
					pg->DrawRectangle(penBlack, 588, 40, 450, 600);

					int rows = (int)numericUpDownRows->Value;
					int cols = (int)numericUpDownColumns->Value;

					Graphics^ pictureBoxGraphics = pictureBox2D->CreateGraphics();
					System::Drawing::SolidBrush^ myBrushGreen = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Green);
					System::Drawing::SolidBrush^ myBrushRed = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red);
					Pen^ penRed = gcnew Pen(Color::Green, 2);

					for (int ii = 0; ii < rows * cols; ii++)
					{
						int x = modelView->GetNetElementX(ii);
						int y = modelView->GetNetElementY(ii);
						
						if (modelView->NetElementHasRightNode(ii))
						{
							int x1 = modelView->GetNetElementRightEdgeX(ii);
							int y1 = modelView->GetNetElementRightEdgeY(ii);
							pictureBoxGraphics->DrawLine(penRed, x, y, x1, y1);
						}

						if (modelView->NetElementHasBelowNode(ii))
						{
							int x2 = modelView->GetNetElementBelowEdgeX(ii);
							int y2 = modelView->GetNetElementBelowEdgeY(ii);
							pictureBoxGraphics->DrawLine(penRed, x, y, x2, y2);
						}

						if (modelView->IsNetElementSelected(ii))
							pictureBoxGraphics->FillEllipse(myBrushRed, System::Drawing::Rectangle(x - 4, y - 4, 8, 8));
						else
							pictureBoxGraphics->FillEllipse(myBrushGreen, System::Drawing::Rectangle(x - 3, y - 3, 6, 6));
					}
					
					delete penRed;
					delete myBrushGreen;
					delete myBrushRed;
					delete pictureBoxGraphics;
				}
private: System::Void pictureBox2D_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 pb2D_LeftMouseDown = true;
			 pb2D_LeftMouseX	= e->X;
			 pb2D_LeftMouseY	= e->Y;
			 modelView->NetTryReleaseNode();
			 modelView->NetTrySelectNode(e->X,e->Y,3);
			this->Invalidate();
			pictureBox2D->Refresh();
		 }
private: System::Void pictureBox2D_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			pb2D_LeftMouseDown = false;
			
		 }
private: System::Void pictureBox2D_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 if (pb2D_LeftMouseDown)
			 {
				int x = e->X;
				int y = e->Y;
				int deltaX = x - pb2D_LeftMouseX;
				int deltaY = y - pb2D_LeftMouseY;
				modelView->MoveNetByDelta(deltaX,deltaY);
				this->Invalidate();
				pictureBox2D->Refresh();
				
				pb2D_LeftMouseX = x;
				pb2D_LeftMouseY = y;
			 }
		 }
private: System::Void pictureBox2D_MouseLeave(System::Object^  sender, System::EventArgs^  e) 
		 {
			 pb2D_LeftMouseDown = false;
			// modelView->NetTryReleaseNode();
		 }
private: System::Void buttonSave_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 modelView->Save("mapfile.xml", widthImageScale , heightImageScale);
		 }									
private: System::Void menuItemRestore_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 	openFileDialog1->Filter = L"XML|*.xml";
				openFileDialog1->Title = "Select Xml";

				int rows = (int)numericUpDownRows->Value;
				int columns = (int)numericUpDownColumns->Value;

				// Show the Dialog.
				// If the user clicked OK in the dialog and
				if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					std::string fileName = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
					modelView->Restore((char *)fileName.c_str(),widthImageScale,heightImageScale,rows,columns);
				}

				numericUpDownRows->Value = rows;
				numericUpDownColumns->Value = columns;
		 }
private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

