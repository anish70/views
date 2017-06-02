#include <string>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
bool check_palindrome(const char *s)
{
	int i = 0;
	int j = strlen(s);

	while (i != j) {
        	if (!isalpha(s[i])) {
			++i;
			continue;
		}

        	if (!isalpha(s[j])) {
			j--;
			continue;
		}

                if (toupper(s[i]) != toupper(s[j])) {
                	return false;
                }
		++i; --j;
        }

        return true;
}
 
int
main(int argc, char *argv[])
{
	std::string s = "A man, a plan, a canal, Panama!";
	printf("Initial %s\n", s.c_str());
	bool b = check_palindrome(s.c_str());
	printf("Result = %d\n", b);
}
