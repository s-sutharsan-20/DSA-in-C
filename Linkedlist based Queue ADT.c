//Linked List based implementation of Queue ADT
#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node{
    int roomno;
	char name[20];
	char roomtype[20];
	long long int phoneno;
	int NOD;
	float rent;
    struct node *next;
}*front=NULL,*rear=NULL,*p=NULL,*temp=NULL;
void ENQUEUE(int,char[],char[],long long int,int,float);
void display();
int DEQUEUE();
struct node* DEQUEUENode();
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
		printf("\n1- Book a Room ");
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
				DEQUEUENode();
				printf("Room Deleted Successfully!");
			break;
			case 4:
				printf("-----------------------------");
				printf("\nTHANK YOU VISIT AGAIN");
				printf("\n-----------------------------");
			return 0;
			default:
				printf("<<<<< INVALID CHOICE >>>>>");
				return 0;
		}
	}
}
void ENQUEUE(int d,char a[],char b[],long long int c,int e,float f){
    temp=(struct node*)malloc(sizeof(struct node));
    temp->roomno=d;
    strcpy(temp->name,a);
    strcpy(temp->roomtype,b);
    temp->phoneno=c;
    temp->NOD=e;
    temp->rent=f;
    temp->next=NULL;
    if(front==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}
void display(){
        if(front==NULL){
          printf("\nSorry Rooms are not Yet Booked");
        return;
       }
       p=front;
       while(p!=NULL){
           printf("\n%d\t%s\t%s\t%lld\t%d\t%.2f",p->roomno,p->name,p->roomtype,p->phoneno,p->NOD,p->rent);
           p=p->next;
       }
}
struct node* DEQUEUENode(){
 	if(front==NULL){
    	printf("\nSorry Rooms are not Yet Booked");
    	return;
	}
	p=front;
	front=front->next;
	return p;    
}
