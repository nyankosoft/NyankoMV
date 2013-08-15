#ifndef  __amorphous_LogInputBase_HPP__
#define  __amorphous_LogInputBase_HPP__


#include <vector>
#include <string>
#include <boost/timer/timer.hpp>

#include "LogOutputBase.hpp"
#include "TimeFormats.hpp"


namespace amorphous
{


class LogOutputBase;


class LogInputBase
{
	char *m_pBuffer;
	int m_BufferSize;

	TimeFormat::Format m_TimeStampFormat;

	boost::timer::cpu_timer m_Timer;

	/// holds pointers to output device (borrowed reference)
	/// NOTE: user is responsible for releasing these instances
	std::vector<LogOutputBase *> m_vecpLogOutput;

	void PrintInternal( int filter_val, const char *format,... );

	void GetTimeStampString( std::string& strTime );

	void SendLogMessageToOutput( int filter_val, const std::string strText );

public:

	enum Param
	{
		MAX_LOG_TEXT_BUFFER_SIZE = 1024
	};

	LogInputBase( int buffer_size = MAX_LOG_TEXT_BUFFER_SIZE );

	virtual ~LogInputBase();

	void Print( const std::string& text );

	void Print( int filter_val, const std::string& text );

	void Print( const char *format,... );

	void Print( int filter_val, const char *format,... );

	/// add a log output instance to the list
	inline void AddLogOutputDevice( LogOutputBase *pLogOutput ) { m_vecpLogOutput.push_back( pLogOutput ); }
	inline void AddLogOutput( LogOutputBase *pLogOutput ) { AddLogOutputDevice( pLogOutput ); } /// deprecated

	/// removes the specified log output instance from the list
	/// returns fales if it was not found in the list
	/// NOTE: does not release the actual memory, just releases the pointer from the list
	bool RemoveLogOutputDevice( LogOutputBase *pLogOutput );
	bool RemoveLogOutput( LogOutputBase *pLogOutput ) { return RemoveLogOutputDevice(pLogOutput); } /// deprecated

	void RemoveAllLogOutputDevices() { m_vecpLogOutput.resize( 0 ); }

	virtual bool TestFilter( int filter_val ) { return true; }

	TimeFormat::Format GetTimeStampFormat() { return m_TimeStampFormat; }

	void SetTimeStampFormat( TimeFormat::Format time_format ) { m_TimeStampFormat = time_format; }

	unsigned long GetCurrentTimeMS() const;

//	inline std::vector<CLogBase *>& GetLogOutput() const { return m_vecpLogOutput; }

};


class LogInput_Default : public LogInputBase
{

	/// filter reference value
	/// the filter value handed as an argument in Print() is tested against this by default
	int m_FilterRefVal;

	int m_FilterType;

public:

	enum eFilterType
	{
		FILTER_EQUAL,
		FILTER_LESS_THAN_REFVAL,
		FILTER_LESSTHAN_EQUALTO_REFVAL,
		FILTER_GREATER_THAN_REFVAL,
		FILTER_GREATERTHAN_EQUALTO_REFVAL,
		NUM_FILTERTYPES
	};
	
	LogInput_Default() : m_FilterRefVal(0), m_FilterType(FILTER_GREATERTHAN_EQUALTO_REFVAL) {}

	virtual ~LogInput_Default() {}


	void SetRefVal( int ref_val ) { m_FilterRefVal = ref_val; }

	int GetRefVal() const { return m_FilterRefVal; }

	void SetFilterType( int filter_type ) { m_FilterType = filter_type; }

	int GetFilterType() const { return m_FilterType; }

	virtual bool TestFilter( int filter_val );
};

} // namespace amorphous



#endif		/*  __amorphous_LogInputBase_HPP__  */
