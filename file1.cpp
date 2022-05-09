#include<iostream>
#include<thread>
#include<unistd.h>
#include<time.h>
#include<string.h>
#include<semaphore.h>
#include<mutex>
using namespace std;
#define Thread_size 2
int buffer[10];
int count = 0;
mutex mt;
sem_t semEmpty;
sem_t semFull;
void* producer()
{   string sample;
    while (1)
    
    {   
        int x = rand() % 10;
        sleep(3);
        sem_wait(&semEmpty);
        mt.lock();
        buffer[count] = x;
        count++;
        mt.unlock();
        sem_post(&semFull);
        cout<<"generator : " <<x<<endl;
        
    }
    
    
    
}
void* consumer()
{   
    while (1)
    {  int y;
        sem_wait(&semFull);
        mt.lock();
        y = buffer[count -1];
        count--;
        mt.unlock();
        sem_post(&semEmpty);
        cout<<"The consumer received the variable : "<<y<<endl;
        sleep(3);
    }
}
int main()
{   srand(time(NULL));
    thread pt1 (&producer);
    thread pt (&consumer);
    pt1.join();
    pt.join();
}