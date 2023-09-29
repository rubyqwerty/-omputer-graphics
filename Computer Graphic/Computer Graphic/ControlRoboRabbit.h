#pragma once
#include "Roborabbit.h"
#include "RoboRabbit2d.h"
#include "RoboRabbit3d.h"
#include "Tetragon.h"
#include <algorithm>

class ControlRoboRabbit {
public:
	RoboRabbit* roborabbit;
	ControlRoboRabbit(RoboRabbit* _roboRabbit) {
		roborabbit = _roboRabbit;
		Control();
	}
private:
	vector<vector<double>> MultiplicationMatrix(vector<vector<double>>& a, vector<vector<double>>& b) {
		vector<vector<double>> rslt(a.size(), { 0,0,0,0 });
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
	quad Transformation(quad& m, vector<vector<double>> a) {
		return { m.first * a[0][0] + m.second * a[0][1] + m.third * a[0][2] + m.fourth * a[0][3],
				m.first * a[1][0] + m.second * a[1][1] + m.third * a[1][2] + m.fourth * a[1][3],
				m.first * a[2][0] + m.second * a[2][1] + m.third * a[2][2] + m.fourth * a[1][3],
				m.first * a[3][0] + m.second * a[3][1] + m.third * a[3][2] + m.fourth * a[3][3] };
	}
	void StartDrawing() {
		RenderWindow window(VideoMode(1000, 800), L"Titul", Style::Default);
		while (window.isOpen())
		{
			if (!roborabbit->Work) break;
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed) window.close();
			}

			vector<pair<Vertex, Vertex>> G(roborabbit->LINES);
			//	if (!(G.size() == 237 || G.size() == 103)) continue;
			if (roborabbit->CurrentCoordinate.size() != 130) continue;
			auto COOR = roborabbit->CurrentCoordinate;
			vector<pair<int, Tetragon>> tr;
			auto hh = Tetragon::GetTetragons(roborabbit->CurrentCoordinate);
			for (auto gg : hh)
				tr.push_back({ 0, gg });
			for (auto& A : tr) {
				sf::ConvexShape convex;
				auto i = A.second;
				convex.setPointCount(4);
				double CentX = 0, CentY = 500;
				convex.setPoint(0, sf::Vector2f(i.first.first + CentX, i.first.second + CentX));
				convex.setPoint(1, sf::Vector2f(i.second.first + CentX, i.second.second + CentX));
				convex.setPoint(2, sf::Vector2f(i.third.first + CentX, i.third.second + CentX));
				convex.setPoint(3, sf::Vector2f(i._quad.first + CentX, i._quad.second + CentX));
				convex.setOutlineColor(Color::Red);
				window.clear(Color::Green);
				window.draw(convex); // “ут мы рисуем
				sf::Vector2u windowSize = window.getSize();
				sf::Texture texture;
				texture.create(windowSize.x, windowSize.y);
				texture.update(window);
				sf::Image screenshot = texture.copyToImage();
				vector<vector<double>> cor(800, vector<double>(1000, 0));
				for (int x = 0; x < 1000; ++x) {
					for (int y = 0; y < 800; ++y) {
						if (screenshot.getPixel(x, y) == Color::White)
							cor[y][x] = 1;
						else if (screenshot.getPixel(x, y) == Color::Red)
							cor[y][x] = 1;
					}
				}
				double Zmin = 1000000000000000;
				vector<double> k;
				for (double _y = 0; _y < 800; ++_y) {
					for (double _x = 0; _x < 1000; ++_x) {
						if (cor[_y][_x] == 1) {
							if (i.GetZ(_x, _y) < Zmin)
								Zmin = i.GetZ(_x, _y);
						}
					}
				}
				A.first = Zmin;
			}
			sort(tr.begin(), tr.end(), [](auto& left, auto& right) {
				return left.first < right.first;
				});
			window.clear(Color::Green);
			for (auto& A : tr) {
				sf::ConvexShape convex;
				auto i = A.second;
				convex.setPointCount(4);
				convex.setPoint(0, sf::Vector2f(i.first.first, i.first.second));
				convex.setPoint(1, sf::Vector2f(i.second.first, i.second.second));
				convex.setPoint(2, sf::Vector2f(i.third.first, i.third.second));
				convex.setPoint(3, sf::Vector2f(i._quad.first, i._quad.second));
				convex.setOutlineThickness(1.3);
				convex.setOutlineColor(Color::Red);
				convex.setFillColor(Color::Yellow);
				window.draw(convex); // “ут мы рисуем
			}
			window.display();
		}
	}
	
	void Action() {
		while (roborabbit->Work) {
			roborabbit->Poisoning();
			roborabbit->Heartbeat();
			roborabbit->Rotation();
			roborabbit->Moving();
		}
	}
	void Control() {
		thread thread1(&ControlRoboRabbit::Action, this);
		thread thread2(&ControlRoboRabbit::StartDrawing, this);
		while (1) {
			int action;

			cout << "Input command: ";
			cin >> action;
			switch (action) {
			case 0:
				roborabbit->HeartbeatWork = false;
				roborabbit->RotationWork = false;
				roborabbit->PoisoningWork = false;
				roborabbit->MovingWork = true;
				break;
			case 1:
				roborabbit->HeartbeatWork = false;
				roborabbit->RotationWork = false;
				roborabbit->PoisoningWork = true;
				roborabbit->MovingWork = false;
				break;
			case 2:
				roborabbit->HeartbeatWork = true;
				roborabbit->RotationWork = false;
				roborabbit->PoisoningWork = false;
				roborabbit->MovingWork = false;
				break;
			case 3:
				roborabbit->RotationWork = true;
				roborabbit->PoisoningWork = false;
				roborabbit->HeartbeatWork = false;
				roborabbit->MovingWork = false;
				break;
			
			default:
				roborabbit->RotationWork = false;
				roborabbit->PoisoningWork = false;
				roborabbit->HeartbeatWork = false;
				roborabbit->MovingWork = false;
				roborabbit->Work = 0;
				thread1.join();
				thread2.join();
				return;
			}
		}
	}

};