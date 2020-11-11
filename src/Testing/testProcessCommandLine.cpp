//! Unit test for ProcessCommandLine.cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE("Help is requested properly via -h", "[programme_information]")
{
    const std::vector<std::string> cmdLineArgs {"./mpags-cipher","-h"};
    ProgramSettings settings{false,false,"","","",CipherMode::Encrypt};
    REQUIRE(processCommandLine(cmdLineArgs, settings) == true);
}

TEST_CASE("Help is requested properly via --help", "[programme_information]")
{
    const std::vector<std::string> cmdLineArgs {"./mpags-cipher","--help"};
    ProgramSettings settings{false,false,"","","",CipherMode::Encrypt};
    REQUIRE(processCommandLine(cmdLineArgs, settings) == true);
    REQUIRE(settings.helpRequested==true);
}

TEST_CASE("Version number is requested properly", "[programme_information]")
{
    const std::vector<std::string> cmdLineArgs {"./mpags-cipher","--version"};
    ProgramSettings settings{false,false,"","","",CipherMode::Encrypt};
    REQUIRE(processCommandLine(cmdLineArgs, settings) == true);
    REQUIRE(settings.versionRequested==true);
}

TEST_CASE("Input file name recognised properly", "[I/O]")
{
    const std::vector<std::string> cmdLineArgs {"./mpags-cipher","-i","testInput.txt"};
    ProgramSettings settings{false,false,"","","",CipherMode::Encrypt};
    REQUIRE(processCommandLine(cmdLineArgs, settings) == true);
    REQUIRE(settings.inputFile=="testInput.txt");
}

TEST_CASE("Output file name recognised properly", "[I/O]")
{
    const std::vector<std::string> cmdLineArgs {"./mpags-cipher","-o","testOutput.txt"};
    ProgramSettings settings{false,false,"","","",CipherMode::Encrypt};
    REQUIRE(processCommandLine(cmdLineArgs, settings) == true);
    REQUIRE(settings.outputFile=="testOutput.txt");
}

TEST_CASE("Caesar key value recognised properly", "[caesar_setup]")
{
    const std::vector<std::string> cmdLineArgs {"./mpags-cipher","-k","21"};
    ProgramSettings settings{false,false,"","","",CipherMode::Encrypt};
    REQUIRE(processCommandLine(cmdLineArgs, settings) == true);
    REQUIRE(settings.cipher_key=="21");
}

TEST_CASE("Caesar encrypt recognised properly", "[caesar_setup]")
{
    const std::vector<std::string> cmdLineArgs {"./mpags-cipher","--encrypt"};
    ProgramSettings settings{false,false,"","","",CipherMode::Decrypt};
    REQUIRE(processCommandLine(cmdLineArgs, settings) == true);
    REQUIRE(settings.cipherMode == CipherMode::Encrypt);
}

TEST_CASE("Caesar decrypt recognised properly", "[caesar_setup]")
{
    const std::vector<std::string> cmdLineArgs {"./mpags-cipher","--decrypt"};
    ProgramSettings settings{false,false,"","","",CipherMode::Encrypt};
    REQUIRE(processCommandLine(cmdLineArgs, settings) == true);
    REQUIRE(settings.cipherMode == CipherMode::Decrypt);
}