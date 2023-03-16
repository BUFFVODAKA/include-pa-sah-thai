//v.3
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct product {
    string name;
    double price ;
    vector<string> people;
};

int main() {
    vector<product> productz;
    vector<string> people;
    string input;
    cout << "กรุณใส่เป็นภาษาอังกฤษเพื่อความเสถียรของของโปรเเกรม" << endl ;

    // 1. ให้ผู้ใช้ใส่รายชื่อคนที่หารค่าอาหาร เมื่อใส่ครบให้พิมพ์1
    while (true) {
        cout << "ใส่รายชื่อผู้มีส่วนร่วมทั้งหมด(พิมพ์ '1' เมื่อใส่รายชื่อครบ): ";
        getline(cin, input);
        if (input == "1") {
            break;
        }
        people.push_back(input);
    }

    // 2. ใส่ชื่ออาหาร, ราคาอาหาร, ชื่อคนที่มีส่วนร่วมกับอาหาร, และถ้าจะเพิ่มเมนูกด 1 ไม่เพิ่มกด 2
    while (true) {
        string product_name;
        double product_price;
        vector<string> product_people;
        cout << "ใส่ชื่อสินค้า: ";
        getline(cin, product_name);
        cout << "ใส่ราคาสินค้า: ";
        cin >> product_price;
        cin.ignore();
        while (true) {
            cout << "ใส่รายชื่อผู้มีส่วนร่วมกับ" << product_name << "(พิมพ์ '1' เมื่อใส่รายชื่อครบ): ";
            getline(cin, input);
            if (input == "1") {
                break;
            }
            product_people.push_back(input);
        }
        productz.push_back({product_name, product_price, product_people});
        cout << "พิมพ์ 1 เพื่อเพิ่มรายการสินค้า พิมพ์ 2 เพื่อสรุปราคา: ";
        getline(cin, input);
        if (input == "2") {
            break;
        }
    }

    // 3. คำนวณราคาของแต่ละคนที่ต้องจ่าย
    double total_product_price = 0;
    for (string person : people) {
        double total_price = 0;
        for (product product : productz) {
            if (find(product.people.begin(), product.people.end(), person) != product.people.end()) {
                total_price += product.price / product.people.size();
                total_product_price = total_product_price + (product.price / product.people.size())  ;
            }
        }
        cout << person << " มียอดชำระ " << total_price << " บาท" << endl;
    }
    cout << "ราคารวมทั้งสิ้นของสินค้าทั้งหมด: " << total_product_price << " บาท" << endl;
    cout << "ขอบคุณที่เข้ามาใช้โปรเเกรมของเรา" << endl;

    return 0;
}