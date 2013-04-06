#pragma once


#include <string>
//#include <boost/filesystem.hpp>


namespace namechanger {

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

			// Enable drag-and-drop operations and 
			// add handlers for DragEnter and DragDrop. 
			this->AllowDrop = true;
			this->DragEnter += gcnew DragEventHandler( this, &Form1::Form1_DragEnter );
			this->DragLeave += gcnew EventHandler( this, &Form1::Form1_DragLeave );
//			this->DragDrop += gcnew DragEventHandler( this, &Form1::Form1_DragDrop );
//			this->DragOver += gcnew DragEventHandler( this, &Form1::Form1_DragOver );

			this->richTextBox1->AllowDrop = true;
			this->richTextBox2->AllowDrop = true;
			this->groupBox1->AllowDrop = true;
			this->richTextBox1->DragDrop += gcnew DragEventHandler( this, &Form1::Form1_DragDrop_InputRichTextBox );
			this->richTextBox2->DragDrop += gcnew DragEventHandler( this, &Form1::Form1_DragDrop_InputRichTextBox );
			this->groupBox1->DragDrop += gcnew DragEventHandler( this, &Form1::Form1_DragDrop_InputRichTextBox );
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
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	protected: 

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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->EnableAutoDragDrop = true;
			this->richTextBox1->Location = System::Drawing::Point(32, 32);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(335, 341);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"abcde\nxyz\n12345";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox1_TextChanged);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(392, 32);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(355, 340);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"";
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox2_TextChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(32, 392);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(227, 101);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(834, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 12);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 12);
			this->label2->TabIndex = 4;
			this->label2->Text = L"label2";
			// 
			// Form1
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(872, 505);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void richTextBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void Form1_PrintEventInfo(System::Object^  sender, System::EventArgs^  e) {
				 String^ name = e->GetType()->GetEnumName(e);
				 array<Char>^ char_array = name->ToCharArray();

				 std::string dest = "Event: ";
				 for( int i=0; i<char_array->Length; i++ )
				 {
					 char c = char_array[i];
					 dest += c;
				 }

//				 MessageBox::Show( dest.c_str(), __FUNCTION__, MessageBoxButtons::OK );
			 }
	private: System::Void Form1_DragDrop(System::Object^  sender, DragEventArgs^ e) {
				 MessageBox::Show( "","DragDrop", MessageBoxButtons::OK );
				 Form1_PrintEventInfo( sender, e );
			 }
	private: System::Void Form1_DragEnter(System::Object^  sender, DragEventArgs^ e) {
//				 MessageBox::Show( "","DragEnter", MessageBoxButtons::OK );
				 label1->Text = "DragEnter";
//				 richTextBox1->ReadOnly = false;
//				 Form1_PrintEventInfo( sender, e );
			 }
	private: System::Void Form1_DragLeave(System::Object^  sender, EventArgs^ e) {
//				 MessageBox::Show( "","DragLeave", MessageBoxButtons::OK );
				 label1->Text = "DragLeave";
//				 richTextBox1->ReadOnly = true;
//				 Form1_PrintEventInfo( sender, e );
			 }
	private: System::Void Form1_DragOver(System::Object^  sender, DragEventArgs^ e) {
				 MessageBox::Show( "","DragOver", MessageBoxButtons::OK );
//				 Form1_PrintEventInfo( sender, e );
			 }

	private: System::Void Form1_DragEnter_InputRichTextBox(System::Object^  sender, DragEventArgs^ e) {
				 label2->Text = "DragEnter";
			}
	private: System::Void Form1_DragLeave_InputRichTextBox(System::Object^  sender, EventArgs^ e) {
				 label2->Text = "DragLeave";
			}
	private: System::Void Form1_DragDrop_InputRichTextBox(System::Object^  sender, DragEventArgs^ e)
			{
				IDataObject^ data_object = e->Data;
				Object^ file_drop_object = data_object->GetData( DataFormats::FileDrop );
				Array^ file_drop_object_array = (Array^)data_object->GetData( DataFormats::FileDrop );
				if( file_drop_object == nullptr )
				{
					MessageBox::Show( "No object was found in the dropped data object.","DragDrop", MessageBoxButtons::OK );
					return;
				}

				String^ dropped_objects_string;
				for( int i=0; i<file_drop_object_array->Length; i++ )
				{
					Object^ element = file_drop_object_array->GetValue(i);
					Type^ type = element->GetType();
					String^ element_string = element->ToString();
					dropped_objects_string += element_string;
					dropped_objects_string += "\n";
				}

				String^ num_items = System::Convert::ToString(file_drop_object_array->Length);

				String^ obj_str = file_drop_object->ToString();

				MessageBox::Show(
					obj_str + "\n" + dropped_objects_string,
					"DragDrop: " + num_items,
					MessageBoxButtons::OK
					);

				richTextBox1->Text = dropped_objects_string;

				Form1_PrintEventInfo( sender, e );
			}
	};
}

