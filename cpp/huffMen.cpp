#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    char ch;
    int fre;
    struct node *left = NULL;
    struct node *right = NULL;
};

struct greaters {
    bool operator()(const struct node *a, const struct node *b) {
            return a->fre > b->fre;
    }
};

typedef struct node nd;

void printData(vector<nd*> arr) {
    cout << "data is given :: " << endl;
    for (int i = 0; i < arr.size(); ++i) {
        cout << "\tchar is :: " << arr[i]->ch << " fre is :: " << arr[i]->fre << endl;
    }
}

vector<nd*> del(vector<nd*> arr) {
    arr[0] = arr[arr.size() - 1];
    arr.pop_back();
    make_heap(arr.begin(), arr.end(), greaters());
    return arr;
}

vector<nd*> insert(vector<nd*> arr, nd *cur) {
    arr.push_back(cur);
    make_heap(arr.begin(), arr.end(), greaters());
    return arr;
}

void tree(nd* head) {
    if (head == NULL)
        return;
    cout << "ch is :: " << head->ch << " fre is :: " << head->fre << endl;
    tree(head->left);
    tree(head->right);
}

int main () {
    vector<nd*> data;
    int temp = 50;
    for (int i = 0; i < 5; ++i) {
        nd *cur = (nd *)malloc(sizeof(nd));
        cur->fre = temp;
        temp /= 2;
        cur->ch = 65 + i;
        cur->right = cur->left = NULL;
        data.push_back(cur);
    }
    make_heap(data.begin(), data.end(), greaters());

    printData(data);
    for (int i = 0; i < 4; i ++ ) {
        nd *cur = (nd *)malloc(sizeof(nd));
        cur->left = data[0];
        data = del(data);
        cur->right = data[0];
        data = del(data);
        cur->fre = cur->left->fre + cur->right->fre;
        data = insert(data, cur);
    }

    tree(data[0]);
    return 0;
}
