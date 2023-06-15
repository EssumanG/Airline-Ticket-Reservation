//This is an Airline Ticket Reservation Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// #include <windows.h>
#define MAX 3
#define KEY 1000
int stack_ticket[MAX] = {3, 2, 1};//This is a stack in the form of array
int top = 2;//The index of the top of the stack

//Protoypte of some functions
char* lowerSrting(char name[40]);
char* upperSrting(char name[40]);

int isFull(){//Checking whether stack is full
    if(top == 2)
        return 1;
    else
        return 0;
}

int isEmpty(){//Checking whether the stack i empty
    if(top == -1)
        return 1;
    else
        return 0;
}
void push(int value){//Pushing ticket back to the stack
    if (isFull() == 1)//When stack is full
        printf("Stack Overflow");
    else{
        top = top + 1;
        stack_ticket[top] = value;
        return;
    }
}

int pop(){//Popping the a ticket from the stack
    int value;
    if (isEmpty() == 1){//When stack is empty
        printf("Stack Underflow");
        }
    else{
        value = stack_ticket[top];
        top = top - 1;
        return value;
    }
}

//Creating the structure of a node(Passenger)
typedef struct Passenger{
    int ticket_id;
    char passenger_name[40];
    char passenger_lastname[40];
    struct passenger_list *next;
}Passenger;

Passenger* headList = NULL;
int len;

//Inserting a node the beginning of the list
void insertAtBegin(Passenger *newPassenger)
{
    newPassenger -> next = headList;
    headList = newPassenger;
}

//Insert a node at the oof the list
 void insertAtEnd(Passenger *newPassenger, Passenger *currPassenger){
        currPassenger = headList;
     while(currPassenger -> next != NULL){
        currPassenger = currPassenger->next;
    }
    currPassenger -> next = newPassenger;
 }

 //Insert a node at a particular postion
 void insertInterNode(int insertPos, Passenger *newPassenger){
     Passenger *currPassenger = headList;
     insertPos--;
     while(insertPos != 1)
     {
         currPassenger = currPassenger ->next;
         insertPos--;
     }
     newPassenger->next = currPassenger ->next;
     currPassenger->next = newPassenger;
    /*int count = 0;
    newPassenger -> next = NULL;
    if(insertPos == 0 )
    {
        newPassenger -> next= headList;
        headList = newPassenger;
        return;
    }
    Passenger *currPassenger = headList;
    while(count < insertPos - 2){
        currPassenger = currPassenger -> next;
        count++;
    }
    newPassenger -> next = currPassenger -> next;
    currPassenger -> next = newPassenger;



    /**for (int i = 0; i < insertPos - 1; i++)
    {
        currPassenger = currPassenger -> next;
    }
    newPassenger-> next = currPassenger -> next;
    currPassenger -> next = newPassenger;**/
 }

 //Traversing to a given index of list
 int gotoIndex(int index)
{
    int count = 1;
    Passenger *temp;
    temp = headList;
    while(count != index ){

            count++;
            temp =  temp -> next;
            //count++;
    }
    return temp -> ticket_id;//Return the ticket id of the passenger at that particular index
}

//Insert a node to the List by insertion sort
void insert(Passenger *newPassenger, int insertPos){
    Passenger *currPassenger, *prevPassenger;
    currPassenger = headList;
    if (headList == NULL)//When list is empty
    {
        headList = newPassenger;
    }
    else{
            if(insertPos == 1)//When the index is 1, insert at the beginning
            {
                insertAtBegin(newPassenger);
            }
            else if (insertPos == length() + 1)//When the index is one greater the the length of the list, insert at the end
            {
                insertAtEnd(newPassenger, currPassenger);
            }
            else
            {
                insertInterNode(insertPos, newPassenger);//Inserting the a node at a position other than the beginning and the end pf the list
            }
    }
    newPassenger -> ticket_id = KEY + pop();//Popping the ticket from the stack and attaching it to the passenger id

    printf("\n<<<<<<<<<<<<<<<Ticket Reserved Successfully>>>>>>>>>>>>>>>");
    printf("\nTicket Id : %d", newPassenger -> ticket_id);
    printf("\nFirst name : %s", upperSrting(newPassenger -> passenger_name));
    printf("\nLast name : %s", upperSrting(newPassenger -> passenger_lastname));
    printf("\n========================================================");

}
/***
void makeReservation(char name){
    addtoList(name, headList);
    pop();
}
**/
char* lowerSrting(char name[40])//Converting all the string to Lowercases
{
    int namelen = strlen(name);
    for (int i = 0; i <= namelen - 1; i++)
    {
        name[i] = (char)tolower(name[i]);
    }
    return name;
}

