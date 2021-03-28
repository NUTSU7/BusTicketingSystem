#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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

char fs[80];
const char login[] = "user", pass[] = "pass";
char login_input[] = "user", pass_input[] = "pass";
char list[30][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty", "Empty "};
int fs1;
int i;
int dec;
char seat[80];
int seat1;
char seat2[30][80];
char name[200]; /*dunno know, trying to make it split */
char name1[30][10];
int tcount;
char s='1', v= '1';
int a=0, b=0;
int j=0, k=0;
int m=0, n=0;

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
        BusSeats();
        break;

        case 2:
         fp = fopen("seats2.txt","r+");
         fgets(seat,80,fp);
         fclose(fp);
         fp2 = fopen("name2.txt","r+");
         fgets(name,200,fp2);
         fclose(fp2);
         BusSeats();
         break;

        case 3:
         fp = fopen("seats3.txt","r+");
         fgets(seat,80,fp);
         fclose(fp);
         fp2 = fopen("name3.txt","r+");
         fgets(name,200,fp2);
         fclose(fp2);
         BusSeats();
         break;

        case 4:
         fp = fopen("seats4.txt","r+");
         fgets(seat,80,fp);
         fclose(fp);
         fp2 = fopen("name4.txt","r+");
         fgets(name,200,fp2);
         fclose(fp2);
         BusSeats();
         break;

        case 5:
         fp = fopen("seats5.txt","r+");
         fgets(seat,80,fp);
         fclose(fp);
         fp2 = fopen("name5.txt","r+");
         fgets(name,200,fp2);
         fclose(fp2);
         BusSeats();
         break;
        }
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
    seat1 = atoi(seat);
    for(i=1; i<=30; i++){
        if(i == seat1){
            printf(" %s.%s\t", seat, name);
            continue;
        }
        else
            printf(" %d.%s\t", i, list[i-1]); /* to start the array from */
}
    printf("\n\n\nAvailable Seats:%d\n",fs1);
}

void Book()
{
    BusFile();
}

void Register()
{
    FILE *fp, *fopen();
    fp = fopen("seats1.txt","w+");
    fgets(fs,80,fp);
    fclose(fp);
    BusSeats();
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
