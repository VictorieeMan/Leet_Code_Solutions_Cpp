//Created: 2023-07-02 by VictorieeMan
/* https://leetcode.com/problems/valid-parentheses/
Runtime 0 ms
Beats
100%

Memory 6.4 MB
Beats
38.89%

Changing map to unordered_map decreased time from 4ms to 0ms.
Memory also increased, but that's probably random fluctuation;
since the unordered_map actually needs less memory.

Here are the stats for the map run:
Runtime 4 ms, Beats 40.24%
Memory 6.2 MB Beats 78.79%
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        //Return True by default for valid string,
        //return false if string fails any checks

        //Quick check for odd length => invalid string
        if(s.length() % 2 == 1){
            //=> unmatched pairs
            return false;
        }

        //Using map to create quick and easy to read pairing check.
        unordered_map<char,char> parMap;
        parMap[')'] = '(';
        parMap[']'] = '[';
        parMap['}'] = '{';

        //Iterating through the string and...
        stack<char> char_stack;
        for (char& symb : s) {
            //...bounce all chars against the char_stack
            if(symb == '(' || symb == '[' || symb == '{'){
                //If opening type
                char_stack.push(symb);
            } else if(symb == ')' || symb == ']' || symb == '}'){
                //if closing type
                if(char_stack.empty()){
                    //If stack is empty on a new found closing parenthasis,
                    //then the string is invalid.
                    return false;
                } else{
                    char top_stack = char_stack.top();
                    char_stack.pop();

                    if(top_stack != parMap[symb]){
                        //If symb doesn't pair with top stack our string is invalid
                        return false;
                    }
                }
            }
        }

        if(char_stack.empty()){
            //The above process is supposed to empty valid the stacks when done.
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution sol;
    string s = "()[]{}";
    // s = "([)]";
    s = "((";
    cout << sol.isValid(s) << endl;
    return 0;
}