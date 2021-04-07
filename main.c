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
void bus_seats_print();
int main_func_list();
void main_func_list_wrapper();
void _register_1st_part();
void _register();
void log_in();
void print_bus_list();
void cancel_ticket_print();
void cancel_ticket_1stpart();
void cancel_ticket_2ndpart();

// Variables
const char login[] = "user", pass[] = "pass"; // login verifier
char login_input[] = "user", pass_input[] = "pass"; // pass
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
int free_seats;
int canceled_ticket[32];

int main()
{
  log_in();
}

int main_func_list()
{
  printf("\t\t\tBus Ticketing System\n\n");
  printf("\t\t\t1. Bus List\n\t\t\t2. Book Tickets\n\t\t\t3. Cancel a Booked Ticket\n\t\t\t4. Bus Status\n\t\t\t5. Exit\n\t\t\t");
  printf("\n\t\t\tEnter your choice:");
  scanf("%d", &choice);
  printf("\n\n");
  return choice;
}


void main_func_list_wrapper()
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
  main_func_list_wrapper(main_func_list());

}

void book_ticket()
{
    bus_file_read();
    split_names();
    bus_seats_print();
    _register_1st_part();
    _register();
    main_func_list_wrapper(main_func_list());
}

void cancel_ticket()
{

  bus_file_read();
  split_names();
  bus_seats_print();
  cancel_ticket_1stpart();
  cancel_ticket_2ndpart();
}

void cancel_ticket_1stpart(){
  printf("\t\tNumber of Tickets you want to cancel-");
  scanf("%d", &num_tickets);
}

void cancel_ticket_2ndpart(){
  if (num_tickets <= count_names)
  {
    for (i = 0; i < num_tickets; i++)
    {
      printf("\n\n\t\t\tSeat Number-");
      scanf("%d", &canceled_ticket[i]);
    }
    for (i = 0; i < num_tickets; i++){
      if (canceled_ticket[i] == 0)
      {
        main_func_list_wrapper(main_func_list());
      }
      else if (canceled_ticket[i] <= count_names)
      {
        cancel_ticket_print();
      }
      else{
        cancel_ticket_2ndpart();
      }
    }
  }
  else
    printf("\t\t\tWay to many seats to cancel");
    cancel_ticket_1stpart();
}

void bus_status()
{
    bus_file_read();
    split_names();
    bus_seats_print();
    for(i=3; i>=1; i--){
      printf("\n\t\t\tGoing back in %ds\n", i);
      sleep(1);
    }
    printf("\n\n");
    main_func_list_wrapper(main_func_list());
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
          if(name[i]=='\0'||name[i]==' ')
          {
              cnt++;
              j=0;
          }
          else
          {
              name_split[cnt][j]=name[i];
              j++;
          }
      }
}
void bus_seats_print()
{
  count_names=cnt-1;
  free_seats=32-count_names;
  char list[32][10]={"Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty",
  "Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty", "Empty"};
  for(i=0; i<count_names; i++)
  {
      strcpy(list[i],name_split[i]);
  }

      for(i=1; i<=32; i++){
        if(i % 4 == 0){
          printf(" %d.%s \n", i, list[i-1]);
        }
        else{
            printf(" %d.%s \t", i, list[i-1]);
          }
        }
        printf("\n\n\n\t\t\tAvailable Seats:%d\n",free_seats);
      }

void _register_1st_part(){
  if(free_seats > 0 && free_seats <= 32){
  printf("\t\t\tNumber of Tickets: ");
  scanf("%d", &num_tickets);
  _register();
}
else if(free_seats == 0){
  printf("\n\t\t\tThere are no available seats\n\n\n");
  main_func_list_wrapper(main_func_list());
}
}

void _register(){
  if(num_tickets <= free_seats && num_tickets > 0){
  printf("\nRemember, your input name shouldn't be longer than 6 letters or smaller than 4");
  for(i=1; i<=num_tickets; i++){
    printf("\n\t\t\tName for Ticket %d: ", i);
    scanf("%s", res_name);
    if(strlen(res_name) > 6 || strlen(res_name) < 4){
      printf("\n\t\t\tInvalid name");
    }
    else
    bus_file_write();
    }
    for(i=3; i>=1; i--){
      printf("\t\t\tGoing back in %ds\n", i);
      sleep(1);
  }
  main_func_list_wrapper(main_func_list());
}
else if(num_tickets == 0){
  main_func_list_wrapper(main_func_list());
}
else{
  printf("\t\t\t\nToo many seats\n\n");
  _register_1st_part();
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

void cancel_ticket_print(){
  FILE *fp, *fopen();
  j=0;
  switch (dec)
  {

  case 1:
    fp = fopen("name1.txt", "r+");
    for(i=0; i<count_names; i++){
      if(i+1 == canceled_ticket[j]){
        fprintf(fp, "Empty ");
        j++;
      }
      else
        fprintf(fp, "%s ", name_split[i]);
    }
    fclose(fp);
    main_func_list_wrapper(main_func_list());
    break;

  case 2:
    fp = fopen("name2.txt", "r+");
    for (i = 0; i < count_names; i++)
    {
      if (i+1 == canceled_ticket[j])
      {
        fprintf(fp, "Empty ");
        j++;
      }
      else
        fprintf(fp, "%s ", name_split[i]);
    }
    fclose(fp);
    main_func_list_wrapper(main_func_list());
    break;

  case 3:
    fp = fopen("name3.txt", "r+");
    for(i=0; i<count_names; i++){
      if(i+1 == canceled_ticket[j]){
        fprintf(fp, "Empty ");
        j++;
      }
      else
        fprintf(fp, "%s ", name_split[i]);
    }
    fclose(fp);
    main_func_list_wrapper(main_func_list());
    break;

  case 4:
    fp = fopen("name4.txt", "r+");
    for(i=0; i<count_names; i++){
      if(i+1 == canceled_ticket[j]){
        fprintf(fp, "Empty ");
        j++;
      }
      else
        fprintf(fp, "%s ", name_split[i]);
    }
    fclose(fp);
    main_func_list_wrapper(main_func_list());
    break;

  case 5:
    fp = fopen("name5.txt", "r+");
    for(i=0; i<count_names; i++){
      if(i+1 == canceled_ticket[j]){
        fprintf(fp, "Empty ");
        j++;
      }
      else
        fprintf(fp, "%s ", name_split[i]);
    }
    fclose(fp);
    main_func_list_wrapper(main_func_list());
    break;
  }
}

void log_in() {
  printf("\t\t\tUSERNAME - ");
  scanf("%16[^\n]%*c", login_input);
  printf("\n");
  printf("\t\t\tPASSWORD - ");
  scanf("%16[^\n]%*c", pass_input);
  printf("\n");
  if (strcmp(login_input,login) == 0){
    if(strcmp(pass_input,pass) == 0){
      printf("\t\tOk, now you have acces to the system, enjoy!\n");
      printf("\tWelcome to the Bus Ticket System, chose the options from below:\n\n");
      main_func_list_wrapper(main_func_list());
    }
    else
    printf("\t\t\tIncorrect PASSWORD\n");
  }
  else
  printf("\t\t\tIncorrect USERNAME\n");
}
