#include <iostream>
#include <string>
using namespace std;

string generateKey(string text, string key) {
    int textLen = text.size();
    int keyLen = key.size();
    
    for (int i = 0; i < textLen - keyLen; i++) {
        key.push_back(key[i % keyLen]);
    }
    return key;
}

string encrypt(string text, string key) {
    string encryptedText;
    
    for (int i = 0; i < text.size(); i++) {
        char x = (text[i] + key[i]) % 26;
        x += 'A';
        encryptedText.push_back(x);
    }
    
    return encryptedText;
}

string decrypt(string encryptedText, string key) {
    string decryptedText;
    
    for (int i = 0; i < encryptedText.size(); i++) {
        char x = (encryptedText[i] - key[i] + 26) % 26;
        x += 'A';
        decryptedText.push_back(x);
    }
    
    return decryptedText;
}

int main() {
    string text, key;
    
    cout << "Masukkan teks (huruf besar): ";
    cin >> text;
    cout << "Masukkan kata kunci (huruf besar): ";
    cin >> key;
    
    key = generateKey(text, key);

    string encryptedText = encrypt(text, key);
    cout << "Teks terenkripsi: " << encryptedText << endl;
    
    string decryptedText = decrypt(encryptedText, key);
    cout << "Teks terdekripsi: " << decryptedText << endl;
    
    return 0;
}
