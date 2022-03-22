#include <iostream>
using namespace std;
string message;
string key;
void upperandmapping();
void cipher(string the_msg, string mapped);
void decipher(string text,string dec_key);
int main()
{
    // let the user choose from the menu
    
    int choice ;
    cout<<"Ahlan ya user ya habibi.\nWhat do you like to do today?\n1- Cipher a message\n2- Decipher a message\n3- Exit\n";
    cin>> choice;
    cin.ignore();
    if (choice==1)
    {
        upperandmapping();
        cipher(message,key);
    }
    else if(choice==2)
    {
        upperandmapping();
        decipher(message,key);
    }
    else if (choice==3)
    {
        cout<<"Salam, ya user ya habibi.";
    }
    else
    {
        cout<<"Wrong choice";
    }
}


// this function get msg (the msg the user want to encrypt) and k (the key for encryption)
// conver msg and k to upper case letters and check if there range are suitable 
// then mapping the key by rewrite it over and over till it became equal in length with the msg
// to global variables called message , key will be equal the upper case msg and mapping key will to use them at other functions 


void upperandmapping()
{
    string msg ;
    cout<<"Enter the message, The message should be restricted to 80 characters : ";
    getline(cin,msg);
    if(msg.length()<=80)
    {
        for(int i=0;i<msg.length();i++)
        {
            msg[i]=toupper(msg[i]);
        }
    }
    else
    {
        cout<<"The input message should be restricted to 80 characters,\n";
    }
    string k;
    cout<<"Enter the key, The key should be restricted to 8 characters : ";
    getline(cin,k);
    if(k.length()<=8)
    {
        for (int i=0;i<k.length();i++)
        {
            k[i]=toupper(k[i]);
        }
    }
    else
    {
        cout<<"The keyword should be restricted to 8 characters \n";
    }
    string map="";
    int j=0;
    for(int i=0;i<msg.length();i++)
    {
        if (j<k.length())
        {
            map += k[j];
        j++;
        }
        else 
        {
            j=0;
            map += k[j];
            j++;
        }
    }
    if(msg.length()<=80 && k.length()<=8)
    {
        cout<< msg <<'\n'<<map<<'\n';
        message=msg;
        key=map;
    }
}

// the cipher function check every letter in the message by for loop of message's length
// chech if there any spaces or number and write it at its place with no change
// then apply the steps to encode the message and print the encrypted message

void cipher(string the_msg,string mapped)
{
    string encrypted = "";
    for (int i=0;i<the_msg.length();i++)
    {
        if(the_msg[i]==32)
        {
            encrypted +=" ";
        }
        else if(isdigit(the_msg[i]))
        {
            encrypted+= the_msg[i];
        }
        else 
        {
            encrypted += char(((the_msg[i]+mapped[i])%26)+65);
        }
    }
        cout<<encrypted<<"\n";
}


// this fucntion check check every letter in the message by for loop of message's length
// chech if there any spaces or number and write it at its place with no change
// then apply the steps to decode the message and print the decrypted message

void decipher(string text,string dec_key)
{
    string decrypted = "";
    for (int i=0;i<text.length();i++)
    {
        if(text[i]==32)
        {
            decrypted +=" ";
        }
        else if(isdigit(text[i]))
        {
            decrypted+= text[i];
        }
        else 
        {
                decrypted += char(((text[i]-dec_key[i]+26)%26)+65);
        }
    }
        cout<<decrypted<<"\n";
}
