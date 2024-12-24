#pragma once
#include <iostream>

using namespace std;

class violation_list {
public:
    string violation;
    violation_list* next;

};

class Node {
public:
    int key;
    violation_list* violations;

    Node* left;
    Node* right;
    Node* parent;

    Node(int key_P) : key(key_P), left(nullptr), right(nullptr), parent(nullptr) {}

    void print_All()
    {
        violation_list* buff = violations;
        int count = 1;

        while (buff->next != nullptr)
        {
            cout << "\nНарушение №" << count << ": " << buff->violation;
            count++;
            buff = buff->next;
        }
    }
};

class BinaryTree {
private:
    Node* root;

    void remove(Node* node);

public:
    BinaryTree() : root(nullptr) {}

    Node* getRoot() const { return root; }

    Node* min(Node* node) const;

    Node* max(Node* node) const;

    Node* next(Node* node) const;

    Node* prev(Node* node) const;

    Node* search(Node* node, int key) const;

    void print(Node* node) const;

    void insert(int value);

    void remove_tree(Node* node);

    void remove_node(Node*& node);

    ~BinaryTree();
};
