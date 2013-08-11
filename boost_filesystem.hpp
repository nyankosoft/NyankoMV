#ifndef __windows_forms_application_boost_wrapper__boost_filesystem_HPP__
#define __windows_forms_application_boost_wrapper__boost_filesystem_HPP__


#include <string>

#pragma managed(push, off)

std::string get_leaf( std::string pathname );
void get_files_in_directory( std::string directory_pathname, int depth = -1 );

#pragma managed(pop)


#endif /* __windows_forms_application_boost_wrapper__boost_filesystem_HPP__ */