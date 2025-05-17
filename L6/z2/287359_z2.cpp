#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Node 
{
    int val;
    Node* left;
    Node* right;

    Node(int value) : val(value), left(0), right(0) {}
};

// (iii) Budowanie bardzo zbalansowanego drzewa z tablicy
Node* zbalansowane_drzewo(const vector<int>& tab, int start, int end) 
{
    if (start > end) return 0;
    int mid = (start + end) / 2;
    Node* root = new Node(tab[mid]);
    root->left = zbalansowane_drzewo(tab, start, mid - 1);
    root->right = zbalansowane_drzewo(tab, mid + 1, end);
    return root;
}

// (ii) Sklejanie dwóch drzew z wartoœci¹ w korzeniu
Node* sklejanie(Node* left, Node* right, int rootVal) 
{
    Node* root = new Node(rootVal);
    root->left = left;
    root->right = right;
    return root;
}

// (iv) Sprawdzenie czy wartoœæ istnieje w drzewie
bool zawieranie(Node* root, int value) 
{
    if (!root) 
	{
		return false;
	}
    if (root->val == value) 
	{
		return true;
	}
    return zawieranie(root->left, value) || zawieranie(root->right, value);
}

// (v) Wysokoœæ drzewa
int wysokosc(Node* root) 
{
    if (!root) return 0;
    return 1 + max(wysokosc(root->left), wysokosc(root->right));
}

// (vi) Liczba wêz³ów i liœci
void wezly_i_liscie(Node* root, int& nodes, int& leaves) 
{
    if (!root) return;
    nodes++;
    if (!root->left && !root->right)
        leaves++;
    wezly_i_liscie(root->left, nodes, leaves);
    wezly_i_liscie(root->right, nodes, leaves);
}

// (i) £adne wyœwietlanie drzewa (odwrócone 90°)
void wyswietlanie(Node* root, int indent = 0) 
{
    if (root != 0) 
	{
        wyswietlanie(root->right, indent + 4);
        if (indent)
            cout << setw(indent) << " ";
        	cout << root->val << "\n";
        wyswietlanie(root->left, indent + 4);
    }
}

// Funkcja g³ówna
int main() 
{
    int n1, n2, r, s;
    cout<<"podaj ilosc elementów pierwszego i drugiego drzewa:"<<endl;
    cin >> n1 >> n2 ;
    cout<<"podaj wartosc korzenia drzewa po sklejeniu tych dwoch drzew:"<<endl;
	cin>> r;
	cout<<"Podaj wartosci w pierwszym drzewie"<<endl;
    vector<int> tab1(n1), tab2(n2);
    for (int i = 0; i < n1; ++i)
	{
		cin >> tab1[i];
	} 
	cout<<"Podaj wartoœci w drugim drzewie"<<endl;
    for (int i = 0; i < n2; ++i)
	{
		cin >> tab2[i];
	} 
	cout<<"jakiej wartosc szukasz w skeljonym drzewie?"<<endl; 
	cin>> s;
    // Budowa dwóch bardzo zbalansowanych drzew
    Node* tree1 = zbalansowane_drzewo(tab1, 0, n1 - 1);
    Node* tree2 = zbalansowane_drzewo(tab2, 0, n2 - 1);

    // Sklejenie ich z wartoœci¹ r w korzeniu
    Node* merged = sklejanie(tree1, tree2, r);

    // Wyœwietlenie drzewa
    cout << "Drzewo:\n";
    wyswietlanie(merged);

    // Wysokoœæ
    int h = wysokosc(merged);
    cout << "\nWysokosc drzewa: " << h << "\n";

    // Liczba wêz³ów i liœci
    int nodes = 0, leaves = 0;
    wezly_i_liscie(merged, nodes, leaves);
    cout << "Liczba wezlow: " << nodes << "\n";
    cout << "Liczba lisci: " << leaves << "\n";

    // Czy zawiera s
    if(zawieranie(merged,s)==true)
    {
    	cout<<"Drezwo zawiera szukana liczbe"<<endl;
	}
	else
	{
		cout<<"Drzewo nie zawiera szukanej liczby"<<endl;
	}
    return 0;
}
