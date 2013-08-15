#ifndef __clamp_HPP__
#define __clamp_HPP__


template<class T>
inline T get_clamped( const T& val, const T& min_val, const T& max_val )
{
	if( val < min_val )
		return min_val;
	else if( max_val < val )
		return max_val;
	else
		return val;
}


template<class T>
inline void clamp( T& val, const T& min_val, const T& max_val )
{
	val = get_clamped( val, min_val, max_val );
}


#endif /* __clamp_HPP__ */
