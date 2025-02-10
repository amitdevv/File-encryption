#include "encryption.h"
#include <fstream>
// fstream->This means it can create , write files, and read data from file
#include <cctype>

using namespace std;

bool performCeaserCipher(string &content, bool encrypt)
{
  int shift = encrypt ? 3 : -3;

  for (char &ch : content)
  {
    if (isalpha(ch))
    {
      char base = isupper(ch) ? 'A' : 'a';
      ch = static_cast<char>((ch - base + shift + 26) % 26 + base);
    }
  }

  return true;
}

bool encryptFile(const string &filename, bool encrypt)
{

  // Open the input file
  ifstream inFile(filename);
  if (!inFile)
  {
    return false;
  }

  // Read the content of the file and store in content
  string content((istreambuf_iterator<char>(inFile)), {});
  inFile.close();

  // performing caesar cipher method
  if (performCeaserCipher(content, encrypt))
  {
    // creating an output file and writing modified content
    ofstream outFile(encrypt ? "ecrypted_" + filename : "decrypted_" + filename);
    if (!outFile)
    {
      return false;
    }

    outFile << content;
    outFile.close();
    return true;
  }
}