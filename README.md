# BusTicketingSystem
**A data base called "BusTicketingSystem" made by me whose trying to learn C (ignore the bugs it has)**

# Functions
**main_func_list** - Prints the available options;
**main_func_list_wrapper** - Executes the option chosen by the user;
**log_in** - It's responsible for the logging in;
**bus_list** - Displays the available buses;
**book_ticket** - Connects all the functions needed for booking a ticket together;
**cancel_ticket** - Connects all the functions needed for canceling a ticket together;
**bus_status** - Connects all the functions needed for displaying a bus's seats;
**print_bus_list** - Prints the buses for nearly every feature;
**bus_file_read** - Reads and copyies the strings from the files **"name1.txt-name5.txt"**, **"seat1.txt-seat5.txt"** into a global variable;
**bus_seats_print** - Prints the available seats for each bus;
**bus_file_write** - Writes to the coresponding files the booked ticket;
**split_names** - Splits the string collected from the file into a 2d Array;
**split_seats** - Splits the string collected from the file into a 2d Array then transforms it into an int;
**remove_empty_seats** - Removes the "Empty" seats from the files that are placed by canceling a seat;
**register_1st_part** - A part of the function that's responsible for booking a ticket;
**register** - Books a ticket;
**cancel_ticket_print** - Prints "Empty" in the place of the credentials's person who booked a ticket;
**cancel_ticket_main** - The main function that's responsible for canceling a ticket;

# Files
The **"main.c"** is the main file and the **"name1.txt-name5.txt"** is where the credentials of the person who booked the ticket are saved. **"seat1.txt-seat5.txt"** are the files where the seat coresponding to the credentials are saved (saved by arrat index)

# Important Note
**Files shouldn't be saved manually**(depending on the text editor you are using, it could break the program :) )
