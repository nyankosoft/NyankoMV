#ifndef __windows_forms_application_boost_wrapper__boost_filesystem_HPP__
#define __windows_forms_application_boost_wrapper__boost_filesystem_HPP__


#include <string>

#pragma managed(push, off)

std::string get_leaf( std::string pathname );
std::string get_parent_path( std::string pathname );
std::string concatenate_paths( std::string lhs, std::string rhs );
void get_files_in_directory( std::string directory_pathname, int depth = -1 );

void rename_path( std::string old_pathname, std::string new_pathname );

#pragma managed(pop)


#endif /* __windows_forms_application_boost_wrapper__boost_filesystem_HPP__ */
