#pragma once
#include <iostream>
#include <exception>

using namespace std;

// ������ ������� ��������� ����� � ���� ����������� ������ ���
// ������ ��������� ����� �� ������ ������� ������ �����
class violation_list {
public:
    // ������ ������ ������
    string violation;
    // ��������� �� ��������� ��� ������� ����������
    violation_list* next;

    // ������������
    violation_list() : violation("none"), next(nullptr) { }
    explicit violation_list(string viol) : violation( viol ) { }
    violation_list(string viol, violation_list* prev) : violation( viol ), next( prev ) { }

    // �� ����� ��� ���� � ����������� �������� ������������
    // �� ������ ��������, ������ ��� �� ����� ������������ �� � ����
    violation_list& operator=(violation_list& ptr);
};

class Node {
public:
    // ���� �������� ����� ������ (�� �������������� �� ���� ����
    // ����� ������� ��� �������� ����� ���� �� �������
    // ���������� ���� � ������� ������ ��� ���� ���� ���������� ����� ������
    int key;
    // ��������� �� ������ ��������� (�� ������ ������� �� ����)
    violation_list* violations;

    Node* left;
    Node* right;
    Node* parent;

    explicit Node(int key_P) : key{ key_P }, violations{ new violation_list{} }, left(nullptr), right(nullptr), parent(nullptr) { }
    Node(int key_P, string viol) : key{ key_P }, violations{ new violation_list{viol} }, left(nullptr), right(nullptr), parent(nullptr) { }

    // ����� ���� ��������� 
    void print_All() const;

    // ���������� ��������� � ������������� �����
    void add_viol(string viol);
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

    /////// ������ ������� ���������� �������� \\\\\\\

    // ����� ����� ������
    void print(Node* node) const;

    // ����� � ���������
    void print_range(Node* node, int left, int right) const;

    // ����� ������������� �������� �� �����
    void print_key(int num) const;

    /////// ����� ������� ���������� �������� \\\\\\\

    void insert(int value, string viol = "none");

    void remove_tree(Node* node);

    void remove_node(Node*& node);

    ~BinaryTree();
};

// ��������� ����� ��������� ��� �������� ��� ������
// ��������� (��� ���� ���� ��������� ����, ������� ������������ ����������)
class KeyAlreadyExists : public exception
{
    const char* error;
public:
    KeyAlreadyExists(const char* text) : error{ text } { };

    virtual const char* what() const noexcept override final
    {
        return error;
    }
};