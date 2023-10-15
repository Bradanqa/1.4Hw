#include <iostream>
#include <fstream>
#include <string>

class Address {
public:
   Address(std::string city, std::string street, int number, int app) {
      this->city = city;
      this->street = street;
      this->number = number;
      this->app = app;
   }
   Address(){
      city = "0";
      street = "0";
      number = 0;
      app = 0;
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
      std::string fullAddress;
      fullAddress = city + ", " + street + ", " + std::to_string(number) + ", " + std::to_string(app) + "\n";
      return fullAddress;
   }

private:
   std::string city;
   std::string street;
   int number;
   int app;
};

int main() {
   int count;
   std::string temp;

   setlocale(LC_ALL, "Russian");

   std::ifstream userData("in.txt");
   userData >> count;

   Address *addresses = new Address[count];
   for (int i = 0; i < count; i++) {
      Address tempC;
      addresses[i] = tempC;
   }

   for (int j = 0; j < count; j++) {
      userData >> temp;
      addresses[j].setCity(temp);
      userData >> temp;
      addresses[j].setStreet(temp);
      userData >> temp;
      addresses[j].setNumber(std::stoi(temp));
      userData >> temp;
      addresses[j].setApp(std::stoi(temp));
   }

   userData.close();

   std::ofstream data("out.txt");
   data << std::to_string(count) + "\n";

   for (int i = 0; i < count - 1; i++) {
      int min = i;
      for (int j = i + 1; j < count; j++) {
         if (addresses[j].getFirstSym() < addresses[min].getFirstSym())
            min = j;
      }
      if (min != i)
         std::swap(addresses[min], addresses[i]);
   }

   for (int j = 0; j < count; j++) {
      data << addresses[j].getOutputAddress();
   }

   data.close();

   delete[] addresses;

   return 0;
}