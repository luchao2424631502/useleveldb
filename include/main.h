#ifndef MAIN_H
#define MAIN_H

#include <leveldb/db.h>
#include <glog/logging.h>
#include <gtest/gtest.h>

#define MPATH "./tmpdb"

class Kvs {
    public:
        Kvs(const std::string &path):path(path) {}
        ~Kvs() {}
    public:
        const std::string path;

        virtual bool open() = 0;
};

class mLevel : public Kvs {
    public:
        mLevel(const std::string &path):Kvs(path) {
            open();
        } 
        ~mLevel(); 
    public:
        leveldb::DB *db;
        leveldb::Options options;

        bool open();
        bool write(const std::string &key, const std::string &value);
        bool read(const std::string &key, std::string &value);
        bool _delete(const std::string &key);

        leveldb::DB *operator->() {
            return db;
        }
};

mLevel::~mLevel() {
    delete db;
}

bool mLevel::open() {
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, path, &db);
    LOG(ERROR) << "db started, status: " << status.ToString() << std::endl;
    return status.ok();
}

bool mLevel::write(const std::string &key, const std::string &value) {
    leveldb::Status status = db->Put(leveldb::WriteOptions(), key, value);
    return status.ok();
}

bool mLevel::read(const std::string &key, std::string &value) {
    leveldb::Status status = db->Get(leveldb::ReadOptions(), key, &value);
    return status.ok();
}

bool mLevel::_delete(const std::string &key) {
    leveldb::Status status = db->Delete(leveldb::WriteOptions(), key);
    return status.ok();
}
#endif