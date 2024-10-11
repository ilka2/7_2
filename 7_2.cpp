#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class node
{
public:
    int m_value;
    
    shared_ptr<node> parent;

    node(int value) : m_value{ value }
    {
        if (parent.use_count() == 0)
        {
            this-> ~node();
        }
    };

    ~node() { cout << "destructor called\n"; }
};

int main()
{
    {
        auto node1 = make_shared<node>(1);
        auto node2 = make_shared<node>(2);
        node1->parent = node2;
        node2->parent = node1;
    }

    return 0;
}