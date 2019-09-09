PROJECT(img_diff)
CMAKE_MINIMUM_REQUIRED(VERSION 3.5.1)
if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

FIND_PACKAGE( OpenCV REQUIRED )

# Declare the target (an executable)
ADD_EXECUTABLE(img_diff  img_diff.cpp)

TARGET_LINK_LIBRARIES(img_diff ${OpenCV_LIBS})

#MESSAGE(STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")     //好了，就修改这么点东西，保存，关闭。