char* upperSrting(char name[40])//Converting all the string to Uppercases
{
    int namelen = strlen(name);
    for (int i = 0; i <= namelen - 1; i++)
    {
        name[i] = (char)toupper(name[i]);
    }
    return name;
}

//Display the all the passengers in the list
void display(){
    Passenger *currentPassenger = headList;
    if(currentPassenger == NULL){
        printf("\n----------!!!List is empty!!!----------\n");
        }
    else{
            while(currentPassenger != NULL)
            {
                printf("\n------------------------------");
                printf("Ticket Id : %d------------------------------\n", currentPassenger -> ticket_id);
                printf("First Name :%s\n", upperSrting(currentPassenger -> passenger_name));
                printf("Last Name :%s\n", upperSrting(currentPassenger -> passenger_lastname));
                printf("Price : $150.00");
                printf("\n-----------------------------------------------------------------------------\n");
                currentPassenger = currentPassenger -> next;
            }
            printf("\n\n");
        }

}

int length()//Getting the length of the list
{
    int count;
    if(headList == NULL){
        int count= 0;
        return count;
    }
    Passenger *currPassenger = headList;
    while(currPassenger != NULL)
    {
        count++;
        currPassenger = currPassenger -> next;

    }
    return count;
}
int position(char name[])//Get the position of given passenger
{
    int index = 1;
    Passenger *temp = headList;
    if (temp == NULL)
    {
        return index;
    }
    while(temp != NULL && (strcmp(lowerSrting(temp -> passenger_name), lowerSrting(name)) == -1))// && (strcmp(lowerSrting(temp -> passenger_lastname), lowerSrting(lastname)) == 0)))
        {
            index++;
            temp = temp -> next;
        }
        return index;
}

int isReserved(char name[], char lastname[])//Check if the given name is resereved
{
    int index = 1;
    Passenger *temp = headList;
    if (temp == NULL)//When List is empty
    {
        printf("\nList is Empty");
    }
    while(temp != NULL)
    {
        if ((strcmp(lowerSrting(temp -> passenger_name), lowerSrting(name)) == 0) && (strcmp(lowerSrting(temp -> passenger_lastname), lowerSrting(lastname)) == 0))//When the given name matches any of the Passenger in the list
        {
            return index;
            break;

        }
        else{//Traverse through the list
            index ++;
            temp = temp -> next;
        }
    }
}

void portal()
{
    int val;
    printf("\n______________________________________________________________________________________________\n");
    printf("\t\t\t\t\t\t\tPress:\n");
            printf("\t\t\t\t\t\t\t1: Back To Menu\n");
            printf("\t\t\t\t\t\tPress Any Key Other to Exit\n");
            printf("\t\t\t\t_________________________________________________\t\t\t\n");
            printf("...>>>");
            scanf("%d", &val);
            if (val == 1)
            {
                system("cls");
                main();
            }
            else
            {
                exit(1);
            }
}

//Deleting a Node at the beginning of the list
void delFirstNode(int index)
{
    struct node *temp;
    temp = headList;
    headList = headList -> next;
    free(temp);
    //push(index);
}

//Deleting a Node at the of the list
void delLastNode(int index)
{
    int count = 0;
    Passenger *currPassenger, *prevPassenger;
    currPassenger = headList;
    while(currPassenger -> next != NULL)
    {
        prevPassenger = currPassenger;
        currPassenger = currPassenger -> next;
        count++;
    }
    if (currPassenger == headList){
        headList = NULL;

    }
    else{
        prevPassenger -> next = NULL;
    }
    free(currPassenger);
}

//Deleting a Node at given position
void delInterNode(int index)
{
    Passenger *currPassenger, *prevPassenger;
    int count = 1;
    prevPassenger = headList;

    while (count < index - 1)
    {
        prevPassenger = prevPassenger -> next;
        count++;
    }
    currPassenger = prevPassenger -> next;
    prevPassenger -> next = currPassenger -> next;
    free(currPassenger);
    //push(index);


}


