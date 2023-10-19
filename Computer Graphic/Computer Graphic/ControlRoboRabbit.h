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
	Texture texture;
	const int Number_of_frames = 100;
	void MakeZbuffer(RenderWindow& window, vector<vector<vector<pair<double, Color>>>>& Animation) {
		ContainerZBuffer g;
		if (roborabbit->CurrentCoordinate.size() != 36) return;
		auto COOR = roborabbit->CurrentCoordinate;
		for (auto& i : COOR) {
			i.first += 500;
			i.second = 400 - i.second;
			i.third -= 600;
		}
		vector<pair<double, Tetragon>> tr;
		auto hh = Tetragon::GetTetragons(COOR);
		vector<vector<pair<double, Color>>> Zbuffer(800, vector<pair<double, Color>>(1000, { -5000, Color::White }));
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
			//convex.setFillColor(Color::Yellow);
			convex.setTexture(&texture);
			window.clear(Color::Green);
			window.draw(convex); // “ут мы рисуем

			sf::Vector2u windowSize = window.getSize();
			sf::Texture texture;
			texture.create(windowSize.x, windowSize.y);
			texture.update(window);
			sf::Image screenshot = texture.copyToImage();
			vector<vector<Color>> cor(800, vector<Color>(1000, Color::White));
			for (int x = 0; x < 1000; ++x) {
				for (int y = 0; y < 800; ++y) {
					if (screenshot.getPixel(x, y) != Color::Green)
						cor[y][x] = screenshot.getPixel(x, y);
				}
			}
			for (double _y = 0; _y < 800; ++_y)
				for (double _x = 0; _x < 1000; ++_x)
					if (cor[_y][_x] != Color::White) {
						if (i.GetZ(_x, _y) > Zbuffer[_y][_x].first) {
							Zbuffer[_y][_x].first = i.GetZ(_x, _y);
							Zbuffer[_y][_x].second = cor[_y][_x];
						}
					}
		}
		//cout << Animation.size() << endl;
		DrawZBuffer(window, Zbuffer);
		if (Animation.size() < Number_of_frames) {
			Animation.push_back(Zbuffer);
		}
	}

	void DrawZBuffer(RenderWindow& window, vector<vector<pair<double,Color>>> Zbuffer) {
		sf::VertexArray pointmap(sf::Points, 1000 * 800);
		int k = 0;
		for (int x = 0; x < 1000; ++x) {
			for (int y = 0; y < 800; ++y) {
				pointmap[k].position = sf::Vector2f(x, y);
				if (Zbuffer[y][x].first > -1000) {
					int r = Zbuffer[y][x].second.r * (Zbuffer[y][x].first + 1000) * 0.001;
					int g = Zbuffer[y][x].second.g * (Zbuffer[y][x].first + 1000) * 0.001;
					int b = Zbuffer[y][x].second.b * (Zbuffer[y][x].first + 1000) * 0.001;
					pointmap[k].color = Color({ (Uint8)(r * 1.4),(Uint8)(g * 1.4),(Uint8)(b * 1.4) });
				}
				else
					pointmap[k].color = Color({ 174,241,255 });
				k++;
			}
		}
		window.draw(pointmap);
		window.display();
	}
	
	void DrawLine(RenderWindow& window) {
		vector<pair<Vertex, Vertex>> G(roborabbit->LINES);
		if (!(G.size() == 237)) return;
		window.clear(Color::Blue);
		VertexArray g(Lines);
		int k = 0;
		for (int i = 0; i < G.size(); ++i) {
			g.append(G[i].first);
			g.append(G[i].second);
		}
		window.draw(g);
		window.display();
	}

	void StartDrawing() {
		texture.loadFromFile("texture.jpg");
		int Height = 1000, Weight = 800;
		RenderWindow window(VideoMode(Height, Weight), L"Titul", Style::Default);
		vector<vector<vector<pair<double, Color>>>> Animation;
		while (window.isOpen())
		{
			if (!roborabbit->Work) break;
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed) window.close();
			}

			//DrawLine(window);
			

			MakeZbuffer(window, Animation);
			if (Animation.size() == Number_of_frames)
				while (1)
					for (auto& i : Animation) {
						DrawZBuffer(window, i);
						Sleep(100);
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
		roborabbit->PoisoningWork = true;
		}

};