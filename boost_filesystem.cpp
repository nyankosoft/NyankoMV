#include "stdafx.h"
#include "boost_filesystem.hpp"

// When this file is in a Windows Forms Application project,
// including the header in another compilation unit like this
// did not do the job (i.e. it still causes the same error."
// 2013-08-11: This file was moved to a separate project, "windows_forms_application_boost_wrapper"
#include <boost/filesystem.hpp>

using namespace boost::filesystem;


std::string get_leaf( std::string pathname )
{
	return path(pathname).leaf().string();
}

std::string get_parent_path( std::string pathname )
{
	return path(pathname).parent_path().string();
}

std::string concatenate_paths( std::string lhs, std::string rhs )
{
	return path( path(lhs)/path(rhs) ).string();
}

void rename_path( std::string old_pathname, std::string new_pathname )
{
	rename( path(old_pathname), path(new_pathname) );
}

void get_files_in_directory( std::string directory_pathname, int depth )
{
//	using namespace boost::filesystem;

//	path dir_path = directory_pathname;
}