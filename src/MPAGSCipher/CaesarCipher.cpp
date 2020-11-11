#include <iostream>

#include "CaesarCipher.hpp"

CaesarCipher::CaesarCipher(const size_t& cipherKey)
: alphabet_{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}, alphabetSize_{alphabet_.size()}, key_{cipherKey%alphabetSize_}
{
}

CaesarCipher::CaesarCipher(const std::string& cipherKey)
: alphabet_{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}, alphabetSize_{alphabet_.size()}, key_{0} 
{
    // We have the key as a string, but the Caesar cipher needs an unsigned long, so we first need to convert it
    // We default (above) to having a key of 0, i.e. no encryption, if no key was provided on the command line
    if ( ! cipherKey.empty() )
    {
        // Before doing the conversion we should check that the string contains a
        // valid positive integer.
        // Here we do that by looping through each character and checking that it
        // is a digit. What is rather hard to check is whether the number is too
        // large to be represented by an unsigned long, so we've omitted that for
        // the time being.
        // (Since the conversion function std::stoul will throw an exception if the
        // string does not represent a valid unsigned long, we could check for and
        // handled that instead but we only cover exceptions very briefly on the
        // final day of this course - they are a very complex area of C++ that
        // could take an entire course on their own!)
        for ( const auto& elem : cipherKey )
        {
            if ( ! std::isdigit(elem) )
            {
                std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
                        << "        the supplied key (" << cipherKey << ") could not be successfully converted and a default key value of 0 has been used." << std::endl;
                return;
            }
        }
        key_ = std::stoul(cipherKey)%alphabetSize_;
    }
}

std::string CaesarCipher::applyCipher(const std::string& inputText, const CipherMode cipherMode) const
{
    // Create the output string
  std::string outputText {};

  // Loop over the input text
  char processedChar {'x'};
  for ( const auto& origChar : inputText ) {

    // For each character in the input text, find the corresponding position in
    // the alphabet by using an indexed loop over the alphabet container
    for ( size_t i{0}; i < alphabetSize_; ++i )
    {

      if ( origChar == alphabet_[i] )
      {
            // Apply the appropriate shift (depending on whether we're encrypting
            // or decrypting) and determine the new character
            // Can then break out of the loop over the alphabet
            switch ( cipherMode )
            {
                case CipherMode::Encrypt:
                    processedChar = alphabet_[ (i + key_) % alphabetSize_ ];
                    break;
                case CipherMode::Decrypt:
                    processedChar = alphabet_[ (i + alphabetSize_ - key_) % alphabetSize_ ];
                    break;
            }
        break;
	    }
    }

    // Add the new character to the output text
    outputText += processedChar;
  }

  return outputText;
}
