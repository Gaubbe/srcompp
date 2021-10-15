# srcompp
**srcompp** is a C++ library used to access the speedrun.com API and parse the results into objects.

## Building
This project uses CMake. You will need OpenSSL pre-installed on your computer. The other dependencies are included using git submodules.

1. Configure CMake with this command  
`cmake -DOPENSSL_ROOT_DIR="path/to/openssl" -B ./build/ .` <br><br>
You may set options for building a shared library as opposed to a static library  

2. Build using this command  
`cmake --build ./build/`