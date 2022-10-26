#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string key;
    do{
 key = get_string("Enter your 26 digit key ");}
while (strlen(key)<26 && strlen(key)>27);

string plain = get_string("Plaintext: ");
printf("Ciphertext: ");
for (int i = 0, len = strlen(plain); i < len; i++){

//the VALUE of the letters in plain need to be subtracted, then that number = the SPOT on key,
//and that letter becomes the new letter in the PLAIN SPOT, the CYPHER
        if (islower(plain[i]))
        {
        char cipher = key[plain[i] - 'a'];
        //gives you the spots in key, like VKXXN
        printf ("%c", cipher);}

}
printf("\n");

}