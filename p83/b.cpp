#include <iostream>
#include <vector>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
    void print()
    {
        ListNode *curr = this;
        while (curr != NULL)
        {
            cout << curr->val << "->";
            curr = curr->next;
        }
        cout << endl;
    }
    void push_back(int x)
    {
        ListNode *curr = this;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new ListNode(x);
    }
    void push_head(int x)
    {
        ListNode *n2 = this->next;
        this->next = new ListNode(this->val);
        this->next->next = n2;
        this->val = x;
    }
    void push_back(std::vector<int> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            this->push_back(v[i]);
        }
    }
};

class Solution
{
public:
    ListNode *removeDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        for (auto i = head; i->next != NULL; i = i->next)
        {
            auto j = i->next;
            while (i->val == j->val)
            {
                if (j->next == NULL)
                {
                    i->next = NULL;
                    return head;
                }
                j = j->next;
            }
            i->next = j;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution sol = Solution();

    auto l1 = ListNode(0);
    l1.push_back(std::vector<int>{1, 1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5});
    l1.print();
    auto l2 = sol.removeDuplicates(&l1);
    l2->print();
    sol.removeDuplicates(nullptr);

    return 0;
}
