#include <iostream>
#include <string>
#include <optional>
#include <exception>

std::optional<int> TryStrToInt(const std::string &input);

std::optional<int> TryStrToInt(const std::string &input)
{
  try
  {
    int output = std::stoi(input);
    return output;
  }
  catch (std::exception &ex)
  {
    return std::nullopt;
  }
}

void ReplaceAll(std::string& input, const std::string& findStr, const std::string& replaceStr);

void ReplaceAll(std::string &input, const std::string &findStr, const std::string &replaceStr)
{
  size_t startPos = std::string::npos;
  auto findStrLen = findStr.length();

  while((startPos = input.find(findStr)) != std::string::npos)
    input.replace(startPos, findStrLen, replaceStr);
}


int main()
{
  std::string line;
  while (std::getline(std::cin, line))
  {
    std::cout << "input: " << line << "\n";

    if (auto inputNumeric = TryStrToInt(line); inputNumeric != std::nullopt)
    {
      std::string roman(*inputNumeric, 'I');

      ReplaceAll(roman, "IIIII", "V");
      ReplaceAll(roman, "IIII", "IV");
      ReplaceAll(roman, "VV", "X");
      ReplaceAll(roman, "VIV", "IX");
      ReplaceAll(roman, "XXXXX", "L");
      ReplaceAll(roman, "XXXX", "XL");
      ReplaceAll(roman, "LL", "C");
      ReplaceAll(roman, "LXL", "XC");
      ReplaceAll(roman, "CCCCC", "D");
      ReplaceAll(roman, "CCCC", "CD");
      ReplaceAll(roman, "DD", "M");
      ReplaceAll(roman, "DCD", "CM");

      std::cout << roman << "\n";
    }
  }
  return 0;
}