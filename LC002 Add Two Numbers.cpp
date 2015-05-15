// #include <stdio.h> 

//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
//  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum;
        sum = new ListNode(l1->val + l2->val);
        ListNode* p = sum;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 != NULL || l2 != NULL || p->val > 9)
        {
            p->next = new ListNode(p->val / 10);
            p->val %= 10;
            p = p->next;


            if(l1)
            {
                p->val += l1->val;
                l1 = l1->next;
            }

            if(l2)
            {
                p->val += l2->val;
                l2 = l2->next;
            }
        }
        
        return sum;
    }
};

// ListNode* link(int n)
// {
//     ListNode* num = new ListNode(n);

//     for(ListNode* p = num; p->val > 9; p = p->next)
//     {
//         p->next = new ListNode(p->val / 10);
//         p->val %= 10;
//     }
//     return num;
// }

// void printl(ListNode* num)
// {
//     printf("%d", num->val);
//     while(num->next)
//     {
//         num = num->next;
//         printf(" -> %d", num->val);
//     }
//     printf("\n");
// }

// int main()
// {
//     Solution s;
//     ListNode* num = s.addTwoNumbers(link(342), link(465));
//     printl(num);
// }
