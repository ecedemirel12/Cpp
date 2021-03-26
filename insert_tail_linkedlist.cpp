#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

class LinkedList
{
    private:
        Node *head, *tail;
        int c;
    
    public:
        LinkedList()
        {
            head = tail = NULL;
        }

        void insertTail(int num)
        {
            Node *p = new Node;
            p->data = num;
            p->link = NULL;
            if(head == NULL)
            {
                head = tail = p;
            }
            else
            {
                tail->link = p;
                tail = p;
            }
            c++;
        }

        void printList()
        {
            Node *temp = head;
            while(temp != NULL)
            {
                cout << temp->data << "  ";
                temp = temp->link;
            }
        }
};

int main()
{
    LinkedList myList;
    myList.insertTail(12);
    myList.insertTail(13);
    myList.insertTail(14);
    myList.printList();

    system("pause");
    return 0;
}
