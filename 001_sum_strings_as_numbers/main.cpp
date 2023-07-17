#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>

/**
 * [Instructions]
 * 
 * Given the string representations of two integers, return the string representation of the sum of those integers.
 * For example:
 *
 * sumStrings('1','2') // => '3'
 * A string representation of an integer will contain no characters besides the ten numerals "0" to "9".
 *
 * I have removed the use of BigInteger and BigDecimal in java
 *
 * Python: your solution need to work with huge numbers (about a milion digits), converting to int will not work.
 *
 */

std::string sum_strings(std::string a, std::string b) 
{
  std::string end_result;
  size_t a_len      = a.length();
  size_t b_len      = b.length();
  size_t max_length = std::max(a_len, b_len);

  end_result.reserve(max_length + 1);

  // Longer string (or `a` if they are equal)
  std::string& other      = (a_len < b_len) ? b : a; 
  // Pad the shorter string with 0s if needed, otherwise just take string `b`
  std::string  padded_str = 
    std::string(max_length - std::min(a_len, b_len), '0') + 
    ((a_len < b_len) ? a : b);
    

  uint8_t curr_result = 0;
  for (int32_t i = max_length - 1; i >= 0; i--)
  {
    // Convert string to digit and add them up
    uint8_t ia   = padded_str[i] - '0'; 
    uint8_t ib   = other[i]      - '0';
    curr_result += ia + ib;

    // If curr_result > 9 we will carry the 1 to the next addition
    uint8_t add = (curr_result > 9) ? curr_result - 10 : curr_result;

    // Convert to string and prepend, carry the 1 if we need to
    end_result.append(std::to_string(add));
    curr_result = (curr_result > 9) ? 1 : 0;
  }

  // If the 1 was carried in the last iteration we need to prepend it
  if (curr_result == 1)
  {
    end_result.append(std::to_string(curr_result));
  }
  std::reverse(end_result.begin(), end_result.end());
  return end_result;
}


int main()
{
  std::string end_result;
  // end_result = sum_strings("123", "456"); // 579
  // end_result = sum_strings("333", "428"); // 761
  for (int i = 0; i < 10'000'000; i++)
  {
    std::string end_result = sum_strings("524979655239307113533173297200449883502306505882499610294664056396581785130441933960454963", "20");
  }
  std::cout << end_result << "\n";
}