void del_passenger(int index)
{
    if (headList != NULL)
    {
        if (index == 1)//If the passenger is first on the list
            {
                delFirstNode(index);
            }

        else if (index == length())//If the passenger is last of the list
            {
                delLastNode(index);
            }
        else//If the Passenger is any other Position other than the first and last
            {
                delInterNode(index);
            }

    }
    else
        printf("\n!!!List Empty!!!\n");

}

int main(){
    int index, id, insert_pos;
    int num;
    char passenger_Name[40];
    char passenger_lastName[40];
    //Displays the menu
        printf("\t\t\t*********************************************************************************\n");
        printf("\t\t\t*\t\t\t\t\t\t\t\t\t\t\t*");
        printf("\n\t\t\t*\t\tPlease Enter Any Number of Your Choice:\t\t\t\t\t*");
        printf("\n\t\t\t*\t\t\t1: Reserve A Ticket\t\t\t\t\t\t*");
        printf("\n\t\t\t*\t\t\t2: Cancel A Reservation\t\t\t\t\t\t*");
        printf("\n\t\t\t*\t\t\t3: Check Whether A Ticket Is Reserved\t\t\t\t*");
        printf("\n\t\t\t*\t\t\t4: Display The Passengers\t\t\t\t\t*");
        printf("\n\t\t\t*\t\tPress Any Key To Exit The Program...\t\t\t\t\t*\n");
        printf("\t\t\t*\t\t\t\t\t\t\t\t\t\t\t*\n");
        printf("\t\t\t*********************************************************************************\n");
        printf("...");
        scanf("%d", &num);

        switch(num)
        {
            case 1://When '1'is Entered
                system("cls");
        if(top != -1)//Checks if ticket is available
        {
            Passenger *newPassenger;
            newPassenger = malloc(sizeof(Passenger));//Creating a new node
            printf("First Name :  \n");
            scanf("%s", &(newPassenger -> passenger_name));
            printf("Last Name :  \n");
            scanf("%s", &newPassenger -> passenger_lastname);
            newPassenger -> next = NULL;//Assigning the pointer of the node to null

            insert_pos = position(newPassenger -> passenger_name) ;

            //Inserting a node a particular position
            insert(newPassenger, insert_pos);
            //printf("%d \t %d", insert_pos, length());

        }
        else//Displays when ticket is not available
            printf("NO Ticket Available");
            //system("cls");
            portal();
            system("cls");
            break;
        case 2://When '2' is entered
             system("cls");
            if (headList == NULL)
            {
                printf("List is Empty");
            }
            else
            {
                printf("Please Enter Your  First Name\n");
                scanf("%s", &passenger_Name);
                printf("Please Enter Your  Last Name\n");
                scanf("%s", &passenger_lastName);
                index = isReserved(passenger_Name, passenger_lastName);
                //printf("%d", index);
                if (index > 0)
                    {
                        printf("\nReservation has been successfully canceled");
                        id = gotoIndex(index)- KEY;
                        del_passenger(index);
                        //printf("%d", id);
                        //printf("%d", index);
                        push(id);

                    }
                else
                    {printf("\n%s %s not found",passenger_Name, passenger_lastName);}
            }
            portal();
            system("cls");
            //printf("%d", val);
            break;

        case 3://When '3' is entered
             system("cls");
            if (headList == NULL)
            {
                printf("List is Empty");
            }
            else
            {
                printf("Please Enter Your Name\n");
                scanf("%s", &passenger_Name);
                printf("Please Enter Your  Last Name\n");
                scanf("%s", &passenger_lastName);
                if (isReserved(passenger_Name, passenger_lastName)> 0)
                    printf("\n%s, your ticket is reserved", passenger_Name);
                else
                    printf("\n%s %s not found",passenger_Name, passenger_lastName);
            }
            portal();
                //printf("%d", val);
            break;

        case 4://When '4' is entered
            //printf("%d", length());
            display();
            //system("cls");
            portal();
             system("cls");
            break;
        default:
            return -1;
             system("cls");
            break;

        /*default:
            printf("\nOops, Your input is invalid\n");
            portal();
            break;*/
        }


    return 0;
}
