#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//structure of the password
struct password {
char site[80];
char pass[50];
int passlen;
char key[50];
};

//functions that are used for the program (except main)
void check();
void menu();
void encrypt(char *password,char *key, int length);
void decrypt();
void sett(char *site,char *password,char *key, int length);


//Ceasar Cipher which encrypts string by selected number of shifts
void ceasar(char arr[], int move){
     int i = 0;
    char a;

    while (arr[i] != '\0') {
        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            arr[i] += move;
        }
        
        i++;
    }
    printf("%s\n", arr);
}

//XOR encryption by key, xor every character of the password with each character of the key
void encrypt(char *password,char *key, int length){

  int i=0;

  for(i = 0; i < length; i++) {
        password[i] = password[i] ^ key[i % (strlen(password)/strlen(key))];

    }

}

//decryption of xor encrypted password, outcome is printed in the console
void decrypt(){

  char dec[50];
  char sos[50];

  printf("Insert encrypted password:");
  scanf("%s",dec);

  printf("Insert key:");
  scanf("%s",sos);

  encrypt(dec,sos,strlen(dec));

  printf("Your original password is %s",dec);
}

//This function stores and encrypts the password and the key
void sett(char *site,char *password,char *key, int length){



  printf("For what site would you like to save password?\n");
  scanf("%s",site);


  printf("Input password:\n");
  scanf("%s",password);

  printf("Your password is: %s\n",password);

  length = strlen(password);
  
  
  printf("Input key:\n");
  scanf("%s",key);

  printf("Your key is: %s\n",key);
  unsigned short size1 = strlen(key);
  



  encrypt(password,key,length);


  printf("Password was saved!\n"); //print this to check if function works

}

