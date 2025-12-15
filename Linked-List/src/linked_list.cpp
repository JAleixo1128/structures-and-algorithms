#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList(){
    this -> head = nullptr;
    this -> size = 0;
}

LinkedList::LinkedList(int data){
    this -> head = new Node(data);
    this -> size = 1;
}

LinkedList::LinkedList(std::vector<int> vec){
    this -> head = new Node(vec[0]);
    int vec_size = 0;
    for(int i =1; i<vec.size(); i++){
        push_back(vec[i]);
        vec_size++;
    }
}

LinkedList::~LinkedList(){

}

void LinkedList::push_front(int data){
    if (head == nullptr) {
        head = new Node(data);
        head->next = nullptr;
        size++;
        return;
    }

    Node *temp = new Node(data);
    temp -> next = head;
    this -> head = temp;
    size++;
}

void LinkedList::push_back(int data){
    if (head == nullptr) {
        head = new Node(data);
        size++;
        return;
    }

    Node *temp = head;
    Node *last = new Node(data);

    while(temp -> next != nullptr){
        temp = temp -> next;
    }
    temp -> next = last;
    size++;
}

void LinkedList::insert(int data, int idx){
    if (head == nullptr) {
        head = new Node(data);
        head->next = nullptr;
        size++;
        return;
    }

    int current = 0;
    Node *temp = head;

    if(temp == nullptr){
        Node* temp2 = new Node(data);
        temp2 -> next = nullptr;  
        head = temp2;
        size++;
    }

    while(temp -> next != nullptr){
        if(current == idx-1){
            break;
        }    
        current++;
        temp = temp -> next;
    }  

    if(idx >= this -> size){
        Node* temp2 = new Node(data);
        temp2 -> next = temp -> next;
        temp -> next = temp2;

    } else if(idx == 0){
        Node* temp2 = new Node(data);
        temp2 -> next = head;
        head = temp2;
    } else {
        Node *temp2 = new Node(data);
        temp2 -> next = temp->next;
        temp -> next = temp2;  
    }
}

void LinkedList::remove(int data){
    if (head == nullptr) {
        return;
    }
    if (head -> data == data){
        Node* temp2 = head;
        head = temp2 -> next;
        size--;
        return;
    }
    Node *prevtemp = nullptr;
    Node *temp = head;
    if (head != nullptr){
        while(temp != nullptr){
            if(temp -> data == data){
                if(prevtemp != nullptr){
                    prevtemp -> next = temp -> next;
                } else {
                    head = temp -> next;
                }
                size--;   
                break; 
            } 
            prevtemp = temp;
            temp = temp -> next;  
        }
        return;     
    }
}

bool LinkedList::contains(int data){
    if (head == nullptr) {
        head = new Node(data);
        head->next = nullptr;
    }

    Node *temp = head;

    while(temp != nullptr){
        if (temp -> data == data){
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

int LinkedList::get_size(){
    return this->size;
}

std::string LinkedList::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while(tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}

