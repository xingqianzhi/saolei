project(sanziqi)
aux_source_directory(src SRC_SUB)
aux_source_directory(. SRC_CUR)
add_executable(main ${SRC_SUB} ${SRC_CUR})
# include_directories(include)

include_directories(${PROJECT_SOURCE_DIR}/include)#添加头文件的搜索路径

#设置debug模式
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")


# C的解决办法
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fexec-charset=GBK")
# C++ 的解决办法
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")