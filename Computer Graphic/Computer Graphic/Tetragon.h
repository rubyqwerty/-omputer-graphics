#pragma once
#include "Roborabbit.h"
using namespace std;


class Tetragon {
public:
	struct Equation_plane {
		double a;
		double b;
		double c;
		double d;
	};
	quad first;
	quad second;
	quad third;
	quad _quad;
	Equation_plane equation_plane;

	Equation_plane Get_equation_plane() {

		double a1 = second.first  - first.first;
		double b1 = second.second - first.second;
		double c1 = second.third - first.third;
		double a2 = third.first - first.first;
		double b2 = third.second - first.second;
		double c2 = third.third - first.third;
		double a = b1 * c2 - b2 * c1;
		double b = a2 * c1 - a1 * c2;
		double c = a1 * b2 - b1 * a2;
		double d = (-a * first.first - b * first.second - c * first.third);
		
		return { a,b,c, d};


	}
	
	Tetragon(quad a, quad b, quad c, quad d) {
		first = a;
		second = b;
		third = c;
		_quad = d;
		equation_plane = Get_equation_plane();
	}

	bool IsAppertain(quad point) {
		return equation_plane.a * point.first + equation_plane.b * point.second + equation_plane.c * point.third + equation_plane.d == 0;
	}

	double GetZ(double x, double y) {
		return ((-equation_plane.d - equation_plane.b * y - equation_plane.a * x) / equation_plane.c);
	}

	static vector<Tetragon> GetTetragons(vector<quad> coordinate) {
		return {
			
			Tetragon(coordinate[3 -1],
			coordinate[2 -1],
			coordinate[20 -1],
			coordinate[21 -1]
			),
			Tetragon(coordinate[6-1],
			coordinate[3-1],
			coordinate[21-1],
			coordinate[24-1]
			),
			Tetragon(coordinate[2-1],
			coordinate[5-1],
			coordinate[23-1],
			coordinate[20-1]
			),
			Tetragon(coordinate[6-1],
			coordinate[5-1],
			coordinate[23-1],
			coordinate[24-1]
			),
			Tetragon(coordinate[15-1],
			coordinate[16-1],
			coordinate[34-1],
			coordinate[33-1]
			),
			Tetragon(coordinate[16-1],
			coordinate[14-1],
			coordinate[32-1],
			coordinate[34-1]
			),
			Tetragon(coordinate[12-1],
			coordinate[13-1],
			coordinate[31-1],
			coordinate[30-1]
			),
			Tetragon(coordinate[13-1],
			coordinate[11-1],
			coordinate[29-1],
			coordinate[31-1]
			),
			Tetragon(coordinate[10-1],
			coordinate[7-1],
			coordinate[25-1],
			coordinate[28-1]
			),
			Tetragon(coordinate[9-1],
			coordinate[10-1],
			coordinate[28-1],
			coordinate[27-1]
			),
			Tetragon(coordinate[8-1],
			coordinate[7-1],
			coordinate[25-1],
			coordinate[26-1]
			),
			Tetragon(coordinate[18-1],
			coordinate[10-1],
			coordinate[28-1],
			coordinate[36-1]
			),
			Tetragon(coordinate[17-1],
			coordinate[18-1],
			coordinate[36-1],
			coordinate[35-1]
			),
			Tetragon(coordinate[20-1],
			coordinate[21-1],
			coordinate[6-1],
			coordinate[5-1]
			),
			Tetragon(coordinate[9-1],
			coordinate[8-1],
			coordinate[7-1],
			coordinate[10-1]
			),
			Tetragon(coordinate[10-1],
			coordinate[18-1],
			coordinate[17-1],
			coordinate[17-1]
			),
			Tetragon(coordinate[15-1],
			coordinate[16-1],
			coordinate[14-1],
			coordinate[14-1]
			),
			Tetragon(coordinate[12-1],
			coordinate[13-1],
			coordinate[11-1],
			coordinate[11-1]
			),
			Tetragon(coordinate[2-1],
			coordinate[3-1],
			coordinate[24-1],
			coordinate[23-1]
			),
			Tetragon(coordinate[27-1],
			coordinate[26-1],
			coordinate[25-1],
			coordinate[28-1]
			),
				Tetragon(coordinate[28-1],
					coordinate[36-1],
					coordinate[35-1],
					coordinate[35-1]
				),
				Tetragon(coordinate[33-1],
					coordinate[34-1],
					coordinate[32-1],
					coordinate[32-1]
				),
				Tetragon(coordinate[30-1],
					coordinate[31-1],
					coordinate[29-1],
					coordinate[29-1]
				)
			/*
			P1(3,2,20, 21) ДМН
P2(6,3,21,24) кебши йпюи
P3(2,5,23,20) опюбши
P4(6,5,23,24) бепу ясдмю
P5(15,16,34,33) мхг кебнцн оюпсяю
P6(16,14,32,34) бепу кебнцн
P7(12,13,31,30) мхг опюбнцн
P8(13,11,29,31) бепу опюбнцн
P9(10,7,25,28) бепусьйю
P10(9,10,28,27) кеб люврю
P11(8, 7, 25, 26) оп люврю
P12(18,10,28,36) бепу ткюцю
P13(17,18,36,35) мхг ткюцю

оепедмъъ
P14(20,21,6,5)
P15(9,8,7,10)
P21(10,18,17,17)
P17(15,16,14,14)
P18(12,13,11,11)

гюдмъъ
P19(2,3,24,23)
P20(27,26,25,28)
P16(28,36,35,40)
P22(33,34,32,32)
P23(30,31,29,29)

			*/
								
		};
	}

};