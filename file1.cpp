#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
using namespace std;
#define Thread_size 2
int buffer;
void* producer(void* args)
{   string sample;
    while (1)
    
    {
        int x = rand() % 10;
        buffer = x;
       // cout<<"generator : " <<buffer<<endl;
    }
    
    
    
}
void* consumer(void* args)
{   
    while (1)
    {
        
        sleep(1);
        cout<<"The consumer received the variable : "<<buffer<<endl;
    }
    
    
    
}
int main()
{   srand(time(NULL));
    pthread_t pt[Thread_size];
    for(int i=0;i<Thread_size;i++)
    {
        if(i==0)
        {
            if(pthread_create(&pt[i],NULL,&producer,NULL) != 0)
            {
                cout<<"error in creating generator\n";
            }
        }
        else
        {
            if(pthread_create(&pt[i],NULL,&consumer,NULL) != 0)
            {
                cout<<"error in creating consumer\n";
            }
        }
    }
    for(int i=0;i<Thread_size;i++)
    {
        if(pthread_join(pt[i],NULL) != 0)
        {
            cout<<"error in connecting\n";
        }
    
    }
}