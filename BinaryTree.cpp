#include "BinaryTree.h"

void BinaryTree::remove(Node* node) {
    if (node) {
        remove(node->left);
        remove(node->right);
        delete node;
    }
}

Node* BinaryTree::min(Node* node) const {
    while (node && node->left)
    {
        node = node->left;
    }

    return node;
}

Node* BinaryTree::max(Node* node) const {
    while (node && node->right)
    {
        node = node->right;
    }

    return node;
}

Node* BinaryTree::next(Node* node) const {
    if (!node) return nullptr;

    Node* parent = nullptr;

    if (node->right) {
        return min(node->right);
    }

    parent = node->parent;

    while (parent && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

Node* BinaryTree::prev(Node* node) const {
    if (!node) return nullptr;

    Node* parent = nullptr;

    if (node->left) {
        return max(node->left);
    }

    parent = node->parent;

    while (parent && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

Node* BinaryTree::search(Node* node, int key) const
{
    while (node)
    {
        if (key == node->key)
        {
            return node;
        }

        node = (key < node->key) ? node->left : node->right;
    }

    return nullptr;
}

void BinaryTree::print(Node* node) const
{
    if (!node) return;

    print(node->left);

    cout << "\nНомер машины: " << node->key << " ";
    node->print_All();
    cout << "\n\n";

    print(node->right);

}

void BinaryTree::print_range(Node* node, int left, int right)
{
    if (!node) return;

    if (left <= node->key && node->key <= right)
    {
        cout << "\nНомер машины: " << node->key << " ";
        node->print_All();
        cout << "\n\n";
    }

    print_range(node->left, left, right);
    print_range(node->right, left, right);

}

void BinaryTree::print_indx(int num)
{
    Node* node = search(root, num);

    cout << "\nНомер машины: " << node->key << " ";
    node->print_All();
    cout << "\n\n";
}

void BinaryTree::insert(int value, string viol)
{
    try {
        if (search(root, value))
        {
            throw KeyAlreadyExists("\n\nКлюч который вы пытаетесь записать уже существует.\n\n");
        }
        Node* newNode = new Node(value, viol);
        Node* current = root;
        Node* parent = nullptr;

        if (!root) {
            root = newNode;

            return;
        }

        while (current) {
            parent = current;

            if (value < current->key) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        newNode->parent = parent;

        if (value < parent->key) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }
    }
    catch (KeyAlreadyExists& obj)
    {
        cout << obj.what();

        search(root, value)->add_viol(viol);
    }
}

void BinaryTree::remove_tree(Node* node) {
    if (!node) return;

    if (node == root) {
        remove(root);
        root = nullptr;
    }
    else {
        if (node->parent->left == node) {
            node->parent->left = nullptr;
        }
        else {
            node->parent->right = nullptr;
        }

        remove(node);
    }
}

void BinaryTree::remove_node(Node*& node)
{
    if (!node) return;

    if (!node->left)
    {
        Node* temp = node->right;

        if (temp)
        {
            temp->parent = node->parent;
        }

        delete node;

        node = temp;
    }
    else if (!node->right)
    {
        Node* temp = node->left;

        if (temp)
        {
            temp->parent = node->parent;
        }

        delete node;

        node = temp;
    }
    else
    {
        Node* next_node = next(node);

        node->key = next_node->key;

        remove_node(next_node);
    }
}

BinaryTree::~BinaryTree() {
    remove(root);
}



void Node::print_All()
{
    violation_list* buff = violations;
    int count = 1;

    if (buff->next == nullptr)
    {
        cout << "\nНарушение №" << count << ": " << buff->violation;
        count++;
    }
    else
    {
        while (buff != nullptr)
        {
            cout << "\nНарушение №" << count << ": " << buff->violation;
            count++;
            buff = buff->next;
        }
    }
}

void Node::add_viol(string viol)
{
    violation_list* buff = violations;
    violation_list* new_viol = new violation_list{ viol };

    while (buff->next != nullptr)
    {
        buff = buff->next;
    }

    buff->next = new_viol;
}