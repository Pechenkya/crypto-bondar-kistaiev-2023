cmake_minimum_required(VERSION 3.8)

#Alias
set(This Lab_AAF_Bondar_Kistaiev)

#Set language
project(${This} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(Headers 
)

set(Sources 
    main.cpp
)

add_executable(${This} ${Headers} ${Sources})
