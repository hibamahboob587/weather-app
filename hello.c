#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <jansson.h>
#include "alert.h"
#include <string.h>
#include <time.h>

size_t write_callback(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

int main() {
    CURL *curl;
    FILE *file;
    CURLcode res;
    curl = curl_easy_init();

    if (!curl) {
        fprintf(stderr, "Error initializing curl.\n");
        return 1;
    }

    const char *url = "https://api.openweathermap.org/data/2.5/weather?q=Karachi&appid=c3bbb66ff397bf859bf0c033ffd4606e";
    file = fopen("response_data.json", "wb");
    if (!file) {
        fprintf(stderr, "Error opening file!\n");
        curl_easy_cleanup(curl);
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        fclose(file);
        curl_easy_cleanup(curl);
        return 1;
    } else {
        printf("*************************************\n");
    }

    fclose(file);
    curl_easy_cleanup(curl);
