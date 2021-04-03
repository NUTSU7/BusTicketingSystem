#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Functions
// TODO: make function names more descriptive
void bus_list();
void book_ticket();
void cancel_ticket();
void bus_status();
void bus_file_read();
void bus_file_write();
void split_names();
void bus_seats();
int list_bus();
void list_bus_wrapper(int choice);
void _register();
void log_in();

// Variables
const char login[] = "user", pass[] = "pass"; // login verifier
char login_input[] = "user", pass_input[] = "pass"; // pass
char list[32][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty", "Empty "};
int dec; // decisions
char name[200]; // name string taken from file
char name_split[32][10]; // name string splitted into array elements so u can print it
int cnt; // used for spliting the strings
int j;
int i;
int count_names=0;
int num_tickets;
char res_name[100];

int main()
{
  log_in();
}

int list_bus()
{
	int choice = 0;
    printf("Bus Ticket System\n\n1. Bus List\n2. Book Tickets\n3. Cancel a Booked Ticket\n4. Bus Status\n5. Exit\n");
    printf("\nEnter your choice:");
    scanf("%d", &choice);
    printf("\n\n");

	return choice;
}


void list_bus_wrapper(int choice)
{
	switch(choice) {
		case 1:
			bus_list();
			break;
			
		case 2:
			book_ticket();
			break;
			
		case 3:
			cancel_ticket();
			break;
			
			
		case 4:
			bus_status();
			break;
			
			
		case 5:
			exit;
			printf("\n\n");
			break;
	}
}


void bus_list()
{
    printf("\n\n1. Cardiff Express\n2. Delfast Express\n3. Derby Express\n4. Chester Expres\n5. Newport Express\n\n\n");
    printf("Going back in 2s\n");
    sleep(1);
    printf("Going back in 1s\n");
    sleep(1);
    printf("\n\n");
    list_bus_wrapper(list_bus());

}

void book_ticket()
{
    bus_file_read();
    split_names();
    bus_seats();
    _register();
//    bus_list();
}

void cancel_ticket()
{
    printf("Under Construction\n");
}

void bus_status()
{
    bus_file_read();
    split_names();
    bus_seats();
    printf("\n\nGoing back in 5s\n");
    sleep(2);
    printf("Going back in 3s\n");
    sleep(1);
    printf("Going back in 2s\n");
    sleep(1);
    printf("Going back in 1s\n");
    sleep(1);
    printf("\n\n");
    list_bus_wrapper(list_bus());
}

void bus_file_read()
{
  char name_local[200];
    FILE *fp, *fopen();

    printf("1. Cardiff Express\n2. Delfast Express\n3. Derby Express\n4. Chester Expres\n5. Newport Express\n\n\n");
    printf("Enter your choice: ");
    scanf("%d", &dec);
    printf("\n\n");

    switch (dec) {

        case 1:
        fp = fopen("name1.txt","r+");
        fgets(name_local,200,fp);
        fclose(fp);
        name=name_local;
        break;

        case 2:
         fp = fopen("name2.txt","r+");
         fgets(name_local,200,fp);
         fclose(fp);
         name=name_local;
         break;

        case 3:
         fp = fopen("name3.txt","r+");
         fgets(name_local,200,fp);
         fclose(fp);
         name=name_local;
         break;

        case 4:
         fp = fopen("name4.txt","r+");
         fgets(name_local,200,fp);
         fclose(fp);
         name=name_local;
         break;

        case 5:
         fp = fopen("name5.txt","r+");
         fgets(name_local,200,fp);
         fclose(fp);
         name=name_local;
         break;
        }
}

void split_names()
{
  cnt=0;
  countNames=0;
  j=0;
  for(i=0;i<=(strlen(name));i++)
      {
          // if space or NULL found, assign NULL into splitStrings[cnt]
          if(name[i]=='\0'||name[i]==' ')
          {
//              name_split[cnt][j]='';
              cnt++;  //for next word
              j=0;    //for next word, init index to 0
          }
          else
          {
              name_split[cnt][j]=name[i];
              j++;
          }
      }
}

void bus_seats()
{
  count_names=cnt-1;
      for(i=1; i<=32; i++){
      if(i % 4 == 0 && i<= count_names){
        printf("%d.%s\n", i, name_split[i-1]);
      }
        else if(i<cnt){
            printf("%d.%s\t", i, name_split[i-1]);
        }
        else if(i % 4 == 0 && i>count_names){
          printf("%d.%s\n", i, list[i-1]);
        }
        else{
            printf("%d.%s\t", i, list[i-1]); /* idk */
          }

}
    printf("\n\n\n\t\tAvailable Seats:%d\n",32-count_names);
}

void _register()
{
  printf("\t\tNumber of Tickets: ");
  scanf("%d", &num_tickets);
  for(i=1; i<=num_tickets; i++){
    printf("\n\t\tName for Ticket %d: ", i);
    scanf("%s", res_name);
    bus_file_write();
  }
}

void bus_file_write()
{
    FILE *fp, *fopen();
    switch (dec) {

        case 1:
        fp = fopen("name1.txt","a");
        fprintf(fp,"%s ", res_name);
        fclose(fp);
        break;

        case 2:
         fp = fopen("name2.txt","a");
         fprintf(fp,"%s ", res_name);
         fclose(fp);
         break;

        case 3:
         fp = fopen("name3.txt","a");
         fprintf(fp,"%s ", res_name);;
         fclose(fp);
         break;

        case 4:
         fp = fopen("name4.txt","a");
         fprintf(fp,"%s ", res_name);
         fclose(fp);
         break;

        case 5:
         fp = fopen("name5.txt","a");
         fprintf(fp,"%s ", res_name);
         fclose(fp);
         break;
        }
}

void log_in() {
  printf("Username:\n");
  scanf("%s", login_input);

  if (strcmp(login_input,login) == 0){
      printf("Pass:\n");
      scanf("%s", pass_input);

      if(strcmp(pass_input,pass) == 0){
          printf("Ok, now you have acces to the system, enjoy!\n\n\n");
          printf("Welcome to the Bus Ticket System, chose the options from below:\n\n");
          list_bus_wrapper(list_bus());
      }

      else
          printf("Incorrect Pass\n");
  }
  else
      printf("Seems like you dont have acces\n");
}
