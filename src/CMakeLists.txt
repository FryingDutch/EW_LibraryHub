cmake_minimum_required(VERSION 3.0)
project ( fileServer )

add_executable(fileServer 
		ew_filehandler.cpp
		main.cpp
		)

find_package(CURL REQUIRED)
target_link_libraries(fileServer OpenSSL::SSL)
target_link_libraries(fileServer ${CURL_LIBRARIES})
target_link_libraries(fileServer ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(fileServer cpr::cpr)


