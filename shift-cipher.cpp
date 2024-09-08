#include <iostream>
#include <string>

using namespace std;


void encrypt(string plain, int k) {
    string cipher = "";

    for (int i = 0; i < plain.length(); i++) {
        char ch = plain[i];

        if (isalpha(ch)) {  
            char offset = isupper(ch) ? 'A' : 'a';
            ch = (ch - offset + k) % 26 + offset;  
        }

        cipher += ch;  
    }

    cout << "Ciphertext: " << cipher << endl;
}


void decrypt(string cipher, int k) {
    string plain = "";

    for (int i = 0; i < cipher.length(); i++) {
        char ch = cipher[i];

        if (isalpha(ch)) {  
            char offset = isupper(ch) ? 'A' : 'a';
            ch = (ch - offset - k + 26) % 26 + offset;  
        }

        plain += ch; 
    }

    cout << "Decrypted Text: " << plain << endl;
}

int main() {
    string text;
    int pil, k;

    cout << "Masukan Text: ";
    getline(cin, text);  

    cout << "Masukan kunci (shift): ";
    cin >> k;

    cout << "Pilih opsi:\n1. Enkripsi\n2. Deskripsi\n";
    cin >> pil;

    if (pil == 1) {
        encrypt(text, k);  
    } else if (pil == 2) {
        decrypt(text, k);  
    } else {
        cout << "Opsi tidak valid!" << endl;  
    }

    return 0;
}
