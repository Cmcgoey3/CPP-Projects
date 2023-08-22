/**
 * Author: Connor McGoey
 * Date: February 6, 2023
 * Description: header file for the request class and the MemoryStruct struct used in the
 * request class.
 */

#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <curl/curl.h>

// MemoryStruct struct used in the request class
struct MemoryStruct
{
    char *memory;       // char pointer to the dynamically allocated place in memory
    std::size_t size;   // size of the memory taken up
};

/**
 * request class prototype
*/
class request
{
// private members including the URL string for the API and the MemoryStruct instance
private:
    std::string URL;
    struct MemoryStruct mem;

// public method prototypes for the request class
public:
    request(std::string URLpath);

    ~request();

    void setURL(std::string newURL);

    std::string getURL();

    bool execute();

    std::string result();
};

#endif
