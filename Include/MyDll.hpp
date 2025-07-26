#include <iostream>

using std::cout;

template <typename T>
class MyDll
{
private:
    struct node
    {
        T data;
        node *next;
        node *previous;
    };

    node *head;
    node *tail;
    int _size;

    node *init(T data)
    {
        node *temp;
        temp = new node;
        temp->data = data;
        temp->next = nullptr;
        temp->previous = nullptr;
        return temp;
    }

public:
    MyDll()
    {
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }

    void push_tail(const T &data)
    {
        if (!head)
        {
            head = init(data);
            tail = head;
        }
        else
        {
            node *temp;
            temp = init(data);
            temp->previous = tail;
            tail->next = temp;
            tail = temp;
        }
        _size++;
    }

    void push_head(const T &data)
    {
        if (!head)
        {
            head = init(data);
            tail = head;
        }
        else
        {
            node *temp;
            temp = init(data);
            head->previous = temp;
            temp->next = head;
            head = temp;
        }
        _size++;
    }

    int size()
    {
        return _size;
    }

    void print()
    {
        node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "\n";
    }

    void insert(int position, const T &data)
    {
        if (position == 0)
        {
            push_head(data);
        }

        else if (position > _size)
        {
            push_tail(data);
        }

        else
        {
            node *temp = head;
            node *n1 = init(data);
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            temp->next->previous = n1;
            n1->next = temp->next;
            n1->previous = temp;
            temp->next = n1;
        }
        _size++;
    }

    void pop_head()
    {
        if (head == tail)
        {
            cout << "Empty List\n";
            delete head;
            head = tail = nullptr;
            return;
        }

        node *temp;
        temp = head;
        head = head->next;
        head->previous = nullptr;
        delete temp;
        _size--;
        if (!head)
            tail = nullptr;
    }

    void pop_tail()
    {
        if (!head)
        {
            cout << "Empty Listn\n";
            return;
        }
        else if (!head->next)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            node *temp = tail;
            tail = tail->previous;
            tail->next = nullptr;
            delete temp;
        }
        _size--;
    }

    void erase(const T &data)
    {
        node *temp = head, *prev;

        if (head->data == data)
        {
            pop_head();
            return;
        }
        else if (tail->data == data)
        {
            pop_tail();
            return;
        }

        while (temp && temp->data != data)
        {
            prev = temp;
            temp = temp->next;
        }

        if (!temp)
        {
            cout << "Value not in list!!\n\n";
            return;
        }

        if (temp == tail)
        {
            pop_tail();
            return;
        }

        temp->next->previous = temp->previous;
        prev->next = temp->next;
        delete temp;
        _size--;
    }

    bool empty()
    {
        return _size == 0;
    }

    T at_head()
    {
        if (!head)
            throw std::runtime_error("List is empty");

        return head->data;
    }

    T at_tail()
    {
        if (!head)
            throw std::runtime_error("List is empty");

        return tail->data;
    }

    bool contains(const T &val)
    {
        node *temp = head;
        while (temp)
        {
            if (temp->data == val)
            {
                return true;
            }
            temp = temp->next;
        }

        return false;
    }

    void clear()
    {
        node *temp = head;
        while (temp)
        {
            node *next = temp->next;
            delete temp;
            temp = next;
        }
        head = tail = nullptr;
        _size = 0;
    }

    // TODO : write a reverse funtion

    void print_reverse()
    {
        node *temp = tail;
        while (temp)
        {
            cout << temp->data << "<-";
            temp = temp->previous;
        }
        cout << "\n";
    }

    ~MyDll()
    {
        clear();
    }
};