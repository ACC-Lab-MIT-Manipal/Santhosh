#include<stdio.h>

int main()
{
    char msg[100], ch;
    int i, key;
    printf("Enter a message to decrypt: ");
    gets(msg);
    printf("Enter key: ");
    scanf("%d", &key);
    for(i = 0; msg[i] != '\0'; ++i)
    {
        ch = msg[i];
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;
            if(ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;
            if(ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }
            msg[i] = ch;
        }
    }
printf("Decrypted message: %s", msg);
return 0;
}
