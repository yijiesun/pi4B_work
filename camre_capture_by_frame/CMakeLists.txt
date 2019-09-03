PROJECT(cam_cap)
CMAKE_MINIMUM_REQUIRED(VERSION 3.5.1)
if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

FIND_PACKAGE( OpenCV REQUIRED )
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
# Declare the target (an executable)
ADD_EXECUTABLE(cam_cap  cam_cap.cpp)

TARGET_LINK_LIBRARIES(cam_cap ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})

#MESSAGE(STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")
