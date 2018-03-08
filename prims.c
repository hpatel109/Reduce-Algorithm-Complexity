#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
 
// A structure for a node in adjacency list
struct ALNode
{
    int dest;
    int weight;
    struct ALNode* next;
};
 

struct AdjList
{
    struct ALNode *head;  
};
 

struct Graph
{
    int V;
    struct AdjList* array;
};
 

struct ALNode* newALNode(int dest, int weight)
{
    struct ALNode* newNode =
            (struct ALNode*) malloc(sizeof(struct ALNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
 

struct Graph* create_graph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
    
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 

void addEdge(struct Graph* graph, int src, int dest, int weight)
{
    struct ALNode* newNode = newALNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    newNode = newALNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
 
struct Min_Heap_Node
{
    int  v;
    int key;
};
 
struct Min_Heap
{
    int size;      
    int capacity;  
    int *pos;     // This is needed for decreaseKey()
    struct Min_Heap_Node **array;
};
 
// A utility function to create a new Min Heap Node
struct Min_Heap_Node* newMin_Heap_Node(int v, int key)
{
    struct Min_Heap_Node* min_Heap_Node =
           (struct Min_Heap_Node*) malloc(sizeof(struct Min_Heap_Node));
    min_Heap_Node->v = v;
    min_Heap_Node->key = key;
    return min_Heap_Node;
}
 
// A utilit function to create a Min Heap
struct Min_Heap* createMin_Heap(int capacity)
{
    struct Min_Heap* min_Heap =
         (struct Min_Heap*) malloc(sizeof(struct Min_Heap));
    min_Heap->pos = (int *)malloc(capacity * sizeof(int));
    min_Heap->size = 0;
    min_Heap->capacity = capacity;
    min_Heap->array =
         (struct Min_Heap_Node**) malloc(capacity * sizeof(struct Min_Heap_Node*));
    return min_Heap;
}
 
// A utility function to swap two nodes of min heap. Needed for min heapify
void swapMin_Heap_Node(struct Min_Heap_Node** a, struct Min_Heap_Node** b)
{
    struct Min_Heap_Node* t = *a;
    *a = *b;
    *b = t;
}
 
// A standard function to heapify at given idx
// This function also updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void min_Heapify(struct Min_Heap* min_Heap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;
 
    if (left < min_Heap->size &&
        min_Heap->array[left]->key < min_Heap->array[smallest]->key )
      smallest = left;
 
    if (right < min_Heap->size &&
        min_Heap->array[right]->key < min_Heap->array[smallest]->key )
      smallest = right;
 
    if (smallest != idx)
    {
        struct  Min_Heap_Node *smallestNode = min_Heap->array[smallest];
        struct Min_Heap_Node *idxNode = min_Heap->array[idx];
 
        min_Heap->pos[smallestNode->v] = idx;
        min_Heap->pos[idxNode->v] = smallest;
 
        swapMin_Heap_Node(&min_Heap->array[smallest], &min_Heap->array[idx]);
 
        min_Heapify(min_Heap, smallest);
    }
}
 
int isEmpty(struct Min_Heap* min_Heap)
{
    return min_Heap->size == 0;
}
 
 struct Min_Heap_Node* extractMin(struct Min_Heap* min_Heap)
{
    if (isEmpty(min_Heap))
        return NULL;
    struct Min_Heap_Node* root = min_Heap->array[0];
 
    struct Min_Heap_Node* lastNode = min_Heap->array[min_Heap->size - 1];
    min_Heap->array[0] = lastNode;
 
    min_Heap->pos[root->v] = min_Heap->size-1;
    min_Heap->pos[lastNode->v] = 0;
 
    --min_Heap->size;
    min_Heapify(min_Heap, 0);
 
    return root;
}
 
void decreaseKey(struct Min_Heap* min_Heap, int v, int key)
{
    int i = min_Heap->pos[v];
     min_Heap->array[i]->key = key;
 
    while (i && min_Heap->array[i]->key < min_Heap->array[(i - 1) / 2]->key)
    {
        // Swap this node with its parent
        min_Heap->pos[min_Heap->array[i]->v] = (i-1)/2;
        min_Heap->pos[min_Heap->array[(i-1)/2]->v] = i;
        swapMin_Heap_Node(&min_Heap->array[i],  &min_Heap->array[(i - 1) / 2]);
 
        // move to parent index
        i = (i - 1) / 2;
    }
}
 
bool isInMin_Heap(struct Min_Heap *min_Heap, int v)
{
   if (min_Heap->pos[v] < min_Heap->size)
     return true;
   return false;
}
 
void Array_Print(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
        printf("%d - %d\n", arr[i], i);
}
 
void Prim_MST(struct Graph* graph)
{
    int V = graph->V;
    int parent[V];   
    int key[V];      
 
    struct Min_Heap* min_Heap = createMin_Heap(V);
 
    for (int v = 1; v < V; ++v)
    {
        parent[v] = -1;
        key[v] = INT_MAX;
        min_Heap->array[v] = newMin_Heap_Node(v, key[v]);
        min_Heap->pos[v] = v;
    }
 
    key[0] = 0;
    min_Heap->array[0] = newMin_Heap_Node(0, key[0]);
    min_Heap->pos[0]   = 0;
 
    min_Heap->size = V;
 
    while (!isEmpty(min_Heap))
    {
        struct Min_Heap_Node* min_Heap_Node = extractMin(min_Heap);
        int u = min_Heap_Node->v; 
 
        struct ALNode* noDE = graph->array[u].head;
        while (noDE != NULL)
        {
            int v = noDE->dest;
 
            if (isInMin_Heap(min_Heap, v) && noDE->weight < key[v])
            {
                key[v] = noDE->weight;
                parent[v] = u;
                decreaseKey(min_Heap, v, key[v]);
            }
            noDE = noDE->next;
        }
    }
 
    Array_Print(parent, V);
}
 
int main()
{
    
 
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
   
    int j;
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
    int i=0,harsh=0,ver,count=0,k=0,digit,h=0,q=0,w=0,n=0;
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
 
  
   
 
  
    int V = Final_vertex;  // Number of vertices in graph
    int E = Final_edge;  // Number of edges in graph
    printf("error %d\n",Final_vertex);
    struct Graph* graph = create_graph(V);
 
 //printf("\n %d",n);
    j=0;
    i=0;
 while(!(source[i]==9190))
{
   printf("\n%d\n",source[i]);
    
    if(source[i]!=-99)
    {
  /*  graph->edge[i].src = source[i];
    graph->edge[i].dest = vertex[i];
    graph->edge[i].weight = weight[i];*/

          addEdge(graph,source[i],vertex[i],weight[i]);
          printf("\n %d %d %d",source[i],vertex[i],weight[i]);
    }
    i++;
  }

  

 
    

   /* for(int i=0;i<V;i++)
    {
    printf(" enter the input");
    scanf("%d %d %d",&z,&x,&c);
    addEdge(graph, z, x, c);
    }*/

    Prim_MST(graph);
 
    return 0;
}
