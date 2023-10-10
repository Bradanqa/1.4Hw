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

   std::string getFirstSym() {
      return city;
   }

   std::string getOutputAddress() {
      fullAddress = city + ", " + street + ", " + std::to_string(number) + ", " + std::to_string(app) + "\n";
      return fullAddress;
   }

private:
   std::string city;
   std::string street;
   int number = 0;
   int app = 0;
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

   for (int i = 0; i < count - 1; i++) {
      int min = i;
      for (int j = i + 1; j < count; j++) {
         if (addresses[j]->getFirstSym() < addresses[min]->getFirstSym())
            min = j;
      }
      if (min != i)
         std::swap(addresses[min], addresses[i]);
   }

   for (int j = 0; j < count; j++) {
      data << addresses[j]->getOutputAddress();
   }

   data.close();

   for (int i = 0; i < count; i++) {
      delete addresses[i];
   }

   return 0;
}