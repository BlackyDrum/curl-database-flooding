# Database-Flooding with cURL and C++

## To setup the cURL library in Visual Studio, you can follow these steps:

1. Download the cURL library: You can download the pre-compiled library from the official cURL website: https://curl.haxx.se/download.html
2. Extract the library: Extract the contents of the downloaded archive to a directory on your system.
3. Open ``` Developer Command Prompt ``` for Visual Studio and  ```$cd C:\curl\winbuild\```
4. Run ``` nmake /f Makefile.vc mode=static ```
5. Create a new project in Visual Studio
6. Add the include directory to Visual Studio: In Visual Studio, go to "Project" -> "Properties" -> "VC++ Directories" -> "Include Directories". Add the path to the include directory of the extracted cURL library: ``` C:\curl\builds\libcurl-vc-x86-release-static-ipv6-sspi-winssl\include\ ```
7. Add the library directory to Visual Studio: In Visual Studio, go to "Project" -> "Properties" -> "VC++ Directories" -> "Library Directories". Add the path to the lib directory of the extracted cURL library: ``` C:\curl\builds\libcurl-vc-x86-release-static-ipv6-sspi-winssl\lib\ ```
8. Link the library to your project: In Visual Studio, go to "Project" -> "Properties" -> "Linker" -> "Input" -> "Additional Dependencies" and add ``` Ws2_32.lib ```, ``` libcurl_a.lib ```, ``` Crypt32.lib ```, ``` Wldap32.lib ```, ``` Normaliz.lib ```
9. You can try to build this sample program:
```c++
#define CURL_STATICLIB
#include <curl\curl.h>

int main()
{
    CURL *curl;

    curl = curl_easy_init();
    curl_easy_cleanup(curl);

    return 0;
}
```
10. Add the main.cpp to your project and make sure to put the data folder in the directory containing the project file (.vcxproj)

## How to use:
You have to specify the URL you want to send the request to:
```c++
std::string url = "www.example.com";
```
After that, you need to choose the HTTP-Method the server is expecting, most commonly POST for forms:
```c++
curl_easy_setopt(curl, CURLOPT_POST, 1L);
// OR curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
```
You can choose the amount of requests you want to send to the server:
```c++
int loopAmount = 1;
```
You have to specify the form data to be sent in the request:
```c++
std::string data = "email=" + localPart + randomNum + "@" + domainPart + 
                   "&password=" + password;
// Add more parameters with "&param="
```
Try to run. A random Email Address and Password will be generated every loop.

*NOTE:* <b> The code provided in this repository is for educational purposes only and should not be used for harmful purposes. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the code or the use or other dealings in the code. </b>
