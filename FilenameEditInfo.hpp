#ifndef __FilenameEditInfo_HPP__
#define __FilenameEditInfo_HPP__

#include <string>
#include <vector>
#include "diff_match_patch.h"
#include "log/DefaultLog.hpp"
#include "log/StringAux.hpp"
#include "boost_filesystem.hpp"

using namespace amorphous;


class FilenameEditInfo
{
public:

	typedef diff_match_patch<std::wstring> dmp;
	typedef dmp::Diffs diff_list;

	FilenameEditInfo(){}
	~FilenameEditInfo(){}

	std::string orig_pathname;

	std::string from_leaf;

	std::string to_leaf;

	dmp::Diffs diffs;
};

class FilenameEditInfoContainer
{
public:
	std::vector<FilenameEditInfo> edit_info;

	void ClearDestLeaves()
	{
		for( size_t i=0; i<edit_info.size(); i++ )
		{
			edit_info[i].to_leaf.clear();
		}
	}

	void CompareSourceAndDestLeavesPair( FilenameEditInfo& filename_edit_info )
	{
		using std::wstring;
		typedef diff_match_patch<std::wstring> dmp;
		typedef dmp::Diffs diff_list;

		dmp diff_calculator;

		const std::string& text_0 = filename_edit_info.from_leaf;
		const std::string& text_1 = filename_edit_info.to_leaf;

		wstring wstring_text_0( text_0.length(), L' ' );
		wstring wstring_text_1( text_1.length(), L' ' );
		std::copy( text_0.begin(), text_0.end(), wstring_text_0.begin() );
		std::copy( text_1.begin(), text_1.end(), wstring_text_1.begin() );
		filename_edit_info.diffs = diff_calculator.diff_main( wstring_text_0, wstring_text_1 );

		LOG_PRINTF(( "src: %s, dest: %s (%d diffs)", filename_edit_info.from_leaf.c_str(), filename_edit_info.to_leaf.c_str(), (int)filename_edit_info.diffs.size() ));
	}

	void CompareSourceAndDestLeaves()
	{
		for( size_t i=0; i<edit_info.size(); i++ )
		{
			CompareSourceAndDestLeavesPair( edit_info[i] );
		}
	}

	void ExecuteRenames()
	{
		for( size_t i=0; i<edit_info.size(); i++ )
		{
			if( edit_info[i].from_leaf == edit_info[i].to_leaf )
				continue;

			std::string parent_path = get_parent_path( edit_info[i].orig_pathname );
			std::string dest_pathname = concatenate_paths( parent_path, edit_info[i].to_leaf );

			rename_path( edit_info[i].orig_pathname, dest_pathname );
		}
	}
};


inline void break_into_lines( const std::string& src_text, std::vector<std::string>& dest_lines )
{
	using std::string;

	const char newline_char = '\n';

	string src_text_copy = src_text;

	size_t i, str_len = src_text.length();
	size_t next_pos = 0, num_separaters = 1;
	string str;

	for( i=0; i<str_len; i++ )
	{
		if( src_text_copy[i] == newline_char )
			break;

		if( 0 < num_separaters )
		{
			if( next_pos < i )
			{
				str = src_text_copy.substr( next_pos, i - next_pos );
//				strncpy( str, pSrcStr + next_pos, i - next_pos );
//				str[i - next_pos] = '\0';
				dest_lines.push_back( str );
			}
			next_pos = i + 1;
		}
	}

	// add the last separated string
	if( next_pos < i )
		dest_lines.push_back( src_text_copy.substr(next_pos) );
}


extern FilenameEditInfoContainer g_FilenameEditInfoContainer;


#endif /* __FilenameEditInfo_HPP__ */
