#include <stdio.h>
#include <string.h>

void decrypt( const char* key)
{
    char v3[22] = { 6, 17, 29, 114, 96, 31, 24, 124, 62, 15, 109, 120, 51, 53, 64, 94, 62, 37, 95, 48, 120, 20 };

    for (int i = 0; i <= 23; ++i)
    {
       

        char decrypted_char =   v3[i] ^ key[i];

        printf("%c", decrypted_char);
    }
    printf("\n");
}

int main()
{
    const char* key = "GRX14YcKLzXOlW5iaSlBIrN7"; // Khóa mã hóa

    decrypt( key);

    return 0;
}
// --> may be ACECTF{7ru57_bu7_v3r1fé√ ---> ACECTF{7ru57_bu7_v3r1fy}