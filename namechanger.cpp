// namechanger.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include "log/LogOutput.hpp"

using namespace namechanger;


FilenameEditInfoContainer g_FilenameEditInfoContainer;


[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
//	MessageBox::Show( "Starting the application...", "Starting", MessageBoxButtons::OK );

	LogOutput_HTML html_log( "log.html" );
	GlobalLog().AddLogOutput( &html_log );

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
