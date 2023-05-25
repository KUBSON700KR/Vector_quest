#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

vector<int> zakodowaneHaslo(const string& haslo) {
    vector<int> zakodowaneHaslo;

    for (char c : haslo) {
        int kod;
        if (c >= 'a' && c <= 'z') {
            kod = c - 'a' + 1;
        }
        else if (c >= 'A' && c <= 'Z') {
            kod = c - 'A' + 27;
        }
        else if (c >= '0' && c <= '9') {
            kod = c - '0' + 53;
        }
        else {
            throw invalid_argument("zly znak w haslo");
        }
        zakodowaneHaslo.push_back(kod);
    }

    return zakodowaneHaslo;
}

int main() {
    string haslo = "Admin123";

    try {
        vector<int> zakodowane = zakodowaneHaslo(haslo);

        cout << "Zakodowane haslo: ";
        for (int digit : zakodowane) {
            cout << digit << " ";
        }
        cout << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Wyjatek: " << e.what() << endl;
    }

    return 0;
}
