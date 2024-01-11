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
FILE *json_file = fopen("response_data.json", "r");
    if (!json_file) {
        fprintf(stderr, "Error opening the JSON file.\n");
        return 1;
    }

    
   // Read the JSON file and parse it
    json_error_t error;
    json_t *root = json_load_file("response_data.json", 0, &error);
    if (!root) {
        fprintf(stderr, "Error parsing JSON data: %s\n", error.text);
        return 1;
    }

    // Extracting weather description 
    json_t *weather = json_object_get(root, "weather");
    if (json_array_size(weather) > 0) {
        json_t *weather_data = json_array_get(weather, 0);
        json_t *description = json_object_get(weather_data, "description");
        if (description && json_typeof(description) == JSON_STRING) {
            printf("Weather Description: %s\n", json_string_value(description));
        }
    }

    
    json_t *main_data = json_object_get(root, "main");
    json_t *temperature = json_object_get(main_data, "temp");
    json_t *humidity = json_object_get(main_data, "humidity");
    json_t *pressure = json_object_get(main_data, "pressure");
    json_t *visibility = json_object_get(root, "visibility");
    json_t *feels_like = json_object_get(main_data,"feels_like");
    json_t *mint = json_object_get(main_data,"temp_min");
    json_t *maxt = json_object_get(main_data,"temp_max");
    json_t *cloud = json_object_get(root, "clouds");
    json_t *percent = json_object_get(cloud, "all");
    json_t *sys = json_object_get(root,"sys");
    json_t *sunrise = json_object_get(sys, "sunrise");
    json_t *sunset = json_object_get(sys, "sunset");
    json_t *country = json_object_get(sys, "country");
    json_t *city = json_object_get(root, "name");
    json_t *wind = json_object_get(root, "speed");
  
    //printing
    printf("%s/%s \n",json_string_value(city),json_string_value(country));
    printf("pressure : %lld  \n",json_integer_value(pressure));
    printf("humidity : %lld percent \n",json_integer_value(humidity));
    printf("visibility : %lld km \n",json_integer_value(visibility)/1000);
    printf("Temperature: %.2f Celsius\n", json_real_value(temperature) - 273.15); 
    printf("feels like : %.2f Celcius\n",json_real_value(feels_like) - 273.15);
    printf("%.2f / %.2f \n" ,json_real_value(mint) - 273.15,json_real_value(maxt) - 273.15);
