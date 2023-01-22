#include <iostream>
#include <string>
using namespace std;
void reverseS(string &s, int i, int j)
{
    if (j % 2 == 0)
    {
        if (i == j)
        {
            return;
        }
    }
    else if (i > j)
    {
        return;
    }
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
    reverseS(s, i + 1, j - 1);
}
void reverseS2(string &s, int index, string &ans)
{
    if (index == s.length())
    {
        return;
    }
    reverseS2(s, index + 1, ans);
    ans.push_back(s[index]);
}
int main()
{
    string s1 = "abcd";
    cout << s1 << endl;
    reverseS(s1, 0, s1.length() - 1);
    cout << s1 << endl;
    string s2 = "kjhl";
    string ans = "";
    reverseS2(s2, 0, ans);
    cout << ans;
    return 0;
}