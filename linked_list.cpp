#include <iostream>
#include <stack>

using namespace std;

class single_linked
{
private:
    int size;
    struct _node
    {
        int val;
        _node *next;
    };
    _node* head;

public:
    single_linked()
    {
        size = 0;
        head = NULL;
    }
    _node* create_node(int val)
    {
        _node* new_node = new _node();
        new_node->val = val;
        return new_node;
    }
    void push_back(int val)
    {
        _node* temp = head, *new_node = create_node(val);
        size++;
        new_node->next = NULL;
        if(size == 1)
        {
            head = new_node;
            return;
        }
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
    void pop_back()
    {
        _node* temp = head;
        size--;
        if(size == 0)
        {
            delete head;
            head = NULL;
            return;
        }
        while(temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
    void print()
    {
        _node* temp = head;
        while(temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void push_front(int val)
    {
        _node* temp = head, *new_node = create_node(val);
        size++;
        new_node->next = head;
        head = new_node;
    }
    void pop_front()
    {
        _node* temp = head;
        size--;
        head = head->next;
        delete temp;
    }
    bool find_val(int val)
    {
        _node* temp = head;
        while(temp != NULL)
        {
            if(temp->val == val)
                return true;
            temp = temp->next;
        }
        return false;
    }
    void insert_after(int val, int targ)
    {
        if(!find_val(targ)) return;
        size++;
        _node* new_node = create_node(val);
        _node* temp = head;
        while(temp-> val != targ)
            temp = temp->next;
        new_node->next = temp->next;
        temp->next = new_node;
    }
    void remove_val(int val)
    {
        if(!find_val(val)) return;
        _node* temp = head;
        size--;
        if(head->val == val)
        {
            head = head->next;
            delete temp;
            return;
        }
        while(temp->next->val != val)
            temp = temp->next;
        _node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
    void reverse()
    {
        stack <int> stk;
        while(size != 0)
        {
            stk.push(head->val);
            pop_front();
        }
        while(!stk.empty())
        {
            push_back(stk.top());
            stk.pop();
        }
    }
};

int main()
{
    single_linked A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_front(5);
    A.push_front(6);
    A.insert_after(99, 5);
    // A.remove_val(5);

    A.print();
    A.reverse();
    A.print();
    return 0;
}