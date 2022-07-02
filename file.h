struct square
{
char c;
int row;
int column;
};
int checkalp(int,char []);//check if letter already printed from key
void square(struct square* ,char* ,char,char arr[5][5]);//create the square
void splits(struct square*,char*,char arr[][5],int);//create digraphs
void encrypt(struct square*, char[2],char arr[][5]);//prints the encrypted digraphs
void decrypt(struct square*, char[2],char arr[][5]);//prints the decrypted digraphs

