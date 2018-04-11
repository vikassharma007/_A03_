#include<stdlib.h>
#include<stdio.h>
void RRS(int n,int b[10])
{
	printf("----------------------------------QUEUE 2-------------------------------------\n\n");
	int br[10],wo[10];
	int i,bt,q=2,count;
	float awt=0,att=0;
	for (i=0;i<10;i++)
		 wo[i]=0;
	for(i=0;i<n;i++)
		br[i]=b[i];
	bt=0;
	for(i=0;i<n;i++)
		bt=bt+b[i];
	count=0;
	printf("\nThe Gantt Chart is as follows:\n");
	printf("\n 0");
	do
	{
	for(i=0;i<n;i++)
	{
	  if(br[i]==0)
	   {}
	  else
	  {
	   if(br[i]>=q)
	   {
		 br[i]=br[i]-q;
		 if(br[i]==0)
			wo[i]=count;
		 count=count+q;
		 printf("\t(P%d)",i);
		 printf("\t%d",count);
	   }
	   else
	   {
		 if(br[i]<q)
		{
		   count=count+br[i];
		   br[i]=0;
		   wo[i]=count;
		   printf("\t(P%d)",i);
		   printf("\t%d",count);
		 }
	   }
	 }
	}
	}while(count<bt);
	for(i=0;i<n;i++)
		awt=awt+(wo[i]-b[i]);
	awt=awt/n;
	printf("\n The average waiting time is....%f",awt);
	for(i=0;i<n;i++)
		att=att+wo[i];
	att=att/n;
	printf("\n The average turnaround time is....%f",att);
}
int n;
int main()
{
	int a;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	while(n<0)
	{
		printf("Enter a value greater than 0\n\n");
		printf("Enter the number of processes:");
		scanf("%d",&n);
	}
	int p[n][3],temp[n],sorted[n][6],tottm=0,time=0,count=0;
	
	for(int i=0;i<n;i++)
	{
		sorted[i][4]=0;
		sorted[i][5]=0;
		system("clear||cls");
		printf("--------------------------Process No.%d------------------------------\n",i);
		printf("Enter the Priority of Process No.%d:",i);
		scanf("%d",&p[i][0]);
		while(p[i][0]<0)
		{
			printf("Enter a value greater than 0\n\n");
			printf("Enter the Priority of Process No.%d:",i);
			scanf("%d",&p[i][0]);
		}
		printf("Enter the Arrival Time of Process No.%d:",i);
		scanf("%d",&p[i][1]);
		while(p[i][1]<0)
		{
			printf("Enter a value greater than 0\n\n");
			printf("Enter the Arrival Time of Process No.%d:",i);
			scanf("%d",&p[i][1]);
		}
		printf("Enter the Burst Time of Process No.%d:",i);
		scanf("%d",&p[i][2]);
		while(p[i][2]<0)
		{
			printf("Enter a value greater than 0\n\n");
			printf("Enter the Burst Time of Process No.%d:",i);
			scanf("%d",&p[i][2]);
		}
	}
	for(int i=0;i<n;i++)
	{
		tottm+=p[i][2];
		temp[i]=p[i][1];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if (temp[i] > temp[j])
            {
                a =  temp[i];
                temp[i] = temp[j];
                temp[j] = a;
            }
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(temp[i]==p[j][1])
			{
				sorted[i][0]=p[j][0];
				sorted[i][1]=p[j][1];
				sorted[i][2]=p[j][2];
				sorted[i][3]=p[j][2];
			}
		}
	}
	printf("\n\n-----------------------------QUEUE 1-------------------------\n\n");
	int i=0,j=1;
	
	while(tottm>=time)
	{
		time++;
		if(sorted[i][1]==time && sorted[i][0]>sorted[j][0])
		{
			i++;
			if(i==n)
			{
				i=0;
			}
			j++;	
			if(j==n)
			{
				j--;
			}
		}
		if(sorted[i][4]==0)				//Checking if it's from Q1 or Q2
		{
			if(sorted[i][2]!=0 && sorted[j][1]==time && sorted[j][0]<sorted[i][0])		//SETTING THE BIT
			{
				sorted[i][4]=1;
			}
			if(sorted[i][2]>=0 && sorted[j][0]<sorted[i][0] && sorted[i][4]!=1)
			{
				sorted[i][2]-=1;  //REDUCING FROM BT
				sorted[i][5]+=1; //ADDING TO TAT
			}
		}
	}
	for(int j=0;j<n;j++)
	{
		if(sorted[j][4]==1)
		{
			count++;
		}
	}
	int bt[count];
	for(int j=0;j<n;j++)
	{
		int m=0;
		if(sorted[j][4]==1)
		{
			bt[m]=sorted[j][2];
			m++;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("Arrival Time : %d\n",sorted[i][1]);
		printf("Burst Time : %d\n",sorted[i][2]);
		printf("Priority : %d\n",sorted[i][0]);
		printf("BTC: %d\n",sorted[i][3]);
	}
	RRS(count,bt);
}
