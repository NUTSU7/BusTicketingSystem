#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Functions
void BusList();
void BusFile();
void CancelT();
void BusStatus();
void BusSeats();
void List();
void Book();
void Register();
void nameT();
void LogIn();
void SplitNames();

// Variables
const char login[] = "user", pass[] = "pass"; // login verifier
char login_input[] = "user", pass_input[] = "pass"; // pass
char list[32][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty", "Empty "};
int dec; // decisions
char seat[200]; // seat string taken from file
char seat2[30][80]; // seat string after being splitted
char name[200]; // name string taken from file
char nameSplit[32][10]; // name string splitted into array elements so u can print it
int cnt=0; // used for spliting the strings
int j=0;
int i;
int countNames=0;

int main()
{
  LogIn();
}

void List()
{
    printf("Bus Ticket System\n\n1. Bus List\n2. Book Tickets\n3. Cancel a Booked Ticket\n4. Bus Status\n5. Exit\n");
    printf("\nEnter your choice:");
    scanf("%d", &dec);
    printf("\n\n");

    switch(dec) {

        case 1:
         BusList();
         break;

        case 2:
         Book();
         break;

        case 3:
         CancelT();
         break;


        case 4:
         BusStatus();
         break;


        case 5:
         exit;
         printf("\n\n");
         break;
    }
}


void BusList()
{
    printf("\n\n1. Cardiff Express\n2. Delfast Express\n3. Derby Express\n4. Chester Expres\n5. Newport Express\n\n\n");
    printf("Going back in 2s\n");
    sleep(1);
    printf("Going back in 1s\n");
    sleep(1);
    printf("\n\n");
    List();

}

void BusFile()
{
    FILE *fp, *fopen();
    FILE *fp2, *fopen();

    printf("1. Cardiff Express\n2. Delfast Express\n3. Derby Express\n4. Chester Expres\n5. Newport Express\n\n\n");
    printf("Enter your choice: ");
    scanf("%d", &dec);
    printf("\n\n");

    switch (dec) {

        case 1:
        fp = fopen("seats1.txt","r+");
        fgets(seat,80,fp);
        fclose(fp);
        fp2 = fopen("name1.txt","r+");
        fgets(name,200,fp2);
        fclose(fp2);
        SplitNames();
        BusSeats();
        break;

        case 2:
         fp = fopen("seats2.txt","r+");
         fgets(seat,80,fp);
         fclose(fp);
         fp2 = fopen("name2.txt","r+");
         fgets(name,200,fp2);
         fclose(fp2);
         SplitNames();
         BusSeats();
         break;

        case 3:
         fp = fopen("seats3.txt","r+");
         fgets(seat,80,fp);
         fclose(fp);
         fp2 = fopen("name3.txt","r+");
         fgets(name,200,fp2);
         fclose(fp2);
         SplitNames();
         BusSeats();
         break;

        case 4:
         fp = fopen("seats4.txt","r+");
         fgets(seat,80,fp);
         fclose(fp);
         fp2 = fopen("name4.txt","r+");
         fgets(name,200,fp2);
         fclose(fp2);
         SplitNames();
         BusSeats();
         break;

        case 5:
         fp = fopen("seats5.txt","r+");
         fgets(seat,80,fp);
         fclose(fp);
         fp2 = fopen("name5.txt","r+");
         fgets(name,200,fp2);
         fclose(fp2);
         SplitNames();
         BusSeats();
         break;
        }
}

void SplitNames()
{
  for(i=0;i<=(strlen(name));i++)
      {
          // if space or NULL found, assign NULL into splitStrings[cnt]
          if(name[i]==' '||name[i]=='\0')
          {
              nameSplit[cnt][j]='\0';
              cnt++;  //for next word
              j=0;    //for next word, init index to 0
          }
          else
          {
              nameSplit[cnt][j]=name[i];
              j++;
              countNames++;
          }
      }

//      for(int i=0; i<cntName; i++)
//      {
//        printf("%d.%s\t", i+1, name1[i]);
//      }
}

void nameT()
{

}

void CancelT()
{
    printf("Under Construction\n");
}

void BusStatus()
{
    BusFile();
    printf("\n\nGoing back in 5s\n");
    sleep(2);
    printf("Going back in 3s\n");
    sleep(1);
    printf("Going back in 2s\n");
    sleep(1);
    printf("Going back in 1s\n");
    sleep(1);
    printf("\n\n");
    List();
}

void BusSeats()
{
  int z=0;
    for(i=1; i<=32; i++){
      if(i % 4 == 0){
        printf("%d.%s\n", i, list[i-1]);
      }
        else if(i<3){ //its i<3 cuz i just want to test if it can print right, there should be countNames so it will know how many times to print names
            printf("%d.%s\t", i, nameSplit[i-1]);
        }
        else
            printf("%d.%s\t", i, list[i-1]); /* idk */

}
    printf("\n\n\nAvailable Seats:%d\n",30-j);
}

void Book()
{
    BusFile();
}

void Register()
{

}
void LogIn() {
  printf("Username:\n");
  scanf("%s", login_input);

  if (strcmp(login_input,login) == 0){
      printf("Pass:\n");
      scanf("%s", pass_input);

      if(strcmp(pass_input,pass) == 0){
          printf("Ok, now you have acces to the system, enjoy!\n\n\n");
          printf("Welcome to the Bus Ticket System, chose the options from below:\n\n");
          List();
      }

      else
          printf("Incorrect Pass\n");
  }
  else
      printf("Seems like you dont have acces\n");
}
