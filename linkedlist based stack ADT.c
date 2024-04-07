//Linked List Based Implementation of Stack ADT
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
}*top=NULL,*p=NULL,*temp=NULL;
void PUSH(int,char[],char[],long long int,int,float);
void display();
int POP();
struct node* POPNode();
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
				PUSH(roomno,name,roomtype,phoneno,NOD,rent);
			break;
			case 2:
				printf("\nBooked Rooms are :\n");
				display();
			break;
			case 3:
				POP();
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
//Algorithm for PUSHion in Linked List ADT
void PUSH(int d,char a[],char b[],long long int c,int e,float f){
    temp=(struct node*)malloc(sizeof(struct node));
    temp->roomno=d;
    strcpy(temp->name,a);
    strcpy(temp->roomtype,b);                                                                                                                   
    temp->phoneno=c;
    temp->NOD=e;
    temp->rent=f;
    temp->next=NULL;
    if(top==NULL){
        top=temp;
        return;
    }
    temp->next=top;
    top=temp;
}
void display(){
       if(top==NULL){
          printf("\nSorry Stack is empty; Stack underflow");
        return;
       }
       p=top;
       while(p!=NULL){
           printf("\n%d\t%s\t%s\t%lld\t%d\t%.2f",p->roomno,p->name,p->roomtype,p->phoneno,p->NOD,p->rent);
           p=p->next;
       }
}
int POP(){
 int x;
 if(top==NULL){
    printf("\nSorry stack is empty:Stack underflow");
    return 0;
}
x=top->roomno;
top=top->next;
return x;
}
struct node* POPNode(){
 if(top==NULL){
    printf("\nSorry stack is empty:Stack underflow");
    return 0;
}
p=top;
top=top->next;
return p;    
}
