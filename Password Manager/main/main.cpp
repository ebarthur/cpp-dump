#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

class Credential {
public:
    Credential(const std::string& username, const std::string& password)
        : username(username), password(password) {}

    const std::string& getUsername() const { return username; }
    const std::string& getPassword() const { return password; }

private:
    std::string username;
    std::string password;
};

class PasswordManager {
public:
    void addCredential(const Credential& credential) {
        credentials.push_back(credential);
    }

    const Credential* findCredential(const std::string& username) const {
        for (const auto& credential : credentials) {
            if (credential.getUsername() == username) {
                return &credential;
            }
        }
        return nullptr;
    }

    void displayCredentials() const {
        std::cout << "Saved Credentials:\n";
        std::cout << std::setw(15) << "Username" << std::setw(15) << "Password" << std::endl;
        std::cout << "-----------------------------\n";
        for (const auto& credential : credentials) {
            std::cout << std::setw(15) << credential.getUsername() << std::setw(15) << credential.getPassword() << std::endl;
        }
        std::cout << "-----------------------------\n";
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& credential : credentials) {
                file << credential.getUsername() << " " << credential.getPassword() << "\n";
            }
            std::cout << "Credentials saved to file: " << filename << std::endl;
        } else {
            std::cerr << "Error: Unable to open file for writing." << std::endl;
        }
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            credentials.clear();
            std::string username, password;
            while (file >> username >> password) {
                credentials.emplace_back(username, password);
            }
            std::cout << "Credentials loaded from file: " << filename << std::endl;
        } else {
            std::cerr << "Error: Unable to open file for reading." << std::endl;
        }
    }

private:
    std::vector<Credential> credentials;
};

int main() {
    PasswordManager passwordManager;
    passwordManager.loadFromFile("credentials.txt");

    while (true) {
        std::cout << "1. Add Credential\n";
        std::cout << "2. Find Credential\n";
        std::cout << "3. Display Credentials\n";
        std::cout << "4. Save to File\n";
        std::cout << "5. Exit\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string username, password;
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                passwordManager.addCredential(Credential(username, password));
                break;
            }
            case 2: {
                std::string username;
                std::cout << "Enter username to find: ";
                std::cin >> username;
                const Credential* credential = passwordManager.findCredential(username);
                if (credential) {
                    std::cout << "Password for " << username << ": " << credential->getPassword() << std::endl;
                } else {
                    std::cout << "Credential not found." << std::endl;
                }
                break;
            }
            case 3:
                passwordManager.displayCredentials();
                break;
            case 4:
                passwordManager.saveToFile("credentials.txt");
                break;
            case 5:
                passwordManager.saveToFile("credentials.txt");
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
