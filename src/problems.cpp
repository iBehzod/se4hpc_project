#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

// ############################### PROBLEM 1: Balanced Number [lvl 1] #############################################
//  A balanced number is a number where the sum of digits to the left of the middle digit(s)
//  and the sum of digits to the right of the middle digit(s) are equal.
//  If the number has an odd number of digits,
//  then there is only one middle digit. (For example, 92645 has one middle digit, 6.)
//  Otherwise, there are two middle digits. (For example, the middle digits of 1301 are 3 and 0.)
//  The middle digit(s) should not be considered when determining whether
//  a number is balanced or not, e.g. 413023 is a balanced number because the left sum and right sum are both 5.
//  Given a number, find if it is balanced, and return the string "Balanced" or "Not Balanced" accordingly.
//  The passed number will always be positive.

//  Examples
//  7 ==> return "Balanced"
//  Explanation:
//  middle digit(s): 7
//  sum of all digits to the left of the middle digit(s) -> 0
//  sum of all digits to the right of the middle digit(s) -> 0
//  0 and 0 are equal, so it's balanced.
//  295591 ==> return "Not Balanced"
//  Explanation:
//  middle digit(s): 55
//  sum of all digits to the left of the middle digit(s) -> 11
//  sum of all digits to the right of the middle digit(s) -> 10
//  11 and 10 are not equal, so it's not balanced.
//  959 ==> return "Balanced"
//  Explanation:
//  middle digit(s): 5
//  sum of all digits to the left of the middle digit(s) -> 9
//  sum of all digits to the right of the middle digit(s) -> 9
//  9 and 9 are equal, so it's balanced.
//  27102983 ==> return "Not Balanced"
//  Explanation:
//  middle digit(s): 02
//  sum of all digits to the left of the middle digit(s) -> 10
//  sum of all digits to the right of the middle digit(s) -> 20
//  10 and 20 are not equal, so it's not balanced.

std::string balancedNum(unsigned long long int number)
{
  std::string numStr = std::to_string(number);
  int numDigits = numStr.length();
  int mid = numDigits / 2;
  int leftSum = 0;
  int rightSum = 0;

  for (int i = 0; i < mid; ++i) {
    leftSum += numStr[i] - '0';
  }

  for (int i = numDigits - 1; i >= mid + (numDigits % 2); --i) {
    rightSum += numStr[i] - '0';
  }

  return (leftSum == rightSum) ? "Balanced" : "Not Balanced";
}


// std::string balancedNum(unsigned long long int number)
// {
//   // your code here
//   return "";
// }

// ********************************************************************************************************


// ############################### PROBLEM 2: Isograms [lvl 1] #############################################
// An isogram is a word that has no repeating letters, consecutive or non-consecutive. Implement a function 
//that determines whether a string that contains only letters is an isogram. Assume the empty string is an isogram. Ignore letter case.
// Example: (Input --> Output)
// "Dermatoglyphics" --> true
// "aba" --> false
// "moOse" --> false (ignore letter case)

bool is_isogram(std::string str) {
  std::unordered_set<char> seenLetters;
  for (char c : str) {
    char lowerC = std::tolower(c);
    if (seenLetters.count(lowerC) > 0) {
      return false;
    }
    seenLetters.insert(lowerC);
  }
  return true;
}


// bool is_isogram(std::string str) {
//   // your code here
//   return false;
// }

// ********************************************************************************************************

// ############################### PROBLEM 3: All or Nothing [lvl 1] #############################################
// Suppose a student can earn 100% on an exam by getting the answers all correct or all incorrect. 
// Given a potentially incomplete answer key and the student's answers, 
// write a function that determines whether or not a student can still score 100%. 
// Incomplete questions are marked with an underscore, "_".

// ["A", "_", "C", "_", "B"]   # answer key
// ["A", "D", "C", "E", "B"]   # student's solution

// ➞ True

// # Possible for student to get all questions correct.

// ["B", "_", "B"]   # answer key
// ["B", "D", "C"]   # student's solution

// ➞ False

// # First question is correct but third is wrong, so not possible to score 100%.

// ["T", "_", "F", "F", "F"]   # answer key
// ["F", "F", "T", "T", "T"]   # student's solution

// ➞ True

// # Possible for student to get all questions incorrect.

