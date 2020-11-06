#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include <vector>

#include "CipherMode.hpp"

class CaesarCipher{
    public:
        explicit CaesarCipher(const size_t& cipherKey);
        explicit CaesarCipher(const std::string& cipherKey);

        std::string applyCipher(const std::string& inputText, const CipherMode encrypt) const;
        
    private:
        const std::vector<char> alphabet_;
        const size_t alphabetSize_;
        size_t key_;
};
#endif // MPAGSCIPHER_CAESARCIPHER_HPP 