#pragma once
#include "Paint.h"
#include <string>
#include <map>
struct triple {
	double first;
	double second;
	double third = 1;
};

class RoboRabbit : public Paint {
protected: 
	const vector<triple> coordinate{
		{-70, 240},
		{-30,240},
		{30,240},
		{70,240},
		{-90,180},
		{-70,180},
		{-30,180},
		{30,180},
		{70,180},
		{90,180},
		{-70,160},
		{-30,160},
		{30,160},
		{70,160},
		{-110,120},
		{-90,120},
		{-70,120},
		{-30,120},
		{30,120},
		{70,120},
		{90,120},
		{110,120},
		{-90,100},
		{90,100},
		{-90,80},
		{90,80},
		{-110,60},
		{-90,60},
		{90,60},
		{110,60},
		{-190,40},
		{-90,40},
		{90,40},
		{190,40},
		{-150,0},
		{150,0},
		{-190,-60},
		{-150,-60},
		{150,-60},
		{190,-60},
		{-90,-80},
		{-70,-80},
		{70,-80},
		{90,-80},
		{-70,-120},
		{-50,-120},
		{-10,-120},
		{10,-120},
		{50,-120},
		{70,-120},
		{-90,-180},
		{-50,-180},
		{-10,-180},
		{10,-180},
		{50,-180},
		{90,-180},
		{-90,-220},
		{-10,-220},
		{10,-220},
		{90,-220},
		{-90,0},
		{90, 0}
};
	const map<int, vector<double>> graph{
{0, {1,5}},
{1, {0,6}},
{2, {3,7}},
{3, {2,8}},
{4, {5,15}},
{5, {0,4,6}},
{6, {1,5,7}},
{7, {2,6,8}},
{8, {3,7,9}},
{9, {8}},
{10, {11,16}},
{11, {10,17}},
{12, {13,18}},
{13, {12,19}},
{14, {15,26}},
{15, {4,14,16}},
{16, {10,15,17}},
{17, {11,16,18}},
{18, {12,17,19}},
{19, {13,18,20}},
{20, {9,19,21}},
{21, {20,29}},
{22, {23,24}},
{23, {22,25}},
{24, {22,25}},
{25, {23,24}},
{26, {14,27}},
{27, {26,28,31}},
{28, {27,29,32}},
{29, {21,28}},
{30, {31,36}},
{31, {27,30,40}},
{32, {28,33,43}},
{33, {32,39}},
{34, {37,60}},
{35, {38,61}},
{36, {37}},
{37, {}},
{38, {}},
{39, {38}},
{40, {43}},
{41, {44}},
{42, {49}},
{43, {}},
{44, {49}},
{45, {51}},
{46, {52}},
{47, {53}},
{48, {54}},
{49, {}},
{50, {52,56}},
{51, {}},
{52, {57}},
{53, {55,58}},
{54, {}},
{55, {59}},
{56, {57}},
{57, {}},
{58, {59}},
{59, {}},
{60, {}},
{61, {}},
	};

	triple Transformation(triple& m, vector<vector<double>> a) {
		return { m.first * a[0][0] + m.second * a[0][1] + m.third * a[0][2],
				m.first * a[1][0] + m.second * a[1][1] + m.third * a[1][2],
				m.first * a[2][0] + m.second * a[2][1] + m.third * a[2][2] };
	}
	public:

	// Рисование картинки
	void Draw() {
		ClearSreen();
		pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
		SelectObject(hdc, pen);
		for (auto it = graph.begin(); it != graph.end(); ++it) {
			for (auto places = (*it).second.begin(); places != (*it).second.end(); ++places) {
				POINT points[] = { {CenterX + coordinate[(*it).first].first , CenterY - coordinate[(*it).first].second } , {CenterX + coordinate[*places].first , CenterY - coordinate[*places].second} };
				Polygon(hdc, points, 2);
			}
		}
		DeleteObject(pen);
	}

	// Рисование картинки по координатам
	void Draw(vector<triple> coordinate) {
		ClearSreen();
		pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
		SelectObject(hdc, pen);
		for (auto it = graph.begin(); it != graph.end(); ++it) {
			for (auto places = (*it).second.begin(); places != (*it).second.end(); ++places) {
				POINT points[] = { {CenterX + coordinate[(*it).first].first , CenterY - coordinate[(*it).first].second } , {CenterX + coordinate[*places].first , CenterY - coordinate[*places].second} };
				Polygon(hdc, points, 2);
			}
		}
		DeleteObject(pen);
	}


	// Поворот
	void Turn(double a) {
		vector <vector<double>> RotationMatrix{
			{cos(a) , sin(a), 0}, {-sin(a), cos(a),0}, {0,0,1}
		};
		DoNewImage(RotationMatrix);
	}
	
	// Изменение размера
	void ChangeSize(pair<double, double> a) {
		vector <vector<double>> ScaleMatrix{
			{a.first,0,0}, {0,a.second,0}, {0,0,1}
		};
		DoNewImage(ScaleMatrix);
	}


	// Сдвиг
	void Shift(pair<double, double> a) {
		vector <vector<double>> ScaleMatrix{
			{1,tan(a.first),0}, {a.second,1,0}, {0,0,1}
		};
		DoNewImage(ScaleMatrix);
	}
	
	// Перемещение 
	void Move(pair<double, double> a) {
		vector <vector<double>> MoveMatrix{
			{1,0,a.first}, {0,1,a.second}, {0,0,1}
		};
		DoNewImage(MoveMatrix);
	}

	// Создание новый координат по матрице-изменения
	void DoNewImage(vector<vector<double>> matrix) {
		vector <triple> NewCoordinate;
		for (auto i : coordinate) {
			NewCoordinate.push_back(Transformation(i, matrix));
		}
		Draw(NewCoordinate);
	}

	// анимация растягивания
	void Poisoning() {
		double ratio = 1;
		for (double i = 0.01; ; i += 0.01 * ratio) {
			if (!PoisoningWork) return;
			Shift({ i,i });
			Sleep(10);
			if (i >= 1) ratio = -1;
			if (i <= -1) ratio = 1;
		}
	}

	// Уменьшение и увеличение картинки (анимация)
	void Heartbeat() {
		double ratio = 1;
		for (double i = 0.01; ; i += 0.03 * ratio) {
			if (!HeartbeatWork) return;
			ChangeSize({ i,1 });
			Sleep(10);
			if (i >= 1) ratio = -1;
			if (i <= 0) ratio = 1;
		}
	}

	// Вращение картинки (анимация)
	void Rotation() {
		for (double i = 0; i < 1000; i += 0.01) {
			if (!RotationWork) return;
			Turn(i);
			Sleep(10);
		}
	}

	// Перемещение (анимация)
	void Moving() {
		double ratio = -1;
		for (double i = 0; ; i += 4 * ratio) {
			if (!MovingWork) return;
			Move({i, i * 0.2 });
			if (i <0) ratio = 1;
			else if (i >= 299) ratio = -1;
			Sleep(10);
		}
	}
	
	bool RotationWork = false, PoisoningWork = false, HeartbeatWork = false, MovingWork = false, Work = 1;
};

