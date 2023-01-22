#include <iostream>
#include <string>
using namespace std;
void subseq(string s, int index, string ans)
{
    if (index == s.length())
    {
        cout << ans << "  ";
        return;
    }
    subseq(s, index + 1, ans + s[index]);
    subseq(s, index + 1, ans);
}

int main()
{
    string s1 = "abc";
    subseq(s1, 0, "");
    return 0;
}