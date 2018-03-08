#include<stdio.h>
 
#define MAX 30
 
typedef struct edge
{
    int u,v,w;
}edge;
 
typedef struct edgelist
{
    edge data[MAX];
    int n;
}edgelist;
 
edgelist elist;
 
int G[MAX][MAX],n;
edgelist spanlist;
 
void kruskal();
int find(int belongs[],int vertexno);
void union1(int belongs[],int c1,int c2);
void sort();
void print();
 
void main()
{
    int i,j,total_cost;


FILE *fp;
   char a[500],final[500],chx,ix=0,bx=0;

   

   fp=fopen("maste.txt","r");

   if(fp==NULL)
   {

   }
   else
   {
    while(chx != EOF)
    {
        chx=getc(fp);
        final[ix++]=chx;
    }
   }
   fclose(fp);
   
   //na[i+1]=''
   //printf("%d",i);
   
    
   for( j=0;j<ix;j++)
   {
     if(final[j]=='\n')
     {
j++;
     }
     
a[bx++]=final[j];
     
      
     // printf("%c",final[j]);
     }
      
   
   a[bx-1]='.';
//printf("\n\n %d \n",bx);
for( j=0;j<(bx);j++)
{
  printf("%c",a[j]);
}









     int x,c,e,nn;   
    

    int vertex[50],weight[50],source[50],Final_vertex=0,Final_edge=0;
    //char a[500];
    char ans;
    int harsh=0,ver,count=0,k=0,digit,h=0,q=0,w=0,n=0;
    j=0;
//char z,x,c;
   // while( (a[i++]=getchar()) != '\n' && i < 500); /* take input from user until it's a newline or equal to 10 */
   // a[i] = '.'; /* null-terminate the string */
    i = 0;  
    //while(a[i] != '\0') /* print until we've hit \0 */
      //   {
           ho:
           
           if((a[i]>='0' && a[i]<='9') && (a[i+1]>='0' && a[i+1]<='9') && (a[i+2]>='0' && a[i+2]<='9') )
           {
            ver=(100*(a[i++]-'0') + 10*(a[i++]-'0') + (a[i++]-'0'));
                
                while(!(a[i]==')' && a[i+1]==')' && (a[i+2]==','|| a[i+2]=='?')))
                {
                harsh=1;
                
                 if((a[i]>='0' && a[i]<='9'))
                 {
                    

                    if((a[i]>='0' && a[i]<='9') && (a[i+1]>='0' && a[i+1]<='9') && (a[i+2]>='0' && a[i+2]<='9') )
                    {
                    digit=(100*(a[i++]-'0') + 10*(a[i++]-'0') + (a[i++]-'0'));
                    

                         if(count%2==0)
                          {
                            source[h++]=ver;
                           //   printf("\n %d",digit);
                             vertex[j++]=digit;
                             count++;
                             digit=0;
                          }
                          else
                          {
                          //    printf("\n %d",digit);
                            weight[k++]=digit;
                            count++;
                            digit=0;
                          }
                    }

                     else if((a[i]>='0' && a[i]<='9') && (a[i+1]>='0' && a[i+1]<='9'))
                     {
                     digit=(10*(a[i++]-'0') + (a[i++]-'0'));
                     
                          if(count%2==0)
                          {
                            source[h++]=ver;
                          //    printf("\n %d",digit);
                             vertex[j++]=digit;
                             count++;
                             digit=0;
                          }
                          else
                          {
                          //    printf("\n %d",digit);
                            weight[k++]=digit;
                            count++;
                            digit=0;
                          }
                     }
                     else     //(a[i]>='0' && a[i]<='9')
                     {
                     digit=a[i++]-'0';
                         
                          if(count%2==0)
                          {
                            source[h++]=ver;
                           //   printf("\n %d",digit);
                             vertex[j++]=digit;
                             count++;
                             digit=0;
                          }
                          else
                          {
                          //    printf("\n %d",digit);
                            weight[k++]=digit;
                            count++;
                            digit=0;
                          }
                     }
                          


                }
                else
                {
                    i++;    
                }

                }
                i=i+3;
            
            
                goto ho;
                

           }
           else if((a[i]>='0' && a[i]<='9') && (a[i+1]>='0' && a[i+1]<='9'))
           {
            ver=(10*(a[i++]-'0') + (a[i++]-'0'));
            while(!(a[i]==')' && a[i+1]==')' && (a[i+2]==','|| a[i+2]=='.')))
                {
                harsh=1;
                
                 if((a[i]>='0' && a[i]<='9'))
                 {
                    

                    if((a[i]>='0' && a[i]<='9') && (a[i+1]>='0' && a[i+1]<='9') && (a[i+2]>='0' && a[i+2]<='9') )
                    {
                    digit=(100*(a[i++]-'0') + 10*(a[i++]-'0') + (a[i++]-'0'));
                    

                         if(count%2==0)
                          {
                            source[h++]=ver;
                           //   printf("\n %d",digit);
                             vertex[j++]=digit;
                             count++;
                             digit=0;
                          }
                          else
                          {
                          //    printf("\n %d",digit);
                            weight[k++]=digit;
                            count++;
                            digit=0;
                          }
                    }

                     else if((a[i]>='0' && a[i]<='9') && (a[i+1]>='0' && a[i+1]<='9'))
                     {
                     digit=(10*(a[i++]-'0') + (a[i++]-'0'));
                     
                          if(count%2==0)
                          {
                            source[h++]=ver;
                          //    printf("\n %d",digit);
                             vertex[j++]=digit;
                             count++;
                             digit=0;
                          }
                          else
                          {
                          //    printf("\n %d",digit);
                            weight[k++]=digit;
                            count++;
                            digit=0;
                          }
                     }
                     else     //(a[i]>='0' && a[i]<='9')
                     {
                     digit=a[i++]-'0';
                         
                          if(count%2==0)
                          {
                            source[h++]=ver;
                           //   printf("\n %d",digit);
                             vertex[j++]=digit;
                             count++;
                             digit=0;
                          }
                          else
                          {
                          //    printf("\n %d",digit);
                            weight[k++]=digit;
                            count++;
                            digit=0;
                          }
                     }
                          


                }
                else
                {
                    i++;    
                }

                }
                i=i+3;
            
            
                goto ho;


           }
           else if(a[i]>='0' && a[i]<='9')
           {
            ver=a[i++]-'0';
            

            while(!(a[i]==')' && a[i+1]==')' && (a[i+2]==','|| a[i+2]=='.')))
                {
                harsh=1;
                
                 if((a[i]>='0' && a[i]<='9'))
                 {
                    

                    if((a[i]>='0' && a[i]<='9') && (a[i+1]>='0' && a[i+1]<='9') && (a[i+2]>='0' && a[i+2]<='9') )
                    {
                    digit=(100*(a[i++]-'0') + 10*(a[i++]-'0') + (a[i++]-'0'));
                    

                         if(count%2==0)
                          {
                            source[h++]=ver;
                           //   printf("\n %d",digit);
                             vertex[j++]=digit;
                             count++;
                             digit=0;
                          }
                          else
                          {
                          //    printf("\n %d",digit);
                            weight[k++]=digit;
                            count++;
                            digit=0;
                          }
                    }

                     else if((a[i]>='0' && a[i]<='9') && (a[i+1]>='0' && a[i+1]<='9'))
                     {
                     digit=(10*(a[i++]-'0') + (a[i++]-'0'));
                     
                          if(count%2==0)
                          {
                            source[h++]=ver;
                          //    printf("\n %d",digit);
                             vertex[j++]=digit;
                             count++;
                             digit=0;
                          }
                          else
                          {
                          //    printf("\n %d",digit);
                            weight[k++]=digit;
                            count++;
                            digit=0;
                          }
                     }
                     else     //(a[i]>='0' && a[i]<='9')
                     {
                     digit=a[i++]-'0';
                         
                          if(count%2==0)
                          {
                            source[h++]=ver;
                           //   printf("\n %d",digit);
                             vertex[j++]=digit;
                             count++;
                             digit=0;
                          }
                          else
                          {
                          //    printf("\n %d",digit);
                            weight[k++]=digit;
                            count++;
                            digit=0;
                          }
                     }
                          


                }
                else
                {
                    i++;    
                }

                }
                i=i+3;
            
            
                goto ho;
           }

       //  }
   //   printf("\n%d\n",ver);
            source[h]=9190;
            vertex[j]=9190;
            weight[k]=9190;
/*i=0;

     while(!(vertex[i]==100))
     {
     printf("%d\n",source[i]);
    printf("%d\n",vertex[i]);
    printf("%d\n",weight[i]);
    i++;
     }*/
n=j;
i=0;

while(!(source[i]==9190))
{
    j=0;
    q=source[i];
    w=vertex[i];

    for(j=i+1;j<n;j++)
    {
        if(q==vertex[j] && w==source[j])
        {
            source[j]=-99;

        }
     //printf("\n %d",source[i++]);
    }
i++;

}
i=0;
j=0;
int array[100],we=0;
while(!(source[i]==9190))
{
    if(source[i] != -99)
    {
     array[we++]=source[i];
     array[we++]=vertex[i];
     printf("\n %d ",source[i]);
     printf("%d ",vertex[i]);
     printf(" %d",weight[i]);
    Final_edge++;
    }
i++;
}

nn=i;
for(i=0;i<we;i++)
{
    printf("\n %d\n",array[i]);
}

  
 /*
  
 printf("Unique Elements\n");
 for(i = 0; i < we; i++) {
  for (j=0; j<i; j++){
      if (array[i] == array[j])
       break;
   printf("\n hello1");
       }
      
     if (i == j){
        Final_vertex++;
        printf("\n hello2");
      // No duplicate element found between index 0 to i 
      printf("\n%d ", array[i]);
  }
 } */
int temp;
for (i = 0; i < we; ++i)
    {
        for (j = i + 1; j < we; ++j)
        {
            if (array[i] > array[j])
            {
                temp =  array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    

    for(i=0;i<we;i++)
{
    printf(" %d",array[i]);
}

Final_vertex=0;


for(i = 0; i < we ; i++)
{
if(array[i]==array[i+1])
continue;
else
Final_vertex++;
}
printf("The number of unique elements are %d ",Final_vertex);


  
printf("\n%d\n  ", Final_edge);
printf("%d ", Final_vertex);

//printf("hello");
 
  
   n = Final_vertex;  // Number of vertices in graph
    int E = Final_edge;  // Number of edges in graph
   
 i=0;j=0;
 bx=0;

 for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        G[i][j]=0;
i=0;
 while(!(source[i]==9190))
{
    
    if(source[i]!=-99)
    {
    
    G[source[i]][vertex[i]]=weight[i];
    G[vertex[i]][source[i]]=weight[i];

    printf("\n %d %d %d",source[i],vertex[i],weight[i]);
    }
  printf("\n%d",bx);
i++;
 }

for(i=0;i<n;i++)
{
        for(j=0;j<n;j++)
        {
        printf(" %d ",G[i][j] );}
        printf("\n");
    }

i=0;
    
    //printf("\nEnter the adjacency matrix:\n");
    
   

            
    kruskal();
    print();
}
 
void kruskal()
{
    printf("1" );
    int belongs[MAX],i,j,cno1,cno2;
    elist.n=0;
 
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
        {
            if(G[i][j]!=0)
            {
                elist.data[elist.n].u=i;
                elist.data[elist.n].v=j;
                elist.data[elist.n].w=G[i][j];
                elist.n++;
            }
        }
 
    sort();
    
    for(i=0;i<n;i++)
        belongs[i]=i;
    
    spanlist.n=0;
    
    for(i=0;i<elist.n;i++)
    {
        cno1=find(belongs,elist.data[i].u);
        cno2=find(belongs,elist.data[i].v);
        
        if(cno1!=cno2)
        {
            spanlist.data[spanlist.n]=elist.data[i];
            spanlist.n=spanlist.n+1;
            union1(belongs,cno1,cno2);
        }
    }
}
 
int find(int belongs[],int vertexno)
{
    return(belongs[vertexno]);
}
 
void union1(int belongs[],int c1,int c2)
{
    int i;
    
    for(i=0;i<n;i++)
        if(belongs[i]==c2)
            belongs[i]=c1;
}
 
void sort()
{
    int i,j;
    edge temp;
    
    for(i=1;i<elist.n;i++)
        for(j=0;j<elist.n-1;j++)
            if(elist.data[j].w>elist.data[j+1].w)
            {
                temp=elist.data[j];
                elist.data[j]=elist.data[j+1];
                elist.data[j+1]=temp;
            }
}
 
void print()
{
    int i,cost=0;
    
    for(i=0;i<spanlist.n;i++)
    {
        printf("\n%d\t%d\t%d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
        cost=cost+spanlist.data[i].w;
    }
 
    printf("\n\nCost of the spanning tree=%d",cost);
}