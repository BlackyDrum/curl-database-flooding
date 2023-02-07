#include <iostream>
#include <curl/curl.h>
#include <string>
#include <random>
#include <time.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>

int main() {

    srand(time(NULL));

    CURL* curl;
    CURLcode res;

    std::ifstream name_list, domain_list, surname_list, password_list;
    name_list.open("data/names.txt", std::ios::in);
    domain_list.open("data/domain.txt", std::ios::in);
    surname_list.open("data/surnames.txt", std::ios::in);
    password_list.open("data/passwords.txt", std::ios::in);

    if (!name_list.is_open() || !domain_list.is_open() || !surname_list.is_open() || !password_list.is_open()) {
        std::cout << "Error opening one or more file!" << std::endl;
        return -1;
    }

    std::string name = "";
    std::vector<std::string> nameVector;

    while (std::getline(name_list, name)) {
        nameVector.push_back(name);
    }
    name_list.close();

    std::string surname = "";
    std::vector<std::string> surnameVector;

    while (std::getline(surname_list, surname)) {
        /* Cast Names in names.txt to lowercase */
        std::transform(surname.begin(), surname.end(), surname.begin(),
            [](unsigned char c) { return std::tolower(c); });
        surnameVector.push_back(surname);
    }
    surname_list.close();
    

    std::string domain = "";
    std::vector<std::string> domainVector;

    while (std::getline(domain_list, domain)) {
        domainVector.push_back(domain);
    }
    domain_list.close();

    std::string password = "";
    std::vector<std::string> passwordVector;

    while (std::getline(password_list, password)) {
        passwordVector.push_back(password);
    }
    password_list.close();




    curl = curl_easy_init();


    if (curl) {
        
        /* Set the URL to send the request to */
        const char* url = "www.example.com";
        curl_easy_setopt(curl, CURLOPT_URL, url);

        /* Set the request type to POST OR GET */
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        /* Set the amount of curl requests */
        int loopAmount = 1;

        for (int i = 0; i < loopAmount; i++) {

            /* Generate random email address */
            std::string domainPart, localPart;

            int num = rand() % domainVector.size();
            domainPart = domainVector[num];

            num = rand() % nameVector.size();
            localPart = nameVector[num];
            num = rand() % surnameVector.size();
            int tmp = rand() % 3;
            switch (tmp) {
                case 0: localPart += "." + surnameVector[num]; break;
                case 1: localPart += surnameVector[num]; break;
            }

            /* Generate random number */
            std::string randomNum = std::to_string(rand() % 10000 + 100);

            /* Get random password from passwords.txt */
            num = rand() % passwordVector.size();
            std::string password = passwordVector[num];

            /* Form data to be sent in the request */
            std::string data = "email=" + localPart + randomNum + "@" + domainPart + 
                               "&password=" + password;
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

            /* Send the request */
            res = curl_easy_perform(curl);

            /* Check for errors */
            if (res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
                
        }

        /* cleanup */
        curl_easy_cleanup(curl);
        
    }

    return 0;
}
