//! Unit test for CaesarCipher.cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "ProcessCommandLine.hpp"

TEST_CASE("cipher uses a key to correctly encrypt a simple string", "[cipher]")
{
    std::string str_key{""};
    unsigned int int_key{};
    std::string test{"TEST"};
    std::string encryptedTest{"DOCD"};
    
    SECTION("cipher implements an empty key correctly")
    {
        CaesarCipher caesar{str_key};
        REQUIRE(caesar.applyCipher(test, CipherMode::Encrypt)==test);
        REQUIRE(caesar.applyCipher(test, CipherMode::Decrypt)==test);
    }
    SECTION("cipher implements a null key correctly")
    {
        str_key="0";
        CaesarCipher caesar{str_key};
        REQUIRE(caesar.applyCipher(test, CipherMode::Encrypt)==test);
        REQUIRE(caesar.applyCipher(test, CipherMode::Decrypt)==test);
    }
    SECTION("cipher implements a key within [1,25] correctly")
    {
        str_key="10";
        CaesarCipher caesar{str_key};
        REQUIRE(caesar.applyCipher(test, CipherMode::Encrypt)==encryptedTest);
        REQUIRE(caesar.applyCipher(encryptedTest, CipherMode::Decrypt)==test);
    }
    SECTION("cipher implements a multiple of 26 correctly")
    {
        str_key="26";
        CaesarCipher caesar{str_key};
        REQUIRE(caesar.applyCipher(test, CipherMode::Encrypt)==test);
        REQUIRE(caesar.applyCipher(test, CipherMode::Decrypt)==test);
    }
    SECTION("cipher implements a key >25 that isn't a multiple of 26 correctly")
    {
        str_key="36";
        CaesarCipher caesar{str_key};
        REQUIRE(caesar.applyCipher(test, CipherMode::Encrypt)==encryptedTest);
        REQUIRE(caesar.applyCipher(encryptedTest, CipherMode::Decrypt)==test);
    }

    //Repeat tests but using an integer input
    SECTION("cipher implements an empty key correctly")
    {
        CaesarCipher caesar{int_key};
        REQUIRE(caesar.applyCipher(test, CipherMode::Encrypt)==test);
        REQUIRE(caesar.applyCipher(test, CipherMode::Decrypt)==test);
    }
    SECTION("cipher implements a null key correctly")
    {
        int_key=0;
        CaesarCipher caesar{int_key};
        REQUIRE(caesar.applyCipher(test, CipherMode::Encrypt)==test);
        REQUIRE(caesar.applyCipher(test, CipherMode::Decrypt)==test);
    }
    SECTION("cipher implements a key within [1,25] correctly")
    {
        int_key=10;
        CaesarCipher caesar{int_key};
        REQUIRE(caesar.applyCipher(test, CipherMode::Encrypt)==encryptedTest);
        REQUIRE(caesar.applyCipher(encryptedTest, CipherMode::Decrypt)==test);
    }
    SECTION("cipher implements a multiple of 26 correctly")
    {
        int_key=26;
        CaesarCipher caesar{int_key};
        REQUIRE(caesar.applyCipher(test, CipherMode::Encrypt)==test);
        REQUIRE(caesar.applyCipher(test, CipherMode::Decrypt)==test);
    }
    SECTION("cipher implements a key >25 that isn't a multiple of 26 correctly")
    {
        int_key=36;
        CaesarCipher caesar{int_key};
        REQUIRE(caesar.applyCipher(test, CipherMode::Encrypt)==encryptedTest);
        REQUIRE(caesar.applyCipher(encryptedTest, CipherMode::Decrypt)==test);
    }
}