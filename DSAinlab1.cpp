//22520468
//Nguyen Huy Hoang
#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;
    Node(int value) : data(value), next(nullptr) {}
};

class SingleLinkedList {
public:
    Node* head;
    SingleLinkedList() : head(nullptr) {}

    void addNode(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "error";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getLength(Node* temp) {
        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    void getMiddle() {
        Node* temp = head;
        int length = getLength(temp);
        int mid_index = length / 2;
        Node* prev = nullptr;
        temp = head; // Reset temp to head for finding middle
        while (mid_index--) {
            prev = temp;
            temp = temp->next;
        }
        if (length % 2 == 0) {
            cout << "Middle nodes: " << prev->data << " and ";
        }
        cout << temp->data << endl; // Output the middle element
    }

    Node* mergeSortedLists(Node* list1, Node* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        Node* dummy = new Node(0);
        Node* current = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->data <= list2->data) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1 != nullptr) current->next = list1;
        if (list2 != nullptr) current->next = list2;

        return dummy->next;
    }

   
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
        	// tuyet dinh reverse
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
 void removeDuplicates() {
        if (head == nullptr) return;

        Node* current = head;
        while (current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* temp = current->next; // Store the node to be deleted
                current->next = current->next->next; // Bypass the duplicate
                delete temp; // Free memory
            } else {
                current = current->next; // Move to the next node
            }
        }
    }
    bool isPalindrome() {
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            Node* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        if (fast != nullptr) {
            slow = slow->next;
        }

        while (prev != nullptr && slow != nullptr) {
            if (prev->data != slow->data) {
                return false;
            }
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }

    void search(int value) {
        Node* temp = head;
        int count=1;
        bool checkflag=false;
        while (temp != nullptr) {
            if (temp->data == value) {
              	cout<<count<<" "<<endl;
              	checkflag=true;
			    // Return the address of the node found
            }
            temp = temp->next;
            count++;
        }
        if(!checkflag){
        	cout<<"Not found"<<endl;
		}
    // Value not found
    }
      void GetIntersection(SingleLinkedList L1) {
        Node* Cur = head;
        bool found = false;
        cout << "Intersection: ";
        while (Cur != nullptr) {
            Node* Cur1 = L1.head;
            while (Cur1 != nullptr) {
                if (Cur->data == Cur1->data) {
                    cout << Cur->data << " ";
                    found = true;
                }
                Cur1 = Cur1->next;
            }
            Cur = Cur->next;
        }
        if (!found) {
            cout << "No intersection";
        }
        cout << endl;
    }
};


class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() : head(nullptr) {}

    void addNode(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "empty";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void checkCircular() {
        if (head == nullptr) {
            cout << "This is not a circular linked list." << endl;
            return;
        }
        Node* temp = head;
        do {
            temp = temp->next;
            if (temp == head) {
                cout << "This is a circular linked list." << endl;
                return;
            }
        } while (temp != nullptr);
        cout << "This is not a circular linked list." << endl;
    }
};

int main() {
    SingleLinkedList list;
    CircularLinkedList Clist;
    SingleLinkedList list1, list2;
    Node* mergedList = nullptr;

    cout << "Enter a linked list (end with -1):" << endl;
    while (true) {
        int x;
        cin >> x;
        if (x == -1) break;
        list.addNode(x);
        Clist.addNode(x);
    }

    int choice;
    while (true) {
        cout << "Choose an operation:\n";
        cout << "1. Find Middle Node\n";
        cout << "2. Detect Cycle\n";
        cout << "3. Combine Linked Lists\n";
        cout << "4. Find Intersection\n";
        cout << "5. Reverse Linked List\n";
        cout << "6. Eliminate Duplicates\n";
        cout << "7. Check Palindrome\n";
        cout << "8. Search for Nodes\n";
        cout << "9. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                list.getMiddle();
                break;
            case 2:
                Clist.checkCircular();
                break;
            case 3: {
	                cout << "Add sorted list 1 (end with -1):" << endl;
	                while (true) {
	                    int x;
	                    cin >> x;
	                    if (x == -1) break;
	                    list1.addNode(x);
	                }
	                cout << "Add sorted list 2 (end with -1):" << endl;
	                while (true) {
	                    int y;
	                    cin >> y;
	                    if (y == -1) break;
	                    list2.addNode(y);
	                }
	                mergedList = list1.mergeSortedLists(list1.head, list2.head);
	                cout << "Merged list: ";
	                Node* temp = mergedList;
	                while (temp != nullptr) {
	                    cout << temp->data << " ";
	                    temp = temp->next;
	                }
	                cout << endl;
	                break;
            }
            case 4:
			{
			cout << "Enter a new linked list for intersection (end with -1):" << endl;
                while (true) {
                    int x;
                    cin >> x;
                    if (x == -1) break;
                    list2.addNode(x);
                }
                list.GetIntersection(list2);
                break;
            }
            case 5: {
                list.reverse();
                cout << "Reversed list: ";
                list.display();
                break;
            }
            case 6:
                {
                list.removeDuplicates(); 
                cout << "List after removing duplicates: ";
                list.display(); 
                break;
				}
            case 7:
                if (list.isPalindrome()) {
                    cout << "The linked list is a palindrome." << endl;
                } else {
                    cout << "The linked list is not a palindrome." << endl;
                }
                break;
            case 8: {
                int value;
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                
                break;
            }
            case 9:
                exit(0);
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}

