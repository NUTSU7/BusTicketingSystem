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
void list_bus_wrapper();
void _register();
void log_in();
void print_bus_list();

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
int choice;
char bus_list_5[5][20] = {"Cardiff Express", "Delfast Express", "Derby Express", "Chester Express", "Newport Express"};

int main()
{
  log_in();
}

int list_bus()
{
  printf("\t\t\tBus Ticketing System\n\n");
  printf("\t\t\t1. Bus List\n\t\t\t2. Book Tickets\n\t\t\t3. Cancel a Booked Ticket\n\t\t\t4. Bus Status\n\t\t\t5. Exit\n\t\t\t");
  printf("\n\t\t\tEnter your choice:");
  scanf("%d", &choice);
  printf("\n\n");
  return choice;
}


void list_bus_wrapper()
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
  print_bus_list();
  for(i=2; i>=1; i--){
    printf("\n\t\t\tGoing back in %ds\n", i);
    sleep(1);
  }
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
    for(i=3; i>=1; i--){
      printf("\n\t\t\tGoing back in %ds\n", i);
      sleep(1);
    }
    printf("\n\n");
    list_bus_wrapper(list_bus());
}

void print_bus_list(){
  for(i=0; i<5; i++){
    printf("\t\t\t%d.%s\n", i+1, bus_list_5[i]);
  }
}
void bus_file_read()
{
  char name_local[200];
    FILE *fp, *fopen();

    print_bus_list();
    printf("\n\t\t\tEnter your choice:");
    scanf("%d", &dec);
    printf("\n\n");

    switch (dec) {

        case 1:
        fp = fopen("name1.txt","r+");
        fgets(name_local,200,fp);
        fclose(fp);
        strcpy(name, name_local);
        break;

        case 2:
         fp = fopen("name2.txt","r+");
         fgets(name_local,200,fp);
         fclose(fp);
         strcpy(name, name_local);
         break;

        case 3:
         fp = fopen("name3.txt","r+");
         fgets(name_local,200,fp);
         fclose(fp);
         strcpy(name, name_local);
         break;

        case 4:
         fp = fopen("name4.txt","r+");
         fgets(name_local,200,fp);
         fclose(fp);
         strcpy(name, name_local);
         break;

        case 5:
         fp = fopen("name5.txt","r+");
         fgets(name_local,200,fp);
         fclose(fp);
         strcpy(name, name_local);
         break;
        }
}

void split_names()
{
  cnt=0;
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
            printf("%d.%s\t\t", i, name_split[i-1]);
        }
        else if(i % 4 == 0 && i>count_names){
          printf("%d.%s\n", i, list[i-1]);
        }
        else{
            printf("%d.%s\t\t", i, list[i-1]); /* idk */
          }

}
    printf("\n\n\n\t\t\tAvailable Seats:%d\n",32-count_names);
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
  printf("\t\t\tUSERNAME - ");
  scanf("%s", login_input);
  printf("\n");
  printf("\t\t\tPASSWORD - ");
  scanf("%s", pass_input);
  printf("\n");
  if (strcmp(login_input,login) == 0){
    if(strcmp(pass_input,pass) == 0){
      printf("\t\tOk, now you have acces to the system, enjoy!\n");
      printf("\tWelcome to the Bus Ticket System, chose the options from below:\n\n");
      list_bus_wrapper(list_bus());
    }
    else
    printf("Incorrect PASSWORD\n");
  }
  else
  printf("Incorrect USERNAME\n");
}
