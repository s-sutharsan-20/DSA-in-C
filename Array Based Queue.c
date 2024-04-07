//Array based implementation of Queue ADT
#include<stdio.h>
#include<string.h>
#define MAX 60
struct node{
    int roomno;
	char name[20];
	char roomtype[20];
	long long int phoneno;
	int NOD;
	float rent;
}s[MAX];
int front=-1;
int rear=-1;
void ENQUEUE(int,char[],char[],long long int,int,float);
void display();
int DEQUEUE();
int main(){
    int ch,roomno,NOD,oldval,newval;
	float rent;
	char name[20],roomtype[20];
    long long int phoneno;
	while(1){
		printf("\n------------------------------");
		printf("\n Room Booking System \n");
		printf("\n------------------------------");		
		printf("\nEnter Your Choice\n");
		printf("\n1- Book Room ");
		printf("\n2- Show Booked Rooms");
		printf("\n3- Delete a Room");
		printf("\n4- Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the Room Number:");
				scanf("%d",&roomno);
				printf("\nEnter your Name:");
				scanf("%s",&name);
				printf("\nEnter the Room Type: A/C or Non-A/C :");
	    		scanf("%s",&roomtype);
				printf("\nEnter your Phone Number:");	
				scanf("%lld",&phoneno);
				printf("\nEnter no of days you need to Stay:");
				scanf("%d",&NOD);
				rent=NOD*2000;
				ENQUEUE(roomno,name,roomtype,phoneno,NOD,rent);
			break;
			case 2:
				printf("\nBooked Rooms are :\n");
				display();
			break;
			case 3:
				DEQUEUE();
			break;
			case 4:
				printf("-----------------------------");
				printf("\nTHANK YOU VISIT AGAIN");
				printf("\n-----------------------------");
			return 0;
			default:
				printf("<<<<< PLEASE ENTER THE VALID CHOICE >>>>>");
				return 0;
	}
	}
}
//Algorithm for ENQUEUE
void ENQUEUE(int d,char a[],char b[],long long int c,int e,float f){
    if(rear==MAX-1){
        printf("\nSorry Queue is full;Overflow");
        return;
    }
    if(front==-1)
        ++front;
    ++rear;
    s[rear].roomno=d;
    strcpy(s[rear].name,a);
	strcpy(s[rear].roomtype,b);
	s[rear].phoneno=c;
	s[rear].NOD=e;
	s[rear].rent=f;
}
//Algorithm for traversal / display
void display(){
    int i;
    if(rear==-1){
        printf("\nSorry Queue is empty;Underflow");
        return;
    }
    printf("\nThe Queue contents are:");
    for(i=front;i<=rear;i++)
        printf("\n%d\t%s\t%s\t%lld\t%d\t%.2f",s[i].roomno,s[i].name,s[i].roomtype,s[i].phoneno,s[i].NOD,s[i].rent);
}
//Algorithm for DEQUEUE
int DEQUEUE(){
    int x;
    if(front==-1){
        printf("\nSorry Queue is empty:Queue Underflow");
        return 0;
    }
    x=s[front].roomno;
    front++;
    if(front==rear+1)
        front=rear=-1;
    return x;
}
