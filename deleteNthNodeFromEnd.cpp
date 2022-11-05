#include <iostream>

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//simple solution using two passes over list
class simpleSolution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);
        deleteNode(&head,size-n);
        return head;
    }
    int getSize(ListNode* head){
        ListNode* current = head;
        int size = 0;
        while(current != nullptr){
            current = current->next;
            size++;
        }
        return size;
    }
    
    void deleteNode(ListNode** head,int index){
        ListNode* current = *head;
        if(index == 0){
            *head = (*head)->next;
            return;
        }
        while(index > 1){
            current = current->next;
            index--;
        }
        current->next = current->next->next;
    }

    void printList(ListNode* head){
        std::cout << "list:" << std::endl;
        ListNode* current = head;
        while(current != nullptr){
            std::cout << current->val << "-" ; 
            current = current->next;
        }
        std::cout <<  "end" << std::endl ; 
    }
};

//use two pointers, one will start shifted to the right by n so the difference between them will remain n
//then move both pointers until the right one reaches the end -> because the difference remains the same the left pointer
//will point right before the node we want to delete
class pointerSolution{
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *p = head, *q = head;
            while (n--) {
                q = q->next;
            }
            if (!q){
                return head->next;
            }
            while (q->next) {
                p = p->next;
                q = q->next;
            }
            ListNode* toDelete = p->next;
            p->next = p->next->next;
            return head;
    }
    void printList(ListNode* head){
        std::cout << "list:" << std::endl;
        ListNode* current = head;
        while(current != nullptr){
            std::cout << current->val << "-" ; 
            current = current->next;
        }
        std::cout <<  "end" << std::endl ; 
    }
};

int main(){
   ListNode four(4);
   ListNode three(3,&four);
   ListNode two(2,&three);
   ListNode one(1,&two);
   ListNode head(0,&one);

   simpleSolution s1;
   pointerSolution s2;
   //list before: 0-1-2-3-4-end
   ListNode* temp1 = s1.removeNthFromEnd(&head,1);
   s1.printList(temp1);
   //list before: 0-1-2-3-end
   ListNode* temp2 =s2.removeNthFromEnd(&head,2); 
   s2.printList(temp2); 
}