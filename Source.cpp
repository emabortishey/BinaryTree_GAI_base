#include "BinaryTree.h"

int main()
{
	setlocale(LC_ALL, "Russian");
 
    BinaryTree tree;

    // Пример работы
    // заполнение с помощью инсертов
    tree.insert(20, "meeow");
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);

    // попытка вставить уже существующий ключ после которой выводится сообщение выброшенное исключением
    tree.insert(20, "bark");

    // проверка методов заданных заданием и плюс некоторых чисто
    // чтобы проверить правильно ли написанны базовые методы класса дерева

    cout << "Распечатка всей базы данных: ";
    tree.print(tree.getRoot());
    cout << "\n";

    Node* root = tree.getRoot();
    cout << "Минимум: " << tree.min(root)->key << "\n";
    cout << "Максимум: " << tree.max(root)->key << "\n";
    
    cout << "\n\nВывод по ключу 5: \n\n";

    tree.print_key(5);

    cout << "\n\nВывод в диапазоне ключей 5 - 16: \n\n";

    tree.print_range(root, 5, 16);


    // я не помню что это но на всякий пусть будет

    /* Node* searchNode = tree.search(root, 10);
    if (searchNode) {
        cout << "Следующий после 10: " << (tree.next(searchNode) ? tree.next(searchNode)->key : -1) << "\n";
        cout << "Предыдущий до 10: " << (tree.prev(searchNode) ? tree.prev(searchNode)->key : -1) << "\n";
    }

    cout << "Удаление ветки с корнем 10\n";
    tree.remove_tree(searchNode);

    cout << "\n\nДерево после удаления: ";
    tree.print(tree.getRoot());*/

	return 0;
}