// Examples
// (["B", "A", "_", "_"], ["B", "A", "C", "C"]) ➞ True
// (["A", "B", "A", "_"], ["B", "A", "C", "C"]) ➞ True
// (["A", "B", "C", "_"], ["B", "A", "C", "C"]) ➞ False
// (["B", "_"], ["C", "A"]) ➞ True
// (["B", "A"], ["C", "A"]) ➞ False
// (["B"], ["B"]) ➞ True
// (["_"], ["B"]) ➞ True


// Notes:
// Test has at least one question.
// len(key) == len(answers)

bool possibly_perfect(const std::vector<char>& key, const std::vector<char>& answers)
{
    // your code here
    return true;
}

// ********************************************************************************************************


// ############################### PROBLEM 4: Find the odd int [lvl 2] #############################################
//  Given an array of integers, find the one that appears an odd number of times.
//  There will always be only one integer that appears an odd number of times.
//  Examples
//  [7] should return 7, because it occurs 1 time (which is odd).
//  [0] should return 0, because it occurs 1 time (which is odd).
//  [1,1,2] should return 2, because it occurs 1 time (which is odd).
//  [0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
//  [1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).

int findOdd(const std::vector<int> &numbers)
{
  int result = 0;
  for (int num : numbers) {
    result ^= num;
  }
  return result;
}

// Explanation:
// This solution utilizes the bitwise XOR operator (^) to efficiently find the odd-occurring number. Here's how it works:
// Initialization: result is initialized to 0.
// XOR Iteration: The code iterates through each number in the numbers vector. For each num:
// result ^= num performs a bitwise XOR operation between the current value of result and num.
// XOR Properties: The XOR operation has the following properties:
// a ^ a = 0 (XORing a number with itself results in 0)
// 0 ^ a = a (XORing 0 with a number results in the number itself)
// XOR is associative and commutative (order doesn't matter)
// Finding the Odd One Out: Due to these properties, as we XOR all the numbers together:
// Numbers occurring an even number of times will cancel themselves out (e.g., 2 ^ 2 ^ 2 ^ 2 = 0).
// The number occurring an odd number of times will remain in the result variable.
// Return: The final value of result will be the number that appeared an odd number of times in the input vector.

// ********************************************************************************************************



// ############################### PROBLEM 5: The Vowel Code [lvl 2] #############################################
// Step 1: Create a function called encode() to replace all the lowercase vowels in 
// a given string with numbers according to the following pattern:
// a -> 1
// e -> 2
// i -> 3
// o -> 4
// u -> 5
// For example, encode("hello") would return "h2ll4". There is no need to worry about uppercase vowels in this exercise.
// Step 2: Now create a function called decode() to turn the numbers back into vowels according to the same pattern shown above.
// For example, decode("h3 th2r2") would return "hi there".
// For the sake of simplicity, you can assume that any numbers passed into the function will correspond to vowels.

std::string encode(const std::string &str) {
  std::string result = str;
  for (int i = 0; i < result.length(); ++i) {
    switch (result[i]) {
      case 'a': result[i] = '1'; break;
      case 'e': result[i] = '2'; break;
      case 'i': result[i] = '3'; break;
      case 'o': result[i] = '4'; break;
      case 'u': result[i] = '5'; break;
    }
  }
  return result;
}

std::string decode(const std::string &str) {
  std::string result = str;
  for (int i = 0; i < result.length(); ++i) {
    switch (result[i]) {
      case '1': result[i] = 'a'; break;
      case '2': result[i] = 'e'; break;
      case '3': result[i] = 'i'; break;
      case '4': result[i] = 'o'; break;
      case '5': result[i] = 'u'; break;
    }
  }
  return result;
}

// Explanation:
// encode(const std::string &str):
// Creates an empty string result to store the encoded string.
// Iterates through each character c in the input string str.
// Uses a switch statement to check if c is a lowercase vowel:
// If it's a vowel, append the corresponding number to result.
// If it's not a vowel, append the character c itself to result.
// Returns the encoded string result.
// decode(const std::string &str):
// Works similarly to encode, but in reverse.
// Creates an empty string result to store the decoded string.
// Iterates through each character c in the input string str.
// Uses a switch statement to check if c is a vowel number ('1' to '5'):
// If it's a vowel number, append the corresponding lowercase vowel to result.
// If it's not a vowel number, append the character c itself to result.
// Returns the decoded string result.
// This approach is more memory-efficient as it avoids creating a copy of the entire input string.




