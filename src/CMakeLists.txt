include(GoogleTest)
file(GLOB SRC_MAIN CONFIGURE_DEPENDS *.cpp)

add_executable(main ${SRC_MAIN})

# 设置头文件目录
include_directories(main PUBLIC ${CMAKE_HOME_DIRECTORY}/include)

# 链接相关库
target_link_libraries(main PRIVATE gflags::gflags glog::glog GTest::gtest)
target_link_libraries(main PRIVATE PkgConfig::FUSE3)
target_link_libraries(main PRIVATE leveldb::leveldb)