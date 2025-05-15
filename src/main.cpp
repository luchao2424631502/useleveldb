#include "main.h"

TEST(lctest, wrdb) {
    mLevel *ml = new mLevel(MPATH);

    std::string old_key = "key";
    std::string old_value = "value";
    ASSERT_TRUE( ml->write(old_key, old_value) );

    std::string new_value;
    ASSERT_TRUE( ml->read(old_key, new_value) );
    ASSERT_EQ(old_value, new_value);

    ASSERT_TRUE( ml->_delete(old_key) );
    ASSERT_FALSE( ml->read(old_key, new_value) );

    delete ml; 
}

TEST(lctest, dafterr) {
    mLevel *ml = new mLevel(MPATH);

    std::string old_key = "key";
    std::string old_value = "value";
    ASSERT_TRUE( ml->write(old_key, old_value) );
    ASSERT_TRUE( ml->_delete(old_key) );
    leveldb::Status status = (*ml)->Get(leveldb::ReadOptions(), old_key, &old_value);
    ASSERT_TRUE( !status.ok() );
    LOG(ERROR) << status.ToString();
}

int main(int argc, char* argv[])
{
    google::InitGoogleLogging(argv[0]); // 初始化 glog
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}