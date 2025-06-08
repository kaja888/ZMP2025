#include <iostream>
#include <vector>
using namespace std;

//Definicja Wêz³a 
struct Node 
{
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(0), right(0) {}
};

// Klasa BST 
class BST 
{
private:
    Node* root;

    Node* wstawianie(Node* node, int value) 
	{
        if (!node) return new Node(value);
        if (value < node->value)
            node->left = wstawianie(node->left, value);
        else
            node->right = wstawianie(node->right, value);
        return node;
    }

    bool izomorfizm(Node* n1, Node* n2)  
	{
        if (!n1 && !n2) return true;
        if (!n1 || !n2) return false;
        return izomorfizm(n1->left, n2->left) && izomorfizm(n1->right, n2->right);
    }

    Node* dodawanie(Node* n1, Node* n2) 
	{
        if (!n1 || !n2) return 0;
        Node* newNode = new Node(n1->value + n2->value);
        newNode->left = dodawanie(n1->left, n2->left);
        newNode->right = dodawanie(n1->right, n2->right);
        return newNode;
    }

    Node* odejmowanie(Node* n1, Node* n2) 
	{
        if (!n1 || !n2) return 0;
        Node* newNode = new Node(n1->value - n2->value);
        newNode->left = odejmowanie(n1->left, n2->left);
        newNode->right = odejmowanie(n1->right, n2->right);
        return newNode;
    }

    void wyswietlanie(Node* node, ostream& os)  
	{
        if (!node) return;
        wyswietlanie(node->left, os);
        os << node->value << " ";
        wyswietlanie(node->right, os);
    }

    // Szukaj indeksu (n-ty element)
    bool ind(Node* node, int& index, int target, int& result)
	 {
        if (!node) return false;
        if (ind(node->left, index, target, result)) return true;
        if (index == target) {
            result = node->value;
            return true;
        }
        index++;
        if (ind(node->right, index, target, result)) return true;
        return false;
    }

public:
    BST() : root(0) {}

    void wstawianie(int value) 
	{
        root = wstawianie(root, value);
    }

    bool izomorfizm(const BST& other) 
	 {
        return izomorfizm(this->root, other.root);
    }

    // Przeci¹¿enie operatorów
    BST operator+(const BST& other) 
	{
        BST result;
        result.root = dodawanie(this->root, other.root);
        return result;
    }

    BST operator-(const BST& other) 
	{
        BST result;
        result.root = odejmowanie(this->root, other.root);
        return result;
    }

    // Przeci¹¿enie operatora []
    int operator[](int index)  
	{
        int counter = 0;
        int result = -1;
        ind(root, counter, index, result);
        return result;
    }

    // Wypisywanie drzewa
    friend ostream& operator<<(ostream& os, BST& tree) 
	{
        tree.wyswietlanie(tree.root, os);
        return os;
    }
};
int main() {
    int n1, n2;
    cout<<"Podaj liczbe wezlow w pierwszym drzewie:"<<endl;
    cin >> n1;
    BST t1;
    cout<<"Podaj wartosci w wezlach pierwszego drzewa:"<<endl;
    for (int i = 0; i < n1; ++i)
	 {
        int x;
        cin >> x;
        t1.wstawianie(x);
    }
	cout<<"Podaj ilosc wezlow w drugim drzewie:"<<endl;
    cin >> n2;
    BST t2;
    cout<<"Podaj wartosci w wezlach drugiego drzewa:"<<endl;
    for (int i = 0; i < n2; ++i) 
	{
        int x;
        cin >> x;
        t2.wstawianie(x);
    }

    if (t1.izomorfizm(t2)) 
	{
        cout << "Drzewa sa izomorficzne.\n";

        BST suma = t1 + t2;
        BST roznica = t1 - t2;

        cout << "Suma drzew (inorder): " << suma << endl;
        cout << "Roznica drzew (inorder): " << roznica << endl;

        cout << "Elementy drzewa sumy przez operator []:\n";
        for (int i = 0; i < n1; ++i) 
		{
            cout << "sum[" << i << "] = " << suma[i] << endl;
        }

    } 
	else 
	{
        cout << "Drzewa NIE sa izomorficzne.\n";
    }

    return 0;
}

