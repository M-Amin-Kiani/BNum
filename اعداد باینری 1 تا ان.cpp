
#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;

    Node(T d, Node <T>* n)  //constractor
    {
        data = d;
        next = n;
    }
};

template <typename T>
class one_LinkedList
{
public:
    Node<T>* head, * tail;
    int size;

    one_LinkedList()
    {
        size = 0;
        head = tail = nullptr;
    }

    bool IsEmpty()
    {
        return size == 0;
    }

    T First()
    {
        if (IsEmpty())
        {
            return nullptr;
        }

        return head->data;
    }

    void addLast(T d)
    {
        Node<T> *newlast = new Node<T>(d,nullptr);
        if (IsEmpty())
        {
            head = newlast;
        }
        else
        {
            tail->next = newlast;
        }

        tail = newlast;

        size++;
    }

    T removeFirst()
    {
        if (IsEmpty())
        {
            return nullptr;
        }

        Node<T>* tmp_deleted = head;

        T first_of_l = head->data;
        head = head->next;
        delete tmp_deleted;

        size--;

        if (size == 0)
        {
            tail = nullptr;
        }

        return first_of_l;
    }
};

template <class T>
class BQueue_linkedlist
{
public:

    one_LinkedList <T> *my_Blist = new one_LinkedList<T>;

    void enqueue(T d)
    {
        my_Blist->addLast(d);
    }
    T dequeue()
    {
        return my_Blist->removeFirst();
    }

    T top ()
    {
        return my_Blist->First();
    }
};

int main()
{
    int n;

    cin >> n;

    BQueue_linkedlist<string> *my_binary_queue = new BQueue_linkedlist<string>;

    my_binary_queue->enqueue("1"); // first binary num

    for(int i = 0; i < n; i++)
    {

        string Bnext = my_binary_queue->top(), Bnextnext = my_binary_queue->top(), b1, b2;

        my_binary_queue->dequeue(); // delete last top (next of 1 2 3 4 ...)

        cout << Bnext << " ";

        b1 = Bnext + "0"; // aval in chap
        b2 = Bnextnext + "1"; // go to saf

        my_binary_queue->enqueue(b1);
        my_binary_queue->enqueue(b2);
    }

    cout << endl;

    return 0;
}
