PROJECT(VideoInputDetector) #Project name is VideoInputDetector
CMAKE_MINIMUM_REQUIRED (VERSION 2.8.3)
SET(CMAKE_BUILD_TYPE Release) # Release, RelWithDebInfo
SET(CMAKE_VERBOSE_MAKEFILE off) #do not change

SET_PROPERTY(GLOBAL PROPERTY TARGET_SUPPORT_SHARED_LIBS TRUE)#do not change
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/")#do not change

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")#do not change

set(CMAKE_CONFIGURATION_TYPES RELEASE CACHE TYPE INTERNAL FORCE)#do not change

Find_package(OpenCV REQUIRED) #find opencv or other software pkg automatically, not necessary, can also be given manually

ADD_DEFINITIONS(-D NON_MATLAB_PARSING -D MAX_EXT_API_CONNECTIONS=255) # add #Define -D NON_MATLAB_PARSING

#set(OpenCV_DIR D:/1-Education/6_Projects/Kinect/opencv/) # set Opencv Path

#set include path for example head file, necessary
include_directories(
	
	${OpenCV_INCLUDE_DIR}
	
)

#copy dll to bin folder
add_custom_target(CopyFolder 
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/dlls"     ${CMAKE_CURRENT_BINARY_DIR}/Release
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/dlls"     ${CMAKE_CURRENT_BINARY_DIR}/Debug

   
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}) #do not change




##########################
## Build User Interface ##
##########################
LINK_DIRECTORIES(lib) #set path that include library xxxx.lib, necessary

add_executable(VideoInputDetector #name of a executable subproject necessary

src/main.cpp #source file here

)

target_link_libraries(VideoInputDetector  # link the static lib or dynamic dll to a executable subproject
	
	
	${OpenCV_LIBS} #will automatically found in opencv path
	${OpenCV_LIBRARIES} #will automatically found in opencv path

)

