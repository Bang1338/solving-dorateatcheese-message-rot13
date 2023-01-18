#include<iostream>
#include<string>
using namespace std;
int main()
{
    /*
    Dorateatcheese message solver
    This one is using ROT13.
    */
    string s;
    int offset;
    cout<<"Enter the encoded message: ";
    getline(cin>>ws,s);
    cout<<"Enter offset: ";
    cin>>offset;
    cout<<"Decoded message: ";
    for(int i=0; i<=s.size(); i++){
        if(s[i] >= 'a' && s[i] <='z'){
            if(s[i] + offset >= 'a' && s[i] + offset <='z')
                cout<<char(s[i] + offset);
            else if (s[i] - offset >= 'a' && s[i] - offset <='z')
                cout<<char(s[i] - offset);
        }
        else if (s[i] >= 'A' && s[i] <='Z'){
            if(s[i] + offset >= 'A' && s[i] + offset <='Z')
                cout<<char(s[i] + offset);
            else if (s[i] - offset >= 'A' && s[i] - offset <='Z')
                cout<<char(s[i] - offset);
        }
        else if (s[i] == ' ') cout<<" ";
        else cout<<s[i];
    }
}
