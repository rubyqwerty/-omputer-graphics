#pragma once
#define NOMINMAX
#include <iostream>
#include <vector>
#include <math.h>
#include <thread>
#include <conio.h>
#include <Windows.h>
#include <windowsx.h>
#include <map>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
struct Point3D {
	double x;
	double y;
	double z;
};
struct quad {
	double first = 1;
	double second = 1;
	double third = -100;
	double fourth = 1;

};
class RoboRabbit {
public:
	double N = 0.00;
	double CenterX = 500;
	double CenterY = 400;
	virtual void Turn(double a) = 0;
	virtual void Move(pair<double, double> a) = 0;
	virtual void ChangeSize(pair<double, double> a) = 0;
	virtual void Poisoning() = 0;
	map<int, vector<double>> graph;
	vector<quad> coordinate;
	vector<quad> CurrentCoordinate;
	vector <pair<Vertex, Vertex>> LINES;

	quad Transformation(quad& m, vector<vector<double>> a) {
		return { m.first * a[0][0] + m.second * a[0][1] + m.third * a[0][2] + m.fourth * a[0][3],
				m.first * a[1][0] + m.second * a[1][1] + m.third * a[1][2] + m.fourth * a[1][3],
				m.first * a[2][0] + m.second * a[2][1] + m.third * a[2][2] + m.fourth * a[1][3],
				m.first * a[3][0] + m.second * a[3][1] + m.third * a[3][2] + m.fourth * a[3][3] };
	}
	// Рисование картинки по координатам
	void Draw(vector<quad> coordinate) {
		LINES.clear();
		for (auto it = graph.begin(); it != graph.end(); ++it) {
			for (auto places = (*it).second.begin(); places != (*it).second.end(); ++places) {
				LINES.push_back({
						Vertex(sf::Vector2f(CenterX + coordinate[(*it).first].first, CenterY - coordinate[(*it).first].second)),
						Vertex(sf::Vector2f(CenterX + coordinate[*places].first , CenterY - coordinate[*places].second))
					});
			}
		}
		int j;
	}
	// Создание новый координат по матрице-изменения
	void DoNewImage(vector<vector<double>> matrix) {
		vector <quad> newcoordinate;
		for (auto i : coordinate) {
			newcoordinate.push_back(Transformation(i, matrix));
			int n = newcoordinate.size() - 1;
		    newcoordinate[n].first = newcoordinate[n].first / (newcoordinate[n].third * N + 1);
			newcoordinate[n].second = newcoordinate[n].second / (newcoordinate[n].third * N + 1);
			newcoordinate[n].third = newcoordinate[n].third / (newcoordinate[n].third * N + 1);
		}
		CurrentCoordinate = newcoordinate;
	    Draw(newcoordinate);
	}
	// Перемещение (анимация)
	void Moving() {
		double ratio = -1;
		for (double i = 0; ; i += 4 * ratio) {
			if (!MovingWork) return;
			Move({ i, i * 0.2 });
			if (i < 0) ratio = 1;
			else if (i >= 299) ratio = -1;
			Sleep(20000);
		}
	}
	// Вращение картинки (анимация)
	void Rotation()
	{
		for (double b = -100; b < 180; b += 0.01, b += 0.016) {
			if (!RotationWork) return;
			Turn(b);
			Sleep(100);
			//break;
		}
	}
	// Уменьшение и увеличение картинки (анимация)
	void Heartbeat() {
		double ratio = 1;
		for (double i = 0.01; ; i += 0.03 * ratio) {
			if (!HeartbeatWork) return;
			ChangeSize({ i,i });
			Sleep(1000);
			if (i >= 1) ratio = -1;
			if (i <= 0) ratio = 1;
		}
	}

	bool RotationWork = false, PoisoningWork = false, HeartbeatWork = false, MovingWork = false, Work = 1, turnU;
};