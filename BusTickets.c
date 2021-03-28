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
void SplitNameNumber();

char fs[80];
const char login[] = "user", pass[] = "pass"; // login verifier
char login_input[] = "user", pass_input[] = "pass"; // pass
char list[30][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty", "Empty "};
int fs1;
int i;
int dec; // decisions
char seat[80]; // seat string taken from file
int seat1[30][80]; //seat after being trasformed into int
char seat2[30][80]; // seat string after being splitted
char name[200]; // name string taken from file
char name1[30][10]; // name string splitted into array elements so u can print it
int tcount; // forgot what this even does
int cntName=0; // used for spliting the strings
int cntNumber=0; // same as cntName

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
        SplitNameNumber();
      //  BusSeats();
        break;

        case 2:
         fp = fopen("seats2.txt","r+");
         fgets(seat,80,fp);
         fclose(fp);
         fp2 = fopen("name2.txt","r+");
         fgets(name,200,fp2);
         fclose(fp2);
         SplitNameNumber();
         BusSeats();
         break;

        case 3:
         fp = fopen("seats3.txt","r+");
         fgets(seat,80,fp);
         fclose(fp);
         fp2 = fopen("name3.txt","r+");
         fgets(name,200,fp2);
         fclose(fp2);
         SplitNameNumber();
         BusSeats();
         break;

        case 4:
         fp = fopen("seats4.txt","r+");
         fgets(seat,80,fp);
         fclose(fp);
         fp2 = fopen("name4.txt","r+");
         fgets(name,200,fp2);
         fclose(fp2);
         SplitNameNumber();
         BusSeats();
         break;

        case 5:
         fp = fopen("seats5.txt","r+");
         fgets(seat,80,fp);
         fclose(fp);
         fp2 = fopen("name5.txt","r+");
         fgets(name,200,fp2);
         fclose(fp2);
         SplitNameNumber();
         BusSeats();
         break;
        }
}

void SplitNameNumber()
{
  int j=0;
  for(int i=0;i<=(strlen(name));i++)
      {
          // if space or NULL found, assign NULL into splitStrings[cnt]
          if(name[i]==' '||name[i]=='\0')
          {
              name1[cntName][j]='\0';
              cntName++;  //for next word
              j=0;    //for next word, init index to 0
          }
          else
          {
              name1[cntName][j]=name[i];
              j++;
          }
      }

      int k=0;
      for(int i=0;i<=(strlen(seat));i++)
      {
        // if space or NULL found, assign NULL into splitStrings[cnt]
        if(seat[i]==' '||seat[i]=='\0')
        {
          seat2[cntNumber][k]='\0';
          cntNumber++;  //for next word
          k=0;    //for next word, init index to 0
        }
        else
        {
          seat2[cntNumber][k]=seat[i];
          k++;
        }
      }

  //    for(int i=0; i<sizeof(seat2); i++){
  //      seat1[i] = atoi(seat2[i]);
  //    }

      for(int i=0; i<cntNumber; i++)
      {
        printf(" %s.%s\t", seat2[i], name1[i]);
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
/*    seat1 = atoi(seat);
    for(i=1; i<=30; i++){
        if(i == seat1){
            printf(" %s.%s\t", seat, name1[i]);
            continue;
        }
        else
            printf(" %d.%s\t", i, list[i-1]); /* to start the array from */

            int num10=sizeof(name1)+1;
            for(int i=1; i<=2; i++){
                    printf(" %d.%s\t", i, name1[i-1]);
                  }

                    for(int k=i; k<=30; k++){
                    printf(" %d.%s\t", k, list[k-1]); /* to start the array from */
                  }

    printf("\n\n\nAvailable Seats:%d\n",fs1);
}

void Book()
{
    BusFile();
}

void Register()
{
  /*
    FILE *fp, *fopen();
    fp = fopen("seats1.txt","w+");
    fgets(fs,80,fp);
    fclose(fp);
    BusSeats();
    */
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
