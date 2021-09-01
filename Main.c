#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"MovieBookingHeader.h"
#include"MovieBookingStructure.h"
#include"MovieBookingFunction.c"

int seat = 60;
int main() {
    int ch;
    do {
        printf("\nMovie Ticket booking!!!");
        printf("\n1. To Insert Movie\n");
        printf("2. To View All Movie\n");
        printf("3. To Find Movie\n");
        printf("4. To Book Tickets\n");
        printf("5. To View All Transactions\n");
        printf("0. To Exit\n");

        printf("\nEnter your Choice :\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert_details();
                break;
            case 2:
                viewAll();
                break;
            case 3:
                find();
                break;
            case 4:
                book_ticket();
                break;
            case 5:
               old_record();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Wrong choice !");
                break;
        }
    } while (ch != 0);
    return 0;
}
