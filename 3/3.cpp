#include <iostream>
#include <vector>
#include <cstring>
class room {
private:
    int id;
    int price;
    char *cname{ nullptr };
    char *cid{ nullptr };

public:
    room(int id, int price) : id{id}, price{price} {}
    ~room(){
        delete[] cname;
        delete[] cid;
    }
    bool PrintInfoAndCheckOut(){
        if(cname == nullptr || cid == nullptr){
            std::cout << "Can't print: No infomation." << std::endl;
            return false;
        }
        std::cout << "ID:" << id << ", Price:" << price
                  << ", Name:" << cname << ", CID:" << cid << std::endl;
        delete[] cname;
        delete[] cid;
        cname = nullptr;
        cid = nullptr;
        return true;
    }
    bool BookRoom(const std::string& cname, const std::string& cid){
        if(this->cname != nullptr){
            std::cout << "Room " << id << " is occuppied!" << std::endl;
            return false;
        }
        this->cname = new char[cname.length() + 1];
        strcpy(this->cname, cname.c_str());
        this->cid = new char[cid.length() + 1];
        strcpy(this->cid, cid.c_str());
        return true;
    }
};
int main(){
    std::vector<std::vector<room>> rooms;
    for (int i = 0; i < 9; i++)
    {
        std::vector<room> floor;
        for (int j = 0; j < 20; j++)
        {
            floor.push_back(room{((i + 1) * 100 + j + 1), 2000});
        }
        rooms.push_back(floor);
    }

    rooms[3][15].BookRoom("Xiao Wang", "ABCD1234sadnanas");
    rooms[3][15].PrintInfoAndCheckOut();
    rooms[8][6].BookRoom("Xiao Zhang", "EFGH5678sadnanas");
    rooms[8][6].PrintInfoAndCheckOut();
    rooms[3][15].PrintInfoAndCheckOut();
}