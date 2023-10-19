#pragma once
#include <string>
#include "Roborabbit.h"
#include <map>

class RoboRabbit3d : public RoboRabbit {
	
protected:
	vector<vector<double>> MultiplicationMatrix(vector<vector<double>>& a, vector<vector<double>>& b) {
		vector<vector<double>> rslt(a.size(), {0,0,0,0});
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				rslt[i][j] = 0;
				for (int k = 0; k < b.size(); k++) {
					rslt[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		return rslt;
	}

public:

	RoboRabbit3d() {
		coordinate = {
			{4, -7, 0},
{4, -12, 0},
{-4, -12, 0},
{-4, -7, 0},
{7, -7, 0},
{-7, -7, 0},
{0.25, 12, 0},
{0.25, -7, 0},
{-0.25, -7, 0},
 {-0.25, 12, 0},
 {0.25, 10, 0},
 {0.25, -6, 0},
 {6, -1, 0},
 {-0.25, 10, 0},
 {-0.25, -6, 0},
 {-4, -3, 0},
 {-0.25, 11, 0},
 {-3, 11, 0},

 {4, -7, 4} ,
 {4, -12, 4},
 {-4, -12, 4},
 {-4, -7, 4},
 {7, -7, 4},
 {-7, -7, 4},
 {0.25, 12, 4},
 {0.25, -7, 4},
 {-0.25, -7, 4},
 {-0.25, 12, 4},
 {0.25, 10, 4},
 {0.25, -6, 4},
 {6, -1, 4},
 {-0.25, 10, 4},
 {-0.25, -6, 4},
 {-4, -3, 4},
 {-0.25, 11, 4},
 {-3, 11, 4},
		};


		graph = {
{0, {1,5,62}},
{1, {0,6,63}},
{2, {3,7,64}},
{3, {2,8,65}},
{4, {5,15,66}},
{5, {0,4}},
{6, {1,5,7}},
{7, {2,6,8}},
{8, {3,7,9}},
{9, {8,71}},
{10, {11,16}},
{11, {10,17}},
{12, {13,18}},
{13, {12,19}},
{14, {15,26,76}},
{15, {4,14,16,77}},
{16, {10,15,17}},
{17, {11,16,18}},
{18, {12,17,19}},
{19, {13,18,20}},
{20, {9,19,21,82}},
{21, {20,29,83}},
{22, {23,24}},
{23, {22,25}},
{24, {22,25}},
{25, {23,24}},
{26, {14,27,88}},
{27, {26,28,31,89}},
{28, {27,29,32,90}},
{29, {21,28,91}},
{30, {31,36,92}},
{31, {27,30,40}},
{32, {28,33,43}},
{33, {32,39,95}},
{34, {37,60}},
{35, {38,61}},
{36, {37,98}},
{37, {99}},
{38, {100}},
{39, {38,101}},
{40, {43,102}},
{41, {44}},
{42, {49}},
{43, {105}},
{44, {49,106}},
{45, {51}},
{46, {52}},
{47, {53}},
{48, {54}},
{49, {111}},
{50, {52,56,112}},
{51, {}},
{52, {57}},
{53, {55,58}},
{54, {}},
{55, {59,117}},
{56, {57,118}},
{57, {119}},
{58, {59,120}},
{59, {121}},
{60, {122}},
{61, {123}},

{62,{ 63, 67, }},
{63,{ 62, 68, }},
{64,{ 65, 69, }},
{65,{ 64, 70, }},
{66,{ 67, 77, }},
{67,{ 62, 66, 68, }},
{68,{ 63, 67, 69, }},
{69,{ 64, 68, 70, }},
{70,{ 65, 69, 71, }},
{71,{ 70, }},
{72,{ 73, 78, }},
{73,{ 72, 79, }},
{74,{ 75, 80, }},
{75,{ 74, 81, }},
{76,{ 77, 88, }},
{77,{ 66, 76, 78, }},
{78,{ 72, 77, 79, }},
{79,{ 73, 78, 80, }},
{80,{ 74, 79, 81, }},
{81,{ 75, 80, 82, }},
{82,{ 71, 81, 83, }},
{83,{ 82, 91, }},
{84,{ 85, 86, }},
{85,{ 84, 87, }},
{86,{ 84, 87, }},
{87,{ 85, 86, }},
{88,{ 76, 89, }},
{89,{ 88, 90, 93, }},
{90,{ 89, 91, 94, }},
{91,{ 83, 90, }},
{92,{ 93, 98, }},
{93,{ 89, 92, 102, }},
{94,{ 90, 95, 105, }},
{95,{ 94, 101, }},
{96,{ 99, 122, }},
{97,{ 100, 123, }},
{98,{ 99, }},
{99,{ }},
{100,{ }},
{101,{ 100, }},
{102,{ 105, }},
{103,{ 106, }},
{104,{ 111, }},
{105,{ }},
{106,{ 111, }},
{107,{ 113, }},
{108,{ 114, }},
{109,{ 115, }},
{110,{ 116, }},
{111,{ }},
{112,{ 114, 118, }},
{113,{ }},
{114,{ 119, }},
{115,{ 117, 120, }},
{116,{ }},
{117,{ 121, }},
{118,{ 119, }},
{119,{ }},
{120,{ 121, }},
{121,{ }},
{122,{ }},
{123,{ }},


		};
	}

	// Изменение размера
	void ChangeSize(pair<double, double> a) {
		vector <vector<double>> ScaleMatrix{
			{1,0,0,0}, {0,a.first,0,0}, {0,0,1,0},{0,0,0,1}
		};
		DoNewImage(ScaleMatrix);
	}

	// Перемещение 
	void Move(pair<double, double> a) {
		vector <vector<double>> MoveMatrix{
			{1,0,0,0}, {0,1,0,a.first}, {0,0,1,0}, {0,0,0,1}
		};
		DoNewImage(MoveMatrix);
	}

	void Turn2(double a, double b, double c) {

		
		vector <vector<double>> RotationMatrix({
			{cos(b),	0,-sin(b),0},
			{0,1,0,0},
			{sin(b),0,cos(b),0},
			{0,0,0,1}
			});
		vector <vector<double>> RotationMatrix2({
			{1,	0,0,0},
			{0,cos(a),sin(a),0},
			{0,-sin(a),cos(a),0},
			{0,0,0,1}
			});
		vector <vector<double>> G({
			{20,0,0,0},{0,20,0,0},{0,0,20,0},{0,0,0,0}
			});

		RotationMatrix = MultiplicationMatrix(RotationMatrix2, RotationMatrix);
		RotationMatrix = MultiplicationMatrix(G, RotationMatrix);
		DoNewImage(RotationMatrix);

	}

	void Turn(double a) {
		vector <vector<double>> RotationMatrix({
			{cos(a),	0,-sin(a),0},
			{0,1,0,0},
			{sin(a),0,cos(a),0},
			{0,0,0,1}
			});
		vector <vector<double>> RotationMatrix2({
			{1,	0,0,0},
			{0,cos(100),sin(100),0},
			{0,-sin(100),cos(100),0},
			{0,0,0,1}
			});
		vector <vector<double>> G({
			{0.7,0,0,0},{0,0.7,0,0},{0,0,0.7,0},{0,0,0,0}
			});
		//RotationMatrix = MultiplicationMatrix(RotationMatrix, G);
		RotationMatrix = MultiplicationMatrix(RotationMatrix, RotationMatrix2);
		DoNewImage(RotationMatrix);
	}

	void Jump(quad a) {
		vector <vector<double>> ScaleMatrix{
			{1,0,0,0}, {0,a.first,0,0}, {0,0,1,0},{0,0,0,1}
		};
		vector <vector<double>> MoveMatrix{
			{1,0,0,0}, {0,1,0,a.second}, {0,0,1,0}, {0,0,0,1}
		};
		vector <vector<double>> RotationMatrix2({
			{1,	0,0,0},
			{0,cos(a.third),sin(a.third),0},
			{0,-sin(a.third),cos(a.third),0},
			{0,0,0,1}
			});
		ScaleMatrix = MultiplicationMatrix(ScaleMatrix, MoveMatrix);
		ScaleMatrix = MultiplicationMatrix(ScaleMatrix, RotationMatrix2);
		DoNewImage(ScaleMatrix);
	}
	// Вращение картинки (анимация)
	void Poisoning() {
		
		for (double a = 0, b = 0; ; a += 0.01, b += 0.01)
			Turn2(a, b, 0);

		/*
		for (double a = 1; a >= 0.7; a -= 0.006) {
			Jump({ a, a * 150,0 });
			Sleep(10);
		}
		for (double a = 0.7; a <= 1; a += 0.055) {
			Jump({ a, a * 150,0 });
			Sleep(10);
		}

		double ratio = 1;
		double b = 0;
		for (double a = 1; a <= 3.5; a += 0.055 * ratio, b += 0.053) {
			Jump({ 1, a * 150, b});
			ratio -= 0.008;
			Sleep(1);
		}

		for (double a = 3.5; a >= 1; a -= 0.055 * ratio,b+=0.053 ) {
			Jump({ 1,a * 150, b });
			Sleep(1);
			ratio += 0.008;
		}
		*/
		
	}
	public:
	void PerespectivePro() {
		vector<vector<double>> Matrix{
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1, 0.1},
			{0,0,0,1}
		};
		double a = 5;
		vector <vector<double>> RotationMatrix({
			{cos(a),	0,-sin(a),0},
			{0,1,0,0},
			{sin(a),0,cos(a),0},
			{0,0,0,1}
			});
		a = 00;
		vector <vector<double>> RotationMatrix2({
			{1,	0,0,0},
			{0,cos(a),sin(a),0},
			{0,-sin(a),cos(a),0},
			{0,0,0,1}
			});

		auto Mat = MultiplicationMatrix(RotationMatrix, RotationMatrix2);
		vector <vector<double>> ScaleMatrix{
			{0.7,0,0,0}, {0,0.7,0,0}, {0,0,0.7,0},{0,0,0,1}
		};
		Mat = MultiplicationMatrix(Mat, ScaleMatrix);
		DoNewImage(Mat);
	}


};

