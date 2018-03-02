#include "json.hpp"
#include <fstream>
#include <iostream>



using json = nlohmann::json;
using  namespace std;


class test {
public:
	test() {}

	string getId() {

		//std::ifstream i("1.json");
		//json j;
		//i >> j;
		//return j["Id"].get<std::string>();
		return "1";
	}
	string getPath() {
		std::ifstream i("1.json");
		json j;
		return j["path"].get<std::string>();
	}

	int getTotalFrames() {
		std::ifstream i("1.json");
		json j;
		return j["TotalFrames"].get<int>();
	}


	float getX() {
		ifstream i("1.json");
		json j;
		return j["object"]["X"].get<float>();
	}


	float getY() {
		ifstream i("1.json");
		json j;
		return j["object"]["X"].get<float>();
	}


	float getWidth() {
		std::ifstream i("1.json");
		json j;
		return j["object"]["Width"].get<float>();
	}



	float getHeight() {
		ifstream i("1.json");
		json j;
		return j["object"]["Height"].get<float>();
	}
};