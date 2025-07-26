#include <iostream>

using std::cout;

template <typename T>
class MyList
{
private:
  struct node
  {
    T data;
    node *next;
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
    return temp;
  }

public:
  MyList()
  {
    head = nullptr;
    tail = nullptr;
    _size = 0;
  }

  void push_tail(T data)
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
      tail->next = temp;
      tail = temp;
    }
    _size++;
  }

  void push_head(T data)
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

  void insert(int position, T data)
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
      for (int i = 0; i < position - 1; i++)
      {
        temp = temp->next;
      }
      n1->next = temp->next;
      temp->next = n1;
    }
    _size++;
  }

  void pop_head()
  {
    if (!head)
    {
      cout << "Empty List\n";
      return;
    }

    node *temp;
    temp = head;
    head = head->next;
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
      node *temp = head;
      while (temp->next->next)
      {
        temp = temp->next;
      }
      delete temp->next;
      temp->next = nullptr;
      tail = temp;
    }
    _size--;
  }

  void erase(T data)
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

    if (head)
    {
      return head->data;
    }
  }

  T at_tail()
  {
    if (!head)
      throw std::runtime_error("List is empty");

    if (head)
    {
      return tail->data;
    }
  }

  bool contains(T val)
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

  void reverse()
  {
    if (!head)
    {
      cout << "List is Empty\n";
      return;
    }

    node *prev, *curr, *forward;
    curr = head;
    prev = nullptr;
    while (curr)
    {
      forward = curr->next;
      curr->next = prev;
      prev = curr;
      curr = forward;
    }

    head = prev;
  }

  ~MyList()
  {
    clear();
  }
};