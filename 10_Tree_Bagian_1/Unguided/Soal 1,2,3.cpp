#include <iostream>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init(){
    root = NULL;
}

bool isEmpty(){
    return root == NULL;
}

void buatNode(char data){
    if (isEmpty()){
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node){
    if (isEmpty()){
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } if (node->left != NULL){
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

Pohon *insertRight(char data, Pohon *node){
    if (isEmpty()){
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } if (node->right != NULL){
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

void update(char data, Pohon *node){
    if (isEmpty()){
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    } if (!node){
        cout << "\nNode yang ingin diganti tidak ada!" << endl;
        return;
    }
    char temp = node->data;
    node->data = data;
    cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
}

void retrieve(Pohon *node){
    if (isEmpty()){
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    } if (!node){
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nData node: " << node->data << endl;
}

void find(Pohon *node){
    if (isEmpty()){
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    } if (!node){
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nData Node: " << node->data << endl;
    cout << "Root: " << root->data << endl;
    cout << "Parent: " << (node->parent ? node->parent->data : '(tidak punya parent)') << endl;

    if (node->parent){
        if (node->parent->left == node && node->parent->right)
            cout << "Sibling: " << node->parent->right->data << endl;
        else if (node->parent->right == node && node->parent->left)
            cout << "Sibling: " << node->parent->left->data << endl;
        else
            cout << "Sibling: (tidak ada sibling)" << endl;
    }
}

void tampilkanChild(Pohon* node) {
    if (node->left) cout << "Child kiri: " << node->left->data << endl;
    else cout << "Tidak ada child kiri.\n";

    if (node->right) cout << "Child kanan: " << node->right->data << endl;
    else cout << "Tidak ada child kanan.\n";
}

void tampilkanDescendant(Pohon* node) {
    if (node) {
        if (node->left) {
            cout << node->left->data << " ";
            tampilkanDescendant(node->left);
        }
        if (node->right) {
            cout << node->right->data << " ";
            tampilkanDescendant(node->right);
        }
    }
}

bool is_valid_bst(Pohon* node, int min_val, int max_val) {
    if (node == NULL) return true;
    if (node->data <= min_val || node->data >= max_val) return false;
    return is_valid_bst(node->left, min_val, node->data) && 
           is_valid_bst(node->right, node->data, max_val);
}

int cari_simpul_daun(Pohon* node) {
    if (node == NULL) return 0;
    if (node->left == NULL && node->right == NULL) return 1;
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

Pohon* cariNode(Pohon* node, char data) {
    if (node == NULL) return NULL;
    if (node->data == data) return node;

    Pohon* foundNode = cariNode(node->left, data);
    if (foundNode == NULL) {
        foundNode = cariNode(node->right, data);
    }
    return foundNode;
}

void menu() {
    int choice;
    char data, parentData;
    Pohon *parentNode;

    do {
        cout << "\nMenu:\n";
        cout << "1. Buat Root Node\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Tampilkan Child Node\n";
        cout << "5. Tampilkan Descendant Node\n";
        cout << "6. Periksa Apakah BST\n";
        cout << "7. Hitung Simpul Daun\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Masukkan data untuk root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "Masukkan data untuk node kiri: ";
                cin >> data;
                cout << "Masukkan data parent: ";
                cin >> parentData;
                parentNode = cariNode(root, parentData);
                if (parentNode) insertLeft(data, parentNode);
                break;
            case 3:
                cout << "Masukkan data untuk node kanan: ";
                cin >> data;
                cout << "Masukkan data parent: ";
                cin >> parentData;
                parentNode = cariNode(root, parentData);
                if (parentNode) insertRight(data, parentNode);
                break;
            case 4:
                cout << "Masukkan data node untuk melihat child: ";
                cin >> data;
                parentNode = cariNode(root, data);
                if (parentNode) tampilkanChild(parentNode);
                break;
            case 5:
                cout << "Masukkan data node untuk melihat descendant: ";
                cin >> data;
                parentNode = cariNode(root, data);
                if (parentNode) tampilkanDescendant(parentNode);
                break;
            case 6:
                if (is_valid_bst(root, INT_MIN, INT_MAX)) {
                    cout << "Tree adalah BST yang valid.\n";
                } else {
                    cout << "Tree bukanlah BST yang valid.\n";
                }
                break;
            case 7:
                cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << endl;
                break;
            case 0:
                cout << "Keluar.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 0);
}

int main() {
    init();
    menu();
    return 0;
}