#pragma once
#include <iostream>
#include <exception>

using namespace std;

// решила создать отдельный класс в виде двусвязного списка под
// список нарушений чтобы не делать обычный массив строк
class violation_list {
public:
    // обьект класса стринг
    string violation;
    // указатель на следующий для цепного соединения
    violation_list* next;

    // конструкторы
    violation_list() : violation("none"), next(nullptr) { }
    explicit violation_list(string viol) : violation( viol ) { }
    violation_list(string viol, violation_list* prev) : violation( viol ), next( prev ) { }

    // не помню для чего я перегружала оператор присваивания
    // но решила оставить, потому что не помню использовала ли в коде
    violation_list& operator=(violation_list& ptr);
};

class Node {
public:
    // ключ хранящий номер машины (не заморачивалась на счёт того
    // чтобы сделать его строчным чтобы было по канонам
    // содержания букв в номерах потому что лень было исправлять когда поняла
    int key;
    // указатель на список нарушений (на первый элемент по сути)
    violation_list* violations;

    Node* left;
    Node* right;
    Node* parent;

    explicit Node(int key_P) : key{ key_P }, violations{ new violation_list{} }, left(nullptr), right(nullptr), parent(nullptr) { }
    Node(int key_P, string viol) : key{ key_P }, violations{ new violation_list{viol} }, left(nullptr), right(nullptr), parent(nullptr) { }

    // вывод всех нарушений 
    void print_All() const;

    // добавление нарушения к существующему ключу
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

    /////// НАЧАЛО МЕТОДОВ ОГЛАШЕННЫХ ЗАДАНИЕМ \\\\\\\

    // вывод всего дерева
    void print(Node* node) const;

    // вывод в диапазоне
    void print_range(Node* node, int left, int right) const;

    // вывод определенного элемента по клбчу
    void print_key(int num) const;

    /////// КОНЕЦ МЕТОДОВ ОГЛАШЕННЫХ ЗАДАНИЕМ \\\\\\\

    void insert(int value, string viol = "none");

    void remove_tree(Node* node);

    void remove_node(Node*& node);

    ~BinaryTree();
};

// кастомный класс созданный как дочерний для класса
// экзепшион (мне лень было создавать свой, поэтому использовала библиотеку)
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