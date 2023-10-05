#pragma once
#include "Roborabbit.h"
#include "RoboRabbit2d.h"
#include "RoboRabbit3d.h"
#include "Tetragon.h"
#include <algorithm>
#include "Container.h"

class ControlRoboRabbit {
public:
	RoboRabbit* roborabbit;
	ControlRoboRabbit(RoboRabbit* _roboRabbit) {
		roborabbit = _roboRabbit;
		Control();
	}
private:
	void StartDrawing() {
		RenderWindow window(VideoMode(1000, 800), L"Titul", Style::Default);
		vector<vector<vector<double>>> Animation;
		ContainerZBuffer g;
		while (window.isOpen())
		{
			if (!roborabbit->Work) break;
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed) window.close();
			}
			
			//auto f = g.Get();
			if (roborabbit->CurrentCoordinate.size() != 128) continue;
			auto COOR = roborabbit->CurrentCoordinate;
			for (auto& i : COOR) {
				i.first += 500;
				i.second = 400 - i.second;
				i.third -= 300;
			}
			vector<pair<double, Tetragon>> tr;
			auto hh = Tetragon::GetTetragons(COOR);
			vector<vector<double>> Zbuffer(800, vector<double>(1000, -5000));
			for (auto gg : hh)
				tr.push_back({ 0, gg });
			for (auto& A : tr) {
				sf::ConvexShape convex;
				auto i = A.second;
				convex.setPointCount(4);
				convex.setPoint(0, sf::Vector2f(i.first.first, i.first.second));
				convex.setPoint(1, sf::Vector2f(i.second.first, i.second.second));
				convex.setPoint(2, sf::Vector2f(i.third.first, i.third.second));
				convex.setPoint(3, sf::Vector2f(i._quad.first, i._quad.second));
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
				for (double _y = 0; _y < 800; ++_y)
					for (double _x = 0; _x < 1000; ++_x)
						if (cor[_y][_x] == 1) {
							if (i.GetZ(_x, _y) > Zbuffer[_y][_x])
								Zbuffer[_y][_x] = i.GetZ(_x, _y);
						}
			}
			Animation.push_back(Zbuffer);
			if (Animation.size() == 250) {
				g.Save(Animation);
				while (1){
					for (auto& buff : Animation) {
						sf::VertexArray pointmap(sf::Points, 1000 * 800);
						int k = 0;
						for (int x = 0; x < 1000; ++x) {
							for (int y = 0; y < 800; ++y) {
								pointmap[k].position = sf::Vector2f(x, y);
								if (buff[y][x] > -1000) {
									sf::Uint8 l1 = max((sf::Uint8)(buff[y][x] * 0.3 + 200), (sf::Uint8)100);
									pointmap[k].color = Color{ l1, l1, (sf::Uint8)0 };
								}
								else
									pointmap[k].color = Color::Blue;
								k++;
							}
						}
						window.draw(pointmap);
						window.display();
						Sleep(10);
					}

				}
				
			}
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
			int action = 1;

			//cout << "Input command: ";
			//cin >> action;
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