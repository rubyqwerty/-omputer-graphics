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
			
			Tetragon(coordinate[5],
			coordinate[6],
			coordinate[6 + 62],
			coordinate[5 + 62]
			),
			Tetragon(coordinate[0 + 62],
			coordinate[1 + 62],
			coordinate[6 + 62],
			coordinate[5 + 62]
			),

			Tetragon(coordinate[0],
			coordinate[5],
			coordinate[62 + 5],
			coordinate[62]
			),
			Tetragon(coordinate[1],
			coordinate[6],
			coordinate[6 + 62],
			coordinate[1 + 62]
			),
			Tetragon(coordinate[0],
			coordinate[1],
			coordinate[1 + 62],
			coordinate[0 + 62]
			),

			Tetragon(coordinate[0],
			coordinate[1],
			coordinate[6],
			coordinate[5]
			),
			
			
			Tetragon(coordinate[2],
			coordinate[3],
			coordinate[8],
			coordinate[7]
			),

			Tetragon(coordinate[2+62],
			coordinate[3 + 62],
			coordinate[8 + 62],
			coordinate[7 + 62]
			),
			
			Tetragon(coordinate[2],
			coordinate[7],
			coordinate[7 + 62],
			coordinate[2 + 62]
			),

			Tetragon(coordinate[3],
			coordinate[8],
			coordinate[8 + 62],
			coordinate[3 + 62]
			),

			Tetragon(coordinate[2],
			coordinate[3],
			coordinate[3 + 62],
			coordinate[2 + 62]
			),

			Tetragon(coordinate[7],
			coordinate[8],
			coordinate[8 + 62],
			coordinate[7 + 62]
			),

			//

			Tetragon(coordinate[4],
			coordinate[9],
			coordinate[20],
			coordinate[15]
			),

			Tetragon(coordinate[4+62],
			coordinate[9+62],
			coordinate[20+62],
			coordinate[15+62]
			),

			Tetragon(coordinate[9],
			coordinate[20],
			coordinate[20 + 62],
			coordinate[9 + 62]
			),

			Tetragon(coordinate[4],
			coordinate[15],
			coordinate[15 + 62],
			coordinate[4 + 62]
			),

			Tetragon(coordinate[4],
			coordinate[9],
			coordinate[9 + 62],
			coordinate[4 + 62]
			),

			//

			Tetragon(coordinate[14],
			coordinate[21],
			coordinate[29],
			coordinate[26]
			),

			Tetragon(coordinate[14+62],
			coordinate[21+62],
			coordinate[29+62],
			coordinate[26+62]
			),

			Tetragon(coordinate[14],
			coordinate[26],
			coordinate[26+62],
			coordinate[14+62]
			),

			Tetragon(coordinate[21],
			coordinate[29],
			coordinate[29+62],
			coordinate[21+62]
			),

			Tetragon(coordinate[14],
			coordinate[21],
			coordinate[21+62],
			coordinate[14+62]
			),

			Tetragon(coordinate[26],
			coordinate[29],
			coordinate[29+62],
			coordinate[26+62]
			),

			//


			Tetragon(coordinate[27],
			coordinate[28],
			coordinate[43],
			coordinate[40]
			),

				Tetragon(coordinate[27+62],
					coordinate[28+62],
					coordinate[43+62],
					coordinate[40+62]
				),

				Tetragon(coordinate[27],
					coordinate[40],
					coordinate[40+62],
					coordinate[27+62]
				),

				Tetragon(coordinate[28],
					coordinate[43],
					coordinate[43+62],
					coordinate[28+62]
				),

				Tetragon(coordinate[27],
					coordinate[28],
					coordinate[28+62],
					coordinate[27+62]
				),

				Tetragon(coordinate[40],
					coordinate[43],
					coordinate[43+62],
					coordinate[40+62]
				),

				//

				//


				Tetragon(coordinate[41],
					coordinate[42],
					coordinate[49],
					coordinate[44]
				),

				Tetragon(coordinate[41 + 62],
					coordinate[42 + 62],
					coordinate[49 + 62],
					coordinate[44 + 62]
				),

				Tetragon(coordinate[41],
					coordinate[44],
					coordinate[44 + 62],
					coordinate[41 + 62]
				),

				Tetragon(coordinate[42],
					coordinate[49],
					coordinate[49 + 62],
					coordinate[42 + 62]
				),

				Tetragon(coordinate[44],
					coordinate[49],
					coordinate[49 + 62],
					coordinate[44 + 62]
				),

				Tetragon(coordinate[41],
					coordinate[42],
					coordinate[42 + 62],
					coordinate[41 + 62]
				),

				//


				//


				Tetragon(coordinate[45],
					coordinate[46],
					coordinate[52],
					coordinate[51]
				),

				Tetragon(coordinate[45 + 62],
					coordinate[46 + 62],
					coordinate[52 + 62],
					coordinate[51 + 62]
				),

				Tetragon(coordinate[45],
					coordinate[51],
					coordinate[51 + 62],
					coordinate[45 + 62]
				),

				Tetragon(coordinate[46],
					coordinate[52],
					coordinate[52 + 62],
					coordinate[46 + 62]
				),

				Tetragon(coordinate[51],
					coordinate[52],
					coordinate[52 + 62],
					coordinate[51 + 62]
				),

				Tetragon(coordinate[45],
					coordinate[46],
					coordinate[46 + 62],
					coordinate[45 + 62]
				),

				//

						//


						Tetragon(coordinate[47],
							coordinate[48],
							coordinate[54],
							coordinate[53]
						),

						Tetragon(coordinate[47 + 62],
							coordinate[48 + 62],
							coordinate[54 + 62],
							coordinate[53 + 62]
						),

						Tetragon(coordinate[47],
							coordinate[53],
							coordinate[53 + 62],
							coordinate[47 + 62]
						),

						Tetragon(coordinate[48],
							coordinate[54],
							coordinate[54 + 62],
							coordinate[48 + 62]
						),

						Tetragon(coordinate[47],
							coordinate[48],
							coordinate[48 + 62],
							coordinate[47 + 62]
						),

						Tetragon(coordinate[53],
							coordinate[54],
							coordinate[54 + 62],
							coordinate[53 + 62]
						),

						//

						//


						Tetragon(coordinate[50],
							coordinate[52],
							coordinate[57],
							coordinate[56]
						),

						Tetragon(coordinate[50 + 62],
							coordinate[52 + 62],
							coordinate[57 + 62],
							coordinate[56 + 62]
						),

						Tetragon(coordinate[50],
							coordinate[56],
							coordinate[56 + 62],
							coordinate[50 + 62]
						),

						Tetragon(coordinate[52],
							coordinate[57],
							coordinate[57 + 62],
							coordinate[52 + 62]
						),

						Tetragon(coordinate[50],
							coordinate[52],
							coordinate[52 + 62],
							coordinate[50 + 62]
						),

						Tetragon(coordinate[56],
							coordinate[57],
							coordinate[57 + 62],
							coordinate[56 + 62]
						),

					//

						//


						Tetragon(coordinate[53],
							coordinate[55],
							coordinate[59],
							coordinate[58]
						),

						Tetragon(coordinate[53 + 62],
							coordinate[55 + 62],
							coordinate[59 + 62],
							coordinate[58 + 62]
						),

						Tetragon(coordinate[53],
							coordinate[58],
							coordinate[58 + 62],
							coordinate[53 + 62]
						),

						Tetragon(coordinate[55],
							coordinate[59],
							coordinate[59 + 62],
							coordinate[55 + 62]
						),

						Tetragon(coordinate[53],
							coordinate[55],
							coordinate[55 + 62],
							coordinate[53 + 62]
						),

						Tetragon(coordinate[58],
							coordinate[59],
							coordinate[59 + 62],
							coordinate[58 + 62]
						),


								//


							Tetragon(coordinate[34],
								coordinate[60],
								coordinate[31],
								coordinate[124]
							),

							Tetragon(coordinate[34+62],
								coordinate[60 + 62],
								coordinate[31 + 62],
								coordinate[125]
							),

							Tetragon(coordinate[31],
								coordinate[60],
								coordinate[60+62],
								coordinate[31+62]
							),

							
							Tetragon(coordinate[31],
								coordinate[60],
								coordinate[60 + 62],
								coordinate[31 + 62]
							),

							Tetragon(coordinate[34],
								coordinate[124],
								coordinate[125],
								coordinate[34+62]
							),

							Tetragon(coordinate[34],
								coordinate[60],
								coordinate[60 + 62],
								coordinate[34 + 62]
							),
								
						

								//


								Tetragon(coordinate[30],
									coordinate[124],
									coordinate[37],
									coordinate[36]
								),

							Tetragon(coordinate[30+62],
								coordinate[125],
								coordinate[37+62],
								coordinate[36+62]
							),

								Tetragon(coordinate[30],
									coordinate[36],
									coordinate[36 + 62],
									coordinate[30 + 62]
								),


								Tetragon(coordinate[124],
									coordinate[37],
									coordinate[37 + 62],
									coordinate[125]
								),

								Tetragon(coordinate[30],
									coordinate[124],
									coordinate[125],
									coordinate[30 + 62]
								),

								Tetragon(coordinate[36],
									coordinate[37],
									coordinate[37 + 62],
									coordinate[36 + 62]
								),



								//


								Tetragon(coordinate[32],
									coordinate[126],
									coordinate[35],
									coordinate[61]
								),

								Tetragon(coordinate[32 + 62],
									coordinate[127],
									coordinate[35 + 62],
									coordinate[61 + 62]
								),

								Tetragon(coordinate[32],
									coordinate[126],
									coordinate[127],
									coordinate[32 + 62]
								),


								Tetragon(coordinate[61],
									coordinate[35],
									coordinate[35 + 62],
									coordinate[61+62]
								),

								Tetragon(coordinate[32],
									coordinate[61],
									coordinate[61+62],
									coordinate[32 + 62]
								),

								Tetragon(coordinate[35],
									coordinate[126],
									coordinate[127],
									coordinate[35 + 62]
								),



								//


								Tetragon(coordinate[126],
									coordinate[38],
									coordinate[39],
									coordinate[33]
								),

								Tetragon(coordinate[127],
									coordinate[38+62],
									coordinate[39 + 62],
									coordinate[33 + 62]
								),

								Tetragon(coordinate[126],
									coordinate[33],
									coordinate[33 + 62],
									coordinate[127]
								),


								Tetragon(coordinate[38],
									coordinate[39],
									coordinate[39 + 62],
									coordinate[38+62]
								),

								Tetragon(coordinate[33],
									coordinate[39],
									coordinate[39+62],
									coordinate[33 + 62]
								),

								Tetragon(coordinate[126],
									coordinate[38],
									coordinate[38+62],
									coordinate[127]
								),

							
							//
							/*
								Tetragon(coordinate[36],
									coordinate[37],
									coordinate[124],
									coordinate[30]
								),
							Tetragon(coordinate[36+62],
								coordinate[37+62],
								coordinate[125],
								coordinate[30+62]
							),

							Tetragon(coordinate[30],
								coordinate[36],
								coordinate[36+62],
								coordinate[30+62]
							),

							Tetragon(coordinate[37],
								coordinate[124],
								coordinate[125],
								coordinate[37+62]
							),

							Tetragon(coordinate[36],
								coordinate[37],
								coordinate[37 + 62],
								coordinate[36 + 62]
							),
							Tetragon(coordinate[30],
								coordinate[124],
								coordinate[125],
								coordinate[30 + 62]
							),


								//
								/*

							Tetragon(coordinate[126],
								coordinate[32],
								coordinate[128],
								coordinate[35]
							),
								Tetragon(coordinate[127],
									coordinate[32+62],
									coordinate[129],
									coordinate[35+62]
								),

								Tetragon(coordinate[35],
									coordinate[128],
									coordinate[129],
									coordinate[35+62]
								),
								
								Tetragon(coordinate[35],
									coordinate[128],
									coordinate[129],
									coordinate[35+62]
								),

								Tetragon(coordinate[126],
									coordinate[35],
									coordinate[35+62],
									coordinate[127]
								),
							//
							// 
							
								Tetragon(coordinate[38],
									coordinate[39],
									coordinate[33],
									coordinate[128]
								),

										Tetragon(coordinate[38+62],
											coordinate[39+62],
											coordinate[33+62],
											coordinate[129]
										),

								Tetragon(coordinate[33],
									coordinate[39],
									coordinate[39+62],
									coordinate[33+62]
								),
								Tetragon(coordinate[38],
									coordinate[39],
									coordinate[39+62],
									coordinate[38+62]
								),

								Tetragon(coordinate[128],
									coordinate[33],
									coordinate[33+62],
									coordinate[129]
								),



									Tetragon(coordinate[10],
										coordinate[11],
										coordinate[17],
										coordinate[16]
									),

								Tetragon(coordinate[12],
									coordinate[13],
									coordinate[19],
									coordinate[18]
								),

								Tetragon(coordinate[22],
									coordinate[23],
									coordinate[25],
									coordinate[24]
								),
								//

							
								Tetragon(coordinate[30],
									coordinate[36],
									coordinate[37],
									coordinate[34]
								),

							Tetragon(coordinate[34],
								coordinate[35],
								coordinate[35 + 62],
								coordinate[34 + 62]
							),

								Tetragon(coordinate[30 + 62],
									coordinate[36 + 62],
									coordinate[37 + 62],
									coordinate[34 + 62]
								),

								Tetragon(coordinate[30],
									coordinate[36],
									coordinate[36 + 62],
									coordinate[30 + 62]
								),

								Tetragon(coordinate[37],
									coordinate[34],
									coordinate[34 + 62],
									coordinate[37 + 62]
								),

								Tetragon(coordinate[30],
									coordinate[34],
									coordinate[34 + 62],
									coordinate[30 + 62]
								),
							Tetragon(coordinate[30],
								coordinate[33],
								coordinate[33 + 62],
								coordinate[30 + 62]
							),

								Tetragon(coordinate[36],
									coordinate[37],
									coordinate[37 + 62],
									coordinate[36 + 62]
								),
							//

								//

								
								Tetragon(coordinate[35],
									coordinate[38],
									coordinate[39],
									coordinate[33]
								),

								Tetragon(coordinate[35 + 62],
									coordinate[38 + 62],
									coordinate[39 + 62],
									coordinate[33 + 62]
								),

								Tetragon(coordinate[35],
									coordinate[38],
									coordinate[38 + 62],
									coordinate[35 + 62]
								),

								Tetragon(coordinate[33],
									coordinate[39],
									coordinate[39 + 62],
									coordinate[33 + 62]
								),

								Tetragon(coordinate[38],
									coordinate[39],
									coordinate[39 + 62],
									coordinate[38 + 62]
								),

								Tetragon(coordinate[35],
									coordinate[33],
									coordinate[33 + 62],
									coordinate[35 + 62]
								),
								*/
							//

								//
								/*

								Tetragon(coordinate[30],
									coordinate[33],
									coordinate[35],
									coordinate[34]
								),

								Tetragon(coordinate[30 + 62],
									coordinate[33 + 62],
									coordinate[35 + 62],
									coordinate[34 + 62]
								),

								Tetragon(coordinate[30],
									coordinate[34],
									coordinate[34 + 62],
									coordinate[30 + 62]
								),

								Tetragon(coordinate[33],
									coordinate[35],
									coordinate[35 + 62],
									coordinate[33 + 62]
								),

								Tetragon(coordinate[30],
									coordinate[33],
									coordinate[33 + 62],
									coordinate[30 + 62]
								),

								Tetragon(coordinate[34],
									coordinate[35],
									coordinate[35 + 62],
									coordinate[34 + 62]
								),
								*/
								
		};
	}

};