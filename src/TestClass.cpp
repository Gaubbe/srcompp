#include <iostream>
#include <json/json.h>
#include <srcompp/TestClass.h>

void TestClass::Test() {
  Json::Value root;
  root["test"] = "test";
  root["array"][0] = "lmao";
  root["array"][1] = "xd";
  root["array"][2] = "mdr";

  Json::Value obj;
  obj["prop"] = "objProperty";
  root["obj"] = obj;

  std::cout << root << std::endl;
}