#ifndef IO_STREAM_HPP_
#define IO_STREAM_HPP_

#include <string>

using namespace std;

// Io_Stream is a wrapper class for getting the input command string and writting
// the output response string

class Io_Stream
{
public:
	Io_Stream();
	virtual ~Io_Stream();
	
	std::string Io_StreamGetLine(void);
	
	void Io_StreamPutLine(std::string outputString);
};

#endif /*IO_STREAM_HPP_*/
