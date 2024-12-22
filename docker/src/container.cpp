#include "../include/container.hpp"
#include <curl/curl.h>
#include <string> 
#include <iostream>
using namespace std;

Container::Container(){};

int Container::getContainers(){
    return 1;
};


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void Container::sendRequest(){
   
  CURL *curl;
  CURLcode res;
  std::string readBuffer;
  curl = curl_easy_init();
  //if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "localhost:2375/v1.45/version");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    std::cout << readBuffer << std::endl;
  //}
   
   
   // try{
   //     auto response = http_client::get("localhost:2375/v1.45/containers/json")
   //	        .add_headers("Accept: '*/*'") // Can be multiple lines for more than one header.
   //	        .add_headers("Accept-Encoding: gzip, deflate, br")
   //         .add_headers("Connection: keep-alive")
   //         .send();
   //     std::cout << "Containers" << response.get_body_string();
   // }catch (http_client::errors::ConnectionFailed const& error) {
   //		std::cout << "The connection failed with error \"" << error.what() << '"';
   //	}
}