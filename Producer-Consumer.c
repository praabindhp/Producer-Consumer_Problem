#include<stdio.h>
#include<stdlib.h>
int frnt=-1,rear=-1,buffer[5];
void consume()
{
if(frnt==-1)
printf("\n Cannot consume till producer produces it:");
else
{
printf("The consumed item is:%d",buffer[frnt]);
if(frnt==rear)
frnt=rear=-1;
else
frnt=((frnt+1)%5);
}
}
void producer(int x)
{
if(frnt==(rear+1)%5)
{
printf("\n Cannot produce till consumer haves it");
}
else
{
if(frnt==-1)
frnt=rear=0;
else
rear=((rear+1)%5);
buffer[rear]=x;
printf("\n The produced element is:%d",buffer[rear]);
}
}
void disp()
{
int i;
printf("\n The buffer contains:");
if(rear>=frnt)
{
for(i=frnt;i<=rear;++i)
printf("%d\t",buffer[i]);
}
else
{
for(i=frnt;i<5;++i)
printf("%d\t",buffer[i]);
for(i=0;i<=rear;++i);
printf("%d\t",buffer[i]);
}
}
void main()
{
int ch,z;
do
{
printf("\n*********MENU*********\n");
printf("\n Producer and Consumer");
printf("\n1.Produce an item");
printf("\n2.Consume an item");
printf("\n3.Display the items");
printf("\n4.Exit");
printf("\n Enter the choice:");
scanf("\t%d",&ch);
switch(ch)
{
case 1:
printf("\n Enter the item to be inserted in buffer");
scanf("%d",&z);
producer(z);
break;
case 2:
consume();
break;
case 3:
disp();
break;
case 4:
exit(0);
break;
}
} while(ch<=4);
}