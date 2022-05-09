#include<iostream>
#include<thread>
#include<unistd.h>
#include<time.h>
#include<mutex>
#include<queue>
using namespace std;
int size;
int x = 0;
queue<int> qvalues;
mutex mt;
int bufferstatus = 1;
void* producer()
{   
    while (1)
    
    {   
        
        if(size<5)
        {
        
        mt.lock();
        sleep(1);
        qvalues.push(++x);
        size = qvalues.size();
        mt.unlock();
        cout<<"producer : " <<qvalues.back()<<endl;
        if(size==5)
        {
            bufferstatus = 0;
        }
        }
    }
    
    
    
}
void* consumer()
{   
    while (1)
    {  
        if(bufferstatus == 0)
       {
           int y;
        mt.lock();
        y = qvalues.front();
        qvalues.pop();
        size = qvalues.size();
        sleep(1);
        mt.unlock();
        cout<<"The consumer received the variable : "<<y<<endl;
        bufferstatus = 1;
       }
    }
}
int main()
{   srand(time(NULL));
    thread pt1 (&producer);
    thread pt (&consumer);
    pt1.join();
    pt.join();
}