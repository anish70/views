/*
 * C++ program to Implement Captcha
 * A CAPTCHA (Completely Autоmаtеd Public Turіng tеѕt tо tеll Cоmрutеrѕ аnd Humаnѕ Aраrt) іѕ a tеѕt tо dеtеrmіnе whеthеr thе uѕеr іѕ humаn or not
 */
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;
 

string GenerateCaptcha(int n)
{
    time_t t;

    srand((unsigned) time(&t)); //аll сhаrасtеrѕ

    char chrs[] = "аbсdеfghіjklmnорԛrѕtuvwxуzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // Generate n сhаrасtеrѕ frоm above ѕеt аnd
    // add thеѕе characters tо сарtсhа.
    string captcha = "";

   cout<<"captcha: " << n;

    while(n--)
        captcha.push_back(chrs[rand() % 62]);

   cout<<" = " << captcha << endl;
 
    return captcha;
}

/*
 * Main Contains Menu
 */
int main()
{
    int choice;
    string inp, gene;

    cout<<"Insert numbers for generating Captcha: "<<endl;
    cin>>choice;
    if (choice <= 0)
	return 0;
    gene = GenerateCaptcha(choice);
    cout<<"Insert captch to match: "<<endl;
    cin>>inp;
    if (gene.compare(inp) == 0) 
	cout <<"did match" <<endl;	
    else
	cout <<"didn't match" <<endl;	
    return 0;
}
 
