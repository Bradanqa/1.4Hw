#include <iostream>
#include <fstream>
#include <string>

class Address {
public:
   Address(int userCount) {
      count = userCount;
   }

   void setCity(std::string userCity){
      city = userCity;
   }
   void setStreet(std::string userStreet){
      street = userStreet;
   }
   void setNumber(int userNumber){
      number = userNumber;
   }
   void setApp(int userApp){
      app = userApp;
   }

   std::string getOutputAddress() {
      fullAddress = city + ", " + street + ", " + std::to_string(number) + ", " + std::to_string(app) + "\n";
      return fullAddress;
   }

private:
   std::string city;
   std::string street;
   int number;
   int app;
   int count;

   std::string fullAddress;
};

int main() {
   int count;
   std::string temp;

   setlocale(LC_ALL, "Russian");

   std::ifstream userData("in.txt");
   userData >> count;

   Address **addresses = new Address*[count];
   for (int i = 0; i < count; i++) {
      addresses[i] = new Address(count);
   }

   for (int j = 0; j < count; j++) {
      userData >> temp;
      addresses[j]->setCity(temp);
      userData >> temp;
      addresses[j]->setStreet(temp);
      userData >> temp;
      addresses[j]->setNumber(std::stoi(temp));
      userData >> temp;
      addresses[j]->setApp(std::stoi(temp));
   }

   userData.close();

   std::ofstream data("out.txt");
   data << std::to_string(count) + "\n";

   for (int j = count; j > 0; j--) {
      data << addresses[j - 1]->getOutputAddress();
   }
   data.close();

   for (int i = 0; i < count; i++) {
      delete addresses[i];
   }

   return 0;
}