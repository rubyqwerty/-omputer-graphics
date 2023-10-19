#pragma once
#include <fstream>
#include <vector>
#include <iostream>
// include headers that implement a archive in simple text format

#include <boost/archive/binary_iarchive.hpp> // Двоичная сериализация
#include <boost/archive/binary_oarchive.hpp> // Двоичная сериализация
#include <boost/serialization/vector.hpp> // Сериализованный контейнер STL для импорта
#include<boost/serialization/map.hpp> 
#include <boost/json.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/algorithm/string/replace.hpp>
using namespace std;

class ContainerZBuffer {
public:
	void Save(vector<vector<vector<double>>> a) {
	
		boost::json::value jv = boost::json::value_from(a);
		string g = boost::json::serialize(jv);
		boost::system::error_code error;
		boost::filesystem::create_directories("animation", error);
		assert(!error);
		std::ofstream ofs("animation/animation.txt");
		ofs << g;
		assert(ofs);
		ofs.close();
	}
	void Get(vector < vector < vector < double>> >& result ) {
		const boost::interprocess::mode_t mode = boost::interprocess::read_only;
		boost::interprocess::file_mapping fm("animation/animation.txt", mode);
		boost::interprocess::mapped_region region(fm, mode, 0, 0);
		const char* begin = static_cast<const char*>(
			region.get_address()
			);
		string line = begin;
		boost::json::value jv = boost::json::parse(line);
		result = boost::json::value_to<vector<vector<vector<double>>>>(jv);
	}

};