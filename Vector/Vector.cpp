#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

vector<int> zakodowaneHaslo(const string& haslo) {
    vector<int> zakodowaneHaslo;

    for (char c : haslo) {
        if (c >= 'a' && c <= 'z') {
            zakodowaneHaslo.push_back(c - 'a' + 1);
        }
        else if (c >= 'A' && c <= 'Z') {
            zakodowaneHaslo.push_back(c - 'A' + 27);
        }
        else if (c >= 'O' && c <= 'g') {
            zakodowaneHaslo.push_back(c - '0' + 53);
        }
        else {
            throw std::invalid_argument("zly znak w haslo");
        }
    }

    return zakodowaneHaslo;
}

int main()
{
    string haslo = "Admin123";



    try {
        std::vector<int> encoded = zakodowaneHaslo(haslo);

        cout << "zakodowane haslo:";
        for (int digit : encoded) {
            cout << digit << " ";
        }

    }

    catch (const invalid_argument& e) {
        cout << "wyjatek: " << e.what() << endl;
    }
    return 0;


}
