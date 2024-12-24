#include "BinaryTree.h"

int main()
{
	setlocale(LC_ALL, "Russian");
 
    BinaryTree tree;

    // ������ ������
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);

    cout << "������: ";
    tree.print(tree.getRoot());
    cout << "\n";

    Node* root = tree.getRoot();
    cout << "�������: " << tree.min(root)->key << "\n";
    cout << "��������: " << tree.max(root)->key << "\n";
    
    tree.print_indx(5);
    
    /*

    Node* searchNode = tree.search(root, 10);
    if (searchNode) {
        cout << "��������� ����� 10: " << (tree.next(searchNode) ? tree.next(searchNode)->key : -1) << "\n";
        cout << "���������� �� 10: " << (tree.prev(searchNode) ? tree.prev(searchNode)->key : -1) << "\n";
    }

    cout << "�������� ����� � ������ 10\n";
    tree.remove_tree(searchNode);

    cout << "\n\n������ ����� ��������: ";
    tree.print(tree.getRoot());*/

	return 0;
}