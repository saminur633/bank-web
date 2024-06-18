#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int password = 2048;
char w, spt;
int plen, key, ascii;
int count = 0;

int ran_key();
int key_pin();
void encryption_decryption();
void encryption();
void decryption();

int ran_key() {
time_t seconds;
seconds = time(NULL);
long long second = seconds;
key = 2 + (second % 22);
return key;
}

int key_pin() {
int pinmach;
tryagain:
if (count > 0) {
printf("\nYou entered the wrong password %d time/s. You can try %d more time/s.\n\n", count, 3 - count);
}
printf("Please Enter your Pin to know your Encryption key: ");
scanf("%d", &pinmach);
if (password == pinmach) {
printf("Password Matched successfully..\n\n");
printf("Your automatic key is %d", key);
count = 0;
} else {
printf("Password Not Matched..\n\a");
count++;
if (count >= 3) {
printf("\n\nSorry, You have exceeded the maximum attempts. The program will exit for security reasons.\n\n");
printf("\n\n\t\t\t\tThe program ends here...");
exit(0);
}
printf("If you want to re-enter your password press a key.\n");
getch();
system("CLS");
goto tryagain;
}
}

void encryption_decryption() {
char enorde;
system("CLS");
printf("\t\t\t-------------------------------------------------\n");
printf("\t\t\t|\tWelcome to Encryption Decryption. \t|\n");
printf("\t\t\t-------------------------------------------------\n\n\n");
printf("Please enter 'E' for Encryption or 'D' for Decryption: ");
scanf(" %c", &enorde);

arduino
Copy code
if (enorde == 'e' || enorde == 'E') {
    encryption();
} else if (enorde == 'd' || enorde == 'D') {
    decryption();
} else {
    printf("\nYou chose the wrong value.\n");
}

printf("\n\nDo you want to Encrypt or Decrypt again?\n");
printf("If you want to Encrypt or Decrypt again press 'Y'. If not, press 'N': ");
scanf(" %c", &w);
if ((w == 'y' || w == 'Y') || (w == 'n' || w == 'N')) {
    printf("");
} else {
    printf("You pressed a wrong key. Note: If you press the wrong key again, the program will exit....\n");
    printf("\nPlease enter a valid (Y/N) key: ");
    scanf(" %c", &w);
    if ((w == 'y' || w == 'Y') || (w == 'n' || w == 'N')) {
        printf("");
    } else {
        printf("\nSorry, you pressed a wrong key again..\n\a");
    }
}
if (w == 'n' || w == 'N') {
    exit(0);
}
if (w == 'y' || w == 'Y') {
    encryption_decryption();
}
}

void encryption() {
char plaintext[500];
printf("\nPlease enter the Plain text: ");
fflush(stdin);
gets(plaintext);
plen = strlen(plaintext);
ran_key();
printf("\nThe cipher text is: ");
for (int i = 0; i < plen; i++) {
ascii = plaintext[i];
if (ascii == 32) {
printf("%c", ascii);
} else if (ascii >= 65 && ascii <= 90) {
int temp = ascii - 65;
temp = (temp + key) % 26;
temp = temp + 65;
printf("%c", temp);
} else if (ascii >= 97 && ascii <= 122) {
int temp = ascii - 97;
temp = (temp + key) % 26;
temp = temp + 97;
printf("%c", temp);
} else if ((ascii >= 48 && ascii <= 58) || (ascii >= 33 && ascii <= 48) || (ascii >= 58 && ascii <= 65) || (ascii == 92) || (ascii == 94) || (ascii == 95)) {
int temp = ascii;
printf("%c", temp);
}
}
printf("\n\n");
key_pin();
}

void decryption() {
char ciphertext[500];
printf("\nPlease enter the Cipher text: ");
fflush(stdin);
gets(ciphertext);
plen = strlen(ciphertext);
printf("\nPlease enter the Key: ");
scanf(" %d", &key);
printf("\nThe decrypted text is: ");
for (int i = 0; i < plen; i++) {
ascii = ciphertext[i];
if (ascii == 32) {
printf("%c", ascii);
} else if (ascii >= 65 && ascii <= 90) {
int temp = ascii - 65;
temp = (temp - key) % 26;
if (temp < 0) {
temp += 26;
}
temp = temp + 65;
printf("%c", temp);
} else if (ascii >= 97 && ascii <= 122) {
int temp = ascii - 97;
temp = (temp - key) % 26;
if (temp < 0) {
temp += 26;
}
temp = temp + 97;
printf("%c", temp);
} else if ((ascii >= 48 && ascii <= 58) || (ascii >= 33 && ascii <= 48) || (ascii >= 58 && ascii <= 65) || (ascii == 92) || (ascii == 94) || (ascii == 95)) {
int temp = ascii;
printf("%c", temp);
}
}
}

int main() {
encryption_decryption();
system("CLS");
printf("\n\n\t\t\t\tThe program ends here...");
printf("\n\n\t\t-------------------------------------------------\n\n");
getch();
getch();
getch();
return 0;
}