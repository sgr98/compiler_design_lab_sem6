/**
 * CS2292 Lab 0
 *
 */
#include <iostream>
#include <chrono> 
#include <cstddef>
#include <cstdlib>
#include <ctime>

using namespace std::chrono;
using namespace std;

class Node {
    public:
      int data;
    Node *next;
};

class LinkedList {
    // LinkedList() {
    //     head = NULL;
    //     head = new Node();
    //     return;
    // }

    public:
        int size = 0;
        Node *head = new Node();

        void print_list() {
            cout << "\nPrinting new list..." << endl;
            Node *n = head;
            while (n != NULL) {
                cout << n->data << " ";
                n = n->next;
            }
        } 

        void append(int new_data) {
            struct Node *new_node = (struct Node * ) malloc(sizeof(struct Node));
            struct Node *last = head;

            if (head == NULL) {
                head->data = new_data;
                head->next = NULL;
            }
            else {
                new_node->data = new_data;
                new_node->next = NULL;

                while (last->next != NULL)
                    last = last->next;
                last->next = new_node;
            }
            size++;
        }
};

int main() {
  srand((unsigned) time(0));

  const int N = 10000;
  
  auto start = high_resolution_clock::now();

  LinkedList list;
  for(int i = 0; i < N; i++)
    list.append(rand());
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count() << endl;
  return 0;
}

