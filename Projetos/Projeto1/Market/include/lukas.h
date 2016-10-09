#ifndef LUKAS_H
#define LUKAS_H
#include "linked_queue.h"
#include <iostream>
#include "client.h"
#include "market_box.h"

using namespace std;

class Lukas
{
    public:
        Lukas()
        {
            //:xTESTLinkedQueue();
        }
        virtual ~Lukas(){}

        /*TESTLinkedQueue()
        {
            cout << "===================LINKED QUEUE===================" << endl;
            LinkedQueue* lqueue = new LinkedQueue();
            auto test_time = new Time();

            Client* client = new Client(test_time);

            cout << "Empty | 1 = " << lqueue->empty() << endl;
            lqueue->enqueue(client);
            cout << "Empty | 0 = " << lqueue->empty() << endl;
            lqueue->enqueue(client);
            cout << "Num People | 2 = " << lqueue->num_people() << endl;
            lqueue->dequeue();
            lqueue->dequeue();
            cout << "Num People | 0 = " << lqueue->num_people() << endl;
            cout << "===================LINKED QUEUE===================\n" << endl;
        }*/


    protected:

    private:
};

#endif // LUKAS_H
