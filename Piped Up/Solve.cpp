#include <iostream>
#include <vector>
#include <cstring>

int main() {
    // Chuỗi cần giải mã từ case 2
    unsigned char finalEncrypt[31] = {
        'l', ',', '\xE0', '\xEF', '\x8D', '`', '\xDC', 'u', '\x0D', '\xFF',
        '\xD6', 'Y', '\xF4', ']', '\xDE', '\x9B', '\xE3', '\xD7', 'R',
        '\x99', 'Z', '|', '\xA3', '\xC9', 'N', '\x1B', 'E', '\xE5',
        '\xC0', ')', '\x9A'
    };

    // Tạo bản sao của chuỗi để xử lý
    unsigned char result[31];
    memcpy(result, finalEncrypt, sizeof(finalEncrypt));

    std::cout << "Chuỗi gốc (hex): ";
    for (int i = 0; i < 31; i++) {
        printf("%02X ", (unsigned char)finalEncrypt[i]);
    }
    std::cout << std::endl;

    // Bước 1: Định nghĩa mảng encrypted từ case 5
    unsigned char encrypted[31] = {
        '{', '.', '\xF1', '\xEB', '\x8B', 'v', '\xE7', 'h', 'w', '\xA3',
        '\xEF', 'R', '\xF6', '<', '\xDA', '\xAA', '\xF6', '\xA7', 'C',
        '\xEB', '!', '$', '\xC3', '\x9C', '}', '\x08', '3', '\xB7',
        '\xF7', ',', '\xB4'
    };


   
    // Bước 2: Đảo ngược bước 5 - XOR với mảng encrypted
    std::cout << "Sau khi đảo ngược bước 5:" << std::endl;
    for (int i = 0; i < 31; i++) {
        result[i] ^= encrypted[i];
        printf("result[%d] = %02X (%c)\n", i, (unsigned char)result[i], isprint(result[i]) ? result[i] : '.');
    }

   

    // Bước 4: Đảo ngược bước 1 - XOR với v17
    std::cout << "\nSau khi đảo ngược bước 1:" << std::endl;
    unsigned char v17 = 0;
    unsigned char prev;
    for (int i = 0; i < 31; i++) {
        prev = result[i];
        result[i] ^= v17;
        v17 = prev;
        printf("result[%d] = %02X (%c)\n", i, (unsigned char)result[i], isprint(result[i]) ? result[i] : '.');
    }
    // Bước 3: Đảo ngược bước 3 - XOR với 0x56
    std::cout << "\nSau khi đảo ngược bước 3:" << std::endl;
    for (int i = 0; i < 31; i++) {
        result[i] ^= 0x56;
        printf("result[%d] = %02X (%c)\n", i, (unsigned char)result[i], isprint(result[i]) ? result[i] : '.');
    }

    // Hiển thị kết quả cuối cùng dưới dạng chuỗi
    std::cout << "\nKết quả giải mã: ";
    for (int i = 0; i < 31; i++) {
        if (isprint(result[i])) {
            std::cout << result[i];
        }
        else {
            printf("\\x%02X", (unsigned char)result[i]);
        }
    }
    std::cout << std::endl;

    // Hiển thị kết quả dưới dạng chuỗi nếu tất cả ký tự có thể in được
    bool all_printable = true;
    for (int i = 0; i < 31; i++) {
        if (!isprint(result[i]) && result[i] != 0) {
            all_printable = false;
            break;
        }
    }

    if (all_printable) {
        std::cout << "\nChuỗi giải mã: ";
        for (int i = 0; i < 31; i++) {
            if (result[i] == 0) break;  // Dừng ở ký tự null nếu có
            std::cout << result[i];
        }
        std::cout << std::endl;
    }

    return 0;
}