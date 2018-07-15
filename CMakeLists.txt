cmake_minimum_required(VERSION 2.8)

project(CPP_TUI_DownloadManager)

file(GLOB_RECURSE myCode "Source/DM/*")

include_directories(Source/DM/)
include_directories(Source/DM/3rdParty/CURL/include/)

add_executable(${PROJECT_NAME} ${myCode})

# Linking Curl (Dynamic Lib)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/Source/DM/3rdParty/CURL/lib/libcurl.so)