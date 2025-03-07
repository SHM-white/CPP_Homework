#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
class RoomInfo{
public:
    bool setId(const std::string& str){
        strcpy(id, str.c_str());
        return true;
    }
    bool setPrice(int i){ 
        if(i < 0 || i > 10000){
            std::cout << "Error: illegal price" << std::endl;
            return false;
        }
        price = i; 
        return true;
    }
    bool setBooked(bool b){ booked = b; return true; }
    bool setCname(const std::string& str){ strcpy(cname, str.c_str()); return true; }
    bool setCid(const std::string& str){ strcpy(cid, str.c_str()); return true; }
    char id[10];
    int  price;
    bool booked;
    char cname[20];
    char cid[20];
};
std::istream& operator>>(std::istream& is, RoomInfo& room){
    std::string id, cname, cid;
    int price;
    bool booked;
    is >> id >> price >> booked >> cname >> cid;
    room.setId(id) && room.setPrice(price) && room.setBooked(booked) && room.setCname(cname) && room.setCid(cid);
    return is;
}
std::ostream& operator<<(std::ostream& os, RoomInfo& room){
    os << room.id << " " << room.price << " " << room.booked << " " << std::ios::boolalpha << room.cname << " " << room.cid;
    return os;
}
bool SaveRooms(std::vector<RoomInfo>& rooms){
    std::fstream out{"22.bin", std::ios::out | std::ios::binary};
    if(!out.is_open()){ return false; }
    for(auto& i : rooms){
        out.write(reinterpret_cast<char*>(&i), sizeof(RoomInfo));
    }
    std::cout << "Save success" << std::endl;
    return true;
}
bool AddRoomInfo(std::vector<RoomInfo>& rooms){
    RoomInfo newInfo;
    std::cout << "id|price|booked(bool)|cname|cid" << std::endl;
    std::cin >> newInfo;
    rooms.push_back(newInfo);
    return SaveRooms(rooms);
}
void ShowAllRoomInfos(std::vector<RoomInfo>& rooms, bool ask = false){
    if(ask){
        std::cout << "Show all room infos?(y/n)";
        char in;
        std::cin >> in;
        if(std::tolower(in) != 'y'){
            return;
        }
    }
    std::cout << "index|id|price|booked(bool)|cname|cid" << std::endl;
    for (size_t i = 0; i < rooms.size(); i++)
    {
        std::cout << i << " " << rooms[i] << std::endl;
    }
}
bool DeleteRoomInfo(std::vector<RoomInfo>& rooms){
    ShowAllRoomInfos(rooms, true);
    std::cout << "Index:";
    int index;
    std::cin >> index;
    rooms.erase(rooms.begin() + index);
    return SaveRooms(rooms);
}
bool EditBookInfo(std::vector<RoomInfo>& rooms){
    ShowAllRoomInfos(rooms, true);
    std::cout << "Index | status" << std::endl;
    int index;
    bool status;
    std::cin >> index >> status;
    rooms[index].setBooked(status);
    return SaveRooms(rooms);
}
bool EditCustomInfo(std::vector<RoomInfo>& rooms){
    ShowAllRoomInfos(rooms, true);
    std::cout << "Index | cname | cid" << std::endl;
    int index;
    std::string cname, cid;
    std::cin >> index >> cname >> cid;
    rooms[index].setCname(cname);
    rooms[index].setCid(cid);
    return SaveRooms(rooms);
}
void FindByName(std::vector<RoomInfo>& rooms){
    std::string name;
    std::cin >> name;
    auto result = std::find_if(rooms.begin(), rooms.end(), [&](RoomInfo &info)
                 { return std::string(info.cname) == name; });
    if(result == rooms.end()){
        return;
    }
    std::cout << *result;
}
bool DeleteCustomInfo(std::vector<RoomInfo>& rooms){
    ShowAllRoomInfos(rooms, true);
    int index;
    std::cin >> index;
    auto& r = rooms[index];
    r.setBooked(false);
    r.setCname("");
    r.setCid("");
    return SaveRooms(rooms);
}
void CalculateRoomInfos(std::vector<RoomInfo>& rooms){
    int total = 0, booked = 0, livedIn = 0;
    for(auto& i : rooms){
        if(i.cid == ""){
            if(i.booked == true){
                booked++;
            }
        }
        else{
            livedIn++;
        }
        total++;
    }
    std::cout << "Total:" << total << " Booked:" << booked << " LivedIn:" << livedIn << std::endl;
}
int main(){
    std::vector<RoomInfo> rooms;
    std::ifstream input{"22.bin", std::ios::binary | std::ios::in};
    if(input.is_open()){
        while (!input.eof())
        {
            RoomInfo ri;
            input.read(reinterpret_cast<char*>(&ri), sizeof(RoomInfo));
            rooms.push_back(std::move(ri));
        }
    }
    input.close();
    char command;
    while (1)
    {
        std::cin >> command;
        switch (tolower(command))
        {
        case 'a':
            AddRoomInfo(rooms);
            break;
        case 'b':
            DeleteRoomInfo(rooms);
            break;
        case 'c':
            ShowAllRoomInfos(rooms);
            break;
        case 'd':
            EditBookInfo(rooms);
            break;
        case 'e':
            EditCustomInfo(rooms);
            break;
        case 'f':
            FindByName(rooms);
            break;
        case 'g':
            DeleteCustomInfo(rooms);
            break;
        case 'h':
            CalculateRoomInfos(rooms);
            break;
        case 'q':
            return 0;
        default:
            break;
        }
    }
    
}