#include "Io_stream.hpp"

// public constructor
Io_Stream::Io_Stream()
{
	// do nothing
}

// destructor
Io_Stream::~Io_Stream()
{
}

#define MAX_INPUT_STREAM_LENGTH (128)

// NOTE: Do not use <iostream> library functions (cin, cout) because they take
//       too much memory.  This code must fit into 128KB of L3 Memory.  Stick
//       with the <stdio> functions.

std::string Io_Stream::Io_StreamGetLine(void)
{
	char inputString[MAX_INPUT_STREAM_LENGTH];

	// Get a line from stdin
	fgets(inputString, MAX_INPUT_STREAM_LENGTH, stdin);
	/* Remove trailing newline, if there. */
    if (inputString[strlen (inputString) - 1] == '\n')
    {
        inputString[strlen (inputString) - 1] = '\0';
    }
	
	std::string returnString(inputString);
	return(returnString);
}

void Io_Stream::Io_StreamPutLine(std::string outputString)
{
	printf("%s\r\n", outputString.c_str());
	return;
}
