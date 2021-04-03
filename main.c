#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Functions
void BusList();
void Book();
void CancelT();
void BusStatus();
void BusFileRead();
void BusFileWrite();
void SplitNames();
void BusSeats();
void List();
void Register();
void LogIn();

// Variables
const char login[] = "user", pass[] = "pass"; // login verifier
char login_input[] = "user", pass_input[] = "pass"; // pass
char list[32][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty", "Empty "};
int dec; // decisions
char name[200];
char nameSplit[32][10]; // name string splitted into array elements so u can print it
int cnt; // used for spliting the strings
int j;
int i;
int countNames;
int numTickets;
char resName[100];

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

void Book()
{
    BusFileRead();
    BusSeats();
    Register();
//    BusList();
}

void CancelT()
{
    printf("Under Construction\n");
}

void BusStatus()
{
    BusFileRead();
    BusSeats();
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

void BusFileRead()
{
  char nameLocal[200];
    FILE *fp, *fopen();

    printf("1. Cardiff Express\n2. Delfast Express\n3. Derby Express\n4. Chester Expres\n5. Newport Express\n\n\n");
    printf("Enter your choice: ");
    scanf("%d", &dec);
    printf("\n\n");

    switch (dec) {

        case 1:
        fp = fopen("name1.txt","r+");
        fgets(nameLocal,200,fp);
        fclose(fp);
        name=nameLocal;
        break;

        case 2:
         fp = fopen("name2.txt","r+");
         fgets(nameLocal,200,fp);
         fclose(fp);
         name=nameLocal;
         break;

        case 3:
         fp = fopen("name3.txt","r+");
         fgets(nameLocal,200,fp);
         fclose(fp);
         name=nameLocal;
         break;

        case 4:
         fp = fopen("name4.txt","r+");
         fgets(nameLocal,200,fp);
         fclose(fp);
         name=nameLocal;
         break;

        case 5:
         fp = fopen("name5.txt","r+");
         fgets(nameLocal,200,fp);
         fclose(fp);
         name=nameLocal;
         break;
        }
}

void SplitNames()
{
  cnt=0;
  countNames=0;
  j=0;
  for(i=0;i<=(strlen(name));i++)
      {
          // if space or NULL found, assign NULL into splitStrings[cnt]
          if(name[i]=='\0'||name[i]==' ')
          {
//              nameSplit[cnt][j]='';
              cnt++;  //for next word
              j=0;    //for next word, init index to 0
          }
          else
          {
              nameSplit[cnt][j]=name[i];
              j++;
          }
      }
}

void BusSeats()
{
  SplitNames();
  countNames=cnt-1;
      for(i=1; i<=32; i++){
      if(i % 4 == 0 && i<= countNames){
        printf("%d.%s\n", i, nameSplit[i-1]);
      }
        else if(i<cnt){
            printf("%d.%s\t", i, nameSplit[i-1]);
        }
        else if(i % 4 == 0 && i>countNames){
          printf("%d.%s\n", i, list[i-1]);
        }
        else{
            printf("%d.%s\t", i, list[i-1]); /* idk */
          }

}
    printf("\n\n\n\t\tAvailable Seats:%d\n",32-countNames);
}

void Register()
{
  printf("\t\tNumber of Tickets: ");
  scanf("%d", &numTickets);
  for(i=1; i<=numTickets; i++){
    printf("\n\t\tName for Ticket %d: ", i);
    scanf("%s", resName);
    BusFileWrite();
  }
}

void BusFileWrite()
{
    FILE *fp, *fopen();
    switch (dec) {

        case 1:
         fp = fopen("name1.txt","a");
         fprintf(fp,"\b%s ", resName);
         fclose(fp);
         break;

        case 2:
         fp = fopen("name2.txt","a");
         fprintf(fp,"\b%s ", resName);
         fclose(fp);
         break;

        case 3:
         fp = fopen("name3.txt","a");
         fprintf(fp,"\b%s ", resName);;
         fclose(fp);
         break;

        case 4:
         fp = fopen("name4.txt","a");
         fprintf(fp,"\b%s ", resName);
         fclose(fp);
         break;

        case 5:
         fp = fopen("name5.txt","a");
         fprintf(fp,"\b%s ", resName);
         fclose(fp);
         break;
        }
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
