#include <cstddef>
#include <string>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (p.empty())
        {
            return s.empty();
        }
        bool areFirstCharsMatching =
            !s.empty() && (p[0] == '.' || p[0] == s[0]);
        if (p.size() > 1 && p[1] == '*')
        {
            return (areFirstCharsMatching && isMatch(s.substr(1), p)) ||
                   isMatch(s, p.substr(2));
        }
        return areFirstCharsMatching && isMatch(s.substr(1), p.substr(1));
    }
};