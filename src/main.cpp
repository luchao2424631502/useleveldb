#include <iostream>
#include <leveldb/db.h>

#include <glog/logging.h>

int main(int argc, char* argv[])
{
    google::InitGoogleLogging(argv[0]); // 初始化 glog
    leveldb::DB *db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "./tmpdb", &db);

    LOG(ERROR) << "db started, status: " << status.ToString() << std::endl;

    delete db;
    return 0;
}