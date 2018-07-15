#include <iostream>
#include <fstream>
#include <curl/curl.h>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

int main()
{
    FILE* pagefile;

	curl_global_init(CURL_GLOBAL_ALL);
	auto data = curl_version_info(CURLVERSION_NOW);
	std::cout << "libcurl " << data->version << " at " << data->host << "\n";

	auto curl_handle = curl_easy_init();

    curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);
    //curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

	curl_easy_setopt(curl_handle, CURLOPT_URL, "https://sv5.onlinevideoconverter.com/download?file=f5h7a0f5a0e4g6j9");
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);


    pagefile = fopen("file.mp3", "wb");
    if(pagefile)
    {
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);
        curl_easy_perform(curl_handle);
        fclose(pagefile);
    }


	curl_easy_cleanup(curl_handle);
  	curl_global_cleanup();
	return 0;
}