cmake_minimum_required(VERSION 3.0)
project ( fileServer )

set(MY_LIB_INCLUDE_DIRS /EW_LibraryHub/cpr/include/)
include_directories(fileServer PUBLIC ${MY_LIB_INCLUDE_DIRS})

link_directories(/EW_LibraryHub/cpr/build/lib)

add_executable(fileServer 
		ew_filehandler.cpp
		main.cpp
		)

target_link_libraries(fileServer PUBLIC ${MYLIB})
target_link_libraries(fileServer PUBLIC OpenSSL::SSL)
target_link_libraries(fileServer PUBLIC ${CURL_LIBRARIES})
target_link_libraries(fileServer PUBLIC ${CMAKE_THREAD_LIBS_INIT})


