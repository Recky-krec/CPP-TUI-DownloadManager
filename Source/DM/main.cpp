#include <iostream>
#include <fstream>
#include <curl/curl.h>

// for testing: https://img.memecdn.com/quack-quack-motherfucker_o_1174873.jpg

static size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

int main()
{
    std::string url, outputFileName;
    std::cout << "URL: ";
    std::cin >> url;
    std::cout << "Output Filename (don't put extension): ";
    std::cin >> outputFileName;


    FILE* pageFile;
	curl_global_init(CURL_GLOBAL_ALL);
	auto data = curl_version_info(CURLVERSION_NOW);
	std::cout << "libcurl " << data->version << " at " << data->host << "\n";
	auto curlHandle = curl_easy_init();


	curl_easy_setopt(curlHandle, CURLOPT_VERBOSE, 1L);
    //curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
	curl_easy_setopt(curlHandle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, write_data);


    pageFile = fopen( (outputFileName + std::string(".out")).c_str(), "wb");
    if(pageFile)
    {
        curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, pageFile);
        curl_easy_perform(curlHandle);
        fclose(pageFile);
    }


	curl_easy_cleanup(curlHandle);
  	curl_global_cleanup();
	return 0;
}