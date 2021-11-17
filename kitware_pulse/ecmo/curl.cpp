#include <iostream>
#include <stdio.h>
#include <string>
#include <curl/curl.h>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void getFromDB()
{
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://46y7wzkd1j.execute-api.ap-southeast-2.amazonaws.com/chapters");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    std::cout << readBuffer << std::endl;
  }

}


void putToDB(std::string id, double time, std::string jsonString)
{
  CURL *curl;
  CURLcode res;
  char curl_url[1024];
  char curl_fields[1024];

  curl_global_init(CURL_GLOBAL_ALL);

  curl = curl_easy_init();
  if(curl)
  {
    snprintf(curl_url, sizeof(curl_url), "https://46y7wzkd1j.execute-api.ap-southeast-2.amazonaws.com/vitals");
    snprintf(curl_fields, sizeof(curl_fields),"%s", jsonString.c_str());

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
    curl_easy_setopt(curl, CURLOPT_URL, curl_url);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, curl_fields);

    res = curl_easy_perform(curl);
    
    if (res != CURLE_OK) 
    {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
  }
}