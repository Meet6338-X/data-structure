#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int data1, node *next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};

class Stack
{
public:
    node *top;
    int size;

    Stack()
    {
        top = nullptr;
        size = 0;
    }

    void push(int val)
    {
        node *temp = new node(val);
        temp->next = top;
        top = temp;
        size++;
        cout << val << " pushed\n";
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack underflow\n";
            return;
        }
        node *temp = top;
        cout << temp->data << " popped\n";
        top = top->next;
        delete temp;
        size--;
    }

    void peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << top->data << endl;
    }

    void sizei()
    {
        cout << "Stack size: " << size << endl;
    }

    void display()
    {
        node *temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    // testing by gpt
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();
    s.peek();
    s.sizei();

    s.pop();
    s.display();
    s.peek();
    s.sizei();

    s.pop();
    s.pop();
    s.pop();
    return 0;
}

// copy
//  struct stackNode
//  {
//      int data;
//      stackNode *next;
//      int size;
//      stackNode(int d)
//      {
//          data = d;
//          next = NULL;
//      }
//  };
//  struct stack
//  {
//      stackNode *top;
//      int size;
//      stack()
//      {
//          top = NULL;
//          size = 0;
//      }
//      void stackPush(int x)
//      {
//          stackNode *element = new stackNode(x);
//          element->next = top;
//          top = element;
//          cout << "Element pushed" << "\n";
//          size++;
//      }
//      int stackPop()
//      {
//          if (top == NULL)
//          {
//              return -1;
//          }
//          int topData = top->data;
//          stackNode *temp = top;
//          top = top->next;
//          delete temp;
//          size--;
//          return topData;
//      }
//      int stackSize()
//      {
//          return size;
//      }
//      bool stackIsEmpty()
//      {
//          return top == NULL;
//      }
//      int stackPeek()
//      {
//          if (top == NULL)
//              return -1;
//          return top->data;
//      }
//      void printStack()
//      {
//          stackNode *current = top;
//          while (current != NULL)
//          {
//              cout << current->data << " ";
//              current = current->next;
//          }
//      }
//  };
//  int main()
//  {
//      stack s;
//      s.stackPush(10);
//      cout << "Element popped: " << s.stackPop() << "\n";
//      cout << "Stack size: " << s.stackSize() << "\n";
//      cout << "Stack empty or not? " << s.stackIsEmpty() << "\n";
//      cout << "stack's top element: " << s.stackPeek() << "\n";
//      return 0;
//  }