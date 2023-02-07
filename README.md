# cpp-curl-database-flooding

## To setup the cURL library in Visual Studio, you can follow these steps:

1. Download the cURL library: You can download the pre-compiled library from the official cURL website: https://curl.haxx.se/download.html
2. Extract the library: Extract the contents of the downloaded archive to a directory on your system.
3. Open ``` Developer Command Prompt ``` for Visual Studio
4. ``` $cd C:\curl\winbuild\ ```
5. Run ``` nmake /f Makefile.vc mode=static ```
6. Create a new project in Visual Studio
7. Add the include directory to Visual Studio: In Visual Studio, go to "Project" -> "Properties" -> "VC++ Directories" -> "Include Directories". Add the path to the include directory of the extracted cURL library: ``` C:\curl\builds\libcurl-vc-x86-release-static-ipv6-sspi-winssl\include\ ```
8. Add the library directory to Visual Studio: In Visual Studio, go to "Project" -> "Properties" -> "VC++ Directories" -> "Library Directories". Add the path to the lib directory of the extracted cURL library: ``` C:\curl\builds\libcurl-vc-x86-release-static-ipv6-sspi-winssl\lib\ ```
9. Link the library to your project: In Visual Studio, go to "Project" -> "Properties" -> "Linker" -> "Input" -> "Additional Dependencies" and add ``` Ws2_32.lib ```, ``` libcurl_a.lib ```, ``` Crypt32.lib ```, ``` Wldap32.lib ```, ``` Normaliz.lib ```
