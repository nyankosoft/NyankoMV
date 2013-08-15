#pragma once


#include <string>
#include <vector>

#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;

//#include <boost/filesystem.hpp> // The app fails to start when this is included

//#pragma managed(push, off)
//#include <boost/filesystem.hpp> // The app still fails to start when this is included
//#pragma managed(pop)

//#pragma managed(push, off)
//#include "boost_filesystem.hpp"
//#pragma managed(pop)

#include "FilenameEditInfo.hpp"
#include "boost_filesystem.hpp"
#include "log/DefaultLog.hpp"
#include "log/StringAux.hpp"

using namespace amorphous;



#ifdef _DEBUG
#pragma comment (lib,"windows_forms_application_boost_wrapper_d.lib")
#else /* _DEBUG */
#pragma comment (lib,"windows_forms_application_boost_wrapper.lib")
#endif /* _DEBUG */


System::String^ ToString( const std::string& src )
{
	return gcnew System::String(src.c_str());
}


std::string to_string( System::String^ src )
{
    msclr::interop::marshal_context context;
    return std::string( context.marshal_as<std::string>(src) );
}



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

//	private: FilenameEditInfoContainer^  editInfoContainer; // FilenameEditInfoContainer must be a 'public ref class'

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
	private: System::Windows::Forms::Button^  button1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->EnableAutoDragDrop = true;
			this->richTextBox1->Location = System::Drawing::Point(48, 45);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(500, 481);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"abcde\nxyz\n12345";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox1_TextChanged);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(588, 45);
			this->richTextBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(530, 480);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"";
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox2_TextChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(48, 555);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(340, 143);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1251, 13);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(48, 20);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"label2";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(852, 659);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(268, 40);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Rename";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1308, 715);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void UpdateTextColors()
			 {
				typedef diff_match_patch<std::wstring> dmp;
				typedef dmp::Diffs diff_list;

				std::vector<FilenameEditInfo>& edit_info = g_FilenameEditInfoContainer.edit_info;

				std::vector<int> character_offsets;
				character_offsets.resize( edit_info.size(), 0 );
				int offsets_sum = 0;
				for( size_t i=0; i<edit_info.size(); i++ )
				{
					character_offsets[i] = offsets_sum;
					offsets_sum += edit_info[i].to_leaf.length() + 1;
				}

				const int ss1 = richTextBox1->SelectionStart;
				const int ss2 = richTextBox2->SelectionStart;
				const int sl1 = richTextBox1->SelectionLength;
				const int sl2 = richTextBox2->SelectionLength;

				richTextBox1->SelectionStart      = 0;
				richTextBox2->SelectionStart      = 0;
				richTextBox1->SelectionLength     = richTextBox1->Text->Length;
				richTextBox2->SelectionLength     = richTextBox2->Text->Length;
				richTextBox1->SelectionColor      = Color::Black;
				richTextBox2->SelectionColor      = Color::Black;
				richTextBox1->SelectionBackColor  = Color::White;
				richTextBox2->SelectionBackColor  = Color::White;

				for( size_t i=0; i<edit_info.size(); i++ )
				{
					int diff_offset = 0;
					diff_list& diffs = edit_info[i].diffs;
					for( diff_list::const_iterator itr = diffs.begin(); itr != diffs.end(); itr++ )
//					for( size_t j=0; j<edit_info[i].diffs.size(); j++ )
					{
						const dmp::Diff& diff = *itr;

						switch( diff.operation )
						{
						case dmp::DIFF_DELETE:
							richTextBox1->SelectionStart = character_offsets[i] + diff_offset;
							richTextBox1->SelectionLength = diff.text.size();
//							richTextBox1->SelectionFont=fnt;
							richTextBox1->SelectionColor     = Color::Red;
							richTextBox1->SelectionBackColor = Color::Pink;
							break;
						case dmp::DIFF_INSERT:
							richTextBox2->SelectionStart = character_offsets[i] + diff_offset;
							richTextBox2->SelectionLength = diff.text.size();
//							richTextBox2->SelectionFont=fnt;
							richTextBox2->SelectionColor     = Color::Red;
							richTextBox2->SelectionBackColor = Color::Pink;
							break;
						case dmp::DIFF_EQUAL:
							break;
						default:
							LOG_PRINTF_ERROR(( "An unsupported diff type: %d", (int)diff.operation ));
							break;
						}

						diff_offset += diff.text.length();
					}
				}

				richTextBox1->SelectionStart  = ss1;
				richTextBox2->SelectionStart  = ss2;
				richTextBox1->SelectionLength = sl1;
				richTextBox2->SelectionLength = sl2;
			 }

	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void richTextBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {

				 std::vector<std::string> lines;

				 std::string text = to_string( richTextBox2->Text );
				 LOG_PRINTF(( "richTextBox2->Text (converted to std::string): %s", text.c_str() ));
				 break_into_lines( text, lines );

//				 array<String^> array_of_string = richTextBox2->Lines;
				 Array^ text_box_lines = richTextBox2->Lines;
				 lines.resize( 0 );
				 lines.resize( text_box_lines->Length );
				 LOG_PRINTF(( "richTextBox2->Lines->Length %d", text_box_lines->Length ));
				 for( int i=0; i<text_box_lines->Length; i++ )
				 {
					 Object ^obj = text_box_lines->GetValue(i);
					 String ^line = obj->ToString();
					 LOG_PRINTF(( "line[%d]: %s", i, to_string(line).c_str() ));

					 lines[i] = to_string( line );
				 }

				 if( 2 <= lines.size() && lines.back() == "" )
					 lines.erase( lines.end() - 1 );

				 std::vector<FilenameEditInfo>& edit_info = g_FilenameEditInfoContainer.edit_info;

				 LOG_PRINTF(( "edit_info.size(): %d, lines.size(): %d", (int)edit_info.size(), (int)lines.size() ));

				 g_FilenameEditInfoContainer.ClearDestLeaves();
				 if( edit_info.size() < lines.size() )
					 edit_info.insert( edit_info.end(), lines.size() - edit_info.size(), FilenameEditInfo() );

				 // Each line in lines represents an i-th destintion filename

				 for( size_t i=0; i<lines.size(); i++ )
					 edit_info[i].to_leaf = lines[i];

				 g_FilenameEditInfoContainer.CompareSourceAndDestLeaves();

				 UpdateTextColors();
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
//	private: System::Void CreatePathnameList(Array^ file_drop_object_array, std::vector<boost::filesystem::path>& pathnames)
//			{
//				pathnames.resize( file_drop_object_array->Length );
//
//				String^ dropped_objects_string;
//				for( int i=0; i<file_drop_object_array->Length; i++ )
//				{
//					Object^ element = file_drop_object_array->GetValue(i);
//					//Type^ type = element->GetType();
//					String^ element_string = element->ToString();
//					dropped_objects_string += element_string;
//					dropped_objects_string += "\n";
//				}
//			}
	private: System::Void Form1_DragDrop_InputRichTextBox(System::Object^  sender, DragEventArgs^ e)
			{
				System::Windows::Forms::IDataObject^ data_object = e->Data;
				Object^ file_drop_object = data_object->GetData( DataFormats::FileDrop );
				Array^ file_drop_object_array = (Array^)data_object->GetData( DataFormats::FileDrop );
				if( file_drop_object == nullptr )
				{
					MessageBox::Show( "No object was found in the dropped data object.","DragDrop", MessageBoxButtons::OK );
					return;
				}


//				std::vector<boost::filesystem::path> pathnames;
//				CreatePathnameList( file_drop_object_array, pathnames );

				String^ num_items = System::Convert::ToString(file_drop_object_array->Length);

//				String^ obj_str = file_drop_object->ToString();

				std::vector<FilenameEditInfo>& edit_info = g_FilenameEditInfoContainer.edit_info;
				edit_info.resize( file_drop_object_array->Length );
				for( int i=0; i<file_drop_object_array->Length; i++ )
				{
					Object^ obj = file_drop_object_array->GetValue(i);
					edit_info[i].orig_pathname = to_string( obj->ToString() );

					edit_info[i].from_leaf = get_leaf( edit_info[i].orig_pathname );

//					obj_str += obj->ToString() + "\n";
				}

				// Create text for the text buffer
				String^ obj_str = "";
				this->richTextBox1->Clear();
				this->richTextBox2->Clear();
				for( size_t i=0; i<edit_info.size(); i++ )
				{
					obj_str += ::ToString( edit_info[i].from_leaf ) + L"\n";
					this->richTextBox1->Text += ::ToString( edit_info[i].from_leaf ) + Environment::NewLine;
					this->richTextBox2->Text += ::ToString( edit_info[i].from_leaf ) + Environment::NewLine;
				}

//				this->richTextBox1->Text = obj_str;
//				this->richTextBox2->Text = obj_str;

//				MessageBox::Show(
//					obj_str,// + "\n" + dropped_objects_string,
//					"DragDrop: " + num_items,
//					MessageBoxButtons::OK
//					);

//				richTextBox1->Text = "";
//				for( size_t i=0; i<pathnames.size(); i++ )
//				{
//					richTextBox1->Text += ::ToString( pathnames[i].leaf().string() );
//				}

				Form1_PrintEventInfo( sender, e );
			}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}