// ********************************************************************************************************



// ############################### PROBLEM 6: Bananas [lvl 3] #############################################
// > "What is your name" said Tim.
// "My name" said the mouse "Is Dinglemouse".
// > "What were you before the witch turned you into a mouse" said Rose.
// "I was a banana" said Dingle the mouse, "So be careful. If you see her, run away!".
// - Badjelly the Witch (12:32), Spike Milligan

// Given a string of letters a, b, n how many different ways can you make the word "banana" 
// by crossing out various letters and then reading left-to-right?
// (Use - to indicate a crossed-out letter)

// Example:

// Input
// bbananana

// Output
// b-anana--
// b-anan--a
// b-ana--na
// b-an--ana
// b-a--nana
// b---anana
// -banana--
// -banan--a
// -bana--na
// -ban--ana
// -ba--nana
// -b--anana

// Notes
// You must return all possible bananas, but the order does not matter
// The example output above is formatted for readability. Please refer to the example tests for expected format of your result.


// std::unordered_set<std::string> bananas(const std::string& s) {
//     // your code here
//     return {};
// }

void generateBananas(const std::string &s, int idx, int depth, std::vector<int> &positions, std::unordered_set<std::string> &results) {
    static const std::string target = "banana";
    if (depth == target.size()) {
        std::string result(s.size(), '-');
        for (int i = 0; i < positions.size(); ++i) {
            result[positions[i]] = s[positions[i]];
        }
        results.insert(result);
        return;
    }
    
    for (int i = idx; i < s.size(); ++i) {
        if (s[i] == target[depth]) {
            positions[depth] = i;
            generateBananas(s, i + 1, depth + 1, positions, results);
        }
    }
}

std::unordered_set<std::string> bananas(const std::string &s) {
    std::unordered_set<std::string> results;
    std::vector<int> positions(6); // "banana" has 6 letters
    generateBananas(s, 0, 0, positions, results);
    return results;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// std::unordered_set<std::string> bananas(const std::string& s) {
//     std::unordered_set<std::string> result;
//     int n = s.length();

//     // Iterate through all possible combinations of crossed-out letters
//     for (int i = 0; i < (1 << n); ++i) {
//         std::string banana = s;
//         int countB = 0, countA = 0, countN = 0;
//         int bananaIndex = 0;

//         for (int j = 0; j < n; ++j) {
//             // If the j-th bit of i is set, cross out the j-th letter
//             if (i & (1 << j)) {
//                 banana[j] = '-';
//             } else {
//                 // Check if the uncrossed letter contributes to forming "banana"
//                 if (banana[j] == 'b' && countB < 1) {
//                     banana[bananaIndex++] = banana[j];
//                     countB++;
//                 } else if (banana[j] == 'a' && countA < 3) {
//                     banana[bananaIndex++] = banana[j];
//                     countA++;
//                 } else if (banana[j] == 'n' && countN < 2) {
//                     banana[bananaIndex++] = banana[j];
//                     countN++;
//                 } else {
//                     banana[j] = '-'; // Cross out if it doesn't contribute to "banana"
//                 }
//             }
//         }

//         // Add the formed "banana" to the result if it's valid
//         if (countB == 1 && countA == 3 && countN == 2) {
//             result.insert(banana);
//         }
//     }

//     return result;
// }




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// std::vector<std::string> bananas(std::string s) {
//   std::vector<std::string> result;
//   std::string banana = "banana";
//   int sLen = s.length();

//   for (int i = 0; i < (1 << sLen); ++i) { // Iterate through all possible combinations of crossed-out letters
//     std::string temp = s;
//     int bananaIndex = 0;
//     bool validBanana = true;

//     for (int j = 0; j < sLen; ++j) {
//       if ((i >> j) & 1) { // Check if the j-th bit in i is set (meaning the j-th letter is crossed out)
//         temp[j] = '-';
//       } else if (bananaIndex < 6 && temp[j] == banana[bananaIndex]) {
//         bananaIndex++;
//       } else {
//         validBanana = false;
//         break;
//       }
//     }

//     if (validBanana && bananaIndex == 6) {
//       result.push_back(temp);
//     }
//   }

//   return result;
// }

// ********************************************************************************************************