//This function prints selected encrypted passwords in the file. It asks how many passwords should be stored and how many of them are supposed to be printed. It searches the files by their sites.
void add(){


struct password a;
struct password b;
struct password c;
struct password d;
struct password e;


char lul[50];
int i;
int decision;
int x,y,z,v,u;
int j;

unsigned short size1 = strlen(a.pass);
unsigned short size2 = strlen(b.pass);
unsigned short size3 = strlen(c.pass);
unsigned short size4 = strlen(d.pass);
unsigned short size5 = strlen(e.pass);

  FILE* file;
  file = fopen("file.bin", "wb");


  printf("How many passwords would you like to store(1-5)?\n");
  scanf("%d",&decision);

  if(decision ==1){
    

    sett(a.site,a.pass,a.key,a.passlen);

    printf("which of these passwords would u like to store in the file, input the address:\n");
    scanf("%s",lul);

    x = strcmp(lul,a.site);

    if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 

      printf("Thank you for using this program, have a nice day!\n\n");
    }
    else{
      printf("Error!!!!!!!!");
    }

  }
  else if(decision ==2){

    sett(a.site,a.pass,a.key,a.passlen);
    sett(b.site,b.pass,b.key,b.passlen);


 printf("how many passwords would you like to input in the file:\n");
 scanf("%d",&j);


if(j==1){
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);

  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
    fwrite(b.pass, sizeof(char), strlen(b.pass), file);
    fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");
}
}
else if(j==2){
  fwrite(a.pass, sizeof(char), strlen(a.pass), file);
  fwrite("\n", sizeof(char), 1, file);
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else{
  printf("Error!!!!!!!!");
}


  }
  else if(decision ==3){

    sett(a.site,a.pass,a.key,a.passlen);
    sett(b.site,b.pass,b.key,b.passlen);
    sett(c.site,c.pass,c.key,c.passlen);

  printf("how many passwords would you like to input in the file:\n");
  scanf("%d",&j);


if(j==1){
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);

  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if (y==0){
      fwrite(b.pass, sizeof(char), strlen(b.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");
}
else if(z==0){
     fwrite(c.pass, sizeof(char), strlen(c.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");
}
}
else if(j==2){
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);


  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
  
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);


  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}

}
else if(j==3){
  fwrite(a.pass, sizeof(char), strlen(a.pass), file);
  fwrite("\n", sizeof(char), 1, file);
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else{
  printf("Error!!!!!!!!");
}

  }
  else if(decision ==4){

    sett(a.site,a.pass,a.key,a.passlen);
    sett(b.site,b.pass,b.key,b.passlen);
    sett(c.site,c.pass,c.key,c.passlen);
    sett(d.site,d.pass,d.key,d.passlen);


  printf("how many passwords would you like to input in the file:\n");
  scanf("%d",&j);

if(j==1){  
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);

  if(strcmp(lul,a.site)==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if (strcmp(lul,b.site)==0){
      fwrite(b.pass, sizeof(char), strlen(b.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");
}
else if(strcmp(lul,c.site)==0){
     fwrite(c.pass, sizeof(char), strlen(c.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");
}
else if(strcmp(lul,d.site)==0){
     fwrite(d.pass, sizeof(char), strlen(d.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");
}
}

else if(j==2){
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);
  v = strcmp(lul,d.site);


  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(v==0){
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
  
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);


  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(v==0){
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}

}

else if(j==3){

  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);
  v = strcmp(lul,d.site);


  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(v==0){
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
  
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);
  v = strcmp(lul,d.site);


  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(v==0){
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);
  v = strcmp(lul,d.site);


  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(v==0){
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}

}
else if (j==4){
    fwrite(a.pass, sizeof(char), strlen(a.pass), file);
  fwrite("\n", sizeof(char), 1, file);
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else{
  printf("Error!!!!!!!!");
}
}

  else if(decision ==5){


    sett(a.site,a.pass,a.key,a.passlen);
    sett(b.site,b.pass,b.key,b.passlen);
    sett(c.site,c.pass,c.key,c.passlen);
    sett(d.site,d.pass,d.key,d.passlen);
    sett(e.site,e.pass,e.key,e.passlen);

  printf("how many passwords would you like to input in the file:\n");
  scanf("%d",&j);

  if(j==1){

printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);

  if(strcmp(lul,a.site)==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if (strcmp(lul,b.site)==0){
      fwrite(b.pass, sizeof(char), strlen(b.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");
}
else if(strcmp(lul,c.site)==0){
     fwrite(c.pass, sizeof(char), strlen(c.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");
}
else if(strcmp(lul,d.site)==0){
     fwrite(d.pass, sizeof(char), strlen(d.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");
}
else if(strcmp(lul,e.site)==0){
     fwrite(e.pass, sizeof(char), strlen(e.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");
}
}
else if(j==2){


  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);
  v = strcmp(lul,d.site);
  u = strcmp(lul,e.site);


  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(v==0){
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(u==0){
  fwrite(e.pass, sizeof(char), strlen(e.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
  
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);
  v = strcmp(lul,d.site);
  u = strcmp(lul,e.site);

  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(v==0){
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(u==0){
  fwrite(e.pass, sizeof(char), strlen(e.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}

}
else if(j==3){

  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);
  v = strcmp(lul,d.site);
  u = strcmp(lul,e.site);


  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(v==0){
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(u==0){
  fwrite(e.pass, sizeof(char), strlen(e.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
  
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);
  v = strcmp(lul,d.site);
  u = strcmp(lul,e.site);

  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(v==0){
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(u==0){
  fwrite(e.pass, sizeof(char), strlen(e.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);
  v = strcmp(lul,d.site);
  u = strcmp(lul,e.site);

  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(v==0){
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(u==0){
  fwrite(e.pass, sizeof(char), strlen(e.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
}

else if(j==4){

  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);
  v = strcmp(lul,d.site);
  u = strcmp(lul,e.site);


  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(v==0){
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(u==0){
  fwrite(e.pass, sizeof(char), strlen(e.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
  
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);
  v = strcmp(lul,d.site);
  u = strcmp(lul,e.site);

  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(v==0){
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(u==0){
  fwrite(e.pass, sizeof(char), strlen(e.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);
  v = strcmp(lul,d.site);
  u = strcmp(lul,e.site);

  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(v==0){
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(u==0){
  fwrite(e.pass, sizeof(char), strlen(e.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
  printf("which of these passwords would u like to store in the file, input the address:\n");
  scanf("%s",lul);

  x = strcmp(lul,a.site);
  y = strcmp(lul,b.site);
  z = strcmp(lul,c.site);
  v = strcmp(lul,d.site);
  u = strcmp(lul,e.site);

  if(x==0){


      fwrite(a.pass, sizeof(char), strlen(a.pass), file);
      fwrite("\n", sizeof(char), 1, file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else if(y==0){
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(z==0){
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(v==0){
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
else if(u==0){
  fwrite(e.pass, sizeof(char), strlen(e.pass), file);
  fwrite("\n", sizeof(char), 1, file);
 
  printf("Thank you for using this program, have a nice day!\n\n");

}
}

else if (j==5){
  fwrite(a.pass, sizeof(char), strlen(a.pass), file);
  fwrite("\n", sizeof(char), 1, file);
  fwrite(b.pass, sizeof(char), strlen(b.pass), file);
  fwrite("\n", sizeof(char), 1, file);
  fwrite(c.pass, sizeof(char), strlen(c.pass), file);
  fwrite("\n", sizeof(char), 1, file);
  fwrite(d.pass, sizeof(char), strlen(d.pass), file);
  fwrite("\n", sizeof(char), 1, file);
  fwrite(e.pass, sizeof(char), strlen(e.pass), file);
 
    printf("Thank you for using this program, have a nice day!\n\n");

}
else{
  printf("Error!!!!!!!!");
}


  }


  
  fclose(file);
  
}


// This function askes user for string and number of shifts for Ceasar Cipher. After encryption it prints outcome to the file
void check(){
    char arr[99];
    int move;
    int i = 0;
  FILE* file;

  file = fopen("file.bin", "wb");



    printf("Enter the text, please: ");
    scanf("%s",arr);

    printf("On how many latters would you like to move?: ");
    scanf("%d", &move);

    for (i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            arr[i] = arr[i] - 32;
        }
    }

    ceasar(arr,move);

    fwrite(arr, sizeof(char), strlen(arr), file);

    printf("Check file to see your encrypted password!\n");
    printf("Thank you for using our program!!! Have a nice day!!!");

fclose(file);
}

//main menu where all the choices can be made.
void menu(){

int choise;
struct password a;
char key[50];
char result[50];
FILE* file;

  file = fopen("file.bin", "wb");


  printf("\n\n Welcome to password decryption!\n\n");
  printf("Use our program and make hackers go (╯°□°)╯︵ ┻━┻\n\n");
  printf("Press 1 to store a password\nPress 2 to make a Ceasar Cipher encryption\nPress 3 to decrypt your password\nPress 4 to exit\n");
  printf("Your input:");
  scanf("%d",&choise);

  if(choise ==1){
    add();
  
  }
  else if(choise ==2){

    check();

  }
  else if(choise ==3){

    decrypt();
  }
  else if(choise ==4){
    printf("Thank you for using our program!!! Have a nice day!!!");
  }
  else{
    printf("Error,try again\n");
    menu();
  }

}

// main function which calls menu.
int main(void) {
 
  menu();  


  return 0;


}
