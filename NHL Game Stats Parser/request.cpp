/**
 * Author: Connor McGoey
 * Date: February 6, 2023
 * Description: request class function declarations to call and return information from the 
 * NHL stats api.
 */

#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream>
#include <curl/curl.h>
#include "request.h"

using namespace std;

/**
 * Function Name: WriteMemoryCallback
 * Description: write contents to dynamic memory referenced in userp and then return
 *              the size of the new block of memory
 * Parameters: contents: pointer to what is to be written to dynamic memory, size: the size of the elements already
 *             in dynamic memory, nmemb: the size of the type stored in dynamic memory, userp: pointer to the 
 *             MemoryStruct object in use
 * Return Description: size_t realsize: the size of the data in memory after updating
*/
static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = (char*)realloc(mem->memory, mem->size + realsize + 1);
    if (!ptr)
    {
        /* out of memory! */
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

/**
 * Function Name: request
 * Description: constructor for the request class
 * Parameters: the URL string of the API to be fetched
 * Return Description: N/A
*/
request::request(string URLpath)
{
    this->URL = URLpath;
    mem.memory = (char *)malloc(1); /* will be grown as needed by the realloc above */
    mem.size = 0;                   /* no data at this point */
}

/**
 * Function Name: ~request
 * Description: Destruct the request object by freeing the dynamic memory on the MemoryStruct object
 * Parameters: N/A
 * Return Description: N/A
*/
request::~request()
{
    free(mem.memory);
}

/**
 * Function Name: execute
 * Description: execute the request to the API by making use of libcurl. Stores the data in the 
 *              MemoryStruct object.
 * Parameters: N/A
 * Return Description: boolean True if the request was successful and False otherwise
*/
bool request::execute()
{
    // initialize curl variables
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl_handle;
    CURLcode res;

    /* init the curl session */
    curl_handle = curl_easy_init();
    
    // curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);

    /* Pass in the URL as a C string in order for it to work with curl */
    curl_easy_setopt(curl_handle, CURLOPT_URL, URL.c_str());

    /* send all data to the WriteMemoryCallback */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

    /* Pass the 'MemoryStruct' struct to the callback function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&mem);

    /* some servers do not like requests that are made without a user-agent
    field, so we provide one */
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    res = curl_easy_perform(curl_handle);

    /* check for errors */
    if (res != CURLE_OK)
    {
        // Print error message and then return false if it failes
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
        return false;
    }
    else
    {
        // Return true on success
        return true;
    }

    /* cleanup curl stuff */
    curl_easy_reset(curl_handle);
    free(mem.memory);
    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();
}

/**
 * Function Name: result
 * Description: returns the resulting information returned from the API call
 * Parameters: N/A
 * Return Description: The information stored in the dynamic memory in the MemoryStruct
*/
string request::result() {
    return mem.memory;
}
